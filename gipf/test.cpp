#include <ncurses.h>
#include <iostream>
#include "Point.h"
#define S 6

void moveCursor(int *cursorX, int *cursorY);

void drawBoard(int *cursorX, int *cursorY) {
    Point *leftTop = new Point(S-1, 2*(S-1));
    Point *leftBottom = new Point(S-1, 0);
    Point *rightTop = new Point(2*(S-1), 2*(S-1));
    Point *rightBottom = new Point(2*(S-1), 0);
    Point *left = new Point(0, S-1);
    Point *right = new Point(3*(S-1), S-1);

    int width = 3*(S-1);
    int halfHeight = S-1;

    // Draw the top part of the hexagon
    for (int y = 0; y < halfHeight; y++) {
        for (int x = 0; x < width; x++) {
            if (x == leftTop->x && y == 0) {
                mvprintw(y, x, "W");
            } else if (x == rightTop->x && y == 0) {
                mvprintw(y, x, "B");
            } else {
                if (x >= (leftTop->x - y) && x <= (rightTop->x + y)) {
                    mvprintw(y, x, "_");
                } else {
                    mvprintw(y, x, " ");
                }
            }
        }
    }

    // Draw the middle part of the hexagon
    for (int x = 0; x <= width; x++) {
        if (x == 0) {
            mvprintw(halfHeight, x, "B");
        } else if (x == width) {
            mvprintw(halfHeight, x, "W");
        } else {
            mvprintw(halfHeight, x, "_");
        }
    }

    // Draw the bottom part of the hexagon
    for (int y = 0; y < halfHeight; y++) {
        for (int x = 0; x < width; x++) {
            if (x == leftBottom->x && y == halfHeight - 1) {
                mvprintw(halfHeight + y + 1, x, "W");
            } else if (x == rightBottom->x && y == halfHeight - 1) {
                mvprintw(halfHeight + y + 1, x, "B");
            } else {
                if (x >= left->x + y + 1 && x <= right->x - y - 1) {
                    mvprintw(halfHeight + y + 1, x, "_");
                } else {
                    mvprintw(halfHeight + y + 1, x, " ");
                }
            }
        }
    }

    moveCursor(cursorX, cursorY);
}

void moveCursor(int *cursorX, int *cursorY) {
    // Refresh the window to display changes
    refresh();

    // Game loop
    while (true) {
        int key = getch();

        // Move the cursor based on arrow key input
        switch (key) {
            case KEY_UP:
                if (*cursorY > 0) {
                    *cursorY--;
                }
                break;
            case KEY_DOWN:
                if (*cursorY < 2*(S-1)) {
                    *cursorY++;
                }
                break;
            case KEY_LEFT:
                if (*cursorX > 0) {
                    *cursorX--;
                }
                break;
            case KEY_RIGHT:
                if (*cursorX < 3*(S-1)) {
                    *cursorX++;
                }
                break;
            case 'q':
                // Quit the game if 'q' key is pressed
                endwin();
                return;
        }

        // Move the cursor to the updated position
        move(*cursorY, *cursorX);
        refresh();
        
    }
}

int main() {
    // Initialize cursor coordinates
    int cursorX = 0, cursorY = 0;

    // Initialize ncurses
    initscr();
    
    // Clear the screen
    clear();
    
    // Move the cursor to the initial position
    move(cursorY, cursorX);

    drawBoard(&cursorX, &cursorY);

    // End the window
    endwin();
    
    return 0;
}
