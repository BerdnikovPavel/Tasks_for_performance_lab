#include <iostream>
#include <fstream>
#include "json.hpp"
#include <map>

using json = nlohmann::json;
using namespace std;

json detour(json& Doc, map<int, string> res)
{
    for (int i = 0; i < Doc.size(); ++i)
    {
        if (Doc[i].contains("value"))
        {
            Doc[i]["value"] = res[Doc[i]["id"]];
        }

        if (Doc[i].contains("values"))
        {
            detour(Doc[i]["values"], res);
        }
    }
    return Doc;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");

    if (argc < 3)
    {
        cout << "Вы должны указать имена файлов";
        exit(1);
    }

    json DataTests;
    json DataValues;
    map<int, string>results;

    ifstream tests(argv[1]);
    if(tests.is_open())
    {
        tests >> DataTests;
    }
    else
    {
        cout << "Файл tests.json не удалось открыть";
        exit(0);
    }
    tests.close();

    ifstream values(argv[2]);
    if (values.is_open())
    {
        values >> DataValues;
    }
    else
    {
        cout << "Файл values.json не удалось открыть";
        exit(0);
    }
    values.close();

    for (int i = 0; i < DataValues["values"].size(); ++i)
    {
        for (auto it = DataValues["values"][i].begin(); it != DataValues["values"][i].end(); ++it)
        {
            results[DataValues["values"][i]["id"]] = DataValues["values"][i]["value"];
        }
    }

    detour(DataTests["tests"], results);

    ofstream report("report.json");
    report << setw(4) << DataTests << endl;

    return 0;
}
