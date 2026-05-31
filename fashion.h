#include <cstdlib>
#include <ctime>
using namespace std;
#include <vector>
#include <iostream>

class Tile //declaro mi calse de casillas
{
    protected:
        int position;
        char type;

    public:
        Tile(int pos, char t)
        {
            position = pos;
            type = t;
        }

        char getType()
        {
            return type;
        }

        virtual int applyEffect(int currentPosition)
        {
            return currentPosition;
        }
};

class NormalTile : public Tile //el tipo N hereda lo que todas las casillas tienen
{
    public:
        NormalTile(int pos) : Tile(pos, 'N') {}
};

class AdvanceTile: public Tile
{
    public:
        AdvanceTile(int pos) : Tile(pos, 'L') {}

        int applyEffect(int currentPosition)
        {
            return currentPosition + 4;
        }
};


class SetbackTile : public Tile
{
    public:
        SetbackTile(int pos) : Tile(pos, 'S') {}

        int applyEffect(int currentPosition)
        {
            return currentPosition - 3;
        }
};

class Dice
{
    private:
        bool seeded;
    public:
        Dice()
        {
            seeded = false;
        }
        int roll()
        {
            if(!seeded)
            {
                srand(time(0));
                seeded = true;
            }
            return rand() % 6 + 1;
        }
};

class Player
{
    private:
        int id;
        int position;
    public:
        Player(int i)
        {
            id = i;
            position = 1;
        }

        int getPosition()
        {
            return position;
        }

        void setPosition(int pos)
        {
            position = pos;
        }

        int getId()
        {
            return id;
        }
};

class Board
{
    private:
        vector<Tile*> tiles; //un puntero que me dice en donde hay un Tile
    public:
        Board()
        {
            for(int i = 1; i <= 30; i++)
            {
                if (i == 6 || i == 12 || i == 18)
                {
                    tiles.push_back(new SetbackTile(i)); // push_back agrega el elemento al final del vector
                }
                else if (i == 9 || i == 15 || i == 21)
                {
                    tiles.push_back(new AdvanceTile(i));
                }
                else
                {
                    tiles.push_back(new NormalTile(i));
                }
            }
        }

        Tile * getTile(int position)
        {
            return tiles[position -1];
        }
        

};

class MyGame
{
    private: //estoy creando las partes de mi juego, decir lo que tengo como objeto
        Board board; //declarando que voy a tener tablero con base a mi clase ya creada
        Player p1; //declarando que voy a tener jugador 1 con base a mi clase ya creada
        Player p2; //declarando que voy a tener jugador 2 con base a mi clase ya creada
        Dice dice; //declarando que voy a tener un dado con base a mi clase ya creada
    public:
        MyGame() : p1(1), p2(2) {}

        void start()
        {
            char option;
            int turn = 1;

            while(true)
            {
                cout << "Welcome to the Fashion Game World Competition!! \n";
                cout << "Press C to continue next turn, or E to end the game:";
                cin >> option;

                if(option !='C' && option !='E')
                {
                    cout << "Invalid option, please press C to continue next turn or E to end the game";
                    continue;
                }
                if(option == 'E')
                {
                    cout << "-- GAME OVER -- \n";
                    cout << "Thanks for playing!!!";
                    break;
                }

            Player* currentPlayer;
            if(turn % 2 == 1)
            {
                currentPlayer = &p1; //puntero para saber que jugador esta
            }
            else
            {
                currentPlayer = &p2;
            }
            
            int currentTile = currentPlayer->getPosition();

            int diceRoll = dice.roll();

            int newPosition = currentTile + diceRoll;

            if(newPosition> 30)
            {
                newPosition = 30;
            }

            Tile* tile = board.getTile(newPosition);
            
            char tileType = tile ->getType();
            int finalTile = tile ->applyEffect(newPosition);

            currentPlayer ->setPosition(finalTile);
            
            if(finalTile < 1) finalTile= 1;
            if(finalTile > 30) finalTile = 30;

            currentPlayer ->setPosition(finalTile);

            cout << turn << " "
                << currentPlayer->getId() << " "
                << currentTile << " "
                << diceRoll << " "
                << tileType << " "
                << finalTile << endl;

            if(finalTile >= 30)
            {
                cout << "-- GAME OVER -- \n";
                cout << "Player " << currentPlayer->getId() << " is the winner!!!" << endl;
                break;
            }

            turn ++;
            }
        }

};
