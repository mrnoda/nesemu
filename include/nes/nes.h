#ifndef NES_NES_H
#define NES_NES_H

#include "nes/cartridge/cart.h"
#include "nes/cpu/cpu.h"

/** Power on the nes console. */
void nes_power_on();

/** Power off the nes console. */
void nes_power_off();

/** Load a cartridge into the system. */
void nes_load(struct cart *cart);

/** Reset the system, equivalent to a power cycle. */
inline void nes_reset();

/** A representation of a nintendo system */
struct nes
{
    struct cpu *cpu;
    struct cart *cart;
};

/** The system instance. */
extern struct nes nes;

#endif /* NES_NES_H */
