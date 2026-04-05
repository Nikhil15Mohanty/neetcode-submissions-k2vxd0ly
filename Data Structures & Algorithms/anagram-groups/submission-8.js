class Solution {
    /**
     * @param {string} str
     * @return {string}
     */
    getFrequencyCount(str) {
        const arr = new Array(26).fill(0);
        for (let ch of str) {
            arr[ch.charCodeAt(0) - 'a'.charCodeAt(0)] += 1;
        }

        let result = "";
        for (let i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                result += String.fromCharCode('a'.charCodeAt(0) + i) + arr[i];
            }
        }
        return result;
    }

    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        const hash_map = new Map();

        for (const str of strs) {
            let keyValue = this.getFrequencyCount(str);
            if (hash_map.has(keyValue)) {
                hash_map.get(keyValue).push(str);
            } else {
                hash_map.set(keyValue, [str]);
            }
        }

        return Array.from(hash_map.values());
    }
}
