#include "graphics.h"

using namespace std;
using namespace mssm;

Graphics g("Hello Graphics!", 1024, 768);

Vec2d position{g.width()/2,g.height()/2,};

Vec2d velocity{7, 2.5};

int score = 0;
int score2 = 0;

int y = g.height()/2-60;

int y2 = g.height()/2-60;

void playScreen(Graphics & g){
    while (g.draw()) {

        if (g.isKeyPressed(' ')){
            velocity = {7, 2.5};
        }
        if (g.isKeyPressed('w')){
            y = y - 5;
        }
        if (g.isKeyPressed('s')){
            y = y + 5;
        }
        if (position.y > y2){
            y2 = y2 + 5;
        }
        if (position.y < y2){
            y2 = y2 - 5;
        }
        Vec2d position2{0,y};
        Vec2d position3{g.width() - 20,y2};

        if (position2.y + 120 > g.height()) {
            y = y - 5;

        }
        if (position2.y < 0) {
            y = y + 5;
        }
        if (position3.y + 120 > g.height()) {
            y2 = y2 - 5;

        }
        if (position3.y < 0) {
            y2 = y2 + 5;
        }

        Vec2d p1{20,40};

        Vec2d p2;

        p2.x = 500;
        p2.y = 20;

        g.rect  (position2, 20, 120, WHITE, WHITE);
        g.rect  (position3, 20, 120, WHITE, WHITE);
        g.ellipse(position, 30, 30, WHITE, WHITE);

        position = position + velocity;

        if (position.x > g.width()){
            position = {g.width()/2,g.height()/2,};
            velocity = {0,0};
            score = score + 1;

        }

        if (position.x < 0){
            position = {g.width()/2,g.height()/2,};
            velocity = {0,0};
            score2 = score2 +1;
        }
        if (position.y > g.height() - 15 || position.y < 15) {

            velocity.y = - velocity.y;
            velocity = velocity * 1.04;
        }
        if (position.x > position2.x && position.x < position2.x + 20 && position.y > position2.y && position.y < position2.y + 120){
            velocity.x = - velocity.x;
            velocity = velocity * 1.04;
        }
        if (position.x > position3.x && position.x < position3.x + 20 && position.y > position3.y && position.y < position3.y + 120){
            velocity.x = - velocity.x;
            velocity = velocity * 1.04;
        }
        if (velocity.x == 0){
            g.cout << "                                                                                               " << score << "   |   " << score2 << endl;
            g.cout << "                                                                              Press Spacebar to Restart" << endl;
        }
        if (score == 10){
            Vec2d x {50,50};
            Vec2d y {25,16};
            while (g.draw()) {

        x = x + y;

                g.ellipse(x, 30, 30, WHITE, WHITE);

                if (x.x > g.width() - 15 || x.x < 15) {

                    y.x = - y.x;
                }
                if (x.y > g.height() - 15 || x.y < 15) {

                    y.y = - y.y;
                }
                    g.text ({60,g.height()/2}, 100, "WINNER WINNER", WHITE);
                    g.text ({60,g.height()/2 + 175}, 100, "CHICKEN DINNER!", WHITE);
                    g.cout << "                                                                           Press Spacebar to Quit" << endl;

                if (g.isKeyPressed(' ')){
                    return;
                }
            }
        }
        if (score2 == 10){
            Vec2d x {50,50};
            Vec2d y {25,16};
            while (g.draw()) {

        x = x + y;

                g.ellipse(x, 30, 30, WHITE, WHITE);

                if (x.x > g.width() - 15 || x.x < 15) {

                    y.x = - y.x;
                }
                if (x.y > g.height() - 15 || x.y < 15) {

                    y.y = - y.y;
                }
                    g.text ({210,g.height()/2}, 125, "YOU LOST!", WHITE);

                    g.cout << "                                                                           Press Spacebar to Quit" << endl;

                if (g.isKeyPressed(' ')){
                    return;
                }
        }
    }
}}
void startScreen(Graphics & g){
    Vec2d x {50,50};
    Vec2d y {25,16};
    while (g.draw()) {

x = x + y;

        g.ellipse(x, 30, 30, WHITE, WHITE);

        if (x.x > g.width() - 15 || x.x < 15) {

            y.x = - y.x;
        }
        if (x.y > g.height() - 15 || x.y < 15) {

            y.y = - y.y;
        }
            g.text ({60,g.height()/2}, 125, "Hit the spacebar", WHITE);
            g.text ({275,g.height()/2 + 175}, 125, "to begin!", WHITE);

        if (g.isKeyPressed(' ')){
            return;
        }
    }
}

int main(int argc, char* argv[])
{

    startScreen(g);
    playScreen(g);

}


