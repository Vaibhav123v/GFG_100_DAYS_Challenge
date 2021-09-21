// code by @vaibhav123v
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{

    public:
    int repeatedStringMatch(string A, string B) 
    {
        // Your code goes here
        string original_str = A;
        int repeat = B.length()/A.length();
        int count =1;
        for(int i = 0; i < repeat+2 ;i++){
            if(A.find(B)!= string::npos){
                return count;
            }
            else{
                A+=original_str;
                count++;
            }
        }
        return -1;
        
    }
  
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution obj;
        cout<<obj.repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends