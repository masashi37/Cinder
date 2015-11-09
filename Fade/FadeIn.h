
#pragma once

#include "Fade.h"


class FadeIn :public Fade {

private:

public:

	FadeIn();

	//終わったかどうかの判定を返す
	bool getEnd();

	//フルスクリーンで展開されるFadeOut
	//（終了までの時間(秒)）
	void fullScreenFade(int);

	void draw();

};

