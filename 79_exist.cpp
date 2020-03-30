79. 单词搜索
难度
中等

346

收藏

分享

切换为英文

关注

反馈
给定一个二维网格和一个单词，找出该单词是否存在于网格中。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 
示例:
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false


class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i,int j, int w){
        if(board[i][j]!=word[w]) return false;
        if(w==word.length()-1) return true;
        char tmp=board[i][j]; board[i][j]=0;
        if( (i-1>=0 && dfs(board, word, i-1, j, w+1)) 
        || (j+1<=board[0].size()-1 && dfs(board, word, i, j+1, w+1))
        || (i+1<=board.size()-1 && dfs(board, word, i+1, j, w+1))
        || (j-1>=0 && dfs(board, word, i, j-1, w+1)) ) return true;
        board[i][j]=tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++) if(dfs(board, word, i, j, 0)) return true;
        }
        return false;
    }
};
