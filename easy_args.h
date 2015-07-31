#pragma once


typedef struct {
	char* command;
	char** arguments;
} Arguments;

int addArgument(char* argShort, char* argLong, void* func);
char** parse(int argc, char** argv);
