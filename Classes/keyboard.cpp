#include "keyboard.h"

USING_NS_CC;

keyboard::keyboard(Sprite *Sprite, Scene *Scene,bool anim)
{
    auto eventListener = EventListenerKeyboard::create();

    eventListener->onKeyPressed = [anim](EventKeyboard::KeyCode keyCode, Event *event)
    {
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            {
            auto animation = Animation::create();
            for (int i = 1; i <= 5; i++)
            {
                std::string name = StringUtils::format("res/vikingPlayer/viking%d.png", i);
                animation->addSpriteFrameWithFile(name.c_str());
            }
            animation->setDelayPerUnit(0.1f);
            animation->setRestoreOriginalFrame(true);
            animation->setLoops(1);
            auto action1 = Animate::create(animation);
            auto action2 = MoveBy::create(0.5, Vec2(-10, 0));
            auto action = Spawn::create(action1, action2, nullptr);
            if(anim==true){
                event->getCurrentTarget()->runAction(action);
            }else event->getCurrentTarget()->runAction(action2);
            
            }
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
             {
            auto animation = Animation::create();
            for (int i = 2; i <= 4; i++)
            {
                std::string name = StringUtils::format("res/vikingPlayer/viking%d.png", i);
                animation->addSpriteFrameWithFile(name.c_str());
            }
            animation->setDelayPerUnit(0.1f);
            animation->setRestoreOriginalFrame(true);
            animation->setLoops(1);
            auto action1 = Animate::create(animation);
            auto action2 = MoveBy::create(0.5, Vec2(10, 0));
            auto action = Spawn::create(action1, action2, nullptr);
                        if(anim==true){
                event->getCurrentTarget()->runAction(action);
            }else event->getCurrentTarget()->runAction(action2);
            }
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
              {
            auto animation = Animation::create();
            for (int i = 1; i <= 5; i++)
            {
                std::string name = StringUtils::format("res/vikingPlayer/viking%d.png", i);
                animation->addSpriteFrameWithFile(name.c_str());
            }
            animation->setDelayPerUnit(0.1f);
            animation->setRestoreOriginalFrame(true);
            animation->setLoops(1);
            auto action1 = Animate::create(animation);
            auto action2 = JumpBy::create(0.5, Vec2(10, 0), 50, 1);
            auto action = Spawn::create(action1, action2, nullptr);
                        if(anim==true){
                event->getCurrentTarget()->runAction(action);
            }else event->getCurrentTarget()->runAction(action2);
            }
            break;
        }
    };
    Scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, Sprite);
}