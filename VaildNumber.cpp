/*
author: jtr@BNU
date: 8.7
Valid Number Total Accepted: 9095 Total Submissions: 82996 My Submissions
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/
 bool isNumber(const char *s) {
 	bool res = false;
        	int len = 0;
        	while(s[len] != '\0')
        	{
        		len++;
        	}
        	int k = 0;
        	while(s[k] == " ") ++k;
	for (int i = k; i < len; ++i)
	{

		char tem = s[i];
		if (/* condition */)
		{
			/* code */
		}

	}
	return res;
    }

int main(){
	char * s = "1.2";

	return 0;
}