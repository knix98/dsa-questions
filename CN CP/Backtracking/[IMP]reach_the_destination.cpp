/*
Given a source point (sx, sy) and a destination point (dx, dy), the task is to check if it is possible to reach the destination point using the following valid moves:
(a, b) -> (a + b, b)
(a, b) -> (a, a + b)
Your task is to find if it is possible to reach the destination point using only the desired moves or not.
For example:
For the coordinates, source point = (1, 1) and destination point = (3, 5)
The output will be true as the destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)
Input Format:
The first line of input contains an integer ‘T’ representing the number of test cases. Then the test cases follow.

The only line of each test case contains four space-separated integers sx, sy, dx, and dy where sx, sy represents the coordinates of the source point and dx, dy represents the coordinates of the destination point.
Output Format:
For each test case, return the boolean true if the destination point can be reached from the source point using only the desired moves, else return false.

The output for each test case is to be printed on a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= x, y <= 3000

Where ‘T’ is the number of test cases and ‘x’, ‘y’ are the coordinates of the given points.

Time Limit: 1sec
Sample Input 1:
2
1 1 3 5
1 1 1 4
Sample Output 1:
True
True
Explanation For Sample Input 1:
For the first test case
The output will be true as destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (3, 2) -> (3, 5)

For the second test case
The output will be true as destination point can be reached using the following sequence of moves:
(1, 1) -> (1, 2) -> (1, 3) -> (1, 4)
Sample Input 2:
2
1 1 2 2
1 1 1 1
Sample Output 2:
False
True
*/





/*
EXPLANATION :
Analyze the Moves properly based on two conditions, like suppose both a and b are 1 initially.

Condition (a, a+b) => (1, 1+1) => (1, 2) i.e. If we make a move (a, a+b), our new b value will be greater than a.
Condition (a + b, b) => (1 + 1, 1) => (2, 1) i.e. If we make a move (a+b, b), our new a value will be greater than b.

So, instead of incrementing sx or sy, we play it safe using kind of reverse engineering 🤯, and decrement dx or dy. 
Because, instead of trying two directions to move up, we might choose to track downwards on exact 1 path, that we might have took to climb up.

If dx is greater than dy, it means we might have made a previous move as (a + b, a), So, we do reverse of it as(a - b, b)

if dy is greater than dx, it means we might have made a previous move as (a, a + b). So, we do reverse of it as (a, b - a).

EXPLAIN : if b = -----      =>  after a+b, b   =>  a = --------
                   a = ---                                    b = -----

Observation : dx and dy can never be equal, apart from one case => if the initial sx , sy itself is the destination points and sx == sy
*/

bool reachDestination(int sx, int sy, int dx, int dy) {
    while(dx >= sx && dy >= sy){
        if(sx == dx && sy == dy) return true;

        if(dx > dy) dx = dx - dy;
        else dy = dy - dx;
    }

    return false;
}