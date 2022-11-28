#include <iostream>
#include <vector>


using namespace std;

int64_t sqr(int64_t x)
{
    return x * x;
}

void odrediNizKvadrata(vector<int64_t>& br, vector<int64_t>& kvadrati);
void ispisi(const vector<int64_t>& v);

int main()
{
    int n;
    cin >> n;

    vector<int64_t> br(n);

    for (int i = 0; i < n; i++)
    {
        cin >> br[i];
    }
    
    vector<int64_t> kvadrati(n);
    
    odrediNizKvadrata(br, kvadrati);
    ispisi(kvadrati);

    return 0;
}

void ispisi(const vector<int64_t>& v)
{
    for (auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

void odrediNizKvadrata(vector<int64_t>& br, vector<int64_t>& kvadrati)
{
    int n = br.size();
    int l = 0, d = n - 1, k = n - 1;
    
    while (k >= 0)
    {
        kvadrati[k--] = (abs(br[l]) > abs(br[d]))? sqr(br[l++]) : sqr(br[d--]);   
    }
}