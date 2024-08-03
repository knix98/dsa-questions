/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575417/offering/8882800/problem/16580
*/


// basically we will do memoization (recursion and backtracking, but also storing the answers, so that recursion is not called on same thing 2 times)
// because straight up dp is not possible here, because the dependence of dp[i][j] is on cells which are far away from i,j
int grid[16][16];
bool gridInitialiseDone = false;

/*
	x-1, y-2
	x+1, y-2
	x-2, y-1
	x-2, y+1
*/

bool valid(int x, int y) { 
	if(x<=0 or y<=0 or x>15 or y>15) {
		return false;
	}
	return true;
}

// basically for x,y to be winning position, atleast 1 possible next move cell should be a loosing position
// if all possible next move cells are winning positions themselves, then x,y is loosing position
int f(int x, int y) {
	if(grid[x][y] != -1) return grid[x][y];

	else {
		bool isWin = false;
		if(valid(x-1, y-2)) {
			if(f(x-1, y-2) == 0) isWin = true;
		}

		if(valid(x+1, y-2)) {
			if(f(x+1, y-2) == 0) isWin = true;
		}

		if(valid(x-2, y-1)) {
			if(f(x-2, y-1) == 0) isWin = true;
		}

		if(valid(x-2, y+1)){
			if(f(x-2, y+1) == 0) isWin = true;
		}

		if(isWin) grid[x][y] = 1;
		else grid[x][y] = 0;
		return grid[x][y];
	}
}


string winnerOfGame(int x, int y)
{
    if(!gridInitialiseDone) {
        for(int i=0; i<=15; i++) {
			for(int j=0; j<=15; j++) {
				grid[i][j] = -1;
			}
		}
        gridInitialiseDone = true;
    }

    if(f(x, y) == 0) return "Second"; // means x,y is loosing position, so second wins
	else return "First";
}