#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<vector>
#include<math.h>
using namespace std;
#define F(a,b) for(int a=0;a<b;a++)
float distance(int x,int y,int a,int b)
{
	float d=sqrt(pow(x-a,2)+pow(y-b,2));
	return d;
}
int main()
{
	int count=0;
	int max=0;
	F(user,100)
	{
		F(iter,8)
		{
			float feature[10][20]={0};
			char file[30]="cleanedminutia/";
			char temp[10];
			sprintf(temp,"%d",user+1);
			strcat(file,temp);
			strcat(file,"_");
			sprintf(temp,"%d",iter+1);
			strcat(file,temp);
			strcat(file,".xyt");
			ifstream fp;
			fp.open(file,fstream::in);
			vector<int> X,Y,T;
			int t,x,y;
			while(fp.good())
			{
				fp>>x>>y>>t;
				X.push_back(x);
				Y.push_back(y);
				T.push_back(t);
			}
			int count=0;
			
			F(i,X.size())
			{
				for(int j=i+1;j<X.size();j++)
				{
					float d=distance(X[i],Y[i],X[j],Y[j]);
					int dt=(T[i]-T[j]);
					dt=dt>0?dt:-1*dt;
					dt=(dt<90)?dt:(180-dt);
					feature[dt/10][(int)d/20]+=1000;
				}
			}
			fstream fw;
			char out[100]="dataset/featureangdistance.txt";
			fw.open(out,fstream::out| fstream::app);
			cout<<X.size()<<endl;
			for(int j=0;j<9;j++)
			{
				for(int k=0;k<20;k++)
					fw<<feature[j][k]/(X.size()*(X.size()-1))<<" ";
			}
			X.clear();
			Y.clear();
			T.clear();
			fw<<endl;
			fp.close();
			fw.close();
		}
	}
}
