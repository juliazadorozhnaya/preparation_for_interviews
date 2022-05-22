#include <iostream>
#include <vector>
using namespace std;


int main(){
    int64_t n;
    cin >> n;
    vector<int64_t> v(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int64_t k;
    cin >> k;
    
    for (int i = 0; i < k; ++i){
        int64_t l, r;
        cin >> l >> r;
        cout << v[r] - v[l - 1] << ' ';
    }
    return 0;
}

