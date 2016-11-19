#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
class GrowArray
{
	private:
		vector<int> arr;
	public:
		GrowArray() 
		{
		}
		~GrowArray() 
		{
			arr.clear();
		}
		void add_front(int start,int step,int end);
		void add_back(int start,int step,int end);
		void output();
		void remove_front(int n);
		void remove_back(int n);
};
void GrowArray::add_front(int start,int step,int end)
{
	for(int i=start;i<=end;i+=step)
	{
		arr.insert(arr.begin(),i);
	}
}
void GrowArray::add_back(int start,int step,int end)
{
	for(int i=start;i<=end;i+=step)
	{
		arr.push_back(i);
	}
}
void GrowArray::output()
{
	cout<<arr[0];
	for(int i=1;i<arr.size();i++)
	{
		cout<<","<<arr[i];
	}
	cout<<"\n";
}
void GrowArray::remove_front(int n)
{
	for(int i=0;i<n;i++)
	{
		arr.erase(arr.begin());
	}
}
void GrowArray::remove_back(int n)
{
	for(int i=0;i<n;i++)
	{
		arr.pop_back();
	}
}
int main()
{
    GrowArray a;
    a.add_front(1,2,10);
    a.add_back(1,3,12);
    a.output();
    a.remove_back(3);
    a.remove_front(2);
    a.output();
    //cout<<a<<'\n';
}
