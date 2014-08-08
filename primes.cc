#include <cstdlib>
#include <iostream>
#include <sstream>

#include "primes.h"
#include "print-table.h"

using fc::primes;
using fc::print_table;
using std::cerr;
using std::cout;
using std::endl;
using std::ios_base;
using std::istringstream;

template <typename T>
inline T lexical_cast(char const* c) {
  istringstream is(c);
  T ret;
  is >> ret;
  if (!is.eof()) {
    throw ios_base::failure("bad n");
  }
  return ret;
}

void usage(char const* argv0) {
  cout << "usage: " << argv0 << " [n]" << endl
       << "  where n is the number of primes to print (10 if omitted)."
       << endl;
  exit(1);
}

int main(int argc, char* argv[]) {
  if (argc > 2) {
    usage(*argv);
  }
  try {
    auto n = (argc == 1) ? 10
      : lexical_cast<size_t>(argv[1]);
    auto ps = primes(n);
    if (ps) {
      print_table(cout, *ps);
    }
    else {
      throw std::runtime_error("Null pointer");
    }
  } catch(ios_base::failure&) {
    usage(*argv);
  } catch(std::exception& e) {
    cerr << "Internal error: " << e.what() << endl;
    exit(2);
  }
  return 0;
}
