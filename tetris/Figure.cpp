#include "Figure.h"
#include "definit.h"

#include <ctime>
#include <cstdlib>

Figure::Figure( )
{
	srand( time( 0 ) );

	type = FigureType( 0 + rand( ) % 5 );

	isHorisontal = true;
	

	indexToMove = 0;

	figure[ 0 ].row = 1;
	figure[ 0 ].col = FIELD_SIZE / 2;

	Init( );
}

Figure::Figure( FigureType type )
{
	this ->type = type;

	isHorisontal = true;
	

	figure[ 0 ].row = 0;
	figure[ 0 ].col = FIELD_SIZE / 2;

	Init( );
}

Figure::Figure( const FigureType type, const Point *coordinates )
{
	this ->type = type;

	for( int i = 0; i < 4; i ++ )
	{
		figure[ i ].row = coordinates[ i ].row;
		figure[ i ].col = coordinates[ i ].col;
	}

	Init( );
}

void Figure::Init( )
{
	indexToMove = 0;
	for( int i = 0 ; i < 4; i ++ )
	{
		checkDown[ i ] = false;
		checkLeft[ i ] = false;
		checkRight[ i ] = false;
	}

	if( isHorisontal )
	{
		InitHorisontal( );

		return ;
	}
	InitVertical( );
}

bool Figure::MoveDown( )
{
	return figure[ indexToMove ].MoveDown( );
}

bool Figure::MoveLeft( )
{
	return figure[ indexToMove ].MoveLeft( );
}

bool Figure::MoveRight( )
{
	return figure[ indexToMove ].MoveRight( );
}

bool Figure::Rotate( )
{	
		isHorisontal = !isHorisontal;

		return 1;//randon number
}