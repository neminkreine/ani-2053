#include <iostream>
#include <string>

using namespace std;

int main() {
    // Optimisation des entres-sorties
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    if (!(cin >> n)) return 0;

    long long total_points = 0;
    long long total_segments = 0;
    long long total_triangles = 0;
    long long total_refuses = 0;

    for (int i = 0; i < n; ++i) {
        string type;
        long long s;
        if (!(cin >> type >> s)) break;

        if (type == "POINTS") {
            long long count = s;
            long long rest = 0;
            total_points += count;
            cout << type << " " << s << " " << count << " POINTS " << rest << "\n";
        } 
        else if (type == "LINES") {
            long long count = s / 2;
            long long rest = s % 2;
            total_segments += count;
            cout << type << " " << s << " " << count << " SEGMENTS " << rest << "\n";
        } 
        else if (type == "LINE_STRIP") {
            long long count = (s >= 2) ? (s - 1) : 0;
            long long rest = (s >= 2) ? 0 : s;
            total_segments += count;
            cout << type << " " << s << " " << count << " SEGMENTS " << rest << "\n";
        } 
        else if (type == "TRIANGLES") {
            long long count = s / 3;
            long long rest = s % 3;
            total_triangles += count;
            cout << type << " " << s << " " << count << " TRIANGLES " << rest << "\n";
        } 
        else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN") {
            long long count = (s >= 3) ? (s - 2) : 0;
            long long rest = (s >= 3) ? 0 : s;
            total_triangles += count;
            cout << type << " " << s << " " << count << " TRIANGLES " << rest << "\n";
        } 
        else {
            total_refuses++;
            cout << type << " " << s << " REFUSE\n";
        }
    }

    // Affichage des bilans finaux
    cout << "POINTS " << total_points << "\n";
    cout << "SEGMENTS " << total_segments << "\n";
    cout << "TRIANGLES " << total_triangles << "\n";
    cout << "REFUSES " << total_refuses << "\n";

    return 0;
}