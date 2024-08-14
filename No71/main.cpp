#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        auto split = [](const string &s, char delim) -> vector<string> {
            vector<string> ans;
            string cur;
            for (char ch : s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                } else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        vector<string> names = split(path, '/');
        vector<string> st;
        for (string &name : names) {
            if (name == "..") {
                if (st.size())
                    st.pop_back();
            } else if (name.size() && name != ".") {
                st.push_back(move(name));
            }
        }
        string ans;
        if (st.empty())
            ans = "/";
        else {
            for (string &name : st) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};

signed main() {
    string path = "/a/./b/../../c/";
    Solution sol;
    cout << sol.simplifyPath(path) << endl;

    return 0;
}