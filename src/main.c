#include <getopt.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "nes/cartridge/cart.h"
#include "nes/debugger.h"
#include "nes/nes.h"
#include "version.h"

/* The NES console instance. */
struct nes nes;

void print_usage(const char *bin_name)
{
    printf("Usage: %s [options] <file>\n", bin_name);
}

int main(int argc, char *argv[])
{
    printf("nesemu %s\n", VERSION);

    bool debug = false;
    int option;
    while ((option = getopt(argc, argv, "")) != -1)
    {
        switch (option)
        {
            case '?':
                print_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Make sure we receive a non option (the rom file)
    if ((optind + 1) > argc)
    {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    // Optionally start the debug server
    if (debug)
    {
        // TODO: enable the debugger when it exists!
    }

    // Register any signal handlers
    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
        perror("Failed to set signal handler");
        exit(EXIT_FAILURE);
    }

    /** Play the rom file. */
    const char *rom_file = argv[argc - 1];
    nes_init(&nes);
    play_rom(rom_file);

    return EXIT_SUCCESS;
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

