#include "Gem.h"

Gem::Gem(Vector2 pos) {
    position = pos;
    color = LIME;
}

void Gem::Draw() {

    DrawPoly(position, 4, 6.0f, 0.0f, color);
    DrawPolyLines(position, 6, 10.0f, 0, Fade(color, 0.3f));
}