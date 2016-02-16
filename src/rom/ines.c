#include <stdio.h>
#include <stdlib.h>

#include "rom/ines.h"

#define HI_NIBBLE(b) ((b >> 4) & 0x0F)
#define LO_NIBBLE(b) ((b) & 0x0F)

struct ines_file *load_rom(const char *filename)
{
    FILE *f = fopen(filename, "r"); 
    if (f == NULL)
    {
        fprintf(stderr, "Could not open file '%s'\n", filename);
        return NULL;
    }

    size_t hdr_size = sizeof(struct ines_header);
    void *ines = calloc(hdr_size, 1);
    if (ines == NULL)
    {
        return NULL;
    }

    size_t bytes_read = fread(ines, 1, hdr_size, f);
    if (bytes_read != hdr_size)
    {
        fprintf(stderr, "Failed to read rom file '%s\n", filename);
        return NULL;
    }

    fclose(f);
    return ines;
}

void unload_rom(struct ines_file *rom)
{
    free(rom);
}

void print_rom_info(struct ines_file *rom)
{
    struct ines_header header = rom->header;
    printf("Magic:        %s\n", header.magic);
    printf("PRG ROM:      %zuKB\n", (header.prg_rom_16_cnt << 4));
    printf("CHR ROM:      %zuKB\n", (header.chr_rom_8_cnt << 5));
    printf("PRG RAM:      %zuKB\n", (header.prg_ram_8_cnt << 5));
    printf("Mapper Num:   %zu\n", LO_NIBBLE(header.flags_6));
    
}
