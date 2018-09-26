//
// Created by yyf on 9/20/18.
//

#include "Player.h"
#include <queue>
#include <ctime>

Player::Player() {
    this->depth = 6;
    this->board = Board();
}

double Player::minvalue(Board board, double alpha, double beta,int depth) {
    double a = alpha;
    double b = beta;
    Board best;
    if(board.check() != 0 || depth == 0){
        return this->heuristic(board);
    }
    double v = double(INT_MAX);
//    for (int i = 0; i < board.get_size(); ++i) {
        bool br = 0;
        for (int k = 0; k < board.get_size()*board.get_size(); ++k) {
            int i = k/board.get_size();
            int j = k%board.get_size();
            if(board.get_board()[i][j] == 0){
                Board tmp = Board(board.play(k));
                double v_minimax = minimax(tmp,a,b,depth-1);
                if (v_minimax < v){
                    best = tmp;
                    v = v_minimax;
                }
                if (v<a) {
//                    br = 1;
                    break;
                }
                b = min(v,b);
            }
        }
//        if (br) break;
//    }
    this->next = new Board(best);
    return v;
}

double Player::maxvalue(Board board, double alpha, double beta, int depth) {
    double a = alpha;
    double b = beta;
    Board best;
    if(board.check() != 0 || depth == 0){
        return this->heuristic(board);
    }
    double v = double(INT_MIN);
//    for (int i = 0; i < board.get_size(); ++i) {
//        bool br = 0;
        for (int k = 0; k < board.get_size()*board.get_size(); ++k) {
            int i = k/board.get_size();
            int j = k%board.get_size();
            if(board.get_board()[i][j] == 0){
                Board tmp = Board(board.play(k));
                double v_minimax = minimax(tmp,a,b,depth-1);
                if (v_minimax > v){
                    v = v_minimax;
                    best = tmp;

                }
                if (v>b) {
//                    br = 1;
                    break;

                }
                a = max(v,a);
            }

        }
//        if(br) break;
//    }
    this->next = new Board(best);
    return v;
}

double Player::minimax(Board board, double alpha, double beta, int depth) {
    if(this->player_number == board.get_player()) return maxvalue(board,alpha,beta,depth);
    else return minvalue(board,alpha,beta,depth);
}

void Player::flash(Board board) {
    /*
    Board* b = this->board;
    queue<Board*> q;
    q.push(b);
    while(!q.empty()){
        Board* tmp = q.front();
        q.pop();
        for (int i = 0; i < tmp->get_children().size(); ++i) {
            q.push(tmp->get_children()[i]);
        }
        delete tmp;
    }
    this->board = board;
    this->depth = 6;
    */
    if(this->next) delete this->next;
    this->board = board;
    this->depth = 6;
}

Board* Player::get_next() {
//    clock_t begin;
    this->minimax(this->board,-100,100,1000);
//    cout<<double(clock()-begin)/1000.0<<endl;
    return this->next;
//    return this->next_state();
}

Player::Player(int playnum, int depth, Board board) {
    this->player_number = playnum;
    this->depth = depth;
    this->board = board;
}

void Player::set_board(Board b) {
    this->board = b;
    this->depth = 6;
}

Board *Player::next_state() {
    return this->next;
}

void Player::set_next(Board* next) {
    this->next = next;
}

double Player::heuristic(Board b) {
    if (b.check() == -1) return 0;
    if (b.check() != this->player_number) return -1;
    if (b.check() == this->player_number) return 1;
}

double Player::minvalue(Grid grid, double alpha, double beta, int depth) {
    double a = alpha;
    double b = beta;
    Grid best;
    if(grid.check() != 0 || depth == 0){
        return this->heuristic(grid);
    }
    double v = double(INT_MAX);
    int grid_size = grid.get_size();
    int board_size = grid.get_grid()[0][0].get_size();
    for (int i = 0; i < grid_size*grid_size; ++i) {
        int grid_row = i/grid_size;
        int grid_col = i/grid_size;
        bool br = 0;
        for (int j = 0; j < board_size*board_size; ++j) {
            int board_row = j/board_size;
            int board_col = j%board_size;
            if(grid.islegal(i,j)){
                Grid tmp = Grid(grid.play(i,j));
                double v_minimax = minimax(tmp,a,b,depth-1);
                if (v_minimax < v){
                    best = tmp;
                    v = v_minimax;
                }
                if (v<a) {
                        br = 1;
                    break;
                }
                b = min(v,b);
            }
        }
        if (br) break;
    }
//    if(this->next_grid != NULL) delete(this->next_grid);
    this->next_grid = new Grid(best);
    return v;
}

double Player::maxvalue(Grid grid, double alpha, double beta, int depth) {
    double a = alpha;
    double b = beta;
    Grid best;
    if(grid.check() != 0 || depth == 0){
        return this->heuristic(grid);
    }
    double v = double(INT_MIN);
    int grid_size = grid.get_size();
    int board_size = grid.get_grid()[0][0].get_size();
    for (int i = 0; i < grid_size*grid_size; ++i) {
        int grid_row = i/grid_size;
        int grid_col = i/grid_size;
        bool br = 0;
        for (int j = 0; j < board_size*board_size; ++j) {
            int board_row = j/board_size;
            int board_col = j%board_size;
            if(grid.islegal(i,j)){
                Grid tmp = Grid(grid.play(i,j));
                double v_minimax = minimax(tmp,a,b,depth-1);
                if (v_minimax > v){
                    best = tmp;
                    v = v_minimax;
                }
                if (v>b) {
                    br = 1;
                    break;
                }
                b = min(v,b);
            }
        }
        if (br) break;
    }
//    if(this->next_grid != NULL) delete(this->next_grid);
    this->next_grid = new Grid(best);
    return v;
}

double Player::minimax(Grid g, double alpha, double beta, int depth) {
    if(this->player_number == g.get_player()) return maxvalue(g,INT_MIN,INT_MAX,depth);
    else return minvalue(g,INT_MIN,INT_MAX,depth);
}

double Player::heuristic(Grid g) {
    return 1;
}

Player::Player(int playnum, int depth, Grid grid) {
    this->player_number = playnum;
    this->depth = depth;
    this->grid = grid;
}

Grid *Player::get_next_grid() {
    return this->next_grid;
}

void Player::set_grid(Grid g) {
    this->grid = g;
}



