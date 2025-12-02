#include<iostream>
#include<fstream>
using namespace std;

unsigned long long int mult(unsigned long long int a, unsigned long long int b) // a^b
{
	unsigned long long int res = 1;
	for (unsigned long long int i=0; i<b; i++)
	{
		res *= a;
	}
	return res;
}

unsigned long long int len_of_int(unsigned long long int i)
{
	unsigned long long int_len = 1;
	while(i/10>0)
	{
		int_len++;
		i/=10;
	}
	return int_len;
}

bool divs(unsigned long long int x)
{
	unsigned long long int x_size = len_of_int(x);
	unsigned long long int temp;
	unsigned long long int d = 1;
	unsigned long long int y=0;
	unsigned long long int part = 0; // 12 in 121212 for example
	unsigned long long int p10 = 1; // 100 for 12 in 121212
	//bool is_divs=0;
	for (unsigned long long int d = 1; d<=x_size/2; d++)
	{
		y = 0;
		if (x_size%d==0)
		{
			
			temp = x;
			p10 = mult(10,d);
			part = temp%p10;
			//cout<<d<<"-sized part "<<part<<" trying to be divided by "<<p10<<endl;
			while(temp%p10==part)
			{
				temp/=p10;
				if(temp==0)
				{
					return true;	
				}	
			}
			
		}
	}	
	
	return false;
}

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

unsigned long long int final=0;
void generate(unsigned long long int x, unsigned long long int y)
{
	cout<<"In range: "<<x<<", "<<y<<endl;
	unsigned long long int int_len;
	unsigned long long int temp;
	unsigned long long int m;
	for (unsigned long long int i = x; i<=y; i++)
	{
		if(divs(i))
		{
			final+=i;
		}
	}
}


int main()
{
	ifstream data;
    string s;
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