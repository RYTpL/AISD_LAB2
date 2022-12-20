#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <random>
#include "matrix.h"
#include <complex>
/*
template<class T>
T Check_Double()
{
    T number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ââåäèòå êîððåêòíîå çíà÷åíèå...\n";
    }
    return number;
}
//int
int Check_Int()
{
    int number = 0;
    while (number <= 0)
    {
        while (!(cin >> number) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Ââåäèòå êîððåêòíîå çíà÷åíèå...\n";
        }
        if (number <= 0) cout << "Ââåäèòå êîððåêòíîå çíà÷åíèå...\n";
    }
    return number;
}
*/
template <class T>
Matrix<T>::Matrix() {
    epsilon = 0.0;
    rows = 0;
    columns = 0;
    matrix = NULL;
}
template <class T>
Matrix<T>::Matrix(int rows, int columns) {
    if (rows > 0)
        this->rows = rows;
    else throw "Invalid value!";
    if (columns > 0)
        this->columns = columns;
    else throw "Invalid value!";

    matrix = new T * [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new T[columns];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = i + j;
}
template <class T>
int Matrix<T>::GetRows() const {
    return rows;
}
template <class T>
int Matrix<T>::GetCols() const {
    return columns;
}

template <class T>
T Matrix<T>::tr()
{
    T result = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                result += matrix[i][j];
            }
        }
    }
    return result;
}
template <class T>
T& Matrix<T>::operator () (int i, int j) {
    if ((i >= 0) && (i < rows) && (j >= 0) && (j < columns))
        return matrix[i][j];
    else throw "Incorrect index values!";
}



template <class T>
Matrix<T> Matrix<T>::operator + (const Matrix<T>& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        return result;
    }
    throw "The dimensions of the matrices do not match! Addition of matrices with different dimensions is unacceptable!";
}

template <class T>
Matrix<T> Matrix<T>::operator - (const Matrix<T>& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix<T> result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
        return result;
    }
    throw "The dimensions of the matrices do not match! Subtraction of matrices with different dimensions is unacceptable!";
}
template <class T>
Matrix<T> Matrix<T>::operator * (const Matrix<T>& rhs) {
    if (columns == rhs.rows) {
        Matrix<T> result(rows, rhs.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                result.matrix[i][j] = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                for (int k = 0; k < columns; k++)
                    result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
        return result;
    }
    throw "Matrices cannot be multiplied! Invalid dimension!";
}
template <class T>
Matrix<T> Matrix<T>::operator / (const T h) {
    Matrix<T> result(rows, columns);
    if (h == T(0))
    {
        std::cout << "invalid syntax, division by zero is not possible";
    }
    else
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] / h;
    }
    return result;
    
}
template <class T>
void Matrix<T>::EnterMatrix() {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    std::cout << "Enter the dimension of the matrix:" << endl;
    std::cout << "Number of rows: ";
    int newRows;
    cin >> newRows;
    std::cout << "Number of columns: ";
    int newColumns;
    cin >> newColumns;

    Matrix<T> newMatrix(newRows, newColumns);
    for (int i = 0; i < newRows; i++)
        for (int j = 0; j < newColumns; j++) {
            std::cout << "Cell (" << i << ", " << j << ") = ";
            std::cin >> newMatrix.matrix[i][j];
        }

    rows = newRows;
    columns = newColumns;
    matrix = new T * [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new T[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = newMatrix.matrix[i][j];
}


template <class T>
Matrix<T> Matrix<T>::operator * (const T h) {
    Matrix<T> result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] * h;
    return result;
}
template <class T>
Matrix<T> operator / (double h, Matrix<T> matrix) {
    Matrix<T> result(matrix.GetRows(), matrix.GetCols());
    if (h == T(0))
    {
        std::cout << "invalid syntax, division by zero is not possible";
    }
    else
    {
        result = matrix / h;
        return result;
    }
}

template <class T>
bool Matrix<T>::operator == (const Matrix<T>& rhs) {
    bool result = true;
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (matrix[i][j] != rhs.matrix[i][j])
                    //if (abs(matrix[i][j] - rhs.matrix[i][j])>epsilon)
                {
                    result = false;
                }
    }
    else
    {
        result = false;
    }
    return result;

}

template <class T>
bool Matrix<T>::operator != (const Matrix<T>& rhs) {
    bool result = false;
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (matrix[i][j] != rhs.matrix[i][j])
                {
                    result = true;
                }
    }
    else
    {
        result = true;
    }
    return result;

}


template <class T>
void Matrix<T>::CreateMatrixForCheck() {
    T* a = new T[3];
    T* b = new T[3];
    T* c = new T[3];

    std::cout << "Enter a vector a" << endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "a(" << i << ") = ";
        cin >> a[i];
        //    a[i] = Check_Double();
    }
    std::cout << "Enter a vector b" << endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "b(" << i << ") = ";
        cin >> b[i];
    }
    std::cout << "Enter a vector c" << endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "c(" << i << ") = ";
        cin >> c[i];
    }
    Matrix newMatrix(3, 3);
    std::cout << "Enter a vector a" << endl;
    for (int i = 0; i < 3; i++)
    {
        newMatrix.matrix[0][i] = a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        newMatrix.matrix[2][i] = b[i];
    }
    for (int i = 0; i < 3; i++)
    {
        newMatrix.matrix[2][i] = c[i];
    }
    rows = 3;
    columns = 3;
    matrix = new T * [3];
    for (int i = 0; i < 3; i++)
        matrix[i] = new T[3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = newMatrix.matrix[i][j];
}
template <class T>
void Matrix<T>::CheckTheDeterminant() {
    T d = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0]
        + matrix[1][0] * matrix[2][1] * matrix[0][2] - matrix[2][0] * matrix[1][1] * matrix[0][2] -
        matrix[2][1] * matrix[1][2] * matrix[0][0] - matrix[1][0] * matrix[0][1] * matrix[2][2];
    T a = 0;
    if (d == a)
    {
        std::cout << "the determinant of the matrix = 0, the vectors are coplanar" << endl;
    }
    else
    {
        std::cout << "the vectors are non-planar, since the determinant of the matrix is" << d << endl;
    }
}

template <>
void Matrix<complex<double>>::Random()
{
    srand(time(0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            complex<double> value(((1 + rand() % 100) / 10.0), ((1 + rand() % 100) / 10.0));
            matrix[i][j] = value;
        }
    }
}


template <>
void Matrix<complex<float>>::Random()
{

    srand(time(0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            complex<float> value(((1 + rand() % 100) / 10.0), ((1 + rand() % 100) / 10.0));
            matrix[i][j] = value;
        }
    }
}

/*
template <class T>
Matrix<T>::~Matrix()
{
    if (rows > 0)
    {
        for (int i = 0; i < columns; i++)
            delete[] matrix[i];
    }

    if (rows > 0)
        delete[] matrix;
}
*/
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<complex<float>>;
template class Matrix<complex<double>>;