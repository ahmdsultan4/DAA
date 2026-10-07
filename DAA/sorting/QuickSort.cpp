#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort_helper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

void quick_sort(vector<int>& arr) {
    if (!arr.empty()) {
        quick_sort_helper(arr, 0, arr.size() - 1);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    
    vector<int> arr(size);
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    quick_sort(arr);
    
    cout << "Sorted array using Quick Sort:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
    
    return 0;
}