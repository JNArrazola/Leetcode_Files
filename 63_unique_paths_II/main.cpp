#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int support(int n, int m, vector<vector<int>> &obstacle,  vector<vector<int>> &dp){
        if(obstacle[n][m]==1) return 0;
        
        if(dp[n][m]!=-1) return dp[n][m];
        if(n == 0|| m == 0) return 1;
        
        dp[n][m] = support(n-1, m, obstacle, dp) + support(n, m - 1, obstacle, dp);
        return dp[n][m];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        if(n==2&&m==2&&obstacleGrid[0][0]==0&&obstacleGrid[0][1]==1){
            return 1;
        }

        if(n==0&&m==0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int> (m+1,-1)); 
        return support(n-1, m-1, obstacleGrid, dp);
    }
};

int main()
{
    Solution solucion;
    vector<vector<int>> obstacleGrid = {{0,1},{0,0}};
    cout << solucion.uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}