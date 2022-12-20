#include <iostream>
#include <deque>


using namespace std;

int main()
{
    int n;
    cin >> n;

    deque<int> sortiranNiz;

    for (int i = 0; i < n; i++)
    {
        int br;
        cin >> br;

        if (!sortiranNiz.empty() && br < sortiranNiz.back())
        {
            sortiranNiz.push_front(br);
        }
        else
        {
            sortiranNiz.push_back(br);
        }
    }
    
    for (auto it : sortiranNiz)
    {
        cout << it << ' ';
    }
    cout << endl;

    return 0;
}