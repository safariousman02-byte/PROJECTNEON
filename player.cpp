#include "player.h"
#include "raymath.h"


Player::Player() {

    position = {640, 360};
    speed = 300.0f;
    color = (Color){0, 255, 255, 255};
}

void Player::UPdate(float dt) {

    Vector2 direction = {0, 0};

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) position.y -= 1;
    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) position.y += 1;
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) position.x -= 1;
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) position.x += 1;

    if (Vector2Length(direction) > 0) {

        direction = Vector2Normalize(direction);

    }

    position.x += direction.x * speed * dt;
    position.y += direction.y * speed * dt;

}

void Player::Draw() {

    DrawTriangle({position.x, position.y-20},
        {position.x-15, position.y+15},
        {position.x+15, position.y+15},
        Fade((Color){0, 255, 255, 255}, 0.3f)
    );

    DrawTriangleLines({position.x, position.y-20},
        {position.x-15, position.y+15},
        {position.x+15, position.y+15},
        (Color){0, 255, 255, 255}
    );

}
