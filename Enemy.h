#pragma once
#include "raylib.h"

class Enemy {

    public:
        Enemy(Vector2 startpos);
        void Update(Vector2 playerpos, float dt);
        void Draw();

        Vector2 GetMousePosition() {
            return position;
        }

    private:
        Vector2 position;
        float speed;
};