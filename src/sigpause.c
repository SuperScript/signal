#include <signal.h>
#include "pathexec.h"
#include "strerr.h"
#include "scan.h"
#include "str.h"
#include "case.h"
#include "sig.h"
#include "sgetopt.h"
#include "exit.h"
#include "error.h"

#define FATAL "sigpause: fatal: "

void usage(void) {
  strerr_die1x(100,"sigpause: usage: sigpause [ -budic sig -an ] [ prog ]");
}

void unknown(const char *sigstr) {
  strerr_die3x(100,FATAL,"unknown signal: ",sigstr);
}

void signull(int i) {
}

int main(int argc,char *const *argv) {
  int opt;
  int i;
  sig_set ss;

  sig_emptyset(&ss);
  while ((opt = getopt(argc,argv,"c:d:b:u:an")) != opteof)
    switch(opt) {
      case 'c':
	if (!sig_scan(optarg,&i)) unknown(optarg);
	sig_delset(&ss,i); sig_catch(i,signull); break;
      case 'd':
	if (!sig_scan(optarg,&i)) unknown(optarg);
	sig_delset(&ss,i); sig_uncatch(i); break;
      case 'b':
	if (!sig_scan(optarg,&i)) unknown(optarg);
	sig_addset(&ss,i); break;
      case 'u':
	if (!sig_scan(optarg,&i)) unknown(optarg);
	sig_delset(&ss,i); break;
      case 'a':
	sig_fillset(&ss); break;
      case 'n':
	sig_emptyset(&ss); break;
      default: usage();
    }

  argc -= optind;
  argv += optind;

  sig_wait(&ss);
  if (!*argv) _exit(0);
  pathexec(argv);
  strerr_die4sys(111,FATAL,"unable to run ",*argv,": ");
}
