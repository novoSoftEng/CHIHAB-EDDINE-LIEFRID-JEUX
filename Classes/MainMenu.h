#pragma once
#include "cocos2d.h"

class MainMenu : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
  void  GoToScene1(cocos2d::Ref* pSender);
   void GoToScene2(cocos2d::Ref* pSender);
    void GoToScene3(cocos2d::Ref* pSender);
    // a selector callback
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
};