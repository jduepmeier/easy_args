#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ArgumentItem {

	char* argShort;
	char* argLong;
	void* func;
	unsigned arguments;
	struct ArgumentItem* next;

};

struct ArgumentItem* base;

int args_addArgument(char* argShort, char* argLong, void* func, unsigned arguments) {

	struct ArgumentItem* item = (struct ArgumentItem*) malloc(sizeof(struct ArgumentItem));
	item->argShort = argShort;
	item->argLong = argLong;
	item->func = func;
	item->arguments = arguments;
	item->next = NULL;

	if (!base) {
		base = item;	
	} else {
		struct ArgumentItem* next = base->next;
		while (next) {
			next = next->next;
		}
		next->next = item;
	}

	return 1;
}

int clearItem(struct ArgumentItem* item) {
	
	if (item->next) {
		clearItem(item->next);
	} else {
		free(item);
	}

	return 1;
}

int clear() {

	if (base) {
		if (base->next) {
			clearItem(base->next);
		}
		free(base);
	}

	return 1;
}

int parseItem(int argc, char** cmds) {

	struct ArgumentItem* item = base;
	int arg = 0;

	if (argc < 1) {
		return arg;
	}

	while (item) {
		
		if (!strcmp(cmds[0], item->argShort) || !strcmp(cmds[0], item->argLong)) {
			arg = 1;
			void * (*p)(char** cmds) = item->func;
			p(cmds);
		}
		
		item = item->next;
	}

	return arg;
}

char** args_parse(int argc, char** argv) {


	struct ArgumentItem* item = base;

	char** output = malloc(argc * sizeof(char*));
	memset(output, 0, argc * sizeof(char*));
	int curr = 0;
	int i;

	for (i = 1; i < argc; i++) {
		int v = parseItem(argc - i, &argv[i]);

		if (v == 0) {
			output[curr] = argv[i];
			curr++;

		}
	}

	clear();

	return output;
}
