#include<iostream>
#include<fstream>
using namespace std;

unsigned long long int convert_to_int(string s)
{
    unsigned long long int x = 1;
    unsigned long long int res = 0;
    for (long long int j = s.size()-1; j>=0; j--)
    {
    	res+=(('0'-s[j])*x*-1);
	    x*=10;
    }
    return res;
}

unsigned long long int mult(unsigned long long int a, unsigned long long int b) // a^b
{
	unsigned long long int res = 1;
	for (unsigned long long int i=0; i<b; i++)
	{
		res *= a;
	}
	return res;
}
unsigned long long int final=0;
void generate(unsigned long long int x, unsigned long long int y)
{
	cout<<"In range: "<<x<<", "<<y<<endl;
	unsigned long long int int_len;
	unsigned long long int temp;
	unsigned long long int m;
	for (unsigned long long int i = x; i<=y; i++)
	{
		temp = i;
		int_len = 1;
		while(temp/10>0)
		{
			int_len++;
			temp/=10;
		}
		if(int_len%2==0)
		{
			m = mult(10, (int_len/2));
			if(i%m == (i/m)%m)
			{
				final +=i;
				cout<<i<<endl;
			}
		}
		//cout<<"Len of "<<i<<": "<<int_len<<endl;
	}
}


int main()
{
	ifstream data;
    string s;

	cout<<"Norton let me run my exe! "<<endl;
    data.open("input_02.txt");
    
    while (!data.eof())
    {
        data >> s;
    }
    //cin>>s;
    //cout<<s;
    unsigned long long int a;
    unsigned long long int b;
    string num="";
    for (int i=0; i<s.size(); i++)
    {
    	if (s[i]!=',' && s[i]!='-')
    	{
    		num = num + s[i];
		}
		if (s[i]=='-')
		{
			a = convert_to_int(num);
			num = "";
		}
		if(s[i]==',' || i==s.size()-1) 
		{
			b = convert_to_int(num);
			generate(a,b);
			num = "";
		}
	}
	
	
	cout<<final<<endl;
	
	//generate(95,115);
	
	data.close();
	
	return 0;
}