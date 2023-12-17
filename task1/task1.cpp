#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int m, n;
    int index = 0;
    
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = i + 1;
    }

    cout << "Введите размер интервала: ";
    cin >> m;

    do
    {
        cout << arr[index];
        index = (index + (m - 1))%n;
    } 
    while (index != 0);

    delete [] arr;
    return 0;
} 

