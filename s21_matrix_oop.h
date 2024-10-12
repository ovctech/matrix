#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>
#include <stdexcept>

#define OK 0
#define ERROR 1
#define CALCULATION_ERROR 2
#define SUCCESS true
#define FAILURE false
#define EPS 1e-7

namespace S21 {
class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(double num) const;
  S21Matrix operator*(const S21Matrix& other) const;
  bool operator==(const S21Matrix& other) const;
  void Swap(S21Matrix& other);
  S21Matrix& operator=(S21Matrix other);
  // S21Matrix& operator=(S21Matrix&& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;

  int GetCols() const;
  int GetRows() const;
  void SetCols(int cols);
  void SetRows(int rows);

 private:
  int rows_, cols_;
  double** matrix_;

  void AllocateMemoryForMatrix_();
  S21Matrix GetMinorOfMatrix_(int row, int column) const;
};
}  // namespace S21
#endif  // SRC_S21_MATRIX_OOP_H_