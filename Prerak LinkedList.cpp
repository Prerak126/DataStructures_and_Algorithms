// As i am using Dev-C++5.11 i have to use NULL instead of nullptr

#include<iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList()  
	    {
        this->head= NULL; 
    }
    ~LinkedList()  
    {
         Node* current=head;
         while(current!=0)
        {
            Node* next=current->next;
            delete current;
            current=next;
        }
        head=NULL;
        cout<<"Whole LinkedList deleted successfully"<<'\n';
    }
    
    void Add_Front(int value)
    {
         if(head==NULL)
        {
          head=new Node();
          tail=head;
          head->data=value;
          head->next=NULL;
        }
        else      
        {
         Node* temp=new Node();
         temp->data=value;
         temp->next=head;
         head=temp;
        }

    }
    void Add_End(int value)
    {
        if(head==NULL)
        {
          head=new Node();
          tail=head;
          head->data=value;
          head->next=NULL;
        }
        else      
        {
            tail->next=new Node();
            tail=tail->next;
            tail->data=value;
            tail->next=NULL;
         }
    }

    void Remove_Front()
    {
        if(head==NULL)
        {
            cout<<"Empty list";
        }
        Node* temp=head;
        head=head->next;
        delete(temp);
    }

    void Remove_Back()
    {
        if(head==NULL)
        {
            cout<<"Empty list";
        }
        Node *temp,*p;
        p=head;
        temp=head->next;
        while(temp->next)
        {
            p=temp;
            temp=temp->next;
        }
        p->next=NULL;
        delete(temp);

    }
    void Output()
    {
        Node* temp;
        if(head==NULL)
        {
            return;
        }
        temp=head;
        while(temp!=NULL)
        {
            cout<<" "<<temp->data<<",";
            temp=temp->next;
        }
        cout<<'\n';
    }

};

int main()
{
    LinkedList* HW4b=new LinkedList();
	ifstream f("Hw4a.txt");
	string line;
	while( getline(f,line) )
        {
		string temp;
		if(line != "\0")
		{
			stringstream info(line); 
			info>>temp;
			if(temp == "ADD_FRONT")
            {
				for(int i=0;line[i]!='\0';i++)
                    if((line[i])==':')
                        line[i]=' ';           

                istringstream obj(line);
                string name;
                int start, step, end;

                obj >> name >> start >> step >> end;  

                int asize=((end-start)/step)+1;   
                int a[asize];
                int cnt=0;
                for(int i=start;i<=end;i=i+step)
                    a[cnt++]=i;        
				for(int i = 0;i<asize;i++){
					HW4b->Add_Front(a[i]);         
				}
			}

	
			if(temp == "ADD_BACK")
            {
                
			    for(int i=0;line[i]!='\0';i++)
                    if((line[i])==':')
                        line[i]=' ';

                istringstream obj(line);
                string name;
                int start, step, end;

                obj >> name >> start >> step >> end;

                int asize=((end-start)/step)+1;
                int a[asize];
                int cnt=0;
                for(int i=start;i<=end;i=i+step)
                    a[cnt++]=i;                      

				for(int i = 0;i<asize;i++){
					HW4b->Add_End(a[i]);     

                }
            }
	        if(temp == "REMOVE_FRONT")
            {
               int t;
               info>>t;
               for(int i =0;i<t;i++)
               {
					HW4b->Remove_Front(); 
					               }

            }


            if(temp == "REMOVE_BACK")
            {
               int t;
               info>>t;
               for(int i =0;i<t;i++)
               {
					HW4b->Remove_Back();
               }

            }


			if(temp == "OUTPUT"){
				HW4b->Output(); 
			}


			}
		}

}


