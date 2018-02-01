# easy_args

[![Coverity Scan Build Status](https://scan.coverity.com/projects/15020/badge.svg)](https://scan.coverity.com/projects/jduepmeier-easy_args)

This is a small lib for parsing arguments in c.
It parses arguments in three styles:
* short arguments with single hyphen (``` -h ```)
* long arguments with two hyphens (```--help, --variable test```)
* long arguments with two hyphens and equals sign (```--variable=test```)

Every argument after two hyphens will be in the output array.

## USE

You should read the comments in the header file and look into the example code.
Short explanation:

* add arguments with ``` eargs_addArgument(char* argShort, char* argLong, void* func, unsigend arguments) ```
* init a struct for holding configuration variables
* start parsing with ``` eargs_parse(int argc, char* argc[], char* output[], void* config) ```
* read remaining arguments from output (args_parse returns the number of remaining items)
* free output array
