#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    if (!(cin >> n)) return 0;

    int total_refuses = 0;

    for (int i = 0; i < n; ++i) {
        string nom;
        long long w, h, px, py, ox, oy, sx, sy, angle;
        if (!(cin >> nom >> w >> h >> px >> py >> ox >> oy >> sx >> sy >> angle)) break;

        long long normalized_angle = angle % 360;
        if (normalized_angle < 0) {
            normalized_angle += 360;
        }
        long long c = 0, s = 0;
        bool valid_angle = true;

        if (normalized_angle == 0) {
            c = 1; s = 0;
        } else if (normalized_angle == 90) {
            c = 0; s = 1;
        } else if (normalized_angle == 180) {
            c = -1; s = 0;
        } else if (normalized_angle == 270) {
            c = 0; s = -1;
        } else {
            valid_angle = false;
        }

        if (!valid_angle) {
            total_refuses++;
            cout << nom << " ANGLE REFUSE\n";
            continue;
        }

        long long local_x[4] = {0, w, w, 0};
        long long local_y[4] = {0, 0, h, h};

        long long world_x[4];
        long long world_y[4];

        long long min_x = 2e18, max_x = -2e18;
        long long min_y = 2e18, max_y = -2e18;

        for (int j = 0; j < 4; ++j) {
        
            long long ax = (local_x[j] - ox) * sx;
            long long ay = (local_y[j] - oy) * sy;

         
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;
   world_x[j] = px + rx;
            world_y[j] = py + ry;


            min_x = min(min_x, world_x[j]);
            max_x = max(max_x, world_x[j]);
            min_y = min(min_y, world_y[j]);
            max_y = max(max_y, world_y[j]);
        }

        cout << nom << " COINS";
        for (int j = 0; j < 4; ++j) {
            cout << " " << world_x[j] << " " << world_y[j];
        }
        cout << "\n";

        cout << nom << " BOITE " << min_x << " " << min_y << " " << max_x << " " << max_y << "\n";
    }

    cout << "REFUSES " << total_refuses << "\n";

    return 0;
}