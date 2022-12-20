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
#include "matrix.h"
#include <complex>

template<class T>
T Check_Double()
{
    T number;

    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите корректное значение...\n";
    }


    return number;
}

int Check_Int()
{
    int number = 0;
    while (number <= 0)
    {
        while (!(cin >> number) || (cin.peek() != '\n'))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Введите корректное значение...\n";
        }
        if (number <= 0) cout << "Введите корректное значение...\n";

    }

    return number;
}

int get_key()
{
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key;
}

int menu1()
{
    std::cout << "\nMatrix Class.\n\n"
        "1 - View/edit the studied matrices.\n"
        "2 - Matrix Addition(+)\n"
        "3 - Matrix difference(-)\n"
        "4 - multiplication matrix(*)\n"
        "5 - Multiplying a matrix by a scalar\n"
        "6 - Dividing a matrix by a scalar\n"
        "7 - Calculating the trace of the matrix\n"
        "8 - Checking vectors for coplanarity\n"
        "9 - Matrix Comparison\n"
        "0 - Access to an element in matrix A by index.Var-3\n\n"
        "Exit: Esc";


    while (true)
    {
        int key = get_key();
        if ((key == 27) || (key >= '0' && key <= '9'))
            return key;
    }
}

int menu2()
{
    std::cout << "\n\n";
    std::cout << "Resume: Enter";
    while (true)
    {
        int key = get_key();
        if (key == 13) return key;
    }
}

int menu3()
{
    std::cout << "1 - Yes\n2 - No";
    while (true)
    {
        int key = get_key();
        if (key == '1' || key == '2') return key;
    }
}




template <class T>
std::ostream& operator << (std::ostream& s, const Matrix<T>& matrix);
template <class T>
int menu()
{
    Matrix<T> A(2, 2), B(2, 2), C(2, 2), D(2, 2);

    while (true) {
        system("cls");
        int m1 = menu1();
        switch (m1) {
        case 27: return 0;
        case 49: {
            system("cls");
            std::cout << "\tInvestigated matrices:\n\n";
            std::cout << "A:\n" << A << endl;
            std::cout << "B:\n" << B;

            std::cout << "\n\nDo you want to change the matrices?" << endl;
            int m3 = menu3();
            switch (m3) {
            case 49: {
                system("cls");
                std::cout << "\n--------Setting the matrix A--------" << endl;
                A.EnterMatrix();

                std::cout << "\n--------Setting the matrix B--------" << endl;
                B.EnterMatrix();

                break;
            }
            case 50: {
                break;
            }
            }

            break;
        }
        case 50: {
            system("cls");
            std::cout << "\tMatrix Addition.\n\n";
            bool check = 0;
            try {
                C = A + B;
                check = 1;
            }
            catch (const char* message) {
                std::cout << message;
            }

            if (check) {
                std::cout << "A + B:\n\n" << endl;
                std::cout << A << "\n +\n\n" << B << "\n = \n\n";
                std::cout << A + B;
            }

            break;
        }
        case 51: {
            system("cls");
            std::cout << "\tMatrix difference.\n\n";
            bool check = 0;
            try {
                C = A - B;
                check = 1;
            }
            catch (const char* message) {
                std::cout << message;
            }

            if (check) {
                C = A - B;
                std::cout << "A - B:\n\n" << endl;
                std::cout << A << "\n -\n\n" << B << "\n = \n\n";
                std::cout << C;
            }

            break;
        }
        case 52: {
            system("cls");
            std::cout << "\tmultiplication matrix.\n\n";
            bool check = 0;
            try {
                C = A * B;
                check = 1;
            }
            catch (const char* message) {
                std::cout << message;
            }

            if (check) {
                C = A * B;
                std::cout << "A * B:\n\n" << endl;
                std::cout << A << "\n *\n\n" << B << "\n = \n\n";
                std::cout << C;
            }

            break;
        }
        case 53: {
            system("cls");
            std::cout << "\tMultiplying a matrix by a scalar.\n\n";
            T a;
            std::cout << "Enter a value (scalar): ";
            //a = double_checker();
            a = Check_Double<T>();
            std::cout << "A * a:\n\n" << endl;
            std::cout << A << "\n *\n\n " << a << "\n\n = \n\n";
            C = A * a;
            std::cout << C;
            std::cout << D;
            break;
        }
        case 54: {
            system("cls");
            std::cout << "\tDividing a matrix by a scalar.\n\n";
            T a;
            std::cout << "Enter a value (scalar): ";
            //a = zero_checker();
            a = Check_Double<T>();
            std::cout << "A \ a:\n\n" << endl;
            std::cout << A << "\n /\n\n " << a << "\n\n = \n\n";
            C = A / a;
            std::cout << C;

            break;
        }
        case 55: {
            system("cls");
            std::cout << "\tCalculating the trace of the matrix.\n\n";
            std::cout << "Tr(A) = " << A.tr();
            break;
        }
               /*case 56: {
                   system("cls");
                   std::cout << "Checking vectors for coplanarity." << endl;
                   Matrix<T> test;
                   test.CreateMatrixForCheck();
                   test.CheckTheDeterminant();
                   break;
               }*/
        case 58:
        {
            system("cls");
            std::cout << "Access to an element in matrix A by index." << endl;
            std::cout << "enter the row: ";
            int x = Check_Int();
            std::cout << "\nenter the column: ";
            int y = Check_Int();
            std::cout << "\nthe value of the element: " << A(x, y);
            std::cout << "\nDo you want to change ellement?\n";
            int m3 = menu3();
            switch (m3) {
            case 49: {
                system("cls");
                cout << "Enter the value: ";
                A(x, y) = Check_Double<T>();
                break;
            }
            case 50: {
                break;
            }
                   break;
            }
        }
        case 57:
        {
            system("cls");
            std::cout << "Matrix Comparison.\n Enter epsilon: " << endl;
            std::cin >> A.epsilon;
            if (A == B)
            {
                std::cout << "A == B\n";
            }
            else
            {
                std::cout << "A!=B\n";
            }
        }
        }
        while (true)
        {
            int m2 = menu2();
            if (m2 == 13) break;
        }
    }

}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");
    system("cls");
    bool exit = true;
    while (exit) {
        system("cls");
        cout << "Здравствуйте! Вас приветствует программа \"МНОГО МАТРИЦ\"\n" << endl;
        cout << "Нажмите:" << endl;
        cout << "1 - чтобы работать с типом int" << endl;
        cout << "2 - чтобы работать с типом double" << endl;
        cout << "3 - чтобы работать с типом float" << endl;
        cout << "4 - чтобы работать с типом complex-double" << endl;
        cout << "5 - чтобы работать с типом complex-float" << endl;
        cout << "0 - чтобы завершить работу" << endl;

        int key = get_key();

        switch (key)
        {
        case 49:
            menu<int>();
            break;
        case 50:
            menu<double>();
            break;
        case 51:
            menu<float>();
            break;
        case 52:
            menu<complex<double>>();
            break;
        case 53:
            menu<complex<float>>();
            break;
        case 48:
            exit = false;
            break;
        default:
            break;
        }

    }

    return 0;
}
