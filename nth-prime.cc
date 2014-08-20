#include <boost/lexical_cast.hpp>
#include <exception>
#include <iostream>

#include "primes.h"

using namespace boost;
using namespace fc;
using namespace std;

void usage(char const* argv0) {
  cerr << "usage: " << argv0 << " <n>" << endl
       << "  prints the nth prime for n > 0." << endl;
}

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      throw ios_base::failure("Expected exactly one argument");
    }
    else {
      auto n = lexical_cast<long>(argv[1]);
      if (n > 0) {
        cout << *primes(n)->rbegin() << endl;
      }
      else throw ios_base::failure("Expected n > 0");
    }
  }
  catch (ios_base::failure& e) {
    cerr << e.what() << endl;
    usage(argv[0]);
    exit(1);
  }
  catch (boost::bad_lexical_cast&) {
    usage(argv[0]);
    exit(1);
  }
  catch (std::exception& e) {
    cerr << "Internal failure: " << e.what() << endl;
    exit(2);
  }
  return 0;
}
