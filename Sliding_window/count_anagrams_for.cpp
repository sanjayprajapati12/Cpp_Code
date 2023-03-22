#include<bits/stdc++.h>
using namespace std;
// in this we use for loop

#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// Generate a map of all character occurances of the 2nd string, i.e char and its count.
// The window size becomes the length of 2nd string, as the anangrams wil also be of this length, amd another variable count denotes the distinct characters left in a sliding window.
// In a window if the current character is present in map, then decrease its count, and if the count becomes 0, decrease the 'count' variable.
// If the window size is lesser than k just move forward the window
// When the window is hit the end -> If the count is 0, it means all the characters needed for its anagram is here in it, therefore increase your answer
// To remove the last part (arr[i] part) so that the window can be shifted ->
// If the s[i] is present in map then increase its count and if it changes from 0->1 then increase the 'count' variable

int solve(string s, string ana){

    unordered_map<char,int> m;
    for(auto &it:ana) m[it]++;

    int k = ana.length();
    int count = m.size();

    int ans=0;
    // make window of length k 
    for(int i=0 ; i<k ;i++){

        if(m.find(s[i])!=m.end()){
            m[s[i]]--;
            if(m[s[i]]==0) count--;
        }

    }

    if(count==0) ans++;
    if(m.find(s[0])!=m.end()){
        m[s[0]]++;
        if(m[s[0]]==1)count++;
    }

    for(int j=k; j<s.length() ; j++){
        int i = j-k+1;

        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }

        if(count==0) ans++;

        if(m.find(s[i])!=m.end()){
            m[s[i]]++;
            if(m[s[i]]==1) count++;
        }    
        
    }

    return ans;
}

// TC : O(n)
// SC : O(distinctChars(ana))

int main(){

    // Given a string, and another string, find count of occurances of all anagrams of 2nd one in 1st one.
    // Input : "forxxorfxdofr", "for"
    // Output : 3
    // Explanation : Anagrams of the word for - for, orf, ofr appear in the text and hence the count is 3.

    string str = "forxxorfxdofr";
    string anagram = "for";

    // string str1 = "aabaabaa";
    // string anagram1 = "aaba";

    int ans = solve(str, anagram);
    cout<<ans<<endl; 

    return 0;
}