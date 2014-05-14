//
//  GameLayer.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#include "GameLayer.h"

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

bool GameLayer::init() {
    bool ret = false;
    do {
        CC_BREAK_IF(!Layer::init());
        
        Sprite* bgsprite = Sprite::create("page_sample.png");
        bgsprite->setPosition(Point(270.0f, 480.0f));
        this->addChild(bgsprite);
        this->schedule(schedule_selector(GameLayer::update), 1 / 60);
        
        ret = true;
    } while (0);
    return ret;
}

void GameLayer::update(float dt)
{
//    CCLOG("updating...");
}