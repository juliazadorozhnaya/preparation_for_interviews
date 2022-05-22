#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::deque;

int main() {
    int n, bufferSize;
    cin >> n >> bufferSize;

    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    deque<int> d;
    int localMin[n - bufferSize + 1];
    int ind = 0;

    for (int i = 0; i < bufferSize - 1; i++) {
        while (!d.empty() && nums[d[d.size() - 1]] >= nums[i]) {
            d.pop_back();
        }

        d.push_back(i);
    }

    for (int i = bufferSize - 1; i < n; i++) {
        if (!d.empty() && (d[0] <= i - bufferSize)) {
            d.pop_front();
        }
        while (!d.empty() && nums[d[d.size() - 1]] >= nums[i]) {
            d.pop_back();
        }

        d.push_back(i);

        localMin[ind] = nums[d[0]];
        ind++;
    }

    for (int i = 0; i < n - bufferSize + 1; i++) {
        cout << localMin[i] << "\n";
    }
    cout << "\n";
    return 0;
}