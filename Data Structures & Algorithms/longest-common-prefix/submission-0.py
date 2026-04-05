class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        result = ""
        sorted_string = sorted(strs)
        first = sorted_string[0]
        last = sorted_string[len(strs) - 1]
        for i in range(len(first)):
            if first[i] != last[i]:
                return result
            result += first[i]
        return result
