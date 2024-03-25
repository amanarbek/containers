#ifndef CONTAINERS_MYSTD_SET_H_
#define CONTAINERS_MYSTD_SET_H_

#include "tree.h"

namespace mystd {

template <typename Key>
class set {
  struct retractor;

 public:
  using key_type = Key;
  using value_type = key_type;
  using size_type = std::size_t;
  using base = tree<key_type, const key_type, retractor>;
  using iterator = typename base::iterator;
  using const_iterator = typename base::const_iterator;

  set() {}

  set(std::initializer_list<value_type> const& items) {
    for (auto cit = items.begin(); cit != items.end(); ++cit) insert(*cit);
  }

  set(const set& s) {
    for (auto cit = s.begin(); cit != s.end(); ++cit) insert(*cit);
  }

  set(set&& s) { data_ = std::move(s.data_); }

  ~set() {}

  // Set Iterators
  iterator begin() noexcept { return data_.begin(); }
  const_iterator begin() const noexcept { return data_.begin(); }

  iterator end() noexcept { return data_.end(); }
  const_iterator end() const noexcept { return data_.end(); }
  // Set Iterators

  std::pair<iterator, bool> insert(const value_type& value) {
    return data_.insert(value);
  }

  bool empty() const { return begin() == end(); }

  size_type size() const { return data_.size(); }

  size_type max_size() { return data_.max_size(); }

  iterator find(const key_type& key) {
    iterator it = data_.find_node(key);
    if (*it != key) return data_.end();
    return it;
  }

  bool contains(const Key& key) {
    auto pos = iterator(data_.find_node(key));
    return (pos != end()) ? key == *data_.find_node(key)->data : false;
  }

  void erase(iterator pos) { data_.erase(pos); }

  void clear() { data_.clear(); }

  void swap(set& other) { data_.swap(other.data_); }

  void merge(set& other) { data_.merge(other.data_); }

 private:
  struct retractor {
    const key_type& operator()(const key_type& t) const { return t; }
  };

  base data_;
};

}  // namespace mystd

#endif  // CONTAINERS_MYSTD_SET_H_
