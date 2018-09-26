//
// Created by yyf on 9/24/18.
//

#ifndef PROJECT1_GRID_H
#define PROJECT1_GRID_H

#include "Board.h"

class Grid{
private:
    vector<vector<Board>> grid;
    int player;
    int depth;
    int size;
    int pos;
public:
    Grid();
//    Grid(Grid& g);
    Grid(vector<vector<Board>> b, int player, int depth, int size, int pos);
    Grid play(int x, int y);
    void set_player(int player);
    void set_pos(int pos);
    void display();
    int get_pos();
    int check();
    int get_size();
    vector<vector<Board>> get_grid();
    bool islegal(int x, int y);
    int get_player();
    void set_board(int x, Board d);
};
#endif //PROJECT1_GRID_H
