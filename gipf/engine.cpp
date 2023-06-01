#include "engine.h"

Engine::Engine() {
    // Create an instance of rules
    this->gameRules = new GameRules();     

    // Instantiate the board
    this->board = new BoardPieces(this);

    // Start processing commands
    processCommands();

    // Find captures
    this->board->findCaptures();

}

void Engine::LOAD_GAME_BOARD() {
    // Delete previous values
    this->board->clearData();
    this->gameRules->clearData();

    // Load rules values
    this->gameRules->loadRules();

    // Scan and cache the board
    this->board->scanBoard();

    // Check the state of the board
    gameRules->checkBoardState(board->getBoard());

    // Make a test move
    // board->makeMove("d1", "d2");
}

void Engine::PRINT_GAME_BOARD() {
    if (this->getRules()->getMapCorrect()) {
        this->gameRules->printRules();
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
        else if (line.compare("PRINT_GAME_BOARD") == 1) {
            PRINT_GAME_BOARD();
        } 
    }
}

GameRules* Engine::getRules() {
    return this->gameRules;
}
