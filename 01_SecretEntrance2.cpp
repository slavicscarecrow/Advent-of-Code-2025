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
    int ile=0;
    bool cycle = 0;
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
        cycle = 0;
        ile = direction * convert_to_int(s);
        dial = dial + ile;
		
		if (dial==0 && ile>-99) // no cycle, so 0 won't click
        {
        	cycle = 0;
        	//counter--;
        	dial = 99+ile;
        	//cout<<"Erasing start from 0 going out of bounds "<<s<<endl;
		}
	
        while (dial<0)
        {
        	//cout<<"Too small dial for "<<s<<": "<<dial<<endl;
	        dial = 100+dial; 
	        counter++;
	        //cout<<s<<endl;
	        cycle = 1;
	        //cout<<s<<" is a cycle"<<endl;
	    }
	    
	    while(dial>99)
	    {
	    	//cout<<"Too big dial for "<<s<<": "<<dial<<endl;
			dial = dial-100;
			counter++;
			//cout<<s<<endl;
			cycle = 1;
			//cout<<s<<" is a cycle"<<endl;
		}
		
		if (dial==0 && !cycle)
		{
			//cout<<"Adding counter for "<<s<<endl;
			counter++;
		}
		
		//cout<<"Dial after "<<s<<": "<<dial<<endl<<"-------"<<endl;
    }
    
    cout<<counter<<endl;
    
    return 0;
}