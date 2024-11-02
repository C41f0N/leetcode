#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

# @lc code=start
class Solution:

    combs = []

    def backtrack(self, nO: int, nC: int, n: int, comb: str):
        if nC == n:
            self.combs.append(comb)
        else:
            # Open brace
            if (nO < n):
                self.backtrack(nO + 1, nC, n, comb + "(")
            
            # Close brace
            if (nC < nO):
                self.backtrack(nO, nC + 1, n, comb + ")")
            

    def generateParenthesis(self, n: int) -> list[str]:
        self.combs = []
        self.backtrack(0, 0, n, "")
        return self.combs
        
# @lc code=end

s = Solution()

print(s.generateParenthesis(1))