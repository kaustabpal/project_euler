#include<iostream>
#include<chrono>
int gcf(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	return gcf(b%a, a);
}
int lcm(int a, int b)
{
	return (a*b)/gcf(a,b);
}
int main()
{
	int n = 999;
	auto start_time = std::chrono::high_resolution_clock::now();
	int s_3 = 3*(n/3)*(n/3+1)/2;
	int s_5 = 5*(n/5)*(n/5+1)/2;
	int lcm_= lcm(3,5);
	int s_lcm_ = lcm_*((n/lcm_)*(n/lcm_+1))/2;
	int s = 0;
	s = s_3 + s_5 - s_lcm_;
	auto end_time = std::chrono::high_resolution_clock::now();
	double elapsed_time_ms = std::chrono::duration<double, std::nano>(end_time - start_time).count();
	std::cout<<"Time taken: "<<elapsed_time_ms<<"ns\n";
	std::cout<<s;
	return 0;
}
