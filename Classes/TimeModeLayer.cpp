//
//  TimeModeLayer.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/19/14.
//
//

#include "TimeModeLayer.h"
#include <random>

TimeModeLayer::TimeModeLayer()
{
    
}

TimeModeLayer::~TimeModeLayer()
{
    
}

void TimeModeLayer::startGame()
{
    _timeRemained = 60.0;
    int startNumber = GameLayer::generateRandomDigit();
    setCurrentNumber(startNumber);
    _numberLabel->setString(to_string(startNumber));
    _timeLabel->setString(to_string(60));
    this->schedule(schedule_selector(TimeModeLayer::update), 0.1);
}

/*
bool TimeModeLayer::passOrNot(int digit, int number)
{
    return this->GameLayer::passOrNot(digit, number);
}*/

bool TimeModeLayer::init()
{
    if (GameLayer::init())
    {
        return true;
    }
    else
        return false;
}

void TimeModeLayer::initAppearance()
{
    GameLayer::passOrNot(1, 2);
    
    Sprite* bgSprite = Sprite::create("bg.png");
    bgSprite->setPosition(Point(270, 480));
    this->addChild(bgSprite);
    
    Sprite* scoreSprite = Sprite::create("scorebg.png");
    scoreSprite->setPosition(Point(350,825));
    bgSprite->addChild(scoreSprite);
    LabelTTF* scorelabel = LabelTTF::create("10", "Helvetica", 30);
    scorelabel->setHorizontalAlignment(TextHAlignment::CENTER);
    scorelabel->setColor(Color3B(255, 255, 255));
    scorelabel->setPosition(Point(50, 30));
    scoreSprite->addChild(scorelabel);
    
    Sprite* bestSprite = Sprite::create("bestbg.png");
    bestSprite->setPosition(Point(475,825));
    bgSprite->addChild(bestSprite);
    LabelTTF* bestlabel = LabelTTF::create("100", "Helvetica", 30);
    bestlabel->setHorizontalAlignment(TextHAlignment::CENTER);
    bestlabel->setColor(Color3B(255, 255, 255));
    bestlabel->setPosition(Point(50, 30));
    bestSprite->addChild(bestlabel);
    
    Sprite* timerSprite = Sprite::create("doublecircle.png");
    _timer = ProgressTimer::create(timerSprite);
    _timer->setType(ProgressTimer::Type::RADIAL);
    _timer->setReverseDirection(true);
    _timer->setPercentage(100.0f);
    _timer->setPosition(Point(350, 700));
    this->addChild(_timer);
    
    Sprite* innerSprite = Sprite::create("browncircle.png");
    innerSprite->setPosition(50,50);
    _timer->addChild(innerSprite);
    
    LabelTTF* timelabel = LabelTTF::create("59", "Helvetica", 50);
    timelabel->setHorizontalAlignment(TextHAlignment::CENTER);
    timelabel->setColor(Color3B(255, 255, 255));
    timelabel->setPosition(Point(50, 50));
    _timeLabel = timelabel;
    _timer->addChild(timelabel);
    
    Sprite* digitSprite = Sprite::create("digitbg.png");
    digitSprite->cocos2d::Node::setPosition(Point(150, 770));
    this->addChild(digitSprite);
    
    LabelTTF* digitlabel = LabelTTF::create("3", "Helvetica", 70);
    digitlabel->setHorizontalAlignment(TextHAlignment::CENTER);
    digitlabel->setColor(Color3B(255, 255, 255));
    digitlabel->setPosition(Point(120, 75));
    digitSprite->addChild(digitlabel);
    
    Sprite* numberSprite = Sprite::create("numberbg.png");
    numberSprite->cocos2d::Node::setPosition(Point(270, 450));
    this->addChild(numberSprite);
    
    LabelTTF* numberlabel = LabelTTF::create("30", "Helvetica", 70);
    numberlabel->setHorizontalAlignment(TextHAlignment::CENTER);
    numberlabel->setColor(Color3B(255, 255, 255));
    numberlabel->setPosition(Point(100, 100));
    _numberLabel = numberlabel;
    numberSprite->addChild(numberlabel);
    
    auto passItem = MenuItemImage::create(
                                           "pass.png",
                                           "passdeep.png",
                                          CC_CALLBACK_1(TimeModeLayer::passItemPressed,this));
    auto sayItem = MenuItemImage::create(
                                          "say.png",
                                          "saydeep.png",
                                          CC_CALLBACK_1(TimeModeLayer::sayItemPressed,this));
    
    Menu* menu = Menu::create(passItem,sayItem, NULL);
    menu->alignItemsHorizontallyWithPadding(150.0);
    menu->setPosition(270.0f, 200.0f);
    this->addChild(menu);
}

void TimeModeLayer::passItemPressed(Object* pSender)
{
    if (passOrNot(getCurrentDigit(), getCurrentNumber()))
    {
        int newnumber = generateRandomDigit();
        setCurrentNumber(newnumber);
        _numberLabel->setString(to_string(newnumber));
    }
}

void TimeModeLayer::sayItemPressed(Object* pSender)
{
    if (!passOrNot(getCurrentDigit(), getCurrentNumber()))
    {
        int newnumber = generateRandomDigit();
        setCurrentNumber(newnumber);
        _numberLabel->setString(to_string(newnumber));
    }
}

void TimeModeLayer::update(float dt)
{
    _timeRemained = _timeRemained - dt;
    _timer->setPercentage((_timeRemained / 60.0) * 100.0);
    _timeLabel->setString(to_string((int)_timeRemained));
}



