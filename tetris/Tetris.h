#pragma once
#ifndef TETRIS_H
#define TETRIS_H

#include "Field.h"
#include "Hill.h"

class Tetris
{
	Field				*field;
	Figure				*figure;

	int					level;
	int					speed;

	char				choise;
	char				*input;
	int					input_pos;

	int					score;
	//int					level;

public:
						Tetris( );

	void				Input( );
	static void 		InputWrapper( void *ptr )
	{
		static_cast< Tetris * >( ptr ) ->Input( ) ;
	}

	void				StartGame( );
	void				PauseGame( );
	void				StopGame( );
	void				SaveGame( );
	void				RestoreGame( );

						~Tetris( );

};

#endif TETRIS_H