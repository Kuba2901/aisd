#include "engine.h"

Engine::Engine() {
    // Create an instance of rules
    this->gameRules = new GameRules(this);     

    // Instantiate the board
    this->board = new BoardPieces(this);

    // Start processing commands
    processCommands();
}

void Engine::LOAD_GAME_BOARD() {
    // Delete previous values
    this->board->clearData();
    this->gameRules->clearData();

    // Load rules values
    this->gameRules->loadRules();

    // Set the currently moving player
    this->currentlyMoving = this->gameRules->getPlayer();

    // Set remaining pieces in the board
    this->board->setRemaining();

    // Scan and cache the board
    this->board->scanBoard();

    // Check the state of the board
    gameRules->checkBoardState(board->getBoard());

    // printf("\n");

    // this->board->printBoard();

    // Make a test move
    // board->makeMove("d1", "d2");
}

void Engine::PRINT_GAME_BOARD() {
    if (this->getRules()->getMapCorrect()) {
        this->board->printValues();
        this->board->printOriginalBoard();
        printf("\n");
    } else {
        printf("EMPTY_BOARD\n");
    }
}

void Engine::processCommands() {
    // Define a line buffor
    std::string line;

    while (getline(std::cin, line)) {
        if (line.compare("LOAD_GAME_BOARD") == 1) {
            LOAD_GAME_BOARD();
        } 
        else if (line.compare("PRINT_GAME_BOARD") == 1 || line == "PRINT_GAME_BOARD") {
            PRINT_GAME_BOARD();
        } 
        else if (line.find("DO_MOVE") != std::string::npos) {
            DO_MOVE(line);
        }
    }
}

void Engine::DO_MOVE(std::string args) {
    // Find DO_MOVE
    size_t movePos = args.find("DO_MOVE");

    // printf("MOVE LINE: %s\n", args.c_str());

    // Get arguments
    std::string arguments = args.substr(movePos + 8);

    // Extract the arguments
    std::stringstream ss(arguments);

    std::string from, to;
    std::getline(ss, from, '-');
    std::getline(ss, to);

    // Remove endline
    to.erase(to.length() - 1);

    // Make the move
    this->board->makeMove(from, to);

    printf("\n");

    // Check captures
    getAllCaptures();

    // Change the current player
    this->changeCurrentlyMoving();
}

GameRules* Engine::getRules() {
    return this->gameRules;
}

char Engine::getCurrentlyMoving() {
    return this->currentlyMoving;
}

void Engine::changeCurrentlyMoving() {
    if (this->currentlyMoving == 'B') {
        this->currentlyMoving = 'W';
    } else {
        this->currentlyMoving = 'B';
    }
}

BoardPieces* Engine::getBoardPieces() {
    return this->board;
}

void Engine::getAllCaptures() {
    this->board->findFlatlineCaptures();
    this->board->diagonalCaptures();
    this->board->reverseDiagonalCaptures();

}