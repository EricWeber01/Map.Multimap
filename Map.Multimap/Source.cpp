#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct Dict
{
    void add()
    {
        string w, t;
        cout << ">>> ";
        cin >> w;
        vector<string> v;
        while (cin.peek() != '\n')
        {
            cin >> t;
            v.emplace_back(move(t));
        }
        dict[w] = v;
        cin.ignore();
    }
    void to_file()
    {
        ofstream o("dict.txt");
        info_all(o);
    }
    void to_display()
    {
        info_all(cout);
    }
private:
    void info_all(ostream& o)
    {
        for (const auto& [word, trans] : dict)
        {
            o << word << " \t- ";
            int i = 0;
            for (const auto& t : trans)
            {
                o << t;
                if (i < trans.size() - 1) o << ", ";
                else                   o << "\n";
                i++;
            }
        }
    }
    map<string, vector<string>> dict;
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Dict dict;
    dict.add();
    dict.add();
    dict.add();
    dict.to_display();
    dict.to_file();
}