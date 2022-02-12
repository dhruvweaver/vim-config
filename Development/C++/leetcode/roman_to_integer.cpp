#include <iostream>

using namespace std;

class Solution {
private:
    static int getIntFromChar(char& c) {
        int num;
        switch (c) {
            case 'I':
                num = 1;
                break;
            case 'V':
                num = 5;
                break;
            case 'X':
                num = 10;
                break;
            case 'L':
                num = 50;
                break;
            case 'C':
                num = 100;
                break;
            case 'D':
                num = 500;
                break;
            case 'M':
                num = 1000;
                break;
        }

        return num;
    }

public:
    int romanToInt(string& s) {
        int total = 0;
        int current;
        int prev = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            current = getIntFromChar(s[i]);
            if (current < prev) {
                total -= current;
            } else {
                total += current;
            }
            prev = current;
        }

        return total;
    }
};

int main() {
    Solution s;
    // string in;
    // cout << "Enter a roman numeral: ";
    // cin >> in;

    // cout << endl << s.romanToInt(in) << endl;

    string num = "MDCXCV";
    cout << s.romanToInt(num) << endl;

    return(0);
}
