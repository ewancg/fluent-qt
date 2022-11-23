#ifndef BORDERRADIUS_H
#define BORDERRADIUS_H

#include <utility>

template <typename T>
concept Numeric =
    std::is_integral<T>::value || std::is_floating_point<T>::value;
// Don't take primitives by reference

struct BorderRadius {
  template <Numeric T>
  explicit BorderRadius(const T radius) {
    topLeft = radius;
    topRight = radius;
    bottomLeft = radius;
    bottomRight = radius;
  }
  template <Numeric T>
  explicit BorderRadius(const T top, const T bottom) {
    topLeft = top;
    topRight = top;
    bottomLeft = bottom;
    bottomRight = bottom;
  }
  template <Numeric T>
  explicit BorderRadius(const T topLeft, const T topRight, const T bottomLeft,
                        const T bottomRight) {
    this->topLeft = topLeft;
    this->topRight = topRight;
    this->bottomLeft = bottomLeft;
    this->bottomRight = bottomRight;
  }
  bool operator==(const BorderRadius &x) {
    return topLeft == x.topLeft && topRight == x.topRight &&
           bottomLeft == x.bottomLeft && bottomRight == x.bottomRight;
  }
  BorderRadius operator+(const BorderRadius &x) {
    return BorderRadius(topLeft + x.topLeft, topRight + x.topRight,
                        bottomLeft + x.bottomLeft, bottomRight + x.bottomRight);
  }
  BorderRadius operator-(const BorderRadius &x) {
    return BorderRadius(topLeft - x.topLeft, topRight - x.topRight,
                        bottomLeft - x.bottomLeft, bottomRight - x.bottomRight);
  }
  BorderRadius operator*(const BorderRadius &x) {
    return BorderRadius(topLeft * x.topLeft, topRight * x.topRight,
                        bottomLeft * x.bottomLeft, bottomRight * x.bottomRight);
  }
  BorderRadius operator/(const BorderRadius &x) {
    return BorderRadius(topLeft / x.topLeft, topRight / x.topRight,
                        bottomLeft / x.bottomLeft, bottomRight / x.bottomRight);
  }
  template <Numeric T>
  bool operator==(T x) {
    return topLeft == x && topRight == x && bottomLeft == x && bottomRight == x;
  }
  template <Numeric T>
  BorderRadius operator+(const T x) {
    return BorderRadius(topLeft + x, topRight + x, bottomLeft + x,
                        bottomRight + x);
  }
  template <Numeric T>
  BorderRadius operator-(const T x) {
    return BorderRadius(topLeft - x, topRight - x, bottomLeft - x,
                        bottomRight - x);
  }
  template <Numeric T>
  BorderRadius operator*(const T x) {
    return BorderRadius(topLeft * x, topRight * x, bottomLeft * x,
                        bottomRight * x);
  }
  template <Numeric T>
  BorderRadius operator/(const T x) {
    if (x == 0) return invalid();
    return BorderRadius(topLeft / x, topRight / x, bottomLeft / x,
                        bottomRight / x);
  }

  static const BorderRadius invalid() {
    static auto inv = BorderRadius(-1);
    return inv;
  }
  void invalidate() { topLeft = -1; }
  bool isValid() {
    return topLeft >= 0 && topRight >= 0 && bottomLeft >= 0 && bottomRight >= 0;
  }

  int topLeft = 0, topRight = 0, bottomLeft = 0, bottomRight = 0;
};
#endif  // BORDERRADIUS_H
