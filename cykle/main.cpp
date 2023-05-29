#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int linesNum = 0;
    cin >> linesNum;

    for (size_t matrixes = 0; matrixes < linesNum; matrixes++)
    {
        bool clawFree = true;

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
            for (size_t j = 0; j < rows; j++)
            {
                if (matrix[i][j]) {
                    for (size_t k = j + 1; k < rows; k++)
                    {
                        if (matrix[i][k] && !matrix[j][k]) {
                            for (size_t l = k + 1; l < rows; l++)
                            {
                                if (matrix[i][l] && !matrix[j][l] && !matrix[k][l]) {
                                    clawFree = false;
                                    break;
                                }
                                
                            }
                        }

                    }                
                }
            }
            
        }

        cout << clawFree << endl;
        
    }
    
    
        

    return 0;
}