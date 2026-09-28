#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.frame = false; 

    NkWindow window(cfg);
    bool dragging = false;

    while (window.IsOpen()) {
        NkEvent e;
        while (window.PollEvent(e)) {
            
            if (e.family == NkEventFamily::MOUSE) {
                if (e.mouseButton == NkMouseButton::Left) {
                    if (e.type == NkMouseEventType::ButtonPressed && e.mouseY < 30) dragging = true;
                    if (e.type == NkMouseEventType::ButtonReleased) dragging = false;
                }
                if (e.type == NkMouseEventType::Moved && dragging) {
                    
                }
            }
        }
    }
    return 0;
}