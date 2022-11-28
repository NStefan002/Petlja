#include <iostream>
#include <vector>


using namespace std;

void objedini(vector<int>& rez, vector<int>& A, vector<int>& b);
void ispisi(const vector<int>& v);

int main()
{
    int m;
    cin >> m;

    vector<int> grupaA(m);
    for (int i = 0; i < m; i++)
    {
        cin >> grupaA[i];
    }
    
    int n;
    cin >> n;

    vector<int> grupaB(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grupaB[i];
    }
    
    vector<int> rez(n + m);
    objedini(rez, grupaA, grupaB);
    ispisi(rez);

    return 0;
}

void ispisi(const vector<int>& v)
{
    for (auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void objedini(vector<int>& rez, vector<int>& A, vector<int>& B)
{
    int m = A.size(), n = B.size();
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        rez[k++] = (A[i] <= B[j])? A[i++] : B[j++];
    }

    while (i < m)
    {
        rez[k++] = A[i++];
    }

    while (j < n)
    {
        rez[k++] = B[j++];   
    }
}