#ifndef TRACKPARAMS_H
#define TRACKPARAMS_H


struct TrackParams
{
	float m_dist;
	float m_slick;
	int m_ptsToUnlock;
};

class TrackParamsHolder
{
public:
	static void Initialize()
	{
		s_tracks[0] = { 1, 4, 0 };
		s_tracks[1] = { 2, 3, 500 };
		s_tracks[2] = { 4, 1, 600 };
	}

	static TrackParams s_tracks[3];
};


#endif // TRACKPARAMS_H
