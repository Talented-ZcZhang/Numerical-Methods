//the program is created by zzc(915106840742) on 12.31 ,2017.
//the report has the detail introduction ,Thank.
//////////////////////////////////////////////////////////////////
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib> 
#include<cstring>
#include<iomanip> 
using namespace std;
const int maxn=100;
const int x0=-1,x1=1;
int n,N[maxn];
double h,x,t,fx[maxn][maxn],c[maxn];
void init()
{
	N[0]=1;
	for(int i=1;i<maxn;i++)
		N[i]=N[i-1]*i;
	memset(c,0,sizeof(c));
	memset(fx,0,sizeof(fx));
}
double F(double x)
{
	return (double)1/(1+25*x*x); 
}
void CalFx()
{
	for(int i=0;i<=n;i++){
		fx[i][0]=F(x0+i*h);
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=(n-i);j++)
			fx[j][i]=fx[j+1][i-1]-fx[j][i-1];
}
void CalCoefficient()
{
	for(int i=0;i<=n;i++)
		c[i]=fx[0][i]/N[i];
}
double Nn(double x)
{
	t=(x-x0)/h;
	double ans=0,temp=1;
	for(int i=0;i<=n;i++)
	{
		ans+=(c[i]*temp);
		temp=temp*(t-i); 
	}
	return ans;
}
int main()
{
	cout<<"input n: ";
	cin>>n;
	h=(double)2/n;
	init();
	cout<<"init finish\n";
	CalFx();	
	cout<<"CalFx finish\n";		
	CalCoefficient();
	cout<<"CalCoefficient finish\n";
	for(int i=0;i<=n;i++)
	     cout<<setw(10)<<c[i]<<" ";
	cout<<endl;
	cout<<"Input x: ";
	cin>>x;
	double ans=Nn(x);
	cout<<"ans:  "<<ans<<endl;
	return 0; 
}
