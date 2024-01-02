#pragma once

#include <functional>

#if defined(defer)
#error "'defer' macro already defined"
#endif

namespace com::github::kbinani {
class defer_t final {
public:
  template <class T>
  defer_t(T fn) : fn(fn) {}
  ~defer_t() {
    if (!fn) {
      return;
    }
    try {
      fn();
    } catch (...) {
    }
  }
  defer_t(defer_t const &) = delete;
  defer_t &operator=(defer_t const &) = delete;
  defer_t(defer_t &&) = delete;
  defer_t &operator=(defer_t &&) = delete;
private:
  std::function<void()> const fn;
};
}

#define com_github_kbinani_defer_helper2(line) com_github_kbinani_defer_##line
#define com_github_kbinani_defer_helper(line) com_github_kbinani_defer_helper2(line)

#define defer ::com::github::kbinani::defer_t com_github_kbinani_defer_helper(__LINE__) = [&](void) -> void
