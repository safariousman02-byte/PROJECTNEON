#include "player.h"
#include "raymath.h"


Player::Player() {

    position = {640, 360};
    speed = 300.0f;
    color = (Color){0, 255, 255, 255};

    maxhealth = 100.0f;
    health = maxhealth;

    level = 1;
    currentxp = 0.0f;
    xptonextlevel = 50.0f;
}

void Player::UPdate(float dt) {

    Vector2 direction = {0, 0};

    int playerspeed = 10.0f;

    if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_UP)) position.y -= playerspeed;
    if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_DOWN)) position.y += playerspeed;
    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_LEFT)) position.x -= playerspeed;
    if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_RIGHT)) position.x += playerspeed;

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
