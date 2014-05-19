//
//  TimeModeLayer.h
//  DigitMaster
//
//  Created by 郭 晨 on 5/19/14.
//
//

#ifndef __DigitMaster__TimeModeLayer__
#define __DigitMaster__TimeModeLayer__

#include "GameLayer.h"

USING_NS_CC;

class TimeModeLayer: public GameLayer
{
public:
    TimeModeLayer();
    ~TimeModeLayer();
    CREATE_FUNC(TimeModeLayer);
    virtual bool init();
    virtual void startGame();
    virtual void initAppearance();
    void passItemPressed(Object* pSender);
    void sayItemPressed(Object* pSender);
    void update(float dt);
private:
    ProgressTimer* _timer;
    LabelTTF* _timeLabel;
    LabelTTF* _numberLabel;
    float _timeRemained;
};


#endif /* defined(__DigitMaster__TimeModeLayer__) */
