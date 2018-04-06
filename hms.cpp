#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//BASE CLASS
class supervisor
{
	public: char name[20];
			char add[20];
			char tellno[20];
			char code[20];
			supervisor(){}
			supervisor(char *n,char *d,char *a,char *t)
			{
				strcpy(name,n);
				strcpy(code,d);
				strcpy(add,a);
				strcpy(tellno,t);
			}
			void get_supr();
			void display();
};
void supervisor::get_supr()
{
	cout<<"Enter the Code:"<<endl;
	cin>>code;
	cout<<"Enter Name:"<<endl;
	cin>>name;
	cout<<"Enter Address:"<<endl;
	cin>>add;
	cout<<"Enter Tellno:"<<endl;
	cin>>tellno;
	
}
void supervisor::display()
{
	cout<<"code:"<<code<<"\n"<<"name:"<<name<<"\n"<<"address:"<<add<<"\n"<<"tellno:"<<tellno<<endl;
	
}
//INHERITANCE
class staff :public supervisor
{
				
	public: char work[20];
			char quali[20];
			staff(){}
			staff(char *w,char *q)
			{
				strcpy(work,w);
				strcpy(quali,q);
					
			}
			friend istream &operator>>(istream&,staff&);
			friend ostream &operator<<(ostream&,staff);
};
istream &operator>>(istream &stream,staff &p)
{
	p.get_supr();
	cout<<"Enter working field"<<endl;
	stream>>p.work;
	cout<<"Enter qualification"<<endl;
	stream>>p.quali;
	return stream;
}
ostream &operator<<(ostream&stream,staff p)
{	
	stream<<endl;
	stream<<"Staff code is:"<<p.code<<"\n"<<"Name of the staff:"<<p.name<<"\n"<<"Address of the staff:"<<p.add<<"\n"<<"Telephone no:"<<p.tellno<<"\n"<<"Working field of staff:"<<p.work<<"\n"<<"Qualification:"<<p.quali<<endl;
	stream<<endl;
	return stream;
}	

//INHERITANCE
class student:public supervisor
{
	public: char sem[20];
			char roomno[20];
			char hostel[20];
			float bill;
			student(){}
			student(char *s,char *h,char *r)
			{
				strcpy(sem,s);
				strcpy(hostel,h);
				strcpy(roomno,r);
				
			}
			friend istream &operator>>(istream&,student&);
			friend ostream &operator<<(ostream&,student);
			float messbill(char);
};
float student::messbill(char code)
{
	int *prsnt;
	float *per,*paid;
	
	static float bal;
	prsnt=new int;
	per=new float;
	paid=new float;
	if(code==0)
	{
		cout<<"\n Messbill calculation not possible\n";
	}
	else
	{
		
		cout<<"\n Messbill Calculation:\n";
		cout<<"\n Enter adm. no of student: \n";
		cin>>code;
		cout<<"\n Enter the no of days present:";
		cin>>*prsnt;
		cout<<"\n Enter per day cost:";
		cin>>*per;
	}
	if(code!=0)
	{	
		cout<<"Balance remaining:\n";
		bal=((*prsnt)*(*per))-(*paid);
		cout<<bal<<endl;
		cout<<"\nEnter amount paid\n";
		cin>>*paid;
		bal=((*prsnt)*(*per))-(*paid);
	}
	delete per;
	delete prsnt;
	delete paid;
	return (bal);
}

istream &operator>>(istream &stream,student &p)
{
	p.get_supr();
	cout<<"Enter semister of the student:"<<endl;
	stream>>p.sem;
	cout<<"Enter hostel name:"<<endl;
	stream>>p.hostel;
	cout<<"Enter room no of student:"<<endl;
	stream>>p.roomno;
	return stream;
}
ostream &operator<<(ostream &stream,student p)
{	
	stream<<endl;
	stream<<"Student code is:  "<<p.code<<"\n"<<"Name of the student:  "<<p.name<<"\n"<<"Address of the student:  "<<p.add<<"\n"<<"Telephone no:  "<<p.tellno<<"\n"<<"Semister of student:  "<<p.sem<<"\n"<<"Hostel alloted: "<<p.hostel<<"\n"<<"room no of student:  "<<p.roomno<<endl;	
	char code;
	//stream<<"\nMessbill balance remaining:"<<p.messbill(code)<<endl;
	stream<<endl;
	return stream;
}
// MAIN()
int main()
{
	int i;
	supervisor S;
	student o[20];
	staff s[20];
	float bill;
	int choice;
	
	ofstream out("staff",ios::out|ios::app);
	ifstream in("staff");
	if(!in||!out)
	{
		cout<<"file not found\n";
		return(0);
	}
	
	ofstream outst("Student",ios::out|ios::app);							
	ifstream inst("Student");
	if(!inst||!outst)
	{
		cout<<"file not found\n";
		return(0);
	}
	
	start:
	cout<<"\n";
	cout<<"\n\n!!!*#* PROJECT ON HOSTEL MANAGEMENT*#*!!!\n\n";
	cout<<"\n";
	cout<<"\n           HOSTEL DETAILS           \n";
	cout<<"\n______________________________________________\n";
	cout<<"\n";
	cout<<"choose category from the below menu\n";
	cout<<"\n";
	cout<<"1.SUPERVISOR\n";
	cout<<"2.Exit\n";
	cout<<"\n";
	for(;;)
	{
	cout<<"Enter your choice\n";
	cin>>choice;
	switch(choice)	
	{	
	case 1:cout<<"\n";
		cout<<"1.WORKING STAFF\n";
		cout<<"2.STUDENT REPORT\n";
		cout<<"3.EXIT\n";
		cout<<"\n";
		for(;;)
		{
			cout<<"Enter your choice\n";
			cin>>choice;
			switch(choice)
			{
				case 1: for(;;)
						{
							cout<<"\nSelect your choice from the below sub-menu\n";
							cout<<"\n";
							cout<<"1.ENTER THE STAFF RECORD\n";
							cout<<"2.DISPLAY STAFF DATA\n";
							cout<<"3.SKIP TO MENU\n";
							cout<<"Your option?:\n";
							cin>>choice;
							switch(choice)
							{
								case 1: cout<<"ENTER NUMBER OF STAFF\n";
										int n;	
										cin>>n;
										for(i=0;i<n;i++)
										{
											in.read((char *)&s,sizeof(class staff));
											cin>>s[i];
											out<<s[i];
											in.close();
										}
										break;
								case 2:	out.write((char *)&s,sizeof(class staff));
			 							out.close();
			 							char c;
			 							in.seekg(0,ios::beg);
										while(in.get(c))
										cout<<c;
										in.clear();
										break;
								case 3: goto start; 
							}
						}
	 		
		case 2: cout<<"\nSelect your choice from the below sub-menu\n";
				cout<<"\n";
				for(;;)
				{
							
					cout<<"\n";
					cout<<"1.ENTER THE STUDENT Details\n";
					cout<<"2.DISPLAY STUDENT DETAILS\n";
					cout<<"3.MESSBILL\n";
					cout<<"4.SKIP TO MENU\n";
					cout<<"Enter Your Choice?:\n";
					cin>>choice;
					
		
					
					switch(choice)
					{
						case 1: cout<<"ENTER TOTAL NUMBER OF STUDENTS\n";
								int n;
								cin>>n;
								for(i=0;i<n;i++)
								{
									inst.read((char *)&o,sizeof(class student));
									inst.close();
									cin>>o[i];
									outst<<o[i];
								}	
								 break;
			 			case 2:	outst.write((char *)&o,sizeof(class student));
			 					outst.close();
			 					char c;
			 					inst.seekg(0,ios::beg);
								while(inst.get(c))
								cout<<c;
								inst.clear();
								break;		
						case 3:	char code;
								cout<<"\n Still Balance remaining:"<<o[i].messbill(code)<<endl;
								break;
						case 4: goto start;
					}
				}
				default: in.close();
						out.close();
						break;
			}
								
				case 5: goto end;
		}
	}
				end: return(0);
}
}


