#include <iostream>
#include <algorithm>


const int max_n = 10;
int memo[max_n + 1];
int getMinSteps(int n)
{
    if ( n == 1 ) return 0; // base case
    if ( memo[n] != -1 ) return memo[n];
    int r = 1 + getMinSteps( n - 1 );
    if ( n % 2 == 0 ) r = std::min( r, 1 + getMinSteps( n / 2 ) );
    if ( n % 3 == 0 ) r = std::min( r, 1 + getMinSteps( n / 3 ) );
    memo[n] = r;
    return r;
}

int main(){
    int tests[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::fill(memo, memo + max_n + 1, -1);
    std::cout << "Steps Taken: " << std::endl;
    for (int n : tests) {
        std::cout << n << "\t" << getMinSteps(n) << std::endl;
    }
    return 0;
}


