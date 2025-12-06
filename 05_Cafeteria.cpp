#include<iostream>
#include<fstream>
using namespace std;

bool is_fresh[100]; // gonna kill the poor memory

void all_false()
{
    for (int i=0; i<100; i++)
    {
        is_fresh[i] = false;
    }
}

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
void fill_array(string s)
{
    int x = 0;
    int y = 0;
    string s1 = "";
    cout<<"Converting "<<s<<" to x and y ints "<<endl;
    for (int i=0; i<s.size(); i++)
    {

        if(s[i] == '-')
        {
            cout<<"converting "<<s1<<" to int"<<endl;
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

    cout<<x<<", "<<y<<endl;

}

void check_freshness(string s)
{
    cout<<"Is there anybody out there?"<<endl;
}

int main()
{
    all_false();
    // No cout for norton this time - I'm on a very lovely old laptop with ubuntu for a while:))
    ifstream data;
    data.open("input_05");
    string s;
    bool first_input = true;
    while(!data.eof())
    {
        getline(data,s);
        if(first_input)
        {
            fill_array(s);
        }
        else
        {
            check_freshness(s);
        }
        if(s.size()==0)
        {
            first_input = false;
            cout<<"Breaking point!"<<endl;
            break;
        }
    }
    data.close();
    //cout<<"hello world2"<<endl;
    return 0;
}