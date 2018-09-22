#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
class phone
{
 private:
 int model;
 char comp[10];
 float price;

 public:
 void input()
 {cout<<endl<<"please enter the company of smartphone=";
 gets(comp);
 cout<<endl<<"please enter the model=";
 cin>>model;
 cout<<endl<<"enter the price=";
 cin>>price;
 }

 void output()
 {
  cout<<endl<<"the company entered =";
  puts(comp);
  cout<<endl<<"the model entered ="<<model;
  cout<<endl<<"the price entered ="<<price;
 }
 int retmodel()
 {return model;
 }
 char* retcomp()
 {return comp;
 }
 float retprice()
 {return price;
 }
 };
 //function to write in file
 void smartphone()
 {
  char ans='y';
  do
  {fstream fil;
  fil.open("Mobile.dat",ios::binary|ios::app);
  phone p;
  p.input();
  fil.write((char*)&p,sizeof(p));
  fil.close();

  cout<<endl<<"your phone is ready!!!";
  cout<<endl<<"do you want to continue(y/n)? ";
  cin>>ans;
  }
  while(ans=='y'|| ans=='Y');
  }
  //function to read all record from the file
  void showphone()
  {
  clrscr();
  fstream fil;
  phone p;
  cout<<endl<<"display your record ";
  fil.open("Mobile.dat",ios::binary|ios::in);
  while(fil.read((char*)&p,sizeof(p)))
  {
  p.output();
  getch();
  }
  fil.close();
  getch();
  }
  //function to read specific record.
  void search(int n)
  {
   clrscr();
  fstream fil;
  phone p;
  int flag=0;
  fil.open("Mobile.dat",ios::binary||ios::in);
  while(fil.read((char*)&p,sizeof(p)))
  {
  if(p.retmodel()==n)
  {p.output();
   flag=1;
   }
   }
   fil.close();

   if(flag==0)
   cout<<endl<<"sorry! this record does not exist";
   getch();
   }

   //function to modify a record in a file
   void modify()
   {
   clrscr();
   fstream fil;
   phone p;
   int no,found=0;
   char see;
   cout<<endl<<"MODIFY";
   cout<<endl<<"enter the model no of the phone=";
   cin>>no;
   fil.open("Mobile.dat",ios::binary|ios::in|ios::out);

   while(fil.read((char*)&p,sizeof(p)))
   {
   if(p.retmodel()==no)
   {
   p.output();
   cout<<endl<<"enter the new detail=";
   p.input();

   int pos=-1*sizeof(p);
   fil.seekp(pos,ios::cur);
   fil.write((char*)&p,sizeof(p));
   cout<<endl<<"Record updated";
   cout<<endl<<"do you want to see the updated record(y/n)?";
   cin>>see;
   if(see=='y'||see=='Y')
   {p.output();
   found=1;
   }}}
   fil.close();
   if(found==0)
   cout<<endl<<"record not found";
   getch();
   }

   //function to delete a record
   void delete_phone()
   {
   fstream fil;
   phone p;
   char see;
   int no,flag=0;
   clrscr();
   cout<<endl<<"delete record";
   cout<<endl<<"enter the model to be deleted=";
   cin>>no;
   fil.open("Mobile.dat",ios::binary|ios::in|ios::out);
   fstream filz;
   filz.open("temp.dat",ios::binary|ios::out);
   fil.seekg(0,ios::beg);

   while(fil.read((char*)&p,sizeof(p)))
   {
   if(p.retmodel()!=no)
   {
   filz.write((char*)&p,sizeof(p));
   }
   else
   flag=1;
   }
   filz.close();
   fil.close();

   remove("Mobile.dat");
   rename("temp.dat","luxury.dat");
   if(flag==1)
   cout<<endl<<"record deleted";
   else
   cout<<endl<<"record does not exist";
   cout<<endl<<"do you want to see modified record(y/n) ";
   cin>>see;
   if(see=='y')
   {p.output();
   }
   getch();
   }


 //MAIN MENU

   void admin_menu()
   {
   clrscr();
   char ch2;
   cout<<endl<<"*** WELCOME TO SMARTPHONE SHOWROOM ***";
   cout<<endl<<"made by:PRERNA,PRACHI";
   cout<<endl<<"school:QUEEN MARY'S SCHOOL";
   cout<<endl<<"ADMIN MENU";
   cout<<endl<<"1.CREATE PHONE";
   cout<<endl<<"2.DISPLAY ALL PHONES";
   cout<<endl<<"3.SEARCH A PHONE";
   cout<<endl<<"4.MODIFY A PHONE";
   cout<<endl<<"5.DELETE A PHONE";
   cout<<endl<<"6.BACK TO AMIN MENU";
   cout<<endl<<"enter choice=(1-6)";
   cin>>ch2;

   switch(ch2)
   {case'1':smartphone();
	    break;
   case '2':showphone();
	    break;
   case '3':int num;
	    clrscr();
	    cout<<endl<<"enter the model to be searched=";
	    cin>>num;
	    search(num);
	    break;
   case '4':modify();
	    break;
   case '5':delete_phone();
	    break;
   case '6':cout<<endl<<"PLEASE GO BACK TO THE MAIN MENU";
	    break;
   default:cout<<endl<<"enter a valid choice";
   }
   }
   void main()
   {
   char ch;
   do
   {
   clrscr();
   cout<<endl<<"MAIN MENU";
   cout<<endl<<"1.ADMINISTRATOR";
   cout<<endl<<"2.EXIT";
   cout<<endl<<"please enter your choice";
   cin>>ch;

   switch(ch)
   {
   case '1':clrscr();
	    admin_menu();
	    break;

   case '2':cout<<endl<<"Thank For Visiting";
	    getch();
	    exit(0);
  default:cout<<endl<<"enter the valid choice";
  }
  }
  while(ch!=3);
  }

