#include <defer.hpp>
#include <iostream>

int main() {
  defer {
    std::cout << 3;
  };
  defer {
    std::cout << 2;
  };
  std::cout << 0;
  {
    defer {
      std::cout << 1;
    };
  }
  return 0;
}
