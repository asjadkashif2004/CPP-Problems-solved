	#include<iostream>
	using namespace std;
	struct person{
	string name;
	int age;
	float grade;	
	};
	void display(person n[])
	{
	for(int i = 0 ; i < 2  ; i++)	
	{
		cout<<"---------------"<<endl;
		cout<<"Name of student "<<i + 1<<" : "<<n[i].name<<endl;
		cout<<"---------------"<<endl;
		cout<<"---------------"<<endl;
		cout<<"Age of student "<< i + 1 <<" : "<<n[i].age<<endl;
		cout<<"----------------"<<endl;
		cout<<"-----------------"<<endl;
		cout<<" Grade "<< i + 1 <<" : "<<n[i].grade<<endl;
		cout<<"-----------------"<<endl;
		
		
	}
	}
	int main()
	{
		person students[5];
		for(int i = 0 ;i<5 ;i++)
		{
			cout<<"Enter the name of student "<<i + 1<<" : "; //i+1 is used because students starts form i=0 and student cant be 0 so we used i+1
			cin>>students[i].name;	
			cout<<"Enter the Age of student "<<i + 1<<" : ";
				cin>>students[i].age;
			
			cout<<"Enter the Fee of student "<<i + 1<<" : ";
				cin>>students[i].grade;
		}
		display(students);
	}

