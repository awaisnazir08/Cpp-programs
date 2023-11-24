#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// A utility function to print an array
void print(string* str, int n)
{
    for (int i = 0; i < n; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}

// A utility function to get the ASCII value
// of the character at index d in a string
int char_at(string str, int d)
{
    if (str.size() <= d)
        return -1;
    else
        return str.at(d);
}

// The main function to sort array using
// MSD Radix Sort recursively
void MSD_sort(string* str, int lo, int hi, int d)
{

    // recursion break condition
    if (hi <= lo) {
        return;
    }

    vector<int> count(256 + 2, 0);

    // temp is created to easily swap strings in str[]
    unordered_map<int, string> temp;

    // Store occurrences of most significant character
    // from each string in count[]
    for (int i = lo; i <= hi; i++) {
        int c = char_at(str[i], d);
        count[c + 2]++;
    }

    // Change count[] so that count[] now contains actual
    // position of this digits in temp[]
    for (int r = 0; r < 256 + 1; r++)
        count[r + 1] += count[r];

    // Build the temp
    for (int i = lo; i <= hi; i++) {
        int c = char_at(str[i], d);
        temp[count[c + 1]++] = str[i];
    }

    // Copy all strings of temp to str[], so that str[] now
    // contains partially sorted strings
    for (int i = lo; i <= hi; i++)
        str[i] = temp[i - lo];

    // Recursively MSD_sort() on each partially sorted
    // strings set to sort them by their next character
    for (int r = 0; r < 256; r++)
        MSD_sort(str, lo + count[r], lo + count[r + 1] - 1,
                d + 1);
}

int main()
{
    string str[] = { "midnight", "badge", "bag",
                    "worker", "banner", "wander" };

    int n = sizeof(str) / sizeof(str[0]);

    cout << "Unsorted array : ";
    // print the unsorted array
    print(str, n);

    // Function call
    MSD_sort(str, 0, n - 1, 0);

    cout << "Sorted array : ";
    // print the sorted array
    print(str, n);

    return 0;
}
