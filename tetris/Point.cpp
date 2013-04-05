#include "Point.h"

#include "definit.h"

bool Point::MoveDown( )
{
	if( row < FIELD_SIZE - 1 )
	{
		row ++;

		return true;
	}
	return false;
}


bool Point::MoveLeft( )
{
	if( col > 0 )
	{
		col --;

		return false;
	}
	return true;
}
bool Point ::MoveRight( )
{
	if( col < FIELD_SIZE - 1 )
	{
		col ++;
		return true;
	}
	return false;
}
