#include <iostream>


const int M = 4, N = 4;

int countPaths(int mat[M][N], int cost) {
    int dp[M][N][100] = {};                  
    if (mat[0][0] > cost) return 0;
    dp[0][0][mat[0][0]] = 1;                 

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            for (int c = 0; c <= cost; c++) {
                if (i == 0 && j == 0) continue;
                if (c < mat[i][j]) continue;
                int before = c - mat[i][j];
                if (i > 0) dp[i][j][c] += dp[i-1][j][before];   
                if (j > 0) dp[i][j][c] += dp[i][j-1][before];  
            }
    return dp[M-1][N-1][cost];
}

int main() {
    int a[M][N] = {{4,7,1,6},{6,7,3,9},{3,8,1,2},{7,1,7,3}};   
    std::cout << "Printed matrix, cost 26: " << countPaths(a, 26) << std::endl;

    int b[M][N] = {{4,7,1,6},{5,7,3,9},{3,2,1,2},{7,1,6,3}};   
    std::cout << "Original matrix, cost 25: " << countPaths(b, 25) << std::endl;
}