#include <iostream>
using namespace std;

class Solution {
private:
    static int letterToNum(char letter) {
        switch (letter) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // Invalid character
        }
    }

public:
    static int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (letterToNum(s[i]) < letterToNum(s[i + 1])) {
                num -= letterToNum(s[i]);
            } else {
                num += letterToNum(s[i]);
            }
        }
        return num;
    }
};

int main() {
    // Example usage
    Solution S;
    string romanNumeral = "MCMXCIV"; // 1994
    int number = S.romanToInt(romanNumeral);
    cout << "The integer value of " << romanNumeral << " is: " << number << endl;
    return 0;
}