#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;
#define F(a,b) for(int a=0;a<b;a++)
float multiply(float *projection,float *feature)
{
	float ans=0;
	float factor=0;
	F(i,1010)
		factor=factor+(projection[i]*projection[i]);
	factor=sqrt(factor);
	F(i,1010)
		ans=ans+projection[i]*feature[i];
	ans=ans/factor;
	return ans;
}
int main()
{
	fstream feat1,feat2,projection;
	projection.open("randomProjection.txt",fstream::in);
	fstream output;
	output.open("dataset1010.txt",fstream::out);
	F(i,1500)
	{
		float proj[1010];
		float feature[1010];
		F(j,1010)
			projection>>proj[j];
		feat1.open("featureangdistance.txt",fstream::in);
		feat2.open("featuretriangle.txt",fstream::in);
		F(k,800)
		{
			F(j,810)
				feat2>>feature[j];
			F(j,200)
				feat1>>feature[j+810];
			float a=multiply(proj,feature);
			output<<a<<" ";
		}
		output<<endl;
		feat1.close();
		feat2.close();
	}
	projection.close();
	output.close();
}
