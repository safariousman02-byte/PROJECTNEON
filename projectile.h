#pragma once
#include "raylib.h"

class Projectile {

    public :
        Projectile(Vector2 pos, Vector2 dir);
        void Update(float dl);
        void Draw();
        bool isoffscreen();

        Vector2 GetPosition() {
             return position; 
        }

    private :
        Vector2 position;
        Vector2 direction;
        float speed;
};