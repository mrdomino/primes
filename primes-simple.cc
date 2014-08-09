#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

static const size_t first_10_primes[] = {
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29
};

int main(int argc, char* argv[]) {
  cout << setw(4) << "";
  for_each(begin(first_10_primes), end(first_10_primes),
      [](size_t p) {
        cout << setw(4) << p;
      });
  cout << endl;
  for_each(begin(first_10_primes), end(first_10_primes),
      [](size_t p) {
        cout << setw(4) << p;
        for_each(begin(first_10_primes), end(first_10_primes),
            [p](size_t q) {
              cout << setw(4) << p * q;
            });
        cout << endl;
      });
  return 0;
}
