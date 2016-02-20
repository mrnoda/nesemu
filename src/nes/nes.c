#include "nes/nes.h"
#include "nes/cpu/cpu.h"

struct nes nes = {0};

void nes_power_on()
{
   cpu_init(nes.cpu);
}

void nes_power_off()
{
    // what should we do here?
}

void nes_load(struct cart *cart)
{
    nes.cart = cart;
}

inline void nes_reset()
{
    nes_power_off();
    nes_power_on();
}
