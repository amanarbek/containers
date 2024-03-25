#ifndef CONTAINERS_MYSTD_QUEUE_H_
#define CONTAINERS_MYSTD_QUEUE_H_

#include "mystd_list.h"

namespace mystd {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() : container_(){};

  queue(std::initializer_list<value_type> const items) : container_(items) {}

  queue(const queue &s) : container_(s.container_) {}

  queue(queue &&s) { *this = std::move(s); }

  ~queue() { container_.clear(); }

  queue &operator=(const queue &s) {
    container_.clear();
    container_ = s.container_;
    return *this;
  }

  queue &operator=(queue &&s) {
    container_ = std::move(s.container_);
    return *this;
  }

  const_reference front() const { return container_.front(); }

  const_reference back() const { return container_.back(); }

  void push(const_reference value) { container_.push_back(value); }

  bool empty() { return container_.empty(); }

  size_type size() { return container_.size(); }

  void pop() { container_.pop_front(); }

  void swap(queue &other) { container_.swap(other.container_); }

 private:
  list<T> container_;
};
}  // namespace mystd
#endif  // CONTAINERS_MYSTD_QUEUE_H_
