#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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
    int sum = 0;
    for( int i = 0 ; i < N ; i ++ )
        sum += nums[i];

    cout<<fixed<<setprecision(1)<<(double)sum/N<<endl;


    // Median
    sort( nums.begin(), nums.end() );

    if( N%2 )
        cout<<nums[N/2];
    else{
        sum = nums[N/2] + nums[N/2-1];
        if( sum%2 )
            cout<<fixed<<setprecision(1)<<(double)sum/2.0<<endl;
        else
            cout<<sum/2<<endl;
    }


    // Mode
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

    cout<<res<<endl;

    return 0;
}