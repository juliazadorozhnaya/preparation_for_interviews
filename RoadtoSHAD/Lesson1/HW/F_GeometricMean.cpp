#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    vector<double> v(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        v[i] = log(v[i]);
        v[i] += v[i - 1];
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << setprecision(12) << exp((v[r + 1] - v[l]) / (r - l + 1)) << '\n';
    }
}