class Solution {
    /**
     * @param {string[]} strs
     * @return {string[][]}
     */
    groupAnagrams(strs) {
        let result = []
        const used = new Array(strs.length).fill(false);
        for (let i = 0; i < strs.length; i++) {
            if (used[i]) {
                continue;
            }
            let group = [strs[i]]
            const sorted_i = strs[i].split('').sort().join('');
            used[i] = true;
            for (let j = i+1; j < strs.length; j++) {
                const sorted_j = strs[j].split('').sort().join('');
                if (!used[j] && sorted_i === sorted_j) {
                    used[j] = true;
                    group.push(strs[j]);
                }
            }
            result.push(group);
        }
        return result;
    }
}
