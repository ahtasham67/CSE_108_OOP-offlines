#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

#define GRIDSIZE 4
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
#define MAX_SHOTS 3

/*string to_string(int x)
{
    std::string out_string;
    std::stringstream ss;
    ss << x;
    return ss.str();
}*/

class Position
{

    int x, y;

public:
    Position(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    Position() {}

    // Modify the following four so that the resulting position does not leave the grid
    void moveRight()
    {
        if (x >= 0 && x < GRIDSIZE - 1)
            x++;
        else
            cout << "Position cannot go beyond the grid" << endl;
    }

    void moveLeft()
    {
        if (x > 0 && x <= GRIDSIZE - 1)
            x--;
        else
            cout << "Position cannot go beyond the grid" << endl;
    }

    void moveUp()
    {
        if (y >= 0 && y < GRIDSIZE - 1)
            y++;
        else
            cout << "Position cannot go beyond the grid" << endl;
    }

    void moveDown()
    {
        if (y > 0 && y <= GRIDSIZE - 1)
            y--;
        else
            cout << "Position cannot go beyond the grid" << endl;
    }

    bool isAdjacent(Position p)
    {
        // implement the function
        if (abs(p.x - this->x) == 1)
        {
            if (abs(p.y - this->y) == 0)
            {
                return true;
            }
            else
                return false;
        }
        else if (abs(p.y - this->y) == 1)
        {
            if (abs(p.x - this->x) == 0)
            {
                return true;
            }
            else
                return false;
        }
        else
        return false;
    }

    bool isSamePoint(Position p)
    {
        // implement the function
        if (p.x == this->x && p.y == this->y)
            return true;
        else
            return false;
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
};

class Wumpus
{

    bool killed;
    Position p;

public:
    Wumpus(int x, int y)
    {
        p = Position(x, y);
        killed = false;
    }

    Wumpus()
    {
        //...
        killed = false;
        int X, Y;
        X = rand() % GRIDSIZE;
        if (X == 0)
        {
            Y = (rand() % (GRIDSIZE-1)) + 1;
        }
        else
            Y = rand() % GRIDSIZE;
        p = Position(X, Y);
    }

    void kill()
    {
        killed = true;
    }

    Position getPosition()
    {
        return p;
    }
    void setPositionOutOfGrid()
    {
        p = Position(-1, -1);
    }
};

class Player
{

    int direction;
    int total_shots;
    bool killed;
    Position p;

public:
    Player()
    {
        //...
        p = Position(0, 0);
        killed = false;
        direction = UP;
        total_shots = MAX_SHOTS;
    }

    void turnLeft()
    {
        //...
        if (direction == UP)
            direction = LEFT;
        else if (direction == LEFT)
            direction = DOWN;
        else if (direction == DOWN)
            direction = RIGHT;
        else if (direction == RIGHT)
            direction = UP;
    }

    void turnRight()
    {
        //...
        if (direction == UP)
            direction = RIGHT;
        else if (direction == RIGHT)
            direction = DOWN;
        else if (direction == DOWN)
            direction = LEFT;
        else if (direction == LEFT)
            direction = UP;
    }

    void moveForward()
    {
        //...
        if (direction == UP)
        {
            p.moveUp();
        }
        if (direction == RIGHT)
        {
            p.moveRight();
        }
        if (direction == LEFT)
        {
            p.moveLeft();
        }
        if (direction == DOWN)
        {
            p.moveDown();
        }
    }

    bool isAdjacent(Position pos)
    {
        return p.isAdjacent(pos);
    }

    bool isSamePoint(Position pos)
    {
        return p.isSamePoint(pos);
    }

    void kill()
    {
        killed = true;
    }

    string getPositionInfo()
    {
        return "Player is now at " + to_string(p.getX()) + ", " + to_string(p.getY());
    }

    string getDirectionInfo()
    {
        string s;
        if (direction == UP)
            s = "up";
        if (direction == DOWN)
            s = "down";
        if (direction == LEFT)
            s = "left";
        if (direction == RIGHT)
            s = "right";
        return "Player is moving at direction: " + s;
    }

    int getTotalShots()
    {
        return total_shots;
    }

    void reduceShots()
    {
        total_shots--;
    }

    Position getPosition()
    {
        return p;
    }

    int getDirection()
    {
        return direction;
    }
};

// cretaing pit class PART B

class Pit
{
    Position p;

public:
    Pit(int x, int y)
    {
        p = Position(x, y);
    }
    Pit()
    {
        int X, Y;
        X = rand() % GRIDSIZE;
        if (X == 0)
        {
            Y = (rand() % (GRIDSIZE-1)) + 1;
        }
        else
            Y = rand() % GRIDSIZE;
        p = Position(X, Y);
    }
    Position getPosition()
    {
        return p;
    }
};

class WumpusWorld
{

private:
    Player player;
    Wumpus wumpus;
    Pit pit;
    Position gold_position;
    bool ended;

public:
    WumpusWorld()
    {
        //...
        int X, Y;
        X = rand() % GRIDSIZE;
        if (X == 0)
        {
            Y = (rand() % (GRIDSIZE-1)) + 1;
        }
        else
            Y = rand() % GRIDSIZE;
        gold_position = Position(X, Y);
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y)
    {
        //...
        wumpus = Wumpus(wumpus_x, wumpus_y);
        gold_position = Position(gold_x, gold_y);
        ended = false;
    }

    WumpusWorld(int wumpus_x, int wumpus_y, int gold_x, int gold_y, int pit_x, int pit_y)
    {
        //...
        player = Player();
        wumpus = Wumpus(wumpus_x, wumpus_y);
        pit = Pit(pit_x, pit_y);
        gold_position = Position(gold_x, gold_y);
        ended = false;
    }

    void moveForward()
    {
        player.moveForward();
        return showGameState();
    }

    void turnLeft()
    {
        player.turnLeft();
        return showGameState();
    }

    void turnRight()
    {
        player.turnRight();
        return showGameState();
    }

    void shoot()
    {
        //...
        if (player.getTotalShots() <= 0)
        {
            cout << "You have used all your arrows!" << endl;
            return;
        }
        player.reduceShots();

        int playerX = player.getPosition().getX();
        int playerY = player.getPosition().getY();
        int wumpusX = wumpus.getPosition().getX();
        int wumpusY = wumpus.getPosition().getY();

        if (playerX != wumpusX && playerY != wumpusY)
        {
            cout << "Wumpus is in different line!" << endl;
            return;
        }

        if (playerX == wumpusX)
        {
            if (player.getDirection() == UP && playerY < wumpusY)
            {
                cout << "Wumpus killed!" << endl;
                wumpus.kill();
                wumpus.setPositionOutOfGrid();
                return;
            }
            else if (player.getDirection() == DOWN && playerY > wumpusY)
            {
                cout << "Wumpus killed!" << endl;
                wumpus.kill();
                wumpus.setPositionOutOfGrid();
                return;
            }
            else
            {
                cout << "wumpus is behind you!" << endl;
                return;
            }
        }
        if (playerY == wumpusY)
        {
            if (player.getDirection() == RIGHT && playerX < wumpusX)
            {
                cout << "Wumpus killed!" << endl;
                wumpus.kill();
                wumpus.setPositionOutOfGrid();
                return;
            }
            else if (player.getDirection() == LEFT && playerX > wumpusX)
            {
                cout << "Wumpus killed!" << endl;
                wumpus.kill();
                wumpus.setPositionOutOfGrid();
                return;
            }
            else
            {
                cout << "wumpus is behind you!" << endl;
                return;
            }
        }
    }

    void showGameState()
    {
        cout << player.getPositionInfo() << endl;
        cout << player.getDirectionInfo() << endl;

        if (player.isAdjacent(wumpus.getPosition()))
        {
            cout << "stench!" << endl;
        }

        if (player.isAdjacent(pit.getPosition()))
        {
            cout << "breeze!" << endl;
        }

        if (player.isSamePoint(wumpus.getPosition()))
        {
            cout << "Player is killed!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }
        if (player.isSamePoint(pit.getPosition()))
        {
            cout << "you will have to rot here forever!!" << endl;
            player.kill();
            cout << "Game over!" << endl;
            ended = true;
        }

        if (player.isSamePoint(gold_position))
        {
            cout << "Got the gold!" << endl;
            cout << "Game ended, you won!" << endl;
            ended = true;
        }
    }

    bool isOver()
    {
        return ended;
    }
};

int main()
{
    int c, wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y;
    // take the six integers input from file
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        cout << "ERROR" << endl;
    }
    fscanf(file, "%d %d %d %d %d %d", &wumpus_x, &wumpus_y, &gold_x, &gold_y, &pit_x, &pit_y);
    //cin >> wumpus_x >> wumpus_y >> gold_x >> gold_y >> pit_x >> pit_y;
    WumpusWorld w(wumpus_x, wumpus_y, gold_x, gold_y, pit_x, pit_y);
    w.showGameState();
    while (!w.isOver())
    {
        cout << "1: move forward" << endl;
        cout << "2: Turn left" << endl;
        cout << "3: Turn right" << endl;
        cout << "4: Shoot" << endl;
        cin >> c;
        if (c == 1)
        {
            w.moveForward();
        }
        else if (c == 2)
        {
            w.turnLeft();
        }
        else if (c == 3)
        {
            w.turnRight();
        }
        else if (c == 4)
        {
            w.shoot();
        }
    }
    fclose(file);
    return 0;
}
