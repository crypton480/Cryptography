//RSA-sender
// - crypton480
// Originally November 2007

#include<iostream>
#include<math.h>
#include<string>
#include <fstream>
using namespace std;
int main ()
{
	ifstream code("code.txt");
	ofstream text("message.txt");
	int x,n,r,z,l, i, j;
	string a1;
	cout<<"Enter the string"<<'\n';		//accept message to be coded
	getline (cin, a1, '\n');
	l=a1.size();
	cout<<"Enter value of n:\n";
	cin>>n;								//accept value of n
	cout<<"Enter value of r:\n";
	cin>>r;								//accept value of r
	text<<l<<'\n';  					//length of string to tell the receiver

	for(i=0;i<l;i++)
	{

		x=a1[i];						//convert char into int uing ASCII (Mi)
		z=1;
		for(j=0;j<r;j++)				//compute (((Mi)^r)mod(n))
		{
			z=x*z;
			z=z%n;
		}
		text<<z<<"\n";					//display code for each character
	}
	cout<<"\nText file is ready\n\n";
	return 0;
}
