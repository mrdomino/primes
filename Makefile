override CXXFLAGS+=-std=c++1y -pedantic -Wall
TESTFLAGS=-lgtest -lgtest_main
CXX=g++
BIN=primes primes-simple primes-tmpl
TEST=primes-test print-table-test

all: build test

fc: primes
	@./primes

build: $(BIN)

test: $(TEST)
	@echo Running unit tests
	@for x in $^; do ./$$x; done
	@echo Running integration test
	@./integration-test

primes: primes.h print-table.h
primes-simple: print-table.h
primes-tmpl: print-table.h

%: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

%-test: %-test.cc
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

clean:
	-rm $(BIN) $(TEST)

.PHONY: all build clean fc test
