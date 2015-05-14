
#pragma once

#include "title.h"


class cScene{

private:

	cTitle title;

	//シーンの名前(No.)
	enum SceneName{
		TITLE,
		SELECT,
		GAME,
		RESULT,
	};

	int scene_mover;	//シーンを切り替えるスイッチ

public:

	cScene();

	void setup();
	void update();
	void keyDown(KeyEvent);
	void keyUp(KeyEvent);
	void shift();
	void draw();
};