class Solution {
public:
    //8 × (1 + 2 + ... + block)
    //= 8 × block(block + 1)/2
    //= 4 × block(block + 1)
    
    int minimumPushes(string word) {
        int n = word.size();
        int block = n / 8;
        return (block * (block+1) * 4) + (n % 8) * (block + 1);
    }
};