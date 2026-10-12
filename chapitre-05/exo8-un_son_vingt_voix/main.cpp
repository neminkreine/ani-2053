#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct PlayEvent {
    long long t;
    int index;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long D, C;
    if (!(std::cin >> D >> C)) return 0;

    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<long long> times(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> times[i];
    }

    if (N == 0) {
        std::cout << "VOIX_MAX 0\n";
        std::cout << "RETARD_MAX 0\n";
        std::cout << "COUPES 0\n";
        return 0;
    }

    long long voixMax = 0;
    long long retardMax = 0;
    long long coupesCount = 0;

   
    std::vector<long long> activeVoicesEnds; 
    long long lastLoadingEnd = -1;

    for (int i = 0; i < N; ++i) {
        long long t_i = times[i];

        std::vector<long long> currentActive;
        for (long long end_t : activeVoicesEnds) {
            if (end_t > t_i) {
                currentActive.push_back(end_t);
            }
        }
     
        currentActive.push_back(t_i + D);
        activeVoicesEnds = currentActive;

        long long activeCount = activeVoicesEnds.size();
        if (activeCount > voixMax) {
            voixMax = activeCount;
        }

        long long loadStart = t_i;
        if (i > 0 && lastLoadingEnd > loadStart) {
            loadStart = lastLoadingEnd;
        }
        long long loadEnd = loadStart + C;
        lastLoadingEnd = loadEnd;

        long long retard = loadEnd - t_i;
        if (retard > retardMax) {
            retardMax = retard;
        }

        std::string etat = "ENTIER";
        if (i + 1 < N) {
            long long t_next = times[i + 1];
            if (t_next < t_i + D) {
                etat = "COUPE";
                coupesCount++;
            }
        }

        std::cout << t_i << " " << activeCount << " " << retard << " " << etat << "\n";
    }

    std::cout << "VOIX_MAX " << voixMax << "\n";
    std::cout << "RETARD_MAX " << retardMax << "\n";
    std::cout << "COUPES " << coupesCount << "\n";

    return 0;
}