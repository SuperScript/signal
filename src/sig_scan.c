#include "scan.h"
#include "str.h"
#include "case.h"
#include "sig.h"

int sig_scan(const char *s,int *i) {
  if (str_len(s) != scan_uint(s,i)) {
    if (case_equals(s,"ALRM")) *i = sig_alarm;
    else if (case_equals(s,"CHLD")) *i = sig_child;
    else if (case_equals(s,"CONT")) *i = sig_cont;
    else if (case_equals(s,"HUP")) *i = sig_hangup;
    else if (case_equals(s,"INT")) *i = sig_int;
    else if (case_equals(s,"PIPE")) *i = sig_pipe;
    else if (case_equals(s,"TERM")) *i = sig_term;
    else return 0;
  }
  return 1;
}
