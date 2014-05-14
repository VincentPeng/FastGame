//
//  PreGameScene.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#include "PreGameScene.h"
#include "MainGameScene.h"

PreGameScene::PreGameScene()
{
    
}

PreGameScene::~PreGameScene()
{
    
}

bool PreGameScene::init()
{
    bool ret = false;
    CCLOG("PreGameScene::init");
    do {
        Sprite* bgSprite = Sprite::create("Jiker.jpg");
        bgSprite->setPosition(Point(270.0f, 480.0f));
        this->addChild(bgSprite);
        
        auto startItem = MenuItemImage::create(
                                               "buttonPlay.png",
                                               "buttonPlay.png",
                                               CC_CALLBACK_1(PreGameScene::startPressed,this));
        
        Menu* menu = Menu::create(startItem, NULL);
        menu->alignItemsHorizontallyWithPadding(150.0);
        menu->setPosition(270.0f, 300.0f);
        this->addChild(menu);
        ret = true;
    } while(0);
    return ret;
}

void PreGameScene::startPressed(cocos2d::Object *pSender)
{
    auto scene = MainGameScene::create();
    Director::getInstance()->replaceScene(scene);
}
