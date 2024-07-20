#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() % 2 != 0) return false;  // Check for odd-length strings

        for(int i = 0; i < s.length(); i++) {  // Use '<' instead of '<=' to avoid out-of-bounds access
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);  // Push the opening bracket onto the stack
            } else {
                if(st.empty()) return false;  // If stack is empty and we have a closing bracket
                char top = st.top();  // Get the top element of the stack
                if((s[i] == ')' && top == '(') || 
                   (s[i] == '}' && top == '{') || 
                   (s[i] == ']' && top == '[')) {
                    st.pop();  // Pop the matching opening bracket
                } else {
                    return false;  // Mismatched bracket
                }
            }
        }
        return st.empty();  // If the stack is empty, all brackets were matched correctly
    }
};
