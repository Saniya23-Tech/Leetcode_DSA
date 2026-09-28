class Solution {
public:
    string frequencySort(string s) {
        
        // Fixed array — 256 ASCII characters ke liye
        int freq[256] = {0};
        
        for(char ch : s) {
            freq[ch]++;
        }
        
        string ans = "";
        
        while(ans.size() < s.size()) {
            int maxIdx = 0;
            int maxFreq = 0;
            
            for(int i = 0; i < 256; i++) {
                if(freq[i] > maxFreq) {
                    maxFreq = freq[i];
                    maxIdx = i;
                }
            }
            
            if(maxFreq == 0) break;
            
            ans += string(maxFreq, (char)maxIdx);
            freq[maxIdx] = 0;  // reset
        }
        
        return ans;
    }
};