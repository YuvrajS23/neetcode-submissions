class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> posSpeed(position.size(), {0, 0});
        for(int i = 0; i < position.size(); i++){
            posSpeed[i].first = position[i];
            posSpeed[i].second = speed[i];
        }
        sort(posSpeed.begin(), posSpeed.end(), [](const pair<int, int> a, const pair<int, int> b){
            return a.first > b.first;
        });
        vector<float> timeTaken(position.size(), 0);
        for(int i = 0; i < posSpeed.size(); i++){
            timeTaken[i] = static_cast<float>((target - posSpeed[i].first)) / posSpeed[i].second;
        }
        int numFleet = 1;
        float timeSlowestInFleet = timeTaken[0];
        for(int i = 0; i < timeTaken.size(); i++){
            if(timeTaken[i] <= timeSlowestInFleet){
                continue;
            }
            else{
                numFleet++;
                timeSlowestInFleet = timeTaken[i];
            }
        }
        return numFleet;
    }
};
