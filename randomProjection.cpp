#include<iostream>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h>
using namespace std;
int main()
{
	float f;
	int i=0;
	srand(time(NULL));
	for(int j=0;j<1500;j++)
	{
		for(i=0;i<1010;i++)
		{
			float num =  ((int)(rand())%100)*1.0/50-1 ;
			cout<<num<<" ";
		}
		cout<<endl;
	}
}
