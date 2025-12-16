#include<iostream>
#include<fstream>
using namespace std;


long long int total_joltage = 0;

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

int biggest_element_id(string s, long int starting_i, char not_el) // searching for an index of the biggest element that is not not_el, starting from starting_i
{
	long int id=starting_i;
	char biggest_el=s[starting_i];
	for (long int i=starting_i; i<s.size(); i++)
	{
		if(s[i]>biggest_el && s[i]!=not_el)
		{
			biggest_el = s[i];
			id = i;
		}
	}
	
	return id;
	
}

void find_max_joltage(string s)
{
	int id1 = biggest_element_id(s, 0, 'X');
	int id2;
	string joltage="";
	if (id1==s.size()-1) // so the biggest element is last - search for the second biggest element
	{
		id1 = biggest_element_id(s,0,s[id1]);
	}
	id2 = biggest_element_id(s, id1+1, 'X'); // id2 needs to be after id1
	joltage = s[id1];
	joltage = joltage + s[id2];
	cout<<"Joltage: "<<joltage<<", in int: "<<convert_to_int(joltage)<<endl;
	total_joltage += convert_to_int(joltage);
}

int main()
{
	ifstream data;
	string s;
	data.open("input_03.txt");
    int x = 1;
    while (!data.eof())
    {
        data >> s;
        cout<<s<<endl;
        x++;
        if(s.size()>1) find_max_joltage(s);
    }
    
	data.close();
	cout<<total_joltage<<endl;
	
	
	return 0;
}