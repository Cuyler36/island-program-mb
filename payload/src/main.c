#include "main.h"
#include "game.h"

/* Original address: 0x03000000 */
int transfer_size __attribute__((nocommon));

void AgbMain(void) {
    InitializeHardware();
    transfer_size = sizeof(Island_agb_c);
    Game_Main();
}
