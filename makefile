.PHONY: test

test:
	gcc -g -o test easy_args_test.c easy_args.c

clean:
	rm test
