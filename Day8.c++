// by @vaibhav123v
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    int search(string pat, string txt) {
        int txt_length = txt.length();
        int pat_length = pat.length();
        if (txt_length < 0 || pat_length < 0|| txt_length < pat_length)
            return 0;
 
        constexpr int CHARACTERS = 256;
        int count_occurences = 0;
        int index = 0;
        std::array<char, CHARACTERS> wordArr;
        wordArr.fill(0);
        std::array<char, CHARACTERS> textArr;
        textArr.fill(0);
 
        // till window size
        for (; index < pat_length; index++) {
            wordArr[CHARACTERS - pat[index]]++;
            textArr[CHARACTERS - txt[index]]++;
        }
        if (wordArr == textArr)
            count_occurences += 1;
        // next window
        for (; index < txt_length; index++) {
            textArr[CHARACTERS - txt[index]]++;
            textArr[CHARACTERS
                    - txt[index - pat_length]]--;
 
            if (wordArr == textArr)
                count_occurences += 1;
        }
        return count_occurences;

	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends