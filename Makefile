override CXXFLAGS+=-std=c++1y -pedantic -Wall
TESTFLAGS=-lgtest -lgtest_main
CXX=g++
BIN=primes primes-simple primes-tmpl
TEST=primes-test print-table-test

all: options build test fc

options:
	@echo build options:
	@echo "CXXFLAGS  = $(CXXFLAGS)"
	@echo "TESTFLAGS = $(TESTFLAGS)"
	@echo "CXX       = $(CXX)"

fc: primes
	@echo primes
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
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $< -o $@

%-test: %-test.cc %.h
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

clean:
	@echo cleaning
	@rm -f $(BIN) $(TEST)

.PHONY: all build clean fc options test
