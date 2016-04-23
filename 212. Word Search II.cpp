struct Node {
    char ch;
    unordered_map<char, Node*> next;
    bool is_string;
    Node (char v) : ch(v) {
        is_string = false;
    }
};

class Solution {
public:

    Node * root;
    int directx[4] = {0, 0, -1, 1};
    int directy[4] = {-1, 1, 0, 0};
    
    // Adds a word into the data structure.
    void addWord(string word) {
        if (root == NULL)
            root = new Node('0');
        
        Node * tmp = root;
        
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (tmp->next.find(ch) != tmp ->next.end())
                tmp = tmp -> next[ch];
            else {
                tmp -> next[ch] = new Node(ch);
                tmp = tmp -> next[ch];
            }
            if (i == word.size() - 1)
                tmp -> is_string = true;
        }
    }
    
    bool search(Node* node, string word, int depth) {
        if (depth == word.size())
            return true;
        
        if (node->next.find(word[depth]) == node->next.end()) {
            //cout << "false: " << word[depth] << endl;
            return false;
        }
        
        return search(node->next[word[depth]], word, depth+1);
    }

    void dfs_find(vector<vector<char>>& board, string str, Node* node, set<string>& unique, bool** visited, int i, int j) {
        if (node->is_string) {
            unique.insert(str);
        }
        
        //cout << i << " " << j << " "<<str << endl;
        
        for (int k = 0; k < 4; k++) {
            int x = j + directx[k];
            int y = i + directy[k];
            //cout << y << " " << x << endl;
            if (x < board[0].size() && x >= 0 && y < board.size() && y >= 0) {
                if (visited[y][x]) continue;
                string tmp = "";
                tmp += board[y][x];
                if (search(node, tmp, 0)) {
                    visited[y][x] = true;
                    dfs_find(board, str + board[y][x], (node->next)[board[y][x]], unique, visited, y, x);
                    visited[y][x] = false;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       vector<string> ans;
       set<string> unique;
       
       if (words.size() == 0 || board.size() == 0)
            return ans;
       
       for (int i = 0; i < words.size(); i++) {
           addWord(words[i]);
       }
       
       bool ** visited = new bool*[board.size()];
       for (int i = 0; i < board.size(); i++) {
           visited[i] = new bool[board[0].size()];
           memset(visited[i], 0, board[0].size());
       }
       
       for (int i = 0; i < board.size(); i++) {
           for (int j = 0; j < board[0].size(); j++) {
               string str = "";
               str += board[i][j];
               visited[i][j] = true;
               if (search(root, str, 0))
                    dfs_find(board, str, root->next[board[i][j]], unique, visited, i, j);
               visited[i][j] = false;
           }
       }
       
       for (auto i = unique.begin(); i != unique.end(); i++)
            ans.push_back(*i);
       
       return ans;
       
    }
    
};
