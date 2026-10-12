#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct GlyphGroup {
    std::string name;
    long long n;
    long long w;
    long long h;
};

struct GroupResult {
    long long x1, y1;
    long long x2, y2;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long P;
    long long L_input;
    if (!(std::cin >> P >> L_input)) return 0;

    int G;
    if (!(std::cin >> G)) return 0;

    std::vector<GlyphGroup> groups(G);
    long long totalOccupe = 0;
    long long totalNeedSum = 0;

    for (int i = 0; i < G; ++i) {
        std::cin >> groups[i].name >> groups[i].n >> groups[i].w >> groups[i].h;
        totalOccupe += groups[i].n * groups[i].w * groups[i].h;
        totalNeedSum += groups[i].n * (groups[i].w + P) * (groups[i].h + P);
    }

    if (G == 0) {
        std::cout << "AUCUN\n";
        return 0;
    }

    long long W_init = L_input;
    if (W_init == 0) {
        W_init = 512;
        while (W_init * W_init < 2 * totalNeedSum && W_init < 4096) {
            W_init *= 2;
        }
    }

    long long W = W_init;
    long long H = W;

    int attempt = 0;
    bool success = false;
    std::vector<GroupResult> results(G);

    while (attempt < 8) {
        attempt++;
        bool currentFailed = false;

        long long curX = P;
        long long curY = P;
        long long currentE = 0;

        for (int i = 0; i < G; ++i) {
            long long firstX = -1, firstY = -1;
            long long lastX = -1, lastY = -1;

            long long rw = groups[i].w + P;
            long long rh = groups[i].h + P;

            for (long long k = 0; k < groups[i].n; ++k) {
                if (curX + rw > W - P) {
                    curX = P;
                    curY = curY + currentE + P;
                    currentE = 0;
                }

                if (curX + rw > W - P) {
                    currentFailed = true;
                    break;
                }

                if (curY + rh > H - P) {
                    currentFailed = true;
                    break;
                }

                long long x_pos = curX;
                long long y_pos = curY;

                if (k == 0) {
                    firstX = x_pos;
                    firstY = y_pos;
                }
                if (k == groups[i].n - 1) {
                    lastX = x_pos;
                    lastY = y_pos;
                }

                curX += rw;
                if (rh > currentE) {
                    currentE = rh;
                }
            }

            if (currentFailed) {
                break;
            }

            results[i] = {firstX, firstY, lastX, lastY};
        }

        if (!currentFailed) {
            success = true;
            break;
        }
        if (W == H) {
            W *= 2;
        } else {
            H = W;
        }
    }

    if (!success) {
        std::cout << "ESSAIS 8\n";
        std::cout << "ECHEC\n";
    } else {
        long long totalArea = W * H;
        long long perdu = (totalArea - totalOccupe) * 100 / totalArea;

        std::cout << "ESSAIS " << attempt << "\n";
        std::cout << "TEXTURE " << W << " " << H << "\n";
        for (int i = 0; i < G; ++i) {
            std::cout << groups[i].name << " " 
                      << results[i].x1 << " " << results[i].y1 << " " 
                      << results[i].x2 << " " << results[i].y2 << "\n";
        }
        std::cout << "OCCUPE " << totalOccupe << "\n";
        std::cout << "PERDU " << perdu << "\n";
    }

    return 0;
}