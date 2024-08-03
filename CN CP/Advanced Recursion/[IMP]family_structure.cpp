/*
Aakash is a member of Ninja club. He has a weird family structure. Every male member (M) gives birth to a male child first and then a female child, whereas every female (F) member gives birth to a female child first and then to a male child. Aakash analyses this pattern and wants to know what will be the Kth child in his Nth generation. Can you help him?
A sample generation tree is shown, where ‘M’ denotes the male member and ‘F’ denotes the female member. 

        M             -> first generation
      /   \
    M       F         -> 2nd generation
  /  \    /   \     
M     F  F      M     -> M = 1st child, F = 2nd, F = 3rd, M = 4th

Note
The generation tree starts with a male member i.e. Aakash. 
Every member has exactly two children. 
The given N and K will always be valid. 
Input Format:
The first line contains an integer 'T' which denotes the number of test cases. Then the test cases follow.
The first and the only line of each test case contains two space-separated integers ‘N’ and ‘K’ denoting the generation number and position of the child in Nth generation, respectively. 
Output Format
For each test case, print the gender of the Kth child in the Nth generation. If the gender is male, print “Male” else print “Female” (without quotes). 
The output of each test case is printed in a separate line. 
Note
You don’t have to print anything, it has already been taken care of. Just implement the given function. 
Constraints :
1 <= T <= 5
1 <= N <= 50
1 <= K <= 2^(N - 1)
where ‘T’ is the number of test cases, ‘N’ is generation number and ‘K’ is the position of the child in the Nth generation. 
Sample Input 1:
2
2 2 
3 4  
Sample Output 1:
Female
Male

Sample Input 2:
3
5 1 
3 1
4 4  
Sample Output 2:
Male
Male
Male 
*/


// APPROACH 1 : same as the recursive code below, but in iterative way, by saving the parents in an array
// this code would work for bigger values of n also, because this bottom-up approach and hence there is no need to
// calculate total number of nodes in nth row (2^(n-1)) , which goes out of range of ll
#define ll long long

string kthChildNthGeneration(int n, long long int k)
{
	vector<ll> parents;  // save all nodes from bottom upto root in this array
	while(n >= 1){
		parents.push_back(k);
		k = (k+1)/2;
		n--;
	}

	int gender = 1;  // 1 means male and -1 means female 
	// initially setting gender = male and then starting from second node to root node
	for(int i=parents.size()-2; i>=0; i--){
		if(parents[i] % 2 == 0) gender *= -1; 
	}

	if(gender == 1) return "Male";
	else return "Female";
}




// Recursive code of APPROACH 1 : if we know k = kth child in nth genration, so we can get number of k's parent in the parent's generation using
// parent number = (k+1) / 2
// So call recursion for getting parent number 's gender in n-1th generation
// Time complexity : min( n, log(k) )
string kthChildNthGeneration(int n, long long int k) {
	// base case
	if(n==1 || k == 1) return "Male";  // because the first child in each generation is also, always male if you look at any tree

	// get the parent's index in the previous generation
	ll parent = (k + 1) / 2;

	// get the parent's gender
	string parentGen = kthChildNthGeneration(n-1, parent);

	// if k is first child of parent , then k's gender would be same as parent
	if(k == (2*parent)-1) return parentGen;
	else {
		if(parentGen == "Male") return "Female";
		else return "Male";
	}
}





// APPROACH 2 : since the constraints given in question for n are upto n==50, so the below approach of going from top to bottom
// would not work for bigger values of n
#define ll long long

ll pow_func(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b%2 == 0){
			ans *= (a*a);
			b /= 2;
		}
		else{
			ans *= a;
			b--;
		}
	}

	return ans;
}

string kthChildNthGeneration(int n, long long int k)
{
	ll children_in_nth_gen = pow_func(2, n-1);  // total number of nodes in nth row
	string curr_person_gender = "Male";  // root node is always male
	while(n > 1){
		if(k <= (children_in_nth_gen/2)){
			// go to left subtree, curr_person_gender would remain same for right child
		}
		else{
			// go to right subtree
			if(curr_person_gender == "Male") curr_person_gender = "Female";
			else curr_person_gender = "Male";
			k -= (children_in_nth_gen/2);  // update k, because in next iteration the right child node would be considered as root
		}

		n--; // go to next row below
		children_in_nth_gen /= 2;  // children in nth row would decrease when we go below in tree
	}

	if(k == 1) return curr_person_gender;
	else if(curr_person_gender == "Male") return "Female";
	else return "Male";
}



//APPROACH 2 : starting from root and taking (after calculations) the shortest path to reach kth child in nth generation
// Time : 
string helper(int &n, int l, ll &k, ll perNum, ll &nPeople, char perGen){  // l = current level, perNum = current level's person's number 
                                                                           // nPeople = total people in nth gen (answer gen) , perGen = current level's person's gender 
	// base case
	if(l == n){
		if(perGen == 'm') return "Male";
		return "Female";
	}

	char firstChildGen = 'm', secondChildGen = 'f';
	if(perGen == 'f'){
		firstChildGen = 'f';
		secondChildGen = 'm';
	}

	ll secondChild = 2*perNum; // second child number
	ll firstChild = secondChild - 1; // first child number

	ll totalChilds = pow(2, l);  // total people in next gen

    // calculating the range of nth gen childs of current person's first child and 2nd child, so that we can decide, that which child (1st or 2nd) to take in next recursion
	ll fCSt = ((firstChild-1) * (nPeople / totalChilds)) + 1;    
	ll fCEn = firstChild * (nPeople / totalChilds);  // IMP : if we do (firstChild * nPeople) / totalChilds => it is exceeding ll's range and becoming negative
                                                        // therefore first i m doing (nPeople / totalChilds)  and then multiplying this reduced number with firstChild
                                                        // but be careful and think carefully that (nPeople / totalChilds) > 1 , otherwise 0 would be answer

    // if k lies in first child's range or second child's range
	if(k >= fCSt && k <= fCEn) return helper(n, l+1, k, firstChild, nPeople, firstChildGen);
	return helper(n, l+1, k, secondChild, nPeople, secondChildGen);
}

string kthChildNthGeneration(int n, long long int k)
{
	ll nPeople = pow(2, n-1);
	return helper(n, 1, k, 1, nPeople, 'm');
}

