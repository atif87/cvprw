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
int main(int argc,char *arg[])
{
	float d=500;
	fstream projection,dataset,out;
	projection.open("projection.txt",fstream::in);
	out.open("dataset/datasetSorted.txt",fstream::out);
	float score;
	int index[1500];
	F(j,1500)
		projection>>index[j]>>score;
	float temp[800];
	F(j,1500)
	{
		cout<<j<<" "<<index[j]<<endl;
		dataset.open("dataset1010.txt",fstream::in);
		F(k,index[j]+1)
		{
			F(i,800)
			{
				dataset>>temp[i];
			}
		}
		F(k,800)
			out<<temp[k]<<" ";
		out<<endl;
		dataset.close();
	}
	out.close();
	projection.close();
	return 1;
}
