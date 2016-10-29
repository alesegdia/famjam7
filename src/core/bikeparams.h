#ifndef BIKEPARAMS_H
#define BIKEPARAMS_H

struct BikeParams
{
	int m_accel;
	int m_maxSpeed;
	int m_slide;
	int m_speedLimits[2];
	int m_ptsToUnlock;
};

class BikeParamsHolder
{
public:
	static void Initialize()
	{
		s_bikes[0] = { 1, 2, 3, {2, 3}, 0 };
		s_bikes[1] = { 2, 1, 4, {2, 3}, 300 };
		s_bikes[2] = { 4, 3, 1, {2, 4}, 600 };
	}

	static BikeParams s_bikes[3];
};


#endif // BIKEPARAMS_H
