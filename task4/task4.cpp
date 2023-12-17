#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    string pathToFile;
    vector<int> v;
    int result = 0;

    cout << "введите путь к файлу:" << endl;
    cin >> pathToFile;

    ifstream file(pathToFile);
    if (file.is_open())
    {
        while (!file.eof())
        {
            int i;
            file >> i;
            v.push_back(i);
        }
    }
    else
    {
        cout << "Файл не удалось открыть";
        exit(0);
    }
    file.close();

    sort(begin(v), end(v));
    
    for (auto element : v)
    {
        result = result + abs(element - v[v.size() / 2]);
    }

    cout << result;

    return 0;
}
