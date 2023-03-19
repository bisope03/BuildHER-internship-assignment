#include <iostream>
#include <string>
using namespace std;

/*
Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal 
substring consisting of non-space characters only.

Time complexity: O(n) where n is the length of the string
Space complexity: O(1) 

*/

int main(){
    // string input
    string s;
    getline(cin, s);

    // solution
    int count=0;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i]==' ' && count>0) break;
        else if(s[i]!=' '){
            count++;    
        }
    }
    cout << count;
    return 0;
}
