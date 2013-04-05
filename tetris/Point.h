#pragma once
#ifndef POINT_H
#define POINT_H

class Point
{
public:
	int row, col;


	Point( ): row( 0 ), col( 0 ){};
	Point( int row, int col ): row( row ), col( col ){}
	
	bool			MoveDown( );
	bool			MoveLeft( );
	bool			MoveRight( );

};

#endif POINT_H