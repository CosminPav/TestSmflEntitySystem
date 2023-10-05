#include "Entity.h"

sf::FloatRect Entity::GetBoundingBox() const noexcept
{
    //return the bounding sprite rect, in global space, relative to the top left corner
    return sprite.getGlobalBounds();
}

sf::Vector2f Entity::GetCenter() const noexcept
{
    //Get the coord relative to the sprite
    auto Box = GetBoundingBox();
    return {Box.width/2, Box.height/2};
}

float Entity::X() const noexcept
{
    return sprite.getPosition().x;
}

float Entity::Y() const noexcept
{
    return sprite.getPosition().y;
}


float Entity::Left() const noexcept
{
    auto box = GetBoundingBox();
    return X()- box.width/2;
}

float Entity::Right() const noexcept
{
    auto box = GetBoundingBox();
    return X() + box.width / 2;
}

float Entity::Bottom() const noexcept
{
    auto box = GetBoundingBox();
    return Y() - box.height / 2;
}

float Entity::Top() const noexcept
{
    auto box = GetBoundingBox();
    return Y() + box.height / 2;
}

void Entity::Destroy() noexcept
{
    bDestroyed = true;
}

bool Entity::IsDestroyed() const noexcept
{
    return bDestroyed;
}
