#include "Hill.h"
#include "definit.h"

#include <ctime>
#include <cstdlib>

Hill::Hill( )
{
	type = HILL;

	isHorisontal = true;
	

	position = static_cast< HillPos >( 0 + rand( ) % 4 );

	indexToMove = 1;

	rotateCoords.row = 0;
	rotateCoords.col = 0;

	figure[ 1 ].row = 1;
	figure[ 1 ].col = FIELD_SIZE / 2;

	Init( );
}

void Hill::InitUpHillPos( )
{
	int	center_row = figure[ 1 ].row;
	int center_col = figure[ 1 ].col;

	figure[ 0 ].row =  center_row;
	figure[ 2 ].row =  center_row;
	figure[ 3 ].row =  center_row - 1; //up from center

	figure[ 0 ].col =  center_col - 1;// left from center
	figure[ 2 ].col =  center_col + 1;//right from center
	figure[ 3 ].col =  center_col ;

	checkDown[ 0 ] = true;
	checkDown[ 1 ] = true;
	checkDown[ 2 ] = true;

	checkLeft[ 0 ] = checkLeft[ 3 ] = true;

	checkRight[ 2 ] = checkRight[ 3 ] = true;

//	rotateCoords.row = center_row + 1;
//	rotateCoords.col = center_col;
}

void Hill::InitLeftHillPos( )
{
	int center_row = figure[ 1 ].row;
	int center_col = figure[ 1 ].col;

	figure[ 0 ].row = center_row - 1;//up from center
	figure[ 2 ].row = center_row + 1;//down from center
	figure[ 3 ].row = center_row;    //the same as center

	figure[ 0 ].col = figure[ 2 ].col = center_col;//in one col
	figure[ 3 ].col = center_col + 1;		   //left from center

	checkDown[ 2 ] = checkDown[ 3 ] = true;

	checkLeft[ 0 ] = checkLeft[ 1 ] = checkLeft[ 2 ] = true;

	checkRight[ 0 ] = checkRight[ 3 ] = checkRight[ 2 ] = true;

//	rotateCoords.row = center_row ;
//	rotateCoords.col = center_col - 1;
}


void Hill::InitDownHillPos( )
{
	int center_row = figure[ 1 ].row;//center row
	int center_col = figure[ 1 ].col;//center col

	figure[ 0 ].row = figure[ 2 ].row = center_row;
	figure[ 3 ].row = center_row + 1; //down from center

	figure[ 0 ].col = center_col - 1;//left from center
	figure[ 2 ].col = center_col + 1;//right from center
	figure[ 3 ].col = center_col;

	checkDown[ 0 ] = checkDown[ 3 ] = checkDown[ 2 ] = true;

	checkLeft[ 0 ] = checkLeft[ 3 ] = true;

	checkRight[ 2 ] = checkRight[ 3 ] = true;

//	rotateCoords.row = center_row - 1;
//	rotateCoords.col = center_col;
}

void Hill::InitRightHillPos( )
{
	int center_row = figure[ 1 ].row;//center row
	int center_col = figure[ 1 ].col;//center col

	figure[ 0 ].row  = center_row - 1;//up from center
	figure[ 2 ].row  = center_row + 1;//down from center
	figure[ 3 ].row  = center_row;    //the same as center

	figure[ 0 ].col  = figure[ 2 ].col = center_col;// same col
	figure[ 3 ].col  = center_col - 1;			    // right from center

	checkDown[ 2 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 0 ] = true;
	checkLeft[ 2 ] = true;
	checkLeft[ 3 ] = true;

	checkRight[ 0 ] = true;
	checkRight[ 1 ] = true;
	checkRight[ 2 ] = true;

//	rotateCoords.row = center_row;
//	rotateCoords.col = center_col + 1;
}

void Hill::Init( )
{
	indexToMove = 1;
	for( int i = 0; i < 4; i ++ )
	{
		checkDown[ i ] = false;
		checkLeft[ i ] = false;
		checkRight[ i ] = false;
	}

	switch( position )
	{
	case UP_HILL_POS:
		{
			InitUpHillPos( );

			break;
		}
	case LEFT_HILL_POS:
		{
			InitLeftHillPos( );

			break;
		}
	case DOWN_HILL_POS:
		{
			InitDownHillPos( );

			break;
		}
	case RIGHT_HILL_POS:
		{
			InitRightHillPos( );

			break;
		}
	}
}

bool Hill::Rotate( )
{
	
		switch( position ) 
		{
		case UP_HILL_POS:
			{
				position = LEFT_HILL_POS;

				break;
			}
		case LEFT_HILL_POS:
			{
				position = DOWN_HILL_POS;

				break;
			}
		case DOWN_HILL_POS:
			{
				position = RIGHT_HILL_POS;

				break;
			}
		case RIGHT_HILL_POS:
			{
				position = UP_HILL_POS;

				break;
			}
		}

		Init( );
	

	return 1;
}