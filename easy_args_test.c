#include "easy_args.h"
#include <stdio.h>
#include <stdlib.h>


int test(int argc, char** argv) {
	printf("%s was found and has this argument: %s\n", argv[0], argv[1]);

	return 0;
}

int debug(int argc, char** argv) {
	printf("Current args list:\n");

	int i;

	for (i = 0; i < argc; i++) {
		printf("\t%s\n", argv[i]);
	}

	return 0;
}

void addArgs() {
	// add two arguments
	eargs_addArgument("-d", "--debug", debug, 0);
	eargs_addArgument("-t", "--test", test, 1);

}

int main(int argc, char** argv) {
	addArgs();

	// init output array with size of argc
	char* output[argc * sizeof(char*)];
	int outputc = eargs_parse(argc, argv, output);

	printf("Remaining arguments:\n");

	int i;
	for (i = 0; i < outputc; i++) {
		printf("Cmd[%d]: %s\n", i, output[i]);
	}

	return 0;
};
