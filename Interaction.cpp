#include "Interaction.h"
#include "Entity.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

bool IsInteracting(const Entity& e1, const Entity& e2)
{
    auto entity_1 = e1.GetBoundingBox();
    auto entity_2 = e2.GetBoundingBox();
    return entity_1.intersects(entity_2);
}

void HandleCollision(Ball& ball, const Paddle& pad)
{
    if (IsInteracting(ball, pad)) {
        ball.MoveUp();

        if (ball.X() < pad.X()) {
            ball.MoveLeft();
        }
        else {
            ball.MoveRight();
        }
    }
}

void HandleCollision(Ball& ball, Brick& brick)
{
    if (IsInteracting(ball, brick)) {
       brick.Weaken();
       if (brick.bIsTooWeak()) {
           brick.Destroy();
       }

        float LeftOverlap = ball.Right() - brick.Left();
        float RightOverlap = brick.Right() - ball.Left();
        float TopOverlap = ball.Bottom() - brick.Top();
        float BottomOverlap = brick.Bottom() - ball.Top();

        bool bFromLeft = std::abs(LeftOverlap) < std::abs(RightOverlap);
        bool bFromTop = std::abs(TopOverlap) < std::abs(BottomOverlap);

        float MinXOverlap = bFromLeft ? LeftOverlap : RightOverlap;
        float MinYOverlap = bFromTop ? TopOverlap : BottomOverlap;

        if (std::abs(MinXOverlap) < std::abs(MinYOverlap)) {
            if (bFromLeft) {
                ball.MoveLeft();
            }
            else {
                ball.MoveRight();
            }
        }
        else {
            if (bFromTop) {
                ball.MoveUp();
            }
            else {
                ball.MoveDown();
            }
        }
    }
}
