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
		GrowArray() { }
		void AddFront(int start,int step,int end);
		void AddBack(int start,int step,int end);
		void Output();
		void RemoveFront(int n);
		void RemoveBack(int n);
		~GrowArray() 
		{
			arr.clear();
		}
};
void GrowArray::AddFront(int start,int step,int end)
{
	for(int i=start;i<=end;i+=step)
	{
		arr.insert(arr.begin(),i);
	}
}
void GrowArray::AddBack(int start,int step,int end)
{
	for(int i=start;i<=end;i+=step)
	{
		arr.push_back(i);
	}
}
void GrowArray::Output()
{
	cout<<arr[0];
	for(int i=1;i<arr.size();i++)
	{
		cout<<","<<arr[i];
	}
	cout<<"\n";
}
void GrowArray::RemoveFront(int n)
{
	for(int i=0;i<n;i++)
	{
		arr.erase(arr.begin());
	}
}
void GrowArray::RemoveBack(int n)
{
	for(int i=0;i<n;i++)
	{
		arr.pop_back();
	}
}
int main()
{
    string check,n;
    int s=0,c=0,start,step,end;
    GrowArray HW4a;
    ifstream inFile;
  	inFile.open("HW4a.txt");
  	if (inFile.fail())
  	{
    	cout << "file HW4a.txt can not be able to open for reading" << endl;
      	exit(1);
  	}
    while(inFile>>check)
    {
    	if(check.compare("OUTPUT")==0)
    	{
    		n="\0";
    	}
    	else
    	{
    		inFile>>n;
    	}
    	for(int i=0;n[i]!='\0';i++)
    	{
    		if(n[i]!=':')
    		{
    			s=(s*10)+(n[i]-48);
    		}
    		else
    		{
    			c++;
    			if((c==1 && check.compare("ADD_FRONT")==0)||(c==1 && check.compare("ADD_BACK")==0))
    			{
    				start=s;
    				s=0;
    			}
    			else if((c==2 && check.compare("ADD_FRONT")==0)||(c==2 && check.compare("ADD_BACK")==0))
    			{
    				step=s;
    				s=0;
    			}
    			else
    			{
    				start=0;
    				step=0;
    			}
    		}
    	}
    	if(check.compare("ADD_FRONT")==0)
		{
			end=s;
    		HW4a.AddFront(start,step,end);
    	}
    	else if(check.compare("ADD_BACK")==0)
    	{
    		end=s;
    		HW4a.AddBack(start,step,end);
    	}
		else if(check.compare("OUTPUT")==0)
    	{
    		HW4a.Output();
    	}
    	
    	else if(check.compare("REMOVE_BACK")==0)
    	{
    		end=s;
    		HW4a.RemoveBack(end);
    	}
		else if(check.compare("REMOVE_FRONT")==0)
    	{
    		end=s;
    		HW4a.RemoveFront(end);
    	}
    	
    	s=0;
    	c=0;
    }
}
