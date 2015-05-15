
#include "arrowMove.h"


float cArrowMove::direction(MouseEvent event, Vec2f& arrow_pos){

	mouse_pos = event.getPos();
	Vec2f vec1 = Vec2f(0, -1.0f);		//
	Vec2f vec2 = mouse_pos - arrow_pos;		//マウスと弓のベクトル

	//ノーマライズ
	vec2.normalize();

	//内積ベクトル
	float d = vec1.dot(vec2);

	// 内積のアークコサインで角度
	float radian = acos(d);

	//console() << d << std::endl;

	return radian;


}

void cArrowMove::shoot(MouseEvent event){}