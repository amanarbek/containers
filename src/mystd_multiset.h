#ifndef CONTAINERS_MYSTD_MULTISET_H_
#define CONTAINERS_MYSTD_MULTISET_H_

#include "tree.h"

namespace mystd {

template <typename Key>
class multiset {
  struct retractor;

 public:
  using key_type = Key;
  using value_type = key_type;
  using size_type = std::size_t;
  using base = tree<key_type, const key_type, retractor>;
  using iterator = typename base::iterator;
  using const_iterator = typename base::const_iterator;

  multiset() {}

  multiset(std::initializer_list<value_type> const& items) {
    for (auto cit = items.begin(); cit != items.end(); ++cit) insert(*cit);
  }

  multiset(const multiset& ms) {
    for (auto cit = ms.begin(); cit != ms.end(); ++cit) insert(*cit);
  }

  multiset(multiset&& ms) { data_ = std::move(ms.data_); }

  ~multiset() {}

  iterator begin() noexcept { return data_.begin(); }
  const_iterator begin() const noexcept { return data_.begin(); }

  iterator end() noexcept { return data_.end(); }
  const_iterator end() const noexcept { return data_.end(); }

  iterator insert(const value_type& value) {
    return data_.insert(value, true).first;
  }

  bool empty() const { return begin() == end(); }

  size_type size() { return data_.size(); }

  size_type max_size() { return data_.max_size(); }

  iterator find(const key_type& key) {
    iterator it = data_.find_node(key);
    if (*it != key) return data_.end();
    return it;
  }

  bool contains(const key_type& key) {
    auto pos = iterator(data_.find_node(key));
    return (pos != end()) ? key == *data_.find_node(key)->data : false;
  }

  void erase(iterator pos) { data_.erase(pos); }

  void clear() { data_.clear(); }

  void swap(multiset& other) { data_.swap(other.data_); }

  void merge(multiset& other) { data_.merge(other.data_, true); }

  iterator lower_bound(const Key& key) { return find(key); }

  iterator upper_bound(const Key& key) {
    iterator it = find(key);
    for (; *it == key; ++it) continue;
    return it;
  }

  std::pair<iterator, iterator> equal_range(const Key& key) {
    return {lower_bound(key), upper_bound(key)};
  }

  size_type count(const key_type& key) {
    size_type count = 0;
    for (iterator it = find(key); *it == key; ++it, ++count) continue;
    return count;
  }

 private:
  struct retractor {
    const key_type& operator()(const key_type& t) const { return t; }
  };

  base data_;
};

}  // namespace mystd

#endif  // CONTAINERS_MYSTD_MULTISET_H_
