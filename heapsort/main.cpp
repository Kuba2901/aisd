#include <iostream>
#include <string>
#define NUMS_COUNT 10000

using namespace std;

bool compare(string a, string b);


int parent(int i) {
	return i / 2;
}

int left(int i) {
	return i*2;
} 

int right(int i) {
	return i*2+1;
} 



void heapify(string numArray[], int i, int size) {
	int L = left(i);
	int R = right(i);
	int maxps = 0;
	
	if (L <= size && compare(numArray[L-1], numArray[i-1])) {
		maxps = L;
	} else {
		maxps = i;
	}

	if (R <= size && compare(numArray[R-1], numArray[maxps - 1])) {
		maxps = R;
	}

	if (maxps != i) {
		swap(numArray[i-1], numArray[maxps - 1]);

		heapify(numArray, maxps, size);
	}
}

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		bool gt = false;

		for (int i = 0; i < a.size(); i++)
		{
			if (int(a[i]) > int(b[i])) {
				gt = true;
				break;
			}
		}
		
		return gt;
	} else {
		if (a.size() > b.size()) return true;
		return false;
 	}
}

void buildheap(string numArray[], int size) {
	for (int i = parent(size); i > 0; i--)
	{
		heapify(numArray, i, size);
	}
}

void heapsort(string numArray[], int size) {
	buildheap(numArray, size);
	for (int i = size; i > 0; i--)
	{		
		swap(numArray[i-1], numArray[0]);

		heapify(numArray, 1, i-1);
	}
	
}

int main() {
	string newNum;
	
	int n;
	cin >> n;

	string *nums = new string[n]; 

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	heapsort(nums, n);

	for (int i = 0; i < n ; i++)
	{
		if (!nums[i].empty()) {
			cout << nums[i] << endl;
		}
	}

	delete[] nums;

	return 0;
	
	
}

// #include <iostream>
// #include <string>
// #define NUMS_COUNT 10000

// using namespace std;

// bool compare(string a, string b);


// int parent(int i) {
// 	return i / 2;
// }

// int left(int i) {
// 	return i*2;
// } 

// int right(int i) {
// 	return i*2+1;
// } 



// void heapify(string numArray[], int i, int size) {
// 	int L = left(i);
// 	int R = right(i);
// 	int maxps = 0;
	
// 	if (L <= size && compare(numArray[L-1], numArray[i-1])) {
// 		maxps = L;
// 	} else {
// 		maxps = i;
// 	}

// 	if (R <= size && compare(numArray[R-1], numArray[maxps - 1])) {
// 		maxps = R;
// 	}

// 	if (maxps != i) {
// 		swap(numArray[i-1], numArray[maxps - 1]);

// 		heapify(numArray, maxps, size);
// 	}
// }

// bool compare(string a, string b) {
// 	if (a.size() == b.size()) {
// 		if (a > b) {
// 			return true;
// 		} 
// 		return false;
// 	} else {
// 		if (a.size() > b.size()) return true;
// 		return false;
//  	}
// }

// void buildheap(string numArray[], int size) {
// 	for (int i = parent(size); i > 0; i--)
// 	{
// 		heapify(numArray, i, size);
// 	}
// }

// void heapsort(string numArray[], int size) {
// 	buildheap(numArray, size);
// 	for (int i = size; i > 0; i--)
// 	{		
// 		swap(numArray[i-1], numArray[0]);

// 		heapify(numArray, 1, i-1);
// 	}
	
// }

// int main() {
// 	string newNum;
	
// 	int n;
// 	cin >> n;

// 	string *nums = new string[n]; 

// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> nums[i];
// 	}

// 	heapsort(nums, n);

// 	for (int i = 0; i < n ; i++)
// 	{
// 		if (!nums[i].empty()) {
// 			cout << nums[i] << endl;
// 		}
// 	}

// 	return 0;
	
	
// }