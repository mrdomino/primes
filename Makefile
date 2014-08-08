CXXFLAGS=-std=c++1y -pedantic -Wall
TESTFLAGS=-lgtest -lgtest_main
CXX=g++
BIN=primes primes-simple primes-tmpl
TEST=primes-test

all: $(BIN) test

test: $(TEST)
	./$<
	./integration-test

primes: primes.cc primes.h print-table.h
	$(CXX) $(CXXFLAGS) $< -o $@

primes-simple: primes-simple.cc primes.h print-table.h
	$(CXX) $(CXXFLAGS) $< -o $@

primes-test: primes-test.cc primes.h print-table.h
	$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

primes-tmpl: primes-tmpl.cc print-table.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm $(BIN) $(TEST)
