module; // global module fragment

// Standard headers that appear through nested includes; include them here so
// their declarations are attached to the global module fragment instead of
// the named module below.
#include <charconv>
#include <functional>
#include <tuple>
#include <utility>
#include <array>
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
// Headers pulled in transitively by common.hpp and container headers
#include <optional>
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

// Explicitly export a minimal surface area for initial module adoption.
// Provide thin wrappers under glz::csv that forward to the header API without
// leaking internal types in signatures.
export namespace glz::csv {
	template <class T, class Buffer, uint32_t layout = 0u>
	inline bool read(T& value, Buffer&& buffer)
	{
		auto ec = ::glz::read_csv<layout>(value, std::forward<Buffer>(buffer));
		return !bool(ec);
	}

	template <class T, class Buffer, uint32_t layout = 0u>
	inline T read(Buffer&& buffer)
	{
		return ::glz::read_csv<layout, T>(std::forward<Buffer>(buffer));
	}

	template <class T, class Buffer, uint32_t layout = 0u>
	inline bool read_file(T& value, std::string_view file_name, Buffer&& buffer)
	{
		auto ec = ::glz::read_file_csv<layout>(value, file_name, std::forward<Buffer>(buffer));
		return !bool(ec);
	}
}
