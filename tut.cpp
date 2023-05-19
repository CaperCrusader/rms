#include <bits/stdc++.h>
using namespace std; 

const string mypass = "CodeSpeedy"; 
class login
{
public:
    string id;
    string pass;
    string password;
    void getid()
    {
        cout<<"Enter your id:";
        cin>>id;
        cout<<"Enter the password:";
        cin>>password;
        pass=password;
    }
    void showid()
    {
        cout<<"Id:"<<id<<endl;
        cout<<"Password:"<<pass<<endl;
    }
};
class info{
public:
    int train_no;
    string train_name;
    string board;
    string dest;
    int s1,s1fare;
    int s2,s2fare;
    int dd,mm,yyyy;
    void getinfo()
    {
        cout<<"Enter the following details\n";
        cout<<"Train name:";
        cin>>train_name;
        cout<<"Train no:";
        cin>>train_no;
        cout<<"Boarding point:";
        cin>>board;
        cout<<"Destination pt:";
        cin>>dest;
        cout<<"No of seats in first class & fare per ticket:";
        cin>>s1>>s1fare;
        cout<<"No of seats in second class & fare per ticket:";
        cin>>s2>>s2fare;
        cout<<"Date of travel in the format dd mm yyyy:";
        cin>>dd>>mm>>yyyy;
    }
    void showinfo()
    {
        cout<<train_no<<"\t"<<train_name<<"\t"<<board<<"\t"<<dest<<"\t";
        cout<<s1<<"\t"<<s1fare<<"\t"<<s2<<"\t"<<s2fare<<"\t";
        cout<<dd<<"-"<<mm<<"-"<<yyyy<<"\t"<<endl;
    }
};

class reser
{
public:
    int pnr;
    int train_no;
    string train_name;
    string board;
    string dest;
    char clas;
    int numseats;
    string passenger_name[100];
   	int age[100];
    int i;
    int dd,mm,yyyy;
    int con;

    float amc;
    void resinfo()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Train no:";
        cin>>train_no;
        cout<<"Train name:";
        cin>>train_name;
        cout<<"Boarding point:";
        cin>>board;
        cout<<"Destination pt:";
        cin>>dest;
        cout<<"No of seats required:";
        cin>>numseats;
        string passenger_name[numseats];
   		int age[numseats];
        for(i=0; i<numseats ; i++)
        {
            cout<<"Passenger name:";
            cin>>passenger_name[i];
            cout<<"Passenger age:";
            cin>>age[i];
        }
        cout<<"Enter 'f' for first class and 's' for second class:";
        cin>>clas;
        cout<<"Date of travel(in the format dd mm yyyy):";
        cin>>dd>>mm>>yyyy;
        cout<<"Enter the concession category\n";
        cout<<"1.Military\n2.Senior citizen\n";
        cout<<"3.Children below 5 yrs\n4.None\n";
        cin>>con;
        cout<<"YOUR DETAILS HAVE BEEN RECORDED!\n";
    }
    void show_resinfo()
    {
        cout<<"___________\n";
        cout<<"Pnr no:"<<pnr;
        cout<<"\nTrain no:"<<train_no;
        cout<<"\nTrain name:";
        cout<<train_name<<endl;
        cout<<"Boarding point:";
        cout<<board<<endl;
        cout<<"Destination pt:";
        cout<<dest<<endl;
        cout<<"No of seats reserved:"<<numseats;
        for(i=0; i<numseats; i++)
        {
            cout<<"Passenger name:";
            cout<<passenger_name[i]<<"   ";
            cout<<"Passenger age:"<<age[i]<<endl;
        }

        cout<<"\nYour class:";
        cout<<clas<<endl;
        cout<<"\nDate of reservation:"<<dd<<"-"<<mm<<"-"<<yyyy;
        cout<<"\nYour concession category:"<<con;
        cout<<"\nYou must pay:"<<amc<<endl;
        cout<<"___________\n";
        cout<<"      RESERVATION RECORDED\n";
        cout<<"___________\n";
    }
};

class canc: public reser
{
public:
	int pnr;
	int train_no;
	string train_name;
	string board;
	string dest;
	char clas;
	int numseats_canc;
	int i;
	int dd,mm,yyyy;
	float amr;
void cancinfo()
{
	cout<<"Enter the details as follows\n";
	cout<<"Pnr no:";
	cin>>pnr;
	cout<<"Date of cancellation:";
	cin>>dd>>mm>>yyyy;
	cout<<"___________\n";
	cout<<"       DETAILS RECORDED\n";
	cout<<"___________\n";
}
void show_cancinfo()
{
	cout<<"...........................................\n";
	cout<<"...........................................\n";
	cout<<"Pnr no:"<<pnr;
	cout<<"\nTrain no:"<<train_no;
	cout<<"\nTrain name:";
	cout<<train_name<<endl;
	cout<<board<<endl;
    cout<<"Destination pt:";
    cout<<dest<<endl;
	cout<<"Your class:"<<clas<<endl;
	cout<<"Enter number of seats to be cancelled :";
	cin>>numseats_canc;

	for(i=0; i<numseats_canc; i++)
	{
		cout<<"Passenger name:";
	    cout<<passenger_name[i]<<"   ";
	    cout<<"Passenger age:"<<age[i]<<endl;
	}
	cout<<"\nCancellation Date:"<<dd<<"-"<<mm<<"-"<<yyyy;
	cout<<"\nYou can collect:₹"<<amr<<endl;
	cout<<"___________\n";
	cout<<"     CANCELLATION RECORDED\n";
	cout<<"___________\n";
}
};

void manage();
void user();
void admin();
void reserve();
void showpassengerinfo();
void cancel();
void enquiry();

int main(int argc, char const *argv[])
{
	int ch;
	cout<<"________________\n";
    cout<<"           RAILWAY RESERVATION SYSTEM           \n";
    cout<<"________________\n";
    do
    {
        cout<<"MENU\n"<<endl;
        cout<<"1.  Enter as administrator\n2.  Enter as User\n3.  Exit\n";
        cout<<"Enter the serial number:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            admin();
            break;
        case 2:
            user();
            break;
        case 3:
            exit(0);
        }
    }
    while(ch<=3);
    return 0;
}
void admin(){
	while(1){
		string password;
		cout<<"Enter the password."<<endl;
		cin>>password;
		if(password!=mypass){ 
					cout<<"Wrong password!!! \n";
		        	cout<<"Try again.\n\n";}
		else 
			break;
	}
	int ch;
	fstream f;
	char c;
	info a;
	do
    {
        cout<<"_ADMINISTRATOR MENU_\n\n";
        cout<<"1.  Create detail data base\n2.  Add details\n";
        cout<<"3.  Display details\n4.  User management\n";
        cout<<"5.  Display passenger details\n6.  Return to main menu\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
            {
            case 1:
                f.open("det.txt",ios::out|ios::binary);
                do
                {
                    a.getinfo();
                    f.write((char *) & a,sizeof(a));
                    cout<<"Add one more record?\n";
                    cout<<"y-for Yes\nn-for No\n";
                    cin>>c;
                }
                while(c=='y');
                f.close();
                break;
            case 2:
                f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                a.getinfo();
                f.write((char *) & a,sizeof(a));
                f.close();
                break;
            case 3:
                f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                f.seekg(0);
                while(f.read((char *) & a,sizeof(a)))
                {
                    a.showinfo();
                }
                f.close();
                break;
            case 4:
                manage();
                break;
            case 5:
                showpassengerinfo();
                break;
            }
    }
    while(ch<=5);

        f.close();
}
void manage()
{
    int ch;
    fstream f;
    char c;
    login a;
    cout<<"___________\n";
    cout<<"    THE USER MANAGEMENT MENU\n\n";
    cout<<"___________\n";
    do
    {
        cout<<"1.Create new data base\n2.Add details\n";
        cout<<"3.Show details\n4.Main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            f.open("id.txt",ios::out|ios::binary);
            do
            {
                a.getid();
                f.write((char *) & a,sizeof(a));
                cout<<"Add a new record?\n";
                cout<<"y-Yes\nn-No\n";
                cin>>c;
            }
            while(c=='y');
            f.close();
            break;
        case 2:
            f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
            a.getid();
            f.write((char *) & a,sizeof(a));
            f.close();
            break;
        case 3:
            f.open("id.txt",ios::in|ios::out|ios::binary);

            f.seekg(0);
            while(f.read((char *) & a,sizeof(a)))
            {
                a.showid();
            }
            f.close();
            break;
        }
    }
    while(ch<=3);
}
void showpassengerinfo()
{
    fstream f;
    reser b;
    f.open("p.txt",ios::in|ios::out|ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {
        b.show_resinfo();
    }
    f.close();
}
void reserve()
{
    info a;
    reser b;
    fstream f1,f2;
    time_t t;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
    int ch;
    b.resinfo();
    int amt, flag, addr, ad;
    while(f1.read((char *) &a,sizeof(a)))
    {
        if(a.train_no==b.train_no)
        {
            if(b.clas=='f')
            {
                if(a.s1>=b.numseats)

                {
                    amt=a.s1fare;
                    addr=f1.tellg();
                    ad=sizeof(a.s1);
                    f1.seekp(addr-(7*ad));
                    a.s1=a.s1-b.numseats;
                    f1.write((char *) & a.s1,sizeof(a.s1));
                    if(b.con==1)
                    {
                        cout<<"Concession category:MILITARY PERSONNEL\n";

                        b.amc=b.numseats*((amt*75)/100);
                    }
                    else if(b.con==2)
                    {
                        cout<<"Concession category:SENIOR CITIZEN\n";
                        b.amc=b.numseats*((amt*90)/100);
                    }
                    else if(b.con==3)
                    {
                        cout<<"Concession category:CHILDERN BELOW FIVE\n";
                        b.amc=0.0;
                    }
                    else if(b.con==4)
                    {
                        cout<<"You cannot get any concession\n";
                        b.amc=b.numseats*amt;
                    }
                    srand((unsigned) time(&t));
                    b.pnr=rand();
                    f2.write((char *) & b,sizeof(b));
                    b.show_resinfo();
                    cout<<"___________\n";
                    cout<<"      -Tickets reserved-\n";
                    cout<<"___________\n";
                }
                else
                {
                    cout<<"SEATS UNAVAILABLE NOW!!\n";

                }
            }
            else if(b.clas=='s')
            {
                if(a.s2>=b.numseats)
                {
                    amt=a.s2fare;
                    addr=f1.tellg();
                    ad=sizeof(a.s2);
                    f1.seekp(addr-(5*ad));
                    a.s2=a.s2-b.numseats;
                    f1.write((char *) & a.s2,sizeof(a.s2));
                    if(b.con==1)
                    {
                        cout<<"Concession category:MILITARY PRESONNEL\n";
                        b.amc=b.numseats*((amt*75)/100);
                    }
                    else if(b.con==2)
                    {
                        cout<<"Concession category:SENIOR CITIZEN\n";
                        b.amc=b.numseats*((amt*90)/100);
                    }
                    else if(b.con==3)
                    {
                        cout<<"Concession category:CHILDERN BELOW FIVE\n";
                        b.amc=0.0;
                    }
                    else if(b.con==4)
                    {
                        cout<<"You cannot get any concession\n";
                        b.amc=b.numseats*amt;
                    }
                    f2.write((char *) & b,sizeof(b));
                    b.show_resinfo();
                    cout<<"___________\n";
                    cout<<"      -Tickets reserved-\n";
                    cout<<"___________\n";
                }
                else
                {
                    cout<<"SEATS UNAVAILABLE NOW!!\n";
                }
            }
        }
        else
        {
            cout<<"............Wrong train no......................\n";
        	cout<<"......Enter the train no. from the database.....\n";
        }
    }
    f1.close();
    f2.close();

}
void enquiry()
{

    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    info a;
    while(f.read((char *) & a,sizeof(a)))
    {
        a.showinfo();
    }
}
void cancel()
{
    info a;
    reser b;
    canc c;
    fstream f1,f2,f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);
    cout<<"___________\n";
    cout<<"     MENU FOR CANCELLATION\n";
    cout<<"___________\n";
    c.cancinfo();
    int dd, mm, ad, addr, tamt, flag;
    while(f2.read((char *) & b,sizeof(b)))
    {
        if(b.pnr==c.pnr)
        {
            c.train_no=b.train_no;
            c.train_name=b.train_name;
            c.board=b.board;
            c.dest=b.dest;
            c.numseats_canc=b.numseats;
            for(int j=0; j<c.numseats_canc; j++)
            {
                c.passenger_name[j]=b.passenger_name[j];
                c.age[j]=b.age[j];
            }
            c.clas=b.clas;
            if(c.clas=='f')
            {
                while(f1.read((char *) & a,sizeof(a)))
                {

                    if(a.train_no==c.train_no)
                    {
                        a.s1=a.s1+c.numseats_canc;
                        dd=a.dd;
                        mm=a.mm;
                        addr=f1.tellg();
                        ad=sizeof(a.s1);
                        f1.seekp(addr-(7*ad));
                        f1.write((char *) & a.s1,sizeof(a.s1));
                        tamt=b.amc;
                        if((c.dd==dd)&&(c.mm==mm))
                        {
                            cout<<"You are cancelling at the date of departure\n";
                            c.amr=tamt-((tamt*90)/100);
                        }
                        else if(c.mm==mm)
                        {
                            cout<<"You are cancelling at the month of departure\n";
                            c.amr=tamt-((tamt*75)/100);
                        }
                        else if(mm>c.mm)
                        {
                            cout<<"You are cancelling one month before the date of departure\n";
                            c.amr=tamt-((tamt*30)/100);
                        }
                        else
                        {
                            cout<<"Cancelling after the departure\n";
                            cout<<"Your request cannot be completed\n";
                        }
                        goto h;
                        c.show_cancinfo();
                    }
                }
            }
            else if(c.clas=='s')
            {
                while(f1.read((char *) & a,sizeof(a)))
                {

                    if(a.train_no==c.train_no)
                    {
                        a.s2=a.s2+c.numseats_canc;
                        dd=a.dd;
                        mm=a.mm;
                        addr=f1.tellg();
                        ad=sizeof(a.s2);
                        f1.seekp(addr-(5*ad));
                        f1.write((char *) & a.s2,sizeof(a.s2));
                        tamt=b.amc;
                        if((c.dd==dd)&&(c.mm==mm))
                        {
                            cout<<"You are cancelling at the date of departure\n";
                            c.amr=tamt-((tamt*90)/100);
                        }
                        else if(c.mm==mm)
                        {
                            cout<<"You are cancelling at the month of departure\n";
                            c.amr=tamt-((tamt*75)/100);
                        }
                        else if(mm>c.mm)
                        {
                            cout<<"You are cancelling one month before the date of departure\n";
                            c.amr=tamt-((tamt*30)/100);
                        }
                        else
                        {
                            cout<<"Cancelling after the departure\n";
                            cout<<"Your request cannot be completed\n";
                        }
                        goto h;
                        c.show_cancinfo();
                    }
                }
            }
        }
        else
        {
            flag=0;
        }
    }
h:
    if(flag==0)
    {
        cout<<"Enter the pnr no. correctly\n";
    }
    f1.close();
    f2.close();
    f3.close();
}
void user()
{
    login a;
    int ch, flag;
    cout<<"___________\n";
    cout<<"    WELCOME TO THE USER MENU\n";
    cout<<"___________\n";
    string password;

    fstream f;
    f.open("id.txt",ios::in|ios::out|ios::binary);
    string id;
    cout<<"Enter your id:"<<endl;
    cin>>id;
    cout<<"Enter your password: ";
    cin>>password;
    while(f.read((char *) & a,sizeof(a)))
    {
        if(a.id==id && a.pass==password)
        {
            do
            {
                cout<<"1.Reserve\n2.Cancel\n3.Enquiry\n4.Main menu\n";
                cout<<"Enter your choice:";
                cin>>ch;
                cout<<endl;
                switch(ch)
                {
                case 1:
                    reserve();
                    break;
                case 2:
                    cancel();
                    break;
                case 3:
                    enquiry();
                    break;
                }
            }
            while(ch<=3);
        }
        else
        {
            cout<<"Enter your user id and password correctly\n";
        }
    }
}