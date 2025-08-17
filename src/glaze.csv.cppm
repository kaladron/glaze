module; // global module fragment

// Pull in all transitive non-modular/system headers up front so libc++
// declarations live in the global module, avoiding cross-module
// redeclarations under Clang/LLVM 20's stricter C++ modules rules.
// Standard library
// containers/algorithms/iterators
#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
#include <charconv>
#include <chrono>
#include <cctype>
#include <cfloat>
#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <expected>
#include <filesystem>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <numeric>
#include <optional>
#include <ranges>
#include <set>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>
#include <version>

// SIMD intrinsics (used in parsing hot paths)
#include <xmmintrin.h>
#include <emmintrin.h>
#include <immintrin.h>

export module glaze.csv;

// Enable export blocks in headers before any includes are parsed under this unit
#define GLAZE_MODULE_BUILD 1

#include "glaze/csv.hpp"

// Exports are provided via export macros in the included header during module build.
