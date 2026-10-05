#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Optimisation des entres-sorties
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    if (!(cin >> N)) return 0;

    const double PI = 3.141592653589793;

    long long visibles_count = 0;
    long long refuses_count = 0;

    for (int i = 0; i < N; ++i) {
        long long r, n;
        if (!(cin >> r >> n)) break;

        // Verification du nombre de segments (doit etre >= 3)
        if (n < 3) {
            refuses_count++;
            cout << r << " " << n << " REFUSE\n";
            continue;
        }

        // Calcul de l'ecart g = r * (1 - cos(pi / n))
        double g = r * (1.0 - cos(PI / n));

        // ecart en millièmes de pixel, arrondi vers le bas (floor)
        long long ecart = static_cast<long long>(floor(g * 1000.0));

        // Cas d'un rayon nul (ou ecart nul)
        if (g == 0.0) {
            cout << r << " " << n << " " << ecart << " JAMAIS\n";
            continue;
        }

        // zoom = 100 / g, arrondi vers le haut (ceil)
        long long zoom = static_cast<long long>(ceil(100.0 / g));

        // Le verdict vaut VISIBLE si zoom vaut 100 ou moins, sinon INVISIBLE
        string verdict = (zoom <= 100) ? "VISIBLE" : "INVISIBLE";

        if (verdict == "VISIBLE") {
            visibles_count++;
        }

        cout << r << " " << n << " " << ecart << " " << zoom << " " << verdict << "\n";
    }

    // Affichage des bilans finaux
    cout << "VISIBLES " << visibles_count << "\n";
    cout << "REFUSES " << refuses_count << "\n";

    return 0;
}