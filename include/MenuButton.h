#ifndef _MENU_BUTTON_H_
#define _MENU_BUTTON_H_

#include "GameObject.h"

class MenuButton: public SDLGameObject
{
public:
    MenuButton(const LoaderParams* params, void(*callback)());
    void update() override;
    void draw() override;
    void clean() override;
private:
    enum button_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };
    
    void (*callback)();
    bool buttonReleased;
};

#endif
