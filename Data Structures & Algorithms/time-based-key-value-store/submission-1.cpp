class TimeMap {
private:
    map<string, vector<pair<string, int>>> storage;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int left = 0;
        int right = storage[key].size() - 1;
        pair<string, int> closest;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (storage[key][mid].second == timestamp) {
                return storage[key][mid].first;
            } else if (storage[key][mid].second < timestamp) {
                closest.first = storage[key][mid].first;
                closest.second = storage[key][mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return closest.first;
    }
};
