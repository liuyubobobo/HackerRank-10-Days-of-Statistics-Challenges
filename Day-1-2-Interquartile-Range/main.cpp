#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double medianForSortedVector(const vector<int> &nums){

    if( nums.size()%2 )
        return nums[nums.size()/2];
    else
        return (double)(nums[nums.size()/2] + nums[nums.size()/2-1])/2.0;
}

vector<double> quartiles(vector<int> nums){

    sort(nums.begin(), nums.end());

    double q[3];
    if( nums.size() % 2 ){
        int mid = nums.size()/2;
        q[1] = nums[mid];
        q[0] = medianForSortedVector(
                vector<int>( nums.begin(), nums.begin() + mid ) );
        q[2] = medianForSortedVector(
                vector<int>( nums.begin() + mid + 1 , nums.end() ) );
    }
    else{
        int midL = nums.size()/2 - 1;
        q[1] = (double)(nums[midL] + nums[midL+1])/2.0;
        q[0] = medianForSortedVector(
                vector<int>( nums.begin(), nums.begin() + midL + 1));
        q[2] = medianForSortedVector(
                vector<int>( nums.begin() + midL + 1, nums.end() ) );
    }

    return vector<double>( q , q + sizeof(q)/sizeof(double) );
}

double interquartileRange( const vector<int> nums ){

    vector<double> q = quartiles( nums );
    return q[2] - q[0];
}

int main() {

    int N;
    cin>>N;

    vector<int> nums;
    vector<int> X, F;
    int x, f;
    for( int i = 0 ; i < N ; i ++ ){
        cin>>x;
        X.push_back(x);
    }
    for( int i = 0 ; i < N ; i ++ ){
        cin>>f;
        F.push_back(f);
    }
    for( int i = 0 ; i < X.size() ; i ++ )
        for( int j = 0 ; j < F[i] ; j ++ )
            nums.push_back( X[i] );

    cout<<fixed<<setprecision(1)<<interquartileRange( nums )<<endl;

    return 0;
}