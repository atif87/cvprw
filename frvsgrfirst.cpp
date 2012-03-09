#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <iostream>
#include <fstream>
#include<math.h>
#define trsize 600
#define tesize 200
#define F(a,b) for(int a=0;a<b;a++)
using namespace std;
typedef struct{
	int index;
	float score;
}data;
int compare(void const *a,void const *b)
{
	data *x=(data*)a;
	data *y=(data*)b;
	return ((x->score)>(y->score))?-1:1;
}
char win[tesize][trsize];
double fr,gr;
float score[tesize][trsize];
void myfunction(float *traindata,float *testdata,int index,float windowsize)
{
	int j=0,ret[trsize]={-1};
	float len=0;
	F(i,trsize)
	{
   	   len=(testdata[index]-traindata[i]>0)?(testdata[index]-traindata[i]):(traindata[i]-testdata[index]);
	   if (len<windowsize)
		   ret[j++]=i;
	}
//	F(i,j)
	int temp[trsize]={1};
	F(i,trsize)
		temp[i]=0;
	F(i,j)
		temp[ret[i]]=1;
	F(i,trsize)
                win[index][i]=temp[i] * win[index][i];
        int f=0,g=0,trainclass,testclass;
        F(i,trsize)
                if(win[index][i]==0)
                {
			trainclass=index/2;
			testclass=i/6;
			if(trainclass==testclass)
				f++;
			else g++;
                }
	float z1=f,z2=g;
        fr += f;
        gr += g;
	//cout<<fr<<" "<<gr<<endl;
        return;

}

int main(int argc,char *arg[])
{
	float d=500;
	F(i,200)
		F(j,600)
			win[i][j]=1;
	float temp,min=100,max=-100;
	fstream dataset;
	float traindata[trsize],testdata[tesize];
	dataset.open("dataset/dataset1010.txt",fstream::in);
	fstream sc;
	sc.open("dataset/score.txt",fstream::in);
	F(i,tesize)
		F(j,trsize)
			sc>>score[i][j];
	data dt[1500];
	F(j,1500)
	{
		F(i,200)
			F(j,600)
				win[i][j]=1;
		min=100000;max=-100000;
		int TS=0,TR=0;
		F(i,100)
		{
			float a;
			F(train,6){dataset>>a;if(max<a)max=a;if(min>a)min=a;traindata[train];traindata[TR++]=a;}
			F(test,2)dataset>>testdata[TS++];
		}
		fr=1,gr=1;

		F(i,tesize)
			myfunction(traindata,testdata,i,d);
		dt[j].index=j;
		dt[j].score=gr/fr;
	}
	qsort(dt,1500,sizeof(data),compare);
	F(j,1500)
		cout<<dt[j].index<<" "<<dt[j].score<<endl;
	return 1;
}
