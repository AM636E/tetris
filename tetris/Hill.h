#pragma once
#ifndef HILL_H
#define HILL_H
#include "Figure.h"

enum HillPos
{
	UP_HILL_POS,
	LEFT_HILL_POS,  
	DOWN_HILL_POS,
	RIGHT_HILL_POS
};

class Hill: public Figure
{
	HillPos				position;
public:

						Hill( );

	void				InitUpHillPos( );
	void				InitLeftHillPos( );
	void				InitDownHillPos( );
	void				InitRightHillPos( );
	void				Init( );

	bool				Rotate( );
};

#endif HILL_H