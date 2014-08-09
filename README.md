# Prime Multiplication Table

The `primes` program writes a multiplication table of the first 10 prime
numbers to STDOUT. Optionally, more than 10 primes can be multiplied by passing
a numeric argument on the command line.

Also included is `primes-simple`, which only ever writes the first 10 primes.

And also included is `primes-tmpl`, which can be configured to write a
multiplication table from a list of primes generated at compile-time. It still
does n^2 multiplications at runtime to display the table (making this somewhat
pointless except as a proof of concept), but does no prime computation at
runtime.

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
