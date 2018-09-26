//
// Created by yyf on 9/24/18.
//

#include "Grid.h"

Grid::Grid() {
    this->size = 3;
    this->player = 1;
    this->pos = -1;
    this->depth = 100;
    grid = vector<vector<Board>> (this->size,vector<Board>(Board().get_size(),Board()));
}
/*
Grid::Grid(Grid &g) {
    this->grid = g.grid;
    this->depth = g.depth;
    this->size = g.size;
    this->player = g.player;
    this->pos = g.pos;
}
*/
Grid::Grid(vector<vector<Board>> b, int player, int depth, int size, int pos) {
    this->grid = b;
    this->player = player;
    this->depth = depth;
    this->size = size;
    this->pos = pos;
}
/*
Grid Grid::play(int x, int y) {
    int grid_row = x/this->size;
    int grid_col = x%this->size;
    Board b = this->grid[grid_row][grid_col];
    int board_row = y/b.get_size();
    int board_col = y/b.get_size();
    Grid tmp = Grid(this->get_grid(),2-this->get_player()/2,6,3,this->get_pos());
    tmp.set_player(2-this->player/2);
    tmp.set_pos(y);
    if(this->pos == -1){
        tmp.grid[grid_row][grid_col] = b.play(y,this->player);
        return tmp;
    }
    else{
        if(x != this->pos){
            if (this->grid[grid_row][grid_col].check() == 0){
                cout<<"it's not allowed"<<endl;
                return *this;
            }
            else{
                if(b.get_board()[board_row][board_col] != 0){
                    cout<<"it's not allowed"<<endl;
                    return *this;
                }
                else{
                    tmp.grid[grid_row][grid_col] = b.play(y,this->player);
                    return tmp;
                }
            }
        }
        else{
            if(b.get_board()[board_row][board_col] != 0){
                cout<<"it's not allowed"<<endl;
                return *this;
            }
            else{
                tmp.grid[grid_row][grid_col] = b.play(y,this->player);
                return tmp;
            }
        }
    }
}
*/

Grid Grid::play(int x, int y) {
    if(!this->islegal(x,y)) return *this;
    else{
        Grid tmp = *this;
        tmp.set_player(2-this->player/2);
        Board b = this->get_grid()[x/3][x%3];
        b = b.play(y,this->player);
        tmp.set_board(x,b);
        tmp.set_pos(y);
        return tmp;
    }
}

void Grid::set_player(int player) {
    this->player = player;
}

void Grid::set_pos(int pos) {
    this->pos = pos;
}

void Grid::display() {
    for (int i = 0; i < 9; ++i) {
        int grid_row = i/3;
        int board_row = i%3;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout<<this->grid[grid_row][j].get_board()[board_row][k]<<" ";
            }
            cout<<" ";
        }
//        cout<<" ";
        cout<<endl;
        if(i%3 ==2 ) cout<<endl;
    }
}

int Grid::get_pos() {
    return this->pos;
}

int Grid::check() {
    return 0;
}

int Grid::get_size() {
    return this->size;
}

vector<vector<Board>> Grid::get_grid() {
    return this->grid;
}

bool Grid::islegal(int x, int y) {
    if(this->pos == -1) return true;
    int grid_row = x/3;
    int grid_col = x%3;
    int board_row = y/3;
    int board_col = y%3;
    int pos = this->pos;
    Board b = this->grid[grid_row][grid_col];
    Board b_ori = this->grid[pos/3][pos%3];
    if(x != this->pos){
        if(b_ori.check() == 0) return false;
        else{
            if(b.get_board()[board_row][board_col] == 0) return true;
            else return false;
        }

    }

    if(x == this->pos){
        if(b.get_board()[board_row][board_col] == 0) return true;
        else return false;
    }

}

int Grid::get_player() {
    return this->player;
}

void Grid::set_board(int x, Board d) {
    this->grid[x/3][x%3] = d;
}



