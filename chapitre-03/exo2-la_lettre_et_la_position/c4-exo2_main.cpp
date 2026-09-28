#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include <iostream>

int nkmain(const NkEntryState &state) {
    NkWindow window(NkWindowConfig());

    while (window.IsOpen()) {

        NkEvent e;
        
        while (window.PollEvent(e)) {
            
            if (e.family == NkEventFamily::KEYBOARD && e.pressed) {
                std::cout << "Touche physique (code): " << static_cast<int>(e.key) 
                          << " | Caractère / Lettre: " << e.character << std::endl;
            }
        }
    }
    return 0;
}