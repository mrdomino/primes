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
void print_table(std::ostream& os, std::vector<T> const& v) {
  const size_t wid = 8;
  if (!v.empty()) {
    os << std::setw(wid) << "";
  }
  std::for_each(v.begin(), v.end(),
      [&os](T const& x) {
        os << std::setw(wid) << x;
      });
  os << std::endl;
  std::for_each(v.begin(), v.end(),
      [&v,&os](T const& x) {
        os << std::setw(wid) << x;
        std::for_each(v.begin(), v.end(),
            [&x,&os](T const& y) {
              os << std::setw(wid) << x * y;
            });
        os << std::endl;
      });
}

} // namespace fc

#endif
