#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k <= right; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
}

void merge_sort_helper(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort_helper(arr, left, mid);
        merge_sort_helper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(vector<int>& arr) {
    if (!arr.empty()) {
        merge_sort_helper(arr, 0, arr.size() - 1);
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
    
    merge_sort(arr);
    
    cout << "Sorted array using Merge Sort:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
    
    return 0;
}