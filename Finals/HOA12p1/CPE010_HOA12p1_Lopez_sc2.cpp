#include <iostream>
#include <algorithm>

const int max_n = 10;
int dp[max_n + 1];
int getMinSteps(int n)
{
    dp[1] = 0; // base case
    for ( int i = 2; i <= n; i++ )
    {
        dp[i] = 1 + dp[i - 1];
        if ( i % 2 == 0 ) dp[i] = std::min( dp[i], 1 + dp[i / 2] );
        if ( i % 3 == 0 ) dp[i] = std::min( dp[i], 1 + dp[i / 3] );
    }
    return dp[n];
}

int main(){
    int tests[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Steps Taken: " << std::endl;
    for (int n : tests) {
        std::cout << n << "\t" << getMinSteps(n) << std::endl;
    }
    return 0;
}