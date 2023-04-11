#include "funcs.hpp"

namespace rs {
int add_one(int value) { return value + 1; }
bool is_prime(int x) {
  for (int i = 2; i < x; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}
} // namespace rs
