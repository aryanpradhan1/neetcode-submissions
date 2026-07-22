class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, double> pos_times;
        for (int i = 0; i < position.size(); ++i) {
            pos_times[position[i]] = (double)(target - position[i]) / speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());

        int fleets = 0;
        double max_time = -1;

        for(int i = 0; i < position.size(); ++i) {
            if (pos_times[position[i]] > max_time) {
                max_time = pos_times[position[i]];
                fleets++;
            }
        }

        return fleets;
    }
};
