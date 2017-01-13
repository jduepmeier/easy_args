.PHONY: test all

CFLAGS?=-Wall -g
CFLAGS+=-I.
LDLIBS+=-L. -leasy_args
TESTARGS?=-d -t b -f b

all: libeasy_args.a
test: easy_args_test
	./easy_args_test ${TESTARGS}

libeasy_args.a: easy_args.o
	${AR} ${ARFLAGS} $@ $>

easy_args_test: easy_args_test.c libeasy_args.a

clean:
	rm -f easy_args_test *.o *.a
