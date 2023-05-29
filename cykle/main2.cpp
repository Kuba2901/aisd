#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int linesNum = 0;
    cin >> linesNum;

    for (size_t matrixes = 0; matrixes < linesNum; matrixes++)
    {
        bool cyclic = true;

        // macierz sasiedztwa
        vector<vector<int>> matrix;

        int rows = 0;
        string line;

        cin >> rows;
        cin >> line;


        int k = 0;
        for (int i = 0; i < rows; i++) {
            vector<int> row;
            for (int j = 0; j < rows; j++) {
                row.push_back(line[k] - '0');
                k++;
            }

            matrix.push_back(row);
        }

        

        for (size_t i = 0; i < rows; i++)
        {
            int counter = 0;

            for (size_t j = 0; j < rows; j++)
            {
                if (matrix[i][j] != matrix[j][i]) {
                    cyclic = false;
                }

                counter += matrix[i][j];
                cout << matrix[i][j] << " ";
            }

            if (counter < 2) {
                cyclic = false;
            }

            cout << endl;
        }

        // Check if the last element is connected to the first element
        if (matrix[rows - 1][0] != 1 || matrix[0][rows - 1] != 1) {
            cyclic = false;
        }
        

        cout << endl;

        // if (cyclic) {
        //     cout << 1 << endl;
        // } else {
        //     cout << 0 << endl;
        // }

    }    


    return 0;
}