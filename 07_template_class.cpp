
#include "Matrix.h"







int main()
{
    Matrix<> mas(3);
    Matrix<double> d_mas(3.25);
    Matrix<string> s_mas("Hi");
    cout << mas;
    cout << d_mas;
    cout << s_mas;
    Matrix<> res = mas + 3;
    cout << res;
    cout << res(1,2) << endl;
    cout << res.indexesOf(6)[0]<< " " << res.indexesOf(6)[1] << endl;
}

