#include<bits/stdc++.h>
using namespace std;

class training_set
{
	public :
	double x,y;
	training_set(double x,double y)
	{
		this->x = x;
		this->y = y;
	}
};

double cal_derivative0(double o0,double o1,int m,vector<training_set> &ts)
{
	double k = 0;
	for(int i=0;i<m;i++)
	k +=  (o1 * ts[i].x + o0 - ts[i].y) ;
	return k;
}

double cal_derivative1(double o0,double o1,int m,vector<training_set> &ts)
{
	double k=0;
	for(int i=0;i<m;i++)
	k += ((o1 * ts[i].x + o0) - ts[i].y) * ts[i].x ;
	return k;
}

double cal_J(double o0,double o1,int m,vector<training_set> &ts)
{
	double k = 0;
	for(int i=0;i<m;i++)
	k +=  (o1 * ts[i].x + o0 - ts[i].y) * (o1 * ts[i].x + o0 - ts[i].y) ;
	return k/(2*m);
}

//BY GRADIENT DESCENT METHOD

//FINDING H(x)
// to calculate this...
// we need to find o1 and o0	
double* calculate_hypothesis_function(vector<training_set> &ts)
{
	double o0,o1;
	double temp0=0,temp1=0;
	double a = 0.001;
	double J_present=INT_MAX,J_prev=INT_MAX; // J is the Squared Error Function
	int m = ts.size();
	cout<<" m "<<m<<endl;
	
	while(J_prev >= J_present   )
	{
		//cout<<"prev_j"<<J_prev<<endl;
		//cout<<"present_j"<<J_present<<endl;
		o0 = temp0;
		o1 = temp1;
		J_prev = J_present ;
		temp0 = o0 - a * cal_derivative0(o0,o1,m,ts) / m ; 
		temp1 = o1 - a * cal_derivative1(o0,o1,m,ts) / m ;
		//cout<<temp0<<"\n"<<temp1<<endl;
		J_present  = cal_J(temp0,temp1,m,ts);
	//	cout<<"newJ"<<J_present<<endl;
		//cout<<"o0 "<<o0<<" o1 "<<o1<<"  j "<<J_present<<endl;
	}
	cout<<"J"<<J_prev<<endl;
	double *ans = new double[2];
	 ans[0]= o0;
	 ans[1] = o1;
	return ans;
} 

double cal_h(double o0,double o1,double x)
{
	return o1 * x + o0;
}

int main()
{
	freopen("training_set.txt","r",stdin);
	vector<training_set> ts;	
	// fluff the traing set;
	double x,y;
	while(cin>>x>>y)
	{
		cout<<" x "<<x<<" y "<<y<<endl;
		training_set *t = new training_set(x,y);
		ts.push_back(*t);	
	}
	
	// NOW SINCE WE HAVE THE TRAINING SET READY... START TO MAKE THE HYPOTHESIS FUNCTION
	double *ans = calculate_hypothesis_function(ts);
	
	cout<<"o0 "<<ans[0] << " o1 " <<ans[1]<<endl;
	double q = 65;
	cout<<" value for q = "<<q<<"  "<<cal_h(ans[0],ans[1],q);
	
	return 0;
}


