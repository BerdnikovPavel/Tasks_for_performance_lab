#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    float x, y;
    unsigned int R;

    if (argc < 3)
    {
        cout << "Вы должны указать имена файлов";
        exit(1);
    }

    ifstream f1(argv[1]);
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

    ifstream f2(argv[2]);
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
