#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "engine.h"
#include "mapPoint.h"
#include "Point.h"
#include "indexed_field.h"

class Engine;

class BoardPieces {
    // The board items with coordinates and characters
    std::vector<std::vector<Point*>> boardPieces;
    std::vector<std::vector<Point*>> originalBoard;

    // Keeping track of remaining pawns for each player
    int remainingWhite;
    int remainingBlack;

    // Reindexed fields of the map
    // std::unordered_map<std::string, char> boardMap;
    std::unordered_map<std::string, Point*> boardMap;

    // Point to game rules and engine
    // GameRules *gameRules;
    Engine *engine;

    public:
        BoardPieces(Engine *engine_);

        virtual void incrementWhite();

        virtual void incrementBlack();

        virtual int getRemainingWhite();

        virtual int getRemainingBlack();

        virtual std::vector<std::vector<Point*>> getBoard();

        virtual void scanBoard();

        virtual void printBoard();

        virtual void printHashMap();

        virtual void addFreeFields(int S);

        // Shift indexes while inserting '+' signs
        virtual void shiftIndexes();

        virtual void reindexFields(int S);

        virtual void insertToTheMap(std::string key, Point* val);

        virtual void printField(std::string key);

        virtual bool entryExists(std::string key);

        virtual bool compareIndexes(std::string key1, std::string key2);

        virtual bool isEdge(std::string key1);

        virtual bool isCorner(std::string key);

        virtual bool isCornerMoveLegal(std::string key1, std::string key2);

        // The point is not a corner
        virtual bool isMoveLegal(std::string key1, std::string key2);

        virtual void makeMove( std::string begin, std::string dest);

        // Printing out the indexes
        virtual void printIndexes();

        virtual void removeEmpty();

        // Print out the board without extra fields
        virtual void printOriginalBoard();

        // Clear board data
        virtual void clearData();

        // Check if any 
        virtual void findFlatlineCaptures();

        // Update remaining
        virtual void updateRemaining(int white, int black);

        virtual void printRemaining();

        virtual void setRemaining();


        virtual void findInLine(char c, int x, int y, std::vector<Point *> *vec);

        virtual int findFirstDiagonalIndex(int y);

        virtual int findLastDiagonalIndex(int y);


        virtual void removeCapturedFromBoard(std::vector<Point *> *blacksToBeCaptured);

        // Finding diagonal captures [/]
        virtual void diagonalCaptures();

        virtual void captureDiagonal(int x, int y, std::vector<Point *> *vec);

        virtual void reverseDiagonalCaptures();

        virtual void captureReverseDiagonal(int x, int y, std::vector<Point *> *vec);

        ~BoardPieces() {}

};