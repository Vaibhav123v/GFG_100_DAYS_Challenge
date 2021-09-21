// Code by @Vaibhav123
// Two-Pointer Approach
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    {   int ans = 0 ;
        int max = 0;
        int lower = 0,higher = n-1;
        while(higher-lower!=0){
            ans = min(height[higher],height[lower])*(higher-lower-1); // 8
            if(ans>max){
                max = ans;
            }
            if(height[higher]>height[lower]){
                lower++;
            }
            else{
                higher--;
            }
        }
        return max;
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends