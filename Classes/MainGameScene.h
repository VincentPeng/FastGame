//
//  MainGameScene.h
//  DigitMaster
//
//  Created by 郭 晨 on 5/14/14.
//
//

#ifndef __DigitMaster__MainGameScene__
#define __DigitMaster__MainGameScene__

#include "cocos2d.h"
#include "GameLayer.h"
#include "TimeModeLayer.h"

class MainGameScene : public cocos2d::Scene
{
private:
    
    
public:
    MainGameScene();
    ~MainGameScene();
    virtual bool init();
    CREATE_FUNC(MainGameScene);
    void showTutorialLayer();
    CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
};

#endif /* defined(__DigitMaster__MainGameScene__) */
