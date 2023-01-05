#include "Scene2.h"
#include "Scene3.h"
#include "keyboard.h"
#include "MainMenu.h"
USING_NS_CC;

Scene *Scene2::createScene()
{
    auto scene = Scene::createWithPhysics();
    auto layer = Scene2::create();
    /*   PhysicsWorld *world = scene->getPhysicsWorld();
       world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);*/
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool Scene2::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }
    Size size = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // border
    auto wall = Node::create();
    auto wallBody = PhysicsBody::createEdgeBox(size, PHYSICSBODY_MATERIAL_DEFAULT, 2);
    wall->setPhysicsBody(wallBody);
    wall->setPosition(Vec2(size.width / 2 + origin.x, size.height / 2 + origin.y));
    this->addChild(wall);
    // background
    auto layer1 = Sprite::create("res/scene2/layer1.png");
    layer1->setAnchorPoint(Vec2(0, 0));
    layer1->setPosition(Vec2(10, 0));
    this->addChild(layer1, 4);
    auto layer2 = Sprite::create("res/scene2/layer.png");
    layer2->setAnchorPoint(Vec2(0, 0));
    layer2->setPosition(Vec2(10, 0));
    this->addChild(layer2, 5);
    auto layer2Physics = PhysicsBody::createBox(layer2->getContentSize());
    layer2Physics->setDynamic(false);
    layer2->addComponent(layer2Physics);
    auto sky = Sprite::create("res/scene2/Background.png");
    sky->setAnchorPoint(Vec2(0.5, 0.5));
    sky->setPosition(Vec2(size.width / 2, size.height / 2));
    sky->setScale(2.5, 2.5);
    this->addChild(sky);
    // sprite
    auto sprite = Sprite::create("res/vikingPlayer/viking1.png");
    sprite->setAnchorPoint(Vec2(0.5, 0.5));
    sprite->setScale(0.7, 0.7);
    sprite->setTag(10);
    sprite->setPosition(Vec2(size.width / 6, size.height / 6));
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(1, 0.1f, 0.1f));
    physicsBody->setDynamic(true);
    physicsBody->setVelocityLimit(16.0f);
    physicsBody->setGravityEnable(false);
    physicsBody->setContactTestBitmask(1);
    sprite->setPhysicsBody(physicsBody);
    this->addChild(sprite, 1);

    keyboard(sprite, this, false);
    // board

    auto boar = Sprite::create("res/scene2/boar.png");
    boar->setAnchorPoint(Vec2(0.5, 0.5));
    boar->setScale(2,2);
    boar->setPosition(Vec2(size.height / 1.2, size.height / 6));
    boar->setTag(10);
    auto physicsBoar = PhysicsBody::createBox(boar->getContentSize(), PhysicsMaterial(1, 0.1f, 0.1f));
    physicsBoar->setDynamic(true);
    physicsBoar->setContactTestBitmask(1);
    boar->setPhysicsBody(physicsBoar);
    this->addChild(boar);
    auto action = MoveBy::create(0.5, Vec2(-size.width, 0));
    action->setDuration(40);
    boar->runAction(action);

    

    // TileGrass
    Vector<Sprite *> listTile;
    for (int i = 0; i < 10; i++)
    {
        listTile.pushBack(Sprite::create("res/scene2/TileGrass.png"));
    }
    auto a = size.width / 2;
    auto b = size.height / 4;
    for (int i = 0; i < 4; i++)
    {
        auto tilePhysics = PhysicsBody::createBox((listTile.at(i))->getContentSize(), PhysicsMaterial(1, 1.0f, 1.0f));
        tilePhysics->setDynamic(false);
        (listTile.at(i))->setPhysicsBody(tilePhysics);
        (listTile.at(i))->setAnchorPoint(Vec2(0, 0));
        (listTile.at(i))->setPosition(a, b);
        this->addChild(listTile.at(i));
            // ajout flag
        if(i==3){
            auto flag = Sprite::create("flag1.png");
    flag->setAnchorPoint(Vec2(0, 0));
    flag->setScale(0.5,0.5);
    flag->setPosition(Vec2(a,b+(listTile.at(i))->getContentSize().height));
    flag->setTag(20);
    auto physicsBody2 = PhysicsBody::createBox(flag->getContentSize());
    physicsBody2->setGravityEnable(false);
    physicsBody2->setContactTestBitmask(1);
    flag->setPhysicsBody(physicsBody2);
    this->addChild(flag, 0);
        }
        a += (listTile.at(i))->getContentSize().width;
    }
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

            Director::getInstance()->replaceScene(MainMenu::createScene());
        }
        else
        {
            Director::getInstance()->replaceScene(Scene3::createScene());
        }

        //
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    return true;
}