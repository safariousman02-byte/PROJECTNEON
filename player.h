#pragma once
#include "raylib.h"

class Player {

    public:
        Player();
        void UPdate(float dt);
        void Draw();

        float GetHealth(){
            return health;
        }

        void TakeDamage(float amount) {
            health -= amount;
        }

        Vector2 GetPosition() {
            return position;
        }

    private:
        Vector2 position;
        float speed;
        Color color;
        
        float health;
        float maxhealth;

};