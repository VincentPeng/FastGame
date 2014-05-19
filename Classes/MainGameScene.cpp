//
//  MainGameScene.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#include "MainGameScene.h"

MainGameScene::MainGameScene()
{
    
}

MainGameScene::~MainGameScene()
{}



bool MainGameScene::init() {
    bool ret = false;
    CCLOG("MainGameScene::init");
    do {
        CC_BREAK_IF(!Scene::init());
        _gameLayer = GameLayer::create();
//        _gameLayer->setPosition(Point(0,0));
        TimeModeLayer* timeLayer = TimeModeLayer::create();
        this->addChild(timeLayer);
       
        ret = true;
    } while(0);
    return ret;
}


