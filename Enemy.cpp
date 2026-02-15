#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 startpos) {
    position = startpos;
    speed = 100.0f;
}

void Enemy::Update(Vector2 playerpos, float dt) {

    Vector2 direction = Vector2Subtract(playerpos, position);

    direction = Vector2Normalize(direction);

    position.x += direction.x * speed * dt;
    position.y += direction.y * speed * dt;
}

void Enemy::Draw(){

    DrawPoly(position, 4, 12.0f, 0.0f, RED);
    DrawPolyLinesEx(position, 4, 12.0f, 0.0f, 2.0f, MAROON);
}