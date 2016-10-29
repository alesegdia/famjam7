#ifndef TRACKPARAMS_H
#define TRACKPARAMS_H


struct TrackParams
{
	float m_dist;
	float m_maxSpeed;
	float m_slide;
};

class TrackParamsHolder
{
public:
	static void Initialize()
	{
		s_tracks[0] = { 1, 2, 3 };
		s_tracks[1] = { 2, 1, 4 };
		s_tracks[2] = { 4, 2, 1 };
	}

	static TrackParams s_tracks[3];
};


#endif // TRACKPARAMS_H
