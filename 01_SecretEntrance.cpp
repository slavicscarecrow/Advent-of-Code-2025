#include<iostream>
using namespace std;

const int n = 4068;

int convert_to_int(string s)
{
    int x = 1;
    int res = 0;
    for (int j = s.size()-1; j>0; j--)
    {
    	if (s[j]!=' ')
    	{
	        res+=(('0'-s[j])*x*-1);
	        x*=10;
    	}
    }
    return res;
}

int main()
{
    int dial = 50;
    int direction;
    int counter = 0;
    string s;
    
    for (int i=0; i<n; i++)
    {
        cin>>s;
        if (s[0]=='L')
        {
            direction = -1;
        }
        else
        {
            direction = 1;
        }
        dial = dial + (direction * convert_to_int(s));
        while (dial<0)
        {
            dial = 100+dial; // wliczamy 0 - przy setce resetujemy
            if (dial==100) 
			{
				dial = 0;
				
			}
        }
        while(dial>99)
        {
			dial = dial-100;
			if (dial==100) 
			{
				dial = 0;	
		}
        if (dial==0)
        {
            counter++;
        }
        if(dial==100)
        {
        	dial = 0;
		}
    }
    
    cout<<counter<<endl;
    
    return 0;
}