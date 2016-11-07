/*
Project Name	  :Student Database Academic Performance System
Developed By   	  :Vidur Sharma
School		  	  :Delhi Public School, R.K.Puram
Last Updated      :10-December-2015
*/


#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<iomanip.h>
#include<math.h>

struct Date
{
	int dd,mm,yy;
};

class Student
{
	long int admno;
	int rollno;
	char name[30];
	char cl [10];
	Date dob;
	char subject[5][40];
	float th[5],pr[3];
	float total, avg, shigh[5] , savg[5];
	char remark [150];
   public:
	Student();
	void Enter();
	void Update();
	void Display ();
	void Show();
	void setHighest(float h[], float a []);
	int getrollno()
		{return rollno;}
	int getadmno()
		{return admno;}
	void setadmno(long no)
		{admno=no;}
	char *getname()
		{return name;}
	float getth1()
		{return th[0];}
	float getth2()
		{return th[1];}
	float getth3()
		{return (th[2]+pr[0]);}
	float getth4()
		{return (th[3]+pr[1]);}
	float getth5()
		{return (th[4]+pr[2]);}
};

void  Student::setHighest(float h[], float a[])
{

	for(int i=0;i<5; i++)
	{
		shigh[i]=h[i];       
		savg[i]=ceil(a[i]); 
	}
}

Student::Student()
{
	admno=0;
	rollno=0;
	strcpy(name, "/0");
	strcpy(cl, "/0");
	dob.dd=0, dob.mm=0, dob.yy=0;
	for (int i=0; i<5; i++)
	{
		th[i]=0;
		if(i>1)
			pr[i-2]=0;
	}
	strcpy(subject[0],"English");
	strcpy(subject[1],"Maths");
	strcpy(subject[2],"Physics");
	strcpy(subject[3],"Chemistry");
	strcpy(subject[4],"Computer Science");

	total=0;
	avg=0;
	strcpy(remark,"/0");
}

void Student::Show()
{
	cout<<"\n"<<setw(10)<<cl<<setw(10)<<admno<<setw(10)<<rollno<<setw(20)<<name<<setw(10)<<ceil(avg);
}

void Student::Enter()
{
	int n;
	cout<<"\n\t Student Details Entry Form";
	cout<<"\n\t -----------------------------------";
	cout<<"\n\t ADM No. \t\t:"<<admno;
	do
		{
			cout<<"\n\t Roll No.\t\t:";
			cin>>rollno;
			if(rollno<1 ||rollno>100)
			{
				n=0;
				cout<<"\t Invalid Roll No. Please Re-Enter";
			}
			else
				n=1;
		}while(n==0);
	cout<<"\t Name\t\t\t:";
	gets(name);
	cout<<"\t Class (XII A..XI C...etc):";
	gets(cl);
	cout<<"\t Date of Birth{DD>MM>YY}:";
	cin>>dob.dd;
	cout<<"\t                         ";
	cin>>dob.mm;
	cout<<"\t                         ";
	cin>>dob.yy;
	total=0;
	for(int i=0; i<5; i++)
		{
			cout<<"\n\t Subject "<<(i+1)<<" "<<subject[i];
			cout<<"\n\t Theory  Marks:";
			cin>>th[i];
			total+=th[i];
			if(i>1)
				{
					cout<<"\t Practical Marks:";
					cin>>pr[i-2];
					total+=pr[i-2];
				}
		}

	avg=total/5;
	cout<<"\t Teacher Remarks:";
	gets(remark);
}

void Student::Update()
{
	cout<<"\n\t Student Details Entry Form";
	cout<<"\n\t -----------------------------------";
	cout<<"\n\t ADM No. \t\t:"<<admno;
	cout<<"\n\t Roll No. \t\t:"<<rollno;
	cout<<"\n\t Name\t \t\t:"<<name;
	cout<<"\n\t Class \t\t\t:"<<cl;
	cout<<"\n\t  Date of Birth. \t";
	cout<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yy<<endl;
	total = 0;
	for(int i=0; i<5; i++)
		{
			cout<<"\t Subject "<<(i+1)<<" "<<subject[i];
			cout<<"\n\t Theory Marks : ";
			cin>>th[i];
			total +=th[i];
				if(i>1)
					{
						cout<<":\t Practical Marks : ";
						cin>>pr[i-2];
						total +=pr[i-2];
					}
		}
	avg=total/5;
	cout<<"\t Teacher Remarks : ";
	gets(remark);
}

void Student::Display()
{
	clrscr();
	gotoxy(30,2);
	cout<<"Delhi Public School";
	gotoxy(30,3);
	cout<<"R.K.Puram, New Delhi";
	gotoxy(35,5);

	cout<<"Result Sheet";
	gotoxy(1,6);
	cout<<"--------------------------------"
		<<"--------------------------------------------";
	gotoxy(1,7);
	cout<<"Name";
	gotoxy(10,7);
	cout<<name;
	gotoxy(50,7);
	cout<<"ADM No.:";
	gotoxy(60,7);
	cout<<admno;
	gotoxy(1,8);
	cout<<"Class:";
	gotoxy(10,8);
	cout<<cl;
	gotoxy(50,8);
	cout<<"Roll No.:";
	gotoxy(60,8);
	cout<<rollno;
	gotoxy(1,9);
	cout<<"DOB:";
	gotoxy(10,9);
	cout<<dob.dd<<" / "<<dob.mm<<" / "<<dob.yy;
	gotoxy(1,10);
	cout<<"----------------------------------"
		<<"-----------------------------------------";
	gotoxy(1,11);
	cout<<"Subject";
	gotoxy(25,11);
	cout<<"Theory";
	gotoxy(35,11);
	cout<<"Practical";
	gotoxy(48,11);
	cout<<"Total";
	gotoxy(60,11);
	cout<<"Section";
	gotoxy(70,11);
	cout<<"Section";
	gotoxy(48,12);
	cout<<"M.M.100";
	gotoxy(60,12);
	cout<<"Highest";
	gotoxy(70,12);
	cout<<"Average";
	gotoxy(1,13);
	cout<<"----------------------------------"
		<<"-----------------------------------------";
	for(int i=0; i<5; i++)
	{
		gotoxy(1,14+i);
		cout<<subject[i];
		gotoxy(25,14+i);
	if(th[i] == -1)
		cout<<"ABS";
	else
		cout<<th[i];
	if(i>1)
	{
			gotoxy(35,14+i);
			if(pr[i-2] == -1)
				cout<<"ABS";
			else
				cout<<pr[i-2];
			gotoxy(48,14+i);
			if(th[i] ==-1 || pr[i-2] ==-1)
				cout<<"ABS";
			else
				cout<<th[i]+pr[i-2];
		}
		else
		{
			gotoxy(48,14+i);
			if(th[i]== -1)
				cout<<"ABS";
			else
				cout<<th[i];
		}
		gotoxy(60,14+i);
		cout<<shigh[i];
		gotoxy(70,14+i);
				cout<<savg[i];
		}
		gotoxy(1,19);
		cout<<"----------------------------------"
			<<"-----------------------------------------";
		gotoxy(48,20);
		cout<<"Total: "<<total;
		gotoxy(48,21);
		cout<<"Agg:  "<<ceil(avg);
		gotoxy(1,22);
		cout<<"----------------------------------"
			<<"-----------------------------------------";
		gotoxy(1,23);
		cout<<"Teacher Remarks : "<<remark;
		gotoxy(1,24);
		cout<<"----------------------------------"
			<<"-----------------------------------------";
}

int getnew_admno()
{
		fstream F("Student.dat",ios::binary | ios::in);
		Student s1;
		int admno=0;
		// File pointer move at end of file
		F.seekg(0,ios::end);
		//CHECK IF ANY RECORD EXISTS OR NOT
	if(F.tellg()>0)
{
		//Move File pointer to the beginning of last record
		F.seekg(F.tellg() - sizeof(s1));
		// Read last record
		F.read((char*)&s1,sizeof(s1));
		//set new adm no = last adm no + 1
		admno = s1.getadmno() + 1;
}
	else
{
		admno = 1001;
}
	F.close();
return admno;
}

void stud_add()
{
	fstream F;
	Student snew;
	long ano = getnew_admno();
	snew.setadmno(ano);
	F.open("Student.dat",ios::binary | ios::app);
	snew.Enter();
	F.write((char*)&snew,sizeof(snew));
	F.close();
}

void stud_search()
{
	int ch, x, found=0;
	char name[30];
	Student s1;
	do
	{
		clrscr();
		cout<<"Please select a choice:";
		cout<<"\n 1.search by Roll no"<<"\n 2.search by name";
		cout<<"\n 3.search by ADMNO"<<"\n Enter choice[1-3] :";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n Enter Roll no to be searched:";
					cin>>x;
					break;
			case 2: cout<<"\n please enter name to tbe searched:";
					gets(name);
					break;
			case 3: cout<<"\n Enter ADMNO to be searched:";
					cin>>x;
					break;
			default:cout<<"\n invalid choice! ";
		}

		}while(ch<1 || ch>3);

		ifstream F;
		F.open("Student.dat",ios::in | ios::binary);

		while(F.read((char*)&s1, sizeof(s1)))
		{
			if(ch==1)
			{
				if(x==s1.getrollno())
				{
					found = 1;
					s1.Display();
					break;
				}
			}
			else if(ch==2)
			{
				if  (!strcmpi(name, s1.getname()))
				{
					s1.Display();
					found++;
				}
			}
			else
			{
				if (x==s1.getadmno())
			{
				found=1;
				s1.Display();
				break;
			}
		}
	}
	F.close();
	if(found==0)
		cout<<"\n Record does not exist !!!! ";
}

void stud_modify()
{
	int found=0;
	long x;
	char ch;
	cout<<"Please enter ADMNO to be modified:";
	cin>>x;
	Student s1;
	fstream F;
	F.open("Student.dat" , ios::in | ios::out | ios::binary);
	while (F.read((char*)&s1, sizeof(s1)&&(!found)))
	{
		if(s1.getadmno()==x)
			{
				s1.Update();
				F.seekp(F.tellg()-sizeof(s1));
				F.write((char*)&s1, sizeof(s1));
				found++;
			}
		}
		F.close();
		if(found)
		{
		cout<<"\n Record updated successfully!";
		cout<<"\n Do you wish to generate the new report card?(y/n)";
		cin>>ch;
		if (tolower(ch)=='y')
			s1.Display();
		}
		else
		cout<<"\n Record does not exist!";
}

void stud_delete()
{
	Student s1;
	fstream f1,f2;
	f1.open("Student.dat",ios::in | ios::binary);
	f2.open("Temp.dat",ios::out | ios::binary);
	long admno;
char ch;int found=0;
cout<<"\n Please Enter the ADMNO to be deleted from records;";
cin>>admno;
while (f1.read((char*) & s1, sizeof(s1)))
{
	if (!(s1.getadmno()==admno))
		f2.write((char*)&s1, sizeof(s1));
	else
	{
		found++;
		s1.Show();
		cout<<"\n Are you sure you want to delete this record?(Y/N)";
		cin>>ch;
		if(tolower(ch)=='n')
			f2.write((char*)&s1,sizeof(s1));
		else
			cout<<"\n Deleted successfully!";
	}
}
f1.close();
f2.close();
remove("Student.dat");
rename("Temp.dat","Student.dat");
if (!found)
	cout<<"No record matches";
}

void stud_report()
{
	fstream F;
	clrscr();
	F.open("Student.dat",ios::in|ios::binary);
	Student s1;
	int n=0;
	cout<<"\n------------------------------------------------------------"<<"----------------------------------------------------------------";
	cout<<"\n"<<setw(10)<<"Class"<<setw(10)<<"Admno"<<setw(10)<<"Rollno"<<setw(20)<<"Name"<<setw(10)<<"Average";
	cout<<"\n--------------------------------------------"<<"----------------------------------------------";
	while(F.read((char*)&s1,sizeof(s1)))
	{
		s1.Show();
		n++;
		if(n%20==0)
			getch();
//TO PAUSE AFTER 20 RECORDS
	}
	if(n==0)
		cout<<"\n Record not Found !!!";
		cout<<"\n------------------------------------"<<"-------------------------------------------------";
	F.close();
}

void FinalUpdate()
{
	float stot[5]={0,0,0,0,0};
	float avg[5]={0,0,0,0,0};
	float high[5]={0,0,0,0,0};
	int count=0;
	fstream f("Student.dat",ios::in|ios::binary);
	Student s1;
	while(f.read((char*)&s1,sizeof(s1)))
	{
	stot[0]+=s1.getth1();
	stot[1]+=s1.getth2();
	stot[2]+=s1.getth3();
	stot[3]+=s1.getth4();
	stot[4]+=s1.getth5();
	if(high[0]<s1.getth1())
		high[0]=s1.getth1();
	if(high[1]<s1.getth2())
		high[1]=s1.getth2();
	if(high[2]<s1.getth3())
		high[2]=s1.getth3();
	if(high[3]<s1.getth4())
		high[3]=s1.getth4();
	if(high[4]<s1.getth5())
		high[4]=s1.getth5();
count++;
}
f.close();

for(int i=0; i<5; i++)
{
	avg[i]=stot[i]/count;
}
fstream File("Student.dat",ios::in|ios::out|ios::binary);
while(File.read((char*)&s1,sizeof(s1)))
{
	s1.setHighest(high,avg);
	File.seekp(File.tellg()-sizeof(s1));
	File.write((char*)&s1,sizeof(s1));
}
File.close();
}


void menu()
{
int ch;
do
	{
	clrscr();
	FinalUpdate();
	cout<<"\n\t Main menu";
	cout<<"\n\t ---------------------";
	cout<<"\n\t 1. Add Record";
	cout<<"\n\t 2. Search Record";
	cout<<"\n\t 3. Modify Record";
	cout<<"\n\t 4. Delete Record";
	cout<<"\n\t 5. Report";
	cout<<"\n\t 6. Exit";
	cout<<"\n\t Enter Choice[1-6]:";
	cin>>ch;
	switch(ch)
	{
		case 1:stud_add();
			break;
		case 2:stud_search();
			break;
		case 3:stud_modify();
			break;
		case 4:stud_delete();
			break;
		case 5:stud_report();
			break;
		case 6:cout<<"\n\t Quitting..Press Enter";
			break;
		default:cout<<"\n\t Invalid Choice!";
			break;
	}
	getch();
	}while(ch!=6);
}

void main()
{
	clrscr();
	menu();
	cout<<"Have a nice day ";
	getch();
}