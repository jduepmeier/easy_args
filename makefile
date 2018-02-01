.PHONY: test all

CFLAGS?=-Wall -g
CFLAGS+=-I.
LDLIBS+=-L. -leasy_args
TESTARGS?=-d -t b -f b

all: libeasy_args.a easy_args_test
test: easy_args_test
	./easy_args_test ${TESTARGS}

libeasy_args.a: easy_args.o
	${AR} ${ARFLAGS} $@ $>

%.o: %.c easy_args.h
	$(CC) $(CFLAGS) $(LDLIBS) -c -o $@ $<

easy_args_test: easy_args_test.o easy_args.o

clean:
	rm -f easy_args_test *.o *.a
