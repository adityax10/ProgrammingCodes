#include<bits/stdc++.h>
using namespace std;

namespace aditya {
class complex
{
	private:
	int r,i;
	public:
		complex()
		{
			r=i=0;
		}
		complex(int re,int im)
		{
			real(re);
			imag(im);
		}
		void real(int re)
		{
			r = re;
		}
		void imag(int im)
		{
			i = im;
		}
		void show()
		{
			cout<<r<<" + i"<<i<<endl;
		}
		//add
		complex& operator+=(complex b)
		{
			this->r += b.r;
			this->i += b.i;
			return *this;
 		}
 		//add 2
 		complex operator+(complex b)
 		{
 			complex c = *this;
 			c += b;
 			return c;
 		}
 		
 		//substract
 		complex& operator-=(complex b)
 		{
 			this->r -= b.r;
			this->i -= b.i;
			return *this;
 		}
 		// multiply
 		complex& operator*=(complex b)
 		{
 			this->r = r * b.r - i * b.i;
 			this->i = i * b.r + r * b.i;
 			return *this;
 		}
};
}

int main()
{
	aditya::complex a(2,3),b(4,5);
	a.show();
	b.show();
	//add
	a+=b;
	a.show();
	b.show();
	aditya::complex c = a+b;
	c.show();
	a.show();
	b.show();
//	//sub
//	a-=b;
//	a.show();
//	b.show();
//	//mul
//	a*=b;
//	a.show();
//	b.show();
	return 0;
}


