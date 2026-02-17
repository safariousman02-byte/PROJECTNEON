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

        void Addxp(float amount) {
            currentxp += amount;
            
            if (currentxp >= xptonextlevel) {

                level++;
                currentxp = 0.0f;
                xptonextlevel *= 1.2f;
                speed += 20.0f;
            }
        }

        float Getxppercent() {
            return currentxp / xptonextlevel;
        }

        int Getlevel() {
            return level;
        }

    private:
        Vector2 position;
        float speed;
        Color color;

        float health;
        float maxhealth;

        int level;
        float currentxp;
        float xptonextlevel;

};