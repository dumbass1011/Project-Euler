
/*
problem 1:

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

/*

My approach:

sum of all multiples of integer k upto n is
k*(1 + 2 + ... int(n/k))

so now when we do the same for 3 & 5 upto 30
series for 3 :
	3 + 6 + 9 + 12 + 15 + 18 + 21 + 24 + 27 + 30 = 3(1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 )
series for 5 :
	5 + 10 + 15 + 20 + 25 + 30 = 5(1 + 2 + 3 + 4 + 5 + 6)
	
now we see 15 and 30 are repeated
so 15 and 30 are added 2 times if we directly sum these up so we just add sum of all
the multiples of 3 & 5 and subtract sum of all multiples of 15

now we can observe 15 is lcm of 3 & 5 and observing other testcases we can see our observation is true

generalizing it
let the 2 numbers be i & j;
required sum  = Si + Sj - Slcm(i,j)

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int gcd(int a,int b)
{
	if(b == 0)
	{
		return a;
	}
	
	return gcd(b,a%b);
}


int lcm(int a,int b)
{
	//lcm of a and b = a*b/hcf(a,b)
	int x = max(a,b);
	int y = a + b - x;
	return a*b/gcd(x,y);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,n,k,lcmAB;

	cin>>a>>b;
	lcmAB = lcm(a,b);
	cin>>n;
	k = (n-1)/a;
	ll si = a*(k*(k+1)/2);
	k = (n-1)/b;
	ll sj = b*(k*(k+1)/2);
	k = (n-1)/lcmAB;
	
	ll st = lcmAB*(k*(k+1)/2);
	
	cout<<si + sj - st<<endl;
	return 0;
}

