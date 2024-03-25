#include <gtest/gtest.h>

#include <set>

#include "../mystd_multiset.h"

class MultisetTest : public ::testing::Test {
 protected:
  mystd::multiset<int> multiset{8,   20,  -14, -18, 1,   -18, -8,
                                -20, -14, -12, -9,  15,  -19, -17,
                                -3,  7,   4,   -12, -17, -14, -20};
  std::multiset<int> std_multiset{8,   20,  -14, -18, 1,   -18, -8,
                                  -20, -14, -12, -9,  15,  -19, -17,
                                  -3,  7,   4,   -12, -17, -14, -20};
  void eq_set(mystd::multiset<int> multiset, std::multiset<int> std_multiset);
};

void MultisetTest::eq_set(mystd::multiset<int> multiset,
                          std::multiset<int> std_multiset) {
  EXPECT_EQ(multiset.size(), std_multiset.size());
  auto i1 = multiset.begin();
  auto i2 = std_multiset.begin();
  for (; i2 != std_multiset.end(); ++i1, ++i2) EXPECT_EQ(*i1, *i2);
}

TEST(Multiset, default_constructor_empty) {
  mystd::multiset<int> multiset;
  EXPECT_TRUE(multiset.empty());
}

TEST_F(MultisetTest, init_constructor_insert) {
  eq_set(multiset, std_multiset);
}

TEST_F(MultisetTest, copy_constructor) {
  mystd::multiset<int> copy(multiset);
  eq_set(copy, std_multiset);
}

TEST_F(MultisetTest, move_constructor_assignment) {
  mystd::multiset<int> move1(std::move(multiset));
  eq_set(move1, std_multiset);
  mystd::multiset<int> move2 = std::move(move1);
  eq_set(move2, std_multiset);
}

TEST_F(MultisetTest, clear) {
  multiset.clear();
  EXPECT_TRUE(multiset.empty());
}

TEST_F(MultisetTest, erase) {
  multiset.erase(multiset.begin());
  std_multiset.erase(std_multiset.begin());
  multiset.erase(++multiset.begin());
  std_multiset.erase(++(std_multiset.begin()));
  multiset.erase(--multiset.end());
  std_multiset.erase(--(std_multiset.end()));
  eq_set(multiset, std_multiset);
}

TEST_F(MultisetTest, swap) {
  mystd::multiset<int> empty;
  std::multiset<int> std_empty;
  multiset.swap(empty);
  std_multiset.swap(std_empty);
  eq_set(empty, std_empty);
  EXPECT_TRUE(multiset.empty());
}

TEST_F(MultisetTest, merge) {
  std::initializer_list<int> init = {14, 8, 13, 15, 6, 7, 13, 9, 16, 8};
  mystd::multiset<int> multiset2(init);
  std::multiset<int> std_multiset2(init);
  multiset.merge(multiset2);
  std_multiset.merge(std_multiset2);
  eq_set(multiset, std_multiset);
  EXPECT_EQ(multiset2.empty(), std_multiset2.empty());
  multiset2.merge(multiset);
  std_multiset2.merge(std_multiset);
  eq_set(multiset2, std_multiset2);
  EXPECT_EQ(multiset.empty(), std_multiset.empty());
}

TEST_F(MultisetTest, count) {
  EXPECT_EQ(multiset.count(-14), std_multiset.count(-14));
}

TEST_F(MultisetTest, find) {
  EXPECT_EQ(*multiset.find(20), *std_multiset.find(20));
  EXPECT_EQ(*multiset.find(-20), *std_multiset.find(-20));
  EXPECT_EQ(*multiset.find(-19), *std_multiset.find(-19));
}

TEST_F(MultisetTest, contains) {
  EXPECT_TRUE(multiset.contains(8));
  EXPECT_TRUE(multiset.contains(-18));
  EXPECT_TRUE(multiset.contains(15));
  EXPECT_FALSE(multiset.contains(10));
}

TEST_F(MultisetTest, equal_range_bound) {
  auto pair = multiset.equal_range(-14);
  size_t count = 0;
  for (; pair.first != pair.second; ++pair.first) ++count;
  EXPECT_EQ(count, 3);
}
