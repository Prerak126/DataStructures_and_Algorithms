#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#define ll long long
using namespace std;
 

ll powmod(ll a, ll b, ll m)
{
    ll x = 0,y = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % m;
        }
        y = (y * 2) % m;
        b /= 2;
    }
    return x % m;
}

ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = powmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int x=0,iteration=100;
	int ll input[10];
	ifstream infile;
	infile.open("hw2.dat");
	
	while(! infile.eof()){
		infile >> input[x];
	//	cout<<input[x] <<endl;
		
	
	if (Miller(input[x], iteration))
        cout<<input[x]<<" true "<<endl;
    else
        cout<<input[x]<<" false "<<endl;
    
}
return 0;
}
