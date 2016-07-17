#include <iostream>
using namespace std;

string addBinary(string a, string b) {
        if(a.length() > b.length()) 
            for(int j = 0; b.length() != a.length(); ++j)
                b.insert(b.begin(), '0');
        else 
            for(int j = 0; b.length() != a.length(); ++j) 
                a.insert(a.begin(), '0');
        int carry = 0;
        string result;
        for(int i = a.length() - 1; i > -1; --i) {
            result.insert(result.begin(), (a[i] + b[i] -96 + carry)%2 + 48);
            if((a[i] + b[i] -96 + carry) > 1) 
                carry = 1;
            else 
                carry = 0;
        }
        if(carry == 1)
            result.insert(result.begin(), '1');
        return result;
     }

int main()
{
	string a = "11", b = "111";
	cout<<"a+b="<<addBinary(a,b)<<endl;
	return 0;
}
