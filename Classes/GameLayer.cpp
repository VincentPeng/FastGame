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

bool GameLayer::passOrNot (int digit, int number)
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
    
}

void GameLayer::startGame()
{
    
}

int GameLayer::generateRandomDigit()
{
    int ret = 0;
    while (ret == 0 || ret == 5 || ret == 2 || ret == 1)
        ret = _rd() % 200;
    return ret;
}

bool GameLayer::init() {
    bool ret = false;
    do {
        CC_BREAK_IF(!Layer::init());
        
        for (int i = 0;i < 100;i++)
        {
            cout<<generateRandomDigit()<<endl;
        }
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

int GameLayer::getCurrentDigit()
{
    return _currentDigit;
}

void GameLayer::setCurrentNumber(int number)
{
    _currentNumber = number;
}

int GameLayer::getCurrentNumber()
{
    return _currentNumber;
}

