#ifndef NES_CARTRIDGE_CART_H
#define NES_CARTRIDGE_CART_H

#include <stdint.h>

/* A cart represents a physical cartridge to be loaded into the NES. */
struct cart
{
    uint8_t reserved;
};

/* Load a cartridge from a file. */
struct cart *load_cartridge(const char *filepath);

#endif /* NES_CARTRIDGE_CART_H */
