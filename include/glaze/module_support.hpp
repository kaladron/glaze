#pragma once

// Module support macros for dual-mode compilation
// This header enables the same code to work as both traditional headers and module content

// Detect if we're building the module interface unit and allow selective exports
#ifdef GLAZE_MODULE_BUILD
#  define GLZ_MODULE_EXPORT export
#  define GLZ_BEGIN_EXPORT export
#  define GLZ_END_EXPORT
#  define GLZ_EXPORT export
#else
#  define GLZ_MODULE_EXPORT
#  define GLZ_BEGIN_EXPORT
#  define GLZ_END_EXPORT
#  define GLZ_EXPORT
#endif

// Deprecated/compatibility helpers (no-ops)
// Most headers already use `#pragma once`, so guard helpers are unnecessary.
#define GLZ_HEADER_GUARD_BEGIN(name)
#define GLZ_HEADER_GUARD_END

// Standard include helper: intentionally a no-op because the preprocessor
// cannot emit a directive from a macro body. Prefer explicit `#include` with
// `#ifndef GLAZE_MODULE_BUILD` guards at use sites when needed.
#define GLZ_STD_INCLUDE(header)