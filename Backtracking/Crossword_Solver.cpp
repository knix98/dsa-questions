/*
Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values.
Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.

Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'.

Output format:
Print the crossword grid, after placing the words of word list in '-' cells.

Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second

Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include <bits/stdc++.h>
using namespace std;

void printAns(vector<vector<char>> &cw)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << cw[i][j];
        }
        cout << endl;
    }
}

pair<int, int> blankChecker(vector<vector<char>> &cw, int x, int y, string direction)
{
    // (x,y) ke aage-peeche dono check kar for blankLength
    pair<int, int> blankEnds;

    // first check in reverse...
    if (direction == "row")
    {
        int j = y - 1;
        while (j >= 0 && cw[x][j] != '+')
        {
            j--;
        }

        blankEnds.first = j + 1;
    }
    else
    {
        int i = x - 1;
        while (i >= 0 && cw[i][y] != '+')
        {
            i--;
        }

        blankEnds.first = i + 1;
    }

    // now check in forward...
    if (direction == "row")
    {
        int j = y + 1;
        while (j < 10 && cw[x][j] != '+')
        {
            j++;
        }

        blankEnds.second = j - 1;
    }
    else
    {
        int i = x + 1;
        while (i < 10 && cw[i][y] != '+')
        {
            i++;
        }

        blankEnds.second = i - 1;
    }

    return blankEnds;
}

bool wordSetter(vector<vector<char>> &cw, string word, int x, int y, int *blankPositions, string direction)
{
    // at whichever index a new char inserted(because of presence of blank) -> we will mark 1 in blankPositions

    if (direction == "row")
    {
        // 'i' will travel over the row of cw, and j will travel over word as well as blankPositions
        for (int i = y, j = 0; j < word.size(); i++, j++)
        {
            if (cw[x][i] == '-')
            {
                blankPositions[j] = 1;
                cw[x][i] = word[j];
            }
            else
            { // means here a char is already present
                if (cw[x][i] != word[j])
                {
                    return false;
                }
            }
        }
    }
    else
    {
        // 'i' will travel over the column of cw, and j will travel over word as well as blankPositions
        for (int i = x, j = 0; j < word.size(); i++, j++)
        {
            if (cw[i][y] == '-')
            {
                blankPositions[j] = 1;
                cw[i][y] = word[j];
            }
            else
            { // means here a char is already present
                if (cw[i][y] != word[j])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void wordRemover(vector<vector<char>> &cw, string word, int x, int y, int *blankPositions, string direction)
{
    // will just place a '-' at whichever positions 1 is present in blankPositions
    // recieved word (to be removed) as argument just for the length of the word

    if (direction == "row")
    {
        // 'i' will travel over the row of cw, and j will travel over blankPositions
        for (int i = y, j = 0; j < word.size(); i++, j++)
        {
            if (blankPositions[j] == 1)
            {
                cw[x][i] = '-';
            }
        }
    }
    else
    {
        // 'i' will travel over the column of cw, and j will travel over blankPositions
        for (int i = x, j = 0; j < word.size(); i++, j++)
        {
            if (blankPositions[j] == 1)
            {
                cw[i][y] = '-';
            }
        }
    }
}

bool mainSolver(vector<vector<char>> &cw, unordered_map<int, queue<string>> &words, int x, int y)
{
    // edge case: if (x,y) has gone out of the crossword
    if (y >= 10)
    {
        x++;
        y = 0;

        if (x >= 10)
        {
            printAns(cw);
            return true;
        }
    }

    // start checking each of the coordinates inside crossword...
    for (int i = x; i < 10; i++)
    {
        // initialize j to 0 if, we have gone into a new row of crossword
        for (int j = i == x ? y : 0; j < 10; j++)
        {

            // base case: if we reach end of crossword...
            if (i == 9 && j == 9 && cw[i][j] != '-')
            {
                printAns(cw);
                return true;
            }

            // we wud do anything only when a '-' is encountered
            if (cw[i][j] == '-')
            {

                // first checking if a word can be filled in row direction at this '-'
                pair<int, int> blankEnds = blankChecker(cw, i, j, "row"); // first get the endpoints of this blank in horizontal direction
                int blankLength = blankEnds.second - blankEnds.first + 1;
                for (int k = 0; k < words[blankLength].size(); k++) // check if any of the words(present with us currently) of blanklength fits correctly into this blank
                {
                    string front = words[blankLength].front();
                    words[blankLength].pop();

                    int blankPositions[blankLength] = {0}; // this array wud be given to wordSetter, so that, it can mark the positions, wherever chars were inserted

                    // if word fits into the blank && then we pass thee rest of crossword to recursion call, and if recursion returns true...
                    // then we can assume that answer wud have been printed by base case, so we simply return true
                    // the starting point for recursion wud be the next cell after the blank (i, blankEnds.second + 1)
                    if (wordSetter(cw, front, i, blankEnds.first, blankPositions, "row") && mainSolver(cw, words, i, blankEnds.second + 1))
                    {
                        return true;
                    }
                    else
                    { // means front(word) didn't set in the blank || front did set but, just wasn't the right word at this blank
                        // then push the word at the back of the queue and also remove the word from the cw
                        // wordRemover wud remove the chars only from those positions in the blank where new chars were inserted(using the blankPositions array)...
                        // and wud not remove the already present chars
                        words[blankLength].push(front);
                        wordRemover(cw, front, i, blankEnds.first, blankPositions, "row");
                    }
                }

                // if row checking fails to solve crossword then we check in column direction for this blank...
                // similar code as above for column checking...just some minor changes to adjust for column instead of row
                blankEnds = blankChecker(cw, i, j, "column");
                blankLength = blankEnds.second - blankEnds.first + 1;
                for (int k = 0; k < words[blankLength].size(); k++)
                {
                    string front = words[blankLength].front();
                    words[blankLength].pop();

                    int blankPositions[blankLength] = {0};

                    // in case of column checking...we wud give the starting point to recursion as the next cell (i,j+1)
                    if (wordSetter(cw, front, blankEnds.first, j, blankPositions, "column") && mainSolver(cw, words, i, j + 1))
                    {
                        return true;
                    }
                    else
                    { // means front didn't set in the blank || front just wasn't the right word at this blank
                        words[blankLength].push(front);
                        wordRemover(cw, front, blankEnds.first, j, blankPositions, "column");
                    }
                }

                // backtrack with false if anywhere in the above code true wasn't returned
                return false; // because no word fitted here (at this '-'), neither in row direction nor in column direction
            }
        }
    }
}

int main()
{
    vector<vector<char>> cw; // for taking the input of empty crossword

    // taking empty crossword input
    for (int i = 0; i < 10; i++)
    {
        vector<char> v;
        char c;
        for (int j = 0; j < 10; j++)
        {
            cin >> c;
            v.push_back(c);
        }
        cw.push_back(v);
    }

    // taking the input of string containing all the words
    string words;
    cin >> words;

    // map wud contain string-length as key and the strings of that length, wud be kept in a queue as value
    unordered_map<int, queue<string>> wordMap;

    string word = "";
    for (int i = 0; i <= words.size(); i++)
    {
        // if end of input string || ';' encountered
        if (i == words.size() || words[i] == ';')
        {
            // then input the string formed into the queue corresponding to the length of string
            if (wordMap.count(word.size()) > 0)
            {
                wordMap[word.size()].push(word);
            }
            else
            {
                // if queue corresponding to the length of string no there in map...
                // then create a queue and rhen insert this queue corresponding to string length in the map
                queue<string> q;
                q.push(word);
                wordMap[word.size()] = q;
            }

            word = "";
        }
        else
        {
            word += words[i];
        }
    }

    // (0,0) is the starting point for the solver
    mainSolver(cw, wordMap, 0, 0);

    return 0;
}