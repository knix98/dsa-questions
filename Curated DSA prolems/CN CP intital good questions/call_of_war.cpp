/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575394/offering/8882390/problem/9060?leftPanelTabValue=PROBLEM

DecenTile Games have launched a new First Person Shooter soldier game, called the Call of War, that young gamers can play on their website.

Our protagonist, Ninja (played by you) is a soldier whose mission is to kill all the enemies plotting against you. Your enemies are standing in a circle, numbered clockwise from 1 to n. Initially, the i-th enemy has ai health.

You have only one pistol, and infinite bullet magazines. You have to shoot the enemies in order to kill them. Each bullet fired at the enemy decreases their health by 1 (deals 1 damage to it). When the health of some enemy i becomes 0 or less than 0, he dies and his grenade drops down and explodes, dealing bi damage to the next enemy (enemy i+1, if i<n, or enemy 1, if i=n). If the next enemy is already dead, then nothing happens. If the frag from the grenade kills the next enemy, even he drops a grenade, damaging the enemy after him and possibly triggering another explosion, and so on.

You have to calculate the minimum number of bullets you need in order to kill all the enemies and win the game.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 10^4
1 <= a, b <= 10^12
Sample Input:
1
3
7 15
2 14
5 3
Sample Output:
6
*/



#include<bits/stdc++.h>
using namespace std;

// APPROACH : Every person's hlth and dmg it can get from previous person is fixed
// So if hlth[i] - dmg[i-1] for some person is positive, then that means no matter from which position we start the killing
// this person would not die by dmg[i-1] alone and we would have to spend hlth[i] - dmg[i-1] on this person
// So a O(n) approach : calculate all such positive differences in "totalPositiveHealthRemaining"
// Now calculate total bullets required to finish everyone when started from person at index i using this formula :-
// totalBullets[i] = hlth[i] + (totalPositiveHealthRemaining - positiveHealthValueAtCurrentIndex)
// where positiveHealthValueAtCurrentIndex = hlth[i] - dmg[i-1]

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> hlth(n);
        vector<int> dmg(n);

        for(int i=0; i<n; i++){
            cin >> hlth[i] >> dmg[i];
        }

        vector<int> afterDmg(n, 0);
        int totalPositiveHealthRemaining = 0;
        for (int i = 0; i < n; i++) {
            int nextI = (i + 1) % n;

            afterDmg[nextI] = hlth[nextI] - dmg[i];

            if (afterDmg[nextI] > 0)
              totalPositiveHealthRemaining += afterDmg[nextI];
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int check = hlth[i] + totalPositiveHealthRemaining;
            if(afterDmg[i] > 0) check = check - afterDmg[i];

            ans = ans > check ? check : ans;
        }

        cout << ans << endl;
    }

    return 0;
}