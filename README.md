# defer

`defer` for C++, like Swift

[![CI](https://github.com/kbinani/defer/actions/workflows/main.yml/badge.svg)](https://github.com/kbinani/defer/actions/workflows/main.yml)

# example

```c++
#include <defer.hpp>
#include <iostream>

int main() {
    defer {
        std::cout << 3 << std::endl;
    };
    defer {
        std::cout << 2 << std::endl;
    };
    std::cout << 0 << std::endl;
    {
        defer {
            std::cout << 1 << std::endl;
        };
    }
    return 0;
}
```

# license

- MIT
