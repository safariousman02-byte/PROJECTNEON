#include "Game.h"

Game::Game() {
    screenwidth = 1280;
    screenheight = 720;
    
    InitWindow(screenwidth, screenheight, "SAFARI STUDIO - PROJECTNEON");
    SetTargetFPS(60);

    currentstate = GameState::LOGO;
}

Game::~Game() {
    CloseWindow();
}

void Game::Update() {

    float dt = GetFrameTime();


    if (currentstate == GameState::LOGO && GetTime() > 60.0f){
        currentstate = GameState::MENU;
    }

    if (currentstate == GameState::MENU && IsKeyPressed(KEY_ENTER)){
        currentstate = GameState::GAMEPLAY;
    }

    switch(currentstate) {

        case GameState::LOGO:
            loadingprogress += dt * 0.1;
            if (loadingprogress >= 1.0f || IsKeyPressed(KEY_P)) currentstate = GameState::MENU;
        break;

        case GameState::GAMEPLAY:

            player.UPdate(dt);

        break;
    }

}

void Game::Draw() {
    BeginDrawing();
      ClearBackground( {10, 10, 25, 255});

      switch(currentstate) {

        case GameState::LOGO:

            DrawText("SAFARI STUDIO", 475, 300, 40, GOLD);

            DrawRectangleLinesEx((Rectangle){440,360, 400, 20}, 2.0f, BLUE);
            DrawRectangle(445,365, 390*loadingprogress, 10, (Color){0, 255, 255, 255});
            DrawText("INITIALISING NEON CORE...", 440, 390, 10, RAYWHITE);

        break;

        case GameState::MENU:

            for (int i=0; i<screenwidth; i+=40) {
                    DrawLine(i, 0, i, screenheight, (Color){0, 255, 255, 50} );
            }

            DrawText("PROJECT NEON", 400, 200, 60, MAGENTA);
            DrawText("PRESS ENTER TO START", 500, 450, 20, RAYWHITE);

        break;

        case GameState::GAMEPLAY:
            DrawText("GAME ACTIVE", 100, 100, 20, LIME);

            player.Draw();

        break;
      }


    EndDrawing();
}

void Game::Run() {
    
    while(!WindowShouldClose() && currentstate != GameState::EXIT) {
        Update();
        Draw();
    }
}