#include <iostream>
#include <vector>
#include <algorithm>


int quantity_of_segments(std::vector<int64_t> *points, int l) {
    int count = 0;
    int64_t right = (*points)[0] - 1;

    for (int i = 0; i < points->size(); ++i) {
        if ((*points)[i] > right) {
            ++count;
            right = (*points)[i] + l;
        }
    }

    return count;
}

int main(void) {
    int n, k, l;
    std::vector<int64_t> points;

    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int64_t tmp;
        std::cin >> tmp;
        points.push_back(tmp);
    }
    std::sort(points.begin(), points.end());

    int64_t left = 0;
    int64_t right = points[points.size() - 1] - points[0];
    while (left < right) {
        l = (left + right) / 2;
        if (quantity_of_segments(&points, l) <= k)
            right = l;
        else
            left = l + 1;
    }

    std::cout << left << std::endl;

    return 0;
}