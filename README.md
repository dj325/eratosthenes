# Sieve of Eratosthenes
Simple implementation of the Sieve of Eratosthenes, written with a focus on
Clean Coding principles. Once compiled execution will return each prime less
than 100 by default, or any positive limit up to 2,147,483,647 (max int32 value),
preceded by its sequence number.

## Installation
Download both files into the same directory and during compilation link the math
library.
```
gcc eratosthenes.c -lm
```
will compile.

## Running
Run the executable, with the option for a single argument of an integer max prime.

For example:
```
./a.out 10
```
will calculate and print all the primes up to 10.


Execution time for the primes up to 1,000,000 are:
```
real 0m0.306s
user 0m0.095s
sys  0m0.138s
```
