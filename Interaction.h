#pragma once
class Entity;
class Ball;
class Paddle;
class Brick;

bool IsInteracting(const Entity& e1, const Entity& e2);
void HandleCollision(Ball& ball, const Paddle& pad);
void HandleCollision(Ball& ball, Brick& brick);
