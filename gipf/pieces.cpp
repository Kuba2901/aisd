#include "pieces.h"

BoardPieces::BoardPieces(Engine *engine_) {
    this->engine = engine_;
}

void BoardPieces::incrementWhite() {
    this->remainingWhite++;
}

void BoardPieces::incrementBlack() {
    this->remainingBlack++;
}

int BoardPieces::getRemainingWhite() {
    return this->remainingWhite;
}

int BoardPieces::getRemainingBlack() {
    return this->remainingBlack;
}

std::vector<std::vector<Point*>> BoardPieces::getBoard() {
    return this->boardPieces;
}

void BoardPieces::scanBoard() {
    int S = engine->getRules()->getS();

    // Create line buffer
    std::string line;

    // Get board dimensions
    int height = 1; //2*(S-1);
    int width = 3*(S-1); // 3*(S-1);

    int y = 0;

    while (getline(std::cin, line)) {
        std::vector<Point*> row;

        // printf("LINE: %s", line.c_str());

        if (!line.empty() && line.length() > 1) {
            for (size_t x = 0; x < line.length(); x++)
            {
                // Adding +1 for later '+'
                row.push_back(new Point(x, y+1, line[x]));
            }

            // Add an extra ' ' to the end of the line
            row.insert(row.end() - 1, new Point(0, y+1, ' '));;
            boardPieces.push_back(row);
            y++;
        } 


        // Detect input end
        if (line.length() == 1 && y > 1) {
            break;
        }
    }

    // Copy the original board to a different structure
    this->originalBoard = boardPieces;

    // printBoard();

    addFreeFields(S);
    reindexFields(S);

    // ! TESTING
    // printBoard();
}

void BoardPieces::removeEmpty() {
    for (size_t y = 0; y < boardPieces.size(); y++)
    {
        if (boardPieces[y].size() == 0) {
            // printf("LINE EMPTY: %d", y);
        }
     }
    
}

void BoardPieces::printBoard() {
    for (auto pointRow : boardPieces)
    {
        for (auto point : pointRow)
        {
            printf("%c", point->c);
        }

        printf("\n");
        
    }    
}


void BoardPieces::printHashMap() {
    for (auto kv : boardMap)
    {
        std::cout << kv.first;
    }
    
}

void BoardPieces::addFreeFields(int S) {
    // Add the '+' signs to the top and bottom of the board
    std::vector<Point *> top;
    std::vector<Point *> bottom;


    for (size_t y = 0; y < boardPieces.size(); y++)
    {

        for (size_t x = 0; x < boardPieces[y].size() - 1; x++)
        {
            // Inserting to the front
            Point* curr = boardPieces[y][x];

            // The first element is not empty
            if (x == 0 && curr->c != ' ') {
                boardPieces[y].insert(boardPieces[y].begin(), new Point(0, y, '+'));
                boardPieces[y].insert(boardPieces[y].begin() + 1, new Point(1, y, ' '));
                break;
            } 
            else if (curr->c != ' ' && boardPieces[y][x+1]) {
                boardPieces[y].insert(boardPieces[y].begin() + x, new Point(x, y, '+'));
                boardPieces[y].insert(boardPieces[y].begin() + x + 1, new Point(x, y, ' '));
                break;
            }
        }

        // Push '+' sign to the end
        // boardPieces[y].insert(boardPieces[y].end() - 1, new Point(boardPieces[y].size() - 2, y, ' '));
        boardPieces[y].insert(boardPieces[y].end() - 1, new Point(boardPieces[y].size() - 2, y, '+'));
    }

    // Iterate over the top
    for (size_t x = 0; x < boardPieces[0].size() - 2; x++)
    {
        if (boardPieces[0][x + 1]->c != ' ' && x >= S) {
            top.push_back(new Point(x, 0, '+'));
        } else {
            top.push_back(new Point(x, 0, ' '));
        }
    }

    
    // Iterate over the bottom
    for (size_t x = 0; x < boardPieces[boardPieces.size() - 1].size() - 2; x++)
    {
        if (boardPieces[boardPieces.size() - 1][x + 1]->c != ' ' && x >= S) {
            bottom.push_back(new Point(x, boardPieces.size() + 1, '+'));
        } else {
            bottom.push_back(new Point(x ,boardPieces.size() + 1, ' '));
        }
    }

    // Push rows to the board
    boardPieces.insert(boardPieces.begin(), top);
    boardPieces.push_back(bottom);

    // Repair indexes
    shiftIndexes();
}

// Shift indexes while inserting '+' signs
void BoardPieces::shiftIndexes() {
    for (size_t y = 0; y < boardPieces.size(); y++)
    {
        for (size_t x = 0; x < boardPieces[y].size() - 1; x++)
        {
            boardPieces[y][x]->x = x;
            boardPieces[y][x]->y = y;
        }
    }
}

void BoardPieces::reindexFields(int S) {
    char c = 'a';

    int yCounter = 0;
    int xCounter = 0;
    int wordCounter = 0;

    for (int y = 0; y < boardPieces.size(); y++)
    {
        // Second half
        if (y > S) {
            wordCounter++;
        }

        for (size_t i = 0; i < boardPieces[y].size(); i++)
        {
            std::vector<Point *> pointRow = boardPieces[y];
            Point *curr = pointRow[i];

            // Before the line
            if (i <= 3*S-yCounter) {
                if (curr->c != ' ') {
                    // Start counting
                    if (xCounter == 0) {
                        xCounter = (y <= S - 1) ? (i + 1): 1;
                    } 
                    // Increment the counter
                    else {
                        xCounter++;
                    }

                    char character = c + wordCounter;
                    int index = xCounter;

                    std::string key;
                    key += character;
                    key += std::to_string(index);

                    insertToTheMap(key, curr);

                    // printf("%c%d", character, index);
                    
                    c++;

                } else  {
                    // Print out the space
                    // printf("%c", curr->c);
                }
                
            } 
            // After the line
            else {
                // Check the character
                if (curr->c == 'B' || curr->c == 'W' || curr->c == '_' || curr->c == '+') {
                    char character = c + wordCounter;
                    int index = xCounter;

                    std::string key;
                    key += character;
                    key += std::to_string(index);

                    insertToTheMap(key, curr);

                    // printf("%c%d", character, index);
                    c++;

                } else {
                    // Print out the space
                    // printf("%c", curr->c);
                }
            }
        }

        // printf("\n");

        yCounter++;
        xCounter = 0;

        // Reset the character
        c = 'a';
    }
}


void BoardPieces::insertToTheMap(std::string key, Point* val) {
    boardMap[key] = val;
}

void BoardPieces::printField(std::string key) {
    bool exists = boardMap.count(key);

    if (exists) {
        Point* curr = boardMap[key];
        // std::cout << "FOUND: " << curr->c << std::endl;
    } else {
        // std::cout << "DOES not EXIST" << std::endl;
    }
}

bool BoardPieces::entryExists(std::string key) {
    return boardMap.count(key);
}

bool BoardPieces::compareIndexes(std::string key1, std::string key2) {
    if (entryExists(key1) && entryExists(key2)) {
        // Get indexes from the keys
        int index1 = stoi(key1.substr(1));
        int index2 = stoi(key2.substr(1));

        return abs(index1 - index2) <= 1;
    }

    return false;
}

bool BoardPieces::isEdge(std::string key1) {
    int S = engine->getRules()->getS();
    // Get information from string 1
    char c1 = key1[0];
    int index1 = stoi(key1.substr(1));

    // Last letter
    char last = 'a' + 2*S;
    int lastMaxIndex = S + 1;

    // Top edge
    int constValue = ('a' - (S + 1));
    int currValue = c1 - index1;

    // Check letter
    if ((c1 == 'a' || c1 == last) && (index1 > 0 && index1 <= S+1)) {
        // printf("A OR LAST");
        return true;
    }

    // Index equal to 1
    if (index1 == 1) {
        // printf("INDEX EQUAL TO 1");
        return true;
    }

    // Delta equal to constValue
    if (currValue == constValue) {
        // printf("DELTA EQUAL CONSTVALUE");
        return true;
    } 

    // Right top corner - multiple comparisons
    int letterDelta = last - c1;
    int indexDelta = index1 - lastMaxIndex;

    if (letterDelta == indexDelta) {
        // printf("TOP RIGHT");
        return true;
    }

    // printf("CENTER, constValue: %d", constValue);
    return false;
}

bool BoardPieces::isCorner(std::string key) {
    // Get S
    int S = engine->getRules()->getS();

    // Get information from the string key
    char c1 = key[0];
    int index = stoi(key.substr(1));

    // Determine the max index for the first and last letter
    int flMaxIndex = S+1;

    // Determine the last letter
    char last = 'a' + 2*S;

    // Determine the max index on the board
    int boardMaxIndex = 2*S+1;

    // Determine longest diagonal letter
    char longestDiagonalLetter = 'a' + S;

    // Print data
    // printf("LONGEST DIAGONAL LETTER: %c", longestDiagonalLetter);

    // CORNER CHECKING
    // Check if it's the first or last letter and the index is 1 or S+1
    if ((c1 == 'a' || c1 == last) && (index == 1 || index == flMaxIndex)) {
        return true;
    }

    // Check if it's a corner on the longest diagonal
    if (c1 == longestDiagonalLetter && (index == 1 || index == boardMaxIndex)) {
        return true;
    }

    return false;
}

bool BoardPieces::isCornerMoveLegal(std::string key1, std::string key2) {
    // Define map points
    MapPoint *mp1 = new MapPoint(key1);
    MapPoint *mp2 = new MapPoint(key2);

    // Define index delta
    int indexDelta = abs(mp1->index - mp2->index);
    int charDelta = abs(mp1->c - mp2->c);

    // Check if the two points are next to each other
    if (indexDelta <= 1) {
        // Move a -> b
        if (mp1->c == 'a' && mp2->c == 'b') {
            return true;
        }

        // Move on the longest diagonal
        if (mp1->c == mp2->c) {
            return true;
        }

        // Move from the last letter to the one before
        if (mp1->c - mp2->c == 1) {
            return true;
        }
    }

    // No condition was fulfilled
    return false;
}

// The point is not a corner
bool BoardPieces::isMoveLegal(std::string key1, std::string key2) {
    int S = engine->getRules()->getS();

    // Check if values are in the board
    if (!entryExists(key1) || !entryExists(key2)) {
        // printf("ERROR: Entries don't exist");
        return false;
    }

    // Define map points
    MapPoint *mp1 = new MapPoint(key1);
    MapPoint *mp2 = new MapPoint(key2);

    // Define index delta
    int indexDelta = abs(mp1->index - mp2->index);
    int charDelta = abs(mp1->c - mp2->c);

    // Check whether the first field is on the edge
    if (!isEdge(key1)) {
        // printf("ERROR: The first field is not on the edge\n");
        return false;
    }

    // Check whether the second field is not on the edge
    if (isEdge(key2)) {
        // printf("ERROR: The second field is on the edge\n");
        return false;
    }

    // Check if the first field is a corner
    if (isCorner(key1)) {

        // Check if the corner move is legal
        if (isCornerMoveLegal(key1, key2)) {
            // TODO: Add map checking
            // printf("SUCCESS: Corner move is legal\n");
            return true;
        }

        // printf("ERROR: Corner move is not legal\n");
        return false;

    }

    // Check non-corner move conditions
    if (indexDelta <= 1 && charDelta <= 1) {
        // printf("SUCCESS: Move legal\n");
        return true;
    }

    // printf("ERROR: Conditions were not met\n");
    return false;
}

void BoardPieces::makeMove( std::string begin, std::string dest) {
    if (isMoveLegal(begin, dest)) {
        printf("\n\nMOVE MADE\n");
        boardMap[dest]->c = 'B';
        printBoard();
    } else {
        // printf("BAD_MOVE\n");
    }
}

// Printing out the indexes
void BoardPieces::printIndexes() {
    for (auto pointRow : boardPieces)
    {
        for (auto point : pointRow)
        {
            printf("(%d,%d) ", point->x, point->y);
        }

        printf("\n");
    }
    
}

void BoardPieces::clearData() {
    std::vector<std::vector<Point*>> boardPieces;
    this->boardPieces.clear();
    this->remainingBlack = 0;
    this->remainingBlack = 0;
    this->boardMap.clear();
}

void BoardPieces::printOriginalBoard() {
    for (auto pointRow : originalBoard)
    {
        for (auto point : pointRow)
        {
            printf("%c", point->c);
        }

        printf("\n");
        
    }    
}

void BoardPieces::findCaptures() {
    // Determine vector height
    int height = boardPieces.size();

    // Define how many pawns in a row for each player
    int whiteInRow = 0;
    int blackInRow = 0;

    // Find <-> this way (starting from 1 and ending at -1 because of edges)
    for (size_t y = 1; y < height - 1; y++)
    {
        printf("CHECKING ROW: %d\n", y);

        // Determine row width
        int width = boardPieces[y].size();

        // Same here
        for (size_t x = 1; x < width - 1; x++)
        {
            // Define the current element
            Point* curr = boardPieces[y][x];

            if (curr->c == 'W') {
                // printf("WHITE FOUND\n");
                whiteInRow++;
                blackInRow = 0;
            } 
            else if (curr->c == 'B') {
                // printf("BLACK FOUND\n");
                whiteInRow = 0;
                blackInRow++;
            } else if (curr->c == '_') {
                // printf("RESETING COUNTER\n");
                blackInRow = 0;
                whiteInRow = 0;
            }

            // Check status (TODO: Change from 4 to K)
            if (whiteInRow == 4) {
                // 4 whites in a row (capture everying in this row)
                // TODO: White captures everything in that row
                printf("POSSIBLE CAPTURE OF BLACKS IN ROW: %d\n", y);
                break;

            }
            else if (blackInRow == 4) {
                // 4 blacks in a row (capture everying in this row)
                // TODO: Black captures everything in that row
                printf("POSSIBLE CAPTURE OF WHITES IN ROW: %d\n", y);
                break;
            }
        }
        
        // Reset counters
        whiteInRow = 0;
        blackInRow = 0;

    }
    
}
