#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string& s, string& t) {
        bool isAnagram = true;
        if (s.length() == t.length()) {
            while (s.length() > 0) {
                int pos = s.find(t[0]);
                if (pos != string::npos) {
                    // remove found letter from both words
                    t = t.substr(1, t.length() - 1);
                    // cout << "Position: " << pos << endl;
                    if (pos > 0) {
                        s = s.substr(0, pos) + s.substr(pos + 1, s.length() - pos);
                    } else {
                        s = s.substr(1, s.length() - pos);
                    }
                    // cout << "t: " << t << endl << "s: " << s << endl;
                } else {
                    s = "";
                    isAnagram = false;
                }
            }
        } else {
            isAnagram = false;
        }

        return isAnagram;
    }
};

int main() {
    Solution sol;
    string t, s;
    cout << "Enter a word: ";
    cin >> t;
    cout << "Enter an anagram for that word: ";
    cin >> s;

    bool anagram = sol.isAnagram(s, t);
    if (anagram) {
        cout << "Your words are indeed anagrams" << endl;
    } else {
        cout << "Your words are not anagrams" << endl;
    }

    return 0;
}

