//
//  GameLayer.h
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#ifndef __DigitMaster__GameLayer__
#define __DigitMaster__GameLayer__

#include "cocos2d.h"

USING_NS_CC;

class GameLayer: public cocos2d::Layer
{
public:
    GameLayer();
    ~GameLayer();
    CREATE_FUNC(GameLayer);
    virtual bool init();
    void update(float dt);
    void setCurrentDigit (int digit);
    void showTutorialLayer();
    void showRollingNumberLayer();
    void initAppearance();
    void startGame();
    void updateClock(float dt);
private:
    int _currentDigit;
};

#endif /* defined(__DigitMaster__GameLayer__) */
