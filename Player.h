//
// Created by yyf on 9/20/18.
//

#ifndef PROJECT1_PLAYER_H
#define PROJECT1_PLAYER_H

#include <iostream>
#include "Board.h"
#include "Grid.h"
using namespace std;

class Player{
private:
    int depth;
    int player_number;
    double alpha;
    double beta;
    Board board;
    Board* next;
    Grid* next_grid;
public:
    Player();
    Player(int playnum, int depth, Board board);
    double minvalue(Board board, double alpha, double beta, int depth);
    double maxvalue(Board board, double alpha, double beta, int depth);
    double minimax(Board board, double alpha, double beta, int depth);
    void flash(Board board);
    Board* get_next();
    Board* next_state();
    void set_next(Board* next);
    void set_board(Board b);
    double heuristic(Board b);
    double heuristic(Grid g);
    double minvalue(Grid grid, double alpha, double beta, int depth);
    double maxvalue(Grid grid, double alpha, double beta, int depth);
    double minimax(Grid g, double alpha, double beta, int depth);
};




#endif //PROJECT1_PLAYER_H
