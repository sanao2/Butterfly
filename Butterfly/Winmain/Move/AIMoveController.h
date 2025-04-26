#pragma once
#include "IMoveController.h"

namespace Move
{
    class AIMoveController : public IMoveController
    {
    public:
        MoveDirection GetDirection() override
        {
            // 예시용 AI 방향 결정 (항상 오른쪽으로 이동)
            return MoveDirection::Right;
        }
    };
}

