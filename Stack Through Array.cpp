#include<iostream>

using namespace std;

class Stack {
	private:
		int StackPointer;
		int StackArray[10];		
	public:
		void InitializeStack () {
			StackPointer = 0;
			StackArray[0]= 0;
		}
		void Insert (int Value) {
			if (StackPointer==10 )
			{
				cout<<"Stack is full, can't insert any value\n";
			}
			else {
				StackArray[StackPointer]=(Value);
				StackPointer++;
			}
		}
		int Remove () {
			if (StackPointer == 0) {
				cout<<"Stack is Empty\n";
			}
			else
			{
				StackPointer--;
				for (int i=StackPointer-1;i>=0;i--)
				cout<<StackArray[i]<<"\n";
			}
			
		}

};

int main() {
	Stack Prerak;
	Prerak.InitializeStack();
	Prerak.Insert(5);
	Prerak.Insert(10);
	Prerak.Insert(100);
	Prerak.Insert(9586);
	Prerak.Insert(3);
	Prerak.Insert(31);
	cout<<"Now we are going to remove the values\n";
	cout<<Prerak.Remove()<<"\n\n\n";
	cout<<Prerak.Remove()<<"\n\n\n";
	cout<<Prerak.Remove()<<"\n\n\n";
	
}
