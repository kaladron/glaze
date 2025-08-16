module; // global module fragment

// Standard headers that appear through nested includes; include them here so
// their declarations are attached to the global module fragment instead of
// the named module below.
#include <charconv>
#include <functional>
#include <tuple>
#include <utility>
#include <array>
#include <optional>
#include <ranges>
#include <memory>
#include <type_traits>
#include <string>
#include <string_view>
#include <vector>
#include <system_error>
#include <chrono>
#include <atomic>
#include <ctime>
#include <limits>
#include <iterator>
#include <algorithm>
#include <expected>
#include <numeric>
#include <cassert>
#include <bit>
#include <concepts>
#include <compare>
#include <cstdint>
#include <cstddef>
#include <new>
// Pre-include system/intrinsics used indirectly so they attach to the global module
// fragment rather than the named module.
#include <filesystem>
#include <cfloat>
#include <cinttypes>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <immintrin.h>

export module glaze.csv;

// Enable export blocks in headers before any includes are parsed under this unit
#define GLAZE_MODULE_BUILD 1

#include "glaze/csv.hpp"
