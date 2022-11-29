#include <iostream>
#include <map>


using namespace std;

int main()
{
    int n;
    cin >> n;

    map<unsigned, unsigned> ipAdrese;
    unsigned ip;
    for (int i = 0; i < n; i++)
    {
        cin >> ip;
        ipAdrese[ip]++;
    }
    
    cout << ipAdrese.size() << endl;

    return 0;
}