# FixedPoint

Fixed point arithmetic C++ library. Intended for use in microcontroller firmware.

## Usage
This is a header-only library, so just copy the relevant files into your project's include
directory.

To keep things simple, this library only allows scales that are powers of 10. For example, to
define a 32-bit signed fixed-point number with precision of 2 decimal places:

```cpp
#include "FixedPoint.h"

FixedPoint<int32_t, 2> number(1.23);

// alternatively:
Fixed32_2 number(1.23);

// convert from int with given precision:
Fixed32_2 number(12300, 4);
```

In the example above, all the definitions are equal.