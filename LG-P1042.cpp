#include<bits/stdc++.h>
using namespace std;
int w,l;
char a[100000];
int bz_11[1000000],bz_21[1000000];
int main()
{
	int i=1,j,k;
	while(cin>>a[i]&&a[i]!='E')
	{
		i++;
	}
	a[i+1]='\0';
	for(i=1;a[i]!='\0';i++)
	{
		if(a[i]=='W')
			w++;
		if(a[i]=='L')
			l++;
		if(a[i]=='E')
		{
			cout<<w<<":"<<l<<endl;
			break;
		}
		if((w>=11||l>=11)&&(w-l>=2||l-w>=2))
		{
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
	}	
	w=l=0;
	cout<<endl;
	for(i=1;a[i]!='\0';i++)
	{
		if(a[i]=='W')
			w++;
		if(a[i]=='L')
			l++;
		if(a[i]=='E')
		{
			cout<<w<<":"<<l;
			break;
		}
		if((w>=21||l>=21)&&(w-l>=2||l-w>=2))
		{
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
	}
	return 0;
}
