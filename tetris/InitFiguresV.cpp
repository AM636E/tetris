#include "Figure.h"

void Figure::InitLineVertical( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	for( int i = 1 ; i < 4 ; i ++ )
	{
		figure[ i ].row = figure_0_row + i;

		figure[ i ].col = figure_0_col;

		checkLeft[ i ] = true;
		checkRight[ i ] = true;	
	}
	checkDown[ 3 ] = true;	

	rotateCoords.row = figure_0_row ;
	rotateCoords.col = figure_0_col - 3 ;
}

void Figure::InitLeftZVertical( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	figure[ 1 ].row = figure_0_row + 1;
	figure[ 2 ].row = figure_0_row + 1;
	figure[ 3 ].row = figure_0_row + 2;


	figure[ 1 ].col = figure_0_col;
	figure[ 2 ].col = figure_0_col - 1;
	figure[ 3 ].col = figure_0_col - 1;

	checkDown[ 1 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 0 ] = true;
	checkLeft[ 2 ] = true;
	checkLeft[ 3 ] = true;

	checkRight[ 0 ] = true;
	checkRight[ 1 ] = true;
	checkRight[ 3 ] = true;

	rotateCoords.row = figure_0_row - 2;
	rotateCoords.col = figure_0_col + 1 ;
}

void Figure::InitRightZVertical( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	figure[ 1 ].row = figure_0_row + 1;
	figure[ 2 ].row = figure_0_row + 1;
	figure[ 3 ].row = figure_0_row + 2;

	figure[ 1 ].col = figure_0_col;
	figure[ 2 ].col = figure_0_col + 1;
	figure[ 3 ].col = figure_0_col + 1;

	checkDown[ 1 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 0 ] = true;
	checkLeft[ 1 ] = true;
	checkLeft[ 3 ] = true;

	checkRight[ 0 ] = true;
	checkRight[ 2 ] = true;
	checkRight[ 3 ] = true;	

	rotateCoords.row = figure_0_row - 2;
	rotateCoords.col = figure_0_col - 1;
}

void Figure::InitLeftLVertical( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	for( int i = 1; i < 4; i ++ )
	{
		figure[ i ].row = figure_0_row + ( i - 1 );

		figure[ i ].col = figure_0_col - 1;
	}

	for( int i = 1 ; i < 4 ; i ++ )
		checkLeft[ i ] = true;

	checkDown [ 0 ] = true;
	checkDown [ 3 ] = true;

	checkRight[ 0 ] = true;
	checkRight[ 2 ] = true;
	checkRight[ 3 ] = true;

	rotateCoords.row = figure_0_row;
	rotateCoords.col = figure_0_col - 2 ;
}

void Figure::InitRightLVertical( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;

	for( int i = 1; i < 4; i ++ )
	{
		figure[ i ].row = figure_0_row + ( i - 1 );

		figure[ i ].col = figure_0_col + 1;
	}
	for( int i = 1 ; i < 4 ; i ++ )
		checkRight[ i ] = true;

	checkDown[ 0 ] = true;
	checkDown[ 3 ] = true;

	checkLeft[ 0 ] = true;
	checkLeft[ 2 ] = true;
	checkLeft[ 3 ] = true;

	rotateCoords.row = figure_0_row;
	rotateCoords.col = figure_0_col + 2 ;
}


void Figure::InitVertical( )
{
	int figure_0_row = figure[ 0 ].row;
	int figure_0_col = figure[ 0 ].col;
	switch( type )
	{
	case LINE:
		{
			InitLineVertical( );

			break;
		}
	case LEFT_Z:
		{
			InitLeftZVertical( );

			break;
		}
	case RIGHT_Z:
		{
			InitRightZVertical( );

			break;
		}
	case LEFT_L:
		{
			InitLeftLVertical( );

			break;
		}
	case RIGHT_L:
		{
			InitRightLVertical( );

			break;
		}
	case SQUARE:
		{
			InitSquare( );

			break;
		}
	}
}