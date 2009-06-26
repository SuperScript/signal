/* Public domain. */

#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void sig_wait(sig_set *ss) {
#ifdef HASSIGPROCMASK
  sigsuspend(ss);
#else
  sigpause(*ss);
#endif
}
