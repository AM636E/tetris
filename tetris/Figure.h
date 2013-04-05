#pragma once
#ifndef FIGURE_H
#define FIGURE_H
#include "Point.h"

enum FigureType
{
	LINE = 0,

	LEFT_Z,  //1
	RIGHT_Z, //2

	LEFT_L,  //3
	RIGHT_L, //4
	
	SQUARE,  //5

	HILL     //6
};

class Figure
{
protected:
	Point   	figure[ 4 ];
	int			indexToMove;

	bool		isHorisontal;
	
public:

	FigureType			type;

	Point				rotateCoords;
	bool			    checkDown [ 4 ];
	bool				checkLeft [ 4 ];
	bool				checkRight[ 4 ];

public:

						Figure( );
						Figure( FigureType type );
						Figure( const FigureType type, const Point *coordinates );
						
	Point				operator [ ]( int index )const{ return this ->figure[ index ]; }
	Point				GetFigure( int index )const{ return figure[ index ] ; }				

	void				InitLineVertical( );
	void				InitLeftZVertical( );
	void				InitRightZVertical( );
	void				InitLeftLVertical( );
	void				InitRightLVertical( );
	void				InitSquare( );
	void				InitVertical( );

	void				InitLineHorisontal( );
	void				InitLeftZHorisontal( );
	void				InitRightZHorisontal( );
	void				InitLeftLHorisontal( );
	void				InitRightLHorisontal( );
	void				InitHorisontal( );

	virtual void		Init( );

	bool				MoveDown( );
	bool				MoveLeft( );
	bool				MoveRight( );

	virtual bool		Rotate( ) ;

	void				SetType( FigureType value ){ type = value; }
	void				SetHorisotal( bool value ){ isHorisontal = value; }
	void				SetPoint( const int index, const Point& value ){ figure[ index ] = value; } 
};

#endif FIGURE_H