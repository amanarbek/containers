#include <gtest/gtest.h>

#include <queue>

#include "../mystd_containers.h"

TEST(queue_test_constructor, t1) {
  std::queue<int> a;
  mystd::queue<int> A;
  ASSERT_TRUE(a.size() == A.size());
}

TEST(queue_test_constructor, t2) {
  std::queue<int> a({1, 2, 3, 4, 6, 8, 696});
  mystd::queue<int> A{1, 2, 3, 4, 6, 8, 696};
  ASSERT_TRUE(a.size() == A.size());
  for (size_t i = a.size(); i > 0; --i) {
    ASSERT_TRUE(a.front() == A.front());
    a.pop();
    A.pop();
  }
}

TEST(queue_test_constructor, t3) {
  mystd::queue<int> *a = new mystd::queue<int>({16, 312, 2, 4, 6, 2});
  mystd::queue<int> b(*a);
  ASSERT_TRUE(a->size() == b.size());
  delete a;
}

TEST(queue_test_constructor, t4) {
  mystd::queue<int> a({16, 312, 2, 4, 6, 2});
  mystd::queue<int> b(std::move(a));
  ASSERT_TRUE(b.size() == 6);
}

TEST(queue_test_operators, t1) {
  mystd::queue<int> *a = new mystd::queue<int>({16, 312, 2, 4, 6, 2});
  mystd::queue<int> b({9, 3, 2, 1});
  b = *a;
  ASSERT_TRUE(b.size() == 6);
  for (size_t i = 0; i < a->size(); ++i) {
    ASSERT_TRUE(a->front() == b.front());
    a->pop();
    b.pop();
  }
  delete a;
}

TEST(queue_test_operators, t2) {
  mystd::queue<int> a({16, 312, 2, 4, 6, 2});
  mystd::queue<int> b({9, 3, 2, 1});
  b = std::move(a);
  ASSERT_TRUE(b.size() == 6);
}

TEST(queue_test_access, t1) {
  std::queue<int> a({15, 12, 3, 4, 5, 6, 7, 8});
  mystd::queue<int> A({15, 13});
  ASSERT_TRUE(a.front() == A.front());
}

TEST(queue_test_access, t2) {
  std::queue<int> a({15, 12, 3, 4, 5, 6, 7, 8});
  mystd::queue<int> A({15, 8});
  ASSERT_TRUE(a.back() == A.back());
}

TEST(queue_test_capacity, t1) {
  std::queue<int> a({15, 12, 3, 4, 5, 6, 7, 8});
  mystd::queue<int> A({15, 13});
  ASSERT_TRUE(a.empty() == A.empty());
  std::queue<int> b;
  mystd::queue<int> B;
  ASSERT_TRUE(b.empty() == B.empty());
}

TEST(queue_test_capacity, t2) {
  std::queue<int> a({15, 12, 3, 4, 5, 6, 7, 8});
  mystd::queue<int> A({15, 12, 3, 4, 5, 6, 7, 8});
  ASSERT_TRUE(a.size() == A.size());
  std::queue<int> b;
  mystd::queue<int> B;
  ASSERT_TRUE(b.size() == B.size());
}

TEST(queue_test_modifiers, t1) {
  std::queue<int> a;
  mystd::queue<int> A;
  ASSERT_TRUE(a.size() == A.size());
  a.push(15);
  A.push(15);
  ASSERT_TRUE(a.size() == A.size());
  a.push(52);
  A.push(52);
  a.push(67899);
  A.push(67899);
  a.push(7);
  A.push(7);
  ASSERT_TRUE(a.size() == A.size());
  for (size_t i = a.size(); i > 0; --i) {
    ASSERT_TRUE(a.front() == A.front());
    a.pop();
    A.pop();
  }
}

TEST(queue_test_modifiers, t2) {
  std::queue<int> a({15, 12, 3, 4, 5, 6, 7, 8});
  mystd::queue<int> A({15, 12, 3, 4, 5, 6, 7, 8});
  ASSERT_TRUE(a.size() == A.size());
  ASSERT_TRUE(a.front() == A.front());
  a.pop();
  A.pop();
  ASSERT_TRUE(a.front() == A.front());
}

TEST(queue_test_modifiers, t3) {
  mystd::queue<int> a({15, 12, 3, 4, 5, 6, 7, 8});
  mystd::queue<int> b({666});
  mystd::queue<int> c({15, 12, 3, 4, 5, 6, 7, 8});
  a.swap(b);
  ASSERT_TRUE(b.size() == c.size());
  for (size_t i = b.size(); i > 0; --i) {
    ASSERT_TRUE(b.front() == c.front());
    b.pop();
    c.pop();
  }
}
