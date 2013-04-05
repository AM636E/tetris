#include "Tetris.h"

int main( )
{
	Tetris tetris;

	tetris.StartGame( );
	
	return 0;
}






























//#include <iostream>
//#include <string>
//#include <map>
//
//using namespace std;
//
//int main( )
//{
//
//	map< string, int > arr;
//
//	arr.insert( std::pair< string, int >( "age", 5 ) );
//	arr.insert( std::pair< string, int >( "id", 1251 ) );
//	arr.insert( std::pair< string, int >( "count_of_legs", 4 ) );
//	arr.insert( std::pair< string, int >( "hair_count", 100000 ) );
//	arr.insert( std::pair< string, int >( "is_end", true ) );
//
//	cout << arr[ "age" ] << endl;
//	cout << arr[ "id" ] << endl;
//	cout << arr[ "count_of_legs" ] << endl;
//	cout << arr[ "hair_count" ] << endl;
//	cout << arr[ "is_end" ] << endl;
//	cout << arr[ "no_defined_value" ] << endl;
//
//	arr[ "age" ] = 10;
//	arr[ "three" ] = 3;
//
//	cout << arr[ "age" ] << endl;
//	cout << arr[ "three" ] << endl;
//
//	multimap< string, int > multi_arr;
//
//	cin.get( );
//	return 0;
//}

//#include <iostream>
//#include <conio.h>
//#include <process.h>
//using namespace std;
//
//char some_globe[ 80 ] = { 0 };
//int  some_globe_index = 0;
//
//void writeSomeGlobe( void * )
//{
//	while( true )
//	{
//		while( _kbhit( ) )
//		{
//			cout << "i am is still running " << endl;
//			if( some_globe_index == 79 )
//				some_globe_index = 0;
//			some_globe[ some_globe_index ++ ] = _getch( );
//		}
//		cout << "ended " << endl;
//	}
//	cout << "all ended " << endl;//must be newer printed
//}
//
//int main( )
//{
//	_beginthread( writeSomeGlobe, 0, 0 );
//	while( true )
//	{
//		while( _kbhit( ) )
//		{		
//			cout << some_globe_index << endl;
//			for( int i = 0 ; i < some_globe_index; i ++ )
//			{
//				cout << some_globe[ i ] << endl;
//			}
//		}
//	}
//	return 0;
//}