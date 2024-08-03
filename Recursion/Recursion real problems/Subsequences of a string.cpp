#include <bits/stdc++.h>
using namespace std;

// RETURN/STORE SUBSEQUENCES OF A STRING IN AN OUTPUT ARRAY
int subs(string input, string *output){
    if(input.empty()){ //base case
        output[0]="";
        return 1;
    }

    string smallString = input.substr(1);
    int smallStringOutput = subs(smallString, output); //calling recursion on smaller string (without first character)

    for(int i=0; i<smallStringOutput; i++){
        output[i+smallStringOutput] = input[0]+output[i];//adding the first char to every small string subsequences
                                                         //and storing them below the previous small subsequences in the output array
    }

    return 2*smallStringOutput; //return the final size of output array
}

int main(){
    string input;
    cin >> input;
    int n=input.size();
    int x=pow(2, n);
    string *p = new string[x];

    int count=subs(input, p);
    for(int i=0; i<count; i++){
        cout << p[i] << endl;
    } 

    delete [] p;
}




//PRINT SUBSEQUENCES OF A STRING
void printSubs(string input, string print){
    if(input.empty()){
        cout << print << endl;
        return;
    }

    printSubs(input.substr(1), print);
    printSubs(input.substr(1), print + input[0]);
}

int main(){
    string input;
    cin >> input;
    cout << "subsequences...." << endl;
    printSubs(input, "");
}