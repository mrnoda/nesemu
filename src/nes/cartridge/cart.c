#include <stdlib.h>

#include "nes/cartridge/cart.h"
#include "nes/cartridge/ines.h"

struct cart *load_cartridge(const char *filepath)
{
    struct ines_file *rom = load_rom(filepath);
    if (rom)
    {
        print_rom_info(rom);
    }

    // TODO: Create a cartridge from the ines struct
    return NULL;
}
