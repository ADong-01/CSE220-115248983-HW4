# Homework 4
Welcome to your second programming assignment in CSE 220.

For this assignment, you will have to implement string functions and make a caesar cipher encryptor/decryptor.

## Running your Code

For this assignment, you will be using `make` again to compile your code.

To compile your code run:
```bash
make
```

To then run it, run:
```bash
./bin/<FILENAME>
```

In testing, run:
```bash
gcc -Iinclude -Wall -Wextra -O2 tests/base_tests.c src/caesar.c src/strPtr.c -lcriterion -o bin/tests

./bin/tests
```
As provided by TA instructed commands.

## Submitting your Code

After succesfully completing the assignment and passing all the test cases you have created, remember to comment out your test cases. 

After that, zip up your entire assignment, INCLUDING your Makefile. The zip file should be named `FallCSE220-<SBUusername>-<SBUID#>.zip` 
