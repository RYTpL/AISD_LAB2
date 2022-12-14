#include <iostream>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;

template <class T>
class Matrix
{
private:
	T** data;
	int m, n;

public:
	Matrix();
	Matrix(int m, int n);
	Matrix(int m, int n, const T& value);
	Matrix(const Matrix& Matrix);
	void Set_m(int m = 1);
	void Set_n(int n = 1);
	int Get_m();
	int Get_n();
	void Set_Data(const T& value);
	T Get_Data(int i, int j) const;
	void Print(const int& Number_Matrix);
	Matrix& operator = (const Matrix& M);
	~Matrix();
	T& operator () (int m, int n) const;
	Matrix& operator () (int m, int n, const T& value);
	Matrix operator + (const Matrix& New_Matrix);
	Matrix operator - (const Matrix& New_Matrix);
	Matrix operator * (const Matrix& New_Matrix);
	Matrix operator * (const T& scalar);

	friend Matrix operator * (const T& scalar, Matrix& Matrix)
	{
		return Matrix * scalar;
	}

	Matrix operator / (const T& scalar);
	T �alculating_trace_matrix();
	void Random();
	T NDeterminant();
	friend ostream& operator << (ostream& os, const Matrix& New_Matrix)
	{
		for (int i = 0; i < New_Matrix.m; i++) {
			for (int j = 0; j < New_Matrix.n; j++) {
				os << setw(10) << New_Matrix.Get_Data(i, j);
			}
			cout << endl;
		}
		return os;
	}

};

