#include <iostream>
#include <string>
#include <vector>

struct Sound {
    std::string name;
    long long frequency;
    long long channels;
    long long bits;
    long long duration; 
    long long fileSize;
};

int main() {
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long threshold;
    if (!(std::cin >> threshold)) return 0;

    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<Sound> sounds(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> sounds[i].name >> sounds[i].frequency >> sounds[i].channels 
                 >> sounds[i].bits >> sounds[i].duration >> sounds[i].fileSize;
    }

    long long totalMemoryBytes = 0;
    int countFlux = 0;
    int countRefuses = 0;

    for (const auto& sound : sounds) {
        if (sound.bits != 8 && sound.bits != 16 && sound.bits != 24 && sound.bits != 32) {
            std::cout << sound.name << " REFUSE\n";
            countRefuses++;
            continue;
        }

        long long brut = (sound.frequency * sound.channels * (sound.bits / 8) * sound.duration) / 1000;

        long long percent = (brut > 0) ? (sound.fileSize * 100 / brut) : 0;

        std::string mode;
        if (brut > threshold) {
            mode = "FLUX";
            countFlux++;
        } else {
            mode = "MEMOIRE";
            totalMemoryBytes += brut;
        }

        std::cout << sound.name << " " << brut << " " << percent << " " << mode << "\n";
    }

    std::cout << "MEMOIRE " << totalMemoryBytes << "\n";
    std::cout << "FLUX " << countFlux << "\n";
    std::cout << "REFUSES " << countRefuses << "\n";

    return 0;
}