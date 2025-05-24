#include <iostream>

using namespace std;

char b[9] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
int m;

// creating necessary functions

void showBoard() {

    int i = 0;

    while(i<9){
        cout<<b[i]<<" ";
        if((i+1)%3 == 0){
            cout<<endl;
        }
        i++;
    }

}

void move() {

    cout << "Player " << player << "'s turn, enter move from (1-9): ";
    cin >> m;
    if (b[m-1] != 'X' && b[m-1] != 'O' && m<10 && m>0) b[m-1] = player;
    else {
        cout << "Invalid move! Try again please.\n";
        move();
    }
}

bool win() {     //checking all possible cases

    return (b[0] == b[1] && b[1] == b[2]) || (b[3] == b[4] && b[4] == b[5]) || (b[6] == b[7] && b[7] == b[8]) || 
           (b[0] == b[3] && b[3] == b[6]) || (b[1] == b[4] && b[4] == b[7]) || (b[2] == b[5] && b[5] == b[8]) ||
           (b[0] == b[4] && b[4] == b[8]) || (b[2] == b[4] && b[4] == b[6]);

}

bool draw() {     // checking if its an draw

    for (auto c: b) {
        if (c != 'X' && c != 'O') return false;
    }
    return true;

}

void switchplayer() {

    player = (player == 'X') ? 'O' : 'X';

}

void game(){         // main game function

    while (true) {
        showBoard();
        move();
        if (win()) {
            showBoard();
            cout << "Player " << player << " won!\n";
            break;
        }
        if (draw()) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }
        switchplayer();
    }

}

int main() {

    game();
    
    return 0;
}