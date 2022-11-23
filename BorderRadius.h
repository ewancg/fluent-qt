#ifndef BORDERRADIUS_H
#define BORDERRADIUS_H

#include <utility>

template <typename T>
concept Numeric =
    std::is_integral<T>::value || std::is_floating_point<T>::value;
// Don't take primitives by reference

struct BorderRadius {
  template <Numeric T>
  explicit BorderRadius(const T radius) noexcept {
    topLeft = radius;
    topRight = radius;
    bottomLeft = radius;
    bottomRight = radius;
  }
  template <Numeric T>
  explicit BorderRadius(const T top, const T bottom) noexcept {
    topLeft = top;
    topRight = top;
    bottomLeft = bottom;
    bottomRight = bottom;
  }
  template <Numeric T>
  explicit BorderRadius(const T topLeft, const T topRight, const T bottomLeft,
                        const T bottomRight) noexcept {
    this->topLeft = topLeft;
    this->topRight = topRight;
    this->bottomLeft = bottomLeft;
    this->bottomRight = bottomRight;
  }
  constexpr bool operator==(const BorderRadius &x) const noexcept {
    return topLeft == x.topLeft && topRight == x.topRight &&
           bottomLeft == x.bottomLeft && bottomRight == x.bottomRight;
  }
  const BorderRadius operator+(const BorderRadius &x) const noexcept {
    return BorderRadius(topLeft + x.topLeft, topRight + x.topRight,
                        bottomLeft + x.bottomLeft, bottomRight + x.bottomRight);
  }
  const BorderRadius operator-(const BorderRadius &x) const noexcept {
    return BorderRadius(topLeft - x.topLeft, topRight - x.topRight,
                        bottomLeft - x.bottomLeft, bottomRight - x.bottomRight);
  }
  const BorderRadius operator*(const BorderRadius &x) const noexcept {
    return BorderRadius(topLeft * x.topLeft, topRight * x.topRight,
                        bottomLeft * x.bottomLeft, bottomRight * x.bottomRight);
  }
  const BorderRadius operator/(const BorderRadius &x) const noexcept {
    if (x.contains(0)) return invalid();
    return BorderRadius(topLeft / x.topLeft, topRight / x.topRight,
                        bottomLeft / x.bottomLeft, bottomRight / x.bottomRight);
  }
  template <Numeric T>
  constexpr bool operator==(T x) const noexcept {
    return topLeft == x && topRight == x && bottomLeft == x && bottomRight == x;
  }
  template <Numeric T>
  constexpr BorderRadius operator+(const T x) const noexcept {
    return BorderRadius(topLeft + x, topRight + x, bottomLeft + x,
                        bottomRight + x);
  }
  template <Numeric T>
  constexpr BorderRadius operator-(const T x) const noexcept {
    return BorderRadius(topLeft - x, topRight - x, bottomLeft - x,
                        bottomRight - x);
  }
  template <Numeric T>
  constexpr BorderRadius operator*(const T x) const noexcept {
    return BorderRadius(topLeft * x, topRight * x, bottomLeft * x,
                        bottomRight * x);
  }
  template <Numeric T>
  constexpr BorderRadius operator/(const T x) const noexcept {
    if (x == 0) return invalid();
    return BorderRadius(topLeft / x, topRight / x, bottomLeft / x,
                        bottomRight / x);
  }

  static BorderRadius invalid() noexcept {
    static auto inv = BorderRadius(-1);
    return inv;
  }
  void invalidate() { topLeft = -1; }
  constexpr bool isValid() const noexcept {
    return topLeft >= 0 && topRight >= 0 && bottomLeft >= 0 && bottomRight >= 0;
  }
  template <Numeric T>
  constexpr bool contains(T i) const noexcept {
    return topLeft == i || topRight == i || bottomLeft == i || bottomRight == i;
  }
  template <Numeric T>
  const T minimumWidth() noexcept {
    return topLeft + topRight >= bottomLeft + bottomRight
               ? topLeft + topRight
               : bottomLeft + bottomRight;
  }
  template <Numeric T>
  const T minimumHeight() noexcept {
    return topLeft + bottomLeft >= topRight + bottomRight
               ? topLeft + bottomLeft
               : topRight + bottomRight;
  }
  const QSize minimumSize() noexcept {
    return QSize(minimumWidth<int>(), minimumHeight<int>());
  }

  int topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
};

#endif  // BORDERRADIUS_H
