#pragma once

#include <functional>

namespace com::github::kbinani {
class defer_t {
public:
  template <class T>
  defer_t(T fn) : fn(fn) {}
  ~defer_t() {
    if (!fn) {
      return;
    }
    try {
      fn();
    } catch (...) {}
  }
private:
  std::function<void()> fn;
};
}

#define com_github_kbinani_defer_helper2(line) com_github_kbinani_defer_##line
#define com_github_kbinani_defer_helper(line) com_github_kbinani_defer_helper2(line)

#define defer ::com::github::kbinani::defer_t com_github_kbinani_defer_helper(__LINE__) = [&](void) -> void
