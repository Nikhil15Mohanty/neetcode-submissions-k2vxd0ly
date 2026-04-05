class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # with the help of hashmap
        hasmap_s = {} 
        hasmap_b = {}
        if len(s) != len(t):
            return False
        for i in range(len(s)):
            hasmap_s[s[i]] = 1 + hasmap_s.get(s[i], 0)
            hasmap_b[t[i]] = 1 + hasmap_b.get(t[i], 0)
        
        for c in s:
            if hasmap_s[c] != hasmap_b.get(c, 0):
                return False
        return True