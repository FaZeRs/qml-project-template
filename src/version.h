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

#ifndef BUILD_STRING
#define BUILD_STRING ""
#endif  // BUILD_STRING

#ifndef PRERELEASE_STRING
#define PRERELEASE_STRING ""
#endif  // PRERELEASE_STRING

#define STRINGIFY(X) #X
#define TO_STRING(X) STRINGIFY(X)

namespace version {
namespace version_impl {
constexpr const char* makeVersionString() {
  if (BUILD_STRING[0] == '\0') {
    if (PRERELEASE_STRING[0] == '\0') {
      return TO_STRING(VERSION_MAJOR) "." TO_STRING(
          VERSION_MINOR) "." TO_STRING(VERSION_PATCH);
    } else {
      return TO_STRING(VERSION_MAJOR) "." TO_STRING(
          VERSION_MINOR) "." TO_STRING(VERSION_PATCH) "-" PRERELEASE_STRING;
    }
  } else {
    if (PRERELEASE_STRING[0] == '\0') {
      return TO_STRING(VERSION_MAJOR) "." TO_STRING(
          VERSION_MINOR) "." TO_STRING(VERSION_PATCH) "+" BUILD_STRING;
    } else {
      return TO_STRING(VERSION_MAJOR) "." TO_STRING(
          VERSION_MINOR) "." TO_STRING(VERSION_PATCH) "-" PRERELEASE_STRING
                                                      "+" BUILD_STRING;
    }
  }
}
}  // namespace version_impl

static_assert(VERSION_MAJOR >= 0 &&
                  std::is_integral<decltype(VERSION_MAJOR)>::value,
              "VERSION_MAJOR is not positive integer!");
static_assert(VERSION_MINOR >= 0 &&
                  std::is_integral<decltype(VERSION_MINOR)>::value,
              "VERSION_MINOR is not positive integer!");
static_assert(VERSION_PATCH >= 0 &&
                  std::is_integral<decltype(VERSION_PATCH)>::value,
              "VERSION_PATCH is not positive integer!");

static constexpr uint32_t major{VERSION_MAJOR};
static constexpr uint32_t minor{VERSION_MINOR};
static constexpr uint32_t patch{VERSION_PATCH};
static constexpr const char* build{BUILD_STRING};
static constexpr const char* prerelease{PRERELEASE_STRING};
static constexpr const char* version_string{version_impl::makeVersionString()};

/// @brief Get version string
/// @returns Version string
static constexpr auto getVersionString() { return version_string; }

/// @brief Get major version
/// @returns Major version
static constexpr auto getMajor() { return major; }

/// @brief Get minor version
/// @returns Minor version
static constexpr auto getMinor() { return minor; }

/// @brief Get patch version
/// @returns Patch version
static constexpr auto getPatch() { return patch; }

/// @brief Get build number
/// @returns Build number
static constexpr auto getBuild() { return build; }

/// @brief Get pre-release string
/// @returns Pre-release string
static constexpr auto getPrerelease() { return prerelease; }

}  // namespace version

#endif  // VERSION_H