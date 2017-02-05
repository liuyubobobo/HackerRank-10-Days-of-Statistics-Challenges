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

    int total = 6*6;
    int count = 0;
    for( int i = 1 ; i <= 6 ; i ++ )
        for( int j = 1 ; j <= 6 ; j ++ )
            if( i != j && i + j == 6 )
                count ++;

    int g = gcd( total, count );
    cout<<count/g<<"/"<<total/g<<endl;

    return 0;
}