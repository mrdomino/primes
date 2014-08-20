#ifndef _PRINT_TABLE_H_
#define _PRINT_TABLE_H_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace fc {

template <typename T>
size_t width_of(T const& n) {
  std::ostringstream os;
  os << n;
  return os.str().size();
}

/// Print a multiplication table over the contents of v.
///
/// Prints elements of v along the first row and column, with each cell
/// containing the product for the corresponding row and column. wid, if
/// specified, gives the width of each column.
template <typename Container>
void print_table(std::ostream& os, Container const& v, size_t wid=8) {
  // To print a multiplication table of n items requires O(n^2)
  // multiplies. We can reduce this by a constant factor of 1/2 by only
  // doing the upper triangle of multiplications and reusing it for the
  // lower triangle, but this doesn't change the asymptotic performance,
  // so we don't do it in order to save the code complexity.
  //
  using std::endl;
  using std::setw;

  if (!v.empty()) {
    os << setw(wid) << "";
  }
  for (auto x : v) {
    os << setw(wid) << x;
  }
  os << endl;
  for (auto x : v) {
    os << setw(wid) << x;
    for (auto y : v) {
      os << setw(wid) << x * y;
    }
    os << endl;
  }
}

} // namespace fc

#endif
