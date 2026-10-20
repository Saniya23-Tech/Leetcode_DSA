class Solution {
public:
 
 int count =0;
 void backtrack(int pos, int n, vector<int> &ans , vector<bool> &Arrange) {
    if(ans.size() == n) { //Basecase
        count++;
        return;
    }

    for(int i =1 ; i <=n; i++) {

    if(!Arrange[i] && (i % pos == 0 || pos%i == 0)) {
        //choosing 
        ans.push_back(i);
        Arrange[i] = true;
        backtrack(pos+1 , n, ans, Arrange);
        //undo 
    ans.pop_back();
    Arrange[i] = false;
 }
 }
 }

    int countArrangement(int n) {
        vector<bool>  Arrange(n+1, false); 
        vector<int> ans;
        //while returning from backtrack make it back flase otherwise next brach cannot use it 

        backtrack(1, n, ans , Arrange);
        return count;
        
    }
};