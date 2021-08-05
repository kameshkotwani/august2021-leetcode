class Solution {
   public:
   bool stoneGame(vector<int>& piles) {
      int n = piles.size();
      vector < vector <int> > dp(n,vector <int>(n));
      vector <int> pre(n + 1);
      for(int i = 0; i < n; i++){
         pre[i + 1] = pre[i] + piles[i];
      }
      for(int l = 2; l <= n; l++){
         for(int i = 0, j = l - 1; j < n; i++, j++){
            dp[i][j] = max(piles[j] + pre[j] - pre[i] - dp[i][j - 1], piles[i] + pre[i + 2] -pre[j] + dp[i+ 1][j]);
         }
      }
      return dp[0][n - 1] > dp[0][n - 1] - pre[n];
   }
};
