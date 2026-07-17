class Solution {
    encode(strs) {
        let res = "";

        for (const str of strs) {
            res += str.length + "#" + str;
        }

        return res;
    }

    decode(s) {
        const res = [];
        let i = 0;

        while (i < s.length) {
            let j = i;

            while (s[j] !== "#") {
                j++;
            }

            const length = parseInt(s.substring(i, j));
            const word = s.substring(j + 1, j + 1 + length);

            res.push(word);

            i = j + 1 + length;
        }

        return res;
    }
}