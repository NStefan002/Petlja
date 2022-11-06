#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> visine(n);

    for (int i = 0; i < n; i++)
    {
        cin >> visine[i];
    }
    
    vector<int> potrebneVisine(n);
    potrebneVisine[n - 1] = visine[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        potrebneVisine[i] = max(potrebneVisine[i + 1], visine[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << potrebneVisine[i] << '\n';
    }
    

    return 0;
}