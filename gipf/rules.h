#pragma once
#include <vector>
#include "Point.h"

class GameRules {
    // The board size expressed as the number of hexagonal board fields on each side of the board
    int S;

    // The number of player pieces that trigger the collection of pieces 
    int K;

    // The number of pieces belonging to the white player
    int GW;

    // The number of pieces belonging to the black player
    int GB;

    // Determine how many player pieces are on board
    int whiteOnBoard;
    int blackOnBoard;

    // Determine whose turn it is 
    char player;

    public:
        // The default game rules constructor 
        GameRules(int s_, int k_, int gw_, int gb_) {
            this->S = s_;
            this->K = k_;
            this->GW = gw_;
            this->GB = gb_;
        }

        /*
        @returns
        0 - false
        1 - true
        */
        int checkRules() {
            return checkK() && checkGW() && checkGB();
        }

        int checkK() {
            return (K > 2 && K < (2*S-1));
        }

        int checkGW() {
            return GW > 3;
        }

        int checkGB() {
            return GB > 3;
        }

        int getS() {
            return this->S;
        }

        int getK() {
            return this->K;
        }

        int getGW() {
            return this->GW;
        }

        int getGB() {
            return this->GB;
        }

        void setS(int s) {
            this->S = s;
        }

        void setK(int k) {
            this->K = k;
        }

        void setGW(int gw) {
            this->GW = gw;
        }

        void setGB(int gb) {
            this->GB = gb;
        }

        void getOnBoard() {
            int white, black;
            char player_;

            std::cin >> white >> black >> player_;

            this->whiteOnBoard = GW - white;
            this->blackOnBoard = GB - black;
            this->player = player_;
        }

        /*
        @returns
        0 - BOARD_STATE_OK
        1 - WRONG_WHITE_PAWNS_NUMBER - zła liczba białych pionów
        2 - WRONG_BLACK_PAWNS_NUMBER - zła liczba czarnych pionów
        3 - WRONG_BOARD_ROW_LENGTH - zła długość wiersza planszy
        */
        int checkBoardState(std::vector<std::vector<Point *>> boardPieces) {
            // Pawn counters
            int counterWhite = 0;
            int counterBlack = 0;
            
            // TODO: Change later (might not work)
            int _goal = getUnderscoreGoal();
            int _counter = 0;

            // Count elements
            for (auto pointRow : boardPieces)
            {
                for (auto point : pointRow)
                {
                    if (point->c == 'W') {
                        counterWhite++;
                    } else if (point->c == 'B') {
                        counterBlack++;
                    } else if (point->c == '_') {
                        _counter++;
                    }
                }
                
            }
            
            // Decrement the goal
            _goal -= counterWhite + counterBlack;


            // Return the message
            if (counterWhite != this->whiteOnBoard) {
                std::cout << "White on board: "  << this->whiteOnBoard << ", counter: " << counterWhite  << std::endl;
                std::cout << "WRONG_WHITE_PAWNS_NUMBER";
                return 1;
            } else if (counterBlack != this->blackOnBoard) {
                std::cout << "White on board: "  << this->blackOnBoard << ", counter: " << counterWhite  << std::endl;
                std::cout << "WRONG_BLACK_PAWNS_NUMBER";
                return 2;
            } 
            // Check the len' of each side TODO: 
            else if (_goal != _counter) {
                std::cout << "GOAL: "  << _goal << ", counter: " << _counter << std::endl;
                std::cout << "WRONG_BOARD_ROW_LENGTH";
                return 3;
            }
            else {
                std::cout << "BOARD_STATE_OK" << std::endl;
                return 0;
            }
            
            
        }

        int getUnderscoreGoal() {
            int g = 0;
            int i = S - 2;

            while (i >= 0) {
                int curr = S + i;

                // *2 because of hexagon's symmetry
                g += 2*curr;

                // Decrement the iterator
                i--;
            }

            g += 2 * S - 1;
            return g;
        }
};