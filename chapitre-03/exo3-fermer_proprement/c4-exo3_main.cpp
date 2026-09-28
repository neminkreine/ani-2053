#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

int nkmain(const NkEntryState &state) {
    NkWindow window(NkWindowConfig());

    while (window.IsOpen()) {
        NkEvent e;
        while (window.PollEvent(e)) {
            
            if ((e.family == NkEventFamily::WINDOW && e.type == NkWindowEventType::Closed) ||
                (e.family == NkEventFamily::KEYBOARD && e.key == NkKey::NK_ESCAPE && e.pressed)) {
                window.Close();
            }
        }
    }
    return 0;
}