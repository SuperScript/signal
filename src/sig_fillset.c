/* Public domain. */

#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void sig_fillset(sig_set *ss) {
#ifdef HASSIGPROCMASK
  sigfillset(ss);
#else
  *ss = ~0;
#endif
}
