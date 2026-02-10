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

    if (currentstate == GameState::LOGO && GetTime() > 2.0f){
        currentstate = GameState::MENU;
    }

    if (currentstate == GameState::MENU && IsKeyPressed(KEY_ENTER)){
        currentstate = GameState::GAMEPLAY;
    }

}

void Game::Draw() {
    BeginDrawing();
      ClearBackground(BLACK);

      if (currentstate == GameState::MENU) DrawText("SAFARI STUDIO", 400, 300, 40, GOLD);
      if (currentstate == GameState::MENU) DrawText("PRESS ENTER", 500, 400, 20, RAYWHITE);
      if (currentstate == GameState::GAMEPLAY) DrawText("GAME ACTIVE", 100, 100, 20, LIME);

    EndDrawing();
}

void Game::Run() {
    
    while(!WindowShouldClose() && currentstate != GameState::EXIT) {
        Update();
        Draw();
    }
}