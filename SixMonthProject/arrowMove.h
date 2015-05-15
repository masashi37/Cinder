
#pragma once
#include "common.h"


class cArrowMove{
	
private:

	Vec2f mouse_pos;		//マウスポジション
	
	public:

		float direction(MouseEvent, Vec2f&);
		void shoot(MouseEvent);

};