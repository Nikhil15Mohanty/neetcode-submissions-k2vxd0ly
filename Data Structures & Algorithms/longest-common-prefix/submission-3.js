class Solution {
    /**
     * @param {string[]} strs
     * @return {string}
     */
    longestCommonPrefix(strs) {
        strs.sort()
        let first = strs[0]
        let last = strs[strs.length - 1];
        let result = ""
        for (let i = 0; i < first.length; i++) {
            if (first[i] != last[i]) {
                return result;
            }
            result+=first[i];
        }
        return result;
    }
}
