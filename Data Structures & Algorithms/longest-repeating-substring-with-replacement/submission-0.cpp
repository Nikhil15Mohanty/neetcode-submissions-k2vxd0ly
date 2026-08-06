class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> frequencyArray(26, 0);

        int left = 0;
        int answer = 0;
        int maxFrequency = 0;

        for(int right = 0; right<n; right++) {
            // add the frequency 

            frequencyArray[s[right] - 'A']++;

            // maxFrequency so far 
            maxFrequency = max(maxFrequency, frequencyArray[s[right] - 'A']);

            while ((right - left + 1) - maxFrequency > k) {
                frequencyArray[s[left] - 'A']--;
                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};
