//RSA-sender
// - crypton480
// Originally November 2007

#include<iostream>
#include<math.h>
#include<string>
using namespace std;
int main ()
{
	int x,n,r,z,l, i, j;
	string a1;
	cout<<"enter the string"<<'\n';	//accept message to be coded
	getline (cin, a1, '\n');
	l=a1.size();
	cout<<"enter value of n: ";
	cin>>n;							//accept value of n
	cout<<"Enter value of r: ";
	cin>>r;							//accept value of r
	cout<<"the length of the string entered is "<<l<<'\n';  //length of string to tell the receiver

	for(i=0;i<l;i++)
	{

		x=a1[i];					//convert char into int uing ASCII (Mi)
		//cout<<"x="<<x<<"\n";
		z=1;
		for(j=0;j<r;j++)				//compute (((Mi)^r)mod(n))
		{
			z=x*z;
			z=z%n;
		}
		cout<<z<<" ";					//display code for each character
		cout<<"\n";
	}

	return 0;
}
