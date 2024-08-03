/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575417/offering/8882823/problem/10476
*/


int coinGameWinner(int n, int a, int b)
{
	if(n == 1 || n == a || n == b) return 1;

	int winner[100001];
	winner[0] = 0;

	for(int i=1; i<=n; i++){
		if(i-a >= 0 && winner[i-a] == 0) winner[i] = 1;
		else if(i-b >= 0 && winner[i-b] == 0) winner[i] = 1;
		else if(winner[i-1] == 0) winner[i] = 1;
		else winner[i] = 0;
	}

	return winner[n];
}