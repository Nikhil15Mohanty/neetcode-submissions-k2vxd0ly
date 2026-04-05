class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sorted_a = ''.join(sorted(s))
        sorted_b = ''.join(sorted(t));

        if (len(sorted_a) != len(sorted_b)):
            return False
        
        for i, _ in enumerate(sorted_a):
            if (sorted_a[i] != sorted_b[i]):
                return False
        return True