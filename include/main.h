#ifndef MAIN_H
#define MAIN_H

void sig_handler(int sig_num);
void play_rom(const char *filename);

/** The NES console instance. */
extern struct nes nes;

#endif /* MAIN_H */
