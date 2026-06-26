class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      //checks rows
      for(int i=0;i<9;i++){
        unordered_set<char> row;
        for(int j=0;j<9;j++){
            char c = board[j][i];
            if(c!='.'){
                if(row.count(c)) return false;
                row.insert(c);
            }
        }
      }
      //checks columns
      for(int i=0;i<9;i++){
        unordered_set<char> col;
        for(int j=0;j<9;j++){
            char c = board[i][j];
            if(c!='.'){
                if(col.count(c)) return false;
                col.insert(c);
            }
        }
      }
      //checks 3x3 sub-boxes
      for(int boxRow=0;boxRow<3;boxRow++){
        for(int boxCol=0;boxCol<3;boxCol++){
            unordered_set<char> box;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    char c = board[boxRow*3+i][boxCol*3+j];
                    if(c!='.'){
                        if(box.count(c)) return false;
                        box.insert(c);
                    }
                }
            }
        }
      }
      return true;
    }
};
