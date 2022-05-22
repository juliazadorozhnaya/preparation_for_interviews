#include <iostream>
#include <vector>
#include <unordered_map>


/*
std::vector<int> GetPrefixSums(const std::vector<int>& array) {
    std::vector<int> pref_sums(array.size() + 1, 0);
    for (int i = 1; i < pref_sums.size(); ++i) {
        pref_sums[i] = pref_sums[i - 1] + array[i - 1];
    }
    return pref_sums;
}

/*
Calculate sum on [l,r], 1 <= l <= r <= n

 10
 1 2 3 4 5 6 7 8 9 0
 3
 1 1
 1 10
 5 7


int GetQuery(const std::vector<int>& pref_sums, int l, int r) {
    return pref_sums[r] - pref_sums[l - 1];
}

int main() {
    int array_size;
    std::cin >> array_size;
    std::vector<int> array(array_size, 0);
    for (int pos = 0; pos < array_size; ++pos) {
        std::cin >> array[pos];
        //array[pos] = std::log10(array[pos]);
    }

    std::vector<int> pref_sums = GetPrefixSums(array);
    int query_numbers;
    std::cin >> query_numbers;
    int left;
    int right;
    for (int i = 0; i  < query_numbers; i++) {
        std::cin >> left >> right;
        std::cout << GetQuery(pref_sums, left, right) << std::endl;
        //std::pow(10, GetQuery(pref_sums, left, right)) * (1 / right - left + 1))
    }

    //int answer = 0;
    /* for (int pref_sum : pref_sums) {
        /*if (array[pos] % 2 == 0) {
            answer += array[pos];
        }
        std::cout << pref_sum << ' ';
    }
}
// 6 = 1 + 2 + 3
*/

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
     */
}

