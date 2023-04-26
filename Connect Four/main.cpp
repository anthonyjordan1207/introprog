#include "graphics.h"
using namespace mssm;

void startScreen(Graphics & g){
    Vec2d x {50,50};
    Vec2d y {25,16};
    while (g.draw()) {
g.cout << "Game takes some time to process, if you have 4, wait for the game to load"<< endl;
    g.text ({200,g.height()/2}, 50, "Hit the spacebar", WHITE);
            g.text ({275,g.height()/2 + 50}, 50, "to begin!", WHITE);

        if (g.isKeyPressed(' ')){
            return;
        }
    }
}
void drawboard (Graphics& g, vector<vector<int>> board){
    for(int i = 0; i < 7; i ++){
        g.rect(Vec2d{i*g.width()/7,0}, 15, g.height(), WHITE, WHITE);
    }
    g.rect(Vec2d{g.width() -5,0}, 15, g.height(), WHITE, WHITE);
    for(int i = 0; i < 6; i ++){
        g.rect(Vec2d{0, i*g.height()/6}, g.width(), 15, WHITE, WHITE);
    }
    g.rect(Vec2d{0,g.height()-5}, g.width(), 15, WHITE, WHITE);
    Color circleColor = TRANS;
    for (int r = 0; r < 6; r++){
        for (int c = 0; c < 7; c++){
            if(board[r][c] == 0){
                g.ellipse({(c+1)*100 - 43, (r+1)*100 - 43}, 70, 70, TRANS, TRANS);
            }
            else if (board[r][c] == 1){
                g.ellipse({(c+1)*100 - 43, (r+1)*100 - 43}, 70, 70, RED, RED);
            }
            else if (board[r][c] == 2){
                g.ellipse({(c+1)*100 - 43, (r+1)*100 - 43}, 70, 70, YELLOW, YELLOW);
            }
        }
    }
}
void end(Graphics & g, int player){
    Vec2d x {50,50};
    Vec2d y {25,16};
    while (g.draw()) {
    g.cout << "Player" << player << "Wins" << endl;
    }
}
int verticlestius(vector<vector<int>> board, int player, Graphics & g){
    for (int i = 0; i < board.size() - 3; i++){
        for (int j = 0; j < board[i].size() ; j++){
            if (board[i][j] == player &&
                    board[i][j] == board[i+1][j] &&
                    board[i+1][j] == board[i+2][j] &&
                    board[i+2][j] == board[i+3][j]){
              return 1;
            }
            }
        }
    return 0;
}
int horizonticlestius(vector<vector<int>> board, int player, Graphics & g){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size() - 3; j++){
        if (board[i][j] == player &&
                board[i][j] == board[i][j+1] &&
                board[i][j+1] == board[i][j+2] &&
                board[i][j+2] == board[i][j+3]){
            return 1;
        }
        }
    }
    return 0;
}
int diagonalupiclestius(vector<vector<int>> board, int player, Graphics & g){
    for (int i = 3; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
        if (board[i][j] == player &&
                board[i][j] == board[i-1][j+1] &&
                board[i-1][j+1] == board[i-2][j+2] &&
                board[i-2][j+2] == board[i-3][j+3] ){
            return 1;
        }
        }
    }
    return 0;
    }
int diagonaldowniclestius(vector<vector<int>> board, int player, Graphics & g){
    for (int i = 0; i < board.size() - 3; i++){
        for (int j = 0; j < board[i].size() - 3; j++){
        if (board[i][j] == player &&
                board[i][j] == board[i+1][j+1] &&
                board[i+1][j+1] == board[i+2][j+2] &&
                board[i+2][j+2] == board[i+3][j+3]){
            return 1;
        }
        }
    }
    return 0;
}
int main(int argc, char* argv[]){
    Graphics g("Hello Graphics!", 700, 600);
    vector<vector<int>> board (6, vector<int>(7));
    int player = 1;
    startScreen(g);
    while (g.draw()){
        drawboard(g, board);
        if (g.onMousePress(MouseButton::Left)==true){
            int row = 5;
            int column = (g.mousePos().x / 100);
            while (row>= 0 && board [row][column] != 0){
                row--;
            }
                if (row >= 0){
                    board [row][column] = player;
                }
                if (verticlestius(board,player,g) == 1){
                    end(g, player);
                }
                if (horizonticlestius(board,player,g) == 1){
                    end(g, player);
                }
                if (diagonalupiclestius(board,player,g) == 1){
                    end(g, player);
                }
                if (diagonaldowniclestius(board,player,g) == 1){
                    end(g, player);
                }

        if (player == 1){
            player = 2;
        }
        else {
            player = 1;
        }
        }
        }
}

