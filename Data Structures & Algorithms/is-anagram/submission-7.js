class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        if (s.length != t.length) return false;
        const s_map = new Map();
        const t_map = new Map();

        let flag = false;

        let new_s = s.split('');
        new_s.forEach((key) => {
            s_map.set(key, (s_map.get(key) + 1)|| 1)
        })

        let new_t = t.split('');
        new_t.forEach((key) => {
            t_map.set(key, (t_map.get(key) + 1) || 1)
        });

        new_s.forEach((key) => {
            if (s_map.get(key) != t_map.get(key)) {
                flag = true;
            }
        });

        return flag ? false: true;
    }
}
