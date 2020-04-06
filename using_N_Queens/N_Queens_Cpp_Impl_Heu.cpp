
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
//--------------------------------------------------------------------------------------------------
using namespace std;
 
//--------------------------------------------------------------------------------------------------
typedef unsigned int uint;
 
//--------------------------------------------------------------------------------------------------
class nQueens_Heuristic
{
public:
    void solve( uint n ) { makeList( n ); drawBoard( n ); }
 
private:
    void drawBoard( uint n )
    {
	cout << n << "\n";
	solution.clear(); odd.clear(); evn.clear();
    }
 
    void makeList( uint n )
    {
	uint r = n % 6;
	for( uint x = 1; x <= n; x++ )
	{
	    if( x & 1 ) odd.push_back( x );
	    else evn.push_back( x );
	}
	if( r == 2 )
	{
	    swap( odd[0], odd[1] );
	    odd.erase( find( odd.begin(), odd.end(), 5 ) );
	    odd.push_back( 5 );
	}
	else if( r == 3 )
	{
	    odd.erase( odd.begin() ); odd.erase( odd.begin() );
	    odd.push_back( 1 ); odd.push_back( 3 );
	    evn.erase( evn.begin() ); evn.push_back( 2 );
	}
	vector<uint>::iterator it = evn.begin();
	while( it != evn.end() ) 
	{
	    solution.push_back( ( *it ) );
	    it++;
	}
	it = odd.begin();
	while( it != odd.end() ) 
	{
	    solution.push_back( ( *it ) );
	    it++;
	}
    }
 
    vector<uint> odd, evn, solution;
};

//--------------------------------------------------------------------------------------------------
int main(){
    uint n = 10; nQueens_Heuristic nQH;
    nQH.solve(n);
    return 0;
}
