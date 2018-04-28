#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<cstring>
#include<fstream>

using namespace std;

class vehicle
{
  protected:
            string carno;
            string  nameofcustomer;
            string  addressofcustomer;
            int contactno;
            string  typeofvechile;
            string  manufactureofvechile;
            string  nameofvechile;
            int dateofpurche;
            int kmdriven;
            string  typeofsurvice;
 public:

	void setcarno(string   icarno)
	{
		carno=icarno;
	}
	void setnameofcustomer(string inameofcustomer )
	{
	    nameofcustomer=inameofcustomer;
	}
	void setaddressofcustomer(string iaddressofcustomer)
	{
	    addressofcustomer=iaddressofcustomer;
	}
	void setcontactno(int icontactno)
	{
	    contactno=icontactno;
	}
	void settypeofvechile(string itypeofvechile)
	{
	    typeofvechile=itypeofvechile;
	}
	void setmanufactureofvechile(string imanufactureofvechile)
	{
	   manufactureofvechile=imanufactureofvechile;
	}
	void setnameofvechile(string inameofvechile)
	{
	    nameofvechile=inameofvechile;
	}
	void setdateofpurche(int idateofpurche)
	{
	    dateofpurche=idateofpurche;
	}
	void setkmdriven(int ikmdriven)
	{
	    kmdriven=ikmdriven;
	}
	void settypeofsurvice(string itypeofsurvice)
	{
	    typeofsurvice=itypeofsurvice;
	}
};

class newcar :  public vehicle

{
  public:
     string  carno;
	     void getdata1(){

	         cout<<"\t\t\t\t\t\t"<<"WELCOME TO  CAR SERVICE"<<endl;
	         cout<<"\t\t"<<"__________________________________________________________________________________________"<<endl;
	         cout<<endl;

	    cout<<"ENTER THE CAR NUMBER"<<endl;
	    cin>>carno;

	    cout<<"ENTER THE NAME OF CUSTOMER"<<endl;
	    cin>>nameofcustomer;

	    cout<<"ENTER THE ADDRESS OF CUSTOMER"<<endl;
	    cin>>addressofcustomer;

	    cout<<"ENTER THE CONTACT NUMBER"<<endl;
	    cin>>contactno;
	    try{
	        if(sizeof(contactno)!=10)
	    throw(contactno);
	    }
	    catch(int  contactno){
	        cout<<"invalid contact no"<<endl;
            }

	    cout<<"ENTER THE TYPE OF VECHILE"<<endl;
	    cin>>typeofvechile;

	    cout<<"ENTER THE MANUFACTURE OF VECHILE"<<endl;
	    cin>>manufactureofvechile;

	    cout<<"ENTER THE NAME OF VECHILE"<<endl;
	    cin>>nameofvechile;

	    cout<<"ENTER THE DATE OF PURCHESE"<<endl;
	    cin>>dateofpurche;

	    cout<<"ENTER THE KILOMETER DRIVEN"<<endl;
	    cin>>kmdriven;

	}

void forviewinfile()

{

    cout<<"\t\t\t\t\t\t"<<"WELCOME TO  CAR SERVICE"<<endl;
    cout<<"\t\t"<<"__________________________________________________________________________________________"<<endl;
    cout<<endl;

    cout<<"ENTER THE CAR NUMBER"<<carno<<endl;


    cout<<"ENTER THE NAME OF CUSTOMER"<<nameofcustomer<<endl;


    cout<<"ENTER THE ADDRESS OF CUSTOMER"<<addressofcustomer<<endl;


    cout<<"ENTER THE CONTACT NUMBER"<<contactno<<endl;


    cout<<"ENTER THE TYPE OF VECHILE"<<typeofvechile<<endl;


    cout<<"ENTER THE MANUFACTURE OF VECHILE"<<manufactureofvechile<<endl;


    cout<<"ENTER THE NAME OF VECHILE"<<nameofvechile<<endl;


    cout<<"ENTER THE DATE OF PURCHESE"<<dateofpurche<<endl;


    cout<<"ENTER THE KILOMETER DRIVEN"<<kmdriven<<endl;

}

void display1()

{
     if((kmdriven==5000))
    {
      cout<<"CAR GO FOR FIRST SERVICE"<<endl;
    }
     else if(kmdriven==10000)
     {
      cout<<"CAR GO FOR SECOND SERVICE"<<endl;
     }
     else if(kmdriven==15000)
     {
        cout<<"CAR GO FOR THIRD SERVICE"<<endl;
     }
     else
     {
        cout<<"FREE SERVICE IS NOT AVAILABEL-->GO FOR PAID SURVICE"<<endl;
     }
     cout<<"THIS IS YOUR  CAR TOKEN NUMBER FOR TAKING YOUR CAR AFTER SERVICE"<<"  ";

     cout<<rand()<<endl;

     cout<<"YOU HAVE TO WAIT FOR"<<"  ";

     for(int i=1;i<=1;i++)
     {
        cout<<1+(rand()%4)<<" "<<"hour"<<endl;
     }

 }
 void bill()
  {
     srand(time(0));
     long  int sum=0;
     int temp;
     const string partList[4] = { "mobile","break", "shock-up", "tube" };

    for(int i=0;i<2;i++)
    {

    string word = partList[rand() % 4];

    temp=50+(rand()%300);

   cout <<"price of"<<" "<< word << " " <<"is" <<"\t\t "<<temp<< endl;

    sum=sum+temp;
    }
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"your bill is "<<"\t\t\t"<<sum;
    }
    int storedata1();
    void viewdata1();
   void  searchdata1();
};
/*
void  newcar :: searchdata1()
{
      newcar ob;
    string carno;
  ifstream searc;
  searc.open("file1.txt",ios::in | ios::binary);
  if(!searc)
    cout<<"\n file not found";
  else{
      system("cls");
      cout<<"Enter vehicle no"<<endl;
      cin>>carno;
        searc.seekg(0);
    searc.read((char*)&ob,sizeof(ob));
    while(!searc.eof()){
        if(ob.carno==carno)
        {
            ob.getdata1();

        }
        searc.read((char*)&ob,sizeof(ob));
    }
   searc.close();

  }
}*/
  void newcar :: viewdata1()
 {
    ifstream view;
    view.open("file1.txt",ios::in | ios ::binary);
    if(!view)
        cout<<"file does not exit :"<<endl;
    else{
            view.read((char*)this,sizeof(*this));
    while(!view.eof())
    {
        system("cls");
        forviewinfile();
        display1();
        bill();
        view.read((char*)this,sizeof(*this));
    }

        view.close();
    }
 }
int newcar :: storedata1()
 {
     ofstream store;
     store.open("file1.txt",ios :: app | ios :: binary);
     store.write((char*)this,sizeof(*this));
     store.close();
 }
 class accidentcar : public vehicle
 {
   public:
            int condition;
            void getdata2()
	{
      cout<<"\t\t\t\t\t\t"<<"WELCOME TO ACCIDENTAL SERVICE"<<endl;
      cout<<"\t\t"<<"__________________________________________________________________________________________"<<endl;
      cout<<endl;
      cout<<"ENTER THE CONDITION OF CAR"<<endl;
	  cin>>condition;
	}
	void display2()
	{
    if(condition <=50)
     {
    cout<<"CAR GO SURVICE"<<endl;
    cout<<endl;
	 }
	 else
     {
     cout<<"CAR NOT GO SURVICE"<<endl;
	 }
	 }
 void bill2()
  {
     srand(time(0));
     long  int sum1=0;
     int temp1=0;

    const string partList[6] = { "mobile","break", "shock-up", "tube" ,"headlight","horn"};

    cout<<"ENTER NO PART REMOVE"<<endl;

    for(int i=0;i<3;i++)
    {

    string word = partList[rand() % 3];

    temp1=50+(rand()%300);

   cout <<"price of"<<" "<< word << " "<<"is" <<"\t\t "<<temp1<< endl;

   sum1=sum1+temp1;

    }

    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
       cout<<"your bill is "<<"\t\t\t"<<sum1;
    }
     int storedata2();
     void viewdata2();
	};

	 void accidentcar :: viewdata2()
 {
    ifstream view;
    view.open("file1.txt",ios::in | ios ::binary);
    if(!view)
        cout<<"file does not exit :"<<endl;
    else{
            view.read((char*)this,sizeof(*this));
    while(!view.eof())
    {
        system("cls");

        display2();
        bill2();
        view.read((char*)this,sizeof(*this));
    }
        view.close();
    }
 }

  int accidentcar :: storedata2()
 {
     ofstream store;
     store.open("file1.txt",ios :: app | ios :: binary);
     store.write((char*)this,sizeof(*this));
     store.close();
 }


 class dentingandpanting : public vehicle

 {
 public:
 	string parts[25];
 	int n;
 	int price[5];
 	void getdata3()
 	{
    cout<<"\t\t\t\t\t\t"<<"WELCOME TO DENTING AND PAINTING SERVICE"<<endl;
    cout<<"\t\t"<<"__________________________________________________________________________________________"<<endl;
    cout<<endl;

    cout<<"ENTER NUMBER OF PART REQUIRED"<<endl;
    cin>>n;

 	cout<<"ENTER THE PART NAME AND PRICE"<<endl;

 	for(int i=0;i<n;i++)
    {
        cin>>parts[i];
        cin>>price[i];
    }
 	}
 	void display3()
 	{
    int sum=0;
    for(int i=0;i<n;i++)
{
    cout<<"The Part are"<<" "<<parts[i]<<" "<<"whose price is"<<" "<<"Rs"<<" "<<price[i]<<endl;
    sum=sum+price[i];
}

cout<<"---------------------------------------------------------------------------------------------------"<<endl;
cout<<endl;

cout<<"YOUR BILL IS"<<" "<<"Rs"<<" "<<sum;
 	}
 	int storedata3();
 	 void viewdata3();
 };

	 void dentingandpanting  :: viewdata3()
 {
    ifstream view;
    view.open("file1.txt",ios::in | ios ::binary);
    if(!view)
        cout<<"file does not exit :"<<endl;
    else{
            view.read((char*)this,sizeof(*this));
    while(!view.eof())
    {
        display3();
         view.read((char*)this,sizeof(*this));
    }
        view.close();
    }
 }

  int dentingandpanting  :: storedata3()
 {
     ofstream store;
     store.open("file1.txt",ios :: app | ios :: binary);
     store.write((char*)this,sizeof(*this));
     store.close();
 }



 class washing:  public vehicle
 {
public:
    int price;
    getdata4()
    {
         cout<<"\t\t\t\t\t\t"<<"WELCOME TO DENTING AND PAINTING SERVICE"<<endl;
	         cout<<"\t\t"<<"__________________________________________________________________________________________"<<endl;
	         cout<<endl;

        cout<<"ENTER THE PRICE FOR WASHING "<<endl;
        cin>>price;

    }
    display4()
    {
        cout<<"YOUR BILL IS" <<" "<<"Rs"<<" "<<price<<endl;
    }
    int storedata();
    void  viewdata();

 };

 void  washing :: viewdata()
 {
    ifstream view;
    view.open("file1.txt",ios::in | ios ::binary);
    if(!view)
        cout<<"file does not exit :"<<endl;
    else{
            view.read((char*)this,sizeof(*this));
    while(!view.eof())
    {
        display4();
         view.read((char*)this,sizeof(*this));
    }
        view.close();
    }
 }

 int washing :: storedata()
 {
     ofstream store;
     store.open("file1.txt",ios :: app | ios :: binary);
     store.write((char*)this,sizeof(*this));
     store.close();
 }

 int main()
 {
     string  date;
     char ch;
     cout<<"\t\t\t\t\t\t"<<"WELCOME TO THE CAR WORKSHOP"<<endl;
	cout<<"\n";
    cout<<"   -----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t"<<"JANATHA GARAGE"<<"\t\t\t\t\t\t\t\t\t\t\t"<<"DATE:";
    cin>>date;
    cout<<"   -----------------------------------------------------------------------------------------------------------------"<<endl;
 	newcar ob;
 	accidentcar ac;
 	dentingandpanting dp;
 	washing wa;
 	char code;
 	cout<<"\t\t\t\t"<<"ENTER THE TYPE OF SURVICE DO YOU WANT"<<endl;
 	cout<<endl;
 	cout<<" A :  SURVICE FOR NEW CAR \n B : SURVICE FOR ACCIDENTAL  \n C : SURVICE FOR DENTING AND PANTING \n D: SURVICE FOR WASHING"<<endl;
 	cout<<endl;
 	cout<<"PRESS THE GIVEN CODE DO YOU WANT ";
 	cin>>code;
 	switch(code)
 	{
    case 'A':
        {
            system("cls");
            ob.getdata1();
            ob.display1();
            ob.bill();
            ob.storedata1();
            cout<<"ASK THE USER TO SEE THE DATA"<<endl;
            string  n;
            cin>>n;
            if(n=="yes")
     {
         system("cls");
         ob.viewdata1();
          break;
     }

   /*  if(n=="no"){
        system("cls");
    ob.searchdata1();
     }*/
        }
    case 'B':
        {
            system("cls");
            ob.getdata1();
            ac.getdata2();
            ac.display2();
            ac.bill2();
            ac.storedata2();
            string  n;
            cin>>n;
           if(n=="yes")
     {
         system("cls");
         ac.viewdata2();
        break;
    }
        }
    case 'C':
        {
            system("cls");
            ob.getdata1();
            dp.getdata3();
            dp.display3();
            dp.storedata3();
            string  n;
            cin>>n;
            if(n=="yes")
     {
         system("cls");
         dp.viewdata3();
          break;
    }

        }
    case 'D':
        {
             system("cls");
             wa.getdata4();
             wa.display4();
             wa.storedata();

            cout<<"ASK THE USER TO SEE THE DATA"<<endl;
            string  n;
            cin>>n;
            if(n=="yes")
     {
           system("cls");
           wa.viewdata();
    }

    }
 	}
 }
