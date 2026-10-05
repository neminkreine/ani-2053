#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long C = 0, R = 0, W = 0, H = 0, F = 0, D = 0, P = 0;
    if (!(cin >> C >> R >> W >> H >> F >> D >> P)) return 0;

    long long N = 0;
    if (!(cin >> N)) return 0;

    long long current_case = 0;
    long long accumulated_time = 0;

    long long avances_count = 0;
    long long plafonnes_count = 0;

    for (long long i = 0; i < N; ++i) {
        long long dt = 0;
        cin >> dt;

    
        if (dt > P) {
            dt = P;
            plafonnes_count++;
        }

      
        accumulated_time += dt;

        
        while (accumulated_time >= D) {
            accumulated_time -= D;
            current_case = (current_case + 1) % F;
            avances_count++;
        }

        
        long long col = current_case % C;
        long long row = current_case / C;
        long long x = col * W;
        long long y = row * H;

        
        cout << current_case << " " << x << " " << y << " " << W << " " << H << "\n";
    }

    
    cout << "AVANCES " << avances_count << "\n";
    cout << "PLAFONNES " << plafonnes_count << "\n";

    return 0;
}