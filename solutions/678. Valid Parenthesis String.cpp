class Solution {
private: 
    bool isValidString(int index, int openCount,
        const string & str, vector < vector < int >> & memo) {
        // If reached end of the string, check if all brackets are balanced
        if (index == str.size()) {
            return (openCount == 0);
        }

        // If already computed, return memoized result
        if (memo[index][openCount] != -1) {
            return memo[index][openCount];
        }

        bool isValid = false;
        // If encountering '*', try all possibilities
        if (str[index] == '*') {
            isValid |= isValidString(index + 1, openCount + 1, str, memo); // Treat '*' as '('
            if (openCount) {
                isValid |= isValidString(index + 1, openCount - 1, str, memo); // Treat '*' as ')'
            }
            isValid |= isValidString(index + 1, openCount, str, memo); // Treat '*' as empty
        } else {
            // Handle '(' and ')'
            if (str[index] == '(') {
                isValid = isValidString(index + 1, openCount + 1, str, memo); // Increment count for '('
            } else if (openCount) {
                isValid = isValidString(index + 1, openCount - 1, str, memo); // Decrement count for ')'
            }
        }

        // Memoize and return the result
        return memo[index][openCount] = isValid;
    }
public: 
    // DP
    bool checkValidString1(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return isValidString(0, 0, s, memo);
    }
    // two stacks
    bool checkValidString2(string s) {
        stack<int> openBrackets; 
        stack<int> asterisks; 
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (ch == '(') {
                openBrackets.push(i);
            } else if (ch == '*') {
                asterisks.push(i);
            } else {
                
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!asterisks.empty()) {
                    asterisks.pop();
                } else {
                    return false;
                }
            }
        }
        // Check if there are remaining open brackets and asterisks that can balance them
        while (!openBrackets.empty() && !asterisks.empty()) {
            // If an open bracket appears after an asterisk, it cannot be balanced, return false
            if (openBrackets.top() > asterisks.top()) {
                return false; // '*' before '(' which cannot be balanced.
            }
            openBrackets.pop();
            asterisks.pop();
        }
        return openBrackets.empty();
    }
    // two pointer O(n)
    // count * as suppliment for both sides, so any point of time string cant be valid return false
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;
        
        for (int i = 0; i <= length; i++) {
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
        return true;
    }

};
