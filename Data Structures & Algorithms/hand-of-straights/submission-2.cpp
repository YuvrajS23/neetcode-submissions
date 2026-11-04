class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }

        for (auto it = countMap.begin(); it != countMap.end(); ++it) {
            int currentCard = it->first;
            int currentCount = it->second;

            if (currentCount > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    int nextCard = currentCard + i;
                    if (countMap[nextCard] < currentCount) {
                        return false;
                    }
                    countMap[nextCard] -= currentCount;
                }
            }
        }

        return true;
    }
};
