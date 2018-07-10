#ifndef PAD_HPP
#define PAD_HPP

#include <psp2/ctrl.h>


#define DEADZONE 25


class Pad{
	
	public:
		Pad();
		~Pad();
		void read();
		bool up , right , down , left , cross , circle , triangle , square , lefttrigger , righttrigger , start , select, volup , voldown;
		bool left_analog_moving , right_analog_moving;
		int left_analog_calibrated_x , left_analog_calibrated_y , right_analog_calibrated_x , right_analog_calibrated_y;
		unsigned char lx , ly , rx , ry;
		
	private:
		unsigned char left_analog_calibration_x = 128;
		unsigned char left_analog_calibration_y = 128;
		unsigned char right_analog_calibration_x = 128;
		unsigned char right_analog_calibration_y = 128;
		int buttonAssign = -1;
		int checkButtonAssign();
		SceCtrlData vitapad;
	
};


#endif




