#pragma once 
#include "raylib.h"
#include "player.h"
#include <vector>
#include "Enemy.h"

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

        Font FuturisticFont;
        float loadingprogress;
        void DrawUI();

        Player player;

        std::vector<Enemy> enemies;
        float spawntimer;
        

};