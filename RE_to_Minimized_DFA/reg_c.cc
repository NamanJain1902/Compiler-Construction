#include "reg_c.h"

#include<bits/stdc++.h>
using namespace std;

// initializing static variable.
const unordered_set<char> REG_C::ops({'(', ')', '.', '|', '*'});

bool REG_C::isAlpha(char ch) {
    return (ch >= 97 and ch <= 122);
}


/// @brief Adding information about concatenation to easily process R.E.
/// @param regexp 
/// @return processed regular expression.
void REG_C::preprocess() {
    int n = this->regexp.size();
    string res = "";
    res += "(";

    for(int i=0; i<n; ++i) {
        char ch = this->regexp[i];
        char nch = this->regexp[i+1];
        res += ch;

        if(isAlpha(ch)){
            if(isAlpha(nch) /* ab */ || nch == '(' /* a( */) res += '.';
        } else if(ch == ')') {
            if(isAlpha(nch) /* )a */ || nch == '(' /* )( */) res += '.';
        } else if(ch == '*') {
            if(isAlpha(nch) /* *a */ || nch == '(' /* *( */) res += '.';
        }
    }

    res += ")";

    this->preprocessed_regexp = res;
}

std::string REG_C::toPostfix(std::string = "") {

    int n = preprocessed_regexp.length();
    string res = "";
    stack<char> st;

    for(int i=0; i<n; ++i) {

        char ch = preprocessed_regexp[i];

        switch (ch) {
            case '(':
                st.push(ch);
                break;
            case ')':
                if(st.empty()) {
                    break;
                } else {
                    while(st.top() != '(') {
                        res += st.top();
                        st.pop();
                    }
                    st.pop();
                    break;
                }
            case '*':
                if(st.empty()) {
                    break;
                } else {
                    
                }
        }
    }

    return res;
}
