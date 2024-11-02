#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#

# @lc code=start
class Solution:

    keypad = {
        2: "abc",
        3: "def",
        4: "ghi",
        5: "jkl",
        6: "mno",
        7: "pqrs",
        8: "tuv",
        9: "wxyz"
    }

    coveredCombinations = []

    def backtrack(self, combination: str, digits: str):

        if len(digits) <= 0:
            if combination not in self.coveredCombinations and len(combination) > 0:
                self.coveredCombinations.append(combination)
        else:     
            num = digits[0]
            for c in self.keypad[int(num)]:
                self.backtrack(combination + c, digits[1:])

    def letterCombinations(self, digits: str) -> list[str]:
        self.backtrack("", digits)
        return self.coveredCombinations
    
    

s = Solution()
print(s.letterCombinations("2"))


# @lc code=end

