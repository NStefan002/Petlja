#include <iostream>
#include <deque>


using namespace std;

int main()
{
    string operacije;
    cin >> operacije;

    /* igrac koji nosi sesir se nalazi na poslednjem mestu
    u redu (jer se novi igrac dodaje iza njega) */
    deque<int> kolo;

    for (char op : operacije)
    {
        if (op == 'u')
        {
            kolo.push_back(kolo.size() + 1);
        }
        else if (op == 's')
        {
            // naredni (tj. prvi) element dodajemo na kraj reda 
            // (postavljamo ga za nosioca sesira)
            kolo.push_back(kolo.front());
            kolo.pop_front();
        }
        else // if (op == 'i')
        {
            // izbacujemo igraca koji nosi sesir
            kolo.pop_back();
        }
    }
    
    // prvo ispisujemo onoga koji nosi sesir
    cout << kolo.back() << ' ';
    kolo.pop_back();

    // ostale ispisujemo redom od pocetka (nakon igraca koji nosi sesir)
    while (!kolo.empty())
    {
        cout << kolo.front() << ' ';
        kolo.pop_front();
    }

    cout << endl;
    return 0;
}