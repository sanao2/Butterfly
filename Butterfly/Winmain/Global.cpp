#include "Global.h"

Move::MoveManager* move = nullptr;
Render* render = nullptr; // ������ ��ü

Animstate current_state = PLAYER_DEFAULT;
Animstate prev_state = PLAYER_DEFAULT;