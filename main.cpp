#include <iostream>
#include <vector>
#include "Board.h"
#include "Player.h"
#include <ctime>
#include "Grid.h"
using namespace std;




int main() {

    Grid g;
    g.display();
    Player player1 = Player(1,6,g);
    while(1){
        player1.minimax(g,-10000,10000,6);
        Grid* g1 = player1.get_next_grid();
        g1->display();
        int x,y;
        cin>>x>>y;
        Grid g2 = g1->play(--x,--y);
        g2.display();
        g = g2;
        player1.set_grid(g2);
    }
    /*
    int x,y;
    while(1){
        cin>>x>>y;
        Grid a = g.play(--x,--y);
        a.display();
        cout<<a.get_pos()<<endl;
        g = a;
    }
     */

/*
    Board* b0 = new Board();
//    b0->set_player(2);
    Board b = Board(b0->play(0,0));
    Board* b1;
    Player p1 = Player(1,12, b);
    int x,i,j;

    while(1){
        clock_t begin = clock();
        b1 = p1.get_next();
        clock_t end = clock();
        cout<<double(end-begin)/CLOCKS_PER_SEC<<endl;
        b1->displayboard();
        if(b1->check() != 0) break;
        Board b2 = Board(*b1);
        cin>>x;
        Board b3 = Board(b2.play(--x));
        b3.displayboard();
        if(b3.check() != 0) break;

        p1.set_board(b3);
    }
*/
}