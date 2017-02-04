#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

double weightedMean(const vector<int> &nums, const vector<int> &weights){

    assert( nums.size() == weights.size() );

    int sum = 0;
    int weightSum = 0;
    for( int i = 0 ; i < nums.size() ; i ++ ){
        sum += weights[i] * nums[i];
        weightSum += weights[i];
    }

    return (double)sum/weightSum;
}

int main() {

    int N;
    cin>>N;

    vector<int> nums, weights;
    int x;
    for( int i = 0 ; i < N ; i ++ ){
        cin>>x;
        nums.push_back( x );
    }

    for(int i = 0 ; i < N ; i ++ ){
        cin>>x;
        weights.push_back( x );
    }

    cout<<fixed<<setprecision(1)<<weightedMean(nums, weights)<<endl;

    return 0;
}