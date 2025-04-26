#pragma once
#include "MoveDirection.h"


namespace Move{

    struct IMoveController
    {
        virtual ~IMoveController() = default;
        virtual MoveDirection GetDirection() = 0;
    };

}
