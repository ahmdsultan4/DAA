#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    
    insertion_sort(arr);
    
    cout << "Sorted array using Insertion Sort:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
    
    return 0;
}