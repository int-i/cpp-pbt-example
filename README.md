# C++ PBT Example

> C++ Property-based Testing Example (w/ RapidCheck)

![C++](https://img.shields.io/badge/c++-11-00599C?logo=c%2B%2B&logoColor=white&style=for-the-badge)
[![CMake](https://img.shields.io/badge/cmake->=3.11-064F8C?logo=cmake&logoColor=white&style=for-the-badge)](https://cmake.org/)

## Build

### Requirement

- C++11
- CMake(>=3.11)
- [RapidCheck](https://github.com/emil-e/rapidcheck.git)(CMake [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html))

### Guide

1. Clone the repository:

    ```bash
    $ git clone https://github.com/int-i/cpp-pbt-example.git
    ```

2. Build the source:

    ```bash
    $ cd cpp-pbt-example
    $ cmake -S . -B build
    $ cmake --build build
    ```

Related Post: [인하대학교 인트아이 - ???: 내 이름은 PBT. 어설픈 건 용납 못해 (Feat. RapidCheck)](https://int-i.github.io/cpp/2021-07-25/cpp-pbt-rapidcheck/)
