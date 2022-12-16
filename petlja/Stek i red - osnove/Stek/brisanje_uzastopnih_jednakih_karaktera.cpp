#include <iostream>


using namespace std;

int main()
{
    string ulaznaNiska, izlaznaNiska = "";
    cin >> ulaznaNiska;

    // ne treba nam stek, vec ideje koje on koristi
    // (koristimo string jer vec ima neke metode slicne steku
    // a lakse ga je ispisati)
    for (char c : ulaznaNiska)
    {
        if (c != izlaznaNiska.back())
        {
            izlaznaNiska.push_back(c);
        }
        else
        {
            izlaznaNiska.pop_back();
        }
    }

    cout << izlaznaNiska << endl;    

    return 0;
}