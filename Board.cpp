//
// Created by yyf on 9/10/18.
//

#include "Board.h"
#include <queue>

Board::Board() {
    this->player=1;
    this->size=3;
    this->board=vector<vector<int>> (this->size,vector<int> (this->size,0));
//    this->winrate1 = 0.0;
//    this->winrate2 = 0.0;
//    this->depth = INT_MAX;
}

//player is the one to play
Board::Board(vector<vector<int>> board, int size = 3, int player = 1, int depth = INT_MAX) {
    this->player=player;
    this->board=board;
    this->size=size;
//    this->winrate1 = 0.0;
//    this->winrate2 = 0.0;
    this->depth = depth;
}

vector<vector<int>> Board::get_board(){
    return this->board;
}

int Board::get_player() {
    return this->player;
}

void Board::displayboard() {
    cout<<endl;
    for(int i = 0; i < this->size; ++i){
        for (int j = 0; j < this->size; ++j) {
            cout<<this->board[i][j]<<"  ";
        }
        cout<<endl<<endl;
    }
    cout<<endl;
}

Board Board::play(int i) {
    int x = (i)/this->size;
    int y = (i)%this->size;
    if(this->board[x][y] != 0) {
        cout<<"It's not allowed"<<endl;
        return *this;
    }
    else{
        Board temp = Board(this->board,this->size,this->player%2+1,this->depth-1);

        temp.board[x][y] = this->player;
        return (temp);
    }
}

//-1:tie; 0:continue; 1:player1 wins; 2:player2 wins
int Board::check() {
    for(int i = 0; i < this->size; i++) {
        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0) {
            int winner = 2 - this->player / 2;
            /*
            if(winner == 1) {
                this->winrate1 = 1.0;
                this->winrate2 = 0.0;
            }
            else{
                this->winrate1 = 0.0;
                this->winrate2 = 1.0;
            }
             */
            return winner;
        }
    }
    for(int i = 0; i < this->size; i++){
        if(this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0) {
            int winner = 2 - this->player / 2;
            /*
            if(winner == 1) {
                this->winrate1 = 1.0;
                this->winrate2 = 0.0;
            }
            else{
                this->winrate1 = 0.0;
                this->winrate2 = 1.0;
            }
             */
            return winner;
        }
    }
    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[1][1] != 0) {
        int winner = 2 - this->player / 2;
        /*
        if(winner == 1) {
            this->winrate1 = 1.0;
            this->winrate2 = 0.0;
        }
        else{
            this->winrate1 = 0.0;
            this->winrate2 = 1.0;
        }
         */
        return winner;
    }
    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[1][1] != 0) {
        int winner = 2 - this->player / 2;
        /*
        if(winner == 1) {
            this->winrate1 = 1.0;
            this->winrate2 = 0.0;
        }
        else{
            this->winrate1 = 0.0;
            this->winrate2 = 1.0;
        }
         */
        return winner;
    }
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size; j++){
            if(this->board[i][j] == 0) return 0;
        }
    }
    return -1;
}
/*
void Board::generateallstates() {
    if(this->depth == 0) return;
    if(this->check() == 0){
        for (int i = 0; i < this->size; ++i) {
            for (int j = 0; j < this->size; ++j) {
                if(this->board[i][j] == 0){
//                    Board* b = new (this->play(i,j)); //may cause problem
                    Board tmp = this->play(i,j);
                    Board* b = new Board(tmp.get_board(),this->size,tmp.get_player(),this->depth-1);
                    if(b->board == this->board && b->player == this->player) continue;
                    else {
                        b->generateallstates();
//                        b.displayboard();
//                        cout<<"................"<<endl;
                        this->children.push_back(b);
                    }
                }
            }
        }
    }
    return;
}
*/
/*
void Board::calwinrate() {
    if(this->check() == 1){
        this->winrate1 = 1.0;
        this->winrate2 = -1.0;
    }
    if(this->check() == 2){
        this->winrate1 = -1.0;
        this->winrate2 = 1.0;
    }
    if(this->check() == -1){
        this->winrate1 = 0.0;
        this->winrate2 = 0.0;
    }
    if(this->check() == 0){
        for (int i = 0; i < this->children.size(); ++i) {
            this->children[i]->calwinrate();
        }
        for (int i = 0; i < this->children.size(); ++i) {
            this->winrate1 += this->children[i]->winrate1;
            this->winrate2 += this->children[i]->winrate2;
        }
    }
}
*/
/*
int Board::get_winrate1() {
    return this->winrate1;
}

int Board::get_winrate2() {
    return this->winrate2;
}
*/
vector<Board*> Board::get_children() {
    return this->children;
}
/*
Board* Board::minimax() {
    Board* res;
    double maxnum = double(INT_MIN);
    for (int i = 0; i < this->get_children().size(); ++i) {
        Board* child = this->get_children()[i];
        if(maxnum < child->minvalue()){
            maxnum = child->minvalue();
            res = child;
        }
    }
    return res;
}
*/
Board::~Board() {
    /*
    queue<Board*> q;
    for (int i = 0; i < this->get_children().size(); ++i) {
        q.push(this->get_children()[i]);
    }
    while(!q.empty()){
        Board* tmp = q.back();
        q.pop();
        for (int i = 0; i < tmp->get_children().size(); ++i) {
            q.push(tmp->get_children()[i]);
        }
        delete tmp;
    }
     */
}
/*
double Board::minvalue() {
    if(this->check() != 0 ||this->depth == 0){
        return this->heuristic();
    }
    else{
        double v = double(INT_MAX);
        for (int i = 0; i < this->get_children().size(); ++i) {
            Board* child = this->get_children()[i];
            v = min(child->maxvalue(),v);
        }
        return v;
    }

}

double Board::maxvalue() {
    if(this->check() != 0 || this->depth == 0){
        return this->heuristic();
    }
    else{
        double v = double(INT_MIN);
        for (int i = 0; i < this->get_children().size(); ++i) {
            Board* child = this->get_children()[i];
            v = max(child->minvalue(),v);
        }
        return v;
    }
}
*/
double Board::heuristic() {
    if(this->check() == -1) return 0;
/*
    if(this->check() != 0 && (this->check() != this->player)) return 1;
    if(this->check() != 0 && (this->check() == this->player)) return -1;
*/
    if (this->check() == 1) return 1;
    if (this->check() == 2) return -1;

}

int Board::get_size() {
    return this->size;
}

Board *Board::get_next() {
    return this->next;
}

void Board::set_next(Board *next) {
    this->next = next;
}

void Board::add_child(Board *child) {
    this->children.push_back(child);
}

Board::Board(const Board*& b) {
    this->board = b->board;
    this->children = b->children;
    this->depth = b->depth;
    this->player = b->player;
    this->size = b->size;
}

int Board::get_depth() {
    return this->depth;
}

Board::Board(const Board& b) {
    this->board = b.board;
    this->children = b.children;
    this->depth = b.depth;
    this->player = b.player;
    this->size = b.size;
}

void Board::clear() {
    queue<Board*> q;
    for (int i = 0; i < this->get_children().size(); ++i) {
        q.push(this->get_children()[i]);
    }
    while(!q.empty()){
        Board* tmp = q.back();
        q.pop();
        for (int i = 0; i < tmp->get_children().size(); ++i) {
            q.push(tmp->get_children()[i]);
        }
        delete tmp;
    }
}

void Board::set_player(int p) {
    this->player= p ;
}

Board Board::play(int pos, int player) {
    Board tmp = this->play(pos);
//    if(tmp == *this) return *this;
    tmp.board[pos/this->size][pos%this->size] = player;
    return tmp;
}

