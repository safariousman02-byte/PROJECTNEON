#pragma once 
#include "raylib.h"

#include "player.h"

#include <vector>
#include "Enemy.h"

#include "projectile.h"

#include "Gem.h"

enum class GameState {
    LOGO,
    MENU,
    GAMEPLAY,
    GAMEOVER,
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

        std::vector<Projectile> projectiles;
        float shootime;

        std::vector<Gem> gems;
        

};