#include "main.h"
#include "game.h"

void AgbMain(void) {
    InitializeHardware();
    transfer_size = sizeof(Island_agb_c);
    Game_Main();
}
