#ifndef ALL_H
#define ALL_H

#pragma push_macro("all")
#pragma push_macro("common")
#undef all
#undef common

// ============================================================================
// ALL_H: Extended Standard C++ Library Headers
// (Excludes headers already included in common.h to prevent redundancy)
// ============================================================================

// --- 1. Additional Containers & Data Structures ---
#include <array>           // For std::array (fixed-size compile-time arrays)
#include <bitset>          // For std::bitset (fixed-size bit arrays & bit manipulation)
#include <forward_list>    // For std::forward_list (singly-linked list)
#include <list>            // For std::list (doubly-linked list)
#include <unordered_map>   // For std::unordered_map, std::unordered_multimap (hash map)
#include <unordered_set>   // For std::unordered_set, std::unordered_multiset (hash set)

// --- 2. String Streams, Views & Text Processing ---
#include <sstream>         // For std::stringstream, std::istringstream, std::ostringstream
#include <string_view>     // For std::string_view (C++17 zero-copy string views)
#include <regex>           // For std::regex, std::smatch, std::regex_search, std::regex_replace
#include <charconv>        // For std::from_chars, std::to_chars (C++17 fast number parsing)

// --- 3. File System & File I/O ---
#include <fstream>         // For std::ifstream, std::ofstream, std::fstream (file I/O)
#include <filesystem>      // For std::filesystem::path (C++17 filesystem operations)

// --- 4. Utilities, Tuples, Smart Pointers & Type Traits ---
#include <functional>      // For std::function, std::bind, std::greater, std::hash
#include <memory>          // For std::unique_ptr, std::shared_ptr, std::make_unique
#include <optional>        // For std::optional, std::nullopt (C++17 optional values)
#include <variant>         // For std::variant, std::get, std::holds_alternative (C++17 type-safe union)
#include <any>             // For std::any, std::any_cast (C++17 type-safe container for any type)
#include <tuple>           // For std::tuple, std::make_tuple, std::tie, std::get
#include <type_traits>     // For std::is_same_v, std::enable_if_t, compile-time introspection
#include <typeinfo>        // For typeid, std::type_info

// --- 5. Random Numbers, Timing, Math & Numeric Limits ---
#include <random>          // For std::mt19937, std::uniform_int_distribution, random engines
#include <chrono>          // For std::chrono high-precision clocks, duration, time points
#include <complex>         // For std::complex numbers
#include <valarray>        // For std::valarray (vectorized math operations)
#include <ratio>           // For std::ratio (compile-time rational arithmetic)
#include <limits>          // For std::numeric_limits<T>::max(), min(), epsilon()

// --- 6. Concurrency, Multithreading & Atomics ---
#include <thread>          // For std::thread, std::this_thread::sleep_for
#include <mutex>           // For std::mutex, std::lock_guard, std::unique_lock
#include <condition_variable> // For std::condition_variable
#include <future>          // For std::async, std::future, std::promise
#include <atomic>          // For std::atomic<T> (lock-free thread-safe variables)

// --- 7. Error Handling & Diagnostics ---
#include <exception>       // For std::exception
#include <stdexcept>       // For std::runtime_error, std::invalid_argument, std::out_of_range
#include <system_error>    // For std::error_code, std::system_error
#include <cassert>         // For assert() macro

// --- 8. C-Compatibility Libraries ---
#include <cstdio>          // For printf, scanf, sprintf, FILE*
#include <cstdlib>         // For malloc, free, exit, rand, srand, atoi
#include <cstring>         // For strlen, strcmp, strcpy, memset, memcpy
#include <cctype>          // For isdigit, isalpha, tolower, toupper
#include <ctime>           // For time(), clock(), difftime()
#include <cfloat>          // For FLT_MAX, DBL_MAX float limits
#include <cstddef>         // For size_t, ptrdiff_t, nullptr_t

#pragma pop_macro("common")
#pragma pop_macro("all")

#endif // ALL_H


