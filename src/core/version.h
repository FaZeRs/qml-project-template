#ifndef VERSION_H
#define VERSION_H

#include <string>
#include <string_view>

#ifndef VERSION_MAJOR
#define VERSION_MAJOR 0
#endif  // VERSION_MAJOR

#ifndef VERSION_MINOR
#define VERSION_MINOR 0
#endif  // VERSION_MINOR

#ifndef VERSION_PATCH
#define VERSION_PATCH 0
#endif  // VERSION_PATCH

#define STRINGIFY(X) #X
#define TO_STRING(X) STRINGIFY(X)

namespace room_sketcher::version {
namespace version_impl {
constexpr const char* makeVersionString() {
  return TO_STRING(VERSION_MAJOR) "." TO_STRING(
      VERSION_MINOR) "." TO_STRING(VERSION_PATCH);
}
}  // namespace version_impl

static_assert(VERSION_MAJOR >= 0 &&
                  std::is_integral_v<decltype(VERSION_MAJOR)>,
              "VERSION_MAJOR is not positive integer!");
static_assert(VERSION_MINOR >= 0 &&
                  std::is_integral_v<decltype(VERSION_MINOR)>,
              "VERSION_MINOR is not positive integer!");
static_assert(VERSION_PATCH >= 0 &&
                  std::is_integral_v<decltype(VERSION_PATCH)>,
              "VERSION_PATCH is not positive integer!");

static constexpr const char* version_string{version_impl::makeVersionString()};

/// @brief Get version string
/// @returns Version string
static constexpr auto getVersionString() { return version_string; }

}  // namespace room_sketcher::version

#endif  // VERSION_H
