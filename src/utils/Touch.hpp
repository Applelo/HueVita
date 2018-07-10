#ifndef TOUCH_HPP
#define TOUCH_HPP

#include <psp2/touch.h>
#include <string.h>
#include "mathtools.hpp"

#define SLEEP_CLICK_NORMAL 150000
#define SLEEP_CLICK_EXTENDED 350000

#define MIN_DIST_TO_SCROLL_Y 2
#define MIN_DIST_TO_SCROLL_X 2

class Touch{
	public:
		Touch();
		void read();
		SceTouchData touch_old[SCE_TOUCH_PORT_MAX_NUM];
		SceTouchData touch[SCE_TOUCH_PORT_MAX_NUM];
		vector2 getClickPoint();
		vector2 lastClickPoint;
		vector2 lastTouchPoint;
		bool clicking;
		bool scrolling;
		int scrollDirX ;
		int scrollDirY;

	private:
		vector2 emptyClickPoint;
		
};








#endif



