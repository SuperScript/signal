/* Public domain. */

#ifndef SIG_H
#define SIG_H

#include <signal.h>
#include "hassgprm.h"

extern int sig_alarm;
extern int sig_child;
extern int sig_cont;
extern int sig_hangup;
extern int sig_int;
extern int sig_pipe;
extern int sig_term;

extern void (*sig_defaulthandler)();
extern void (*sig_ignorehandler)();

extern void sig_catch(int,void (*)());
#define sig_ignore(s) (sig_catch((s),sig_ignorehandler))
#define sig_uncatch(s) (sig_catch((s),sig_defaulthandler))

extern void sig_block(int);
extern void sig_unblock(int);
extern void sig_blocknone(void);
extern void sig_pause(void);

extern void sig_dfl(int);
extern int sig_scan(const char *,int *);

#ifdef HASSIGPROCMASK
typedef sigset_t sig_set;
#else
typedef int sig_set;
#endif

extern void sig_addset(sig_set *,int);
extern void sig_delset(sig_set *,int);
extern void sig_emptyset(sig_set *);
extern void sig_fillset(sig_set *);
extern void sig_wait(sig_set *);

#endif
