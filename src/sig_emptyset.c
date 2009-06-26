/* Public domain. */

#include <signal.h>
#include "sig.h"
#include "hassgprm.h"

void sig_emptyset(sig_set *ss) {
#ifdef HASSIGPROCMASK
  sigemptyset(ss);
#else
  *ss = 0;
#endif
}
