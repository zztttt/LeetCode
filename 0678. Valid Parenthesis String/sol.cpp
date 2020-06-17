class Solution {
public:
bool checkValidString(string s) {
        if (s.empty())
            return true;
        int len = s.size();
        int countStar = 0, countLeft = 0;
        for (int i = 0; i < len; ++i) {
            switch (s[i]) {
                case '(':
                    ++countLeft;
                    break;
                case '*':
                    ++countStar;
                    break;
                case ')':
                    if (countLeft > 0)
                        --countLeft;
                    else if (countStar > 0)
                        --countStar;
                    else
                        return false;
                    break;
            }
        }

        countStar = 0;
        int countRight = 0;
        for (int i = len - 1; i >= 0; --i) {
            switch (s[i]) {
                case ')':
                    ++countRight;
                    break;
                case '*':
                    ++countStar;
                    break;
                case '(':
                    if (countRight > 0)
                        --countRight;
                    else if (countStar > 0)
                        --countStar;
                    else
                        return false;
                    break;
            }
        }

        return true;
    }
};