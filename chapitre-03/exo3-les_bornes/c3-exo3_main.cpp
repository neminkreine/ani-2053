#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"

int nkmain(const NkEntryState &state) {
    NkWindowConfig cfg;
    cfg.title  = "Test Taille Minimale";
    cfg.width  = 800;
    cfg.height = 600;
    
    
    cfg.minWidth  = 400;
    cfg.minHeight = 300;

    NkWindow window(cfg);
    if (!window.IsOpen()) {
        return -1;
    }

    while (window.IsOpen()) {
      
    }
    return 0;
}