#include<iostream>
#include<vector>
using namespace std;

long long power(int n,int m)
{
    if(m==0) return 1;
    
    long long x=power(n,m/2);
    if(m%2==0) 
               return (x*x);
    else
               return ((x*x)*n);
}

long long cal_value (const string &str ,int count) {

//	cout << "cal_value\n";
	
	vector<int> value;
	value.resize(36,-1);
	long long ans = 0;
	//value[str[0]-'0'+10] = 1;
	
	if ( str[0] >= '0' && str[0] <= '9' ) 	 value[str[0]-'0'] = 1; 
	else 									 value[str[0]-'a'+10] = 1;
	
	ans = 1;
	
	int v = 0;
	bool flag  = false;
	if(count==1)
	count = 2;
	for (int j = 1 ; j < str.size() ; j ++) {
	
			char i = str[j];
			flag = false;
	
			if ( i >= '0' && i <= '9' && value[i-'0'] == -1) 				{	value[i-'0'] = v ; flag = true; }
			else if ( i >= 'a' && i <= 'z' && value[i-'a'+10] == -1)		{	value[i-'a'+10] = v ; flag = true; }
			
			if ( i >= '0' && i <= '9' ) 				ans = (ans*count) + value[i-'0'];
			else										ans = (ans*count) + value[i-'a'+10];
			
			if(flag) {
				v++;
				if(v==1)	v ++;
			}
//				cout << ans << " ";
	}  
	return ans;
}

int main() {

	int t;
	cin >> t; 
	while(t--) {
		string str;
		cin >> str;
//		cout << str;
		vector<bool> exist(36);
		vector<int> value(36);
		
		int count = 0;
//		cout << "calculating count\n";

		for( int j = 0 ; j < str.size() ; j ++) {
			char i = str[j] ;
//			cout << i << " ";
//			cout << "in func";
			if ( i >= '0' && i <= '9' && !exist[i-'0']) {
				count++;
//				cout << "if";
				exist[i-'0'] = true;
			}
			
			else if (i >= 'a' && i <= 'z' && !exist[i-'a'+10]){
				count ++;
				exist[i-'a'+10] = true;
			}
				
		}
//		cout  << count << endl;
//		cout << "calling cal_value";
		cout << cal_value(str,count) << endl;
	}
}
