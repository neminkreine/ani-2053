#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include <vector>
#include <string>

int nkmain(const NkEntryState &state) {
    std::vector<std::string> nomsDroits = {
        "frame", "resizable", "minimizable", "movable", 
        "closable", "maximizable", "canFullscreen"
    };

    for (int i = 0; i < 7; ++i) {
        NkWindowConfig cfg;
        cfg.title  = "Test droit: " + nomsDroits[i];
        cfg.width  = 800;
        cfg.height = 600;

      
        if (i == 0) cfg.frame         = false;
        if (i == 1) cfg.resizable     = false;
        if (i == 2) cfg.minimizable   = false;
        if (i == 3) cfg.movable       = false;
        if (i == 4) cfg.closable      = false;
        if (i == 5) cfg.maximizable   = false;
        if (i == 6) cfg.canFullscreen = false;

        NkWindow window(cfg);
        if (!window.IsOpen()) {
            continue;
        }

        while (window.IsOpen()) {
            NkEvent event;
            while (window.PollEvent(event)) {
                if (event.type == NkEventType::Closed) {
                    window.Close();
                }
            }
            window.Clear();
            window.Display();
        }
    }
    return 0;
}