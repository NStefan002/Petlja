#include <iostream>
#include <vector>

using namespace std;

int brPodskupova(vector<int> &niz);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int broj;
    int ostatak_0 = 0, ostatak_1 = 0, ostatak_2 = 0;
    while (cin >> broj)
    {
        switch (broj % 3)
        {
        case 1:
            ostatak_1++;
            break;

        case 2:
            ostatak_2++;
            break;

        default: // case 0
            ostatak_0++;
            break;
        }
    }

    int rezultat = 0;

    // od n elemenata biramo 2 ili 3 elementa deljivih sa 0  [n nad 2 + n nad 3]
    rezultat += ostatak_0 * (ostatak_0 - 1) / 2 + ostatak_0 * (ostatak_0 - 1) * (ostatak_0 - 2) / 6;

    // od n elemenata biramo 3 elementa deljivih sa 1
    rezultat += ostatak_1 * (ostatak_1 - 1) * (ostatak_1 - 2) / 6;

    // od n elemenata biramo 3 elementa deljivih sa 2
    rezultat += ostatak_2 * (ostatak_2 - 1) * (ostatak_2 - 2) / 6;

    /* mozemo kombinovati jedan element sa ostatkom 2 i jedan sa ostatkom 1
    ili praviti trojke koje cine elementi sa ostatkom 0, 1 i 2 */
    rezultat += ostatak_1 * ostatak_2 + ostatak_1 * ostatak_2 * ostatak_0;

    cout << rezultat << endl;

    return 0;
}