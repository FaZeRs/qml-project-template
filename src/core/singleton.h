#ifndef ROOM_SKETCHER_SINGLETON_H
#define ROOM_SKETCHER_SINGLETON_H

#include <type_traits>

namespace room_sketcher {

template <typename T, typename D = T>
class Singleton {
  friend D;
  static_assert(std::is_base_of_v<T, D>, "T should be a base type for D");

 public:
  Singleton() = default;
  ~Singleton() = default;
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;
  static T& instance();
};

template <typename T, typename D>
T& Singleton<T, D>::instance() {
  static D inst;
  return inst;
}

} // namespace room_sketcher

#endif  // ROOM_SKETCHER_SINGLETON_H
