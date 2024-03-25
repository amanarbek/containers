#ifndef SRC_TREE_H_
#define SRC_TREE_H_

template <typename Key, typename Value, class retractor>
class tree {
  class node;

 public:
  using key_type = Key;
  using value_type = Value;
  using reference = value_type&;
  using const_reference = const value_type&;
  using size_type = std::size_t;

  class iterator {
   public:
    friend class tree;
    iterator(node* ptr = nullptr) : ptr_(ptr) {}

    reference operator*() const noexcept { return *ptr_->data; }

    value_type* operator->() { return ptr_->data; }

    iterator operator++() noexcept {
      if (ptr_->right) {
        ptr_ = ptr_->right;
        while (ptr_->left) ptr_ = ptr_->left;
      } else if (ptr_->parent && ptr_ == ptr_->parent->left) {
        ptr_ = ptr_->parent;
      } else {
        while (ptr_->parent && ptr_ == ptr_->parent->right) {
          ptr_ = ptr_->parent;
        }
        ptr_ = ptr_->parent;
      }
      return *this;
    }

    iterator operator++(int) noexcept {
      iterator it(ptr_);
      ++(*this);
      return it;
    }

    iterator& operator--() noexcept {
      if (ptr_->left) {
        ptr_ = ptr_->left;
        while (ptr_->right) ptr_ = ptr_->right;
      } else if (ptr_->parent && ptr_->parent->left) {
        while (ptr_->parent->parent && ptr_ == ptr_->parent->left)
          ptr_ = ptr_->parent;
        ptr_ = ptr_->parent;
      } else {
        ptr_ = ptr_->parent;
      }
      return *this;
    }

    iterator operator--(int) noexcept {
      iterator it(ptr_);
      --(*this);
      return it;
    }

    bool operator==(const iterator& it) const noexcept {
      return ptr_ == it.ptr_;
    }

    bool operator!=(const iterator& it) const noexcept {
      return ptr_ != it.ptr_;
    }

   private:
    node* ptr_;
  };

  class const_iterator {
    friend class tree;

   public:
    const_iterator(node* ptr = nullptr) : it_(iterator(ptr)) {}

    const_reference operator*() const noexcept { return *it_.ptr_->data; }

    value_type* operator->() const noexcept { return it_.ptr_->data; }

    const_iterator operator++() noexcept {
      ++it_;
      return *this;
    }

    const_iterator operator++(int) noexcept { return it_++; }

    const_iterator& operator--() noexcept {
      --it_;
      return *this;
    }

    const_iterator operator--(int) noexcept { return it_--; }

    bool operator==(const const_iterator& cit) const noexcept {
      return it_.ptr_ == cit.it_.ptr_;
    }

    bool operator!=(const const_iterator& cit) const noexcept {
      return it_.ptr_ != cit.it_.ptr_;
    }

   private:
    iterator it_;
  };

  tree() : root_(new node), size_() {
    begin_ = iterator(root_);
    end_ = iterator(root_);
  }

  ~tree() {
    clear();
    delete root_;
  }

  tree& operator=(tree&& m) {
    swap(m);
    return *this;
  }

  // Tree Iterators
  iterator begin() noexcept { return begin_; }
  const_iterator begin() const noexcept { return const_iterator(begin_.ptr_); }

  iterator end() noexcept { return end_; }
  const_iterator end() const noexcept { return const_iterator(end_.ptr_); }
  // Tree Iterators

  size_type size() const { return size_; }

  size_type max_size() { return SIZE_MAX / sizeof(node) / 2; }

  void swap(tree& other) {
    std::swap(root_, other.root_);
    std::swap(begin_, other.begin_);
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }

  std::pair<iterator, bool> insert(const value_type& data,
                                   bool multiset = false) {
    node* current = find_node(re_(data));
    if (current && !multiset && re_(data) == re_(*current->data))
      return {current, false};
    return {iterator(insert_node(current, new node(data))), true};
  }

  node* insert_node(node* current, node* new_node) {
    bool in = false;
    if (!current) {
      std::swap(root_, new_node);
      root_->right = new_node;
      new_node->parent = root_;
      --begin_;
      ++size_;
      return new_node;
    }
    while (!in) {
      if (re_(*new_node->data) < re_(*current->data)) {
        current->left = new_node;
        new_node->parent = current;
        in = true;
      } else if (current->right) {
        if (current->right == end_.ptr_) {
          current->right = new_node;
          new_node->parent = current;
          new_node->right = end_.ptr_;
          end_.ptr_->parent = new_node;
          in = true;
        } else {
          current = find_node(re_(*new_node->data), current->right);
          continue;
        }
      } else {
        current->right = new_node;
        new_node->parent = current;
        in = true;
      }
    }
    if (re_(*new_node->data) < re_(*begin_)) begin_.ptr_ = new_node;
    ++size_;
    return new_node;
  }

  node* extract_node(node* replace) {
    node* extract = nullptr;
    // if (begin_.ptr_ == end_.ptr_) return root_;  // ??
    if (replace->right &&
        replace->right != end_.ptr_) {  // looking for min node
      extract = replace->right;
      while (extract->left) extract = extract->left;
      std::swap(replace->data, extract->data);
      if (replace->right == extract) {
        if (extract->right) {
          replace->right = extract->right;
          extract->right->parent = replace;
        } else {
          replace->right = nullptr;
          // if (extract == end_.ptr_) end_.ptr_ = extract->parent;  // ??
        }
      } else {
        if (extract->right) {
          extract->parent->left = extract->right;
          extract->right->parent = extract->parent;
        } else {
          extract->parent->left = nullptr;
        }
      }
    } else if (!replace->left && !replace->right) {
      extract = replace;
      if (re_(*extract->data) <= re_(*begin_))
        ++begin_;  // update begin iterator
      (re_(*extract->data) < re_(*extract->parent->data))
          ? extract->parent->left = nullptr
          : extract->parent->right = nullptr;
    } else if (replace->left) {  // looking for max node
      extract = replace->left;
      while (extract->right) extract = extract->right;
      // if (!extract->data && root_->data) extract = extract->parent;  // ??
      std::swap(replace->data, extract->data);
      if (replace->left == extract) {
        if (extract->left) {
          replace->left = extract->left;
          extract->left->parent = replace;
        } else {
          replace->left = nullptr;
        }
      } else {
        if (extract->left) {
          extract->parent->right = extract->left;
          extract->left->parent = extract->parent;
        } else {
          extract->parent->right = nullptr;
        }
      }
    } else {
      std::swap(replace->data, replace->right->data);
      extract = replace->right;
      replace->right = nullptr;
      end_.ptr_ = replace;
    }
    --size_;
    if (!empty() && extract == begin_.ptr_) begin_.ptr_ = replace;
    extract->parent = nullptr;
    extract->left = nullptr;
    extract->right = nullptr;
    return extract;
  }

  node* find_node(const key_type& key, node* current = nullptr) {
    if (!current) current = root_;
    node* parent = nullptr;
    if (begin_ == end_) return nullptr;
    while (current && current != end_.ptr_) {
      parent = current;
      if (key == re_(*current->data))
        break;
      else
        current = (key < re_(*current->data)) ? current->left : current->right;
    }
    if (!current)
      current = parent;
    else if (current == end_.ptr_)
      current = parent;
    return current;
  }

  void remove_node(node* del) { delete del; }

  bool empty() { return begin_ == end_; }

  void clear() {
    while (begin_ != end_) erase(begin_);
  }

  void erase(iterator pos) { remove_node(extract_node(pos.ptr_)); }

  void merge(tree& other, bool multiset = false) {
    node* in = nullptr;
    node* out = nullptr;
    for (auto it = other.begin(); it != other.end();) {
      in = find_node(re_(*it));
      if (!multiset && in && re_(*in->data) == re_(*it)) {
        ++it;
        continue;
      }
      out = other.extract_node(it.ptr_);
      auto tmp = other.begin();
      while (!multiset && tmp != other.end_ && re_(*tmp) <= re_(*out->data))
        ++tmp;
      if (tmp == other.end_) it.ptr_ = other.end_.ptr_;
      insert_node(in, out);
      it.ptr_ = tmp.ptr_;
    }
  }

 private:
  struct node {
    value_type* data;
    node* parent;
    node* left;
    node* right;

    node() : data(nullptr), parent(nullptr), left(nullptr), right(nullptr) {}
    node(value_type data)
        : data(new value_type(data)),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    ~node() {
      if (data) delete data;
    }
  };

  retractor re_;
  iterator begin_;
  iterator end_;
  node* root_;
  size_type size_;
};

#endif  // SRC_TREE_H_