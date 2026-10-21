class Solution {
public:

int dfs(vector<int> &freq) {
    int count =0;

    for(int i=0; i<26; i++) {
        if(freq[i] == 0)
        continue;

        count++;
        freq[i]--;
        count+=dfs(freq);
        //backtrack 
        freq[i]++;
    }
    return count;
}
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char ch : tiles) {
        freq[ch- 'A']++;
    }
    return dfs(freq);
    }
};