#pragma once
#include <iostream>
#include "rules.h"
#include "Point.h"
#include "pieces.h"
#include <ncurses.h>


class Engine {
    // Keeping track of the current cursor position
    Point *cursorPos;

    /*
    @brief The indicator of whose turn it is
    @returns
    1 - white 
    0 - black
    */
    int currentlyMoving;

    // Game rules
    GameRules *gameRules;

    // Keep track of the board structure
    BoardPieces *board;

    public:
        Engine() {
            this->board = new BoardPieces();
        }

        void LOAD_GAME_BOARD() {
            int S, K, GW, GB;
            std::cin >> S >> K >> GW >> GB;

            // std::cout << "S: " << S << ", K: " << K << ", GW: " << GW << ", GB: " << GB << std::endl;

            // Create an instance of rules-holding object
            this->gameRules = new GameRules(
                S, K, GW, GB
            );

            // Count the pieces on the board
            gameRules->getOnBoard();

            // Scan and cache the board
            this->board->scanBoard(S);

            // Check the state of the board
            gameRules->checkBoardState(board->getBoard());
        }

};