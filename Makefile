CXXFLAGS=-std=c++11 -pedantic -Wall $(DEFINES)
TESTFLAGS=-L. -lgtest -lgtest_main -pthread
GTEST_ROOT=/usr/src/gtest
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
	@for x in $(TEST); do ./$$x; done
	@echo Running integration test
	@./integration-test

primes: primes.cc
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $< -o $@

primes-simple: primes-simple.cc
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $< -o $@

primes-tmpl: primes-tmpl.cc
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $< -o $@

primes: primes.h print-table.h

primes-test: primes-test.cc primes.h libgtest.a libgtest_main.a
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

print-table-test: print-table-test.cc print-table.h libgtest.a libgtest_main.a
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

libgtest.a: $(GTEST_ROOT)/src/gtest-all.cc
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) -I$(GTEST_ROOT) $< -c -o $@

libgtest_main.a: $(GTEST_ROOT)/src/gtest_main.cc
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) -I$(GTEST_ROOT) $< -c -o $@

clean:
	@echo cleaning
	@rm -f $(BIN) $(TEST)

distclean: clean
	@echo dist cleaning
	@rm -f libgtest.a libgtest_main.a

.PHONY: all build clean fc options test
