
class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0, n = s.size(), count = 0;
        int freq[26] = {0}, maxFreq = 0;

        while (end < n) {
            freq[s[end] - 'A']++;
            maxFreq = max(maxFreq, freq[s[end] - 'A']);

            while ((end - start + 1) - maxFreq > k) {
                freq[s[start] - 'A']--;
                start++;
            }

            count = max(count, end - start + 1);
            end++;
        }

        return count;
    }
};
