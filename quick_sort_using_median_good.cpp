#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int medianOfThree(std::vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    
    if (arr[low] > arr[mid]) {
        std::swap(arr[low], arr[mid]);
    }
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[high]) {
        std::swap(arr[mid], arr[high]);
    }

    // Place the median at the beginning (leftmost) position
    std::swap(arr[mid], arr[low]);
    
    return arr[low];
}

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = medianOfThree(arr, left, right);
    
    int lb = left;
    while (left < right) {
        while (arr[left] <= pivot) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }
        if (left < right) {
            std::swap(arr[left], arr[right]);
        }
    }
    std::swap(arr[lb], arr[right]);
    return right;
}

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int location = partition(arr, left, right);
        quickSort(arr, left, location - 1);
        quickSort(arr, location + 1, right);
    }
}

int main() {
    std::vector<int> arr = {9, 7, 5, 11, 1, 6, 1, -2, 5, -9, 453, 12, 2, 14, 3, 10, 6};
    int n = arr.size();

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
