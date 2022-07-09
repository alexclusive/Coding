<!--
Markdown notes: https://www.w3schools.io/file/markdown-introduction/
C notes: https://www.educba.com/software-development/software-development-tutorials/c-tutorial/
-->
# Notes for C++
## General
### Compile
For C++ file with filename `test.cpp`.\
&ensp;&ensp;`> g++ test.cpp`\
&ensp;&ensp;`> a`

### Before main
`#include` is the same as C, but most things don't need the `.h`.\
&ensp;&ensp;&ensp;&ensp;Instead of `#include <string.h>`, it's `#include <string>`\
`using namespace std;` means you don't need to use `std::` - sets the default namespace (for input and output).
- `std::cin` becomes `cin`
- `std::cout` becomes `cout`
- `std::endl` becomes `endl`

## Input and output
Make sure to have `#include <iostream>` before main.\
Keywords (assuming `using namespace std;`)
- `cin`
    * used for input
    * returns boolean when taking input with the `>>` operand
        - true if successfully read
        - false if unsuccessfully read
- `cout`
    * used for output
- `endl`
    * used for new line
    * short for "end line"

Operands
- `>>`
    * "extract" operator - basically "take from"
    * usually used after `cin`
    * usually used to extract input from `cin` into variables
        - e.g. with 2 `int` variables `a` and `b` already declared (not necessarily initialised)\
        The `>>` must be used between each variable\
        `cin >> a >> b;`

- `<<`
    * "insert" operator - basically "give to"
    * usually used after `cout`
    * usually used when outputting to `cout`
        - e.g. with 2 `int` variables `a` and `b` already declared (and initialised for meaningful output)\
        The `<<` must be used between each variable\
        `cout << a << b;`
        - e.g. with 2 `int` variables `a` and `b` already declared and initialised\
        `cout << a>b ? 1 : 0;` does not work, but\
        `cout << (a>b) ? 1 : 0;` does work

## Data types
Unsigned ints
- uint16_t
    * using 16 bits
- uint_least16_t
    * using at least 16 bits
- uint_Fast16_t
    * using at least 16 bits
    * using the 'fastest' datatype (e.g. could be 32 bit or something)
    * literally what on earth does that mean

## Arrays
### Initialisation
What you can do:
- `int arr[3];`
    * new int array of size 3
    * printing from this gives random values
        - e.g. `{6422280, 1976201005, 4201648}`
- `int arr[] = {0, 1, 2};`
    * new int array of size 3
    * with values {0, 1, 2}
    * printing from this gives defined values
        - e.g. `{0, 1, 2}`
- `int arr* = new int[n]();`
    * new int array of size `n`
    * making a new array is like using a constructor
    * printing from this gives all 0s
        - e.g. `{0, 0, 0}`

What you cannot do:
- `int arr[] = new int[n];`
    * array size cannot be a variable
    * must be constant
- `int[] arr = {1, 2, 3};`
    * the `[]` must be on the array name (before or after)
    * if done with pointer `*`, must be before array name