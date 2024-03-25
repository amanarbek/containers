#ifndef CONTAINERS_MYSTD_MAP_H_
#define CONTAINERS_MYSTD_MAP_H_

#include "tree.h"

namespace mystd {

template <typename Key, typename T>
class map {
  struct retractor;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using size_type = std::size_t;
  using base = tree<key_type, value_type, retractor>;
  using iterator = typename base::iterator;
  using const_iterator = typename base::const_iterator;

  map(){};
  map(std::initializer_list<value_type> const& items) {
    for (auto cit = items.begin(); cit != items.end(); ++cit) insert(*cit);
  }

  map(const map& m) {
    for (auto cit = m.begin(); cit != m.end(); ++cit) insert(*cit);
  }

  map(map&& m) { data_ = std::move(m.data_); }

  ~map() {}

  // Map Iterators
  iterator begin() noexcept { return data_.begin(); }
  const_iterator begin() const noexcept { return data_.begin(); }

  iterator end() noexcept { return data_.end(); }
  const_iterator end() const noexcept { return data_.end(); }
  // Map Iterators

  std::pair<iterator, bool> insert(const value_type& value) {
    return data_.insert(value);
  }

  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& data) {
    return data_.insert({key, data});
  }

  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& data) {
    iterator pos = find(key);
    if (pos == end()) --pos;
    if (pos->first != key) return insert({key, data});
    pos->second = data;
    return {pos, false};
  }

  bool empty() const { return begin() == end(); }

  size_type size() { return data_.size(); }

  size_type max_size() { return data_.max_size(); }

  iterator find(const key_type& key) {
    iterator it = data_.find_node(key);
    if (it->first != key) return data_.end();
    return it;
  }

  bool contains(const Key& key) { return find(key) != end(); }

  void erase(iterator pos) { data_.erase(pos); }

  void clear() { data_.clear(); }

  void swap(map& other) { data_.swap(other.data_); }

  void merge(map& other) { data_.merge(other.data_); }

  mapped_type& at(const key_type& key) { return find(key)->second; }

  mapped_type& operator[](const Key& key) {
    iterator it = find(key);
    if (it != end()) return it->second;
    return data_.insert({key, mapped_type()}).first->second;
  }

 private:
  struct retractor {
    const Key& operator()(const value_type& value) const { return value.first; }
  };

  base data_;
};

}  // namespace mystd

#endif  // CONTAINERS_MYSTD_MAP_H_
