
#pragma once

#include "SceneBase.h"
#include "Arrow.h"


typedef std::shared_ptr<class Title>TitleSP;
class Title :public SceneBase{

private:

	ArrowSP arrow = ArrowSP(new Arrow);

	//----------------------------------------------------

public:

	void init();
	void update();
	void shift();
	void draw();

	void mouseDown(MouseEvent);
	void mouseMove(MouseEvent);
	void mouseUp(MouseEvent);
};
