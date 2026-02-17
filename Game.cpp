#include "Game.h"

Game::Game(){

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
            loadingprogress += dt * 0.1f;
            if (loadingprogress >= 1.0f || IsKeyPressed(KEY_P)) currentstate = GameState::MENU;
        break;

        case GameState::GAMEPLAY:

            player.UPdate(dt);

            spawntimer += dt;

            if (spawntimer >= 2.0f) {

                Vector2 randompos = { (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(0, GetScreenHeight())};
                enemies.push_back(Enemy(randompos));
                spawntimer = 0.0f;
                TraceLog(LOG_INFO, "ENEMY SPAW! TOTAL: %i", enemies.size());

            }

            for (auto& enemy : enemies){
                enemy.Update(player.GetPosition(), dt);
            }

            shootime += dt;

            if (IsKeyDown(KEY_SPACE) && shootime >= 0.5f) {

                Vector2 shootdir = { 0, -1};
                projectiles.push_back(Projectile(player.GetPosition(), shootdir));
                shootime = 0;
            }

            for (int i=0 ; i< projectiles.size(); i++) {

               projectiles[i].Update(dt);

                 if (projectiles[i].isoffscreen()) {
                    projectiles.erase(projectiles.begin() + i);
                    i--;
                 }
            }

            for (int i=0; i < projectiles.size(); i++) {
                for (int j=0; j < enemies.size(); j++) {

                    if (CheckCollisionCircles(projectiles[i].GetPosition(), 5, enemies[j].GetPosition(), 10)) {

                        gems.push_back(Gem(enemies[j].GetPosition()));
                        
                        projectiles.erase(projectiles.begin() + i);
                        enemies.erase(enemies.begin() + j);

                        i--;

                        break;

                    }

                    for (int i=0; i<gems.size(); i++) {

                        if (CheckCollisionCircles(player.GetPosition(), 20, gems[i].GetPosition(), 10));

                        gems.erase(gems.begin() + i);
                        i--;

                        player.Addxp(10.0f);
                    }

                    
                }
            }

            for (int i=0; i<enemies.size(); i++) {

                if (CheckCollisionCircles(player.GetPosition(), 15, enemies[i].GetPosition(), 10)) {

                    player.TakeDamage(10.0f * dt);
                }
            }

            if (player.GetHealth() <= 0 || IsKeyPressed(KEY_K)) {

                currentstate = GameState::GAMEOVER;
            }

            

        break;

        case GameState::GAMEOVER:
            
            if (IsKeyPressed(KEY_R)) {

                enemies.clear();
                projectiles.clear();
                gems.clear();
                player = Player();
                currentstate = GameState::GAMEPLAY;
            }

        break;
    }

}

void Game::Draw() {
    BeginDrawing();
      ClearBackground( {10, 10, 25, 255});

      switch(currentstate) {

        case GameState::LOGO:{


            DrawText("SAFARI STUDIO", 475, 300, 40, GOLD);

            DrawRectangleLinesEx((Rectangle){440,360, 400, 20}, 2.0f, BLUE);
            DrawRectangle(445,365, 390*loadingprogress, 10, (Color){0, 255, 255, 255});
            DrawText("INITIALISING NEON CORE...", 440, 390, 10, RAYWHITE);

            DrawCircleV(GetMousePosition(), 30, Fade((Color){0, 255, 255, 255}, 0.5f));
            DrawCircleLines(GetMousePosition().x, GetMousePosition().y, 30, (Color){0, 255, 255, 255});
      }
        break;

        case GameState::MENU:{


            for (int i=0; i<screenwidth; i+=40) {
                    DrawLine(i, 0, i, screenheight, (Color){0, 255, 255, 50} );
            }

            DrawText("PROJECT NEON", 400, 200, 60, MAGENTA);
            DrawText("PRESS ENTER TO START", 500, 450, 20, RAYWHITE);

            DrawCircleV(GetMousePosition(), 30, Fade((Color){0, 255, 255, 255}, 0.5f));
            DrawCircleLines(GetMousePosition().x, GetMousePosition().y, 30, (Color){0, 255, 255, 255});
        
        }

        break;

        case GameState::GAMEPLAY:{

            DrawText("GAME ACTIVE", 100, 100, 20, LIME);

            player.Draw();

            for (int i=0; i<enemies.size(); i++) {
                enemies[i].Draw();
            }

            for (int i=0; i<projectiles.size(); i++) {
                projectiles[i].Draw();
            }

            for (auto& gem : gems) gem.Draw();

            
            DrawRectangle(0, 0, GetScreenWidth(), 20, DARKGRAY);

            float barwidth = GetScreenWidth()*player.Getxppercent();

            DrawRectangle(0, 0, (int)barwidth, 20, LIME);

            DrawText(TextFormat("LEVEL: %i", player.Getlevel()), 10, 25, 20, RAYWHITE);

            DrawRectangle(10, 50, 200, 10, RED);

            DrawRectangle(10, 50, (int)(200*(player.GetHealth()/ 100.0f)), 10, GREEN);

        }

        break;

        case GameState::GAMEOVER: {

            DrawText("GAME OVER", 500, 200, 60, RED);
            DrawText("PRESS ENTER TO RESTART", 550, 350, 20, RAYWHITE);
        
        }

        break;

        case GameState::EXIT:{

            DrawText("EXITING GAME", 500, 200, 60, RED);

        }
            
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