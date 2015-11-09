
#pragma once

#include "Fade.h"


class FadeOut :public Fade {

private:

public:

	FadeOut();

	//終わったかどうかの判定を返す
	bool getEnd();

	//フルスクリーンで展開されるFadeOut
	//（ 終了までの時間（秒））
	void fullScreenFade(int);
	//画面中心の円の拡縮とα値変化でFadeOut
	//（ 終了までの時間（秒））
	void circleScalingFade(int);
	//垂れ幕式FadeOut
	//( 終了までの秒数(int))
	void veilDownFade(int);
	//カーテン式(進行方向←)FadeOut
	//( 終了までの秒数(int))
	void fromLeftCurtainFade(int);
	//カーテン式(進行方向→)FadeOut
	//( 終了までの秒数(int))
	void fromRightCurtainFade(int);
	//中央カーテン式FadeOut
	//( 終了までの秒数(int))
	void centerCurtainFade(int);
	//ピンホール式FadeOut
	//※２つ目の引数に入った値が画面を覆う範囲を超えたら強制で完全にOutするように変更する
	//( 終了までの秒数(int), 終了時の円の大きさ(float), 円の分割数(int))
	void pinHoleFade(int, float, int);

	void draw();

};