typedef struct TrieNode{
    struct TrieNode *children[26];
    int numwords, flag
}   TrieNode;

int stringWithLetter(TrieNode *root, char alpha){
    if (root == NULL) return 0;
    int ans = 0;
    for (int x=0; x < 26; ++x) {
        if(root->children[x] != NULL) {
            if('a'+x == alpha)
                ans += root->children[x]->numwords;
            else
                ans += stringWithLetter(root->children[x], alpha);
        }
        
    }
    return ans;
}