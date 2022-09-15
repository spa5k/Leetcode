class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        priority_queue<int> heap;
        set<pair<int, int>> s;
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = count(mat[i].begin(), mat[i].end(), 1);
            s.insert({cnt, i});
        }

        vector<int> res{};

        for (auto i: s) {
            if (k == 0)
                break;
            res.push_back(i.second);
            --k;
        }
        return res;
    }
};
