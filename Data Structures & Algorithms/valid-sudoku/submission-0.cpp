class Solution {
public:

    bool validBlocks(vector<vector<char>>& board,
                     int startrow,
                     int endrow,
                     int columnstart,
                     int columnend) {

        unordered_set<char> st;

        for(int row = startrow; row <= endrow; row++) {

            for(int col = columnstart; col <= columnend; col++) {

                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for(int row = 0; row < 9; row++) {

            unordered_set<char> st;

            for(int col = 0; col < 9; col++) {

                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }

        // Check columns
        for(int col = 0; col < 9; col++) {

            unordered_set<char> st;

            for(int row = 0; row < 9; row++) {

                if(board[row][col] == '.') continue;

                if(st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }

        // Check 3x3 blocks
        for(int startrow = 0; startrow < 9; startrow += 3) {

            int endrow = startrow + 2;

            for(int columnstart = 0; columnstart < 9; columnstart += 3) {

                int columnend = columnstart + 2;

                if(!validBlocks(board,
                                startrow,
                                endrow,
                                columnstart,
                                columnend))
                    return false;
            }
        }

        return true;
    }
};