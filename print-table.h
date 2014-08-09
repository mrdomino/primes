#ifndef _PRINT_TABLE_H_
#define _PRINT_TABLE_H_

#include <algorithm>
#include <iomanip>
#include <iostream>

namespace fc {

/// Print a multiplication table over the contents of v.
///
/// Prints elements of v along the first row and column, with each cell
/// containing the product for the corresponding row and column.
template <typename T>
void print_table(std::ostream& os, std::vector<T> const& v, size_t wid=8) {
  // To print a multiplication table of n items requires O(n^2)
  // multiplies. We can reduce this by a constant factor of 1/2 by only
  // doing the upper triangle of multiplications and reusing it for the
  // lower triangle, but this doesn't change the asymptotic performance,
  // so we don't do it in order to save the code complexity.
  //
  if (!v.empty()) {
    os << std::setw(wid) << "";
  }
  std::for_each(v.begin(), v.end(),
      [&os,wid](T const& x) {
        os << std::setw(wid) << x;
      });
  os << std::endl;
  std::for_each(v.begin(), v.end(),
      [&v,&os,wid](T const& x) {
        os << std::setw(wid) << x;
        std::for_each(v.begin(), v.end(),
            [&x,&os,wid](T const& y) {
              os << std::setw(wid) << x * y;
            });
        os << std::endl;
      });
}

} // namespace fc

#endif
