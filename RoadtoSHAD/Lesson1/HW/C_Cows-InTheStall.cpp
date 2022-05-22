#include <iostream>
#include <vector>


using namespace std;
int main() {
    vector<int> arr;
    int n = 0, k = 0, left = 0, right = 0, en = 0, j = 0, mid = 0;

    cin >> n;
    cin >> k;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        arr.push_back(c);
    }

    left = 0;
    right = arr.back() - arr.front() + 1;
    while (right-left > 1) {
        mid = (left + right) / 2;
        en = 1;
        j = arr.front();
        for(int i : arr){
            if (i - j >= mid) {
                j = i;
                en++;
            }
        }
        if (en >= k){
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left<< endl;
    return 0;
}