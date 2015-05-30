
#pragma once

#include "common.h"
#include "title.h"
#include "select.h"
#include "game.h"


class cScene{

private:

	cTitle title;
	cSelect select;
	cGame game;

	int scene_mover;	//シーンを切り替えるスイッチ

public:

	cScene::cScene();

	void init();
	void update();
	void shift();
	void draw();

	void keyDown(KeyEvent);
	void keyUp(KeyEvent);

	//void mouseDown(MouseEvent);
	//void mouseUp(MouseEvent);
	//void mouseMove(MouseEvent);
};