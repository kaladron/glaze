module; // global module fragment

// Standard headers that are suppressed in headers via guards
#include <charconv>

export module glaze.csv;

// Enable export blocks in headers before any includes are parsed under this unit
#define GLAZE_MODULE_BUILD 1

#include "glaze/module_support.hpp"

// Export the CSV surface via the umbrella header
#include "glaze/csv.hpp"
