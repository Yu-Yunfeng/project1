//
// Created by yyf on 9/10/18.
//

#ifndef PROJECT1_BOARD_H
#define PROJECT1_BOARD_H

#include <vector>
#include <iostream>

using namespace std;


class Board{
private:
    vector<vector<int>> board;
    int player;
    int size;
    int depth;
//    double winrate1,winrate2;
    vector<Board*> children;
    Board* next;

public:
    Board();
    Board(vector<vector<int>> board, int size , int player , int depth );
    Board(const Board* &b);
    Board(const Board& b);
    void clear();
    vector<vector<int>> get_board();
    ~ Board();
    int get_player();
    void displayboard();
    Board play(int i);
    int check();
//    void generateallstates();
//    void calwinrate();
    int get_winrate1();
    int get_winrate2();
    vector<Board*> get_children();
//    Board* minimax();
//    double maxvalue();
//    double minvalue();
    double heuristic();
    int get_size();
    Board* get_next();
    void set_next(Board* next);
    void add_child(Board* child);
    int get_depth();
    void set_player(int p);
    Board play(int pos, int player);
};

#endif //PROJECT1_BOARD_H

