class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        let sorted_a = s.split('').sort().join('');
        let sorted_b = t.split('').sort().join('');

        if (sorted_a.length != sorted_b.length) {
            return false;
        }

        return sorted_a === sorted_b;
    }
}
