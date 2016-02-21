#ifndef NES_DEBUGGER_H
#define NES_DEBUGGER_H

/* Start the debug service, listening on a given TCP port */
int debug_svc_start(const int port);

/* Stop a previously started debugging service. */
void debug_svc_stop(int fd);

#endif
