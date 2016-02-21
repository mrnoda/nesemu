#ifndef NES_NES_H
#define NES_NES_H

#include <stdbool.h>

#include "nes/cartridge/cart.h"
#include "nes/cpu/cpu.h"

/** A representation of a nintendo system */
struct nes
{
    volatile bool alive;
    struct cpu *cpu;
    struct cart *cart;
};

/** Initialise a new console. */
void nes_init(struct nes *nes);

/** Power on the nes console. */
void nes_power_on(struct nes *nes);

/** Power off the nes console. */
void nes_power_off(struct nes *nes);

/** Load a cartridge into the nes console. */
void nes_load(struct nes *nes, struct cart *cart);

/** Destroy a console instance. */
void nes_destroy(struct nes *nes);

/** Reset the console, equivalent to a power cycle. */
static inline void nes_reset(struct nes *nes);

#endif /* NES_NES_H */
