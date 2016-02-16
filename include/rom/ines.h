#ifndef INES_H
#define INES_H

#include <stdint.h>

/* iNES file header format, as described at wiki.nesdev.com */
struct ines_header
{
    uint8_t magic[4]; // 0x4e 0x45 0x53 0x1a
    uint8_t prg_rom_16_cnt;
    uint8_t chr_rom_8_cnt;
    uint8_t flags_6;
    uint8_t flags_7;
    uint8_t prg_ram_8_cnt;
    uint8_t flags_9;
    uint8_t flags_10;
    uint8_t zero_pad[5];
};

/* iNES file, containing both header and data sections. */
struct ines_file
{
    struct ines_header header;
    uint8_t *rom_data;
};

struct ines_file *load_rom(const char *filename);
void unload_rom(struct ines_file *rom);
void print_rom_info(struct ines_file *rom);

#endif
