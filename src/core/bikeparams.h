#ifndef BIKEPARAMS_H
#define BIKEPARAMS_H

struct BikeParams
{
	float m_accel;
	float m_maxSpeed;
	float m_slide;
};

class BikeParamsHolder
{
public:
	static void Initialize()
	{
		s_bikes[0] = { 1, 2, 3 };
		s_bikes[1] = { 2, 1, 4 };
		s_bikes[2] = { 4, 2, 1 };
	}

	static BikeParams s_bikes[3];
};


#endif // BIKEPARAMS_H
