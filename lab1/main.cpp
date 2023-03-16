#include <iostream>

using namespace std;

void printPalindrome(int arr[], int n)
{	
    int palindrome = 1; // Flaga
	int j; // Iterator od tylu

    for (int i = 0; i < n; i++)
    {
		j = (n-1)-i;

		// Jesli indeksy "sie minely" to break bo juz sprawdzone
		if (i >= j) {
			break;
		}
		
		// Porownywanie odpowiednich wartosci od przodu i tylu
        if (!(arr[i] == arr[j])) {
            palindrome = 0;
            break;
        }

		
    }    

	// Jesli dana liczba jest palindromem to wypisujemt na ekran
    if (palindrome) {
        for (int i = 0; i < n; i++) {
            cout << arr[i];
        }
    }

}

void getAllBinaries(int n, int arr[], int i)
{
	if (i == n) {
		printPalindrome(arr, n);
		return;
	}

	// First assign "1" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 1;
	getAllBinaries(n, arr, i + 1);

	// And then assign "0" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 0;
	getAllBinaries(n, arr, i + 1);
}

// Driver Code
int main()
{
	int n;

    cin >> n;

	int arr[100];

    getAllBinaries(n, arr, 0);

	return 0;
}

