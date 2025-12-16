#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


// gonna be using unsigned long long ints everywhere I can because I bought the whole computer, I can use the whole computer
unsigned long long int convert_to_int(string s)
{
    unsigned long long int x = 1;
    unsigned long long int res = 0;
    for (int j = s.size()-1; j>=0; j--)
    {
        res+=(('0'-s[j])*x*-1);
        x*=10;
    }
    return res;
}

vector <pair<unsigned long long int,unsigned long long int>> freshness_ranges;
void fill_array(string s)
{
    unsigned long long int x = 0;
    unsigned long long int y = 0;
    string s1 = "";
    for (int i=0; i<s.size(); i++)
    {

        if(s[i] == '-')
        {
            //cout<<"converting "<<s1<<" to int"<<endl;
            x =  convert_to_int(s1);
            s1 = "";
        }
        else
        {
            s1 = s1 + s[i];
        }
        if(i==s.size()-1)
        {
            y = convert_to_int(s1);
        }
    }
    freshness_ranges.push_back(make_pair(x,y));

}
// yea that's some very serious piece of code out there
void merge_ranges()
{
	sort(freshness_ranges.begin(), freshness_ranges.end());
	for (int i=0; i<freshness_ranges.size()-1; i++)
	{
		if(freshness_ranges[i+1].first>=freshness_ranges[i].first && freshness_ranges[i+1].first<=freshness_ranges[i].second)
		{
			if(freshness_ranges[i+1].second>=freshness_ranges[i].second) freshness_ranges[i].second = freshness_ranges[i+1].second;
			freshness_ranges.erase(freshness_ranges.begin()+i+1);
			i--;
		}
	}
	unsigned long long int counter=0;
	for (int i=0; i<freshness_ranges.size(); i++)
	{
		counter += (freshness_ranges[i].second-freshness_ranges[i].first)+1;
	}
	
	cout<<counter<<endl;
}

int main()
{
    ifstream data;
    data.open("input_05.txt");
    string s;
    bool first_input = true;
    while(!data.eof())
    {
        getline(data,s);
        if(s.size()==0)
        {
            first_input = false;
            merge_ranges();
            break;
        }
        if(first_input)
        {
            fill_array(s);
        }
    }
    data.close();
    
    
    return 0;
}