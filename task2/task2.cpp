#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string pathToFile1, pathToFile2;
    float x, y;
    unsigned int R;

    cout << "введите путь к файлу с координатами центра окружности и ее радиусом: ";
    cin >> pathToFile1;
    cout << "введите путь к файлу с координатами точек: ";
    cin >> pathToFile2;

    ifstream f1(pathToFile1);
    if (f1.is_open())
    {
        f1 >> x;
        f1 >> y;
        f1 >> R;
    }
    else
    {
        cout << "Файл1 не удалось открыть";
        exit(0);
    }
    f1.close();

    ifstream f2(pathToFile2);
    if (f2.is_open())
    {
        while (!f2.eof())
        {
            float X, Y;
            f2 >> X;
            f2 >> Y;
            if ((X - x) * (X - x) + (Y - y) * (Y - y) < R * R) {cout << 1 << endl;}
            else if ((X - x) * (X - x) + (Y - y) * (Y - y) > R * R) {cout << 2 << endl;}
            else {cout << 0 << endl;}
        }
    }
    else
    {
        cout << "Файл2 не удалось открыть";
        exit(0);
    }
    f2.close();

    return 0;
}
