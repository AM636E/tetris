#include "Figure.h"

void Figure::InitLineHorisontal( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	for( int i = 1 ; i < 4 ; i ++ )
	{
		figure[ i ].row = figure_0_row;
		figure[ i ].col = figure_0_col + i;
		checkDown[ i ] = true;	
	}

	checkDown[ 0 ] = true;

	checkLeft[ 0 ] = true;
	checkRight[ 3 ] = true;

	rotateCoords.row = figure_0_row + 4;
	rotateCoords.col = figure_0_col;
}

void Figure::InitLeftZHorisontal( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;


	figure[ 1 ].row = figure_0_row;
	figure[ 2 ].row = figure_0_row + 1;
	figure[ 3 ].row = figure_0_row + 1;

	figure[ 1 ].col = figure_0_col + 1;
	figure[ 2 ].col = figure_0_col + 1;
	figure[ 3 ].col = figure_0_col + 2;

	checkDown[ 0 ] = true;
	checkDown[ 2 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 0 ] = true;
	checkLeft[ 2 ] = true;

	checkRight[ 1 ] = true;
	checkRight[ 3 ] = true;

	rotateCoords.row = figure_0_row + 3;
	rotateCoords.col = figure_0_col - 1;
}

void Figure::InitRightZHorisontal( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	figure[ 1 ].row = figure_0_row;
	figure[ 2 ].row = figure_0_row + 1;
	figure[ 3 ].row = figure_0_row + 1;

	figure[ 1 ].col = figure_0_col - 1;
	figure[ 2 ].col = figure_0_col - 1;
	figure[ 3 ].col = figure_0_col - 2;

	checkDown[ 0 ] = true;
	checkDown[ 2 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 1 ] = true;
	checkLeft[ 3 ] = true;

	checkRight[ 0 ] = true;
	checkRight[ 2 ] = true;

	rotateCoords.row = figure_0_row + 2;
	rotateCoords.col = figure_0_col + 1;
}

void Figure::InitLeftLHorisontal( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;
	for( int i = 1; i < 4; i ++ )
	{
		figure[ i ].row = figure_0_row + 1;

		figure[ i ].col = figure_0_col + ( i - 1 );
	}

	for( int i = 1 ; i < 4 ; i ++ )
		checkDown[ i ] = true;
	checkLeft [ 0 ] = true;
	checkLeft [ 1 ] = true;

	checkRight[ 3 ] = true;

	rotateCoords.row = figure_0_row + 2;
	rotateCoords.col = figure_0_col;
}

void Figure::InitRightLHorisontal( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	for( int i = 1; i < 4; i ++ )
	{
		figure[ i ].row = figure_0_row + 1;

		figure[ i ].col = figure_0_col - ( i - 1 );
	}
	for( int i = 1 ; i < 4 ; i ++ )
		checkDown[ i ] = true;

	checkLeft[ 3 ] = true;

	checkRight[ 0 ] = true;
	checkRight[ 1 ] = true;

	rotateCoords.row = figure_0_row + 2;
	rotateCoords.col = figure_0_col ;
}

void Figure::InitSquare( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	figure[ 1 ].row = figure_0_row;
	figure[ 2 ].row = figure_0_row + 1;
	figure[ 3 ].row = figure_0_row + 1;

	figure[ 1 ].col = figure_0_col + 1;
	figure[ 2 ].col = figure_0_col;
	figure[ 3 ].col = figure_0_col + 1;

	checkDown[ 2 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 0 ] = true;
	checkLeft[ 2 ] = true;

	checkRight[ 1 ] = true;
	checkRight[ 3 ] = true;
}

void Figure::InitHorisontal( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;
	switch( type )
	{
	case LINE:
		{
			InitLineHorisontal( );

			break;
		}
	case LEFT_Z:
		{
			InitLeftZHorisontal( );

			break;
		}
	case RIGHT_Z:
		{
			InitRightZHorisontal( );

			break;
		}
	case LEFT_L:
		{
			InitLeftLHorisontal( );

			break;
		}
	case RIGHT_L:
		{
			InitRightLHorisontal( );

			break;
		}
	case SQUARE:
		{
			InitSquare( );

			break;
		}
	}
}
