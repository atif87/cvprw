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
float angle(int x11,int y11,int x12,int y12,int x21,int y21,int x22,int y22)
{
	float den1=x12-x11;
	float den2=x22-x21;
	if(den1==0)den1=1;
	if(den2==0)den2=1;
	float m1=(y12-y11)*1.0/den1,m2=(y22-y21)*1.0/den2;
	float slope=(m1-m2)/(1+m1*m2);
	slope=slope>0?slope:(-1*slope);
	float ang=atan(slope)*180/M_PI;
	return ang;
}
void triangle(int x1,int y1,int x2,int y2,int x3,int y3,vector<int> *v)
{
	float a=distance(x1,y1,x2,y2);
	float b=distance(x1,y1,x3,y3);
	float c=distance(x3,y3,x2,y2);
	float max=0;
	max=a>b?a:b;
	max=max>c?max:c;
	(*v).push_back(max);
	float ang1,ang2;
	if(max==a)
	{
		ang1=angle(x1,y1,x3,y3,x1,y1,x2,y2);
		ang2=angle(x2,y2,x3,y3,x1,y1,x2,y2);
		if(ang1<ang2){(*v).push_back(ang1);(*v).push_back(ang2);}
		else {(*v).push_back(ang2);(*v).push_back(ang1);}
	}
	if(max==b)
	{
		ang1=angle(x1,y1,x3,y3,x1,y1,x2,y2);
		ang2=angle(x1,y1,x3,y3,x2,y2,x3,y3);
		if(ang1<ang2){(*v).push_back(ang1);(*v).push_back(ang2);}
		else {(*v).push_back(ang2);(*v).push_back(ang1);}
	}
	if(max==c)
	{
		ang1=angle(x2,y2,x3,y3,x1,y1,x2,y2);
		ang2=angle(x2,y2,x3,y3,x1,y1,x3,y3);
		if(ang1<ang2){(*v).push_back(ang1);(*v).push_back(ang2);}
		else {(*v).push_back(ang2);(*v).push_back(ang1);}
	}

	return ;
}
int main()
{
	int count=0;
	int max=0;
	F(user,100)
	{
		F(iter,8)
		{
			
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
			float feature[10][9][9]={0};

			F(i,X.size())
			{
				for(int j=i+1;j<X.size();j++)
				{
					for(int k=j+1;k<X.size();k++)
					{
						vector<int> d;
						triangle(X[i],Y[i],X[j],Y[j],X[k],Y[k],&d);
						feature[d[0]/40][d[1]/10][d[2]/10]+=100000;
						d.clear();
						count++;
					}
				}
			}
			X.clear();
			Y.clear();
			T.clear();
			fstream fw;
			char out[40]="featuretriangle.txt";
			cout<<out<<endl;
			fw.open(out,fstream::out|fstream::app);
			F(i,10)
			{
				F(j,9)
					F(k,9)
						fw<<feature[i][j][k]/count<<" ";
			}
			fw<<endl;
			fp.close();
			fw.close();
		}
	}
}
