//RSA-reciever.cpp
// - crypton480
// Originally done November 2007

#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ifstream text("message.txt");
	int i, j, n, a[100], b[25], p, q, p1, q1, g, l, n1, m, x, y;
	float lim;
	string s1;
	n=99;
	for(i=1;i<=n;i++)
		a[i]=1;	
	for(j=0;j<25;j++)
		b[j]=0;
	lim=sqrt(n)+1;
	for(i=2;i<=lim;i++)
	{
		if(a[i]!=0)
		{
			for(j=i;j<=n;j++)
			{
				if((j%i==0)&&(j!=i))
					a[j]=0;
			}
		}
	}					//generating primes by sieve method
	j=0;
	for(i=2; i<=n; i++)
		if(a[i]==1)
		{
			b[j]=i;			//storing primes in b[i]
			j++;
		}
	
	srand((unsigned int) time(0));
	x=(rand()%10);				//randomly pick one of the last 10 primes
	i=24-x;
	p=b[i];
	do
	{
		y=(rand()%10);
	}
	while((y==x)||(y==0));			//making sure that the two primes are different
	i=24-y;
	q=b[i];
	int r=b[i+1];			//pick prime r co-prime to m
	n1=p*q;					//product of 2 primes
	cout<<"n = "<<n1<<"\n";
	p1=p-1;
	q1=q-1;
	m=p1*q1;
	while(q1!=0)				//gcd of (p-1) & (q-1) using Euclid's algorithm
	{
		g=q1;
		x=p1;
		p1=q1;
		q1=x%q1;
	}
	m=m/g;					//lcm(p,q)=(p*q)/gcd(p,q)
	int s=1;
	while((r*s)%m!=1)		//computing multiplicative inverse of r in U(m)
	{
		s++;
	}
	cout<<"r = "<<r<<"\n";
	cout<<"Press Enter when message is ready\n";
	cin.ignore();
	text>>l; 				//accept message length
	for(int i=0;i<l;i++)
	{
		text>>y;
		x=1;
		for(int j=0;j<s;j++)	//compute (((Ri)^s)mod(n))
		{
			x=x*y;
			x=x%n1;
		}
		s1[i]=x;			//convert and store int ASCII values to string characters
	}
	cout<<"Decoded message is:\n";
	for(i=0;i<l;i++)
		cout<<s1[i];			//display decoded message
	cout<<"\n\n";
	return 0;
}
