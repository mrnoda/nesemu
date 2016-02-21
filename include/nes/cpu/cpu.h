#ifndef CPU_CPU_H
#define CPU_CPU_H

#include <stdint.h>
#include <stdbool.h>

/** Natural word size of the CPU. */
typedef uint8_t word_t;

/** A representation of the NES CPU, based on the MOS 6502. */
struct cpu
{
    uint8_t reg_a;
    uint8_t reg_x;
    uint8_t reg_y;
    uint8_t sp;
    uint16_t pc;
    uint8_t flags;
    uint8_t ram[0x800];
};

/** Initialise the state of the cpu. */
bool cpu_init(struct cpu *cpu);

/** Read a byte of memory from a given address. */
uint8_t read_mem(word_t address);

/** Write a byte to memory at a given address. */
void write_mem(word_t address, uint8_t value);

/** Fetch and execute the next instruction. */
void cpu_step(struct cpu *cpu);

#endif /* CPU_CPU_H */
