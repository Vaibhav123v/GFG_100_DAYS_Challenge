//Initial Template for C++
// by @vaibhav123v
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mapp;
        int max_length = 0;
        int sum = 0;
        for(int i = 0; i<n;i++){
            sum+=A[i]; // sum = -5
            if(sum==0){
                max_length = i+1; // 1
            }
            else{
                if(mapp.find(sum)!=mapp.end()){
                    max_length = max(max_length,i-mapp[sum]);
                }
                else{
                    mapp[sum] = i; // basically inserting
                }
            }
        }
        return max_length;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends