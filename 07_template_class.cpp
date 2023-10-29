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
    Matrix<string> s_res = s_mas + " Jo";
    Matrix<double> d_res  = d_mas + 0.21;
    cout << res;
    cout << d_res;
    cout << s_res;
    mas += 1;
    d_mas += 0.05;
    s_mas += "o";
    cout << mas;
    cout << d_mas;
    cout << s_mas;
    cout << res(1,2) << endl;
    res(2, 3) = 2;
    cout << res;
    cout << "Indexes: " << res.indexesOf(2)[0] << " " << res.indexesOf(2)[1] << endl;
    cout << res.min() << endl;
    cout << d_res.sum() << endl;
    s_mas(2,2) = "Hello";
    cout << s_mas;
    cout << boolalpha << s_mas.find("Hello") << endl;
    cout << "Indexes: " << s_mas.indexesOf("Hello")[0] << " " << s_mas.indexesOf("Hello")[1] << endl;
    cout << boolalpha << res.find(2) << endl;
    cout << boolalpha << (s_res == s_mas) << endl;
    cout << boolalpha << (s_res != s_mas) << endl;
}

