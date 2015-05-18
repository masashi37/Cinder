
#pragma once
#include "arrowStatus.h"


class cArrowMove :public cArrowStatus{

public:

	float direction(MouseEvent);
	void shootPrepare();
	void shootArrow();

};