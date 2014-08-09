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

## Other files

`integration-test` is a script that builds and exercises the whole program.
`big-primes` recompiles and runs `primes-tmpl` with the passed number of
primes.
