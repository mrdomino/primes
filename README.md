# Prime Multiplication Table

The `primes` program writes a multiplication table of the first 10 prime
numbers to STDOUT. Optionally, more than 10 primes can be multiplied by passing
a numeric argument on the command line.

Also included is `primes-simple`, which only ever writes the first 10 primes.

And also included (just for fun, as a proof of concept) is `primes-tmpl`, which
precomputes a dynamically-sized table at compile-time.

Additionally, unit tests are provided for the prime-generation sieve and the
multiplication table routine, as well as an integration test to verify that the
whole program behaves as expected.

## Building

To build the whole thing, run tests, and see the output:

    make

To just build the code:

    make build

To just run the tests:

    make test

To just see the output:

    make fc

To clean up:

    make clean

### Dependencies

A C++ compiler supporting C++11 is required -- clang++ >= 3.4 or g++ >= 4.8
will do. Additionally, [gtest](https://code.google.com/p/googletest/) is
required to build and run the unit tests.

## Other files

`integration-test` is a script that builds and exercises the whole program.
`big-primes` recompiles and runs `primes-tmpl` with the passed number of
primes.

## Complexity

Since we are using a relatively fast prime generation algorithm, the O(n^2)
multiplies required to produce a multiplication table over n items dominate
asymptotic performance. The prime generator, on the other hand, dominates space
usage -- it needs O(n log(n log n)) bits of memory to find n primes. In a very
space-constrained environment, it may be desirable to use a slower prime
generator that uses less memory.

The static multiplication table generator, on the other hand, is constrained
only by the system output routines -- it precomputes all the multiples at
compile time. Of course, the output is still O(n^2), and for even modest n, the
compilation step takes lots of resources due to usage of less efficient
algorithms in the metaprogramming implementation.
