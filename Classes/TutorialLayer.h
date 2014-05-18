//
//  TutorialLayer.h
//  DigitMaster
//
//  Created by 郭 晨 on 5/16/14.
//
//

#ifndef __DigitMaster__TutorialLayer__
#define __DigitMaster__TutorialLayer__

class GameLayer;

#include "cocos2d.h"
#include "UIScrollView.h"
#include "UIPageView.h"
#include "UIImageView.h"

USING_NS_CC;
using namespace cocos2d::gui;

class TutorialLayer: public cocos2d::Layer
{
public:
    TutorialLayer(CCArray* images, GameLayer* parentGameLayer);
    ~TutorialLayer();
//    CREATE_FUNC(TutorialLayer);
    virtual bool init();
    void startPressed (Object* pObject);
private:
    PageView* pagedView;
    GameLayer* _parentGameLayer;
};

#endif /* defined(__DigitMaster__TutorialLayer__) */
