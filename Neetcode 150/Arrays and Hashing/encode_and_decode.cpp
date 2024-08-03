/*
Problem link : https://www.lintcode.com/problem/659/
*/


/*
Approach : in the encoded string I will put 2 infos before each string : 1. length of string 2. number of digits in length of string
Ex : ["abc", "def"]
encoded str = "13abc13def"
13abc means abc is 3 length str and there are 1 number of digits in 3
since number of digits in length of str will never exceed 9, we can be sure that the first char only represents number of digits in length of str
*/

/*
Another nice approach can be neetcode's approach : 
in the encoded string I will put 2 infos before each string : 1. length of string 2. a delimiter say #
Ex : ["abc", "def"]
encoded str = "3#abc3#def"
*/

int strtoint(string s) {
    int digit, ans = 0, multiplier = 1;
    for(int i=s.size()-1; i>=0; i--) {
        digit = (int)s[i] - (int)'0';
        ans += (digit * multiplier);
        multiplier *= 10;
    }

    return ans;
}

string inttostr(int n) {
    int digit;
    string ans = "";
    while(n > 0) {
        digit = n%10;
        n /= 10;

        ans = (char)(digit + (int)'0') + ans;
    }

    return ans;
}

class Solution {
public:
    /*
    * @param strs: a list of strings
    * @return: encodes a list of strings to a single string.
    */
    string encode(vector<string> &strs) {
        string ans = "";
        for(string s : strs) {
            string sizestr = inttostr(s.size());
            sizestr = (char)(sizestr.size() + (int)'0') + sizestr;
            ans += sizestr;
            ans += s;
        }

        return ans;
    }

    /*
    * @param str: A string
    * @return: decodes a single string to a list of strings
    */
    vector<string> decode(string &s) {
        vector<string> ans;
        int i = 0, len, sizestrlen;
        string sizestr, temp;
        while(i < s.size()){
            sizestrlen = (int)s[i++] - (int)'0';
            sizestr = "";
            while(sizestrlen--){
                sizestr += s[i++];
            }

            len = strtoint(sizestr);

            temp = "";
            while(len--){
                temp += s[i++];
            }

            ans.push_back(temp);
        }

        return ans;
    }
};