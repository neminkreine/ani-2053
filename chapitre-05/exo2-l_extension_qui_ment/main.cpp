#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct FileInfo {
    std::string name;
    long long size;
    std::string hexBytes;
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


std::string getExtension(const std::string& filename) {
    size_t dotPos = filename.find_last_of('.');
    if (dotPos == std::string::npos) return "";
    std::string ext = filename.substr(dotPos + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    return ext;
}

int main() {
   
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    if (!(std::cin >> N)) return 0;

    std::vector<FileInfo> files(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> files[i].name >> files[i].size;
        std::string bytesStr;
        std::cin >> bytesStr;
        files[i].hexBytes = bytesStr;
    }

    int countLUS = 0;
    int countMENSONGES = 0;
    int countREFUSES = 0;

    for (const auto& file : files) {
        std::string detectedFormat = "";
        std::vector<unsigned char> b = parseHex(file.hexBytes);

      
        if (file.size < 4) {
            detectedFormat = "REFUSE";
        } else {
         
            if (file.size >= 8 && b.size() >= 4 && b[0] == 0x89 && b[1] == 0x50 && b[2] == 0x4E && b[3] == 0x47) {
                detectedFormat = "PNG";
            }
         
            else if (b.size() >= 3 && b[0] == 0xFF && b[1] == 0xD8 && b[2] == 0xFF) {
                detectedFormat = "JPEG";
            }
            else if (b.size() >= 2 && b[0] == 0x42 && b[1] == 0x4D) {
                detectedFormat = "BMP";
            }

            else if (b.size() >= 4 && b[0] == 0x71 && b[1] == 0x6F && b[2] == 0x69 && b[3] == 0x66) {
                detectedFormat = "QOI";
            }

            else if (b.size() >= 4 && b[0] == 0x47 && b[1] == 0x49 && b[2] == 0x46 && b[3] == 0x38) {
                detectedFormat = "GIF";
            }

            else if (b.size() >= 4 && b[0] == 0x00 && b[1] == 0x00 && (b[2] == 0x01 || b[2] == 0x02) && b[3] == 0x00) {
                detectedFormat = "ICO";
            }
        
            else if (file.size >= 10 && b.size() >= 2 && b[0] == 0x23 && b[1] == 0x3F) {
                detectedFormat = "HDR";
            }
  
            else if (b.size() >= 4 && b[0] == 0x76 && b[1] == 0x2F && b[2] == 0x31 && b[3] == 0x01) {
                detectedFormat = "EXR";
            }
        
            else if (b.size() >= 2 && b[0] == 0x50 && b[1] >= 0x31 && b[1] <= 0x36) {
                if (b[1] == '1' || b[1] == '4') detectedFormat = "PBM";
                else if (b[1] == '2' || b[1] == '5') detectedFormat = "PGM";
                else if (b[1] == '3' || b[1] == '6') detectedFormat = "PPM";
            }
            else if (file.size >= 18 && b.size() >= 3 && (b[2] == 0x00 || b[2] == 0x01 || b[2] == 0x02 || b[2] == 0x03 || b[2] == 0x09 || b[2] == 0x0A || b[2] == 0x0B)) {
                detectedFormat = "TGA";
            }
            else {
                size_t idx = 0;
                if (b.size() >= 3 && b[0] == 0xEF && b[1] == 0xBB && b[2] == 0xBF) {
                    idx = 3;
                }
                while (idx < b.size() && (b[idx] == 0x20 || b[idx] == 0x09 || b[idx] == 0x0A || b[idx] == 0x0D)) {
                    idx++;
                }
               
                auto matchAt = [&](size_t start, const std::vector<unsigned char>& pat) {
                    if (start + pat.size() > b.size()) return false;
                    for (size_t k = 0; k < pat.size(); ++k) {
                        if (b[start + k] != pat[k]) return false;
                    }
                    return true;
                };

                std::vector<unsigned char> xmlPat = {0x3C, 0x3F, 0x78, 0x6D, 0x6C};
                std::vector<unsigned char> svgPat = {0x3C, 0x73, 0x76, 0x67};

                if (matchAt(idx, xmlPat) || matchAt(idx, svgPat)) {
                    detectedFormat = "SVG";
                } else {
                    detectedFormat = "REFUSE";
                }
            }
        }

        if (detectedFormat == "REFUSE") {
            std::cout << file.name << " REFUSE\n";
            countREFUSES++;
        } else {
            std::string ext = getExtension(file.name);
            bool match = false;
            if (detectedFormat == "PNG" && ext == "png") match = true;
            else if (detectedFormat == "JPEG" && (ext == "jpg" || ext == "jpeg")) match = true;
            else if (detectedFormat == "BMP" && ext == "bmp") match = true;
            else if (detectedFormat == "QOI" && ext == "qoi") match = true;
            else if (detectedFormat == "GIF" && ext == "gif") match = true;
            else if (detectedFormat == "ICO" && (ext == "ico" || ext == "cur")) match = true;
            else if (detectedFormat == "HDR" && ext == "hdr") match = true;
            else if (detectedFormat == "EXR" && ext == "exr") match = true;
            else if (detectedFormat == "PBM" && ext == "pbm") match = true;
            else if (detectedFormat == "PGM" && ext == "pgm") match = true;
            else if (detectedFormat == "PPM" && ext == "ppm") match = true;
            else if (detectedFormat == "TGA" && ext == "tga") match = true;
            else if (detectedFormat == "SVG" && ext == "svg") match = true;

            if (match) {
                std::cout << file.name << " " << detectedFormat << " OK\n";
                countLUS++;
            } else {
                std::cout << file.name << " " << detectedFormat << " MENT\n";
                countLUS++;
                countMENSONGES++;
            }
        }
    }

    std::cout << "LUS " << countLUS << "\n";
    std::cout << "MENSONGES " << countMENSONGES << "\n";
    std::cout << "REFUSES " << countREFUSES << "\n";

    return 0;
}