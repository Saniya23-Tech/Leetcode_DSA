class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m>n) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        //s1 frequency 
        for(char ch: s1) {
            freq1[ch - 'a']++;
        }

        int i= 0 , j= 0;
        while(j <n) {
            //add current character to window
            freq2[s2[j]-'a']++;

            if(j-i+1 <m) { //if window size is less than m
                j++;
            }

            else if(j-i+1 == m) {
                //check permutation 
                if(freq1 == freq2)
                return true;
                //slidewindow if there is no matching
                freq2[s2[i]-'a']--; 
                i++;
                j++;
            }
        }
        return false;
    }
};