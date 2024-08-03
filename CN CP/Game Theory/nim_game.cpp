/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575417/offering/8882804/problem/16455
*/



/*
Nim game statement => Ninja and friends are playing game. There are N piles and each pile contains A[i] stones in it.
In each move, a player can choose any pile and remove any number of stones(atleast one) from that pile.
The player who cannot make a move looses the game.
Ninja plays first. Output 1 if ninja wins , else 0.
*/

/*
Nim game solution : just do xor of all the initial number of stones in each pile. If xor == 0, then this is a loosing position for the player making the move
*/

int ninjaGame(vector<int> &a, int n) {
    int check = 0;
    for(int i : a){
        check ^= i;
    }

    if(check == 0) return 0;
    else return 1;
}
