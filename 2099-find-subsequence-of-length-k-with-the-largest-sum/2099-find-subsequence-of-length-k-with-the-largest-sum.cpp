class Solution {
public:
    vector<int> maxSubsequence(vector<int>& a, int k) {
        std::priority_queue<std::pair<int, int>> values;

        for(auto i = 0; i < a.size(); ++i) {
            values.emplace(a[i], i);
        }

        std::vector<std::pair<int, int>> t;
        t.reserve(k);

        for(auto i = 0; i < k; ++i) {
            t.push_back(values.top());
            values.pop();
        }

        std::sort(t.begin(), t.end(), [](auto const& a, auto const& b) {
            return a.second < b.second;
        });

        std::vector<int> results;
        results.resize(k);

        std::transform(t.begin(), t.end(), results.begin(), [](auto const& x) {
            return x.first;
        });

        return results;
    }
};