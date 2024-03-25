#include <gtest/gtest.h>

#include <stack>

#include "../mystd_containers.h"

TEST(stack_test_constructors, t1) {
  std::stack<int> ss;
  mystd::stack<int> ms;

  ASSERT_TRUE(ss.size() == ms.size());
}

TEST(stack_test_constructors, t2) {
  std::stack<int> ss({1, 2, 3});
  mystd::stack<int> ms({1, 2, 3});

  while (!ss.empty()) {
    ASSERT_TRUE(ss.top() == ms.top());
    ss.pop();
    ms.pop();
  }
}

TEST(stack_test_constructors, t3) {
  mystd::stack<int> ms1({1, 2, 3});
  mystd::stack<int> ms2(ms1);

  while (!ms1.empty()) {
    ASSERT_TRUE(ms2.top() == ms1.top());
    ms1.pop();
    ms2.pop();
  }
}

TEST(stack_test_constructors, t4) {
  mystd::stack<int> ms1({1, 2, 3});
  mystd::stack<int> ms2({1, 2, 3});
  mystd::stack<int> ms3(std::move(ms1));

  ASSERT_TRUE(ms1.empty());
  ASSERT_TRUE(ms3.size() == ms2.size());

  while (!ms3.empty()) {
    ASSERT_TRUE(ms2.top() == ms3.top());
    ms2.pop();
    ms3.pop();
  }
}

TEST(stack_test_copy_operator, t1) {
  mystd::stack<int> ms1({1, 2, 3});
  mystd::stack<int> ms2;

  ms2 = ms1;

  while (!ms1.empty()) {
    ASSERT_TRUE(ms2.top() == ms1.top());
    ms1.pop();
    ms2.pop();
  }
}

TEST(stack_test_move_operator, t1) {
  mystd::stack<int> ms1({1, 2, 3});
  mystd::stack<int> ms2({1, 2, 3});
  mystd::stack<int> ms3;

  ms3 = std::move(ms1);

  ASSERT_TRUE(ms1.empty());
  ASSERT_TRUE(ms3.size() == ms2.size());

  while (!ms3.empty()) {
    ASSERT_TRUE(ms2.top() == ms3.top());
    ms2.pop();
    ms3.pop();
  }
}

TEST(stack_test_top, t1) {
  mystd::stack<int> ms({1, 2, 3});
  std::stack<int> ss({1, 2, 3});

  ASSERT_TRUE(ms.top() == ss.top());
}

TEST(stack_test_top, t2) {
  mystd::stack<int> ms({1, 1, 2, 3});
  std::stack<int> ss({1, 1, 2, 3});

  ASSERT_TRUE(ms.top() == ss.top());
}

TEST(stack_test_empty, t1) {
  mystd::stack<int> ms;
  std::stack<int> ss;

  ASSERT_TRUE(ms.empty() == ss.empty());
}

TEST(stack_test_empty, t2) {
  mystd::stack<int> ms({1});
  std::stack<int> ss({1});

  ASSERT_TRUE(ms.empty() == ss.empty());
}

TEST(stack_test_size, t1) {
  mystd::stack<int> ms;
  std::stack<int> ss;

  ASSERT_TRUE(ms.size() == ss.size());
}

TEST(stack_test_size, t2) {
  mystd::stack<int> ms({1, 2});
  std::stack<int> ss({1, 2});

  ASSERT_TRUE(ms.size() == ss.size());
}

TEST(stack_test_size, t3) {
  mystd::stack<int> ms({1, 2, 3, 4});
  std::stack<int> ss({1, 2, 3, 4});

  ASSERT_TRUE(ms.size() == ss.size());
}

TEST(stack_test_push, t1) {
  mystd::stack<int> ms;
  std::stack<int> ss;
  ms.push(1);
  ss.push(1);
  ms.push(2);
  ss.push(2);
  ms.push(2);
  ss.push(2);

  ASSERT_TRUE(ms.size() == ss.size());

  while (!ss.empty()) {
    ASSERT_TRUE(ss.top() == ms.top());
    ss.pop();
    ms.pop();
  }
}

TEST(stack_test_pop, t1) {
  mystd::stack<int> ms;
  std::stack<int> ss;

  ms.push(1);
  ss.push(1);
  ms.pop();
  ss.pop();
  ms.push(2);
  ss.push(2);
  ms.push(2);
  ss.push(2);
  ms.pop();
  ss.pop();

  ASSERT_TRUE(ms.size() == ss.size());

  while (!ss.empty()) {
    ASSERT_TRUE(ss.top() == ms.top());
    ss.pop();
    ms.pop();
  }
}

TEST(stack_test_swap, t1) {
  mystd::stack<int> ms1({1, 2, 3, 4});
  mystd::stack<int> ms2({1, 2});
  std::stack<int> ss1({1, 2, 3, 4});
  std::stack<int> ss2({1, 2});

  ms1.swap(ms2);
  ss1.swap(ss2);

  ASSERT_TRUE(ms1.size() == ss1.size());
  ASSERT_TRUE(ms2.size() == ss2.size());

  while (!ss1.empty()) {
    ASSERT_TRUE(ss1.top() == ms1.top());
    ss1.pop();
    ms1.pop();
  }
  while (!ss2.empty()) {
    ASSERT_TRUE(ss2.top() == ms2.top());
    ss2.pop();
    ms2.pop();
  }
}
