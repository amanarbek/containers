#include <gtest/gtest.h>

#include <list>

#include "../mystd_containers.h"

TEST(list_defaulter_constructor, test0) {
  mystd::list<int> my_list;
  std::list<int> stl_list;
  EXPECT_EQ(my_list.front(), stl_list.front());
  EXPECT_EQ(my_list.size(), stl_list.size());
  EXPECT_EQ(my_list.empty(), stl_list.empty());
}

TEST(list_constructor_with_size, test0) {
  mystd::list<int> my_list(3);
  std::list<int> stl_list(3);
  auto it1 = my_list.begin();
  auto it2 = stl_list.begin();
  for (; it2 != stl_list.end(); it2++, it1++) ASSERT_DOUBLE_EQ(*it1, *it2);
  std::list<double> l2(2);
  mystd::list<double> l1(2);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); ++it3, ++it4) ASSERT_DOUBLE_EQ(*it3, *it4);
}

TEST(list_constructor_initializer, test0) {
  mystd::list<int> my_list{1, 3, 5, 6};
  std::list<int> stl_list{1, 3, 5, 6};
  auto it1 = my_list.begin();
  auto it2 = stl_list.begin();
  for (; it2 != stl_list.end(); it2++, it1++) {
    EXPECT_EQ(*it1, *it2);
  }
}

TEST(list_copy_constructor, test0) {
  mystd::list<int> my_list{1, 3, 5, 6, 8};
  mystd::list<int> my_list2(my_list);

  std::list<int> stl_list{1, 3, 5, 6, 8};
  std::list<int> stl_list2(stl_list);

  auto it1 = my_list.begin();
  auto it2 = stl_list.begin();
  for (; it2 != stl_list.end(); it2++, it1++) {
    EXPECT_EQ(*it1, *it2);
  }
}

TEST(list_copy_operator, test0) {
  mystd::list<int> l1({1, 2, 3, 4});
  mystd::list<int> l2 = l1;
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
}

TEST(list_move_operator, test0) {
  mystd::list<int> l1({1, 2, 3, 4});
  mystd::list<int> l2(std::move(l1));
  std::list<int> l3({1, 2, 3, 4});
  ASSERT_DOUBLE_EQ(0, l1.size());
  auto it3 = l1.begin();
  auto it4 = l3.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
}

TEST(list_move_operator, test1) {
  mystd::list<int> l1({1, 2, 3, 4});
  mystd::list<int> l2 = std::move(l1);
  std::list<int> l3({1, 2, 3, 4});
  ASSERT_DOUBLE_EQ(0, l1.size());
  auto it3 = l1.begin();
  auto it4 = l3.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
}

TEST(list_front, test0) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  ASSERT_DOUBLE_EQ(l1.front(), l2.front());
}

TEST(list_front, test1) {
  mystd::list<int> l1({1, 2});
  mystd::list<int> l2 = l1;
  ASSERT_DOUBLE_EQ(l1.front(), l2.front());
}

TEST(list_back, test0) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  ASSERT_DOUBLE_EQ(l1.back(), l2.back());
}

TEST(list_size, test0) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_size, test1) {
  mystd::list<int> l1;
  std::list<int> l2;
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_size, test2) {
  mystd::list<int> l1(10);
  std::list<int> l2(10);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

// TEST(list_max_size, test0) {
//   mystd::list<int> l1({1, 2});
//   std::list<int> l2({1, 2});
//   std::cout << l1.max_size();
//   std::cout << l2.max_size();
//   ASSERT_DOUBLE_EQ(l1.max_size(), l2.max_size());
// }

// TEST(list_max_size, test1) {
//   mystd::list<int> l1;
//   std::list<int> l2;
//   ASSERT_DOUBLE_EQ(l1.max_size(), l2.max_size());
// }

// TEST(list_max_size, test2) {
//   mystd::list<int> l1(10);
//   std::list<int> l2(10);
//   ASSERT_DOUBLE_EQ(l1.max_size(), l2.max_size());
// }

TEST(list_clear, test0) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.clear();
  l2.clear();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_clear, test1) {
  mystd::list<int> l1;
  std::list<int> l2;
  l1.clear();
  l2.clear();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_clear, test2) {
  mystd::list<int> l1(10);
  std::list<int> l2(10);
  l1.clear();
  l2.clear();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_insert, test0) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.insert(l1.begin(), 3);
  l2.insert(l2.begin(), 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_insert, test1) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.insert(l1.end(), 3);
  l2.insert(l2.end(), 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_insert, test2) {
  mystd::list<int> l1;
  std::list<int> l2;
  l1.insert(l1.begin(), 3);
  l2.insert(l2.begin(), 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_insert, test3) {
  mystd::list<int> l1;
  std::list<int> l2;
  l1.insert(l1.end(), 3);
  l2.insert(l2.end(), 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_insert, t5) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.insert(l1.begin(), 3);
  l2.insert(l2.begin(), 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_insert, t6) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.insert(l1.end(), 3);
  l2.insert(l2.end(), 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_insert, t7) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  it1++;
  it1++;
  advance(it2, 2);
  l1.insert(it1, 3);
  l2.insert(it2, 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_insert, t8) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  auto it1 = l1.end();
  auto it2 = l2.end();
  it1--;
  it1--;
  advance(it2, -2);
  l1.insert(it1, 3);
  l2.insert(it2, 3);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_erase, t1) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.erase(l1.begin());
  l2.erase(l2.begin());
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_erase, t2) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.erase(l1.begin());
  l2.erase(l2.begin());
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_erase, t3) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  it1++;
  it1++;
  advance(it2, 2);
  l1.erase(it1);
  l2.erase(it2);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_erase, t4) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  auto it1 = l1.end();
  auto it2 = l2.end();
  it1--;
  it1--;
  advance(it2, -2);
  l1.erase(it1);
  l2.erase(it2);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_push_back, t1) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.push_back(4);
  l2.push_back(4);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_push_back, t2) {
  mystd::list<int> l1;
  std::list<int> l2;
  l1.push_back(4);
  l2.push_back(4);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_push_back, t3) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.push_back(4);
  l2.push_back(4);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_pop_back, t1) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.pop_back();
  l2.pop_back();
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_pop_back, t2) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.pop_back();
  l2.pop_back();
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_push_front, t1) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.push_front(4);
  l2.push_front(4);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_push_front, t2) {
  mystd::list<int> l1;
  std::list<int> l2;
  l1.push_front(4);
  l2.push_front(4);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_push_front, t3) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.push_front(4);
  l2.push_front(4);
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_pop_front, t1) {
  mystd::list<int> l1({1, 2});
  std::list<int> l2({1, 2});
  l1.pop_front();
  l2.pop_front();
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_pop_front, t2) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.pop_front();
  l2.pop_front();
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  for (; it3 != l1.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
}

TEST(list_test_swap, t1) {
  mystd::list<int> l1({2, 3, 5});
  mystd::list<int> u3(3);
  std::list<int> l2({2, 3, 5});
  std::list<int> u4(3);
  l1.swap(u3);
  l2.swap(u4);
  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
  auto it3 = u3.begin();
  auto it4 = u4.begin();
  for (; it3 != u3.end(); it3++, it4++) ASSERT_DOUBLE_EQ(*it3, *it4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());
}

TEST(list_test_merge, t1) {
  mystd::list<int> l1({1, 2, 3});
  mystd::list<int> u3({4, 5, 6});
  std::list<int> l2({1, 2, 3});
  std::list<int> u4({4, 5, 6});
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_merge, t2) {
  mystd::list<int> l1({1, 7, 8});
  mystd::list<int> u3({4, 5, 6});
  std::list<int> l2({1, 7, 8});
  std::list<int> u4({4, 5, 6});
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_merge, t3) {
  mystd::list<int> l1({7, 8});
  mystd::list<int> u3({4, 5, 6});
  std::list<int> l2({7, 8});
  std::list<int> u4({4, 5, 6});
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_merge, t4) {
  mystd::list<int> l1({1, 7, 8});
  mystd::list<int> u3({4, 8, 9});
  std::list<int> l2({1, 7, 8});
  std::list<int> u4({4, 8, 9});
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_merge, t5) {
  mystd::list<int> l1;
  mystd::list<int> u3({4, 8, 9});
  std::list<int> l2;
  std::list<int> u4({4, 8, 9});
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_merge, t6) {
  mystd::list<int> l1({4, 8, 9});
  mystd::list<int> u3;
  std::list<int> l2({4, 8, 9});
  std::list<int> u4;
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_merge, t7) {
  mystd::list<int> l1({5, 7, 8, 10});
  mystd::list<int> u3({4, 6, 8, 9, 11});
  std::list<int> l2({5, 7, 8, 10});
  std::list<int> u4({4, 6, 8, 9, 11});
  l1.merge(u3);
  l2.merge(u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_splice, t1) {
  mystd::list<int> l1({5, 7, 8, 10});
  mystd::list<int> u3({4, 6, 8, 9, 11});
  std::list<int> l2({5, 7, 8, 10});
  std::list<int> u4({4, 6, 8, 9, 11});
  l1.splice(l1.begin(), u3);
  l2.splice(l2.begin(), u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_splice, t2) {
  mystd::list<int> l1({5, 7, 8, 10});
  mystd::list<int> u3({4, 6, 8, 9, 11});
  std::list<int> l2({5, 7, 8, 10});
  std::list<int> u4({4, 6, 8, 9, 11});
  l1.splice(l1.end(), u3);
  l2.splice(l2.end(), u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_splice, t3) {
  mystd::list<int> l1({5, 7, 8, 10});
  mystd::list<int> u3({4, 6, 8, 9, 11});
  std::list<int> l2({5, 7, 8, 10});
  std::list<int> u4({4, 6, 8, 9, 11});
  auto it3 = l1.begin();
  auto it4 = l2.begin();
  it3++;
  it3++;
  advance(it4, 2);
  l1.splice(it3, u3);
  l2.splice(it4, u4);
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());
  ASSERT_DOUBLE_EQ(u3.size(), u4.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_reverse, t1) {
  mystd::list<int> l1({5, 7, 8, 10});
  std::list<int> l2({5, 7, 8, 10});
  l1.reverse();
  l2.reverse();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_reverse, t2) {
  mystd::list<int> l1;
  std::list<int> l2;
  l1.reverse();
  l2.reverse();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_reverse, t3) {
  mystd::list<int> l1(5);
  std::list<int> l2(5);
  l1.reverse();
  l2.reverse();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_unique, t1) {
  mystd::list<int> l1({1, 1, 1, 2, 3, 3, 2, 2, 5, 5, 69});
  std::list<int> l2({1, 1, 1, 2, 3, 3, 2, 2, 5, 5, 69});
  l1.unique();
  l2.unique();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); ++it1, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_unique, t2) {
  mystd::list<int> l1({1, 1, 1});
  std::list<int> l2({1, 1, 1});
  l1.unique();
  l2.unique();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); ++it1, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_unique, t3) {
  mystd::list<int> l1({1, 1, 1, 1});
  std::list<int> l2({1, 1, 1, 1});
  l1.unique();
  l2.unique();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_sort, t1) {
  mystd::list<int> l1({1, 1, 1, 1, 3});
  std::list<int> l2({1, 1, 1, 1, 3});
  l1.sort();
  l2.sort();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_sort, t2) {
  mystd::list<int> l1 = {};
  std::list<int> l2 = {};
  l1.sort();
  l2.sort();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_sort, t3) {
  mystd::list<int> l1({1});
  std::list<int> l2({1});
  l1.sort();
  l2.sort();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_sort, t4) {
  mystd::list<int> l1({2, 1, 3, 3, -5, -9, 0});
  std::list<int> l2({2, 1, 3, 3, -5, -9, 0});
  l1.sort();
  l2.sort();
  ASSERT_DOUBLE_EQ(l1.size(), l2.size());

  auto it1 = l1.begin();
  auto it2 = l2.begin();
  for (; it1 != l1.end(); it1++, it2++) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_const_iterator, t1) {
  mystd::list<int> l1({1, 1, 1, 1, 3});
  std::list<int> l2({1, 1, 1, 1, 3});

  mystd::list<int>::const_iterator it1 = l1.begin();
  std::list<int>::const_iterator it2 = l2.begin();
  for (; it1 != l1.end(); ++it1, ++it2) ASSERT_DOUBLE_EQ(*it1, *it2);
  for (; it1 != l1.end(); ++it1, ++it2) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_const_iterator, t2) {
  mystd::list<int> l1({1, 1, 1, 1, 3});
  std::list<int> l2({1, 1, 1, 1, 3});

  mystd::list<int>::const_iterator it1 = l1.begin();
  std::list<int>::const_iterator it2 = l2.begin();
  ++it1;
  ++it2;
  for (; it1 != l1.begin(); --it1, --it2) ASSERT_DOUBLE_EQ(*it1, *it2);
  for (; it1 != l1.begin(); --it1, --it2) ASSERT_DOUBLE_EQ(*it1, *it2);
}

TEST(list_test_iterator, t1) {
  mystd::list<int> l1({1, 1, 1, 1, 3});
  std::list<int> l2({1, 1, 1, 1, 3});

  mystd::list<int>::iterator it1 = l1.begin();
  std::list<int>::iterator it2 = l2.begin();
  for (; it1 != l1.end(); ++it1, ++it2) ASSERT_DOUBLE_EQ(*it1, *it2);
  for (; it1 != l1.end(); ++it1, ++it2) ASSERT_DOUBLE_EQ(*it1, *it2);

  mystd::list<int>::iterator it3 = l1.end();
  std::list<int>::iterator it4 = l2.end();
  for (; it3 != l1.end(); --it3, --it4) ASSERT_DOUBLE_EQ(*it3, *it4);
  for (; it3 != l1.end(); --it3, --it4) ASSERT_DOUBLE_EQ(*it3, *it4);
}
