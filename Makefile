CXXFLAGS=-std=c++11 -pedantic -Wall $(DEFINES)
TESTFLAGS=-L. -lgtest -lgtest_main -pthread
GTEST_ROOT=/usr/src/gtest
BIN=nth-prime primes
TEST=primes-test prime-table-test print-table-test

GTEST_ALL=$(GTEST_ROOT)/src/gtest-all.cc
GTEST_MAIN=$(GTEST_ROOT)/src/gtest_main.cc


all: options build test

options:
	@echo build options:
	@echo "CXXFLAGS  = $(CXXFLAGS)"
	@echo "TESTFLAGS = $(TESTFLAGS)"
	@echo "CXX       = $(CXX)"

build: $(BIN)

test: $(TEST)
	@echo Running unit tests
	@for x in $(TEST); do ./$$x; done
	@echo Running integration test
	@./integration-test

nth-prime: nth-prime.cc primes.h
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $< -o $@

primes: main.cc prime-table.h print-table.h primes.h
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $< -o $@

primes-test: primes-test.cc primes.h libgtest.a libgtest_main.a
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

prime-table-test: prime-table-test.cc prime-table.h
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

print-table-test: print-table-test.cc print-table.h libgtest.a libgtest_main.a
	@echo CXX $<
	@$(CXX) $(CXXFLAGS) $(TESTFLAGS) $< -o $@

clean:
	@echo cleaning
	@rm -f $(BIN) $(TEST)


libgtest.a: $(GTEST_ALL)
	@echo CXX $(GTEST_ALL)
	@$(CXX) $(CXXFLAGS) -I$(GTEST_ROOT) $(GTEST_ALL) -c -o $@

libgtest_main.a: $(GTEST_MAIN)
	@echo CXX $(GTEST_MAIN)
	@$(CXX) $(CXXFLAGS) -I$(GTEST_ROOT) $(GTEST_MAIN) -c -o $@

distclean: clean
	@echo dist cleaning
	@rm -f libgtest.a libgtest_main.a

.PHONY: all build clean distclean options test
