/* Public domain. */

#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void sig_addset(sig_set *ss,int sig) {
#ifdef HASSIGPROCMASK
  sigaddset(ss,sig);
#else
  *ss |= (1 << (sig - 1));
#endif
}
