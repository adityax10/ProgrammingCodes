#include<bits/stdc++.h>
using namespace std;

class training_set
{
	public :
	double y;
	vector<double> x; // [ x1 x2 x3 x4 ... xn ]
	training_set(vector<double> &x,double y)
	{
		this->x = x;
		this->y = y;
	}
};

double cal_derivative(double o[],int wrt,int features,int m,vector<training_set> &ts)
{
	double k = 0,ki;
	for(int i=0;i<m;i++)
	{
		ki=0;
		// ho * x[i] 
		for(int j=0;j<=features;j++)
		{
			ki += o[j]*ts[i].x[j]; //ho * x[i] - y[i] for i=0 ... n
		}
		//ho * x[i] - y[i] 
		ki -= ts[i].y;
		//( ho * x[i] - y[i] ) * x[i]'s wrth feature
		ki *= ts[i].x[wrt];
		k += ki;
	}
	return k;
}

double cal_J(double o[],int features,vector<training_set> &ts)
{
	int m = ts.size();
	double k = 0,ki;
	for(int i=0;i<m;i++)
	{
		ki=0;
		for(int j=0;j<=features;j++)
		{
			ki += o[j]*ts[i].x[j]; //ho * x[i] - y[i] for i=0...n
		}
		ki -= ts[i].y;
		ki *= ki;
		k += ki;
	}
	return k/(2*m);
}

//BY GRADIENT DESCENT METHOD

//FINDING H(x)
// to calculate this...
// we need to find o1 and o0	
double* calculate_hypothesis_function(vector<training_set> &ts,int features)
{
	double o[features+1];
	double temp[features+1];
	double a = 0.0003;
	double J_present=INT_MAX,J_prev=INT_MAX; // J is the Squared Error Function
	int m = ts.size();
	cout<<" m "<<m<<endl;
	for(int i=0;i<=features;i++)
	temp[i]= 0;
	
	while(J_prev >= J_present)
	{
		J_prev = J_present;
		
		for(int j=0;j<=features;j++)
		o[j] = temp[j];
		
		for (int j=0;j<=features;j++)
		temp[j] = o[j] - a * cal_derivative(o,j,features,m,ts) / m ;
		
		J_present = cal_J(o,features,ts);
	}
	
	double *ans = new double[features+1];
	
	for(int i=0;i<=features;i++)
	{
		ans[i] = o[i];
	}
	
	return ans;
} 

double cal_h(double o[],double x[],int features)
{
	double ans = 0;
	for(int i=0;i<=features;i++)
	{
		ans+=o[i] * x[i];
	}
	return ans;
}

int main()
{
	freopen("training_set_multiple.txt","r",stdin);
	vector<training_set> ts;	
	// fluff the traing set;
	int features;
	cin>>features;
	cout<<" Features  "<<features<<endl;
	double x,y;
	while(cin>>x)
	{
		cout<<"Read\n";
		vector<double> ts_i;
		int f = features;
		f--;
		ts_i.push_back(1); //x[0] => 1
		ts_i.push_back(x); 
		while((f)--) 
		{
			cin>>x;
			ts_i.push_back(x);
		}
		cin>>y;
		ts.push_back( * (new training_set( ts_i , y ) ));
	}
	
	// NOW SINCE WE HAVE THE TRAINING SET READY... START TO MAKE THE HYPOTHESIS FUNCTION
	double *o = calculate_hypothesis_function(ts,features);
	
	// now test
	double x_sample[]={1,60};
	cout<<cal_h(o,x_sample,features);
	
	
	
	return 0;
}


