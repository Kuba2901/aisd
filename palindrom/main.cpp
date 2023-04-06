// #include <iostream>
// #include <math.h>

// using namespace std;

// void printPalindrome(int bufforArray[], int n)
// {	
//     int palindrome = 1; // Flaga
	

//     for (int i = 0; i < n; i++)
//     {
// 		int j = (n-1)-i; // Iterator od tylu

// 		// Jesli indeksy "sie minely" to break bo juz sprawdzone
// 		if (i >= j) {
// 			break;
// 		}
		
// 		// Porownywanie odpowiednich wartosci od przodu i tylu
//         if (!(bufforArray[i] == bufforArray[j])) {
//             palindrome = 0;
//             break;
//         }

		
//     }    

// 	// Jesli dana liczba jest palindromem to wypisujemy na ekran
//     if (palindrome) {
//         for (int i = 0; i < n; i++) {
//             cout << bufforArray[i];
//         }

//     }


// }

// void getAllBinaries(int iterator, int *bufforArray, int n) {
// 	// Zwijamy funkcje jesli iterator osiagnal koniec ciagu bitowego
// 	if (iterator == n) {
// 		printPalindrome(bufforArray, n);
// 		return;
// 	}

// 	// Iterator dla rekurencji
// 	int j = iterator + 1;

// 	// Początkowo ustawiamy 1, żeby otrzymywac wszystkie permutacje z 1 na początku
// 	bufforArray[iterator] = 1;
// 	getAllBinaries(j, bufforArray, n);

// 	// Pozniej ustawiamy 0, analogicznie do 1
// 	bufforArray[iterator] = 0;
// 	getAllBinaries(j, bufforArray, n);
// }

// int main() {
// 	//  n - długość ciągow bitowych
// 	int n;
	
// 	while (cin >> n) {
// 		// Dynamicznie alokowana tablica, do ktorej zapisywane beda kombinacje
// 	 	int bufforArray[100]; //(int*)malloc(sizeof(int)*int(pow(2,n)));

// 		getAllBinaries(0, bufforArray, n);

// 		cout << endl;
// 	}


// 	return 0;
// }

#include <iostream>
#include <string>

void printReversedString(int counter, std::string palindrome) {
    std::string reversedPalindrome = "";
    for (int i = counter; i >= 0; i--) {
        reversedPalindrome += palindrome[i];
    }
    std::cout << reversedPalindrome;
}

void solution(std::string text, int n, int counter) {
    if(n == 1) {
        std::cout << "10";
        return;
    }
    if(counter == n/2) {
        if(n%2 == 0) {
            std::cout<<text;
            printReversedString(counter, text);
            return;
        } else {
            std::cout<<text;
            std::cout<<"1";
            printReversedString(counter, text);
            std::cout<<text;
            std::cout<<"0";
            printReversedString(counter, text);
            return;
        }
    }
    
    solution(text+"1", n, counter+1);
    solution(text+"0", n, counter+1);
}

int main() {
    int n;
    while(std::cin>>n) {
        solution("", n, 0);
        std::cout<<std::endl;
    }
    return 0;
}
