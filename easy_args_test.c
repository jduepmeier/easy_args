#include <easy_args.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct config {
	int debug;
	bool flag;
};

int test(int argc, char** argv, struct config* config) {

	printf("%s was found and has this argument: %s\n", argv[0], argv[1]);

	return 1;
}

int debug(int argc, char** argv, struct config* config) {
	printf("Current args list:\n");

	config->debug = 1;

	int i;

	for (i = 0; i < argc; i++) {
		printf("\t%s\n", argv[i]);
	}

	return 0;
}

void addArgs(struct config* config) {
	// add two arguments
	eargs_addArgument("-d", "--debug", debug, 0);
	eargs_addArgument("-t", "--test", test, 1);
	eargs_addArgumentFlag("-f", "--flag", &config->flag);
}

int main(int argc, char** argv) {

	struct config config = {
		.debug = 0,
		.flag = false
	};

	addArgs(&config);

	// init output array with size of argc
	char* output[argc * sizeof(char*)];
	int outputc = eargs_parse(argc, argv, output, &config);

	printf("Debug? %d\n", config.debug);

	printf("Remaining arguments:\n");

	int i;
	for (i = 0; i < outputc; i++) {
		printf("Cmd[%d]: %s\n", i, output[i]);
	}

	if (config.flag) {
		printf("flag is true\n");
	}

	return 0;
};
