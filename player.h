#pragma once
#include "raylib.h"

class Player {

    public:
        Player();
        void UPdate(float dt);
        void Draw();

        Vector2 GetPosition() {
            return position;
        }

    private:
        Vector2 position;
        float speed;
        Color color;

};