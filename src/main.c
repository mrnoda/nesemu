#include <stdio.h>
#include <stdlib.h>

#include "rom/ines.h"

void reset_nes(const char *filename);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    reset_nes(argv[1]);

    return EXIT_SUCCESS;
}

void reset_nes(const char *filename)
{
    struct ines_file *rom = load_rom(filename);
    if (!rom)
    {
        fprintf(stderr, "Failed to load rom\n");
        unload_rom(rom);
        exit(EXIT_FAILURE);
    }

    print_rom_info(rom);
    unload_rom(rom);
}
