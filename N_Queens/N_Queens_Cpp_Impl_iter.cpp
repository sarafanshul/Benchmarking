// A straight-forward brute-force C++ version with formatted output,
// eschewing obfuscation and C-isms, producing ALL solutions, which
// works on any OS with a text terminal.
//
// Two basic optimizations are applied:
//
//   It uses backtracking to only construct potentially valid solutions.
//
//   It only computes half the solutions by brute -- once we get the
//   queen halfway across the top row, any remaining solutions must be
//   reflections of the ones already computed.
//
// This is a bare-bones example, without any progress feedback or output
// formatting controls, which a more complete program might provide.
//
// Beware that computing anything larger than N=14 might take a while.
// (Time gets exponentially worse the higher the number.)

#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
#include <algorithm>
#include <ciso646>
#include <iomanip>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

struct queens{

  typedef signed char index_type;

  struct solution_type: std::vector <index_type> {
    typedef std::vector <index_type> base_type;
 
    // constructors  . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    solution_type( std::size_t N          ): base_type( N, -1 ) { }
    solution_type( const solution_type& s ): base_type( s     ) { }
 
    // compare . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    bool operator < ( const solution_type& s ) const {
      auto mm = std::mismatch( begin(), end(), s.begin() );
      return (mm.first != end()) and (*mm.first < *mm.second);
    }
 
    // transformations . . . . . . . . . . . . . . . . . . . . . . . . . . . .
    void vflip() { std::reverse( begin(), end() ); }
 
    void hflip() { for (auto& x : *this) x = size() - 1 - x; }
 
    void transpose() {
      solution_type result( size() );
      for (index_type y = 0; (std::size_t)y < size(); y++)
        result[ (*this)[ y ] ] = y;
      swap( result );
    }
  };
 
  // MEMBER VALUES -----------------------------------------------------------
 
  const int                N;
  std::set <solution_type> solutions;
 
  // SOLVER ------------------------------------------------------------------
 
  queens( int N = 8 ):
    N( (N < 0) ? 0 : N ) {

    solution_type solution( N );
    index_type row = 0;
    while (true) {
      // Advance the queen along the row
      ++solution[ row ];
 
      // (If we get past halfway through the first row, we're done.)
      if ((row == 0) and (solution[ 0 ] > N/2)) break;
 
      if (solution[ row ] < N) {
        // If the queen is in a good spot...
        if (ok( solution, row, solution[ row ] )) {
          // ...and we're on the last row
          if (row == N-1) {
            // Add the solution we found plus all it's reflections
            solution_type
            s = solution;  solutions.insert( s );
            s.vflip();     solutions.insert( s );
            s.hflip();     solutions.insert( s );
            s.vflip();     solutions.insert( s );
            s.transpose(); solutions.insert( s );
            s.vflip();     solutions.insert( s );
            s.hflip();     solutions.insert( s );
            s.vflip();     solutions.insert( s );
          }
          // otherwise begin marching a queen along the next row
          else solution[ ++row ] = -1;
        }
 
      // When we get to the end of a row's columns then
      // we need to backup a row and continue from there.
      }
      else --row;
    }
  }
 
  bool ok( const solution_type& columns, index_type row, index_type column )
  {
    for (index_type r = 0; r < row; r++) {
      index_type c         = columns[ r ];
      index_type delta_row = row - r;
      index_type delta_col = (c < column) ? (column - c) : (c - column);

      if ((c == column) or (delta_row == delta_col))
        return false;
    }
    return true;
  }

  friend
  std::ostream&
  operator << ( std::ostream& outs, const queens& q ){
    if (q.solutions.empty()) outs << "no";
    else outs << q.solutions.size();
     return outs;
  }
};


int main(){
  std::cout << queens( 13 ) << "\n";
}
 