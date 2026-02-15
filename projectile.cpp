#include "projectile.h"
#include "raymath.h"

Projectile::Projectile(Vector2 pos, Vector2 dir) {
    position = pos;
    direction = dir;
    speed = 1000;
}

void Projectile::Update(float dt) {
    position.x += direction.x * speed * dt;
    position.y += direction.y * speed * dt;
}

void Projectile:: Draw() {
    DrawCircleV(position, 4.0f, YELLOW);
    DrawCircleGradient(position.x, position.y, 8.0f, Fade(GOLD, 0.5f), BLACK);
}

bool Projectile::isoffscreen() {
    return (position.x < 0 || position.x > 1280 || position.y < 0 || position.y > 720);
}