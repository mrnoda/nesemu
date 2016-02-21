#include "nes/cpu/cpu.h"

bool cpu_init(struct cpu *cpu)
{
    cpu->reg_a = 0;
    cpu->reg_x = 0;
    cpu->reg_y = 0;
    cpu->sp = 0;
    cpu->pc = 0xFF;
}

void cpu_step(struct cpu *cpu)
{
    // todo: fetch/decode/execute the next instruction
}

