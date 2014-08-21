# Prime Multiplication Table

[![Build Status](https://travis-ci.org/mrdomino/primes.svg?branch=master)](https://travis-ci.org/mrdomino/primes)

The `primes` program writes a multiplication table of the first 10 prime
numbers to STDOUT. Optionally, more than 10 primes can be multiplied by passing
a numeric argument on the command line.

## Building

Just plain old `make`.

### Dependencies

A C++ compiler supporting C++11 is required: `clang++` >= 3.4 or `g++` >= 4.8
will do. [Boost](https://www.boost.org/) is also required. Additionally,
[gtest](https://code.google.com/p/googletest/) is required to build and run the
unit tests.
