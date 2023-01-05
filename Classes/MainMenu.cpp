#include "MainMenu.h"
#include "Scene1.h"
#include "Scene2.h"
//#include "Scene3.h"


USING_NS_CC;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();

    auto layer = MainMenu::create();

    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.


// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto level1 = MenuItemImage::create("res/level1.png",
        "res/level1.png",CC_CALLBACK_1(MainMenu::GoToScene1, this));

    auto level2 = MenuItemImage::create("res/level2.png",
        "res/level2.png",CC_CALLBACK_1(MainMenu::GoToScene2, this));

    auto level3 = MenuItemImage::create("res/level3.png",
      "res/level3.png",
       CC_CALLBACK_1(MainMenu::GoToScene3, this));

    level1->setScale(0.5,0.5);
    level2->setScale(0.5,0.5);
   level3->setScale(0.5,0.5);
    auto menu = Menu::create(level1,level2,level3,nullptr);
    menu->alignItemsVerticallyWithPadding(visibleSize.height / 18);
    this->addChild(menu);

    auto backgroundSprite = Sprite::create("res/Forest.png"); /*background for the main menu*/
    backgroundSprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(backgroundSprite, -1);

    float rx = visibleSize.width / backgroundSprite->getContentSize().width;
    float ry = visibleSize.height / backgroundSprite->getContentSize().height;

    backgroundSprite->setScaleX(rx);
    backgroundSprite->setScaleY(ry);



    return true;
}


void MainMenu::GoToScene1(cocos2d::Ref* pSender)
{
    auto scene = Scene1::createScene();
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(TransitionFade::create(1.0,scene));

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void MainMenu::GoToScene2(cocos2d::Ref* pSender)
{
    auto scene = Scene2::createScene();
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->replaceScene(TransitionFade::create(1.0,scene));

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void MainMenu::GoToScene3(cocos2d::Ref* pSender)
{
  //  auto scene = Scene3::createScene();
    //Close the cocos2d-x game scene and quit the application
   // Director::getInstance()->replaceScene(TransitionFade::create(1.0,scene));

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}