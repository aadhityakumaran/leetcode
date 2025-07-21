#include <sstream>
#include <iostream>
using namespace std;

class Solution {
private:
    static char numToLetter(int num) {
        switch (num) {
            case 1:
                return 'I';
            case 5:
                return 'V';
            case 10:
                return 'X';
            case 50:
                return 'L';
            case 100:
                return 'C';
            case 500:
                return 'D';
            case 1000:
                return 'M';
            default:
                return 'E';
        }
    }

public:
    static string intToRoman(int num) {
        ostringstream s;
        for (int i = 1000; i > 0; i /= 10) {
            int digit = num / i;
            num %= i;

            if (digit == 0) {
                continue;
            } else if (digit == 4) {
                s << numToLetter(i);
                s << numToLetter(i * 5);
                continue;
            } else if (digit == 9) {
                s << numToLetter(i);
                s << numToLetter(i * 10);
                continue;
            } else if (digit >= 5) {
                s << numToLetter(i * 5);
                digit -= 5;
            }
            while (digit--) s << numToLetter(i);
        }
        return s.str();
    }
};


int main() {
    // Example usage
    Solution S;
    int number = 3749;
    string romanNumeral = S.intToRoman(number);
    cout << "The Roman numeral for " << number << " is: " << romanNumeral << endl;
    return 0;
}