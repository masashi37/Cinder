
#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"	

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"

#include "cinder/audio/NodeEffects.h"

#include "cinder/Rand.h"
#include <ctime>

#include "cinder/Font.h"

#include <memory>

using namespace ci;
using namespace ci::app;


//enum-定数
//-----------------------------------------------

//ウィンドウサイズ
enum Window{
	WIDTH = 500,
	HEIGHT = 500,
	DEPTH = 1000
};

//シーンの名前(No.)
enum SceneName{
	TITLE,		//タイトル
	SELECT,		//選択
	GAME,		//ゲーム画面
	RESULT,		//リザルト
};

