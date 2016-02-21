#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "nes/cartridge/cart.h"
#include "nes/nes.h"
#include "version.h"

/** The NES console instance. */
struct nes nes;

int main(int argc, char *argv[])
{
    printf("nesemu %s\n", VERSION);
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
        perror("Failed to handle SIGINT");
        exit(EXIT_FAILURE);
    }

    nes_init(&nes);
    play_rom(argv[1]);
    return 0;
}

void sig_handler(int sig_num)
{
    if (sig_num == SIGINT)
    {
        nes_destroy(&nes);
        putchar('\n');
    }
}

void play_rom(const char *filename)
{
    struct cart *cartridge = load_cartridge(filename);
    if (!cartridge)
    {
        fprintf(stderr, "Failed to load rom\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        nes_load(&nes, cartridge);
        nes_power_on(&nes);
    }
}

