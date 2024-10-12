#include <gtest/gtest.h>

#include "s21_matrix_oop.h"
#define S21_EPS 1e-7

TEST(TestOverloadOperators, Eq1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 3.0;
  B(1, 1) = 4.0;
  bool is_equal = A == B;
  EXPECT_TRUE(is_equal);
}

TEST(TestOverloadOperators, Eq2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 3.0;
  B(1, 1) = 5.0;
  bool is_equal = A == B;
  EXPECT_FALSE(is_equal);
}

TEST(TestOverloadOperators, Eq3) {
  S21::S21Matrix A(1, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 0.0;
  B(1, 1) = 0.0;
  bool is_equal = A == B;
  EXPECT_FALSE(is_equal);
}

TEST(TestOverloadOperators, Eq4) {
  S21::S21Matrix A(2, 1);
  A(0, 0) = 1.0;
  A(1, 0) = 2.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 2.0;
  B(1, 1) = 0.0;
  bool is_equal = A == B;
  EXPECT_FALSE(is_equal);
}

TEST(TestOverloadOperators, Eq5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1e-6;
  bool is_equal = A == B;
  EXPECT_TRUE(is_equal);
}

TEST(TestOverloadOperators, Eq6) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1e-6;
  bool is_equal = A == B;
  EXPECT_TRUE(is_equal);
}

TEST(TestOverloadOperators, Eq7) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2e-6;
  bool is_equal = A == B;
  EXPECT_FALSE(is_equal);
  EXPECT_FALSE(A == B);
}

TEST(TestOverloadOperators, Sum1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  S21::S21Matrix C = A + B;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), 3.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), 5.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), 7.0, S21_EPS);
  EXPECT_NEAR(C(1, 1), 9.0, S21_EPS);
}

TEST(TestOverloadOperators, Sum2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  A(0, 1) = 2e-6;
  A(1, 0) = 3e-6;
  A(1, 1) = 4e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2e-6;
  B(0, 1) = 3e-6;
  B(1, 0) = 4e-6;
  B(1, 1) = 5e-6;
  S21::S21Matrix C = A + B;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), 3e-6, S21_EPS);
  EXPECT_NEAR(C(0, 1), 5e-6, S21_EPS);
  EXPECT_NEAR(C(1, 0), 7e-6, S21_EPS);
  EXPECT_NEAR(C(1, 1), 9e-6, S21_EPS);
}

TEST(TestOverloadOperators, Sum3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 23456789.0;
  B(0, 1) = 34567890.0;
  B(1, 0) = -2345.123;
  B(1, 1) = -3456.1234;
  S21::S21Matrix C = A + B;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), 35802467.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), 58024679.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), -3579.123, S21_EPS);
  EXPECT_NEAR(C(1, 1), -5801.2464, S21_EPS);
}

TEST(TestOverloadOperators, Sum4) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A = A + A;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8.0, S21_EPS);
}

TEST(TestOverloadOperators, Sum5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A += A;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8.0, S21_EPS);
}

TEST(TestOverloadOperators, SumException1) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 2);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A + B);
  EXPECT_ANY_THROW(B + A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, SumException2) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(2, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A + B);
  EXPECT_ANY_THROW(B + A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, SumException3) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A + B);
  EXPECT_ANY_THROW(B + A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, Sub1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  S21::S21Matrix C = A - B;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), -1.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), -1.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), -1.0, S21_EPS);
  EXPECT_NEAR(C(1, 1), -1.0, S21_EPS);
}

TEST(TestOverloadOperators, Sub2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  A(0, 1) = 2e-6;
  A(1, 0) = 3e-6;
  A(1, 1) = 4e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2e-6;
  B(0, 1) = 3e-6;
  B(1, 0) = 4e-6;
  B(1, 1) = 5e-6;
  S21::S21Matrix C = B - A;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), 1e-6, S21_EPS);
  EXPECT_NEAR(C(0, 1), 1e-6, S21_EPS);
  EXPECT_NEAR(C(1, 0), 1e-6, S21_EPS);
  EXPECT_NEAR(C(1, 1), 1e-6, S21_EPS);
}

TEST(TestOverloadOperators, Sub3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 23456789.0;
  B(0, 1) = 34567890.0;
  B(1, 0) = -2345.123;
  B(1, 1) = -3456.1234;
  S21::S21Matrix C = A - B;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), -11111111.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), -11111101.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), 1111.123, S21_EPS);
  EXPECT_NEAR(C(1, 1), 1111.0004, S21_EPS);
}

TEST(TestOverloadOperators, Sub4) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A = A - A;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 0.0, S21_EPS);
}

TEST(TestOverloadOperators, Sub5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(A);
  A -= B;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 0.0, S21_EPS);
}

TEST(TestOverloadOperators, SubException1) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 2);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A - B);
  EXPECT_ANY_THROW(B - A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, SubException2) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(2, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A - B);
  EXPECT_ANY_THROW(B - A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, SubException3) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A - B);
  EXPECT_ANY_THROW(B - A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, MulNumber1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  double number = 2.0;
  A = A * number;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8.0, S21_EPS);
}

TEST(TestOverloadOperators, MulNumber2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  A(0, 1) = 2e-6;
  A(1, 0) = 3e-6;
  A(1, 1) = 4e-6;
  double number = 2.0;
  A = A * number;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2e-6, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4e-6, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6e-6, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8e-6, S21_EPS);
}

TEST(TestOverloadOperators, MulNumber3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  double number = 1.0;
  A = A * number;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 12345678.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 23456789.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -1234.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -2345.123, S21_EPS);
}

TEST(TestOverloadOperators, MulNumber4) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  double number = 0.0;
  A = A * number;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 0.0, S21_EPS);
}

TEST(TestOverloadOperators, MulNumber5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  double number = 2.0;
  A = A * number;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8.0, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrix1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = -2.0;
  A(1, 0) = 3.0;
  A(1, 1) = -4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  S21::S21Matrix C = A * B;
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_NEAR(C(0, 0), -6.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), -7.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), -10.0, S21_EPS);
  EXPECT_NEAR(C(1, 1), -11.0, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrix2) {
  S21::S21Matrix A(1, 2);
  A(0, 0) = 1.0;
  A(0, 1) = -2.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  S21::S21Matrix C = A * B;
  EXPECT_EQ(C.GetRows(), 1);
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_NEAR(C(0, 0), -6.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), -7.0, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrix3) {
  S21::S21Matrix A(2, 1);
  A(0, 0) = 1.0;
  A(1, 0) = -2.0;
  S21::S21Matrix B(1, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  S21::S21Matrix C = A * B;
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_NEAR(C(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), 3.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), -4.0, S21_EPS);
  EXPECT_NEAR(C(1, 1), -6.0, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrix4) {
  S21::S21Matrix A(1, 2);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  S21::S21Matrix B(2, 1);
  B(0, 0) = 2.1234;
  B(1, 0) = 3.1234;
  S21::S21Matrix C = A * B;
  EXPECT_EQ(C.GetRows(), 1);
  EXPECT_EQ(C.GetCols(), 1);
  EXPECT_NEAR(C(0, 0), -4.2468, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrix5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = -3.0;
  A(1, 1) = -4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 0.0;
  B(1, 1) = 1.0;
  S21::S21Matrix C = A * B;
  EXPECT_EQ(C.GetRows(), 2);
  EXPECT_EQ(C.GetCols(), 2);
  EXPECT_NEAR(C(0, 0), 1.0, S21_EPS);
  EXPECT_NEAR(C(0, 1), 2.0, S21_EPS);
  EXPECT_NEAR(C(1, 0), -3.0, S21_EPS);
  EXPECT_NEAR(C(1, 1), -4.0, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrix6) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = -3.0;
  A(1, 1) = -4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 0.0;
  B(1, 1) = 1.0;
  A *= B;
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_NEAR(A(0, 0), 1.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 2.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -3.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -4.0, S21_EPS);
}

TEST(TestOverloadOperators, MulMatrixException1) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 2);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A * B);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, MulMatrixException2) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(2, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(B * A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, MulMatrixException3) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A * B);
  EXPECT_ANY_THROW(B * A);
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOverloadOperators, CopyEq1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  A(1, 0) = 3.1234;
  A(1, 1) = -4.1234;
  S21::S21Matrix B(3, 3);
  B = A;
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(A, B);
}

TEST(TestOverloadOperators, ConstGet1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  A(1, 0) = 3.1234;
  A(1, 1) = -4.1234;
  const S21::S21Matrix B = A;
  const double a = B(0, 0);
  EXPECT_NEAR(a, 1.1234, S21_EPS);
}

TEST(TestMatrix, AccessValidIndices) {
  const int rows = 2;
  const int cols = 2;

  S21::S21Matrix A(rows, cols);

  // Accessing elements with valid indices should not throw any exception
  EXPECT_NO_THROW(A(0, 0));
  EXPECT_NO_THROW(A(1, 1));

  // Accessing elements with valid indices (const version) should not throw any
  // exception
  const S21::S21Matrix B(rows, cols);
  EXPECT_NO_THROW(B(0, 0));
  EXPECT_NO_THROW(B(1, 1));
}

TEST(TestMatrix, AccessInvalidIndices) {
  const int rows = 2;
  const int cols = 2;

  S21::S21Matrix A(rows, cols);

  // Accessing elements with invalid indices should throw std::out_of_range
  EXPECT_THROW(A(-1, 0), std::out_of_range);
  EXPECT_THROW(A(0, -1), std::out_of_range);
  EXPECT_THROW(A(rows, 0), std::out_of_range);
  EXPECT_THROW(A(0, cols), std::out_of_range);

  // Accessing elements with invalid indices (const version) should throw
  // std::out_of_range
  const S21::S21Matrix B(rows, cols);
  EXPECT_THROW(B(-1, 0), std::out_of_range);
  EXPECT_THROW(B(0, -1), std::out_of_range);
  EXPECT_THROW(B(rows, 0), std::out_of_range);
  EXPECT_THROW(B(0, cols), std::out_of_range);
}

TEST(TestOverloadOperators, GetException1) {
  S21::S21Matrix A(2, 2);
  EXPECT_ANY_THROW(A(2, 0));
}

TEST(TestOverloadOperators, GetException2) {
  S21::S21Matrix A(2, 2);
  EXPECT_ANY_THROW(A(0, 2));
}

TEST(TestOverloadOperators, Chain1) {
  S21::S21Matrix A(1, 1);
  S21::S21Matrix B(2, 2);
  S21::S21Matrix C(3, 3);
  EXPECT_EQ((A = B = C).GetCols(), 3);
  EXPECT_TRUE(A == C);
}

TEST(TestOverloadOperators, Chain2) {
  S21::S21Matrix A(1, 1);
  S21::S21Matrix B(2, 2);
  S21::S21Matrix C(3, 3);
  EXPECT_EQ((A = std::move(B) = std::move(C)).GetCols(), 3);
  EXPECT_FALSE(A == C);
}

TEST(TestOperations, Eq1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 3.0;
  B(1, 1) = 4.0;
  bool is_equal = A.EqMatrix(B);
  EXPECT_TRUE(is_equal);
}

TEST(TestOperations, Eq2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 3.0;
  B(1, 1) = 5.0;
  bool is_equal = A.EqMatrix(B);
  EXPECT_FALSE(is_equal);
}

TEST(TestOperations, Eq3) {
  S21::S21Matrix A(1, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 2.0;
  B(1, 0) = 0.0;
  B(1, 1) = 0.0;
  bool is_equal = A.EqMatrix(B);
  EXPECT_FALSE(is_equal);
}

TEST(TestOperations, Eq4) {
  S21::S21Matrix A(2, 1);
  A(0, 0) = 1.0;
  A(1, 0) = 2.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 2.0;
  B(1, 1) = 0.0;
  bool is_equal = A.EqMatrix(B);
  EXPECT_FALSE(is_equal);
}

TEST(TestOperations, Eq5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1e-6;
  bool is_equal = A.EqMatrix(B);
  EXPECT_TRUE(is_equal);
}

TEST(TestOperations, Eq6) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1e-6;
  bool is_equal = A.EqMatrix(B);
  EXPECT_TRUE(is_equal);
}

TEST(TestOperations, Eq7) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2e-6;
  bool is_equal = A.EqMatrix(B);
  EXPECT_FALSE(is_equal);
  EXPECT_FALSE(A == B);
}

TEST(TestOperations, Sum1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  A.SumMatrix(B);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 3.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 5.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 7.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 9.0, S21_EPS);
}

TEST(TestOperations, Sum2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  A(0, 1) = 2e-6;
  A(1, 0) = 3e-6;
  A(1, 1) = 4e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2e-6;
  B(0, 1) = 3e-6;
  B(1, 0) = 4e-6;
  B(1, 1) = 5e-6;
  A.SumMatrix(B);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 3e-6, S21_EPS);
  EXPECT_NEAR(A(0, 1), 5e-6, S21_EPS);
  EXPECT_NEAR(A(1, 0), 7e-6, S21_EPS);
  EXPECT_NEAR(A(1, 1), 9e-6, S21_EPS);
}

TEST(TestOperations, Sum3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 23456789.0;
  B(0, 1) = 34567890.0;
  B(1, 0) = -2345.123;
  B(1, 1) = -3456.1234;
  A.SumMatrix(B);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 35802467.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 58024679.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -3579.123, S21_EPS);
  EXPECT_NEAR(A(1, 1), -5801.2464, S21_EPS);
}

TEST(TestOperations, Sum4) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A.SumMatrix(A);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8.0, S21_EPS);
}

TEST(TestOperations, SumException1) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 2);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.SumMatrix(B));
  EXPECT_ANY_THROW(B.SumMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, SumException2) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(2, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.SumMatrix(B));
  EXPECT_ANY_THROW(B.SumMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, SumException3) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.SumMatrix(B));
  EXPECT_ANY_THROW(B.SumMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, MutatorException) {
  S21::S21Matrix A(2, 2);
  EXPECT_ANY_THROW(A(1, -1));
}

TEST(TestOperations, Sub1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  A.SubMatrix(B);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), -1.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), -1.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -1.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -1.0, S21_EPS);
}

TEST(TestOperations, Sub2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  A(0, 1) = 2e-6;
  A(1, 0) = 3e-6;
  A(1, 1) = 4e-6;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2e-6;
  B(0, 1) = 3e-6;
  B(1, 0) = 4e-6;
  B(1, 1) = 5e-6;
  B.SubMatrix(A);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_NEAR(B(0, 0), 1e-6, S21_EPS);
  EXPECT_NEAR(B(0, 1), 1e-6, S21_EPS);
  EXPECT_NEAR(B(1, 0), 1e-6, S21_EPS);
  EXPECT_NEAR(B(1, 1), 1e-6, S21_EPS);
}

TEST(TestOperations, Sub3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 23456789.0;
  B(0, 1) = 34567890.0;
  B(1, 0) = -2345.123;
  B(1, 1) = -3456.1234;
  A.SubMatrix(B);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), -11111111.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), -11111101.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 1111.123, S21_EPS);
  EXPECT_NEAR(A(1, 1), 1111.0004, S21_EPS);
}

TEST(TestOperations, Sub4) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A.SubMatrix(A);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 0.0, S21_EPS);
}

TEST(TestOperations, SubException1) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 2);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.SubMatrix(B));
  EXPECT_ANY_THROW(B.SubMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, SubException2) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(2, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.SubMatrix(B));
  EXPECT_ANY_THROW(B.SubMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, SubException3) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.SubMatrix(B));
  EXPECT_ANY_THROW(B.SubMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, MulNumber1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A.MulNumber(2.0);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8.0, S21_EPS);
}

TEST(TestOperations, MulNumber2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1e-6;
  A(0, 1) = 2e-6;
  A(1, 0) = 3e-6;
  A(1, 1) = 4e-6;
  A.MulNumber(2.0);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 2e-6, S21_EPS);
  EXPECT_NEAR(A(0, 1), 4e-6, S21_EPS);
  EXPECT_NEAR(A(1, 0), 6e-6, S21_EPS);
  EXPECT_NEAR(A(1, 1), 8e-6, S21_EPS);
}

TEST(TestOperations, MulNumber3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  A.MulNumber(1.0);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 12345678.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 23456789.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -1234.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -2345.123, S21_EPS);
}

TEST(TestOperations, MulNumber4) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 12345678.0;
  A(0, 1) = 23456789.0;
  A(1, 0) = -1234;
  A(1, 1) = -2345.123;
  A.MulNumber(0.0);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), 0.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), 0.0, S21_EPS);
}

TEST(TestOperations, MulMatrix1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = -2.0;
  A(1, 0) = 3.0;
  A(1, 1) = -4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_NEAR(A(0, 0), -6.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), -7.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -10.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -11.0, S21_EPS);
}

TEST(TestOperations, MulMatrix2) {
  S21::S21Matrix A(1, 2);
  A(0, 0) = 1.0;
  A(0, 1) = -2.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  B(1, 0) = 4.0;
  B(1, 1) = 5.0;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetRows(), 1);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_NEAR(A(0, 0), -6.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), -7.0, S21_EPS);
}

TEST(TestOperations, MulMatrix3) {
  S21::S21Matrix A(2, 1);
  A(0, 0) = 1.0;
  A(1, 0) = -2.0;
  S21::S21Matrix B(1, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 3.0;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_NEAR(A(0, 0), 2.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 3.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -4.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -6.0, S21_EPS);
}

TEST(TestOperations, MulMatrix4) {
  S21::S21Matrix A(1, 2);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  S21::S21Matrix B(2, 1);
  B(0, 0) = 2.1234;
  B(1, 0) = 3.1234;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetRows(), 1);
  EXPECT_EQ(A.GetCols(), 1);
  EXPECT_NEAR(A(0, 0), -4.2468, S21_EPS);
}

TEST(TestOperations, MulMatrix5) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = -3.0;
  A(1, 1) = -4.0;
  S21::S21Matrix B(2, 2);
  B(0, 0) = 1.0;
  B(0, 1) = 0.0;
  B(1, 0) = 0.0;
  B(1, 1) = 1.0;
  A.MulMatrix(B);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_NEAR(A(0, 0), 1.0, S21_EPS);
  EXPECT_NEAR(A(0, 1), 2.0, S21_EPS);
  EXPECT_NEAR(A(1, 0), -3.0, S21_EPS);
  EXPECT_NEAR(A(1, 1), -4.0, S21_EPS);
}

TEST(TestOperations, MulMatrixException1) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 2);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.MulMatrix(B));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, MulMatrixException2) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(2, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(B.MulMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, MulMatrixException3) {
  S21::S21Matrix A(2, 2);
  S21::S21Matrix B(3, 3);
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B_copy = B;
  EXPECT_ANY_THROW(A.MulMatrix(B));
  EXPECT_ANY_THROW(B.MulMatrix(A));
  EXPECT_EQ(A, A_copy);
  EXPECT_EQ(B, B_copy);
}

TEST(TestOperations, Transpose1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  A(1, 0) = 3.1234;
  A(1, 1) = -4.1234;
  S21::S21Matrix B = A.Transpose();
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_NEAR(B(0, 0), 1.1234, S21_EPS);
  EXPECT_NEAR(B(0, 1), 3.1234, S21_EPS);
  EXPECT_NEAR(B(1, 0), -2.1234, S21_EPS);
  EXPECT_NEAR(B(1, 1), -4.1234, S21_EPS);
}

TEST(TestOperations, Transpose2) {
  S21::S21Matrix A(2, 1);
  A(0, 0) = 1.1234;
  A(1, 0) = -2.1234;
  S21::S21Matrix B = A.Transpose();
  EXPECT_EQ(B.GetRows(), 1);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_NEAR(B(0, 0), 1.1234, S21_EPS);
  EXPECT_NEAR(B(0, 1), -2.1234, S21_EPS);
}

TEST(TestOperations, Transpose3) {
  S21::S21Matrix A(2, 3);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  A(0, 2) = 3.1234;
  A(1, 0) = -4.1234;
  A(1, 1) = 5.1234;
  A(1, 2) = -6.1234;
  S21::S21Matrix B = A.Transpose().Transpose();
  EXPECT_TRUE(A == B);
}

TEST(TestOperations, Transpose4) {
  S21::S21Matrix A(2, 3);
  A(0, 0) = 1.1234;
  A(0, 1) = -2.1234;
  A(0, 2) = 3.1234;
  A(1, 0) = -4.1234;
  A(1, 1) = 5.1234;
  A(1, 2) = -6.1234;
  S21::S21Matrix B = A.Transpose().Transpose().Transpose();
  EXPECT_TRUE(B == A.Transpose());
}

TEST(TestOperations, CalcComplements1) {
  S21::S21Matrix A(1, 1);
  A(0, 0) = 5.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.CalcComplements();
  EXPECT_EQ(B.GetRows(), 1);
  EXPECT_EQ(B.GetCols(), 1);
  EXPECT_NEAR(B(0, 0), 5.0, S21_EPS);
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, CalcComplements2) {
  S21::S21Matrix A(3, 3);
  A(0, 0) = -3.0;
  A(0, 1) = 6.0;
  A(0, 2) = -3.0;
  A(1, 0) = 6.0;
  A(1, 1) = -12.0;
  A(1, 2) = 6.0;
  A(2, 0) = -3.0;
  A(2, 1) = 6.0;
  A(2, 2) = -3.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.CalcComplements();
  EXPECT_EQ(B.GetRows(), 3);
  EXPECT_EQ(B.GetCols(), 3);
  EXPECT_NEAR(B(0, 0), 0.0, S21_EPS);
  EXPECT_NEAR(B(0, 1), 0.0, S21_EPS);
  EXPECT_NEAR(B(0, 2), 0.0, S21_EPS);
  EXPECT_NEAR(B(1, 0), 0.0, S21_EPS);
  EXPECT_NEAR(B(1, 1), 0.0, S21_EPS);
  EXPECT_NEAR(B(1, 2), 0.0, S21_EPS);
  EXPECT_NEAR(B(2, 0), 0.0, S21_EPS);
  EXPECT_NEAR(B(2, 1), 0.0, S21_EPS);
  EXPECT_NEAR(B(2, 2), 0.0, S21_EPS);
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, CalcComplements3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.CalcComplements();
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_NEAR(B(0, 0), 4.0, S21_EPS);
  EXPECT_NEAR(B(0, 1), -3.0, S21_EPS);
  EXPECT_NEAR(B(1, 0), -2.0, S21_EPS);
  EXPECT_NEAR(B(1, 1), 1.0, S21_EPS);
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, CalcComplements4) {
  S21::S21Matrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A(2, 0) = 7.0;
  A(2, 1) = 8.0;
  A(2, 2) = 9.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.CalcComplements();
  EXPECT_EQ(B.GetRows(), 3);
  EXPECT_EQ(B.GetCols(), 3);
  EXPECT_NEAR(B(0, 0), -3.0, S21_EPS);
  EXPECT_NEAR(B(0, 1), 6.0, S21_EPS);
  EXPECT_NEAR(B(0, 2), -3.0, S21_EPS);
  EXPECT_NEAR(B(1, 0), 6.0, S21_EPS);
  EXPECT_NEAR(B(1, 1), -12.0, S21_EPS);
  EXPECT_NEAR(B(1, 2), 6.0, S21_EPS);
  EXPECT_NEAR(B(2, 0), -3.0, S21_EPS);
  EXPECT_NEAR(B(2, 1), 6.0, S21_EPS);
  EXPECT_NEAR(B(2, 2), -3.0, S21_EPS);
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, CalcComplementsException1) {
  S21::S21Matrix A(2, 3);
  S21::S21Matrix A_copy = A;
  EXPECT_ANY_THROW(A.CalcComplements());
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, CalcComplementsException2) {
  S21::S21Matrix A(3, 2);
  S21::S21Matrix A_copy = A;
  EXPECT_ANY_THROW(A.CalcComplements());
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, Determinant1) {
  S21::S21Matrix A(1, 1);
  A(0, 0) = 5.0;
  EXPECT_NEAR(A.Determinant(), 5.0, S21_EPS);
}

TEST(TestOperations, Determinant2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  EXPECT_NEAR(A.Determinant(), -2.0, S21_EPS);
}

TEST(TestOperations, Determinant3) {
  S21::S21Matrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A(2, 0) = 7.0;
  A(2, 1) = 8.0;
  A(2, 2) = 9.0;
  EXPECT_NEAR(A.Determinant(), 0.0, S21_EPS);
}

TEST(TestOperations, Determinant4) {
  S21::S21Matrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A(2, 0) = 7.0;
  A(2, 1) = 8.0;
  A(2, 2) = 10.0;
  EXPECT_NEAR(A.Determinant(), -3.0, S21_EPS);
}

TEST(TestOperations, Determinant5) {
  S21::S21Matrix A(5, 5);
  A(0, 0) = 3.0;
  A(0, 1) = 4.0;
  A(0, 2) = 1.3;
  A(0, 3) = 3;
  A(0, 4) = 2.2;
  A(1, 0) = 1.0;
  A(1, 1) = 2.0;
  A(1, 2) = 3.0;
  A(1, 3) = 4.0;
  A(1, 4) = 5.0;
  A(2, 0) = -1234.12;
  A(2, 1) = 1234.12;
  A(2, 2) = -1234.12;
  A(2, 3) = 1234.12;
  A(2, 4) = -1234.12;
  A(3, 0) = 5.0;
  A(3, 1) = 4.0;
  A(3, 2) = 3.0;
  A(3, 3) = 2.0;
  A(3, 4) = 1.0;
  A(4, 0) = 123.0;
  A(4, 1) = 234.0;
  A(4, 2) = 345.0;
  A(4, 3) = 456.5;
  A(4, 4) = 567.5;
  EXPECT_NEAR(A.Determinant(), -28137.936, S21_EPS);
}

TEST(TestOperations, DeterminantException1) {
  S21::S21Matrix A(2, 3);
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(TestOperations, DeterminantException2) {
  S21::S21Matrix A(3, 2);
  EXPECT_ANY_THROW(A.Determinant());
}

TEST(TestOperations, InverseMatrix1) {
  S21::S21Matrix A(1, 1);
  A(0, 0) = 5.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.InverseMatrix();
  EXPECT_EQ(B.GetRows(), 1);
  EXPECT_EQ(B.GetCols(), 1);
  EXPECT_NEAR(B(0, 0), 1, S21_EPS);
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, InverseMatrix2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.InverseMatrix();
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_NEAR(B(0, 0), -2.0, S21_EPS);
  EXPECT_NEAR(B(0, 1), 1.0, S21_EPS);
  EXPECT_NEAR(B(1, 0), 1.5, S21_EPS);
  EXPECT_NEAR(B(1, 1), -0.5, S21_EPS);
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, InverseMatrix3) {
  S21::S21Matrix A(3, 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A(2, 0) = 7.2;
  A(2, 1) = 8.0;
  A(2, 2) = 9.0;
  S21::S21Matrix A_copy = A;
  S21::S21Matrix B = A.InverseMatrix();
  EXPECT_EQ(B.GetRows(), 3);
  EXPECT_EQ(B.GetCols(), 3);
  EXPECT_NEAR(B(0, 0), 5.0, S21_EPS);
  EXPECT_NEAR(B(0, 1), -10.0, S21_EPS);
  EXPECT_NEAR(B(0, 2), 5.0, S21_EPS);
  EXPECT_NEAR(B(1, 0), -12.0, S21_EPS);
  EXPECT_NEAR(B(1, 1), 21.0, S21_EPS);
  EXPECT_NEAR(B(1, 2), -10.0, S21_EPS);
  EXPECT_NEAR(B(2, 0), 6.66666666, S21_EPS);
  EXPECT_NEAR(B(2, 1), -10.66666666, S21_EPS);
  EXPECT_NEAR(B(2, 2), 5.0, S21_EPS);
}

TEST(TestOperations, InverseMatrixException1) {
  S21::S21Matrix A(2, 3);
  S21::S21Matrix A_copy = A;
  EXPECT_ANY_THROW(A.InverseMatrix());
  EXPECT_EQ(A, A_copy);
}

TEST(TestOperations, InverseMatrixException2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 2.0;
  A(1, 1) = 4.0;
  EXPECT_ANY_THROW(A.InverseMatrix());
}

TEST(TestConstructor, Params1) {
  S21::S21Matrix A;
  int i = A.GetRows();
  int j = A.GetCols();
  EXPECT_EQ(i, 0);
  EXPECT_EQ(j, 0);
}

TEST(TestConstructor, Params2) {
  S21::S21Matrix A(1, 2);
  int i = A.GetRows();
  int j = A.GetCols();
  EXPECT_EQ(i, 1);
  EXPECT_EQ(j, 2);
}

TEST(TestConstructor, Exception1) { EXPECT_ANY_THROW(S21::S21Matrix(-1, 2)); }

TEST(TestConstructor, Exception2) { EXPECT_ANY_THROW(S21::S21Matrix(2, -1)); }

TEST(TestConstructor, Exception3) { EXPECT_ANY_THROW(S21::S21Matrix(-1, -1)); }

TEST(TestConstructor, Exception4) { EXPECT_ANY_THROW(S21::S21Matrix(-1, -1)); }

TEST(TestConstructor, Copy1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B = A;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(A, B);
}

TEST(TestConstructor, Move1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B = std::move(A);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(B(0, 0), 1.0);
  EXPECT_EQ(B(0, 1), 2.0);
  EXPECT_EQ(B(1, 0), 3.0);
  EXPECT_EQ(B(1, 1), 4.0);
}

TEST(TestConstructor, Transfer1) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B(A);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(B.GetRows(), 2);
  EXPECT_EQ(A, B);
}

TEST(TestConstructor, Transfer2) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  S21::S21Matrix B = A * A;
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(B.GetRows(), 2);
  ASSERT_FALSE(A == B);
}

TEST(TestConstructor, Transfer3) {
  S21::S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(1, 0) = 3.0;
  A(1, 1) = 4.0;
  A = A * A;
  S21::S21Matrix B(A);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(B.GetCols(), 2);
  EXPECT_EQ(B.GetRows(), 2);
  ASSERT_TRUE(A == B);
}

TEST(TestAccessorsMutators, Exception1) {
  S21::S21Matrix A(2, 3);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 3);
  S21::S21Matrix A_copy = A;

  EXPECT_ANY_THROW(A.SetRows(-1));
  EXPECT_EQ(A, A_copy);
}

TEST(TestAccessorsMutators, Exception2) {
  S21::S21Matrix A(2, 3);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 3);
  S21::S21Matrix A_copy = A;

  EXPECT_ANY_THROW(A.SetCols(-1));
  EXPECT_EQ(A, A_copy);
}

TEST(TestAccessorsMutators, Exception3) {
  S21::S21Matrix A(2, 3);
  EXPECT_NO_THROW(A.SetCols(5));
}

// TEST(TestMatrix, MemoryAllocationException) {
//   const int rows = 1486618624;
//   const int cols = 1486618624;
//   EXPECT_ANY_THROW(S21::S21Matrix A(rows, cols));
// }

TEST(TestAccessorsMutators, Simple1) {
  S21::S21Matrix A(2, 3);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 3);
  A.SetRows(3);
  A.SetCols(2);
  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 2);
}

TEST(TestAccessorsMutators, Simple2) {
  S21::S21Matrix A(2, 3);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A.SetRows(3);
  A.SetCols(2);
  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A(0, 0), 1.0);
  EXPECT_EQ(A(0, 1), 2.0);
  EXPECT_EQ(A(1, 0), 4.0);
  EXPECT_EQ(A(1, 1), 5.0);
  EXPECT_EQ(A(2, 0), 0.0);
  EXPECT_EQ(A(2, 1), 0.0);
}

TEST(TestAccessorsMutators, Simple3) {
  S21::S21Matrix A(2, 3);
  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 3);
  A(0, 0) = 1.0;
  A(0, 1) = 2.0;
  A(0, 2) = 3.0;
  A(1, 0) = 4.0;
  A(1, 1) = 5.0;
  A(1, 2) = 6.0;
  A.SetRows(1);
  A.SetCols(2);
  EXPECT_EQ(A.GetRows(), 1);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A(0, 0), 1.0);
  EXPECT_EQ(A(0, 1), 2.0);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
