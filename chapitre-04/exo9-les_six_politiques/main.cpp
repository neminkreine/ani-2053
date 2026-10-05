#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


long long round_div(long long a, long long b) {
    return (2 * a + b) / (2 * b);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long RW, RH, AW, AH, W, H;
    if (!(cin >> RW >> RH >> AW >> AH >> W >> H)) return 0;

    bool has_ref = (RW > 0 && RH > 0);

   
    struct PolicyResult {
        string name;
        long long vx, vy, vw, vh, mw, mh;
    };

    PolicyResult res[6];

    
    res[0] = {"FOLLOW_WINDOW", 0, 0, W, H, W, H};

   
    if (!has_ref) {
        res[1] = {"STRETCH", 0, 0, W, H, W, H};
    } else {
        res[1] = {"STRETCH", 0, 0, W, H, RW, RH};
    }

   
    if (!has_ref) {
        res[2] = {"FIT_LETTERBOX", 0, 0, W, H, W, H};
    } else {
        long long vw, vh;
        
        if (W * RH <= H * RW) {
            vw = W;
            vh = round_div(RH * W, RW);
        } else {
            vh = H;
            vw = round_div(RW * H, RH);
        }
        long long vx = (W - vw) / 2;
        long long vy = (H - vh) / 2;
        res[2] = {"FIT_LETTERBOX", vx, vy, vw, vh, RW, RH};
    }

    
    if (!has_ref) {
        res[3] = {"INTEGER_SCALE", 0, 0, W, H, W, H};
    } else {
        if (W >= RW && H >= RH) {
            long long k = min(W / RW, H / RH);
            if (k <= 0) {
                
                long long vw, vh;
                if (W * RH <= H * RW) {
                    vw = W;
                    vh = round_div(RH * W, RW);
                } else {
                    vh = H;
                    vw = round_div(RW * H, RH);
                }
                long long vx = (W - vw) / 2;
                long long vy = (H - vh) / 2;
                res[3] = {"INTEGER_SCALE", vx, vy, vw, vh, RW, RH};
            } else {
                long long vw = RW * k;
                long long vh = RH * k;
                long long vx = (W - vw) / 2;
                long long vy = (H - vh) / 2;
                res[3] = {"INTEGER_SCALE", vx, vy, vw, vh, RW, RH};
            }
        } else {
           
            long long vw, vh;
            if (W * RH <= H * RW) {
                vw = W;
                vh = round_div(RH * W, RW);
            } else {
                vh = H;
                vw = round_div(RW * H, RH);
            }
            long long vx = (W - vw) / 2;
            long long vy = (H - vh) / 2;
            res[3] = {"INTEGER_SCALE", vx, vy, vw, vh, RW, RH};
        }
    }

    
    if (!has_ref) {
        res[4] = {"FIT_CROP", 0, 0, W, H, W, H};
    } else {
        long long mw, mh;
        
        if (W * RH > H * RW) {
            mw = RW;
            mh = round_div(RW * H, W);
        } else {
            mh = RH;
            mw = round_div(RH * W, H);
        }
        res[4] = {"FIT_CROP", 0, 0, W, H, mw, mh};
    }

   
    res[5] = {"MANUAL", 0, 0, AW, AH, AW, AH};

    
    long long bandes_count = 0;
    for (int i = 0; i < 6; ++i) {
       
        if (res[i].vw < W || res[i].vh < H) {
            bandes_count++;
        }
    }

    
    bool deformation_oui = false;
    if (has_ref) {
        if (W * RH != H * RW) {
            deformation_oui = true;
        }
    }

    
    for (int i = 0; i < 6; ++i) {
        cout << res[i].name << " " 
             << res[i].vx << " " 
             << res[i].vy << " " 
             << res[i].vw << " " 
             << res[i].vh << " " 
             << res[i].mw << " " 
             << res[i].mh << "\n";
    }

  
    cout << "BANDES " << bandes_count << "\n";
    cout << "DEFORMATION " << (deformation_oui ? "OUI" : "NON") << "\n";

    return 0;
}