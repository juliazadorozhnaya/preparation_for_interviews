#include<iostream>

struct Students {
    char name[100];
    char surname[100];
    int inform;
    int math;
    int rus;
    int sum;
};

void merge(Students* left, size_t size_l, Students* right, size_t size_r, Students* result) {
    size_t i = 0;
    size_t j = 0;
    for (size_t k = 0; k < size_l + size_r; k++) {
        if (i >= size_l) {
            result[k] = right[j];
            j++;
        }
        else if (j >= size_r) {
            result[k] = left[i];
            i++;
        }
        else {
            if (left[i].sum >= right[j].sum) {
                result[k] = left[i];
                i++;
            }
            else {
                result[k] = right[j];
                j++;
            }
        }
    }
}


void MergeSort(Students* student, size_t left, size_t right) {
    if (right - left <= 1) {
        return;
    }
    size_t mid = (right + left) / 2;

    MergeSort(student, left, mid);
    MergeSort(student, mid, right);

    Students* result = new Students[right - left];
    merge(student + left, (mid - left), (student + mid), (right - mid), result);

    for (size_t i = left; i < right; i++) {
        student[i] = result[i - left];
    }
    delete[] result;
}

int main() {
    int size;
    std::cin >> size;
    Students* student = new Students[size];

    for (int i = 0; i < size; i++) {
        std::cin >> student[i].surname >> student[i].name >> student[i].inform >> student[i].math >> student[i].rus;
        student[i].sum = student[i].inform + student[i].math + student[i].rus;
    }

    MergeSort(student, 0, size);
    for (int i = 0; i < size; i++) {
        std::cout << student[i].surname << " " << student[i].name << std::endl;
    }
    
    delete[] student;
    return 0;
}
