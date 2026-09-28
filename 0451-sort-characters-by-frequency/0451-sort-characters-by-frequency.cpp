class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        vector<pair<char, int>> v;

        for(auto x : mp) {
            v.push_back({x.first, x.second});
        }

        sort(v.begin(), v.end(),
            [](pair<char, int> a, pair<char, int> b) {
                return a.second > b.second;
            }
        );

        string ans = "";

        for(auto x : v) {
            int freq = x.second;

            while(freq--) {
                ans += x.first;
            }
        }

        return ans;
    }
};