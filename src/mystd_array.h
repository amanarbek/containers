#ifndef CONTAINERS_MYSTD_ARRAY_H_
#define CONTAINERS_MYSTD_ARRAY_H_

#include <initializer_list>
#include <stdexcept>

namespace mystd {
template <typename T, size_t N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array(){};
  array(std::initializer_list<value_type> const &items) {
    if (items.size() > N) {
      throw std::length_error("Too many initializers");
    }
    auto it = items.begin();
    for (size_t i = 0; it != items.end(); ++i, ++it) {
      data_[i] = *it;
    }
  };

  array(const array &a) { std::copy(a.data_, a.data_ + N, data_); }

  array(array &&a) { std::copy(a.data_, a.data_ + N, data_); }

  array operator=(const array &a) noexcept {
    std::copy(a.data_, a.data_ + N, data_);
    return *this;
  }

  array operator=(array &&a) noexcept {
    std::copy(a.data_, a.data_ + N, data_);
    return *this;
  }

  reference operator[](size_type pos) { return data_[pos]; }

  reference at(size_type pos) {
    if (pos >= size()) {
      throw std::out_of_range("Index greater than array size");
    }
    return data_[pos];
  }

  const_reference front() const { return *data_; }

  const_reference back() const { return *(data_ + N - 1); }

  iterator data() noexcept { return data_; }

  iterator begin() noexcept { return data_; }

  iterator end() noexcept { return data_ + N; }

  bool empty() const noexcept { return N == 0; }

  size_type size() const noexcept { return N; }

  size_type max_size() const noexcept { return N; }

  void swap(array &other) { std::swap(*this, other); }

  void fill(const_reference value) {
    for (size_t i = 0; i < N; ++i) {
      data_[i] = value;
    }
  }

 private:
  value_type data_[N];
};
}  // namespace mystd

#endif  // CONTAINERS_MYSTD_ARRAY_H_
