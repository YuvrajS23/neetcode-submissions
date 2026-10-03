class TrieNode {
    public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for(int i=0; i < 26; i++){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* cur = root;
        for(int i = j; i < word.size(); i++){
            if(word[i] == '.') {
                for(TrieNode* child : cur->children) {
                    if(child != nullptr && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                int x = word[i] - 'a';
                if(cur->children[x] == nullptr) {
                    return false;
                }
                cur = cur->children[x];
            }
        }
        return cur->endOfWord;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c: word){
            int i = c - 'a';
            if(cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
