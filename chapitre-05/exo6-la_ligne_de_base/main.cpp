#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

struct Glyph {
    int avance;
    int x0, y0, x1, y1;
    bool exists;
};

int main() {
  
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int G;
    if (!(std::cin >> G)) return 0;

    std::map<char, Glyph> fontTable;
    for (int i = 0; i < G; ++i) {
        char c;
        int avance, x0, y0, x1, y1;
        std::cin >> c >> avance >> x0 >> y0 >> x1 >> y1;
        fontTable[c] = {avance, x0, y0, x1, y1, true};
    }

    int K;
    if (!(std::cin >> K)) return 0;

    std::map<std::string, int> kerningTable;
    for (int i = 0; i < K; ++i) {
        std::string pair;
        int k;
        std::cin >> pair >> k;
        kerningTable[pair] = k;
    }

    std::string text;
    long long ox, oy;
    if (!(std::cin >> text >> ox >> oy)) return 0;

    long long currentX = ox;
    int absentsCount = 0;

    long long minX = LLONG_MAX;
    long long minY = LLONG_MAX;
    long long maxX = LLONG_MIN;
    long long maxY = LLONG_MIN;
    bool hasDrawn = false;

    for (size_t i = 0; i < text.length(); ++i) {
        char c = text[i];

        if (fontTable.find(c) == fontTable.end()) {
            std::cout << c << " ABSENT\n";
            absentsCount++;
         
            continue;
        }

        const Glyph& g = fontTable[c];
        std::cout << c << " " << currentX << "\n";

        if (g.x1 > g.x0 && g.y1 > g.y0) {
            long long rx0 = currentX + g.x0;
            long long ry0 = oy + g.y0;
            long long rx1 = currentX + g.x1;
            long long ry1 = oy + g.y1;

            if (!hasDrawn) {
                minX = rx0;
                minY = ry0;
                maxX = rx1;
                maxY = ry1;
                hasDrawn = true;
            } else {
                if (rx0 < minX) minX = rx0;
                if (ry0 < minY) minY = ry0;
                if (rx1 > maxX) maxX = rx1;
                if (ry1 > maxY) maxY = ry1;
            }
        }

        currentX += g.avance;

        if (i + 1 < text.length()) {
            std::string pair = "";
            pair += c;
            pair += text[i + 1];
            if (kerningTable.find(pair) != kerningTable.end()) {
                currentX += kerningTable[pair];
            }
        }
    }

    std::cout << "CURSEUR " << currentX << "\n";

    if (!hasDrawn) {
        std::cout << "BOITE AUCUNE\n";
        std::cout << "MONTE 0\n";
        std::cout << "DESCEND 0\n";
        std::cout << "ECRAN RIEN\n";
    } else {
        std::cout << "BOITE " << minX << " " << minY << " " << maxX << " " << maxY << "\n";

        long long monte = (minY < oy) ? (oy - minY) : 0;
        long long descend = (maxY > oy) ? (maxY - oy) : 0;

        std::string ecran;
        if (maxY <= 0) {
            ecran = "HORS";
        } else if (minY < 0) {
            ecran = "COUPE";
        } else {
            ecran = "VISIBLE";
        }

        std::cout << "MONTE " << monte << "\n";
        std::cout << "DESCEND " << descend << "\n";
        std::cout << "ECRAN " << ecran << "\n";
    }

    std::cout << "ABSENTS " << absentsCount << "\n";

    return 0;
}