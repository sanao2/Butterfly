#include "Global.h"

Move::MoveManager* move = nullptr;

Animstate current_state = PLAYER_DEFAULT;
Animstate prev_state = PLAYER_DEFAULT;

Render* render = nullptr;