/*

Sample Input 1:
0 1 1 0 1 0 1
Sample Output 1:
0 0 0 1 1 1 1

*/


void sortZeroesAndOne(int *a, int size)
{
    int z=0, i=0; //z=index position for next 0
    
    for( ; i<size; i++){
        if(a[i] == 0){
            a[i] = a[z];
            a[z] = 0;
            z++;
        }
        else if(a[i] == 1){
            continue;
        }
    }
}