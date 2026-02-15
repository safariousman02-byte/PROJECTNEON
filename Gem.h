#pragma once 
#include "raylib.h"

class Gem {

    public:
        Gem(Vector2 pos);
        void Draw();
        Vector2 GetPosition() {
            return position;
        }

    private:
        Vector2 position;
        Color color;

};