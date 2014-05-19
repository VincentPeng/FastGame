//
//  RollingDigitLayer.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/17/14.
//
//

#include "RollingDigitLayer.h"
#include "GameLayer.h"
#include "Contants.h"

RollingDigitLayer::RollingDigitLayer(GameLayer* parentGLayer, bool firstime)
{
    _parentGameLayer = parentGLayer;
    _isFirst = firstime;
}

RollingDigitLayer::~RollingDigitLayer()
{
    
}

bool RollingDigitLayer::init()
{
    bool ret = false;
    do {
        this->setTag(RollingDigitLayerTag);
        auto startItem = MenuItemImage::create(
                                               "buttonPlay.png",
                                               "buttonPlay.png",
                                               CC_CALLBACK_1(RollingDigitLayer::startPressed,this));
        
        Menu* menu = Menu::create(startItem, NULL);
        menu->alignItemsHorizontallyWithPadding(150.0);
        menu->setPosition(270.0f, 300.0f);
        this->addChild(menu);
        ret = true;
    } while (0);
    return ret;
}

void RollingDigitLayer::startPressed(cocos2d::Object *pObject)
{
    _parentGameLayer->setCurrentDigit(3);
    if (_isFirst)
    {
        _parentGameLayer->removeChildByTag(TutorialLayerTag);
    }
    else
    {
        _parentGameLayer->removeChildByTag(RollingDigitLayerTag);
    }
    _parentGameLayer->startGame();
}

