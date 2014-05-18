//
//  GameLayer.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#include "GameLayer.h"
#include "RollingDigitLayer.h"
#include "TutorialLayer.h"

GameLayer::GameLayer() {
    
}

GameLayer::~GameLayer() {
    
}

bool passOrNot (int digit, int number)
{
    if (number % digit == 0)
        return false;
    while (number > 0) {
        int q = number % 10;
        if (q == digit)
            return false;
        number /= 10;
    }
    return true;
}

void GameLayer::initAppearance()
{
    Sprite* bgSprite = Sprite::create("bg.png");
    
//    bgSprite->setContentSize(Size(40, 60));
    bgSprite->setPosition(Point(270, 480));
//    bgSprite->setColor(Color3B(250, 248, 239));
    this->addChild(bgSprite);
    Sprite* scoreSprite = Sprite::create("scorebg.png");
    scoreSprite->setPosition(Point(300,800));
    bgSprite->addChild(scoreSprite);
    
    Sprite* bestSprite = Sprite::create("bestbg.png");
    bestSprite->setPosition(Point(450,800));
    bgSprite->addChild(bestSprite);
    
    
}

bool GameLayer::init() {
    bool ret = false;
    do {
        CC_BREAK_IF(!Layer::init());
        
        
        this->initAppearance();
        bool isFirst = UserDefault::getInstance()->getBoolForKey("ISFIRSTTIME");
        if (isFirst) {
            this->showTutorialLayer();
            UserDefault::getInstance()->setBoolForKey("ISFIRSTTIME", true);
        }
        else
        {
            this->showRollingNumberLayer();
        }
        ret = true;
    } while (0);
    return ret;
}

void GameLayer::showTutorialLayer()
{
    CCArray *stringArray = CCArray::create(
                                           ccs("test1.png"),
                                           ccs("test2.png"),
                                           NULL);
    TutorialLayer* tutotialLayer = new TutorialLayer(stringArray, this);
    tutotialLayer->setPosition(Point(0, 0));
    this->addChild(tutotialLayer);
}

void GameLayer::showRollingNumberLayer()
{
    RollingDigitLayer* RLayer = new RollingDigitLayer(this, false);
    RLayer->init();
    RLayer->setPosition(Point(0,0));
    this->addChild(RLayer);
}

void GameLayer::setCurrentDigit(int digit)
{
    _currentDigit = digit;
}

void GameLayer::startGame()
{
    this->schedule(schedule_selector(GameLayer::updateClock), 1.0f);
}

void GameLayer::updateClock(float dt)
{
    
}

void GameLayer::update(float dt)
{
//    CCLOG("updating...");
}