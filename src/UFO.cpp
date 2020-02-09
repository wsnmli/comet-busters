#include "../include/UFO.h"
#include "../include/ScreenHandler.h"
#include "../include/BulletHandler.h"

UFO::UFO(): Enemy()
{
    health = 1;
    moveSpeed = 2;
}

void UFO::update()
{
    if (!isDead())
    {
        static int xShift = moveSpeed;
        static int yShift = moveSpeed;

        if (!isInScreen(position))
        {
            if (isOutOfHeight(position) && isOutOfWidth(position))
            {
                xShift = -xShift + 1;
                yShift = -yShift + 1;
            }
            else if (isOutOfWidth(position))
            {
                xShift = -xShift;
            }
            else if (isOutOfHeight(position))
            {
                yShift = -yShift;
            }
        }
        
        velocity.setX(xShift);
        velocity.setY(yShift);
        
        shoot();
    } 
    else
    {
        velocity.setX(0);
        velocity.setY(0);
        // TODO: Dying animation
    }
    ShooterObject::update();
}

void UFO::shoot()
{
    static int counter = moveSpeed * 100;
    if (counter < moveSpeed)
    {
        Vector2D heading = velocity;
        BulletHandler::Instance()->addEnemyBullet(position.getX(), position.getY(), 
                                                  16, 16, "bullet3", 1, heading);
        counter = moveSpeed * 100;
    }
    counter--;
}

void UFO::collision()
{
    health -= 1;
    if (health == 0)
    {
        // TODO: Dying animation
        delete this;
    }
}
