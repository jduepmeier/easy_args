#pragma once


typedef struct {
	char* command;
	char** arguments;
} Arguments;

int args_addArgument(char* argShort, char* argLong, void* func);
char** args_parse(int argc, char** argv);
