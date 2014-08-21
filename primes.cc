#include <boost/lexical_cast.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "prime-table.h"

using boost::bad_lexical_cast;
using boost::lexical_cast;
using fc::primeTable;
using std::cerr;
using std::cout;
using std::endl;
using std::exception;

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
    primeTable(cout, n);
  } catch(bad_lexical_cast&) {
    usage(*argv);
  } catch(exception& e) {
    cerr << "Internal error: " << e.what() << endl;
    exit(2);
  }
  return 0;
}
