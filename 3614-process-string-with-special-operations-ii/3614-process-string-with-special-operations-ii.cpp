class Solution {
public:
    char processStr(string s, long long k) {

        long long len = 0;

        // First pass -> only calculate final length
        for (char ch : s) {
            if (isalpha(ch)) {
                len++;
            }
            else if (ch == '*') {
                if (len > 0)
                    len--;
            }
            else if (ch == '#') {
                if (len > 0) {
                    if (len > LLONG_MAX / 2)
                        len = LLONG_MAX;
                    else
                        len *= 2;
                }
            }
        }

        if (k >= len)
            return '.';

        // Second pass -> work backwards
        for (int i = s.size() - 1; i >= 0; i--) {

            char ch = s[i];

            if (isalpha(ch)) {

                if (k == len - 1)
                    return ch;

                len--;
            }
            else if (ch == '*') {

                len++;

            }
            else if (ch == '%') {

                if (len > 0)
                    k = len - 1 - k;

            }
            else {

                if (len == 0)
                    continue;

                long long half = len / 2;

                if (k >= half)
                    k -= half;

                len = half;
            }
        }

        return '.';
    }
};