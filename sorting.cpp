#include <bits/stdc++.h>
using namespace std;

// Merge sort
// divide and merge
void merge(vector<int> &arr, int low, int mid, int high) {

	vector<int> temp;
	int left = low;
	int right = mid + 1;

	while(left <= mid && right <= high) {
		if(arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		} else {
			temp.push_back(arr[right]);
			right++;
		}
	}

	while(left <= mid) {
		temp.push_back(arr[left]);
		left++;
	}

	while(right <= high) {
		temp.push_back(arr[right]);
		right++;
	}

	for(int i = low; i <= high; i++) {
		arr[i] = temp[i - low];
		cout<<arr[i]<<endl;
	}
	cout<<"--------------"<<endl;
}

void mergeSort(vector<int> &arr,int low, int high) {

	if(low == high) return;
	int mid = (low + high)/2;
	mergeSort(arr, low, mid);
	mergeSort(arr, mid + 1, high);
	cout<<"***********"<<endl;
	merge(arr, low, mid, high);

}

// Quick Sort
// divide and conquor

int partition(vector<int> &arr, int low, int high) {

	int pivot = arr[low];
	int i = low;
	int j = high;

	while(i < j) {
		
		while (arr[i] <= pivot && i <= high - 1) {
			i++;
			cout<<i<<endl;
		}

		while (arr[j] > pivot && j >= low + 1) {
			j--;
			cout<<"j:"<<j<<endl;
		}
		
		if(i < j) swap(arr[i], arr[j]);
	}

	swap(arr[low], arr[j]);
	return j;
}

void quickSort(vector<int> &arr, int low, int high) {
	if(low < high) {
		int pIndex = partition(arr, low, high);
		cout<<"p: "<<pIndex<<endl;
		cout<<"----------"<<endl;

		quickSort(arr, low, pIndex - 1);
		cout<<"********"<<endl;
		quickSort(arr, pIndex + 1, high);
	}
	// return arr;
}

int main() {
	vector<int> v = {7, 3, 4, 2, 1};
	// mergeSort(v, 0, v.size() - 1);
	quickSort(v, 0, v.size() - 1);

	// vector<int> arr = {9, 4, 7, 6, 3, 1, 5, 8};
    // int n = 7;

    // cout << "Before Sorting Array: " << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // mergeSort(arr, 0, n - 1);
    // quickSort(v, 0, v.size() - 1);
    // cout << "After Sorting Array: " << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    return 0 ;

}