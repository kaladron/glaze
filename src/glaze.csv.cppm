module; // global module fragment

// Keep a minimal set of system headers in the global fragment to avoid
// redeclarations and purview warnings in the named module below.
#include <charconv>
#include <string_view>
#include <span>
#include <optional>
#include <filesystem>
#include <cassert>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <immintrin.h>

export module glaze.csv;

// Enable export blocks in headers before any includes are parsed under this unit
#define GLAZE_MODULE_BUILD 1

#include "glaze/csv.hpp"

// Exports are provided via export macros in the included header during module build.
