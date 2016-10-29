#ifndef BIKEPARAMS_H
#define BIKEPARAMS_H

struct BikeParams
{
	float m_accel;
	float m_maxSpeed;
	float m_slide;
	int m_ptsToUnlock;
};

class BikeParamsHolder
{
public:
	static void Initialize()
	{
		s_bikes[0] = { 1, 2, 3, 0 };
		s_bikes[1] = { 2, 1, 4, 300 };
		s_bikes[2] = { 4, 2, 1, 600 };
	}

	static BikeParams s_bikes[3];
};


#endif // BIKEPARAMS_H
