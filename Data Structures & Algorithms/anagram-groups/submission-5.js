class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let hash_map = new Map();
        strs.forEach((str) => {
            let keyValue = str.split('').sort().join('');
            if (hash_map.has(keyValue)) {
                hash_map.get(keyValue).push(str);
            } else {
                hash_map.set(keyValue, [str]);
            }
        });
        return Array.from(hash_map.values())
    }
}
