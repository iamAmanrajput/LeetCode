class Solution {
public:

    // Function to calculate Fibonacci using Space Optimized DP
    int solveUsingTabulationSpaceOptimized(int n) {

        if (n == 0 || n == 1) {
            return n;
        }

        // prev represents fib(0)
        int prev = 0;

        // curr represents fib(1)
        int curr = 1;

        // Variable to store current answer
        int ans;

        // Loop from 2 to n
        // Each Fibonacci number = sum of previous two numbers
        for (int i = 2; i <= n; i++) {
            
            // Calculate next Fibonacci number
            ans = curr + prev;

            // Shift values for next iteration
            prev = curr;
            curr = ans;
        }

        // Final answer stored in curr
        return curr;
    }

    int fib(int n) {
        // Call the space optimized function
        return solveUsingTabulationSpaceOptimized(n);
    }
};