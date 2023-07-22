#include<bits/stdc++.h>

string reverseString(string &str){
	stack<string> st;
    string s = "";
    int i = 0;

    while(i < str.length()){
        if(str[i] == ' '){
            st.push(s);
            s = "";
        }
        else s += str[i];
        i++;
    }

    st.push(s);
    str = "";
    
    while(!st.empty()){
        if (st.top() != "") {
            str += st.top();
            if (st.size() > 1) {
                str += ' ';
            }
        }
        st.pop();
    }
    return str;
}
