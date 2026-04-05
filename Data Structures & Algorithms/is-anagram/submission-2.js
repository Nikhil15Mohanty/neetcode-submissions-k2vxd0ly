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

        for (let i = 0; i < sorted_a.length; i++) {
            if (sorted_a[i] != sorted_b[i]) {
                return false;
            }
        }

        return true;
    }
}
