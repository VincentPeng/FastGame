//
//  RollingDigitLayer.h
//  DigitMaster
//
//  Created by 郭 晨 on 5/17/14.
//
//

#ifndef __DigitMaster__RollingDigitLayer__
#define __DigitMaster__RollingDigitLayer__

class GameLayer;
#include "cocos2d.h"

USING_NS_CC;

class RollingDigitLayer: public cocos2d::Layer
{
public:
    RollingDigitLayer(GameLayer* parentGameLayer, bool ISFIRSTTIME);
    ~RollingDigitLayer();
//    CREATE_FUNC(RollingDigitLayer);
    virtual bool init();
    void startPressed (Object* pObject);
private:
    GameLayer* _parentGameLayer;
    bool _isFirst;
};


#endif /* defined(__DigitMaster__RollingDigitLayer__) */
