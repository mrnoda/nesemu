#include <stdlib.h>

#include "nes/cartridge/cart.h"
#include "nes/cartridge/ines.h"

struct cart *load_cartridge(const char *filepath)
{
    struct ines_file *rom = load_rom(filepath);
    if (!rom)
    {
        return NULL;
    }
    else
    {
        struct cart *cart = calloc(1, sizeof(struct cart));
        print_rom_info(rom);
        unload_rom(rom);
        // TODO: read the ines contents into a cartridge
        return cart;
    }

}
