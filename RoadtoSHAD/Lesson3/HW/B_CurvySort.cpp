#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int64_t>& nums) {   
    int n = nums.size();
    vector<int64_t> sorted(n);
        
    sort(nums.begin(), nums.end());
            
    int pos = 1;
        
    for (int i = n - 1; i > (n - 1) / 2; --i){
        sorted[pos] = nums[i];
        pos += 2;
    }
        
    pos = 0;
            
    for (int i = (n - 1) / 2; i >= 0; --i){
        sorted[pos] = nums[i];
        pos += 2;
    }
        
    nums = sorted;
}

int main(){
	int n;
	cin >> n;
    vector<int64_t> nums;
    for (int i = 0; i < n; i++){
        int64_t a;
        cin >> a;
        nums.push_back(a);
    }
    wiggleSort(nums);
    for (int i = 0; i < n; i++){
        cout << nums[i];
        if(i != (n-1))
            cout << " ";
    }
	return 0;
}