#include "Scene1.h"
#include "keyboard.h"
#include "Scene2.h"

USING_NS_CC;

Scene *Scene1::createScene()
{
    auto scene = Scene::createWithPhysics();
auto layer = Scene1::create();
scene->addChild(layer);

return scene;

}

// on "init" you need to initialize your instance
bool Scene1::init()
{
    if (!Scene::init())
    {
        return false;
    }
    Size size = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float x_divise = 0.0f;
    float y_divise = 0.0f;
    int i = 0;
    for (i = 10; i <= size.width; i += 10)
    {
        x_divise = i;
    }
    for (i = 10; i <= size.height; i += 10)
    {
        y_divise = i;
    }
    auto background = Sprite::create("41524.jpg");
    background->setAnchorPoint(Vec2(0.5, 0.5));
    background->setPosition(Vec2(size.width / 2, size.height / 2));
    background->setScaleX((size.width) / (x_divise * 6));
    background->setScaleY((size.height) / (y_divise * 5));
    this->addChild(background, -1);
    auto wall = Node::create();
auto wallBody = PhysicsBody::createEdgeBox(size,PhysicsMaterial(100, 1, 1.0f));
wall->setPhysicsBody(wallBody);
wall->setPosition(Vec2(size.width/2+origin.x,size.height/2+origin.y));
this->addChild(wall);
    //physics de contact entre flag et joueur
    
auto contactListener =EventListenerPhysicsContact::create();
contactListener->onContactBegin = [](PhysicsContact& contact){

Director::getInstance()->replaceScene(TransitionFade::create(1.0,Scene2::createScene()));
auto shapeA = contact.getShapeA();
auto bodyA = shapeA->getBody();
auto shapeB = contact.getShapeB();
auto bodyB = shapeB->getBody();
return true;
};
this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    // ajout sprite

    auto sprite = Sprite::create("res/vikingPlayer/viking1.png");
    sprite->setAnchorPoint(Vec2(0.5, 0.5));
    sprite->setPosition(Vec2(size.width / 6, size.height / 6));
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(),PhysicsMaterial(100, 0,0));
physicsBody->setGravityEnable(false);
physicsBody->setContactTestBitmask(1);
sprite->setPhysicsBody(physicsBody);
 
    this->addChild(sprite, 1);
    // ajout flag
    auto flag = Sprite::create("flag1.png");
    flag->setAnchorPoint(Vec2(0.5, 0.5));
    flag->setPosition(Vec2(size.width - size.width / 9, size.height / 6));
    auto physicsBody2 = PhysicsBody::createBox(flag->getContentSize());
    physicsBody2->setGravityEnable(false);
physicsBody2->setContactTestBitmask(1);
flag->setPhysicsBody(physicsBody2);
    this->addChild(flag, 0);
  
    // keyboard
    keyboard(sprite,this,true );


    return true;
}