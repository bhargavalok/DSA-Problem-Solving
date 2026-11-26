class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceTurn = true;
        while (n >= stones) {
            n -= stones;
            stones--;
            aliceTurn = !aliceTurn;
        }
        // If it's Bob's turn when moves run out, Bob loses and Alice wins
        return !aliceTurn;
    }
};