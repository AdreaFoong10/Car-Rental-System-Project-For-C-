#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cctype>
#include <ctype.h>
#include <time.h>
#include <iomanip>
#include <cstdio>

using namespace std;

//Using in class CarMenu
struct CarDetails{
	string carname,noplate,clas,color,capacity,year,opt,brand,carcode,name,status;
	double price,total;
}CD,CD2,CD3,CD4;

//Store date
struct Date{
	int rdays,day,month,year;
}d1,d2,d3;

struct Invoive{
	string name;
}inv;

//Display starting and ending logo
class Logo{
	private:
		string logo,thank;
		ifstream welc;
	public:
		Logo()
		{
			welc.open("welcome.txt");
	
			if(!welc)
			{
				cout<<"File welcome could not open!"<<endl;
				exit(1);
			}
			else
			{
				while(getline(welc,logo))
				{
					cout<<logo<<endl;	
				}
				
				welc.close();
				cout<<"\nStarting the program please wait....."<<endl;
				sleep(1);
		  		cout<<"\nloading up files....."<<endl;
		  		sleep(1); 
		  		system ("CLS"); 
				
			}
		}
		
		~Logo()
		{
			ifstream tq("thanks.txt");
			if(!tq)
			{
				cout<<"File thanks could not open!"<<endl;
				exit(1);
			}
			else
			{
				while(getline(tq,thank))
				{
					cout<<thank<<endl;
				}
			}
			tq.close();
		}
};


//Display -> when user select option 1 from main menu
class MainSelect1{
	private:
		string cus_name,cus_username,cus_IC,cus_contact_number,cus_email,pass;
		char cus_gender;
	public:
		int email_checking()
		{
			int At = -1, Dot = -1;
    		
    		for (int i = 0;i < cus_email.length(); i++)
			{
    			if (cus_email[i] == '@')
				{
  					At = i;
        		}
		        else if (cus_email[i] == '.')
				{
		            Dot = i;
		        }
    		}
    		
    		if(At == -1 || Dot == -1)
    		{
    			return 0;
			}
        		
    		if(At > Dot)
        	{
    			return 0;
			}
  			
  			if(Dot >= (cus_email.length() - 1))
  			{
  				return 0;
			}
			
			return 1;
		}
			
		int email_validation()
		{
			int num;
			
			if ((cus_email[0] >= 'a' && cus_email[0] <= 'z') || (cus_email[0] >= 'A' && cus_email[0] <= 'Z'))
			{
				num = email_checking();
  				if(num == 0)
  				{
  					return 0;	
				}
				else
					return 1;
    		}
			
    		return 0;
		}
		
		void registration()
		{
			
			
			int valid;
			
			cout<<"\n\n\t\t\t\t==============================================";
			cout<<"\n\t\t\t\t\t\tRegistration";
			cout<<"\n\t\t\t\t=============================================="<<endl;
			
			do
			{	
				
				
				valid = 0;
				fflush(stdin);
				cout<<"\n\t\t\t\tPlease enter your name : ";
				getline(cin,cus_name);
				
				for(int i=0;i<cus_name.length();i++)
				{
					if(isdigit(cus_name[i]))
					{
						valid = 1;
					}	
				}
				
				if(valid == 1)
					cout<<"\n\t\t\t\tInvalid input....\n\t\t\t\tPlease enter again!!!"<<endl;	
			}while(valid == 1);
			
			
			int valid2;
			do
			{
				valid2 = 0;
				fflush(stdin);
				cout<<"\n\t\t\t\tPlease enter your username [only alphabet is acceptable]: ";
				getline(cin,cus_username);
				
				for(int i=0;i<cus_username.length();i++)
				{
					if(isdigit(cus_username[i]))
					{
						valid2 = 1;
					}
				}
					
				if(valid2 == 1)
					cout<<"\n\t\t\t\tInvalid input....\n\t\t\t\tPlease enter again!!!"<<endl;
					
			}while(valid2==1);
			
			
		
			cout<<"\n\t\t\t\tPlease enter you password : ";
			getline(cin>>ws,pass);
			
			int y;
			do{
				y=0;
				cout<<"\n\t\t\t\tPlease enter your NO I/C [without -]: ";
	    		getline(cin,cus_IC);
	    		
	    		for(int x=0;x<cus_IC.length();x++)
	    		{
	    			if(!isdigit(cus_IC[x]))
	    			{
	    				y = 1;
					}
				}
	    		if(cus_IC.length() != 12)
	    		{
	    			y=1;
				}
				
				if(y==1)
				{
					cout<<"\n\t\t\t\tInvalid input....\n\t\t\t\tPlease enter again!!!"<<endl;
				}
			}while(y == 1);
	    	
	    	int z;
	    	do{
	    		z=0;
				cout<<"\n\t\t\t\tPlease enter your contact number [without -]: ";
	    		getline(cin,cus_contact_number);
	
				for(int x=0;x<cus_contact_number.length();x++)
	    		{
	    			if(!isdigit(cus_contact_number[x]))
	    			{
	    				z = 1;
					}
				}
				
	    		if(cus_contact_number.length() < 10 || cus_contact_number.length() > 11 || cus_contact_number[0] != '0')
	    		{
	    			z = 1;
				}
				
				if(z==1)
				{
					cout<<"\n\t\t\t\tInvalid input....\n\t\t\t\tPlease enter again!!!"<<endl;
				}
				
			}while(z == 1);	
	    	
	    	char p;
			do{
				cout<<"\n\t\t\t\tPlease enter your gender [M/F] : ";
	    		cin>>cus_gender;
	    		
	    		p = toupper(cus_gender);
	    		
	    		if( p!= 'M' && p != 'F')
	    		{
	    			cout<<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!"<<endl;
				}
			}while(p != 'M' && p != 'F');
			
			
	    	int ans;
	    	do{
	    		fflush(stdin);
	    		cout<<"\n\t\t\t\tPlease enter your email : ";
    			getline(cin,cus_email);
    			
  				ans = email_validation();
    			
    			if (ans == 1)
				{
        			break;
    			}
    			else
				{
        			cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!"<<endl;
    			}
			}while(ans == 0);
	    	
	    	cout<<"\n\t\t\t\tYour registration is under processing ... ";
	    	sleep(1);
	    	cout<<"\n\n\t\t\t\tRegistration Successful !!! ";
	    	sleep(1);
			
	    	
    		ofstream cusinfo("Customer_Information.txt",ios::app);
    		ofstream logincusinfo("Customer_Login.txt",ios::app);
    		
    		cusinfo<<cus_name<<" "<<cus_IC<<" "<<cus_contact_number<<" "<<cus_gender<<" "<<cus_email<<"\n";
			logincusinfo<<cus_username<<" "<<pass<<"\n";
			
			cusinfo.close();
			logincusinfo.close();	
		}
};

//Display -> Add a payment after user select option 1 from add a payment menu
class addpayment{
	private:
		string cardno,cvv;
		int month,year;
	public:
		void debit_credit()
		{
			cout<<"\n\n\t\t\t\t==================================================";
			cout<<"\n\t\t\t\t    Enter your debit/credit card information";
			cout<<"\n\t\t\t\t==================================================";			
			
			do
			{
				fflush(stdin);
				cout<<"\n\n\t\t\t\tEnter Card No     : ";
				getline(cin,cardno);
				
				if(cardno.length() != 16)
				{
					cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!";
				}
			}while(cardno.length() != 16);
			
			do
			{
				cout<<"\n\t\t\t\tEnter Expiry Date [Month] : ";
				cin>>month;
				cout<<"\n\t\t\t\tEnter Expiry Date [Year] : ";
				cin>>year;
				
				if(month>12 || month<1 && year<18 || year>28) // year>28 becuase maksimum 5 years 2023 + 0005
				{
					cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!"<<endl;
				}
			}while(month>12 || month<1 && year<18 || year>28);		
			
			int cvv_valid;
			do
			{
				cvv_valid = 0;
				fflush(stdin);
				cout<<"\n\t\t\t\tEnter CVV         : ";
				getline(cin,cvv);
				
				if(cvv.length()!=3)
				{
					cout<<"\n\t\t\t\tInvalid CVV...\n\t\t\t\tPlease enter a CVV with only 3 digit!!!"<<endl;
				}
				
				for(int i=0;i<cvv.length();i++)
				{
					if(!isdigit(cvv[i]))
					{
						cvv_valid = 1;
					}
				}
				
				if(cvv_valid == 1)
				{
					cout<<"\n\t\t\t\tInvalid CVV...\n\t\t\t\tPlease enter a valid CVV!!!"<<endl;
				}
				
			}while(cvv.length()!=3 || cvv_valid == 1);
			
			ofstream fout("Debit_Credit.txt",ios::app);
			fout<<cardno<<" "<<month<<" "<<year<<" "<<cvv<<"\n";
			fout.close();
		}
		
		
};



//Display Car Menu
class CarMenu{
	private:
		char opt,u;
	public:
		void select()
		{
			do{
				cout<<"\n\n\t\t\t\tPlease select a car brand : "<<endl;
				cout<<"\n\t\t\t\tEnter 'A' Perodua";
				cout<<"\n\t\t\t\tEnter 'B' Toyota";
				cout<<"\n\t\t\t\tEnter 'C' Honda";
				cout<<"\n\t\t\t\tEnter 'D' BMW";
				cout<<"\n\n\t\t\t\t-----------------------------------------------";
				cout<<"\n\t\t\t\tChoose a Car from the above options : ";
				cin>>opt;
				
				u = toupper(opt);

				if(u != 'A' && u != 'B' && u != 'C' && u != 'D' )
				{
					cout<<"\n\n\t\t\t\tInvalid choice!!!!!";
					cout<<"\n\t\t\t\tPlease enter again......";
					sleep(1);
				}
				
				system("CLS");
				
			}while(u != 'A' && u != 'B' && u != 'C' && u != 'D' );
		}
		
		void FavouMenu()
		{
			cout<<"\n\t\t\t\t-----------------------------------------------";
			cout<<"\n\t\t\t\t| Name               : "<<CD.carname;
			cout<<"\n\t\t\t\t| Number Plate       : "<<CD.noplate;
			cout<<"\n\t\t\t\t| Class              : "<<CD.clas;
			cout<<"\n\t\t\t\t| Color              : "<<CD.color;
			cout<<"\n\t\t\t\t| Capacity           : "<<CD.capacity;
			cout<<"\n\t\t\t\t| Year of Production : "<<CD.year<<endl;
			cout<<"\n\t\t\t\t| Car Code           : "<<CD.carcode;
			cout<<"\n\t\t\t\t| Price per day      : RM "<<fixed<<setprecision(2)<<CD.price;
			cout<<"\n\t\t\t\t-----------------------------------------------"<<endl;
			sleep(1);
		}	
		
		void getinput()
		{
			int carcode_valid,ren_day,ren_month,ren_year,ret_day,ret_month,ret_year;
			string carcode,status;
			
			do
			{
				ifstream fin1,fin2;
				
				fflush(stdin);
				cout<<"\n\t\t\t\tEnter the Car Code : ";
				getline(cin,CD.carcode);
				
				fin1.open("CarMenu.txt");
				
				if(!fin1)
					cout<<"File CarMenu cannot open ... ";
				else
				{
					while(fin1)
					{
						fin1>>CD2.carname>>CD2.noplate>>CD2.clas>>CD2.color>>CD2.capacity>>CD2.year>>CD2.carcode>>CD2.price;
						
						if(CD.carcode == CD2.carcode)
						{
							carcode_valid = 0;
							break;
						}
						
						else
						{
							carcode_valid = 1;
						}
					}
				
					if(carcode_valid == 1)
						cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!"<<endl;
				}
				
				
				fin1.close();
				
			}while(carcode_valid == 1);
		}
		
		void Menu()
		{	
			ifstream menuP,menuT,menuH,menuB;
			
			cout<<"\n\t\t\t\t======================================================";
			cout<<"\n\t\t\t\t             Choose your favourtie car";
			cout<<"\n\t\t\t\t======================================================";
			
			if(u == 'A')
			{
				menuP.open("Perodua.txt");
				
				if(!menuP)
				{
					cout<<"File Perodua could not open!"<<endl;
					exit(1);
				}
				else
				{	
					CD.brand = "Perodua";
					cout<<"\n\t\t\t\tCar Brand : "<<CD.brand<<endl;	
					
					menuP>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;
					while(menuP)
					{	
						FavouMenu();
						menuP>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;
					}
				}	
			}
			
			else if(u == 'B')
			{
				menuT.open("Toyota.txt");
				
				if(!menuT)
				{
					cout<<"File Toyota could not open!"<<endl;
				}
				else
				{
					CD.brand = "Toyota";
					cout<<"\n\t\t\t\tCar Brand : "<<CD.brand<<endl;
					
					menuT>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;	
					while(menuT)
					{
							
						FavouMenu();
						menuT>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;		
					}
				}	
			}
			
			else if(u == 'C')
			{
				menuH.open("Honda.txt");
				
				if(!menuH)
				{
					cout<<"File Honda could not open!"<<endl;
				}
				else
				{
					CD.brand = "Honda";
					cout<<"\n\t\t\t\tCar Brand : "<<CD.brand<<endl;	
									
					menuH>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;	
					while(menuH)
					{

						FavouMenu();
						menuH>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;		
					}
				}	
			}
			
			else if(u == 'D')
			{
				menuB.open("BMW.txt");
				
				if(!menuB)
				{
					cout<<"File BMW could not open!"<<endl;
				}
				else
				{
					CD.brand = "BMW";
					cout<<"\n\t\t\t\tCar Brand : "<<CD.brand<<endl;
						
					menuB>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;	
					while(menuB)
					{
						
						FavouMenu();
						menuB>>CD.carname>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price;		
					}
				}	
			}
			
				menuP.close();
				menuT.close();
				menuH.close();
				menuB.close();			
			}
			
	friend class MainSelect2;
};

class Booking{
	public:
		void user_book()
		{
			cout<<"\n\t\t\t\tHow many days you want to rent? : ";
			cin>>d1.rdays;
			time_t currTime;
			tm* currTm;
			int invalid;
			bool checkd,checkm,checky,input;
			char currentdate[100];
			int count=2;
			time(&currTime);
		    currTm = localtime(&currTime);
		    strftime(currentdate, 50, "%d %m %Y", currTm);
		    
		    fstream fout("date.txt",ios::out);
			fout<<currentdate<<"\n";
			fout.close();
			
			fstream fin("date.txt", ios::in);
			if(fin.fail())
			{
				cout<<"The file could not be opened!";
				exit(1);
			}
			else
			{
				while(fin>>d2.day>>d2.month>>d2.year)
				{	
				}
				do
				{
					cout<<"\n\t\t\t\tEnter the date you want to pick up the car [dd mm yyyy] : ";
					cin>>d1.day>>d1.month>>d1.year;
					if(d1.day>31 || d1.month>12)
					{
						input=false;
					
					}
					else
					{
						input=true;
						if(d1.month==4 || d1.month==6 || d1.month==9 || d1.month==11)
						{
							
							if(d1.day>30)
							{
								input=false;
							}
							else 
							{
								input=true;
							}
						}
						else if(d1.month==1 || d1.month==3 || d1.month==5 || d1.month==7 || d1.month==8 || d1.month==10 || d1.month==12)
						{
							if(d1.day>31)
							{
								input=false;
							}
							else 
							{
								input=true;
							}
						}
					}
					
					while(input==false)
					{
						
						cout<<"\n\t\t\t\tYou entered invalid date please enter again!"<<endl;
						sleep(1);
						cout<<"\n\n\t\t\t\tEnter the date you want to pick up the car [dd mm yyyy] : ";
						cin>>d1.day>>d1.month>>d1.year;
						
						if(d1.month==4 || d1.month==6 || d1.month==9 || d1.month==11)
						{
							
							if(d1.day>30)
							{
								input=false;
							}
							else 
							{
								input=true;
							}
						}
						else if(d1.month==1 || d1.month==3 || d1.month==5 || d1.month==7 || d1.month==8 || d1.month==10 || d1.month==12)
						{
							if(d1.day>31)
							{
								input=false;
							}
							else 
							{
								input=true;
							}
						}
					}
						
					if(d1.month==2)
					{
						if(d1.year/4>=506 && d1.year/4<=749) //2024 ~ 2996
						{
							while(d1.day>29)
							{
								cout<<"\n\t\t\t\tYou entered invalid date please enter again!"<<endl;
								sleep(1);
								cout<<"\n\t\t\t\tEnter the date you want to pick up the car [dd mm yyyy] : ";
								cin>>d1.day>>d1.month>>d1.year;
							}
						}
						else
						{
							while(d1.day>28)
							{
								cout<<"\n\t\t\t\tYou entered invalid date please enter again!"<<endl;
								sleep(1);
								cout<<"\n\t\t\t\tEnter the date you want to pick up the car [dd mm yyyy] : ";
								cin>>d1.day>>d1.month>>d1.year;
							}
						}
					}
					
					if(d1.day>=d2.day)
					{
						checkd=true;
					}
					else{
						checkd=false;
					}
					if(d1.month>=d2.month)
					{
						checkm=true;
						if(d1.month>d2.month)
							checkd = true;
					}
					else{
						checkm=false;
					}
					if(d1.year>=d2.year)
					{
						checky=true;
					
						if(d1.year>d2.year)
						{
							checkd=true;
							checkm=true;		
						}	
					}
					else
					{
						checky=false;
					}
					if(checkd==true && checkm==true && checky==true)
					{
						invalid=1;
						cout<<"\n\t\t\t\tBook successful ..."<<endl;
						sleep(1);
						cout<<"\n\t\t\t\tYour pick up date is : "<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<endl;
						sleep(1);
					}
				
					else if(checkd==false || checkm==false || checky==false)
					{
						invalid=0;
						cout<<"\n\t\t\t\tInvalid date you entered"<<endl;
						sleep(1);
					
					}
					
				}while(invalid==0);
				if(d1.day+d1.rdays>30 || d1.day+d1.rdays>31)
				{
					if(d1.month==4 || d1.month==6 || d1.month==8 || d1.month==10 || d1.month==12)
					{
						d3.day=d1.day+d1.rdays-31-1;
					}
					if(d1.month==1 || d1.month==3 || d1.month==5 || d1.month==7 || d1.month==9 || d1.month==11)
					{
						d3.day=d1.day+d1.rdays-30-1;
					}
					d3.month=d1.month+1;
					if(d3.month>12)
					{
						
						d3.year=d1.year+1;
						d3.month=d3.month-12;	
					}
					else
					{
						d3.year=d1.year;
						d3.day=d1.rdays-1;
						d3.month=d1.month;
					
					}
						
				}
				
				if(d1.day+d1.rdays>28)
				{
					if(d1.month==2)
					{
						d3.day=d1.day+d1.rdays-28-1;
						d3.month=d1.month+1;
						d3.year=d1.year;
					}
					if(d1.year/4>=506 && d1.year/4<=749) //2024 ~ 2996
					{
						if(d1.day+d1.rdays>29)
						{
							if(d1.month==2)
							{
								d3.day=d1.day+d1.rdays-29-1;
								d3.month=d1.month+1;
								d3.year=d1.year;
							}
						}
					}
				}
				else
				{
					d3.day=d1.day+d1.rdays-1;
					d3.month=d1.month;
					d3.year=d1.year;
				}
				
				if(invalid!=0)
				{
					cout<<"\n\t\t\t\tYour drop off date is : "<<d3.day<<"/"<<d3.month<<"/"<<d3.year<<endl;
					system("Pause");
				}
			}
			
		fin.close();	
	}
	
	friend class MainSelect2;
};


//Display -> when user select option 2 from main menu
class MainSelect2:public addpayment{
	private:
		string opt,login_username,username,password,pw;
		CarMenu cm2;
		Booking book2;
	public:
		void addpay()
		{
			string opt2;
			do
			{
				cout<<"\n\n\t\t\t\t==================================================";
				cout<<"\n\t\t\t\t\t\tAdd a Peyment Method";
				cout<<"\n\t\t\t\t==================================================";
				cout<<"\n\n\t\t\t\t1. Debit/Credit Card";
				cout<<"\n\n\t\t\t\t2. Back to Login Page";
				cout<<"\n\n\t\t\t\tEnter your selection : ";
				cin>>opt;
				
				if(opt == "1")
				{
					system("CLS");
					debit_credit();
					cout<<"\n\t\t\t\tProcessing ... ...";
					sleep(1);
					cout<<"\n\n\t\t\t\tYou have successfully adding a payment method!";
					cout<<"\n\n\t\t\t\tEnter [1] back to login menu else to exit : ";
					getline(cin,opt2);
					if(opt2 == "1")
					{
						system("CLS");
						login();
					}
					else
					{
						system("CLS");                                                                             
						exit(1);
					}
				}
				else if(opt == "2")
				{
					system("CLS");
					login();
				}
				else
				{
					opt = "3";
					cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!";
					sleep(1);
					system("CLS");
				}	
			}while(opt == "3");
		}
		
		void Calculation()
		{	
			CD.total = CD2.price * d1.rdays;			
		}
		
	void makepayment()
	{
		string cardnum,cvv,cardno,cvv2;
		int exp_month,exp_year,month,year;
		int i;
		string opt;
		MainSelect2 ms2;
				
		do
		{
			ifstream fin("Debit_Credit.txt");
				
			fflush(stdin);
			cout<<"\n\t\t\t\tPlease enter your Debit/Credit Card Number : ";
			getline(cin,cardnum);
					
			cout<<"\n\t\t\t\tEnter Expiry Date [Month] : ";
			cin>>exp_month;
								
			cout<<"\n\t\t\t\tEnter Expiry Date [Year] : ";
			cin>>exp_year;
					
			fflush(stdin);
			cout<<"\n\t\t\t\tEnter CVV : ";
			getline(cin,cvv);
					
			if(!fin)
			{
				//cout<<"File cannot open...";
				cout<<"\n\t\t\t\tYou must add a payment method before rental ! ";
				sleep(1);
				cout<<"\n\n\t\t\t\tEnter [1] to continue else go to add new payment page : ";
				getline(cin,opt);	
					
				if(opt == "1")
				{
					i = 2;
					continue;			
				}
				else
				{
					system("CLS");
					ms2.debit_credit();
				}
							
			}
			else
			{
				while(fin>>cardno>>month>>year>>cvv2)
				{
					if(cardnum == cardno && exp_month == month && exp_year == year && cvv == cvv2)
					{
						i = 1;
						cout<<"\n\t\t\t\tYour payment is under processing ...";
						sleep(2);
						cout<<"...";
						sleep(1);
						cout<<"\n\n\t\t\t\tThe payment is successful!"<<endl;
						sleep(1);
						system("CLS");
						break;			
					}
					else
					{
						i = 2;
					}
								
				}
						
				if(i == 2)
				{
					cout<<"\n\t\t\t\tYour inputs are not valid...\n\t\t\t\tPlease enter again!!! ";
					sleep(1);
					cout<<"\n\t\t\t\tYou must add a payment method before rental ! ";
					sleep(1);
					cout<<"\n\n\t\t\t\tEnter [1] to continue else go to login page : ";
					getline(cin,opt);	
							
					if(opt == "1")
					{
						continue;
					}
					else
						ms2.login();		
						break;
					}
				}
							
					fin.close();
					
		}while(i == 2);		
	}
		
		//Display Invoice
		void InvoiceDetails()
		{	
			string name;
			
			int valid;
			do
			{
				system("CLS");
				valid = 0;
				fflush(stdin);
				cout<<"\n\t\t\t\tPlease enter your name : ";
				getline(cin,inv.name);
				
				for(int i=0;i<name.length();i++)
				{
					if(isdigit(name[i]))
					{
						valid = 1;
					}	
				}
						
				if(valid == 1)
					cout<<"\n\t\t\t\tInvalid input....\n\t\t\t\tPlease enter again!!!"<<endl;	
					
			}while(valid == 1);
			
			system("CLS");
			
			cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
			cout << "\t\t	/////////////////////////////////////////////////////////////////////"<<endl;
			cout << "\t\t	| Name               : "<<"-----------------| "<<inv.name<<endl;
			cout << "\t\t	| Car Code           : "<<"-----------------| "<<CD2.carcode<<endl;
			cout << "\t\t	| Car Model          : "<<"-----------------| "<<CD.brand<<" "<<CD2.carname<<endl;
			cout << "\t\t	| Car Class          : "<<"-----------------| "<<CD2.clas<<endl;
			cout << "\t\t	| Car Color          : "<<"-----------------| "<<CD2.color<<endl;
			cout << "\t\t	| Car Capacity       : "<<"-----------------| "<<CD2.capacity<<endl;
			cout << "\t\t	| Year of Production : "<<"-----------------| "<<CD2.year<<endl;
			cout << "\t\t	| Car No.            : "<<"-----------------| "<<CD2.noplate<<endl;
			cout << "\t\t	| Number of days     : "<<"-----------------| "<<d1.rdays<<"("<<CD2.price<<")"<<endl;
			cout << "\t\t	| Pick up days       : "<<"-----------------| "<<d1.day<<"/"<<d1.month<<"/"<<d1.year<<endl;
			cout << "\t\t	| Drop off days      : "<<"-----------------| "<<d3.day<<"/"<<d3.month<<"/"<<d3.year<<endl;
			cout << "\t\t	| Venue              : "<<"-----------------| Plaza Melaka Sentral, 75350 Malacca"<<endl;
			cout << "\t\t	 _____________________________________________________________"<<endl;
			cout <<"\n";
			cout << "\t\t	| Total Rental Amount is :"<<"--------------| RM"<<fixed<<setprecision(2)<<CD.total<<endl;
			cout << "\t\t	 _____________________________________________________________"<<endl;
			cout << "\t\t	 # This is a computer generated invoce and it does not"<<endl;
			cout << "\t\t	 require an authorised signature #"<<endl;
			cout <<" "<<endl;
			cout << "\t\t	/////////////////////////////////////////////////////////////////////"<<endl;		
		}
		
		void login()
		{	
			string selection,check;
			
			do
			{
				system("CLS");
				cout<<"\n\n\t\t\t\t==============================================";
				cout<<"\n\t\t\t\t\t\tLogin Menu";
				cout<<"\n\t\t\t\t==============================================";
				cout<<"\n\n\t\t\t\t1. Add a payment method";
				cout<<"\n\n\t\t\t\t2. Rental a car";
				cout<<"\n\n\t\t\t\t3. Log Out";
				cout<<"\n\n\t\t\t\t(Reminder : You must add a payment before rental a car else u cannot make a payment...)";
				fflush(stdin);
				cout<<"\n\n\t\t\t\tEnter your selection : ";
				getline(cin,selection);
				
				
				if(selection == "1")
				{
					system("CLS");
					addpay();
				}
				else if(selection == "2")
				{
					system("CLS");
					cm2.select(); //friend
					cm2.Menu();   //friend
					cm2.getinput(); // friend
					book2.user_book();//friend
					Calculation();
					InvoiceDetails();
					cout<<"\n\t\t\t\tPlease check your invoice details ...";
					cout<<"\n\t\t\t\tEnter [1] to confirm your purchasement else back to login page :";	
					getline(cin>>ws,check);
					if(check == "1")
					{
						makepayment();
					}
					else
					{
						login();
					}
					
				}
				else if(selection == "3")
				{
					exit(1);
				}
				else
				{
					selection = "4";
				}
				
				if(selection == "4")
				{
					cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!";
					sleep(1);
					system("CLS");
				}
				
			}while(selection == "4");	
		}
		
		void logincheck()
		{
			int error;
			MainSelect1 ms1;
			do
			{	
				system("CLS");
				cout<<"\n\n\t\t\t\t==============================================";
				cout<<"\n\t\t\t\t\t\tLogin";
				cout<<"\n\t\t\t\t==============================================";
				
				fflush(stdin);
				cout<<"\n\n\t\t\t\t\tPlease enter your username : "<<endl;
				cout<<"\n\t\t\t\t\t";
				getline(cin,login_username);
				
				cout<<"\n\n\t\t\t\t\tPlease enter your password : "<<endl;
				cout<<"\n\t\t\t\t\t";
				getline(cin>>ws,password);
			
				ifstream cuslogin;
				cuslogin.open("Customer_Login.txt");
				
				if(!cuslogin)
				{
					//cout<<"\n\n\t\t\t\tFile Customer_Login cannot open...";
					cout<<"\n\t\t\t\tYou must register before login ! ";
					sleep(1);
					cout<<"\n\n\t\t\t\tEnter [1] to continue else go to Registration Page : ";
					getline(cin,opt);	
						
					if(opt == "1")
					{
						error = 1;
						system("CLS");
						continue;
						
					}
					else
					{
						system("CLS");
						ms1.registration();
					}
				}
				else
				{
					while(cuslogin>>username>>pw)
					{
						if(login_username == username && password == pw)
						{
							error = 0;
							cout<<"\n\t\t\t\tLogin Successful ... ";
							sleep(1);
							system("CLS");
							login();
							break;
						}
						else
						{
							error = 1;
						}	
					}
					
					
					if(error == 1)
					{
						cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!";
						sleep(1);
						cout<<"\n\t\t\t\tYou must register before login ! ";
						sleep(1);
						cout<<"\n\n\t\t\t\tEnter [1] to continue else go to Registration Page : ";
						getline(cin,opt);	
							
						if(opt == "1")
						{
							error = 1;
							system("CLS");
							continue;
							
						}
						else
						{
							system("CLS");
							ms1.registration();
						}	
						system("CLS");
					}
				}
				
				cuslogin.close();
					
			}while(error == 1);	
	}
	
};


//Admin
class Admin: public CarMenu{
private:
	string carname, noplate, clas, color, capacity, year, carcode, brand, admin_username, username, pw, password, opt;
	double price;	
	int car, i, count_d, validate;
	string code, brand_car, inbrand;
	
public:
	string car_name[];
	void setcar()
	{
		
		cout<<"\n\t\t\t\tEnter car name   :";
		getline(cin>>ws,carname);
		
		cout<<"\n\t\t\t\tEnter No plate   :";
		getline(cin>>ws,noplate);
		
		cout<<"\n\t\t\t\tEnter class      :";
		getline(cin>>ws,clas);
		
		cout<<"\n\t\t\t\tEnter color      :";
		getline(cin>>ws,color);
		
		cout<<"\n\t\t\t\tEnter capacity   :";
		getline(cin>>ws,capacity);
		
		cout<<"\n\t\t\t\tEnter year       :";
		getline(cin>>ws,year);
		
		cout<<"\n\t\t\t\tEnter car code   :";
		getline(cin>>ws,carcode);
		
		cout<<"\n\t\t\t\tEnter price      : RM ";
		cin>>price;
	}
	
	void honda()
	{
		fstream fout("Honda.txt",ios::app);
		setcar();
		fout<<"\n"<<carname<<" "<<noplate<<" "<<clas<<" "<<color<<" "<<capacity<<" "<<year<<" "<<carcode<<" "<<price;
		fout.close();
	}
	
	void perodua()
	{
		fstream fout("Perodua.txt",ios::app);
		setcar();
		fout<<"\n"<<carname<<" "<<noplate<<" "<<clas<<" "<<color<<" "<<capacity<<" "<<year<<" "<<carcode<<" "<<price;
		fout.close();
	}
	
	void bmw()
	{
		fstream fout("BMW.txt",ios::app);
		setcar();
		fout<<"\n"<<carname<<" "<<noplate<<" "<<clas<<" "<<color<<" "<<capacity<<" "<<year<<" "<<carcode<<" "<<price;
		fout.close();
	}
	
	void toyota()
	{
		fstream fout("Toyota.txt",ios::app);
		setcar();
		fout<<"\n"<<carname<<" "<<noplate<<" "<<clas<<" "<<color<<" "<<capacity<<" "<<year<<" "<<carcode<<" "<<price;
		fout.close();
	}
	
	void admincheck()
	{
		int error;
		do
		{
			cout<<"\n\n\t\t\t\t==============================================";
			cout<<"\n\t\t\t\t\t\tLogin";
			cout<<"\n\t\t\t\t==============================================";
			fflush(stdin);
			cout<<"\n\n\t\t\t\t\tPlease enter your username : "<<endl;
			cout<<"\n\t\t\t\t\t";
			getline(cin,admin_username);
			
			cout<<"\n\n\t\t\t\t\tPlease enter your password : "<<endl;
			cout<<"\n\t\t\t\t\t";
			getline(cin,password);
			
			ifstream admlogin;
			admlogin.open("Admin.txt");
				
			if(!admlogin)
			{
				cout<<"\n\n\t\t\t\tFile Admin cannot open...";
				exit(1);
			}
			else
			{
				while(admlogin>>username>>pw)
				{
					if(admin_username == username && password == pw)
					{
						error = 0;
						cout<<"\n\t\t\t\tLogin Successful ... ";
						system("CLS");
						break;
					}
					else
					{
						error = 1;
					}	
				}
							
				if(error == 1)
				{
					cout <<"\n\t\t\t\tInvalid input...\n\t\t\t\tPlease enter again!!!";
					sleep(1);	
					system("CLS");
				}
			}
				
				admlogin.close();
					
			}while(error == 1);	
	}
	
	void addadmin()
	{		
		cout<<"\n\n\t\t\t\t==============================================";
		cout<<"\n\t\t\t\t\t\tAdd a new Admin";
		cout<<"\n\t\t\t\t==============================================";
		
		fflush(stdin);
		cout<<"\n\n\t\t\t\t\tPlease enter new admin's username : "<<endl;
		cout<<"\n\t\t\t\t\t";
		getline(cin,admin_username);
			
		cout<<"\n\n\t\t\t\t\tPlease enter new admin's password : "<<endl;
		cout<<"\n\t\t\t\t\t";
		getline(cin,password);
			
		ofstream admwrite;
		admwrite.open("Admin.txt",ios::app);
		admwrite<<"\n"<<admin_username<<" "<<password;	
		admwrite.close();
		
		cout<<"\n\t\t\t\tYou have successful added a new admin!"<<endl;	
		
	}
	
	void carmenu()
	{
		fstream fout("CarMenu.txt",ios::app);
		fout<<"\n"<<carname<<" "<<noplate<<" "<<clas<<" "<<color<<" "<<capacity<<" "<<year<<" "<<carcode<<" "<<price;
		fout.close();
	}
	
	void addcar()
	{
		string choice;
		
		do
		{
			cout<<"\n\n\t\t\t\t==============================================";
			cout<<"\n\t\t\t\t\t\tAdd a car";
			cout<<"\n\t\t\t\t==============================================";
			cout<<"\n\n\t\t\t\tWhat brand of car do you want to add?   :";
			getline(cin,brand);
			
			while(brand!="Honda" && brand!="Perodua" && brand!="BMW" && brand!="Toyota")
			{
				cout<<"\n\t\t\t\tInvalid brand you entered please enter again!"<<endl;
				cout<<"\n\t\t\t\tWhat brand of car do you want to add?   :";
				getline(cin>>ws, brand);
			}
			if(brand=="Honda")
			{
				honda();
				carmenu();
			}
			else if(brand=="Perodua")
			{
				perodua();
				carmenu();
			}
			else if(brand=="BMW")
			{
				bmw();
				carmenu();
			}
			else if(brand=="Toyota")
			{
				toyota();
				carmenu();
			}
			
		}while(choice == "1");
	}
	
	void showinvoice()
	{
		int day=0,day2=0,month=0,month2=0,year=0,year2=0,rdays=0;
		string opt;
		
		cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
		ifstream invoice;
		invoice.open("Invoice.txt");
		
		if(!invoice)
		{
			cout<<"File invoice cannot open ... ";
			exit(1);
		}
		else
		{	
			invoice>>CD3.carcode>>CD3.brand>>CD3.carname>>CD3.clas>>CD3.color>>CD3.capacity>>CD3.year>>CD3.noplate>>rdays>>day>>month>>year>>day2>>month2>>year2>>CD3.total;
			getline(invoice,CD3.name);
			
			while(invoice)
			{	
				cout << "\t\t	/////////////////////////////////////////////////////////////////////"<<endl;
				cout << "\t\t	| Name               : "<<"-----------------|"<<CD3.name<<endl;
				cout << "\t\t	| Car Code           : "<<"-----------------| "<<CD3.carcode<<endl;
				cout << "\t\t	| Car Model          : "<<"-----------------| "<<CD3.brand<<" "<<CD3.carname<<endl;
				cout << "\t\t	| Car Class          : "<<"-----------------| "<<CD3.clas<<endl;
				cout << "\t\t	| Car Color          : "<<"-----------------| "<<CD3.color<<endl;
				cout << "\t\t	| Car Capacity       : "<<"-----------------| "<<CD3.capacity<<endl;
				cout << "\t\t	| Year of Production : "<<"-----------------| "<<CD3.year<<endl;
				cout << "\t\t	| Car No.            : "<<"-----------------| "<<CD3.noplate<<endl;
				cout << "\t\t	| Number of days     : "<<"-----------------| "<<rdays<<endl;
				cout << "\t\t	| Pick up days       : "<<"-----------------| "<<day<<"/"<<month<<"/"<<year<<endl;
				cout << "\t\t	| Drop off days      : "<<"-----------------| "<<day2<<"/"<<month2<<"/"<<year2<<endl;
				cout << "\t\t	 _____________________________________________________________"<<endl;
				cout << "\n";
				cout << "\t\t	| Total Rental Amount is :"<<"--------------| RM"<<fixed<<setprecision(2)<<CD3.total<<endl;
				cout << "\t\t	 _____________________________________________________________"<<endl;
				cout << "\t\t	/////////////////////////////////////////////////////////////////////"<<endl<<endl;
				
				system("Pause");
				system("CLS");
				
				invoice>>CD3.carcode>>CD3.brand>>CD3.carname>>CD3.clas>>CD3.color>>CD3.capacity>>CD3.year>>CD3.noplate>>rdays>>day>>month>>year>>day2>>month2>>year2>>CD3.total;
				getline(invoice,CD3.name);
			}
		}
		
		invoice.close();
		
	}
	void deletecar()
	{
		int count=0;
		string choice, car_type;
		
		string line;
		ifstream carbrand;
		
		cout<<"\n\n\t\t\t\t==============================================";
		cout<<"\n\n\t\t\t\t\t\tDelete a car";
		cout<<"\n\n\t\t\t\t==============================================";
		carbrand.open("Car Brand.txt");
		if(!carbrand)
		{
			cout<<"Could't open file\n";
		}
		else
		{
			
			while(getline(carbrand, line))
			{
				count++;
				cout<<"\n\t\t\t\tEnter "<<count<<" for "<<line;
			}
		
		}
		carbrand.close();
	
		do
		{
			cout<<"\n\n\t\t\t\tWhich car brand do you want to choose?   :";
			cin>>car;
			
			while(car != 1 && car != 2 && car != 3 && car != 4 )
			{
				cout<<"\n\t\t\t\tInvalid brand you entered please enter again!"<<endl;
				cout<<"\n\t\t\t\tWhat brand of car do you want to delete?   :";
				cin>>car;
			}
			if(car==1)
			{
				brand="Perodua.txt";
				inbrand="inPerodua.txt";
				dtcardetails();
				delcar_1();
				delcar_2();	
			}
			else if(car==2) 
			{
				brand="Toyota.txt";
				inbrand="inToyota.txt";
				dtcardetails();
				delcar_1();
				delcar_2();		
			}
			else if(car==3) 
			{
				brand="Honda.txt";
				inbrand="inHonda.txt";
				dtcardetails();
				delcar_1();
				delcar_2();		
			}
			else if(car==4) 
			{
				brand="BMW.txt";
				inbrand="inBMW.txt";
				dtcardetails();
				delcar_1();
				delcar_2();	
			}
		
			
		}while(choice == "4");
		
	}
	
	void dtcardetails()
	{
		
		i=0;
		count_d=0;
	
		ifstream menu_P,menuT,menuH,menuB;
		
			if(car ==1)
			{
				menu_P.open("Perodua.txt");
				
				if(!menu_P)
				{
					cout<<"File Perodua could not open!"<<endl;
					exit(1);
				}
				else
				{	
					
					while(menu_P>>car_name[i]>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price)
					{	
						cout<<"\n\t\t\t\tCar Name: "<<car_name[i];
						i++;
						count_d++;
					}
					
					cout<<endl;
					
					fflush(stdin);
					
					
				}
				
			}
			else if(car ==2)
			{
				menuT.open("Toyota.txt");
				
				if(!menuT)
				{
					cout<<"File Toyota could not open!"<<endl;
				}
				else
				{
					
					while(menuT>>car_name[i]>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price)
					{	
						cout<<"\n\t\t\t\tCar Name: "<<car_name[i];
						i++;
						count_d++;
					}
					
					cout<<endl;
					
					fflush(stdin);
					
				}	
			}
			else if(car ==3)
			{
				menuH.open("Honda.txt");
				
				if(!menuH)
				{
					cout<<"File Honda could not open!"<<endl;
				}
				else
				{
					while(menuH>>car_name[i]>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price)
					{	
						cout<<"\n\t\t\t\tCar Name: "<<car_name[i];
						i++;
						count_d++;
					}
					
					cout<<endl;
					
					fflush(stdin);
					
				}	
			}
			else if(car ==4)
			{
				menuB.open("BMW.txt");
				
				if(!menuB)
				{
					cout<<"File BMW could not open!"<<endl;
				}
				else
				{
					while(menuB>>car_name[i]>>CD.noplate>>CD.clas>>CD.color>>CD.capacity>>CD.year>>CD.carcode>>CD.price)
					{	
						cout<<"\n\t\t\t\tCar Name: "<<car_name[i];
						i++;
						count_d++;
					}
					
					cout<<endl;
					
					fflush(stdin);
					
				}	
			}
			
						
		
		
		menu_P.close();
		menuT.close();
		menuH.close();
		menuB.close();	
		
	}
	
	void delcar_1()
	{
		int a=0, validate=0;
		string d_carname, d_noplate, d_class, d_color, d_capacity, d_year, d_carcode, d_price, line;
		
		
		
		fstream fo1("CarMenu.txt", ios::in | ios::out);
		fstream fo2("inCarMenu.txt", ios::out);
		
		if(!fo1)
		{
			cout<<"Could not open file CarMenu!"<<endl;
		}
		
			fflush(stdin);
			cout<<"\n\t\t\t\tWhich car do you want to delete? (Type car name) : ";
			getline(cin, code);
			
			
		
							
							while(fo1>>d_carname>>d_noplate>>d_class>>d_color>>d_capacity>>d_year>>d_carcode>>d_price)
							{
								
								
								if(code == d_carname)
								{
									
									validate++;
									
								}
								else 
								{
									fflush(stdin);
									fo2<<d_carname<<" "<<d_noplate<<" "<<d_class<<" "<<d_color<<" "<<d_capacity<<" "<<d_year<<" "<<d_carcode<<" "<<d_price<<endl;
									
								}
								
							}
							
							
							fo1.close();
							fo2.close();
							remove("CarMenu.txt");
							
							
							ifstream fo_2("inCarMenu.txt");
							ofstream ed_fo1;
							ed_fo1.open("CarMenu.txt");
							
							
						
							
							while(fo_2>>d_carname>>d_noplate>>d_class>>d_color>>d_capacity>>d_year>>d_carcode>>d_price)
							{
								fflush(stdin);
								
								ed_fo1<<d_carname<<" "<<d_noplate<<" "<<d_class<<" "<<d_color<<" "<<d_capacity<<" "<<d_year<<" "<<d_carcode<<" "<<d_price<<endl;
								
							}
							fo_2.close();
							remove("inCarMenu.txt");
						
						
						
						
						if(validate==1)
						{
							cout<<"\n\t\t\t\tProceeding";
							for(int b=0; b<3; b++)
							{
								sleep(1);
								cout<<".";
							}
							cout<<endl;
						}
						else
						{
							cout<<"\n\t\t\t\tThere is an error while deleting a car."<<endl;
						}
						ed_fo1.close();
	}
					
	
	void delcar_2()
	{
		string d_carname, d_noplate, d_class, d_color, d_capacity, d_year, d_carcode, d_price;
		validate=0;
		
		fstream fo_1(brand.c_str(), ios::in | ios::out);
		fstream fo_2(inbrand.c_str(), ios::out);
		if(!fo_1)
		{
			cout<<"Could not open file CarMenu!"<<endl;
		}
	
		fflush(stdin);
			while(fo_1>>d_carname>>d_noplate>>d_class>>d_color>>d_capacity>>d_year>>d_carcode>>d_price)
			{
								
								
				if(code == d_carname)
				{
					
					validate++;
					
				}
				else 
				{
					fflush(stdin);
					fo_2<<d_carname<<" "<<d_noplate<<" "<<d_class<<" "<<d_color<<" "<<d_capacity<<" "<<d_year<<" "<<d_carcode<<" "<<d_price<<endl;
					
				}
								
			}
							
		fo_1.close();
		fo_2.close();
		remove(brand.c_str());
							
							
		ifstream info_2(inbrand.c_str());
		ofstream ed_fo1;
		ed_fo1.open(brand.c_str());
			while(info_2>>d_carname>>d_noplate>>d_class>>d_color>>d_capacity>>d_year>>d_carcode>>d_price)
			{
				fflush(stdin);
				
				ed_fo1<<d_carname<<" "<<d_noplate<<" "<<d_class<<" "<<d_color<<" "<<d_capacity<<" "<<d_year<<" "<<d_carcode<<" "<<d_price<<endl;
								
			}
			info_2.close();
			remove(inbrand.c_str());
					
		if(validate==1)
		{
			cout<<"\n\t\t\t\tYou have delete a car from list."<<endl;
		}
		else
		{
			cout<<"\n\t\t\t\tThere is an error while deleting a car."<<endl;
		}
		ed_fo1.close();
		
		
	}
			
	string admin()
	{
		string opt;
		int count;
		
		do
		{
			count = 0;
			opt = "0";
			cout<<"\n\n\t\t\t\t==============================================";
			cout<<"\n\t\t\t\t\t\tAdmin Page";
			cout<<"\n\t\t\t\t==============================================";
			cout<<"\n\n\t\t\t\t1. Add a new Admin";
			cout<<"\n\n\t\t\t\t2. Add car Record";
			cout<<"\n\n\t\t\t\t3. Show Invoice Summary";
			cout<<"\n\n\t\t\t\t4. Delete car records";
			cout<<"\n\n\t\t\t\t5. Back to Main Menu";
			cout<<"\n\n\t\t\t\tEnter your selection : ";
			getline(cin,opt);
			
			if(opt != "1" && opt != "2" && opt!= "3" && opt != "4" && opt != "5")
			{
				count = 1;
			}
			
			if(count == 1)
			{
				cout<<"\n\t\t\t\tInvalid choice!!!!!";
				cout<<"\n\t\t\t\tPlease enter again......";
				sleep(1);
				system("CLS");
			}
		}while(count == 1);
		
		return opt;
	}
};

//DIsplay main menu
class MainMenu:public MainSelect1, public MainSelect2,public Admin{
	private:
		string choice,opt,thank;
	public:
		void main_menu()
		{
			string select,opt2;
			
			do
			{
				
				cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tCAR RENTAL SYSTEM \n\n";
				cout<<"\t\t\t\t==============================================";
				cout<<"\n\t\t\t\t\t\tMAIN MENU";
				cout<<"\n\t\t\t\t==============================================";
				cout<<"\n\n\t\t\t\t1. Registration";
				cout<<"\n\n\t\t\t\t2. Login";
				cout<<"\n\n\t\t\t\t3. Admin";
				cout<<"\n\n\t\t\t\t4. Exit";
				fflush(stdin);
				cout<<"\n\n\t\t\t\tEnter your selection : ";
				getline(cin,choice);
				
				
				if(choice == "1")
				{
					system("CLS");
					registration();
					cout<<"\n\n\t\t\t\tEnter [1] back to main menu else to exit : ";
					getline(cin,opt);
					
					if(opt == "1")
					{
						system("CLS");
						main_menu();
					}
					else
					{
						system("CLS");                                                                             
						exit(1);
					}
				}
				
				else if(choice == "2")
				{
					system("CLS");
					logincheck();
				}
				
				else if(choice == "3")
				{
						system("CLS");
						admincheck();
							
							do
							{
								select = "0";
								select = admin();
							
								if(select == "1")
								{
									system("CLS");
									addadmin();	
								}
								else if(select == "2")
								{
									system("CLS");
									addcar();
								}
								else if(select == "3")
								{
									system("CLS");
									showinvoice();
								}
								else if(select == "4")
								{
									system("CLS");
									deletecar();
								}
								else if(select == "5")
								{
									system("CLS");
									main_menu();
									break;
								}
								
								fflush(stdin);
								cout<<"\n\n\t\t\t\tEnter [1] go to admin page else exit : ";
								getline(cin,opt2);
								system("CLS");
								if(opt2 != "1")
									exit(1);
									
							}while(opt2 == "1");				
				}
				
				else if(choice == "4")
				{
					exit(1);
				}
				else
				{
					cout<<"\n\n\t\t\t\tInvalid selection!";
					cout<<"\n\n\t\t\t\tPlease enter again!";
					sleep(1);
				}
				
				system("CLS");
				
			}while(choice != "1" && choice != "2" && choice != "3");	
		}
};


int main()
{	
	Logo lg;
	MainMenu *mm;
	string check,opt,x;
		
	
	do
	{	
		mm = new MainMenu;
			
		mm->main_menu();
				
		
		ofstream invoice("Invoice.txt",ios::app);
		invoice<<CD2.carcode<<" "<<CD.brand<<" "<<CD2.carname<<" "<<CD2.clas<<" "<<CD2.color<<" "<<CD2.capacity<<" "<<CD2.year<<" "<<CD2.noplate<<" "<<d1.rdays<<" "<<d1.day<<" "<<d1.month<<" "<<d1.year<<" ";
		invoice<<d3.day<<" "<<d3.month<<" "<<d3.year<<" "<<CD.total<<" "<<inv.name<<"\n";
		invoice.close();
				
				
		delete mm;			
			
		cout<<"\n\t\t\t\tWould you like to rental another car ? ";
		cout<<"\n\t\t\t\tEnter [1] back to main menu else to exit : ";
		cin>>opt;
		system("CLS");
		
	}while(opt == "1");
			

	return 0;
}
