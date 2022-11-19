#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;

    int x1, y1, z1, x2, y2, z2;
    vector<int64_t> duzine(n);

    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        // nema potrebe racunati koren, jer nam ne trebaju tacne duzine, samo broj razlicitih
        duzine[i] = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2);
    }
    
    sort(begin(duzine), end(duzine));
    auto it = unique(begin(duzine), end(duzine));

    cout << it - begin(duzine) << endl;

    return 0;
}