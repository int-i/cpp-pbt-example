cmake_minimum_required(VERSION 3.11)
project(PbtEx
        VERSION 1.0
        DESCRIPTION "C++ Property-based Test Example (w/ RapidCheck)"
        HOMEPAGE_URL https://github.com/int-i/cpp-pbt-example
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -pedantic)
endif ()

include(FetchContent)
FetchContent_Declare(
    rapidcheck
    GIT_REPOSITORY https://github.com/emil-e/rapidcheck.git
    GIT_TAG 33d15a858e3125f5af61a655f390f1cbc2f272ba)
FetchContent_MakeAvailable(rapidcheck)

add_subdirectory(src)

