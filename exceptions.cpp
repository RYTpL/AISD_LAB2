#include "exceptions.h"
#include "matrix.h"
#include <iostream>
using namespace std;


Exception::Exception() {}

Invalid_Index::Invalid_Index() {}

void Invalid_Index::print() const {
	cout << "��������� ������: ������ �� ������" << endl;
}


Empty::Empty() {}

void Empty::print() const
{
	cout << "��������� ������: � ������� ��� ���������" << endl;
}

Different_Dimensions::Different_Dimensions() {}

void Different_Dimensions::print() const
{
	cout << "��������� ������: ����������� ������ �� ���������" << endl;
}

Divizion_By_Zero::Divizion_By_Zero() {}

void Divizion_By_Zero::print() const
{
	cout << "��������� ������: ������� ������� �� ����" << endl;
}

Zero_Determinant::Zero_Determinant() {}

void Zero_Determinant::print() const
{
	cout << "��������� ������: ������� ������� �� ������� ������������" << endl;
}

Dimensions_Incorrect::Dimensions_Incorrect() {}

void Dimensions_Incorrect::print() const
{
	cout << "��������� ������: ������� ������ ���� ����������" << endl;
}