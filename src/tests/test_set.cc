#include <gtest/gtest.h>

#include <set>

#include "../mystd_set.h"

class SetTest : public ::testing::Test {
 protected:
  mystd::set<int> set{8,  20,  -14, -18, 1, -18, -8,  -20, -14, -12, -9,
                      15, -19, -17, -3,  7, 4,   -12, -17, -14, -20};
  std::set<int> std_set{8,  20,  -14, -18, 1, -18, -8,  -20, -14, -12, -9,
                        15, -19, -17, -3,  7, 4,   -12, -17, -14, -20};
  void eq_set(const mystd::set<int>& set, const std::set<int>& std_set);
};

void SetTest::eq_set(const mystd::set<int>& set, const std::set<int>& std_set) {
  EXPECT_EQ(set.size(), std_set.size());
  auto i1 = set.begin();
  auto i2 = std_set.begin();
  for (; i2 != std_set.end(); ++i1, ++i2) EXPECT_EQ(*i1, *i2);
}

TEST(set, default_constructor_empty) {
  mystd::set<int> set;
  EXPECT_TRUE(set.empty());
}

TEST_F(SetTest, init_constructor_insert) { eq_set(set, std_set); }

TEST_F(SetTest, copy_constructor) {
  mystd::set<int> Copy(set);
  eq_set(Copy, std_set);
}

TEST_F(SetTest, move_constructor_assignment) {
  mystd::set<int> Move1(std::move(set));
  eq_set(Move1, std_set);
  mystd::set<int> Move2 = std::move(Move1);
  eq_set(Move2, std_set);
}

TEST_F(SetTest, clear) {
  set.clear();
  EXPECT_TRUE(set.empty());
}

TEST_F(SetTest, erase) {
  set.erase(set.begin());
  std_set.erase(std_set.begin());
  set.erase(++set.begin());
  std_set.erase(++std_set.begin());
  set.erase(--set.end());
  std_set.erase(--std_set.end());
  eq_set(set, std_set);
}

TEST_F(SetTest, swap) {
  mystd::set<int> empty;
  std::set<int> std_empty;
  set.swap(empty);
  std_set.swap(std_empty);
  eq_set(empty, std_empty);
  EXPECT_TRUE(set.empty());
}

TEST_F(SetTest, merge) {
  std::initializer_list<int> init = {14, 8, 13, 15, 6, 7, 13, 9, 16, 8};
  mystd::set<int> set2(init);
  std::set<int> std_set2(init);
  set.merge(set2);
  std_set.merge(std_set2);
  eq_set(set, std_set);
  eq_set(set2, std_set2);
  EXPECT_EQ(set2.empty(), std_set2.empty());
}

TEST_F(SetTest, find) {
  mystd::set<int>::iterator i = set.find(10);
  EXPECT_EQ(i, set.end());
  i = set.find(20);
  EXPECT_EQ(i, --(set.end()));
  i = set.find(-20);
  EXPECT_EQ(i, set.begin());
  i = set.find(-19);
  EXPECT_EQ(i, (++(set.begin())));
}

TEST_F(SetTest, contains) {
  EXPECT_TRUE(set.contains(8));
  EXPECT_TRUE(set.contains(-18));
  EXPECT_TRUE(set.contains(15));
  EXPECT_FALSE(set.contains(10));
}