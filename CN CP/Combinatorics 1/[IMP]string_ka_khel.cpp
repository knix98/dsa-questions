/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575413/offering/8882739/problem/10540
*/


// little bit explanation is written in CN CP hand notes of Combinatorics 1 chapter
int stringKhel(vector<string>& arr, int n)
{
	int len = arr[0].size();  // length of each string

	int rr = 0, bb = 0, rb = 0, br = 0;
	for(string s : arr){
		if(s[0] == 'R'){
			if(s[len-1] == 'R') rr++;
			else rb++;
		}
		else{
			if(s[len-1] == 'R') br++;
			else bb++;
		}
	}

	int ans = 0;
	if(rb == 0 && br == 0){ 
		ans = max(bb, rr);
	}
	else if(rb == br){ 
		ans = n;
	}
	else{
		ans = bb + 1 + rr + (2 * min(rb, br));
	}

	return ans * len;
}
