#include "Scene3.h"
#include "MainMenu.h"
#include "keyboard.h"
#include "WinScene.h"

USING_NS_CC;

Scene *Scene3::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = Scene3::create();

    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool Scene3::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }
    Size size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // border
    auto wall = Node::create();
    
    auto wallBody = PhysicsBody::createEdgeBox(size, PhysicsMaterial(100, 1.0f, 0.5f), 2);
    wall->setPhysicsBody(wallBody);

    wall->setPosition(Vec2(size.width / 2 + origin.x, size.height / 2 + origin.y));
    this->addChild(wall);
    // player
    auto sprite = Sprite::create("res/vikingPlayer/viking1.png");
    sprite->setAnchorPoint(Vec2(0.5, 0.5));
    sprite->setPosition(Vec2(size.width / 6, size.height / 7));
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1, 0.1f, 0.1f));
    physicsBody->setDynamic(true);
    physicsBody->setContactTestBitmask(1);
    physicsBody->setVelocityLimit(16.0f);
    sprite->setPhysicsBody(physicsBody);
    sprite->setScale(0.5, 0.5);
    sprite->setTag(10);
    this->addChild(sprite, 1);

    // earth tile
    Vector<Sprite *> listTile;
    for (int i = 0; i < 20; i++)
    {
        listTile.pushBack(Sprite::create("res/scene3/r.png"));
    }
    int a = 0;
    for (int i = 0; i < 20; i++)
    {
        if (i == 3 || i == 6)
        {
            auto trap = Sprite::create("res/scene3/trap.png");
            auto trapPhysics = PhysicsBody::createBox(trap->getContentSize()/2, PhysicsMaterial(1, 0.1f, 0.1f));
            trapPhysics->setDynamic(false);
            trapPhysics->setContactTestBitmask(1);
            trap->addComponent(trapPhysics);
            trap->setAnchorPoint(Vec2(0, 0));
            trap->setScale(0.5, 0.5);
            trap->setPosition(a, 0);
            this->addChild(trap);
             a += trap->getContentSize().width/2;
        }
        else
        {
            (listTile.at(i))->setScale(1, 0.5);
            auto tilePhysics = PhysicsBody::createBox((listTile.at(i))->getContentSize(), PhysicsMaterial(1, 0.1f, 0.1f));
            tilePhysics->setDynamic(false);
            (listTile.at(i))->setPhysicsBody(tilePhysics);
            (listTile.at(i))->setAnchorPoint(Vec2(0, 0));
            (listTile.at(i))->setPosition(a, 0);
            this->addChild(listTile.at(i));
            a += (listTile.at(i))->getContentSize().width;
            if(i==8){
                   // earth spike
    auto spike = Sprite::create("res/scene3/earthSpike.png");
    auto spikePhysics = PhysicsBody::createBox(spike->getContentSize()/2, PhysicsMaterial(1, 0.1f, 0.1f));
    spikePhysics->setDynamic(false);
    spikePhysics->setContactTestBitmask(1);
    spike->addComponent(spikePhysics);
    spike->setAnchorPoint(Vec2(0, 0));
    spike->setScale(0.5, 0.5);
    spike->setPosition(a,(listTile.at(i))->getContentSize().height/2 );
    this->addChild(spike);
            }
        }
    }
auto flag = Sprite::create("flag1.png");
    flag->setAnchorPoint(Vec2(0, 0));
    flag->setScale(0.5,0.5);
    flag->setPosition(Vec2(size.width/1.1,size.height/10));
    flag->setTag(10);
    auto physicsBody2 = PhysicsBody::createBox(flag->getContentSize());
    physicsBody2->setGravityEnable(false);
    physicsBody2->setContactTestBitmask(1);
    flag->setPhysicsBody(physicsBody2);
    this->addChild(flag);
 

    auto contactListener =
        EventListenerPhysicsContact::create();
    contactListener->onContactBegin = [](PhysicsContact &contact)
    {
        auto shapeA = contact.getShapeA();
        auto bodyA = shapeA->getBody();
        auto shapeB = contact.getShapeB();
        auto bodyB = shapeB->getBody();

        auto nodeA = contact.getShapeA()->getBody()->getNode();
        auto nodeB = contact.getShapeB()->getBody()->getNode();

        if (nodeA->getTag() == 10 && nodeB->getTag() == 10)
        {

            Director::getInstance()->replaceScene(TransitionFade::create(1.0,WinScene::createScene()));
        }
        else
        {
            Director::getInstance()->replaceScene(TransitionFade::create(1.0,MainMenu::createScene()));
        }

        //
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    keyboard(sprite, this, false);

    return true;
}