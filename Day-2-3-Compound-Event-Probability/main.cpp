#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int gcd( int a, int b){

    assert( a > 0 && b > 0 );
    if( a < b )
        swap( a, b);

    if( a % b == 0 )
        return b;

    return gcd( b, a%b );
}

int main() {

    // Urn X contains 4 red balls and 3 black balls.
    // Urn Y contains 5 red balls and 4 black balls.
    // Urn Z contains 4 red balls and 4 black balls.

    int total = 7*9*8;
    int count = 0;
    count += 4*5*4; // RRB
    count += 4*4*4; // RBR
    count += 3*5*4; // BRR

    int g = gcd( total, count );
    cout<<count/g<<"/"<<total/g<<endl;

    return 0;
}