
#pragma once


class cScene{

protected:

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
	void shift();
	void draw();
};