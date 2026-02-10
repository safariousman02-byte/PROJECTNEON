#pragma once 
#include "raylib.h"

enum class GameState {
    LOGO,
    MENU,
    GAMEPLAY,
    EXIT
};

class Game {

    public:
        Game();
        ~Game();

    void Run();

    private:
        void Update();
        void Draw();

        GameState currentstate;
        int screenwidth;
        int screenheight;

};