#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<string>diagram;

bool check_fields(int x, int y)
{
	int counter = 0;
	for (int i=-1; i<=1; i++)
	{
		for (int j=-1; j<=1; j++)
		{
			if (x+i>=0 && x+i<diagram[0].size() && y+j>=0 && y+j<diagram.size())
			{
				if (diagram[x+i][y+j]=='@')
				{					
					counter++;
				}
			}
		}
	}
	
	counter--;
	if (counter>=4) return false;
	//cout<<x<<" "<<y<<endl;
	diagram[x][y]='.';
	return true;
}

void printdiagram()
{
	for (int i=0; i<diagram[i].size(); i++)
	{
    	cout<<diagram[i]<<endl;
	}
	cout<<endl;
}

int main()
{
	ifstream data;
	string s;
	data.open("input_04.txt");
    
    int result=1;
    int removed = 0;
    while (!data.eof())
    {
    	data>>s;
        diagram.push_back(s);
    }
    while(result>0)
    {
    	result = 0;
	    for (int i=0; i<diagram[i].size(); i++)
	    {
	    	for (int j=0; j<diagram.size();j++)
	    	{
	    		if(diagram[i][j]=='@' && check_fields(i,j))
	    		{
	    			result++;
	    			removed++;
	    		//	printdiagram();
				}
			}
		}
		cout<<endl;
	}
	data.close();
	cout<<removed<<endl;
	return 0;
}