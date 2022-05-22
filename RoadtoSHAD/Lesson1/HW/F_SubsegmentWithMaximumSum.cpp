#include <iostream>
#include <vector>
using namespace std;

vector<int64_t> v(1E4 + 1);

int64_t MaxSubsegmentSum(int64_t begin, int64_t end){
    int64_t max_sum = v[begin] - v[begin - 1]; 
    int64_t l = begin - 1;
    for (int r = begin; r < end; r++){
        max_sum = max(max_sum, v[r] - v[l]);

        if (v[r] < v[l]){
            l = r;
        }
    }
    return max_sum;
}

int main(){
    int64_t n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i - 1];

    }

    int64_t k;
    cin >> k;
    for (int i = 0; i < k; ++i){
        int64_t l, r;
        cin >> l >> r;
        cout << MaxSubsegmentSum(l + 1, r + 1) << '\n';
    }
    return 0;
}   