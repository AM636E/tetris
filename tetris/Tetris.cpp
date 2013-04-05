#include "Tetris.h"

#include "definit.h"

#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <process.h>
#include <Windows.h>

using namespace std;

Tetris::Tetris( )
{
	speed = START_SPEED;
	level = 1;

	field = new Field;


	input = new char;
	input_pos = -1;

	score = 0;
	level = 1;

	figure = 0;
}

bool continue_ex = true;

void Tetris::StartGame( )
{
	srand( static_cast< unsigned >( time( 0 ) ) ) ;

	int type = 0;
	char ch = 0;
	
	bool isOk = true;
	while ( isOk )
	{
		isOk = false;
		type = 0 + rand( ) % 8;
		if( type < HILL )
		{
			figure = new Figure( static_cast<FigureType>( type ) );
		}
		else
		{
			figure = new Hill;
		}
		//figure = new Hill;
		//cout << figure ->type << endl;

		while( field ->CanMoveDown( *figure ) )
		{			
			isOk = true;
			while( !_kbhit( ) && field ->CanMoveDown( *figure ) )
			{
				field ->MoveDown( *figure );

				Sleep( speed );		
			}

			//_beginthread( Tetris::InputWrapper, 0, static_cast< void *> ( this ) );

			while( _kbhit( ) )
			{				
				choise = _getch( );
				switch( choise )
				{
				case 'a':
					{
						field ->MoveLeft( *figure );

						break;
					}
				case 'd' :
					{
						field ->MoveRight( *figure );

						break;
					}
				case 's':
					{
						field ->MoveDown( *figure );

						break;
					}
				case 'r':
					{
						field ->Rotate( *figure );

						break;
					}
				case 'l':
					{
						field ->_TEST_ROW_ERASING_( );

						break;
					}
				case 'm':
					{
						SaveGame( );

						return ;
					}
				case 'n':
					{
						RestoreGame( );

						break;
					}
				}
			//	cout << "| Score : " << score << " | " << "Level : " << level << " | " << endl;
			}
		}

		while( field ->EraseRowIfFull( figure ->GetFigure( 3 ).row ) )
		{
			score += 1000;
		}
		while( field ->EraseRowIfFull( figure ->GetFigure( 2 ).row ) ) 
		{
			score += 1000;
		}
		while( field ->EraseRowIfFull( figure ->GetFigure( 1 ).row ) ) 
		{
			score += 1000;
		}
		while( field ->EraseRowIfFull( figure ->GetFigure( 0 ).row ) ) 
		{
			score += 1000;
		}

		if( score >= ( SCORE_TO_NEXT_LEVEL * level ) )
		{
			level ++;
		}


		

		if( figure )
			delete figure;

	}
	figure = 0;
}

void Tetris::SaveGame( )
{
	char *filename = new char[ 260 ];

	/*cout << "Enter a file name ( less than 255 symbols ) " << endl;
	cin >> filename ;

	strcat( filename, ".save" );*/
	strcpy( filename, "player.save" );

	ofstream file( filename );

	if( !file )
	{
		cout << "Cant create file to save game " << endl;

		return;
	}

	ofstream addToListOfSavedGames( "saved_games.save" );

	addToListOfSavedGames << filename << endl;

	addToListOfSavedGames.close( );

	file << figure ->type << endl;

	for( int i = 0; i < 4; i ++ )
	{
		file << figure ->GetFigure( i ).row << " ";
		file << figure ->GetFigure( i ).col << endl;
	}

	file << speed << endl;
	file << level << endl;

	for( int i = 0; i < FIELD_SIZE; i ++ )
	{
		for( int j = 0; j < FIELD_SIZE; j ++ )
		{
			file << field ->GetXY( i, j );
		}
		file << endl;
	}

	file.close( );
}

void Tetris::RestoreGame( )
{
	ifstream readSavedGame( "player.save" );

	//FigureType type = LINE;
	int type = 0;

	Point coordinates[ 4 ];

	readSavedGame >> type;

	for( int i = 0; i < 4; i ++ )
	{
		readSavedGame >> coordinates[ i ].row;
		readSavedGame >> coordinates[ i ].col;
	}
	if( figure )
		delete figure;

	figure = new Figure( static_cast< FigureType >( type ), coordinates );

	readSavedGame >> speed;
	readSavedGame >> level;

	if( field )
		delete field;

	field = new Field;

	//	field ->Draw( *figure );
	char currchar = 0;
	for( int i = 0; i < FIELD_SIZE; i ++ )
	{
		for( int j = 0; j < FIELD_SIZE; j ++ )
		{
			readSavedGame >> currchar;

			field ->SetXY( i, j, currchar );
		}
	}

	readSavedGame.close( );
}

void Tetris::Input( )
{
	while( true )
		cout << "| Score : " << score << " | " << "Level : " << level << " | " << endl;
}


Tetris::~Tetris( )
{
	if( field )
		delete field;
	if( figure )
		delete figure;
}
