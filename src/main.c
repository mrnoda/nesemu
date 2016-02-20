#include <stdio.h>
#include <stdlib.h>

#include "nes/cartridge/cart.h"
#include "nes/nes.h"

int play_rom(const char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    return play_rom(argv[1]);
}

int play_rom(const char *filename)
{
    struct cart *cartridge = load_cartridge(filename);
    if (!cartridge)
    {
        fprintf(stderr, "Failed to load rom\n");
        return EXIT_FAILURE;
    }
    else
    {
        nes_load(cartridge);
        nes_reset();
        return EXIT_SUCCESS;
    }
}

