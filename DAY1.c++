//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
          if(array2.size()<array1.size()) return MedianOfArrays(array2,array1);
          int n1 = array1.size();
          int n2 = array2.size();
          int low = 0,high = n1;
          while(low<=high){
              int division_1 = (low + high) >>1;
              int division_2 = (n1+n2+1)/2 - division_1;
              int left_part_1 = division_1==0?INT_MIN : array1[division_1 - 1];
              int left_part_2 = division_2==0?INT_MIN : array2[division_2 - 1];
              int right_part_1= division_1==n1?INT_MAX : array1[division_1];
              int right_part_2= division_2==n2?INT_MAX : array2[division_2];
              if(left_part_1<=right_part_2 && left_part_2<=right_part_1){
                  if((n1+n2)%2==0){
                    return (max(left_part_1,left_part_2) + min(right_part_1,right_part_2)) / 2.0;
                     }
                  else{
                    return max(left_part_1,left_part_2);
                  }
              }
              else if(left_part_1 > right_part_2){
                 high = division_1 - 1; 
              }
              else{
                  low = division_1+1;
              }
          }
      return 0.0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends