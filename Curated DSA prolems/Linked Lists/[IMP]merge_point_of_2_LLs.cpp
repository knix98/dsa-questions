/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204225/offering/2650149/problem/14057?leftPanelTabValue=PROBLEM

Given two singly linked lists, 'FIRST_HEAD' and 'SECOND_HEAD'. Your task is to find the 'MERGING POINT' i.e. the data of the node at which merging starts. If there is no merging, return -1.

For example:-

The given Linked Lists are merging at node c1.
In this case, c1 is 'MERGING POINT'.
alt.txt

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^5     
0 <= M <= 10^5
0 <= K <= 10^5.
-10^9 <= data <= 10^9 and data != -1


 Time Limit: 1 sec
Sample Input 1 :
4 1 8 -1
5 6 1 8 -1
4 5 -1
Sample Output 1 :
8
Explanation For Sample Input 1:
As shown in the diagram the node with data is 8 at which merging starts
Sample Input 1

Sample Input 2 :
1 2 3 4 5 -1
2 3 4 5 -1
6 7 -1
Sample Output 2 :
5
Sample Input 3 :
2 6 4 -1
1 5 -1
-1
Sample Output 3 :
-1
*/





/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    where N is the maximum length of linked list.
*/
int length(Node *head)
{
    int length = 0;
    Node *tmp = head;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        length++;
    }

    return length;
}

int findIntersection(Node *firstHead, Node *secondHead)
{

    //Get the length of both list
    int firstListLength = length(firstHead), secondListLength = length(secondHead);

    //Move headA and headB to the same start point
    while (firstListLength > secondListLength)
    {
        firstHead = firstHead->next;
        firstListLength--;
    }

    while (firstListLength < secondListLength)
    {
        secondHead = secondHead->next;
        secondListLength--;
    }

    //Find the intersection until end
    while (firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    if (firstHead == NULL)
    {
        return -1;
    }

    return firstHead->data;
}