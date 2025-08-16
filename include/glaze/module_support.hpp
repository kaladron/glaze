#pragma once

// Module support macros for dual-mode compilation
// This header enables the same code to work as both traditional headers and module content

// Detect if we're building the module interface unit and allow selective exports
#ifdef GLAZE_MODULE_BUILD
#  define GLZ_MODULE_EXPORT export
#  define GLZ_BEGIN_EXPORT export
#  define GLZ_END_EXPORT
#  define GLZ_EXPORT export
#define GLZ_STATIC
#else
#define GLZ_STATIC static
#  define GLZ_MODULE_EXPORT
#  define GLZ_BEGIN_EXPORT
#  define GLZ_END_EXPORT
#  define GLZ_EXPORT
#endif
