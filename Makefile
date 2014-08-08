CXXFLAGS=-std=c++1y -pedantic -Wall
TESTFLAGS=-lgtest -lgtest_main
CXX=g++
BIN=primes primes-simple primes-tmpl
TEST=primes-test print-table-test

all: build test

build: $(BIN)

test: $(TEST)
	for x in $^; do ./$$x; done
	./integration-test

primes: primes.h print-table.h
primes-simple: primes.h print-table.h
primes-tmpl: print-table.h

%: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

%-test: %-test.cc
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

clean:
	-rm $(BIN) $(TEST)
