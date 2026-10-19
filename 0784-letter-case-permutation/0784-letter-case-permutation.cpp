class Solution {
public:

vector<string> ans;

void solve(string &s, int i) {
    //basecase
    if(i == s.size()){
        ans.push_back(s);
        return;
    }
    // keep i as it is move further 
    solve(s, i+1);

    if(isalpha(s[i])) {
        if(islower(s[i])) {
            s[i] = toupper(s[i]);
        }else{
            s[i] = tolower(s[i]);
        }
        solve(s, i+1);
        //backtrack - to original back the letters
        if(islower(s[i])) {
            s[i] = toupper(s[i]);
        } else{
            s[i] = tolower(s[i]);
        }
    }
}


    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return ans;
    }
};