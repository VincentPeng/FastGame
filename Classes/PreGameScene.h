//
//  PreGameScene.h
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#ifndef __DigitMaster__PreGameScene__
#define __DigitMaster__PreGameScene__

#include "cocos2d.h"

USING_NS_CC;

class PreGameScene : public cocos2d::Scene
{
private:
    
    
public:
    PreGameScene();
    ~PreGameScene();
    virtual bool init();
    CREATE_FUNC(PreGameScene);
    void startPressed(Object* pSender);
};

#endif /* defined(__SaveHostage__PreGameScene__) */
