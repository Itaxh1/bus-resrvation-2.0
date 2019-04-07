#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
#include<stdlib.h>

class data
{
public:
intrno;
char depart[50];
chardest[50];
char time[50];
floatfare,qty,tax;
char name[50];
int age;
char gender;

	voidcreate_route()
	{
	cout<<"Please Enter the route number:";
	cin>>rno;
	cout<<"\tPlease Enter The Departure point: ";
	gets(depart);
	cout<<"\tPlease Enter The Destination point: ";
	gets(dest);
	cout<<"\tPlease enter the time of arrival(HH:MM):";
	gets(time);
	cout<<"\tPlease Enter The Fare of the journey ";
	cin>>fare;
	 }

char* retdepart()
  {return depart;}

char* rettime()
  {return time;}

intretrno()
  {returnrno;}

floatretfare()
  {return fare;}

char* retdest()
  {returndest;}
};         //class ends here

class account
{
public:
int age;
char gen;
char name[50];
charpno[50];

voidcreate_account()
{ gotoxy(12,10);
cout<<"Name:";
gets(name);
gotoxy(12,12);
cout<<"Age:";
cin>>age;
gotoxy(12,14);
cout<<"Gender (M/F):";
cin>>gen;

A:
gen=tolower(gen);
if(gen!='m' &&  gen!='f' )
      {cout<<gen;
cout<<"I guesther is no gender like that!!!";
cout<<"\n Please give it in M or F format";
	cin>>gen;
	goto A;}
B:
gotoxy(12,16);
cout<<"Phone  number:";
gets(pno);
intfg=0;
if(strlen(pno)==8 || strlen(pno)==10)
       {
for(int i=0;i<strlen(pno);i++)
       {
	if(isdigit(pno[i]))
	fg++;
	 }
       }
	if(fg!=8 &&fg!=10)
	{
	cout<<"The number is not valid";
	cout<<"\nEnter valid number:";
	gets(pno);
	}
}
char user[50];
charpassw[50];

intretage()
  {return age;}

char* retpno()
  {returnpno;}

char* retname()
  {return name;}

intretgen()
  {return gen;}
};

void book();
voidmain_menu();
void login();
voidcust(int g);
voidadmin_menu();

void format()
{gotoxy(0,0);
cout<<"***************************";
	cout<<"*************************************";
	cout<<"***************\t\t\t\t       PARVEEN TRAVELS \n****";
	cout<<"*****************************************************";
	cout<<"***********************";


cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
cout<<"************";
		cout<<"*******************************";
		cout<<"*******************************";
		cout<<"*******************************";
		cout<<"*******************************";
		cout<<"************************";
gotoxy(0,3);
}

fstream f,f1,f8;
data d;
account a;



voidadd_account()
{
format();
fstream y;
y.open("account.dat",ios::in);
charuserl[50];

S:
gotoxy(12,5);
char un[40];
strcpy(un,NULL);
int flag3=0;
cout<<"Username:";
gets(un);
while(y.read((char*) &a, sizeof(account)))
{
if(strcmp(a.user,un)==0)
{
cout<<"Username already exists\n\n";
flag3++;
cout<<"Enter username:";
gets(un);


}
}
if(flag3>0)
{
getch();
goto S;
}
else
{
strcpy(a.user,un);
gotoxy(12,8);
cout<<"Enter password:";
intiu=0;
while(1)
{
a.passw[iu]=getch();

if(a.passw[iu]==13)
{
a.passw[iu]='\0';
break;
}
else
cout<<'*';
iu++;
}
a.create_account();

y.close();
y.open("account.dat",ios::app | ios::binary);
y.write((char*)&a, sizeof(account));
y.close();
	 }
cout<<"\n\t\tProcessing";
for(int i=0;i<3;i++)
{
delay(500);
cout<<".";

}
cout<<"\nThe account Has Been Created ";
getch();
clrscr();
}






void login(char username[50],char password[50])
{
int flag=0;
int r=0;
f.open("account.dat",ios::in);
while(f.read((char*)&a,sizeof(account)))
	{  r++;
		if(strcmp(a.user,username)==0 &&strcmp(a.passw,password)==0)
		{
		clrscr();
		format();
		gotoxy(9,6);
		cout<<"Checking";
		for(int i=0;i<3;i++)
		{
		delay(100);
		cout<<".";
		delay(500);
		}
		clrscr();
		gotoxy(25,7);
		cout<<"Welcome";

		if(a.retgen()=='m')
		{gotoxy(25,8);
		cout<<"Mr."<<a.retname();
		}
		else
		{gotoxy(25,8);
		cout<<"Mrs."<<a.retname();
		}
		delay(1000);
		cust(r);
		flag=1;
		}
	}
f.close();
if(flag==0)
{
cout<<"\n\n\t\tChecking";
for(int i=0;i<3;i++)
{
delay(500);
cout<<".";
}
clrscr();
cout<<"\nInvalid username or password";
getch();
main_menu();
    }
}

voidadd_route()
   {
format();
f.open("data.dat",ios::out|ios::app);
gotoxy(9,5);
d.create_route();
f.write((char*)&d,sizeof(data));
f.close();
cout<<"\n\n\t\tPLEASE WAIT PROCESSING";
for(int i=0;i<3;i++)
{
delay(1000);
cout<<".";
delay(800);
}
clrscr();

cout<<"\n\nThe route Has Been Created ";
getch();
admin_menu();
   }

voiddisplay_all()
{
clrscr();
	format();
f.open("data.dat",ios::in);
gotoxy(5,5);
cout<<"Route no.";
gotoxy(20,5);
cout<<" Departure";
gotoxy(40,5);
cout<<"Destination";
gotoxy(60,5);
cout<<"Time";
gotoxy(75,5);
cout<<" Fare\n";
cout<<"=================================";
cout<<"=================================";
cout<<"==============";

int c=2;

while(f.read((char*)&d,sizeof(data)))
{
	gotoxy(5,7+c);
	cout<<d.retrno();
	gotoxy(20,7+c);
	cout<<d.retdepart();
	gotoxy(40,7+c);
	cout<<d.retdest();
	gotoxy(60,7+c);
	cout<<d.rettime();
	gotoxy(75,7+c);
	cout<<d.retfare();
	c+=2;
}
f.close();
getch();
admin_menu();
}


voiddisplay_sel()
{
int c=0;
	gotoxy(5,4);
cout<<"Route no.";
gotoxy(20,4);
cout<<" Departure";
gotoxy(40,4);
cout<<"Destination";
gotoxy(60,4);
cout<<"Time";
gotoxy(75,4);
cout<<" Fare\n";
cout<<"=================================";
cout<<"=================================";
cout<<"==============";
	gotoxy(5,6+c);
	cout<<d.retrno();
	gotoxy(20,6+c);
	cout<<d.retdepart();
	gotoxy(40,6+c);
	cout<<d.retdest();
	gotoxy(60,6+c);
	cout<<d.rettime();
	gotoxy(75,6+c);
	cout<<d.retfare();
}

//**********************************************************
//     query function
//**********************************************************
voiddisplay_sp(int no)
{        clrscr();
format();
int flag=0;
f.open("data.dat",ios::in);
while(f.read((char*)&d,sizeof(data)))
	{
	if(no==d.retrno())
		{
	gotoxy(12,3);
cout<<"Search Results";
	display_sel();
	flag++;
	      }
		}
f.close();
if(flag==0)
{ gotoxy(9,5);
cout<<"Route does not exist";}
getch();
	admin_menu();
}

void up()
{
cout<<"\nUpdating";
for(int i=0;i<3;i++)
  {
delay(1000);
cout<<".";
}
cout<<"\nUpdated";
getch();
}





voidmodify_route()
{
intn,flag=0;
clrscr();
format();
gotoxy(9,5);
cout<<"Please Enter The route number:";
cin>>n;
f.open("data.dat",ios::in|ios::out);
m:  while(f.read((char*)&d,sizeof(data)) && flag==0)
	   {
	if(n==d.retrno())
{
flag++;
intnav=7000;
do
	{       clrscr();
		format();
		display_sel();
		gotoxy(20,8);
		cout<<"Select what you want to modify";
		if(nav%7==0)
		{ gotoxy(9,9);
			cout<<char(175);}
		else
			gotoxy(9,9);
		cout<<"ROUTE NO.";
		if(nav%7==1)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"DEPARTURE";
		if(nav%7==2)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"DESTINATION";
		if(nav%7==3)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"TIME";
		if(nav%7==4)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"FARE";
		if(nav%7==5)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"ALL";

		if(nav%7==6)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"BACK TO ADMIN MENU";
		charch;
		ch=getch();
		clrscr();
		if(int(ch)==80)
			nav++;
		else if(int(ch)==72)
			nav--;
		if(int(ch)==13)
		{	if(nav%7==0)
			{	clrscr();
				cout<<"Enter new route number:";
				cin>>d.rno;
				intpos=-1*sizeof(d);
				f.seekp(pos,ios::cur);
				f.write((char*)&d,sizeof(data));
				up();
				nav=7000;
				break;
			}
			else if(nav%7==1)
			{	clrscr();

				cout<<"Enter new departure point:";
				gets(d.depart);
				intpos=-1*sizeof(d);
				f.seekp(pos,ios::cur);
				f.write((char*)&d,sizeof(data));
				up();
				nav=7000;
				break;
			}
			else if(nav%7==2)
			{
				clrscr();

				cout<<"Enter new destination point:";
				gets(d.dest);
				intpos=-1*sizeof(d);
				f.seekp(pos,ios::cur);
				f.write((char*)&d,sizeof(data));
				up();
				nav=7000;
				break;
			}
			else if(nav%7==3)
			{	clrscr();

				cout<<"Enter new time:";
				gets(d.time);
				intpos=-1*sizeof(d);
				f.seekp(pos,ios::cur);
				f.write((char*)&d,sizeof(data));
				up();
				nav=7000;
				break;
			}
			else if(nav%7==4)
			       {	clrscr();
				intfa;
				cout<<"Enter new fare:";
				cin>>d.fare;
				intpos=-1*sizeof(d);
				f.seekp(pos,ios::cur);
				f.write((char*)&d,sizeof(data));
				up();
				nav=7000;
				break;
				}
		else if(nav%7==5)
				{
				cout<<"\nPlease Enter The New Details of Journey"<<endl;
				d.create_route();
				intpos=-1*sizeof(d);
				f.seekp(pos,ios::cur);
				f.write((char*)&d,sizeof(data));
				up();
				nav=7000;
				break;
				}
		else if(nav%7==6)
				{clrscr();
				nav=7000;
				break;
				}
}
	}while(1);
}
}
f.close();
if(flag==0)
    {
gotoxy(9,10);
cout<<" Route Not Found ";
    }
getch();
	admin_menu();
}

voiddelete_route()
   {
int no;
clrscr();
format();
gotoxy(9,5);
cout<<"Delete route";
cout<<"\n\nPlease Enter The route no. of The route You Want To Delete";
cin>>no;
f.open("data.dat",ios::in|ios::out);
fstream f2;
f2.open("Temp.dat",ios::out);
f.seekg(0,ios::beg);
while(f.read((char*)&d,sizeof(data)))
	{
	if(d.retrno()!=no)
		{
		cout<<"Route does not exist";
		getch();
		admin_menu();
		 }
		else
		{   clrscr();
		format();
		gotoxy(20,3);
		cout<<"Route to be deleted";
		display_sel();
		getch();
		}
	 }
f2.close();
f.close();
remove("data.dat");
rename("Temp.dat","data.dat");
cout<<"\n\n\tDeleting";
for(int i=0;i<3;i++)
{
delay(1000);
cout<<".";
delay(800);
}
cout<<"Route Deleted";
	getch();
admin_menu();
    }

void book()
{ format();
de:
char  ds[50],dp[50];
intquan,amt;
gotoxy(20,3);
cout<<"Routes available";
gotoxy(5,5);
cout<<"Route no.";
gotoxy(15,5);
cout<<" Departure";
gotoxy(35,5);
cout<<"Destination";
gotoxy(55,5);
cout<<"Time";
gotoxy(75,5);
cout<<" Fare\n";
cout<<"=================================";
cout<<"=================================";
cout<<"==============";
f8.open("data.dat",ios::in);
int c=1;
while(f8.read((char*)&d,sizeof(data)))
	 {
	gotoxy(5,7+c);
	cout<<d.retrno();
	gotoxy(20,7+c);
	cout<<d.retdepart();
	gotoxy(40,7+c);
	cout<<d.retdest();
	gotoxy(60,7+c);
	cout<<d.rettime();
	gotoxy(75,7+c);
	cout<<d.retfare();
	c+=2;
	}
f8.close();
fstream b;
cout<<"\n============================";
cout<<"\n    PLACE YOUR BOOKING";
cout<<"\n============================\n";
	cout<<"\n\n\tEnter The Departure point:";
	gets(dp);
	cout<<"\n\tEnter the Destination point:";
	gets(ds);
	x:cout<<"\n\tNumber of tickets : ";
	cin>>quan;
	if(quan>5)
	 {cout<<"Can't book more than 5 tickets";
	getch();
	goto x;}
	clrscr();
		intro=0;
	{
		b.open("data.dat",ios::in);
		b.read((char*)&d,sizeof(data));
		while(!b.eof())
			{
			if (strcmp(d.retdepart(),dp)==0 &&strcmp(d.retdest(),ds)==0)
				{ ro++;
				amt= d.retfare()*quan;
				randomize();
				cout<<"******************************INVOICE*********************";
				cout<<"\nTicket number:"<<random(3000);
				cout<<"\n"<<"Route no."<<d.retrno();
				cout<<"\nDeparture:"<<d.retdepart();
				cout<<"\nDestination:"<<d.retdest();
				cout<<"\nTickets:"<<quan;
				cout<<"\nTime:"<<d.rettime();
				cout<<"\nFare:"<<d.retfare();
				cout<<"\nTotal amount:"<<amt;

				}
			b.read((char*)&d,sizeof(data));
			}

		b.close();
	 }

if(ro==0)
       {cout<<"\n\nRoute does not exist";
	getch();
	clrscr();
	goto de;
	}
cout<<"\n\nPress enter to go to user menu...";
int en=getch();
if(en==13)
clrscr();
    }

voidmodify_user(int u)
 {
clrscr();
	format();
gotoxy(25,12);


f.open("account.dat",ios::in|ios::out);




	cout<<endl;
	int n=4000;
	int h=0;

while(f.read((char*)&a,sizeof(account)))
		{	h++;
			if(h==u)
		{
		do
		{clrscr();
		format();
			gotoxy(25,5);
		cout<<"Current details";
		gotoxy(25,5);
		cout<<"\nName:"<<a.retname();
		cout<<"\nAge:"<<a.retage();
		cout<<"\nPhone number:"<<a.pno;

			charch;
	      _setcursortype(_NOCURSOR);
	gotoxy(9,12);
	cout<<"What do you want to modify"

		if(n%4==0)
		{gotoxy(9,13);
		cout<<char(175);
		}
		else
			gotoxy(9,13);
		cout<<"AGE";
		if(n%4==1)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"PHONE NUMBER";
		if(n%4==2)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"NAME";

		if(n%4==3)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"BACK";
		ch=getch();

		clrscr();
		if(int(ch)==80)
			n++;
		else if(int(ch)==72)
			n--;
		if(int(ch)==13)
		{	if(n%4==0)
			{	n=4000;
				clrscr();
				cout<<"Enter new age:";
				cin>>a.age;

				f.write((char*)&a,sizeof(account));
				up();

			}
			else if(n%4==1)
			{	n=4000;
				clrscr();
				cout<<"Enter new phone number:";
				gets(a.pno);
				intpos=(u-1)*sizeof(a);
				f.seekp(pos,ios::beg);
				f.write((char*)&a,sizeof(account));
				up();
			}
			else if(n%4==2)
			{
			n=4000;
			clrscr();
			cout<<"Enter new name:";
			gets(a.name);
			cout<<"s";
			getch();

			f.seekp((u-1)*sizeof(a),ios::beg);
			cout<<"r";
			getch();
			f.write((char*)&a,sizeof(account));
			up();
			}
			else if(n%4==3)
			{	clrscr();
				n=4000;
				break;
			}
			}
	}while(1);
		} }

f.close();
	getch();
}

void pass()
{
clrscr();
format();
char code[50];
gotoxy(10,10);
cout<<"Enter authorisation code:";
intiu=0;
while(1)
{
code[iu]=getch();

if(code[iu]==13)
{
code[iu]='\0';
break;
}
else
cout<<'*';
iu++;
}

gotoxy(12,12);
cout<<"Checking code";
int i;
for(i=0;i<3;i++)
{delay(500);
cout<<".";
}
if(strcmp("csc123",code)==0 )
admin_menu();
else
{gotoxy(20,20);
cout<<"Invalid authentication code";
delay(1000);
clrscr();
}

}

void user(int u)
{
format();
f.open("account.dat",ios::in|ios::out);
f.seekp((u-1)*sizeof(a),ios::cur);
gotoxy(9,5);
cout<<"Name:"<<a.retname();
cout<<"\n\tAge:"<<a.retage();
cout<<"\n\tPhone number:"<<a.pno;

}

voidadmin_menu()
{
clrscr();
format();
gotoxy(12,12);
cout<<"Accessing files";

delay(1000);
clrscr();

	intnav=6000;
	charch;
	do
	{format();
		if(nav%6==0)
			{gotoxy(9,5);
			cout<<char(175);}
		else
			gotoxy(9,5);

		cout<<"ADD ROUTE";
		if(nav%6==1)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"DISPLAY ALL ROUTE";
		if(nav%6==2)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"QUERY";
		if(nav%6==3)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"MODIFY ROUTE";
		if(nav%6==4)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"DELETE ROUTE";
		if(nav%6==5)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"LOGOUT";
		ch=getch();
		clrscr();
		if(int(ch)==80)
			nav++;
		else if(int(ch)==72)
			nav--;
		if(int(ch)==13)
		{	if(nav%6==0)
			{	clrscr();
				add_route();
				nav=6000;
				break;
			}
			else if(nav%6==1)
			{	display_all();
				nav=6000;
				break;
			}
			else if(nav%6==2)
			{	intrnum;
				format();
				gotoxy(9,5);
				cout<<"Please Enter The route No. ";
				cin>>rnum;
				display_sp(rnum);

				nav=6000;
				break;
			}
			else if(nav%6==3)
			{	modify_route();
				nav=6000;
				break;
			}
			else if(nav%6==4)
			       {delete_route();
				nav=6000;
				break;}
		else if(nav%6==5)
				clrscr();
				nav=6000;
				break;
}
	}while(1);
}

voidcust(int g)
{
charch;
	clrscr();
	intnav=4000;
	do{clrscr();
		int p=g;
	format();
		if(nav%5==0)
			{gotoxy(9,5);
			cout<<char(175);}
		else
			gotoxy(9,5);
		cout<<"BUY TICKETS";
		if(nav%5==1)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"VIEW BUS ROUTES";
		if(nav%5==2)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"MODIFY ACCOUNT";
		if(nav%5==3)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"VIEW ACCOUNT DETAILS";
		if(nav%5==4)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"BACK TO MAIN MENU";

		ch=getch();
		clrscr();
		if(int(ch)==80)
			nav++;
		else if(int(ch)==72)
			nav--;
		if(int(ch)==13)
		{	if(nav%5==0)
			{	book();
				nav=5000;
			}
			else if(nav%5==1)
			{
				cout<<"Routes available";
gotoxy(5,5);
cout<<"Route no.";
gotoxy(15,5);
cout<<" Departure";
gotoxy(35,5);
cout<<"Destination";
gotoxy(55,5);
cout<<"Time";
gotoxy(75,5);
cout<<" Fare\n";
cout<<"=================================";
cout<<"=================================";
cout<<"==============";
f8.open("data.dat",ios::in);
int c=1;
while(f8.read((char*)&d,sizeof(data)))
	 {
	gotoxy(5,7+c);
	cout<<d.retrno();
	gotoxy(20,7+c);
	cout<<d.retdepart();
	gotoxy(40,7+c);
	cout<<d.retdest();
	gotoxy(60,7+c);
	cout<<d.rettime();
	gotoxy(75,7+c);
	cout<<d.retfare();
	c+=2;
	}
f8.close();
			getch();
			nav=5000;
			}
			else if(nav%5==2)
			{

				modify_user(p);
				nav=5000;
			}
			else if(nav%5==3)
			{
				nav=5000;
				user(p);
				getch();
			}

			else if(nav%5==4)
			{	main_menu();
				nav=5000;
			}
		}
	}while(1);
}



void main()
{
clrscr();
charstr[] ="BUS RESERVATION";
	gotoxy(32,12);
	for(int i=0;i<strlen(str);i++)
	   {
	cout<<str[i];

	delay(100);
	   }
charch;
main_menu();
}
voidmain_menu()
{  charch;

	clrscr();

	intnav=4000;
	do{format();
	      _setcursortype(_NOCURSOR);
		gotoxy(27,4);
		cout<<"MAIN MENU";
		if(nav%4==0)
			{gotoxy(9,5);
			cout<<char(175);}
		else
			gotoxy(9,5);

		cout<<"CUSTOMER";
		if(nav%4==1)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"ADMINISTRATOR";
		if(nav%4==2)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"REGISTER";
		if(nav%4==3)
			cout<<"\n\n\t"<<char(175);
		else
			cout<<"\n\n\t";
		cout<<"EXIT";

		ch=getch();
		clrscr();
		if(int(ch)==80)
			nav++;
		else if(int(ch)==72)
			nav--;
		if(int(ch)==13)
		{	if(nav%4==0)
			{	nav=4000;
				clrscr();
				format();
				char u[50],p[50];
				gotoxy(12,7);
				cout<<"Enter username:";
				gets(u);
				gotoxy(12,10);
				cout<<"Enter password:";
				int i=0;
				while(1)
				{
				p[i]=getch();

				if(p[i]==13)
				{
				p[i]='\0';
				break;
				}
				else
				cout<<'*';
				i++;
				}
				login(u,p);
				getch();
				break;
			}
			else if(nav%4==1)
			{	pass();
				nav=4000;
			}
			else if(nav%4==2)
			{	add_account();
				nav=4000;
			}
			else if(nav%4==3)
			{	exit(0);
				nav=4000;
			}

		}

	}while(1);
    }

