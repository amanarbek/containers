#include <gtest/gtest.h>

#include "../mystd_containersplus.h"

TEST(DefaultConstr, test0) {
  mystd::array<int, 0> mystd_empty;
  std::array<int, 0> std_empty;
  EXPECT_EQ(mystd_empty.size(), std_empty.size());
  EXPECT_EQ(mystd_empty.size(), std_empty.size());
}

TEST(DefaultConstr, test1) {
  mystd::array<int, 4> mystd_empty;
  std::array<int, 5> std_empty;
  EXPECT_NE(mystd_empty.size(), std_empty.size());
  EXPECT_NE(mystd_empty.size(), std_empty.size());
}

TEST(InitializerListConstructor, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  for (size_t i = 0; i < mystd_array.size(); ++i) {
    EXPECT_EQ(mystd_array[i], std_array[i]);
  }
}

TEST(CopyConstr, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  mystd::array<int, 6> mystd_copy(mystd_array);
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_copy(std_array);
  for (size_t i = 0; i < mystd_copy.size(); ++i) {
    EXPECT_EQ(mystd_copy[i], std_copy[i]);
    EXPECT_EQ(mystd_array[i], std_array[i]);
  }
}

TEST(Move_Constr, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  mystd::array<int, 6> mystd_move(std::move(mystd_array));
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_move(std::move(std_array));
  for (size_t i = 0; i < mystd_move.size(); ++i) {
    EXPECT_EQ(mystd_move[i], std_move[i]);
    EXPECT_EQ(mystd_array[i], std_array[i]);
  }
}

TEST(Operator_Equal_Copy, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  mystd::array<int, 6> mystd_operator_equal = mystd_array;
  for (size_t i = 0; i < mystd_array.size(); ++i) {
    EXPECT_EQ(mystd_array[i], mystd_operator_equal[i]);
    EXPECT_EQ(mystd_array[i], mystd_operator_equal[i]);
  }
}

TEST(Operator_Equal_Move, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  mystd::array<int, 6> mystd_operator_equal = std::move(mystd_array);
  for (size_t i = 0; i < mystd_array.size(); ++i) {
    EXPECT_EQ(mystd_array[i], mystd_operator_equal[i]);
    EXPECT_EQ(mystd_array[i], mystd_operator_equal[i]);
  }
}

TEST(Operator_Square_Bracket, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(mystd_array[3], 4);
}

TEST(At, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(mystd_array[4], 5);
}

TEST(At, test1) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  ASSERT_ANY_THROW(mystd_array.at(6));
}

TEST(Front, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(mystd_array.front(), mystd_array[0]);
  EXPECT_EQ(mystd_array.front(), std_array.front());
}

TEST(Back, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  std::array<int, 6> std_array{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(mystd_array.back(), mystd_array[mystd_array.size() - 1]);
  EXPECT_EQ(mystd_array.back(), std_array.back());
}

TEST(Data, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(*mystd_array.data(), mystd_array.front());
  //
}
TEST(Begin, test0) {
  mystd::array<int, 6> mystd_array{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(*mystd_array.begin(), mystd_array.front());
  EXPECT_EQ(*mystd_array.begin() + 1, mystd_array[1]);
}

TEST(End, test0) {
  mystd::array<int, 0> mystd_array;
  EXPECT_EQ(mystd_array.begin(), mystd_array.end());
  EXPECT_EQ(mystd_array.end(), mystd_array.begin() + mystd_array.size());
}

TEST(Empty, test0) {
  mystd::array<int, 0> mystd_array;
  EXPECT_TRUE(mystd_array.empty());
}

TEST(Empty, test1) {
  mystd::array<int, 1> mystd_array;
  EXPECT_FALSE(mystd_array.empty());
}

TEST(Size, test0) {
  mystd::array<int, 1> mystd_array{1};
  std::array<int, 1> std_array{2};
  EXPECT_EQ(mystd_array.size(), std_array.size());
}
TEST(Size, test1) {
  mystd::array<int, 0> mystd_array;
  std::array<int, 0> std_array;
  EXPECT_EQ(mystd_array.size(), std_array.size());
}

TEST(Max_size, test0) {
  mystd::array<int, 3> mystd_array{1, 2, 3};
  std::array<int, 3> std_array{4, 5, 6};
  EXPECT_EQ(mystd_array.max_size(), std_array.max_size());
}

TEST(Swap, test0) {
  mystd::array<int, 3> mystd_array{1, 2, 3};
  mystd::array<int, 3> mystd_array2{3, 2, 1};
  std::array<int, 3> std_array{1, 2, 3};
  std::array<int, 3> std_array2{3, 2, 1};
  mystd_array.swap(mystd_array2);
  std_array.swap(std_array2);
  for (size_t i = 0; i < mystd_array2.size(); ++i) {
    EXPECT_EQ(mystd_array[i], std_array[i]);
  }
}

TEST(Fill, test0) {
  mystd::array<int, 3> mystd_array{1, 2, 3};
  std::array<int, 3> std_array{1, 2, 3};
  mystd_array.fill(5);
  std_array.fill(5);
  for (size_t i = 0; i < mystd_array.size(); ++i) {
    EXPECT_EQ(mystd_array[i], std_array[i]);
  }
}
