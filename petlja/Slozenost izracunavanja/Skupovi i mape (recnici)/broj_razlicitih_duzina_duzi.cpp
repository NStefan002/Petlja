#include <iostream>
#include <set>


using namespace std;

int main()
{
    int n;
    cin >> n;

    int x1, y1, z1, x2, y2, z2;

    set<int> razliciteDuzi;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        // nema potrebe racunati koren, jer nam ne trebaju tacne duzine, samo broj razlicitih
        int64_t duz = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2);
        razliciteDuzi.insert(duz);
    }
    
    cout << razliciteDuzi.size() << endl;
    return 0;
}