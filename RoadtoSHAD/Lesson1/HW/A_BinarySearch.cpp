#include <vector>
#include <iostream>

/*
bool BinarySearch(const std::vector<int>& array, int target) {
    int left = 0;
    int right = array.size() - 1;
    while (right - left >= 0) {
        int mid = left + (right + left) / 2;
        if (array[mid] == target) {
            return true;
        }
        if (array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5};
    std::cout << BinarySearch(array, 1);
    //range-based for
    /*for (int& elem:array) {
        std::cin >> elem;
    }
    std::unordered_map<int, int> map;
     
}


3 3
2 3 5
1 2 3
*/

#include<iostream>


bool Binary_Search(int, int, int, int*);

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k, num;

    std::cin >> n >> k;
    int* mas = new int[n];

    //first string
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }

    
    for (int i = 0; i < k; i++) {
        std::cin >> num;
        if (num > mas[n - 1] || num < mas[0]) {
            std::cout << "NO\n";
        } else if (num > mas[n / 2]) {
            if (Binary_Search(n / 2, n, num, mas)) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else if (Binary_Search(0, n / 2, num, mas)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    delete[] mas;
    return 0;
}

bool Binary_Search(int left, int right, int num, int* mas) {
    while (left <= right) {
        int mid_one = (left * 2 + right) / 3;
        int mid_two = (left + right * 2) / 3;

        if (num < mas[mid_one]) {
            right = mid_one - 1;
        }
        else if (num > mas[mid_one] && num < mas[mid_two]) {
            left = mid_one + 1;
            right = mid_two - 1;
        } else if (num > mas[mid_two]) {
            left = mid_two + 1;
        } else if (num == mas[mid_one] || num == mas[mid_two]) {
            return true;
        }
    }
    return false;
}