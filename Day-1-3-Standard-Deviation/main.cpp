#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>

using namespace std;

double mean(const vector<int> &nums){

    int sum = 0;
    for( int i = 0 ; i < nums.size() ; i ++ )
        sum += nums[i];

    return (double)sum/nums.size();
}

double standardDeviation( const vector<int> &nums){

    assert( nums.size() > 0 );

    double miu = mean( nums );

    double sum = 0.0;
    for( int i = 0 ; i < nums.size() ; i ++ )
        sum += (nums[i] - miu) * (nums[i] - miu);
    return sqrt( sum / nums.size() );
}

int main() {

    int N;
    cin>>N;

    vector<int> nums;
    int x;
    for( int i = 0 ; i < N ; i ++ ){
        cin>>x;
        nums.push_back( x );
    }

    cout<<fixed<<setprecision(1)<<standardDeviation( nums )<<endl;

    return 0;
}