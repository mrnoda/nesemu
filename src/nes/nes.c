#include <stdlib.h>

#include "nes/nes.h"
#include "nes/cpu/cpu.h"

void nes_init(struct nes *nes)
{
    nes->cpu = calloc(1, sizeof(struct cpu));
}

void nes_destroy(struct nes *nes)
{
    if (nes->alive)
    {
        nes_power_off(nes);
    }

    // Release heap memory
    if (nes->cart)
    {
        free(nes->cart);
    }
    free(nes->cpu);
    //    free(nes);
}

void nes_power_on(struct nes *nes)
{
    if (!nes->alive)
    {
        cpu_init(nes->cpu);
        nes->alive = true;

        while (nes->alive)
        {
            cpu_step(nes->cpu);
        }
    }
}

void nes_power_off(struct nes *nes)
{
    nes->alive = false;
}

void nes_load(struct nes *nes, struct cart *cart)
{
    nes->cart = cart;
}

static inline void nes_reset(struct nes *nes)
{
    nes_power_off(nes);
    nes_power_on(nes);
}
