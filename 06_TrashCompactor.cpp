#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<vector<int>> numbers;

int convert_to_int(string s)
{
    int x = 1;
    int res = 0;
    for (int j = s.size()-1; j>=0; j--)
    {
        res+=(('0'-s[j])*x*-1);
        x*=10;
    }
    return res;
}

int main()
{
    ifstream data;
    data.open("input_06.txt");
    string s;
    vector<string> rows;
    string operations;
    while(!data.eof())
    {
        getline(data,s);
        if(s[0]=='*' || s[0]=='+')
        {
        	operations = s;
		}
		else if (s.size()>0)
		{
			rows.push_back(s);
		}
    }
    data.close();
    
    string x="";
    
    cout<<rows.size()<<endl;
    for (int i=0; i<rows.size();i++)
    {
    	numbers.push_back({});
    	x = "";
    	for (int j=0; j<rows[i].size();j++)
    	{
    		if(rows[i][j]==' ')
    		{
    			if (x.size()>0) numbers[i].push_back(convert_to_int(x));
    			x = "";
			}
			else
			{
				x=x+rows[i][j];
			}
			if (j==rows[i].size()-1 && rows[i][j]!=' ')
			{
				numbers[i].push_back(convert_to_int(x));
			}
		}
	}
	
	
	for (int i=0; i<numbers.size(); i++)
	{
			cout<<numbers[i].size()<<" ";
		cout<<endl;
	}
	
	unsigned long long int single_res = 0;
	unsigned long long int total_res = 0;
	int index =0;
    for (int i=0; i<operations.size(); i++)
    {
    	if(operations[i]=='+')
    	{
    		single_res=0;
    		for (int j=0; j<numbers.size(); j++)
			{
				single_res+=numbers[j][index];
			}	
			index++;
			cout<<single_res<<endl;
			total_res+=single_res;
		}
		if(operations[i]=='*')
    	{
    		single_res=1;
    		for (int j=0; j<numbers.size(); j++)
			{
				single_res*=numbers[j][index];
			}
    		index++;
    		total_res+=single_res;
    		cout<<single_res<<endl;
		}
	}
	
	cout<<"Total: "<<total_res<<endl;
    
    
    return 0;
}