#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<vector<int>> numbers;

int current_vec_id = 0;

unsigned long long int total_result=0;

unsigned long long int solve(char operation)
{
	unsigned long long int res;
	if (operation=='*')
	{
		res = 1;
		for (int i=0; i<numbers[current_vec_id].size();i++)
		{
			res*=numbers[current_vec_id][i];
		}
	}
	if(operation=='+')
	{
		res = 0;
		for (int i=0; i<numbers[current_vec_id].size();i++)
		{
			res+=numbers[current_vec_id][i];
		}
	}
}

int convert_to_int(string s)
{
    int x = 1;
    int res = 0;
    for (int j = s.size()-1; j>=0; j--)
    {
    	// run the function if + or *
        res+=(('0'-s[j])*x*-1);
        x*=10;
    }
    // instead of returning the res, just add them to vector
    return res;
}

void helper_print()
{
	for (int i=0; i<numbers.size(); i++)
	{
		for (int j=0; j<numbers[i].size();j++)
		{
			cout<<numbers[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
    ifstream data;
    data.open("testinput_06.txt");
    string s;
    vector<string> rows;
    string operations;
    while(!data.eof())
    {
        getline(data,s);
		rows.push_back(s);
	}
    
	data.close();
    
    string x="";
    int columns = rows[0].size(); // the number of columns is the same for each line
    
    cout<<"Random: "<<rows[2][2]<<endl;
    
    //cout<<rows.size()<<endl;
    
    for (int i=columns-i; i>=0; i--)
    {
    	
    	x = "";
    	for (int j=0; j<rows.size(); j++)
    	{
    		//cout<<i<<" , "<<j<<", rows "<<rows[j][i]<<endl;
    		if (rows[j][i]!=' ') x = x + rows[j][i];		
		}
		cout<<x<<endl;
	}
	
    cout<<"*************"<<endl;
    helper_print();
    
	
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