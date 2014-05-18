//
//  TutorialLayer.cpp
//  DigitMaster
//
//  Created by 郭 晨 on 5/16/14.
//
//

#include "TutorialLayer.h"
#include "Contants.h"
#include "RollingDigitLayer.h"

TutorialLayer::TutorialLayer(CCArray* images, GameLayer* parentGameLayer)
{
    _parentGameLayer = parentGameLayer;
    this->setTag(TutorialLayerTag);
    pagedView = PageView::create();
    pagedView->setTouchEnabled(true);
    pagedView->setLayoutType(LAYOUT_LINEAR_HORIZONTAL);
    pagedView->setSize(Size(540, 960));
    pagedView->setBackGroundColor(Color3B(50, 50, 50));
//    pagedView->setContentSize(Size(540 * (images->count() + 1), 960));
//    Layer* contentLayer = Layer::create();
//    contentLayer->setContentSize(Size(540 * (images->count() + 1), 960));
    
    for (int i = 0; i < images->count(); i++) {
        CCString* imgName = (CCString*)images->getObjectAtIndex(i);
        Sprite* imgSprite = Sprite::create();
        imgSprite->setTexture(imgName->_string);
        imgSprite->setPosition(Point(270, 480));
        Layout* newLayout = Layout::create();
        newLayout->setSize(pagedView->getSize());
        newLayout->setBackGroundColor(Color3B(0, 255, 0));
        newLayout->addNode(imgSprite);
        pagedView->insertPage(newLayout, 0);
    }
    Layout* newLayout = Layout::create();
    newLayout->setSize(pagedView->getSize());
    newLayout->setBackGroundColor(Color3B(0, 255, 0));
    
    RollingDigitLayer* RLayer = new RollingDigitLayer(_parentGameLayer, true);
    RLayer->init();
    RLayer->setPosition(Point(270,480));
    
    newLayout->addNode(RLayer);
    pagedView->addPage(newLayout);
    
    pagedView->setAnchorPoint(Point(0.5, 0.5));
    pagedView->setPosition(Point(0,0));
    this->addChild(pagedView);
}

TutorialLayer::~TutorialLayer()
{
    
}

void TutorialLayer::startPressed(cocos2d::Object *pObject)
{
    CCLOG("Tutorial layer start pressed...");
    this->removeFromParent();
}

bool TutorialLayer::init()
{
    bool ret = false;
    do {
        ret = true;
    } while (0);
    return ret;
}