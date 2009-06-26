#include "pathexec.h"
#include "strerr.h"
#include "scan.h"
#include "str.h"
#include "case.h"
#include "sig.h"
#include "sgetopt.h"

#define FATAL "sigaction: fatal: "

void usage(void) {
  strerr_die1x(100,"sigaction: usage: sigaction [ -budi sig ] prog");
}

void unknown(const char *sigstr) {
  strerr_die3x(100,FATAL,"unknown signal: ",sigstr);
}

int main(int argc,char *const *argv) {
  int opt;
  int i;

  while ((opt = getopt(argc,argv,"b:u:d:i:")) != opteof)
    switch(opt) {
      case 'b':
	if (!sig_scan(optarg,&i)) unknown(optarg); sig_block(i); break;
      case 'u':
	if (!sig_scan(optarg,&i)) unknown(optarg); sig_unblock(i); break;
      case 'i':
	if (!sig_scan(optarg,&i)) unknown(optarg); sig_ignore(i); break;
      case 'd':
	if (!sig_scan(optarg,&i)) unknown(optarg); sig_uncatch(i); break;
      default: usage();
    }

  argc -= optind;
  argv += optind;
  if (!*argv) usage();
  pathexec(argv);
  strerr_die4sys(111,FATAL,"unable to run ",*argv,": ");
}
