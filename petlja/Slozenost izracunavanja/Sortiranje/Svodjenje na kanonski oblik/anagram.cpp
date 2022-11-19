#include <iostream>
#include <vector>
#include <cctype>

/* Moze da se uradi sortiranjem sto daje slozenost O(nlogn), gde je n duzina 
stringa, ali ovde je problem resen prebrojavanjem slova (ukoliko dva stringa 
imaju isti broj svakog od slova to znaci da se njihovim preuredjivanjem mogu
dobiti dva jednaka stringa). Slozenost ovog resenja je O(n), ali je jako blizu
slozenosti resenja sa sortiranjem, jer imamo vise linearnih prolazaka kroz stringove */

using namespace std;

static int brSlovaAbecede = 26;

void prebrojKaraktere(vector<int>& brSlova, string s);
bool anagrami(vector<int>& brSlova1, vector<int>& brSlova2);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);    

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> brSlova1;
    vector<int> brSlova2;
    
    prebrojKaraktere(brSlova1, s1);
    prebrojKaraktere(brSlova2, s2);

    cout << (anagrami(brSlova1, brSlova2)? "da" : "ne") << endl; 

    return 0;
}

void prebrojKaraktere(vector<int>& brSlova, string s)
{
    brSlova = vector<int>(brSlovaAbecede, 0);

    for (int i = 0; s[i]; i++)
    {
        if (isalpha(s[i]))
        {
            // zanemarujemo da li su slova velika ili mala
            brSlova[tolower(s[i]) - 'a']++;
        }
    }
}

bool anagrami(vector<int>& brSlova1, vector<int>& brSlova2)
{
    for (int i = 0; i < brSlovaAbecede; i++)
    {
        if (brSlova1[i] != brSlova2[i])
        {
            return false;
        }
    }

    return true;
}