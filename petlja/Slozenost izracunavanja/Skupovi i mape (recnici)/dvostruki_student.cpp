#include <iostream>
#include <set>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string student;
    set<string> vidjeni;
    string rez;
    while (getline(cin, student))
    {
        if (vidjeni.find(student) != vidjeni.end())
        {
            rez = student;
        }
        vidjeni.insert(student);
    }

    // ne mora da se ispisuje novi red jer ga je
    // getline uhvatio i upisao u string student
    cout << rez;

    return 0;
}