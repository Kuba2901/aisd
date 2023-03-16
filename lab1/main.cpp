#include <iostream>
#include <math.h>

using namespace std;

void printPalindrome(int bufforArray[], int n)
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
        if (!(bufforArray[i] == bufforArray[j])) {
            palindrome = 0;
            break;
        }

		
    }    

	// Jesli dana liczba jest palindromem to wypisujemy na ekran
    if (palindrome) {
        for (int i = 0; i < n; i++) {
            cout << bufforArray[i];
        }

		// cout << "	";
    }

}

void getAllBinaries(int iterator, int *bufforArray, int n) {
	// Zwijamy funkcje jesli iterator osiagnal koniec ciagu bitowego
	if (iterator == n) {
		printPalindrome(bufforArray, n);
		return;
	}

	// Iterator dla rekurencji
	int j = iterator + 1;

	// Początkowo ustawiamy 1, żeby otrzymywac wszystkie permutacje z 1 na początku
	bufforArray[iterator] = 1;
	getAllBinaries(j, bufforArray, n);

	// Pozniej ustawiamy 0, analogicznie do 1
	bufforArray[iterator] = 0;
	getAllBinaries(j, bufforArray, n);
}

int main() {
	//  n - długość ciągow bitowych
	int n;

    cin >> n;

	// Dynamicznie alokowana tablica, do ktorej zapisywane beda kombinacje
	int* bufforArray = (int*)malloc(sizeof(int)*pow(2,n));

    getAllBinaries(0, bufforArray, n);

	if (bufforArray != nullptr) {
		free(bufforArray);
	}

	return 0;
}

