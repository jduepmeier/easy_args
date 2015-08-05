# easy_args

This is a small lib for parsing arguments in c.

## USE

You should read the comments in the header file and look into the example code.
Short explanation:

* add arguments with ``` eargs_addArgs(char* argShort, char* argLong, void* func, unsigend arguments) ```
* start parsing with ``` eargs_parse(int argc, char* argc[], char* output[]) ```
* read remaining arguments from output (args_parse returns the number of remaining items)
