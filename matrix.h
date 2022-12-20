#pragma once
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
using namespace std;

template <class T>
class Matrix
{
private:
	int rows, columns;
	T** matrix;

public:
	T epsilon;
	Matrix();
	Matrix(int rows, int columns);
	void EnterMatrix();
	T& operator () (int i, int j);

	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator * (const Matrix& rhs);
	Matrix operator * (const T h);
	Matrix operator / (const T h);
	bool operator == (const Matrix& rhs);
	friend std::ostream& operator << (std::ostream& s, const Matrix& matrix)
	{
		for (int i = 0; i < matrix.rows; i++) {
			for (int j = 0; j < matrix.columns; j++)
				s << matrix.matrix[i][j] << " ";
			s << "\n";
		}
		return s;
	}
	int GetRows() const;
	int GetCols() const;
	T tr();
	void CreateMatrixForCheck();
	void CheckTheDeterminant();
	void Random();
	~Matrix();
};