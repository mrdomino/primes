#include <vector>

#include "primes.h"

using namespace fc;
using namespace std;

static const size_t first_10_primes[] = {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29
};

int main(int argc, char* argv[]) {
  auto x = vector<size_t>(begin(first_10_primes), end(first_10_primes));
  print_table(cout, x);
  return 0;
}
