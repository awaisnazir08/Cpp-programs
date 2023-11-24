#include <iostream>
#include <vector>

using namespace std;

int find_max(string arr[], int size) {
    int max_len = arr[0].length();
    for (int i = 0; i < size; i++) {
        if (arr[i].length() > max_len) {
            max_len = arr[i].length();
        }
    }
    return max_len;
}

void countingSort(string arr[], int size, int pos) {
    const int RANGE = 27;
    int count[RANGE] = {0};
    string *result = new string[size];

    for (int i = 0; i < size; i++) {
        if ((arr[i].length() - pos) < 0) {
            count[0]++;
        } else {
            count[arr[i][arr[i].length() - pos] - 'a' + 1]++;
        }
    }

    for (int i = 1; i < RANGE; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        if ((arr[i].length() - pos) < 0) {
            result[--count[0]] = arr[i];
        } else {
            result[--count[arr[i][arr[i].length() - pos] - 'a' + 1]] = arr[i];
        }
    }

    copy(result, result + size, arr);
    delete[] result;
}

void radixSort(string arr[], int size) {
    int max_len = find_max(arr, size);
    for (int pos = 1; pos <= max_len; pos++) {
        countingSort(arr, size, pos);
    }
}

int main() {
    string arr[] = {"midnight", "badge", "bag",
                    "worker", "banner", "wander"};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
