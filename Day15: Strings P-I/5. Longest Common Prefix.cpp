string longestCommonPrefix(vector<string> &str, int n)
{
    if(str.empty()) return "";

    string cur = str[0];
    for(int i=1; i<str.size(); i++){
        while(str[i].find(cur)){
            cur = cur.substr(0, cur.length()-1);
            if(cur.empty()) return "";
        }
    }
    return cur;
}
