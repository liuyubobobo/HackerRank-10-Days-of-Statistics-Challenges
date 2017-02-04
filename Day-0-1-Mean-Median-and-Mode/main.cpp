#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

double mean(const vector<int> &nums){

    int sum = 0;
    for( int i = 0 ; i < nums.size() ; i ++ )
        sum += nums[i];

    return (double)sum/nums.size();
}

double median(vector<int> nums){

    sort( nums.begin(), nums.end() );

    if( nums.size()%2 )
        return nums[nums.size()/2];
    else
        return (double)(nums[nums.size()/2] + nums[nums.size()/2-1])/2.0;
}

int mode(const vector<int> &nums){

    map<int,int> freq;
    for( int i = 0 ; i < nums.size() ; i ++ )
        freq[nums[i]] += 1;

    int res = -1;
    int bestFreq = 0;
    for( map<int,int>::iterator iter = freq.begin() ; iter != freq.end() ; iter ++ )
        if( iter->second > bestFreq ){
            bestFreq = iter->second;
            res = iter->first;
        }

    return res;
}

int main() {

    int N;
    cin>>N;

    vector<int> nums;
    int x;
    for( int i = 0 ; i < N ; i ++ ){
        cin>>x;
        nums.push_back(x);
    }


    // Mean
    cout<<fixed<<setprecision(1)<<mean(nums)<<endl;

    // Median
    cout<<fixed<<setprecision(1)<<median(nums)<<endl;

    // Mode
    cout<<mode(nums)<<endl;

    return 0;
}