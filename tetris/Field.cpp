#include "Field.h"

#include "definit.h"

#include <iostream>
using namespace std;

Field::Field( )
{
	matrix = new char *[ FIELD_SIZE ];

	for( int i = 0; i < FIELD_SIZE; i ++ )
	{
		matrix[ i ] = new char[ FIELD_SIZE ];

		for( int j = 0; j < FIELD_SIZE; j ++ )
		{
			matrix[ i ][ j ] = FIELD_LETTER;
		}
	}
}

void Field::Draw( const Figure& currFigure )
{
	for( int i = 0; i < 4; i ++ )
	{
		matrix [ currFigure[ i ].row ][ currFigure[ i ].col ] = FIGURE_LETTER;
	}
}

void Field::Erase( const Figure& currFigure  )
{
	for( int i = 0; i < 4; i ++ )
	{
		matrix [ currFigure[ i ].row ][ currFigure[ i ].col ] = FIELD_LETTER;
	}
}

const char gap[ 80 ] = "          ";

void Field::Show( )
{
	system( "cls" );
	cout << gap << "+";
	for( int k = 0; k < FIELD_SIZE; k ++ )
	{
		cout << "-";
	}
	cout << "+" << endl;
	for( int i = 0; i < FIELD_SIZE; i ++ )
	{	
		if( i != FIELD_SIZE / 2 ) 
		{
			cout << gap ;
		}
		else
		{
			cout << "    ";
			cout << "<=";
			cout << " ===";
		}
		cout << "|";

		

		for( int j = 0; j < FIELD_SIZE; j ++ )
		{			
			cout << matrix[ i ][ j ] ;
		}


		cout << "|";
		if( i != FIELD_SIZE / 2 )
			cout << gap;
		else
		{
			cout << "=== ";
			cout << "=>";
			cout << "    " ;
		}
		cout << endl;
	}

	cout << gap << "+";
	for( int i = 0 ; i < FIELD_SIZE; i ++ )
		cout << "-" ;
	cout << "+" << endl;
}

bool Field::CanMoveDown( const Figure& currFigure )
{
	for( int i = 0; i < 4; i ++ )
	{
		if( !currFigure.checkDown[ i ] )
			continue;

		if( currFigure[ i ].row >= FIELD_SIZE - 1 )
			return false;
		if( matrix [ currFigure[ i ].row + 1 ][ currFigure[ i ].col ] == FIGURE_LETTER )
			return false;
	}

	return true;
}

bool Field::CanMoveLeft( const Figure& currFigure )
{
	for( int i = 0; i < 4; i ++ )
	{
		if( !currFigure.checkLeft[ i ] )
			continue;

		if( currFigure[ i ].col <= 0 )
			return false;
		if( matrix[ currFigure[ i ].row ][ currFigure[ i ].col - 1 ]  == FIGURE_LETTER )
			return false;
	}
	return true;
}

bool Field::CanMoveRight( const Figure& currFigure )
{
	for( int i = 0; i < 4; i ++ )
	{
		if( !currFigure.checkRight[ i ] )
			continue;

		if( currFigure[ i ].col > FIELD_SIZE - 2 )
		{

			return false;
		}
		if( matrix[ currFigure[ i ].row ][ currFigure[ i ].col + 1 ] == FIGURE_LETTER )
			return false;
	}
	return true;
}

void Field::MoveDown( Figure& currFigure )
{
	if( !CanMoveDown( currFigure ) )
		return;
	Erase( currFigure );

	currFigure.MoveDown( );
	currFigure.Init( );

	Draw( currFigure );

	Show( );
}

void Field::MoveLeft( Figure& currFigure )
{
	if( !CanMoveLeft( currFigure ) )
		return ;

	Erase( currFigure );

	currFigure.MoveLeft( );
	currFigure.Init( );

	Draw( currFigure );

	Show( );
}

void Field :: MoveRight( Figure& currFigure )
{
	if( !CanMoveRight( currFigure ) )
		return;

	Erase ( currFigure );

	currFigure.MoveRight( );
	currFigure.Init( );

	Draw( currFigure );

	Show( );
}

void Field::Rotate( Figure& figureToRotate )
{
	if( !CanRotate( figureToRotate ) )
		return ;

	Erase( figureToRotate );

	figureToRotate.Rotate( );

	figureToRotate.Init( );

	Draw( figureToRotate );

	Show( );
}


bool Field::CheckIsRowFull( const  int rowIndex ) const
{
	if( rowIndex < 0 || rowIndex > FIELD_SIZE )
		return false;

	for( int i = 0, j = FIELD_SIZE - 1; i < FIELD_SIZE / 2; i ++, j -- )
	{
		if( 
			matrix[ rowIndex ][ i ] != FIGURE_LETTER
			||
			matrix[ rowIndex ][ j ] != FIGURE_LETTER
			)
			return false;
	}

	return true;
}

bool Field::EraseRowIfFull( const int rowIndex )
{
	if( !CheckIsRowFull ( rowIndex ) )
		return false;

	for( int i = rowIndex; i > 0; i -- )
	{
		for( int j = 0; j < FIELD_SIZE; j ++ )
		{
			matrix[ i ][ j ] = matrix[ i - 1 ][ j ];
		}
	}

	return true;
}

bool Field::CanRotate( const Figure& figureToCheck )
{
	if( figureToCheck.rotateCoords.row >= FIELD_SIZE )
		return false;

	if( figureToCheck.rotateCoords.col < 0 || figureToCheck.rotateCoords.col >= FIELD_SIZE )
		return false;

	if( matrix[ figureToCheck.rotateCoords.row + 1 ][ figureToCheck.rotateCoords.col ] == FIGURE_LETTER )
		return false;

	return true;
}

void Field::_TEST_ROW_ERASING_( )
{
	for( int i = FIELD_SIZE - 1; i >= FIELD_SIZE - 3; i -- )
	{
		for( int j = 0; j < FIELD_SIZE; j ++ )
		{
			matrix[ i ][ j ] = FIGURE_LETTER;
		}
	}
}

Field::~Field( )
{
	if( matrix )
	{
		for( int i = 0; i < FIELD_SIZE; i ++ )
			delete matrix[ i ];
		delete [] matrix;
	}
}
