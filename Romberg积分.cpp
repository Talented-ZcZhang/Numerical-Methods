//the program is created by zzc(915106840742) on 1.1 ,2018.
//the report has the detail introduction ,Thank.
//////////////////////////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=100;
const double a=0,b=1;
double T[maxn][maxn];
double _2[maxn];
void init()
{
	memset(T,0,sizeof(T));
	_2[0]=1; 
	for(int i=1;i<maxn;i++)
		_2[i]=2*_2[i-1];
}
double F(double x)
{
	if(x==0)return 1;
	return (double)sin(x)/x;
}
double Romberg(double e)
{
	T[0][0]=(double)0.5*(b-a)*(F(a)+F(b));
	//cout<<T[0][0]<<endl;
	int i=1;
	while(1)
	{
		T[i][0]=0.5*T[i-1][1];
		double t=0;
		for(int k=1;k<=_2[i];k+=2)
			t+=(F(k/_2[i]*(b-a)+a));
		T[i][0]+=((b-a)/_2[i]*t);
		for(int j=1;j<=i;j++)
			T[i][j]=(_2[2*j]*T[i][j-1]-T[i-1][j-1])/(_2[2*j]-1);
		if(abs(T[i][i]-T[i-1][i-1])<=e){
			cout<<i<<endl;
		return T[i][i];
	}
		//cout<<i<<"   "<<T[i][i]<<endl;
		i++;
	} 
	return -1;
}
void debug()
{
	for(int i=0;i<=10;i++)
	{
		for(int j=0;j<=i;j++)
		     cout<<setw(10)<<left<<T[i][j];
	    cout<<endl; 
	}
}
int main()
{
	init();
	//double e=0;
	//cout<<"input e: ";
	//cin>>e;
	double e=1;
	for(int i=0;i<10;i++){
		e/=10;
	long long a=clock();
	double ans=Romberg(e);
	long long b=clock(); 
	//debug();
	cout<<setw(10)<<left<<setprecision(8)<<ans<<endl;
	cout<<"time: "<<b-a<<endl;
    }
	return 0;
} 
