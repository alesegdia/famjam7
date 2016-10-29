#ifndef BIKEPARAMS_H
#define BIKEPARAMS_H

struct BikeParams
{
	int indicatorAccel;
	float realAccel;

	int indicatorMaxSpeed;
	float realMaxSpeed;

	int indicatorSlide;
	float realSlide;

	int indicatorSpeedLimits[2];

	int realPtsToUnlock;
};

class BikeParamsHolder
{
public:
	static void Initialize()
	{
		//				accel(i)	accel(r) 	speed(i)	speed(r)	slide(i)	slide(r)	limits		ptsToUnlock
		s_bikes[0] = {	1,			1.f,		2,			2.f,		3,			3.f,		{2, 3},		0			};
		s_bikes[1] = {	2,			2.f,		1,			1.f,		4,			4.f,		{2, 3},		300			};
		s_bikes[2] = {	4,			4.f,		3,			3.f,		1,			1.f,		{2, 4},		600			};
	}

	static BikeParams s_bikes[3];
};


#endif // BIKEPARAMS_H
