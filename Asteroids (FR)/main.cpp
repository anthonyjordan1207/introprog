#include "graphics.h"
using namespace std;
using namespace mssm;


class Ship {
public:
    Vec2d position;
    Vec2d velocity;
    Color border;
    Color fill;
    double angle;
    double angleV;
    Vec2d accelconst;

    void draw(Graphics& g);

    void update(Graphics& g);
};

class Asteroid {
public:
    Vec2d position;
    Vec2d velocity;
    Color border;
    Color fill;
    double angle;
    double angleV;
    int scale;

    void draw(Graphics& g);

    void update(Graphics& g);
};

class Bullets {
public:
    Vec2d position;
    Vec2d velocity;
    double angle;

    void draw(Graphics& g);

    void update (Graphics& g);
};

void Ship::draw(Graphics& g)
{
    vector<Vec2d> points{ {10, 0}, {-10, 15}, {-3, 0}, {-10,-15}};

    for (int i = 0; i < points.size(); i++) {
        points[i].rotate(angle);
        points[i] = points[i] + position;
    }
    g.polygon(points, border, fill);
}

void Ship::update(Graphics& g )
{     
    position = position + velocity;

    velocity = velocity + accelconst;

    angle = angle + angleV;

    if (g.isKeyPressed(Key::Up) == true) {
        accelconst = {0.05 * cos(angle), 0.05 * sin(angle)};
    }
    else {
        accelconst = {0,0};
    }
    if (g.isKeyPressed(Key::Left) == true){
        angleV = -.05;
    }
    else if (g.isKeyPressed(Key::Right) == true){
        angleV = .05;
    }
    else {
        angleV = 0;
    }
    if (position.x > g.width()) {
        position.x = 0;
    }
    if (position.x < 0) {
        position.x = g.width();
    }
    if (position.y > g.height()) {
        position.y = 0;
    }
    if (position.y < 0) {
        position.y = g.height();
    }
}

void Asteroid::draw(Graphics& g)
{
    vector<Vec2d> points{ {5, 5}, {5, -5}, {-5, -5}, {-5,5}};

    for (int i = 0; i < points.size(); i++) {
        points[i].rotate (angle);
        points[i] = points[i] * scale;
        points[i] = points[i] + position;
    }
    g.polygon(points, border, fill);
}

void Asteroid::update(Graphics& g )
{
    position = position + velocity;

    angle = angle + angleV;

    if (position.x > g.width()) {
        position.x = 0;
    }
    if (position.x < 0) {
        position.x = g.width();
    }
    if (position.y > g.height()) {
        position.y = 0;
    }
    if (position.y < 0) {
        position.y = g.height();
    }
}

void Bullets::draw(Graphics& g)
{
    Color neonGreen (68,214,44);

    vector<Vec2d> points{ {-6, 0}, {0, 0}, {0, 6}, {-6,6}};

    for (int i = 0; i < points.size(); i++) {
        points[i] = points[i] + position;
    }

    g.polygon(points, neonGreen,neonGreen );
}
void Bullets::update(Graphics& g )
{
    position = position + velocity;

}

void end (Graphics& g, int score){
    Vec2d x {50,50};
    Vec2d y {25,16};
    while (g.draw()) {
        g.text ({400,400}, 50, "You Lose :(", WHITE);
        g.text ({350,500}, 50, "You Scored: " + to_string (score), WHITE);
    }
}

void start (Graphics& g){
    while (g.draw()) {
        g.text ({250,100}, 50, "HIT SPACE TO START", WHITE);
        if (g.onKeyPress(Key::Space)){
            break;
        }
}
}

int main(int argc, char *argv[])
{
    Graphics g("Asteroids!", 1024, 768);

    Ship ship;

    vector<Bullets> bullets;

    ship.angle = 0;
    ship.velocity = {0,0};
    ship.position = {100,100};
    ship.border = BLUE;
    ship.fill =  ship.border;
vector<Asteroid> asteroids;
    int lives = 3;
    double invincibleTime = 3000;
    int score = 0;
    start(g);
    while(g.draw()) {

        if (asteroids.size() == 0){

        for (int i = 0; i < 7; i++){
            Asteroid asteroid;
            asteroid.scale = 4;
            asteroid.position = {g.randomDouble(30, g.width()-30),g.randomDouble(30, g.height()-30)};
            asteroid.velocity = {g.randomDouble(-2,2),g.randomDouble(-2,2)};
            asteroid.border = WHITE;
            asteroid.fill = asteroid.border;
            asteroid.angleV = {g.randomDouble(-.05, .05)};
            asteroid.angle = {g.randomDouble(-6,6)};
            asteroids.push_back(asteroid);

}
            invincibleTime = 3000;
        }
        if (invincibleTime > 0){
            ship.border = WHITE;
            invincibleTime = invincibleTime - g.elapsedMs();
        }
        else {
            ship.border = ship.fill;
        }
        int x = 0;
        if (g.onKeyPress(Key::Space) == true){
            x = x + 1;
        }
        for (int i = 0; i < x; i++){
            Bullets pewpews;
            pewpews.position = ship.position;
            pewpews.angle = ship.angle;
            pewpews.velocity = {20 * cos(pewpews.angle), 20 * sin(pewpews.angle)};;
            bullets.push_back(pewpews);

        }

        for (int i = 0; i < asteroids.size(); i++){
            Vec2d distance = ship.position - asteroids[i].position;
            if (distance.magnitude() < 40 && invincibleTime <= 0){
                lives = lives - 1;
                invincibleTime = 3000;
            }
        }

        for (int i = 0; i < asteroids.size(); i++){
            for (int j = 0; j < bullets.size(); j++){
                Vec2d distance = bullets[j].position - asteroids[i].position;
                if (distance.magnitude() < 40){
                    bullets.erase(bullets.begin()+j);
                    if (asteroids[i].scale <= 2){
                        asteroids.erase(asteroids.begin()+i);
                        score = score + 1;
                    }
                    Asteroid lilRock;
                    Asteroid otherLilRock;
                    lilRock.position = asteroids[i].position;
                    otherLilRock.position = asteroids[i].position;
                    lilRock.border = asteroids[i].border;
                    otherLilRock.border = asteroids[i].border;
                    lilRock.fill = asteroids[i].fill;
                    otherLilRock.fill = asteroids[i].fill;
                    lilRock.velocity = asteroids[i].velocity.rotated(1.08);
                    otherLilRock.velocity = asteroids[i].velocity.rotated(-1.08);
                    lilRock.angle = asteroids[i].angle;
                    otherLilRock.angle = asteroids[i].angle * -1;
                    lilRock.scale = asteroids[i].scale - 1;
                    otherLilRock.scale = asteroids[i].scale - 1;
                    asteroids.push_back(lilRock);
                    asteroids.push_back(otherLilRock);
                    asteroids.erase(asteroids.begin() + i);
                    if (asteroids[i].scale <= 2){
                        asteroids.erase(asteroids.begin()+i);
                        score = score + 1;
                    }
                }
            }
        }
        ship.draw(g);
        ship.update(g);

        for (int i = 0; i < asteroids.size(); i++){
            asteroids[i].draw(g);
            asteroids[i].update(g);

        }
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].draw(g);
            bullets[i].update(g);
            if (bullets[i].position.x > g.width() || bullets[i].position.x < 0 || bullets[i].position.y > g.height() || bullets[i].position.y < 0){
                bullets.erase(bullets.begin()+i);
            }

        }
        g.cout << "Score: " << score << "     " << "Lives: " << lives << endl;
        if (lives == 0){
            end(g, score);
        }
    }
}
