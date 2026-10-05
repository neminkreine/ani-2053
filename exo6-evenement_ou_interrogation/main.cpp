#include <iostream>
#include <string>

using namespace std;

int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long v = 0;
    long long N = 0;
    if (!(cin >> v >> N)) return 0;

    long long xe = 0;
    long long xi = 0;

    long long sauts_evenements = 0;
    long long sauts_interrogation = 0;
    long long manques = 0;

    
    bool space_pressed_events = false;
    bool right_pressed_events = false;
    bool left_pressed_events = false;

    bool space_pressed_interrogation = false;
    bool right_pressed_interrogation = false;
    bool left_pressed_interrogation = false;

    for (long long i = 1; i <= N; ++i) {
        long long k = 0;
        if (!(cin >> k)) break;

        
        long long space_events_this_frame = 0;

        for (long long j = 0; j < k; ++j) {
            string ev;
            cin >> ev;

            if (ev.empty()) continue;

            char action = ev[0];
            string name = ev.substr(1);

            if (name == "SPACE") {
                if (action == '+') {
                    sauts_evenements++;
                    space_events_this_frame++;
                    space_pressed_events = true;
                } else if (action == '-') {
                    space_pressed_events = false;
                }
            } else if (name == "RIGHT") {
                if (action == '+') {
                    xe += v;
                    right_pressed_events = true;
                } else if (action == '-') {
                    right_pressed_events = false;
                }
            } else if (name == "LEFT") {
                if (action == '+') {
                    xe -= v;
                    left_pressed_events = true;
                } else if (action == '-') {
                    left_pressed_events = false;
                }
            }
            
        }

       
        if (!space_pressed_events) {
            manques += space_events_this_frame;
        }

       
        space_pressed_interrogation = space_pressed_events;
        right_pressed_interrogation = right_pressed_events;
        left_pressed_interrogation = left_pressed_events;

        if (space_pressed_interrogation) {
            sauts_interrogation++;
        }
        if (right_pressed_interrogation) {
            xi += v;
        }
        if (left_pressed_interrogation) {
            xi -= v;
        }

      
        cout << i << " " << xe << " " << xi << "\n";
    }

    
    cout << "SAUTS EVENEMENTS " << sauts_evenements << "\n";
    cout << "SAUTS INTERROGATION " << sauts_interrogation << "\n";
    cout << "MANQUES " << manques << "\n";

    return 0;
}