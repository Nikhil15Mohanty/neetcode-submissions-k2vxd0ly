class Solution:
    def getFrequencyCount(self, s: str) -> str:
        frequency_array = [0] * 26
        result = ""

        # Count frequencies
        for char in s:
            frequency_array[ord(char) - ord('a')] += 1
        
        # Build frequency string like 'a2b1'
        for i in range(26):
            if frequency_array[i] > 0:
                # Convert index back to character 'a' + i
                result += chr(ord('a') + i) + str(frequency_array[i])
        
        return result
    
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map = {}
        for s in strs:
            frequency_count = self.getFrequencyCount(s)
            if frequency_count in hash_map:
                hash_map[frequency_count].append(s)
            else:
                hash_map[frequency_count] = [s]
        return list(hash_map.values())
