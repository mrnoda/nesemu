#ifndef MAIN_H
#define MAIN_H

/* Print application usage statement. */
void print_usage(const char* bin_name);

/* Handle signals received by the process. */
void sig_handler(int sig_num);

/* Initialise the debug service on a given TCP port. */
void init_debug_svc(const int port);

/* Play a rom file. */
void play_rom(const char *filename);

/* The NES console instance. */
extern struct nes nes;

#endif /* MAIN_H */
