#pragma once

// Module support macros for dual-mode compilation
// This header enables the same code to work as both traditional headers and module content

// Detect if we're building modules
// Keep export macros as no-ops for now to avoid exporting internal linkage
// symbols accidentally. We can selectively add exports later.
#define GLZ_MODULE_EXPORT
#define GLZ_BEGIN_EXPORT
#define GLZ_END_EXPORT

// Deprecated/compatibility helpers (no-ops)
// Most headers already use `#pragma once`, so guard helpers are unnecessary.
#define GLZ_HEADER_GUARD_BEGIN(name)
#define GLZ_HEADER_GUARD_END

// Standard include helper: intentionally a no-op because the preprocessor
// cannot emit a directive from a macro body. Prefer explicit `#include` with
// `#ifndef GLAZE_MODULE_BUILD` guards at use sites when needed.
#define GLZ_STD_INCLUDE(header)