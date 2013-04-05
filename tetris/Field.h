#pragma once 
#ifndef FIELD_H
#define FIELD_H

#include "Figure.h"
#include "definit.h"


class Field
{
	char			**matrix;
	//char			matrix[ FIELD_SIZE ][ FIELD_SIZE ];

public:

	Field( );

	void			Draw( const Figure& figureToDraw );
	void			Erase( const Figure& figureToErase );
	void			Show( );

	bool			CanMoveLeft( const Figure& figureToCheck );
	bool			CanMoveRight( const Figure& figureToCheck );
	bool			CanMoveDown( const Figure& figureToCheck );
	bool			CanRotate( const Figure& figureToCheck );

	void			MoveLeft( Figure& figureToMove );
	void			MoveRight( Figure& figureToMove );
	void			MoveDown( Figure& figureToMove );
	void			Rotate( Figure& figureToRotate );

	bool			CheckIsRowFull( const int rowIndex ) const;

	char			*operator [ ] ( int index ){ return matrix[ index ]; }
	char			GetXY( const int x, const int y )const { return matrix[x][y]; }
	void			SetXY( const int x, const int y, const char toSet ) { matrix[ x ][ y ] = toSet; }

	bool			EraseRowIfFull( int rowIndex );

	////
	void			_TEST_ROW_ERASING_( );
	
	~Field( );
};

#endif FIELD_H