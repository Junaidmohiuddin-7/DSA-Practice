class Solution {
public:
    string remo(string& s, string& part, int n) {
        if (s.find(part) == string::npos) {
            return s;
        }
        s.erase(s.find(part), n);
        return remo(s, part, n);
    }
    string removeOccurrences(string s, string part) {
        int n = part.length();
        remo(s, part, n);
        return s;
    }
};