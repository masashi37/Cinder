
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"


class cScene{

private:

	cTitle title;
	cSelect select;

	//シーンの名前(No.)
	enum SceneName{
		TITLE,
		SELECT,
		GAME,
		RESULT,
	};

	int scene_mover;	//シーンを切り替えるスイッチ

public:

	void setup();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);
};