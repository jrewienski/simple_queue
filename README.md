# Overview
This is a very simple circular queue.

# Compliation
Use make to run the Makefile
```
make
```

# Implementation
TODO

## Code style and formatting
TODO

Formatting with default Visual Studio clang format style (indent width: 4, spaces).


# Testing
Main file consists of number of assertions, that do basic tests for addition, removal and check.


## Code coverage
Code is covered with tests in main.c file.
To run tests and gcov analysis, run:
```
make
./test.out
make coverage
```

At the moment code coverage is at 100% (by gcov).
```
File 'main.c'
Lines executed:100.00% of 41
Creating 'main.c.gcov'

File 'simple_queue.c'
Lines executed:100.00% of 40
Creating 'simple_queue.c.gcov'
```

## Static code analysis
Cppcheck shows no warnings.

```
% cppcheck --enable=all main.c simple_queue.c simple_queue.h
Checking main.c ...
1/3 files checked 47% done
Checking simple_queue.c ...
2/3 files checked 75% done
Checking simple_queue.h ...
3/3 files checked 100% done
```