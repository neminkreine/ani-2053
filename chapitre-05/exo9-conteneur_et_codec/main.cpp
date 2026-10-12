#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

struct Track {
    std::string type;
    std::string code;
};

struct FileData {
    std::string name;
    std::string hexBytes;
    int p;
    std::vector<Track> tracks;
};

std::vector<unsigned char> parseHex(const std::string& hexStr) {
    std::vector<unsigned char> bytes;
    if (hexStr == "-" || hexStr.empty()) return bytes;
    for (size_t i = 0; i + 1 < hexStr.length(); i += 2) {
        std::string byteString = hexStr.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
        bytes.push_back(byte);
    }
    return bytes;
}


std::string translateCodec(const std::string& code) {
    if (code == "mp4a") return "aac";
    if (code == "Opus" || code == "opus") return "opus";
    if (code == "avc1" || code == "avc3") return "h264";
    if (code == "hvc1" || code == "hev1") return "h265";
    if (code == "vp08") return "vp8";
    if (code == "vp09") return "vp9";
    if (code == "mp4v") return "mpeg4";
    if (code == ".mp3") return "mp3";
    if (code == "twos" || code == "sowt" || code == "lpcm") return "pcm";
    return code;
}

int main() {
 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<FileData> files(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> files[i].name >> files[i].hexBytes >> files[i].p;
        files[i].tracks.resize(files[i].p);
        for (int j = 0; j < files[i].p; ++j) {
            std::cin >> files[i].tracks[j].type >> files[i].tracks[j].code;
        }
    }

    int countMP4 = 0;
    int countLisibles = 0;
    int countInconnus = 0;

    for (const auto& file : files) {
        std::vector<unsigned char> b = parseHex(file.hexBytes);
        std::string container = "INCONNU";

        if (b.size() >= 8 && b[4] == 0x66 && b[5] == 0x74 && b[6] == 0x79 && b[7] == 0x70) {
            container = "MP4";
        }
     
        else if (b.size() >= 4 && b[0] == 0x1A && b[1] == 0x45 && b[2] == 0xDF && b[3] == 0xA3) {
            container = "WEBM";
        }
        
        else if (b.size() >= 12 && 
                 b[0] == 0x52 && b[1] == 0x49 && b[2] == 0x46 && b[3] == 0x46 &&
                 b[8] == 0x57 && b[9] == 0x41 && b[10] == 0x56 && b[11] == 0x45) {
            container = "WAV";
        }
   
        else if (b.size() >= 4 && b[0] == 0x4F && b[1] == 0x67 && b[2] == 0x67 && b[3] == 0x53) {
            container = "OGG";
        }
    
        else if (b.size() >= 4 && b[0] == 0x66 && b[1] == 0x4C && b[2] == 0x61 && b[3] == 0x43) {
            container = "FLAC";
        }
    
        else if (b.size() >= 3 && b[0] == 0x49 && b[1] == 0x44 && b[2] == 0x33) {
            container = "MP3";
        }
      
        else if (b.size() >= 2 && b[0] == 0xFF && b[1] >= 0xE0) {
            container = "MP3";
        }

        std::cout << file.name << " " << container << "\n";

        if (container == "MP4") {
            countMP4++;

        
            for (int j = 0; j < file.p; ++j) {
                std::string typeStr = (file.tracks[j].type == "vide") ? "VIDEO" : "AUDIO";
                std::string codecName = translateCodec(file.tracks[j].code);
                std::cout << file.name << " PISTE " << (j + 1) << " " << typeStr << " " << codecName << "\n";
            }

            
            std::string verdict = "SANS_IMAGE";
            for (int j = 0; j < file.p; ++j) {
                if (file.tracks[j].type == "vide") {
                    std::string rawCode = file.tracks[j].code;
                   
                    if (rawCode == "mjpa" || rawCode == "jpeg" || rawCode == "MJPG" ||
                        rawCode == "avc1" || rawCode == "avc3" || rawCode == "hvc1" ||
                        rawCode == "hev1" || rawCode == "av01") {
                        verdict = "LISIBLE";
                    } else {
                        verdict = "ECHEC";
                    }
                    break;
                }
            }

            std::cout << file.name << " LECTEUR " << verdict << "\n";
            if (verdict == "LISIBLE") {
                countLisibles++;
            }
        } else if (container == "INCONNU") {
            countInconnus++;
        }
    }

    std::cout << "MP4 " << countMP4 << "\n";
    std::cout << "LISIBLES " << countLisibles << "\n";
    std::cout << "INCONNUS " << countInconnus << "\n";

    return 0;
}