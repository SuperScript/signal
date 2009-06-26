#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "pathexec.h"
#include "strerr.h"
#include "scan.h"
#include "sig.h"
#include "sgetopt.h"
#include "wait.h"

#define FATAL "sigalarm: fatal: "

void usage(void) {
  strerr_die1x(100,"sigalarm: usage: sigalarm [ -a -s sig ] timeout prog");
}

int child = 0;
int signum;

void sigchld(void) {
  alarm(0);
}

void sigalarm(void) {
  alarm(0);
  if (kill(child,signum) == -1)
    strerr_die2sys(111,FATAL,"cannot kill child: ");
}

int main(int argc,char *const *argv) {
  unsigned int timeout;
  int opt;
  int wstat;
  int r;

  signum = 0;
  while ((opt = getopt(argc,argv,"s:a")) != opteof)
    switch(opt) {
      case 's':
	if (!sig_scan(optarg,&signum))
	  strerr_die3x(100,FATAL,"unknown signal: ",optarg);
	break;
      case 'a': signum = 0; break;
      default: usage();
    }

  argc -= optind;
  argv += optind;
  if (!*argv) usage();
  scan_uint(*argv,&timeout);
  if (!*++argv) usage();

  if (!signum) {
    alarm(timeout);
    pathexec(argv);
    strerr_die4sys(111,FATAL,"unable to run ",*argv,": ");
  }

  child = fork();
  switch(child) {
    case 0:
      pathexec(argv);
      strerr_die4sys(111,FATAL,"unable to run ",*argv,": ");
    case -1:
      strerr_die2sys(111,FATAL,"unable to fork: ");
  }

  sig_catch(sig_child,sigchld);
  sig_catch(sig_alarm,sigalarm);
  alarm(timeout);
  r = wait_pid(&wstat,child);
  if (r == -1) strerr_die2sys(111,FATAL,"cannot reap child: ");
  _exit(wait_exitcode(wstat));
}
