#include <iostream>
using namespace std;
class Animal
{
private:

	int weight;
	int height;
public:
	Animal()
	{
		cout << "Animal constract:" << endl;
	}
	void eat()
	{
		cout << "animal eat:" << endl;
	}
	virtual void breathe()
	{
		cout << "animal breathe:" << endl;
	}
	void sleep()
	{
		cout << "animal sleep:" << endl;
	}
	~Animal()
	{
		cout << "Animal deconstract:" << endl;
	}
};
class Fish : public Animal
{
public:
	Fish()
	{
		cout << "Fish constract:" << endl;

	}
	void breathe()
	{
		cout << "fish bubble:" << endl;
	}
	~Fish()
	{
		cout << "Fish deconstract:" << endl;
	
	}

};
void main()
{
	Fish fh;
	//Fh.breathe();
	Animal an;
	Fish *pFh;
	system("pause");

#define _CRT_SECURE_NO_WARNINGS
#include"cstring"
#include"iostream"
using namespace std;
class Person{  
private :		
	char m_strName[20];	     
	int m_nAge;		 
	int m_nSex;  
public:  
	Person(){        //构造函数 
    strcpy(m_strName,"XXX");	 
	m_nAge=0;	 
	m_nSex=0;   
	}  
	~Person(){      //析构函数  
		cout<<"Now destroying the instance of Person"<<endl;
	}  
	void Register(char *name,int age ,char sex);  
	char *GetName();  
	int GetAge();  
	char GetSex();  
	void ShowPerson();
};
void  Person::Register(char *name,int age ,char sex){	
	strcpy(m_strName,name);	
	m_nAge=age;    
	m_nSex=(sex == 'm'? 0:1);
}
char *Person::GetName(){	
	return m_strName;
}
int Person:: GetAge() {	 
	return m_nAge; 
}
char Person::GetSex()  {	 
	return(m_nSex == 0 ?'m':'f'); 
}
void  Person::ShowPerson()  {	 
	cout<<GetName()<<'\t'<<GetAge()<<'\t'<<GetSex()<<endl;  
}
void main()  {	 
	Person person1,person2;   //创建对象时自动调用构造函数	  
	cout<<"person1:\t";	  
	person1.ShowPerson();	  
	person1.Register("Zhang3",19,'m');	   
	cout<<"person1:\t";      
	person1.ShowPerson();	   
	cout << "person2:\t";
	system("pause");
}