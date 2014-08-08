CXXFLAGS=-std=c++1y -pedantic -Wall
TESTFLAGS=-lgtest -lgtest_main
CXX=g++

all: primes test

test: primes-test integration-test
	./$<
	./integration-test

primes: primes.cc primes.h
	$(CXX) $(CXXFLAGS) $< -o $@

primes-test: primes-test.cc primes.h
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

clean:
	-rm primes primes-test
