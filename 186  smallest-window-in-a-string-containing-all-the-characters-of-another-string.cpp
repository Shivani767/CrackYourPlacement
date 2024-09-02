#include <unordered_map>
#include <string>

std::string smallestWindow(std::string S, std::string P) {
    int lenP = P.length();
    int lenS = S.length();

    if (lenP > lenS) {
        return "-1";
    }

    std::unordered_map<char, int> charCountP;
    for (int i = 0; i < lenP; i++) {
        charCountP[P[i]]++;
    }

    int requiredChars = charCountP.size();

    int left = 0, right = 0, formedChars = 0;
    std::unordered_map<char, int> windowCounts;

    int minLength = INT_MAX, minLeft = 0, minRight = 0;

    while (right < lenS) {
        char character = S[right];
        windowCounts[character]++;

        if (charCountP.find(character) != charCountP.end() && windowCounts[character] == charCountP[character]) {
            formedChars++;
        }

        while (left <= right && formedChars == requiredChars) {
            character = S[left];

            if (right - left + 1 < minLength) {
                minLength = right - left + 1;
                minLeft = left;
                minRight = right;
            }

            windowCounts[character]--;
            if (charCountP.find(character) != charCountP.end() && windowCounts[character] < charCountP[character]) {
                formedChars--;
            }

            left++;
        }

        right++;
    }

    if (minLength == INT_MAX) {
        return "-1";
    }

    return S.substr(minLeft, minLength);
}
