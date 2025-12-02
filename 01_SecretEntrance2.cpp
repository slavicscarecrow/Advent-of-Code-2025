#include<iostream>
#include<fstream>
using namespace std;


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
	ifstream data;
    string s;
	data.open("input_01.txt");
    int dial = 50;
    int direction;
    int counter = 0;
    int ile=0;
    bool cycle = 0;
    while(!data.eof())
    {
        data>>s;
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
        if (dial==0 && (ile>-99 and ile<0)) // no cycle, so 0 won't click
        {
        	cycle = 0;
			dial = 100+ile;	
        }
        
        else
        {
        	
        dial = dial + ile;

        while (dial<0)
        {
	        dial = 100+dial; 
	        //cout<<"S<0: "<<s<<endl;
	        counter++;
	        cycle = 1;
	    }
	    
	    while(dial>99)
	    {
	    	//cout<<"enter wtf";
	    	//cout<<"Too big dial for "<<s<<": "<<dial<<endl;
			dial = dial-100;
			counter++;
			//cout<<"S>100: "<<s<<endl;
			cycle = 1;
			//cout<<s<<" is a cycle"<<endl;
		}
		}
		if (dial==0 && cycle==0) // so we land on 0 from L
		{
		//	cout<<"SNC: "<<s<<endl;
			counter++;
			///cout<<s<<endl;
		}
		
		//cout<<"Dial after "<<s<<": "<<dial<<endl<<"-------"<<endl;
    }
    
    cout<<counter<<endl;
    data.close();
    return 0;
}