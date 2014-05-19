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
#include <iostream>
#include <random>

USING_NS_CC;
using namespace std;

class GameLayer: public cocos2d::Layer
{
public:
    GameLayer();
    ~GameLayer();
    CREATE_FUNC(GameLayer);
    virtual bool init();
    void setCurrentDigit (int digit);
    void setCurrentNumber (int number);
    int getCurrentDigit ();
    int getCurrentNumber ();
    void showTutorialLayer();
    void showRollingNumberLayer();
    virtual void initAppearance();
    virtual void startGame() ;
    bool passOrNot (int digit, int number);
    int generateRandomDigit();
private:
    int _currentDigit;
    int _currentNumber;
    random_device _rd;
};

#endif /* defined(__DigitMaster__GameLayer__) */
