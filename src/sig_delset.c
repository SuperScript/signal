/* Public domain. */

#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void sig_delset(sig_set *ss,int sig) {
#ifdef HASSIGPROCMASK
  sigdelset(ss,sig);
#else
  *ss &= ((~0) & ~(1 << (sig - 1)));
#endif
}
