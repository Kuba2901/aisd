#pragma once
#include <iostream>
#include <vector>
#include "Point.h"
#include "indexed_field.h"
#include <sstream>
#include <unordered_map>


class BoardPieces {
    // The board items with coordinates and characters
    std::vector<std::vector<Point*>> boardPieces;

    // Keeping track of remaining pawns for each player
    int remainingWhite;
    int remainingBlack;

    // Reindexed fields of the map
    std::unordered_map<int, std::string> boardFields;

    public:
        BoardPieces() {
            // Default constructor  
        }

        void incrementWhite() {
            this->remainingWhite++;
        }

        void incrementBlack() {
            this->remainingBlack++;
        }

        int getRemainingWhite() {
            return this->remainingWhite;
        }

        int getRemainingBlack() {
            return this->remainingBlack;
        }

        std::vector<std::vector<Point*>> getBoard() {
            return this->boardPieces;
        }

        void scanBoard(int S) {
            std::string line;

            // Get board dimensions
            int height = 1; //2*(S-1);
            int width = 3*(S-1); // 3*(S-1);

            int y = 0;

            while (getline(std::cin, line)) {
                int len = line.length();

                std::vector<Point*> row;

                if (len != 0) {
                    for (size_t x = 0; x < len; x++)
                    {
                        row.push_back(new Point(x, y, line[x]));
                    }

                    boardPieces.push_back(row);
                    y++;

                }
            }

            addFreeFields(S);
            reindexFields(S);
            printBoard();
        }

        void printBoard() {
            printf("\n\nPRINTING BOARD ITEMS\n\n");

            for (auto pointRow : boardPieces)
            {
                for (auto point : pointRow)
                {
                    printf("%c", point->c);
                }

                printf("\n");
                
            }
            

            std::cout << std::endl << std::endl;
         }

        void addFreeFields(int S) {
            // Add the '+' signs to the top and bottom of the board
            std::vector<Point *> top;
            std::vector<Point *> bottom;

            // Iterate over the top
            for (size_t x = 0; x < boardPieces[0].size() - 1; x++)
            {
                if (boardPieces[0][x + 1]->c != ' ' && x >= S) {
                    top.push_back(new Point(0,0,'+'));
                } else {
                    top.push_back(new Point(0,0,' '));
                }
            }
            
            // Iterate over the bottom
            for (size_t x = 0; x < boardPieces[boardPieces.size() - 1].size() - 1; x++)
            {
                if (boardPieces[boardPieces.size() - 1][x + 1]->c != ' ' && x >= S) {
                    bottom.push_back(new Point(0,0,'+'));
                } else {
                    bottom.push_back(new Point(0,0,' '));
                }
            }

            // Push rows to the board
            boardPieces.insert(boardPieces.begin(), top);
            boardPieces.push_back(bottom);


            for (size_t y = 0; y < boardPieces.size(); y++)
            {
                for (size_t x = 0; x < boardPieces[y].size() - 1; x++)
                {
                    // Inserting to the front
                    Point* curr = boardPieces[y][x];

                    // The first element is not empty
                    if (x == 0 && curr->c != ' ') {
                        boardPieces[y].insert(boardPieces[y].begin(), new Point(0,0,'+'));
                        boardPieces[y].insert(boardPieces[y].begin() + 1, new Point(0,0,' '));
                        break;
                    } 
                    else if (curr->c != ' ' && boardPieces[y][x+1]) {
                        boardPieces[y].insert(boardPieces[y].begin() + x, new Point(0,0,'+'));
                        boardPieces[y].insert(boardPieces[y].begin() + x + 1, new Point(0,0,' '));
                        break;
                    }
                }

                // Push '+' sign to the end
                boardPieces[y].push_back(new Point(0,0,' '));
                boardPieces[y].push_back(new Point(0,0,'+'));
                
            }
            
        }

        void reindexFields(int S) {
            char c = 'a';

            int yCounter = 0;
            int xCounter = 0;

            for (int y = 0; y < boardPieces.size(); y++)
            {
                for (size_t i = 0; i < boardPieces[y].size(); i++)
                {
                    std::vector<Point *> pointRow = boardPieces[y];
                    Point *curr = pointRow[i];
                    
                    if (i <= 3*S-yCounter) {
                        if (curr->c != ' ') {
                            // Start counting
                            if (xCounter == 0) {
                                xCounter = y <= S - 1 ? i + 1: 1;
                            } 
                            // Increment the counter
                            else {
                                xCounter++;
                            }

                            printf("%d", xCounter);

                        } else printf("%c", curr->c);
                        
                    } 
                    // After the line
                    else {
                        if (curr->c != ' ') {
                            printf("%d", xCounter);
                        } else {
                            printf("%c", curr->c);
                        }
                    }
                }

                printf("\n");

                yCounter++;
                xCounter = 0;
            }
        }

        ~BoardPieces() {}

};