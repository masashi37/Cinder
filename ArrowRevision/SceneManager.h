
#pragma once

#include "common.h"

#include "Title.h"


typedef std::shared_ptr<class SceneManager>SceneManagerSP;
class SceneManager{

private:

	TitleSP title = TitleSP(new Title);

public:

	void init();
	void update();
	void shift();
	void draw();

	void mouseDown(MouseEvent);
	void mouseMove(MouseEvent);
	void mouseUp(MouseEvent);
};

