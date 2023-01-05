
#include "LoseScene.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"

USING_NS_CC;

Scene* LoseScene::createScene()
{
    return LoseScene::create();
}
int LoseScene::getCurrent(){
    return current;
}
void LoseScene::setCurrent(int n){
    this->current=n;
}
// on "init" you need to initialize your instance
bool LoseScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("YOU LOSE", "fonts/Marker Felt.ttf", 24);
 
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    auto normalItem = Sprite::create("retry.jpeg");
auto selectedItem = Sprite::create("retry.jpeg");
selectedItem->setColor(Color3B::GRAY);
auto item = MenuItemSprite::create(normalItem, selectedItem,
[this](Ref* sender){
    if(this->getCurrent()==1){
        Director::getInstance()->replaceScene(Scene1::createScene());
    }else if(this->getCurrent()==2){
        Director::getInstance()->replaceScene(Scene2::createScene());
    }else{
        Director::getInstance()->replaceScene(Scene3::createScene());
    }
});
auto size = Director::getInstance()->getVisibleSize();
item->setPosition(size/2);
auto menu = Menu::create(item, nullptr);
menu->setPosition(Vec2());
this->addChild(menu);
    return true;
}