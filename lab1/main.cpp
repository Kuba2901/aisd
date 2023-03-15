#include <iostream>

using namespace std;

// Function to print the output
void printPalindrome(int arr[], int n)
{
    int palindrome = 1;

    for (int i = 0; i < n; i++)
    {
        if (!(arr[i] == arr[n-i-1])) {
            palindrome = 0;
            break;
        }
    }    

    if (palindrome) {
        cout << " ";
        for (int i = 0; i < n; i++) {
            cout << arr[i];
        }
    }
}

// Function to generate all binary strings
void generateAllBinaryStrings(int n, int arr[], int i)
{
	if (i == n) {
		printPalindrome(arr, n);
		return;
	}

	// First assign "0" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 1;
	generateAllBinaryStrings(n, arr, i + 1);

	// And then assign "1" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 0;
	generateAllBinaryStrings(n, arr, i + 1);
}

// Driver Code
int main()
{
	int n;

    cin >> n;

	int arr[100];

    generateAllBinaryStrings(n, arr, 0);

	return 0;
}

