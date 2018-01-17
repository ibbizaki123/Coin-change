#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
void print_tables(int m[3], int c[3], int sum)
{
	cout<<"Print Minimum Coin Table:";
	for(int i=1;i<=sum;i++)
	cout<<m[i]<<" ";
	cout<<endl;
	
	cout<<"Print Coin Index Table:";
	for(int i=1;i<=sum;i++)
	cout<<c[i]<<" ";
	cout<<endl;
}
void print_coin_combination(int coins[3], int n, int sum, int c[3])
{
	if (c[sum] == -1)
	{
		cout<<"Not Possible";
		return;
	}
	else
	{
		cout<<"Coins Used:";
		while (sum>0)
		{
			int j = c[sum];
			cout<<coins[j]<<" ";
			sum = sum - coins[j];
		}
	}
}
int min_coin_change(int coins[3], int n, int sum)
{
	int m[sum+1];
	int c[sum+1];
	int int_max;
	m[0]=0;
	for(int i=1;i<=sum;i++)
	{
		m[i]=int_max-1;
		c[i]=-1;
	}
	for(int j=0;j<n;j++)
	{
		for(int i=coins[j];i<=sum;i++)
		{
			if (m[i]> 1+m[i-coins[j]])
			{
				m[i]=1+m[i-coins[j]];
				c[i]=j;
			}
		}
	}
	print_tables(m,c,sum);
	print_coin_combination(coins,n,sum,c);
	return m[sum];
}
int main()
{
	int coins[3]={3,5,7};
	char ch;
	int n = 7;
	int t = 8;
	string order;
	ifstream fin;
    fin.open("text.txt");

    if(!fin)
    {
        cout << "Cannot open file text.txt";
        exit(0);
    }
    while(fin)
    {

        fin.get(ch); 

        getline(fin, order, '(');

        fin >> n;
        fin.get(ch); 
        fin >> t;
        fin.get(ch); 
        fin.get(); 

    
    }

    fin.close();
    
	
	ofstream fout;
    fout.open("newtext.txt");
    fout<<"\n Minimum No. Of Coins Used:"<<min_coin_change(coins,n,t)<<endl;
    if(!fout)
    {
        cout << "Cannot open output file newtext.txt";
        exit(0);
    }
	return 0; 
}
