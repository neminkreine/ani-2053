#include <iostream>
#include <string>
#include <vector>
#include <map>

struct FormatInfo {
    int bytesPP;
    bool color;
    bool transparency;
    bool floatType;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long w, h;
    if (!(std::cin >> w >> h)) return 0;

    int N;
    if (!(std::cin >> N)) return 0;

    std::map<std::string, FormatInfo> formats = {
        {"GRAY8",      {1, false, false, false}},
        {"GRAY_A16",   {2, false, true,  false}},
        {"RGB24",      {3, true,  false, false}},
        {"RGBA32",     {4, true,  true,  false}},
        {"RGB96F",     {12, true, false, true}},
        {"RGBA128F",   {16, true, true,  true}}
    };

    long long totalBytesTarget = 0;
    int sansPerteCount = 0;
    int refusesCount = 0;

    for (int i = 0; i < N; ++i) {
        std::string src, tgt;
        std::cin >> src >> tgt;

        if (formats.find(src) == formats.end() || formats.find(tgt) == formats.end()) {
            std::cout << src << " " << tgt << " REFUSE\n";
            refusesCount++;
            continue;
        }

        const FormatInfo& sInfo = formats[src];
        const FormatInfo& tInfo = formats[tgt];

        long long srcBytes = w * h * sInfo.bytesPP;
        long long tgtBytes = w * h * tInfo.bytesPP;

        std::string losses = "";
        

        if (sInfo.transparency && !tInfo.transparency) {
            losses += "TRANSPARENCE";
        }
        if (sInfo.color && !tInfo.color) {
            if (!losses.empty()) losses += "+";
            losses += "COULEUR";
        }
        if (sInfo.floatType && !tInfo.floatType) {
            if (!losses.empty()) losses += "+";
            losses += "ETENDUE";
        }

        if (losses.empty()) {
            losses = "AUCUNE";
            sansPerteCount++;
        }

        std::cout << src << " " << tgt << " " << srcBytes << " " << tgtBytes << " " << losses << "\n";
        totalBytesTarget += tgtBytes;
    }

    std::cout << "TOTAL " << totalBytesTarget << "\n";
    std::cout << "SANS_PERTE " << sansPerteCount << "\n";
    std::cout << "REFUSES " << refusesCount << "\n";

    return 0;
}