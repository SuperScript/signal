# Don't edit Makefile!  Use conf-* for configuration.

SHELL=/bin/sh

default: it

clean:
	rm -f alloc.o alloc_re.o buffer_2.o buffer_put.o buffer_write.o \
	byte_copy.o byte_diff.o case_diffs.o choose compile env.o error.o \
	error_str.o hassgact.h hassgprm.h haswaitp.h it load makeinclude makelib \
	makescrip pathexec_env.o pathexec_run.o scan_uint.o scan_ulong.o \
	sgetopt.o sig.o sig_addset.o sig_block.o sig_catch.o sig_delset.o \
	sig_emptyset.o sig_fillset.o sig_scan.o sig_wait.o sigaction sigaction.o \
	sigalarm sigalarm.o sigpause sigpause.o str_chr.o str_diff.o str_len.o \
	str_start.o stralloc_cat.o stralloc_catb.o stralloc_cats.o \
	stralloc_eady.o stralloc_opyb.o stralloc_opys.o stralloc_pend.o \
	strerr_die.o strerr_sys.o subgetopt.o sysdeps systype unix.a wait_pid.o

alloc.o: compile alloc.c alloc.h error.h
	./compile alloc.c

alloc_re.o: compile alloc_re.c alloc.h byte.h
	./compile alloc_re.c

buffer_2.o: compile buffer_2.c buffer.h
	./compile buffer_2.c

buffer_put.o: compile buffer_put.c buffer.h str.h byte.h error.h
	./compile buffer_put.c

buffer_write.o: compile buffer_write.c buffer.h
	./compile buffer_write.c

byte_copy.o: compile byte_copy.c byte.h
	./compile byte_copy.c

byte_diff.o: compile byte_diff.c byte.h
	./compile byte_diff.c

case_diffs.o: compile case_diffs.c case.h
	./compile case_diffs.c

choose: makeinclude makescrip warn-auto.sh choose.sh
	rm -f choose
	./makeinclude code warn-auto.sh choose.sh \
	| ./makescrip choose choose choose.tmp \
	> choose
	chmod 755 choose

compile: conf-cc print-cc.sh systype warn-auto.sh
	rm -f compile
	sh print-cc.sh > compile
	chmod 755 compile

env.o: compile env.c str.h env.h
	./compile env.c

error.o: compile error.c error.h
	./compile error.c

error_str.o: compile error_str.c error.h
	./compile error_str.c

hassgact.h: choose compile trysgact.c hassgact.h1 hassgact.h2
	./choose cl trysgact hassgact.h1 hassgact.h2 > hassgact.h

hassgprm.h: choose compile trysgprm.c hassgprm.h1 hassgprm.h2
	./choose cl trysgprm hassgprm.h1 hassgprm.h2 > hassgprm.h

haswaitp.h: choose compile load trywaitp.c haswaitp.h1 haswaitp.h2
	./choose cl trywaitp haswaitp.h1 haswaitp.h2 >haswaitp.h

it: sysdeps sigaction sigalarm sigpause

load: conf-ld print-ld.sh systype warn-auto.sh
	rm -f load
	sh print-ld.sh > load
	chmod 755 load

makeinclude: makeinclude.sh warn-auto.sh
	rm -f makeinclude
	cat warn-auto.sh makeinclude.sh > makeinclude
	chmod 755 makeinclude

makelib: print-ar.sh systype warn-auto.sh
	rm -f makelib
	sh print-ar.sh > makelib
	chmod 755 makelib

makescrip: warn-auto.sh print-makescrip.sh conf-scrip home
	rm -f makescrip
	sh print-makescrip.sh < conf-scrip > makescrip
	chmod 755 makescrip

pathexec_env.o: compile pathexec_env.c stralloc.h alloc.h str.h byte.h \
env.h pathexec.h gen_alloc.h
	./compile pathexec_env.c

pathexec_run.o: compile pathexec_run.c error.h stralloc.h str.h env.h \
pathexec.h gen_alloc.h
	./compile pathexec_run.c

scan_uint.o: compile scan_uint.c scan.h
	./compile scan_uint.c

scan_ulong.o: compile scan_ulong.c scan.h
	./compile scan_ulong.c

sgetopt.o: compile sgetopt.c buffer.h sgetopt.h subgetopt.h subgetopt.h
	./compile sgetopt.c

sig.o: compile sig.c sig.h hassgprm.h
	./compile sig.c

sig_addset.o: compile sig_addset.c sig.h hassgprm.h hassgprm.h
	./compile sig_addset.c

sig_block.o: compile sig_block.c sig.h hassgprm.h hassgprm.h
	./compile sig_block.c

sig_catch.o: compile sig_catch.c sig.h hassgact.h hassgprm.h
	./compile sig_catch.c

sig_delset.o: compile sig_delset.c sig.h hassgprm.h hassgprm.h
	./compile sig_delset.c

sig_emptyset.o: compile sig_emptyset.c sig.h hassgprm.h hassgprm.h
	./compile sig_emptyset.c

sig_fillset.o: compile sig_fillset.c sig.h hassgprm.h hassgprm.h
	./compile sig_fillset.c

sig_scan.o: compile sig_scan.c scan.h str.h case.h sig.h hassgprm.h
	./compile sig_scan.c

sig_wait.o: compile sig_wait.c sig.h hassgprm.h hassgprm.h
	./compile sig_wait.c

sigaction: load sigaction.o unix.a
	./load sigaction unix.a 

sigaction.o: compile sigaction.c pathexec.h strerr.h scan.h str.h case.h \
sig.h sgetopt.h hassgprm.h subgetopt.h
	./compile sigaction.c

sigalarm: load sigalarm.o unix.a
	./load sigalarm unix.a 

sigalarm.o: compile sigalarm.c pathexec.h strerr.h scan.h sig.h sgetopt.h \
wait.h hassgprm.h subgetopt.h
	./compile sigalarm.c

sigpause: load sigpause.o unix.a
	./load sigpause unix.a 

sigpause.o: compile sigpause.c pathexec.h strerr.h scan.h str.h case.h \
sig.h sgetopt.h exit.h error.h hassgprm.h subgetopt.h
	./compile sigpause.c

str_chr.o: compile str_chr.c str.h
	./compile str_chr.c

str_diff.o: compile str_diff.c str.h
	./compile str_diff.c

str_len.o: compile str_len.c str.h
	./compile str_len.c

str_start.o: compile str_start.c str.h
	./compile str_start.c

stralloc_cat.o: compile stralloc_cat.c byte.h stralloc.h gen_alloc.h
	./compile stralloc_cat.c

stralloc_catb.o: compile stralloc_catb.c stralloc.h byte.h gen_alloc.h
	./compile stralloc_catb.c

stralloc_cats.o: compile stralloc_cats.c byte.h str.h stralloc.h \
gen_alloc.h
	./compile stralloc_cats.c

stralloc_eady.o: compile stralloc_eady.c alloc.h stralloc.h \
gen_allocdefs.h gen_alloc.h
	./compile stralloc_eady.c

stralloc_opyb.o: compile stralloc_opyb.c stralloc.h byte.h gen_alloc.h
	./compile stralloc_opyb.c

stralloc_opys.o: compile stralloc_opys.c byte.h str.h stralloc.h \
gen_alloc.h
	./compile stralloc_opys.c

stralloc_pend.o: compile stralloc_pend.c alloc.h stralloc.h \
gen_allocdefs.h gen_alloc.h
	./compile stralloc_pend.c

strerr_die.o: compile strerr_die.c buffer.h exit.h strerr.h
	./compile strerr_die.c

strerr_sys.o: compile strerr_sys.c error.h strerr.h
	./compile strerr_sys.c

subgetopt.o: compile subgetopt.c subgetopt.h
	./compile subgetopt.c

sysdeps: systype compile load
	rm -f sysdeps
	cat systype compile load >> sysdeps
	grep sysdep *.h 2>/dev/null >> sysdeps || :

systype: find-systype.sh trycpp.c x86cpuid.c
	sh find-systype.sh > systype

unix.a: makelib alloc.o alloc_re.o buffer_2.o buffer_put.o buffer_write.o \
byte_copy.o byte_diff.o case_diffs.o env.o error.o error_str.o \
pathexec_env.o pathexec_run.o scan_uint.o scan_ulong.o sig.o sig_block.o \
sig_catch.o sig_scan.o sig_wait.o sig_addset.o sig_delset.o sig_fillset.o \
sig_emptyset.o str_chr.o str_diff.o str_len.o str_start.o stralloc_cat.o \
stralloc_catb.o stralloc_cats.o stralloc_eady.o stralloc_opys.o \
stralloc_opyb.o stralloc_pend.o strerr_die.o strerr_sys.o sgetopt.o \
subgetopt.o wait_pid.o
	./makelib unix.a alloc.o alloc_re.o buffer_2.o buffer_put.o \
	buffer_write.o byte_copy.o byte_diff.o case_diffs.o env.o error.o \
	error_str.o pathexec_env.o pathexec_run.o scan_uint.o scan_ulong.o sig.o \
	sig_block.o sig_catch.o sig_scan.o sig_wait.o sig_addset.o sig_delset.o \
	sig_fillset.o sig_emptyset.o str_chr.o str_diff.o str_len.o str_start.o \
	stralloc_cat.o stralloc_catb.o stralloc_cats.o stralloc_eady.o \
	stralloc_opys.o stralloc_opyb.o stralloc_pend.o strerr_die.o \
	strerr_sys.o sgetopt.o subgetopt.o wait_pid.o

wait_pid.o: compile wait_pid.c error.h haswaitp.h
	./compile wait_pid.c
