#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Student
{
    string ime;
    string prezime;

    bool operator<(Student s)
    {
        if (ime < s.ime)
        {
            return true;
        }
        else if (ime > s.ime)
        {
            return false;
        }
        else if (prezime < s.prezime)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    vector<Student> spisak;   

    string ime, prezime;
    while (cin >> ime >> prezime)
    {
        spisak.push_back({ime, prezime});
    }

    sort(begin(spisak), end(spisak));

    for (int i = 1; i < spisak.size(); i++)
    {
        if (spisak[i].ime == spisak[i - 1].ime && spisak[i].prezime == spisak[i - 1].prezime)
        {
            cout << spisak[i].ime << ' ' << spisak[i].prezime << endl;
            break;
        }
        
    }
    
    return 0;
}