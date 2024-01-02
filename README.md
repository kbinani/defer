# defer

`defer` for c++, like Swift

# example

```c++
#include <defer.hpp>
#include <iostream>

int main() {
    defer {
        std::cout << "on exit" << std::endl;
    };
    std::cout << "on start" << std::endl;
    return 0;
}
```

# license

- MIT
