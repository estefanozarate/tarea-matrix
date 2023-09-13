
#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
class Matrix {
   private:
      int x;
      int y;
      int** pMatrix;
   public:
      Matrix();
      Matrix(int filas, int columnas, const int setteandoMatrix);
      Matrix(int filas, int columnas);
      Matrix(const Matrix& other);
      void swap(Matrix& other);
      Matrix(Matrix&& otra) noexcept;
      ~Matrix();
      Matrix operator+(Matrix& otra);
      Matrix operator*(const int escalar);
      Matrix operator*(const Matrix& B);
      bool operator==(const Matrix& B);
      bool operator!=(const Matrix& B);
      Matrix operator *=(const int NUMERO);
      friend std::ostream& operator<<(std::ostream& COUT, const Matrix& matriz);
      Matrix operator+ (const int escalar);
};

#endif
