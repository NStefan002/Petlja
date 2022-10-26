#include <iostream>
#include <vector>

using namespace std;

void dvobojka(vector<int>& v);
void swap(vector<int>& v, int i, int j);
void ispisi(vector<int>& v);

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    dvobojka(v);
    ispisi(v);

    return 0;
}

void swap(vector<int>& v, int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void dvobojka(vector<int>& v)
{
    // p p p p ? ? ? ? n n n n
    int l = 0, d = v.size(), i = 0;
    while (l < d)
    {
        if (v[i] % 2 == 0)
        {
            swap(v, i++, l++);
        }
        else
        {
            swap(v, i, --d);
        }
    }
}

void ispisi(vector<int>& v)
{
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}