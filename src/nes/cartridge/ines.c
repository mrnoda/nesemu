#include <stdio.h>
#include <stdlib.h>

#include "nes/cartridge/ines.h"

static const char *str_header_version(enum ines_header_variant header_variant);

struct ines_file *load_rom(const char *filename)
{
    FILE *f = fopen(filename, "r"); 
    if (!f)
    {
        fprintf(stderr, "Could not open file '%s'\n", filename);
        return NULL;
    }

    // Verify the magic ines constant occupies the first 4 bytes of the file
    if (fgetc(f) != 'N' || fgetc(f) != 'E' || fgetc(f) != 'S' || fgetc(f) != 0x1A)
    {
        fprintf(stderr, "File format unsupported, expected iNES\n");
        goto error;
    }
    rewind(f);

    const size_t hdr_size = sizeof(struct ines_header);
    void *ines = calloc(hdr_size, 1);
    if (fread(ines, 1, hdr_size, f) != hdr_size)
    {
        fprintf(stderr, "Failed to read rom file '%s\n", filename);
        goto error;
    }

    // TODO: read the rest of the file into memory

    fclose(f);
    return ines;

    error:
        fclose(f);
        return NULL;
}

void unload_rom(struct ines_file *rom)
{
    free(rom);
}

enum ines_header_variant header_version(const struct ines_header *header)
{
    // nesdev recommended detection method
    //
    // If byte 7 AND $0C = $08, and the size taking into account byte 9 does 
    // not exceed the actual size of the ROM image, then NES 2.0.
    //
    // If byte 7 AND $0C = $00, and bytes 12-15 are all 0, then iNES.
    //
    // TODO: actually detect the version!
    //
    return ines;
}

static const char *str_header_version(enum ines_header_variant header_variant)
{
    switch(header_variant)
    {
        case ines:
            return "iNES";
        case archaic:
            return "Archaic iNES";
        case nes_20:
            return "NES 2.0";
        default:
            return "Unknown";
    }
}

void print_rom_info(const struct ines_file *rom)
{
    struct ines_header header = rom->header;

    printf("iNES ROM Properties\n");
    printf("-------------------\n");
    printf("Version:               %s\n", str_header_version(header_version(&header)));
    printf("Magic:                 %.3s\n", header.magic);
    printf("PRG ROM Size:          %zuKB\n", (header.prg_rom_16_cnt << 4));
    printf("CHR ROM Size:          %zuKB\n", (header.chr_rom_8_cnt << 3));
    printf("CHR RAM:               %s\n", (header.chr_rom_8_cnt == 0 ? "yes" : "no"));
    printf("PRG RAM:               %zuKB\n", (header.prg_ram_8_cnt << 5));
    printf("Mapper Num:            %zu\n", (header.flags_6 >> 4) & 0x0F);
    printf("Mirroring:             %s\n", header.flags_6 & 0x01 ? "vertical" : "horizontal"); 
    printf("Battery Backed RAM:    %s\n", (header.flags_6 >> 1) & 0x01 ? "yes" : "no");
    printf("Trainer:               %s\n", (header.flags_6 >> 2) & 0x01 ? "yes" : "no");
    printf("4 Screen VRAM:         %s\n", (header.flags_6 >> 3) & 0x01 ? "yes" : "no");
    printf("VS Unisystem:          %s\n", header.flags_7 & 0x0 ? "yes" : "no");
    printf("Playchoice-10:         %s\n", (header.flags_7 >> 1) & 0x01 ? "yes" : "no");
    printf("NES-2.0:               %s\n", (header.flags_7 >> 2) & 0x02 ? "yes" : "no");
    printf("TV System:             %s\n", header.flags_9 & 0x01 ? "PAL" : "NTSC");
    printf("-------------------\n");
}
