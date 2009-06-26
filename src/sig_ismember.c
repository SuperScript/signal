/* Public domain. */

#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void sig_ismember(sig_set *ss,int sig) {
#ifdef HASSIGPROCMASK
  sigismember(ss,sig);
#else
  ((*ss & (1 << (sig - 1))) != 0);
#endif
}
