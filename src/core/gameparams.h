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

	int indicatorSpeedLimits[3];

	int realPtsToUnlock;
};

struct TrackParams
{
	int indicatorLength;
	float realLength;

	int indicatorSlick;
	float realSlick;

	int realPtsToUnlock;

	float realPoints;
};


class BikeParamsHolder
{
public:
	static void Initialize()
	{
		//				accel(i)	accel(r) 	speed(i)	speed(r)	slide(i)	slide(r)	limits		ptsToUnlock
		s_bikes[0] = {	2,			0.5f,		1,			20.f,		2,			0.1f,		{2, 3, 4},	0			};
		s_bikes[1] = {	1,			0.3f,		2,			30.f,		3,			0.05f,		{3, 5, 7},	600			};
		s_bikes[2] = {	4,			1.f,		3,			40.f,		1,			0.4f,		{5, 8, 11},	800			};
	}

	static BikeParams s_bikes[3];
};

class TrackParamsHolder
{
public:
	static void Initialize()
	{
		//				length(i)	length(r)	slick(i)	slick(r)	ptsToUnlock		realPoints
		s_tracks[0] = { 3,			8000.f,		1,			0.5f,		0,				600			};
		s_tracks[1] = { 1,			4000.f,		2,			0.4f,		500,			800			};
		s_tracks[2] = { 2,			6000.f,		3,			0.3f,		700,			1000		};
	}

	static TrackParams s_tracks[3];
};


#endif // BIKEPARAMS_H
