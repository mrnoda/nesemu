#include "nes/cpu/cpu.h"

const int CLOCK_SPEED_HZ = 1790000;

bool cpu_init(struct cpu *cpu)
{
    cpu->reg_a = 0;
    cpu->reg_x = 0;
    cpu->reg_y = 0;
    cpu->sp = 0;
    cpu->pc = 0xFF;
}

