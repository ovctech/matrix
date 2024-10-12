#include "s21_matrix_oop.h"

namespace S21 {

// Constructors and Destructors
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  AllocateMemoryForMatrix_();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  AllocateMemoryForMatrix_();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

// Maths and special methodes
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    return FAILURE;
  };
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > EPS) {
        return FAILURE;
      }
    }
  }
  return SUCCESS;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Некорректное количество столбцов или строк!");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("Некорректное количество столбцов или строк!");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(double num) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::logic_error(
        "Некорректное количество столбцов у матрицы A или строк у B, (AxB)!");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (cols_ != rows_) {
    throw std::logic_error("Матрица не квадратная!");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      S21Matrix tmp = GetMinorOfMatrix_(i, j);
      result.matrix_[i][j] = std::pow(-1, i + j) * tmp.Determinant();
    }
  }
  return result;
}

double S21Matrix::Determinant() const {
  if (cols_ != rows_) {
    throw std::logic_error("Матрица не квадратная!");
  }
  double result = 0;
  int size = rows_;
  if (size == 1) {
    result = matrix_[0][0];
  } else if (size == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  } else {
    S21Matrix tmp = S21Matrix(size - 1, size - 1);
    result = 0.0;
    double sign = 1.0;
    double det_tmp = 0.0;
    for (int i = 0; i < size; i++) {
      tmp = GetMinorOfMatrix_(0, i);
      det_tmp = tmp.Determinant();
      result += sign * matrix_[0][i] * det_tmp;
      sign = -sign;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (cols_ != rows_) {
    throw std::logic_error("Матрица не квадратная!");
  }
  double det_result = this->Determinant();
  if (std::abs(det_result) < EPS) {
    throw std::logic_error("Матрица сингулярная!");
  }
  S21Matrix result = this->CalcComplements().Transpose() * (1.0 / det_result);
  return result;
}

// Overloaded operators

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result(*this);  // компилятор создает этот объект вне этого
                            // метода return value opitimization
  // S21Matrix result = *this;
  // S21Matrix result = S21Matrix(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(double num) const {
  S21Matrix result = *this;
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  bool result = this->EqMatrix(other);
  return result;
}

void S21Matrix::Swap(S21Matrix& other) {
  std::swap(matrix_, other.matrix_);
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
}

S21Matrix& S21Matrix::operator=(S21Matrix other) {  // a = b = c
  Swap(other);
  return *this;
}

// S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
//   for (int i = 0; i < rows_; ++i) {
//     delete[] matrix_[i];
//   }
//   delete[] matrix_;
//   rows_ = other.rows_;
//   cols_ = other.cols_;
//   matrix_ = other.matrix_;
//   other.rows_ = 0;
//   other.cols_ = 0;
//   other.matrix_ = nullptr;
//   return *this;
// }

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {  // (a = b) = c;
  *this = *this + other;
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  *this = *this - other;
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  *this = (*this) * other;
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i >= 0 && i < rows_ && j >= 0 && j < cols_) {
    return matrix_[i][j];
  } else {
    throw std::out_of_range("Запрашиваемый индекс вне размерности матрицы!");
  }
}

const double& S21Matrix::operator()(int i, int j) const {
  if (i >= 0 && i < rows_ && j >= 0 && j < cols_) {
    return matrix_[i][j];
  } else {
    throw std::out_of_range("Запрашиваемый индекс вне размерности матрицы!");
  }
}

// Setters and Getters

int S21Matrix::GetCols() const { return cols_; }

int S21Matrix::GetRows() const { return rows_; }

void S21Matrix::SetCols(int cols) {
  if (cols < 0) {
    throw std::logic_error("Некорректное количество столбцов или строк!");
  }
  if (cols != cols_) {
    S21Matrix tmp = S21Matrix(rows_, cols);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < std::min(cols, cols_); j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
    if (cols > cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = cols_; j < cols; j++) {
          tmp.matrix_[i][j] = 0;
        }
      }
    }
    *this = tmp;
  }
}

void S21Matrix::SetRows(int rows) {
  if (rows < 0) {
    throw std::logic_error("Некорректное количество столбцов или строк!");
  }
  if (rows != rows_) {
    S21Matrix tmp = S21Matrix(rows, cols_);
    for (int i = 0; i < std::min(rows, rows_); i++) {
      for (int j = 0; j < cols_; j++) {
        tmp.matrix_[i][j] = matrix_[i][j];
      }
    }
    if (rows > rows_) {
      for (int i = rows_; i < rows; i++) {
        for (int j = 0; j < cols_; j++) {
          tmp.matrix_[i][j] = 0;
        }
      }
    }
    *this = tmp;
  }
}

// Private Methodes

void S21Matrix::AllocateMemoryForMatrix_() {
  if (rows_ < 1 || cols_ < 1) {
    throw std::logic_error("Некорректное количество столбцов или строк!");
  }
  matrix_ = new double* [rows_] {};
  int num_of_allocated_rows = 0;
  try {
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_]{};
      ++num_of_allocated_rows;
    }
  } catch (std::bad_alloc& e) {
    for (int i = 0; i < num_of_allocated_rows; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    throw;
  }
}

S21Matrix S21Matrix::GetMinorOfMatrix_(int row, int column) const {
  S21Matrix minor_of_matrix;
  if (cols_ == 1 && rows_ == 1) {
    minor_of_matrix = S21Matrix(rows_, cols_);
    minor_of_matrix.matrix_[0][0] = matrix_[0][0];
    return minor_of_matrix;
  }
  minor_of_matrix = S21Matrix(rows_ - 1, cols_ - 1);
  int shift_i = 0;
  for (int i = 0; i < rows_ - 1; i++) {
    if (i == row) {
      shift_i = 1;
    }
    int shift_j = 0;
    for (int j = 0; j < cols_ - 1; j++) {
      if (j == column) {
        shift_j = 1;
      }
      minor_of_matrix.matrix_[i][j] = matrix_[i + shift_i][j + shift_j];
    }
  }
  return minor_of_matrix;
}
}  // namespace S21