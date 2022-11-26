#include <iostream> // It is used as a stream of Input and Output using cin and cout.
#include <cstring> 
#include<bits/stdc++.h>
#include<string> //It is used to perform various functionalities related to string manipulation like strlen(), strcmp(), strcpy(), size(), etc.
#include <cctype>  //It contains function prototypes for functions that test characters for certain properties , and also function prototypes for functions that can be used to convert uppercase letters to lowercase letters and vice versa.
#include <stdio.h>  //It is used to perform input and output operations using functions scanf() and printf().
#include <conio.h> 
#include <stdlib.h>
#include "password.cpp"
// #include "kbhit.cpp"
#include<fstream>  //It is used to control the data to read from a file as an input and data to write into the file as an output.
#include<iomanip>  //It is used to access set() and setprecision() function to limit the decimal places in variables.
using namespace std;
int win;
int lose;
int unattempt;
int reward;
int total;
float percent;

//To include all these header files in one
//#include<bits/stdc++.h>
void clear() 
{
	system("cls");
}

void gotoXY(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

class student
{
	string name;
    char password[20];
    string pass;
    string pass1;
    string con_pass;
	int age;
	int gender;
	char email[100]; 
public:
    student(){}
    void login();
	void signup();
    void class_result();
    void result();
    void zeroscreen();
    void firstscreen();  
    void test_quiz();     
    void practice_quiz();
    void info();
    void welcome();
};



void student::signup(){
	clear(); 
    welcome();
    cout<<"\t\t\t---------------------------------------------------------------------------------";
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	gotoXY(60,10);
	cout<<"Signup";
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	gotoXY(42,14);
	cout<<"Enter username: ";
    int n;
    do{
        gotoXY(70,14);
        cin>>name;
        string u,p;
        char e[100];
        char g;
        int a;
        n=0;
        ifstream infile("database.txt");
        while(infile>>u>>p>>a>>g>>e && !infile.eof()){
            if(name==u){
                n=1;
            }
        }
    }while(n==1);
	gotoXY(42,16);
	cout<<"Enter your email address: ";
    gotoXY(90,16);
    cout<<"@gmail.com";
    gotoXY(70,16);
    cin>>email;
    strcat(email,"@gmail.com");
    gotoXY(42,17);
    cout<<"(Use correct format)";
    gotoXY(42,18);
	cout<<"Enter your age:";
    do{
    gotoXY(42,19);
    cout<<"(Above 5 years)";
    gotoXY(70,18);
    cin>>age;
    }while(age<5);
    gotoXY(42,20);
	cout<<"Enter your gender:";
    gotoXY(42,21);
    cout<<"(1-->Female, 2-->Male, 0-->Other)";
    do{
    gotoXY(70,20);
    cin>>gender;
    }while(gender>2);
    clear();
    welcome();
    cout<<"\t\t\t---------------------------------------------------------------------------------";
	gotoXY(55,10);
	cout<<"Username: \""<<name<<"\"";
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
    gotoXY(42,14);
	cout<<"New password: ";
    gotoXY(42,15);
    cout<<"(Must contain one capital letter,small letter and one digit and atleast 5 characters";
    gotoXY(70,14);
    cin>>pass;
    while(checkpassword(pass)){
        gotoXY(70,14);
        cin>>pass; 
    }
    gotoXY(42,16);
    cout<<"Confirm password:";
    do{
        gotoXY(70,16);
        cin>>con_pass;
    }while(con_pass!=pass);
    _getch();
    gotoXY(55,20);
    cout<<"Password matched.....\n";
    ofstream outfile;
    outfile.open("database.txt",ios::app);
    student st;
    outfile<<name<<" "<<pass<<" "<<age<<" "<<gender<<" "<<email<<" "<<endl;
    outfile.close();
    ofstream ofile;
    ofile.open("reward.txt",ios::app);
    ofile<<name<<" "<<50<<endl;
    ofile.close();
    cout<<"\t\t\t---------------------------------------------------------------------------------\n";
	gotoXY(55,22);
	cout<<"Username: \""<<name<<"\"";
    gotoXY(55,23);
    cout<<"Signup successful!!"<<endl;
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
    gotoXY(55,27);
    cout<<"Next: ";
    gotoXY(62,27);
    cin.ignore();
    login();   	
}

void student::login(){
    clear();
	welcome();
    cout<<"\t\t\t---------------------------------------------------------------------------------";
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	gotoXY(60,10);
	cout<<"Login";
    cout<<"\n\n\t\t\t---------------------------------------------------------------------------------";
    string u,p,n;
    char e[100];
    char g;
    int count=0,a,r;
    name.clear();
    pass.clear();
    gotoXY(42,14);
	cout<<"Username:";
    gotoXY(60,14);
    cin>>name;
    _getch();
	gotoXY(42,16);
	cout<<"Password:";
    gotoXY(60,16);
    int i=0;
    
    while((password[i]=_getch())!='\n')
    {
        pass+=password[i];
        cout<<"*";
        i++;
    }
    ifstream infile("database.txt");
    while(infile>>u>>p>>a>>g>>e && !infile.eof()){
        if(name==u && pass==p){
            count=1;
        }
    }
    infile.close();
    if(count==1){
        cout<<"\n\t\t\t---------------------------------------------------------------------------------\n";
        gotoXY(55,20);
        cout<<"Hello \""<<name<<"\"";
        gotoXY(55,21);
        cout<<"Login Successful!!";
        cout<<"\n\n\t\t\t---------------------------------------------------------------------------------\n";
        gotoXY(55,27);
        cout<<"Next: ";
        gotoXY(62,27);
        cin.ignore();
        firstscreen();
    }
    else{
        cout<<"\n\t\t\t---------------------------------------------------------------------------------\n";
        gotoXY(55,20);
        cout<<"LOGIN ERROR!!!!";
        gotoXY(55,21);
        cout<<"Please check your username and password."<<endl;
        cout<<"\n\n\t\t\t---------------------------------------------------------------------------------\n";
        gotoXY(55,27);
        cout<<"Next: ";
        gotoXY(62,27);
        cin.ignore();
        zeroscreen();
    }
    
}

void student::info()
{
	    gotoXY(56,4);	
		cout<<"Instruction"<<endl;
	    gotoXY(50,5);	
		cout<<"Login to go to the home page."<<endl;
		gotoXY(38,6);	
		cout<<"   _______________________________________________"<<endl;
		gotoXY(38,7);
		cout<<" / \\                             	               \\."<<endl;
		gotoXY(38,8);
		cout<<"|   |                                             |."<<endl;
		gotoXY(38,9);
		cout<<" \\_ | Choose mode ==>                             |."<<endl;
        gotoXY(38,10);  
		cout<<"    |                                             |."<<endl;
        gotoXY(38,11);
        cout<<"    | Practice mode -> Answer is displayed.       |."<<endl;
        gotoXY(38,12);
        cout<<"    | Test mode     -> Answer is not displayed.   |."<<endl;
        gotoXY(38,13);  
		cout<<"    |                                             |."<<endl;
		gotoXY(38,14);
		cout<<"    | Press only Valid Options ==> (a,b,c,d)      |."<<endl;
		gotoXY(38,15);
		cout<<"    | Press h for hint.                           |."<<endl;
        gotoXY(38,16);
        cout<<"    | Press E to end game.                        |."<<endl;
		gotoXY(38,17);      
		cout<<"    | Press Enter to Skip.                        |."<<endl;
        gotoXY(38,18);  
		cout<<"    |                                             |."<<endl;
		gotoXY(38,19);
		cout<<"    | Reward points ==>                           |."<<endl;
        gotoXY(38,20);  
		cout<<"    |                                             |."<<endl;
		gotoXY(38,21);
		cout<<"    | -> 30 points will be awared for             |."<<endl;
		gotoXY(38,22);
        cout<<"    |    correct answer.                          |."<<endl;
		gotoXY(38,23);  
		cout<<"    |                                             |."<<endl;
		gotoXY(38,24);
		cout<<"    | Hint ==>                                    |."<<endl;
        gotoXY(38,25);  
		cout<<"    |                                             |."<<endl;
		gotoXY(38,26);
		cout<<"    | Hint can be taken if reward is greater than |."<<endl;
		gotoXY(38,27);
		cout<<"    | or equal to 50.                             |."<<endl;
		gotoXY(38,29);
		cout<<"    |   __________________________________________|"<<endl;
		gotoXY(38,30);
		cout<<"    |  /                                          /."<<endl;
		gotoXY(38,31);
		cout<<"    \\_/__________________________________________/."<<endl;
        gotoXY(50,35);
        cout<<"Next: ";
        gotoXY(58,35);
        getch();
}


void student::test_quiz()
{
    clear();
    int no=1;
    int count=0;
    int take[8];
    string check;
    string ans;
    string andd;
    string ss;
    int type;
    string n;
    int r;
    win=0;
    lose=0;
    unattempt=0;
    total=0;
    ifstream rew("reward.txt");
    while(rew>>n>>r && !rew.eof()){
        if(name==n){
            reward=r;
        }
    }
    rew.close();
    welcome();
    cout<<"\t\t\t---------------------------------------------------------------------------------";
	gotoXY(60,10);
	cout<<"TEST MODE";
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
    gotoXY(52,14);
	cout<<"1--> Random question";
	gotoXY(52,16);
	cout<<"2--> Select Chapters";
    gotoXY(52,20);
	cout<<"Select : ";  
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	gotoXY(60,20);
	cin>>type;	
    ifstream ins("pailo.txt");
    fstream in("doso.txt");
	switch(type)
	{
		case 1:
			{
            do
            {
                clear(); 
                gotoXY(30,7);
                cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                gotoXY(30,10);
                cout<<"QUESTION NO: "<<no;
                no++;
                gotoXY(30,11);
                cout<<"Press E for exit";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                for (int i = 0; i < 3; i++){
                    getline(ins,ss);
                    gotoXY(20,14+i);
                    cout<<ss<<endl;
                    count++;
                }   
                gotoXY(40,18); 
                cout<<"SELECT: ";  
                gotoXY(50,18);
                cin>>ans;
                getch();
                cout<<"\n\n\n\n\n\n\t\t\t---------------------------------------------------------------------------------";
                getline(ins,check);
                count++;
                if(ans.at(0)==check.at(0)){
                    //gotoXY(40,22);
                    //cout<<"Correct answer!!:)";
                    win++;
                    reward=reward+30;
                    gotoXY(60,22);
                    cout<<"Next: ";
                    gotoXY(70,22);
                    getch();
                }
                else if(ans.at(0)=='E' || ans.at(0)=='e'){
                    clear();
                    result();
                }
                else if (ans.at(0)==' ' || ans.at(0)=='\n'){
                    unattempt++;
                    //gotoXY(40,22);
                    //cout<<"Correct answer: "<<check;
                    gotoXY(60,22);
                    cout<<"Next: ";
                    gotoXY(70,22);
                    getch();
                }
                else if (ans.at(0)!=check.at(0) && (ans.at(0)=='a' || ans.at(0)=='b' || ans.at(0)=='c' || ans.at(0)=='d')){
                    //gotoXY(40,22);
                    //cout<<"Incorrect answer!!:("<<endl;
                    lose++;
                    //gotoXY(40,23);
                    //cout<<"Correct answer: "<<check;
                    gotoXY(60,22);
                    cout<<"Next: ";
                    gotoXY(70,22);
                    getch();
                    }
                
            }while(count!=84);
            ifstream infile("reward.txt");
            ofstream ofile;
            ofile.open("reward1.txt",ios::app);
            while(infile>>n>>r && !infile.eof()){
                if(name==n){
                    ofile<<name<<" "<<reward<<endl;
                }
                else{
                    ofile<<n<<" "<<r<<endl;
                }
            }
            ofile.close();
            infile.close();
            remove("reward.txt");
            rename("reward1.txt","reward.txt");
			break;
		    }
        case 2:
        {
            clear();
            no=1;
            int no_of_chaps;
            int chap[8];
            gotoXY(50,10);
            cout<<"SELECT CHAPTER:";
            gotoXY(30,7);
            cout<<"\n\t\t\t---------------------------------------------------------------------------------";
            gotoXY(42,14);
            cout<<"1--> Files";
            gotoXY(42,15);
            cout<<"2--> Inheritance";
            gotoXY(42,16);
            cout<<"3--> Polymorphism";
            gotoXY(42,17);
            cout<<"4--> Encapsulation";
            gotoXY(42,18);
            cout<<"5--> Operator Overloading";
            gotoXY(42,19);
            cout<<"6--> Templates";
            gotoXY(42,20);
            cout<<"7--> Error Handling";
            gotoXY(40,26);
            cout<<"Select no of chapters : ";
            do{
                gotoXY(70,26);
                cin>>no_of_chaps;
            }while(no_of_chaps>7);
            
            int k=0;
            gotoXY(40,28);
            cout<<"Enter the chapters: "<<endl;
            do{
                gotoXY(40,30+k);
                cin>>chap[k];
                k++;
            }while(k< no_of_chaps);

            cout<<"\t\t\t----------------------------------START------------------------------------------";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------";
            int j=0;
                    do
                    {   
                        if( (chap[j]==2) || (chap[j]==3) || (chap[j]==4) || (chap[j]==5) || (chap[j]==6) || (chap[j]==7 ))
                        {
                            count= (12+(chap[j]-2)*12);
                            int n=0;
                            int m=0;
                            in.seekg(0, ios::beg);
                            ins.seekg(0, ios::beg);
                            do
                            {
                                getline(ins,ss);
                                n=n+1;
                            } while (n!=(12+((chap[j]-2)*12)));
                            do
                            {
                                getline(in,andd);
                                m=m+1;
                            } while (m!=3+(((chap[j]-2)*3)));
                        } 
                     do{
                        clear(); 
                        gotoXY(30,7);
                        cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                        gotoXY(30,10);
                        cout<<"QUESTION NO: "<<no;
                        no++;
                        // gotoXY(30,11);
                        // cout<<"Press H for hint";
                        gotoXY(50,11);
                        cout<<"Press E for exit";
                        cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                        for (int i = 0; i < 3; i++)
                        {
                            getline(ins,ss);
                            gotoXY(20,14+i);
                            cout<<ss<<endl;
                            count++;
                        }   
                        gotoXY(40,18); 
                        cout<<"SELECT: ";  
                        gotoXY(50,18);
                        cin>>ans;
                        getch();
                        cout<<"\n\n\n\n\n\n\t\t\t---------------------------------------------------------------------------------";
                        getline(ins,check);
                        count++;
                        if(ans.at(0)==check.at(0))
                        {
                            //gotoXY(40,22);
                            //cout<<"Correct answer!!:)";
                            win++;
                            reward=reward+30;
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                        else if(ans.at(0)=='E' || ans.at(0)=='e'){
                            clear();
                            result();
                        }
                        else if (ans.at(0)==' ' || ans.at(0)=='\n'){
                            unattempt++;
                            //gotoXY(40,22);
                            //cout<<"Correct answer: "<<check;
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                        else{
                            //gotoXY(40,22);
                            //cout<<"Incorrect answer!!:(";
                            lose++;
                            //gotoXY(40,23);
                            //cout<<"Correct answer: "<<check;
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                            }
                      }while(count!=(12+((chap[j]-1)*12)));
                    j++;
                    }while(j < no_of_chaps);
                    ifstream infile("reward.txt");
            ofstream ofile;
            ofile.open("reward1.txt",ios::app);
            while(infile>>n>>r && !infile.eof()){
                if(name==n){
                    ofile<<name<<" "<<reward<<endl;
                }
                else{
                    ofile<<n<<" "<<r<<endl;
                }
            }
            ofile.close();
            infile.close();
            remove("reward.txt");
            rename("reward1.txt","reward.txt");
            break;
        }
        default:
            {
            gotoXY(50,20);
            cout<<"INVALID CHOICE";
            _getch();
            }	
    }
    total=no-1;
    percent=(float(win*100)/total);
    gotoXY(35,20);
    cout<<"Percentage:   "<<  percent <<"%"<<endl;
    ofstream outfile;
    outfile.open("record.txt",ios::app);
    student st;
    outfile<<name<<" "<<" "<<win<<" "<<lose<<" "<<unattempt<<" "<<reward<<" "<<total<<" "<<percent<<" "<<endl;
    outfile.close();
    if(percent>=50){
        gotoXY(70,16);    
        cout<<"Amazing! keep it up <3"<<endl;
        }
    else{
        gotoXY(35,17);
        cout<<"Can do better! <3 "<<endl;
    }
    result();

}



void student::practice_quiz()
{
    clear();
    int no=1;
    int count=0;
    int take[8];
    string check;
    string ans;
    string andd;
    string ss;
    int type;
    string n;
    int r;
    win=0;
    lose=0;
    unattempt=0;
    total=0;
    ifstream rew("reward.txt");
    while(rew>>n>>r && !rew.eof()){
        if(name==n){
            reward=r;
        }
    }
    rew.close();
    welcome();
    cout<<"\t\t\t---------------------------------------------------------------------------------";
	gotoXY(60,10);
	cout<<"TEST MODE";
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
    gotoXY(52,14);
	cout<<"1--> Random question";
	gotoXY(52,16);
	cout<<"2--> Select Chapters";
    gotoXY(52,20);
	cout<<"Select : ";  
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	gotoXY(60,20);
	cin>>type;	
    ifstream ins("pailo.txt");
    fstream in("doso.txt");
	switch(type)
	{
		case 1:
			{
            do
            {
                clear(); 
                gotoXY(30,7);
                cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                gotoXY(30,10);
                cout<<"QUESTION NO: "<<no;
                gotoXY(60,10);
                cout<<"Reward: "<<reward;
                no++;
                gotoXY(30,11);
                cout<<"Press H for hint";
                gotoXY(60,11);
                cout<<"Press E for exit";
                cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                for (int i = 0; i < 3; i++){
                    getline(ins,ss);
                    gotoXY(20,14+i);
                    cout<<ss<<endl;
                    count++;
                }   
                gotoXY(40,18); 
                cout<<"SELECT: ";  
                gotoXY(50,18);
                cin>>ans;
                getch();
                cout<<"\n\n\n\n\n\n\t\t\t---------------------------------------------------------------------------------";
                getline(ins,check);
                count++;
                if(ans.at(0)==check.at(0)){
                    gotoXY(40,22);
                    cout<<"Correct answer!!:)";
                    win++;
                    //reward=reward+30;
                    gotoXY(60,22);
                    cout<<"Next: ";
                    gotoXY(70,22);
                    getch();
                }
                else if(ans.at(0)=='h' || ans.at(0)=='H'){
                    for (int i = 0; i < (no-1); i++){
                    getline(in,andd);
                    }  
                    getline(in,andd);
                    if(reward>=50){
                        gotoXY(40,20);
                        cout<<"Hint: "<<andd;
                        reward=reward-50;
                        gotoXY(50,18);
                        cin>>ans;
                        if(check.at(0)==ans.at(0)){
                            gotoXY(40,22);
                            cout<<"Correct answer!!:)";
                            win++;
                            //reward=reward+15; 
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                        else{
                            gotoXY(40,22);
                            cout<<"Incorrect answer!!:(";
                            lose++;
                            gotoXY(40,23);
                            cout<<"Correct answer: "<<check;
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                    }
                    else{
                        gotoXY(40,20);
                        cout<<"Not enough reward available for hint :("<<endl;
                        gotoXY(40,22);
                        cout<<"Ans: ";
                        gotoXY(50,18);
                        cin>>ans;
                        if(check.at(0)==ans.at(0)){
                            gotoXY(40,24);
                            cout<<"Correct answer!!:)";
                            win++;
                            //reward=reward+30; 
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                        else if(ans.at(0)=='E' || ans.at(0)=='e'){
                            clear();
                            result();
                        }
                        else{
                            gotoXY(40,22);
                            cout<<"Incorrect answer!!:(";
                            lose++;
                            gotoXY(40,23);
                            cout<<"Correct answer: "<<check;
                            gotoXY(60,23);
                            cout<<"Next: ";
                            gotoXY(70,23);
                            getch();
                        }
                    }
                }
                else if(ans.at(0)=='E' || ans.at(0)=='e'){
                    clear();
                    result();
                }
                else if (ans.at(0)==' ' || ans.at(0)=='\n'){
                    unattempt++;
                    gotoXY(40,22);
                    cout<<"Correct answer: "<<check;
                    gotoXY(60,22);
                    cout<<"Next: ";
                    gotoXY(70,22);
                    getch();
                }
                else if (ans.at(0)!=check.at(0) && (ans.at(0)=='a' || ans.at(0)=='b' || ans.at(0)=='c' || ans.at(0)=='d')){
                    gotoXY(40,22);
                    cout<<"Incorrect answer!!:("<<endl;
                    lose++;
                    gotoXY(40,23);
                    cout<<"Correct answer: "<<check;
                    gotoXY(60,23);
                    cout<<"Next: ";
                    gotoXY(70,22);
                    getch();
                    }
                
            }while(count!=84);
            ifstream infile("reward.txt");
            ofstream ofile;
            ofile.open("reward1.txt",ios::app);
            while(infile>>n>>r && !infile.eof()){
                if(name==n){
                    ofile<<name<<" "<<reward<<endl;
                }
                else{
                    ofile<<n<<" "<<r<<endl;
                }
            }
            ofile.close();
            infile.close();
            remove("reward.txt");
            rename("reward1.txt","reward.txt");
			break;
		    }
        case 2:
        {
            clear();
            no=1;
            int no_of_chaps;
            int chap[8];
            gotoXY(50,10);
            cout<<"SELECT CHAPTER:";
            gotoXY(30,7);
            cout<<"\n\t\t\t---------------------------------------------------------------------------------";
            gotoXY(42,14);
            cout<<"1--> Files";
            gotoXY(42,15);
            cout<<"2--> Inheritance";
            gotoXY(42,16);
            cout<<"3--> Polymorphism";
            gotoXY(42,17);
            cout<<"4--> Encapsulation";
            gotoXY(42,18);
            cout<<"5--> Operator Overloading";
            gotoXY(42,19);
            cout<<"6--> Templates";
            gotoXY(42,20);
            cout<<"7--> Error Handling";
            gotoXY(40,26);
            cout<<"Select no of chapters : ";
            do{
                gotoXY(70,26);
                cin>>no_of_chaps;
            }while(no_of_chaps>7);
            
            int k=0;
            gotoXY(40,28);
            cout<<"Enter the chapters: "<<endl;
            do{
                gotoXY(40,30+k);
                cin>>chap[k];
                k++;
            }while(k< no_of_chaps);

            cout<<"\t\t\t----------------------------------START------------------------------------------";
            cout<<"\n\t\t\t---------------------------------------------------------------------------------";
            int j=0;
                    do
                    {   
                        if( (chap[j]==2) || (chap[j]==3) || (chap[j]==4) || (chap[j]==5) || (chap[j]==6) || (chap[j]==7 ))
                        {
                            count= (12+(chap[j]-2)*12);
                            int n=0;
                            int m=0;
                            in.seekg(0, ios::beg);
                            ins.seekg(0, ios::beg);
                            do
                            {
                                getline(ins,ss);
                                n=n+1;
                            } while (n!=(12+((chap[j]-2)*12)));
                            do
                            {
                                getline(in,andd);
                                m=m+1;
                            } while (m!=3+(((chap[j]-2)*3)));
                        } 
                     do{
                        clear(); 
                        gotoXY(30,7);
                        cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                        gotoXY(30,10);
                        cout<<"QUESTION NO: "<<no;
                        no++;
                        gotoXY(60,10);
                        cout<<"Reward: "<<reward;
                        gotoXY(30,11);
                        cout<<"Press H for hint";
                        gotoXY(50,11);
                        cout<<"Press E for exit";
                        cout<<"\n\t\t\t---------------------------------------------------------------------------------";
                        for (int i = 0; i < 3; i++)
                        {
                            getline(ins,ss);
                            gotoXY(20,14+i);
                            cout<<ss<<endl;
                            count++;
                        }   
                        gotoXY(40,18); 
                        cout<<"SELECT: ";  
                        gotoXY(50,18);
                        cin>>ans;
                        getch();
                        cout<<"\n\n\n\n\n\n\t\t\t---------------------------------------------------------------------------------";
                        getline(ins,check);
                        count++;
                        if(ans.at(0)==check.at(0))
                        {
                            gotoXY(40,22);
                            cout<<"Correct answer!!:)";
                            win++;
                            //reward=reward+30;
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                        else if(ans.at(0)=='h' || ans.at(0)=='H')
                        {
                            getline(in,andd);
                            if(reward>=50)
                            {
                                gotoXY(40,20);
                                cout<<"Hint: "<<andd;
                                reward=reward-50;
                                gotoXY(50,18);
                                cin>>ans;
                                if(check.at(0)==ans.at(0))
                                {
                                    gotoXY(40,22);
                                    cout<<"Correct answer!!:)";
                                    win++;
                                    //reward=reward+15; 
                                    gotoXY(60,22);
                                    cout<<"Next: ";
                                    gotoXY(70,22);
                                    getch();
                                }
                                else{
                                    gotoXY(40,22);
                                    cout<<"Incorrect answer!!:("<<endl;
                                    lose++;
                                    gotoXY(40,23);
                                    cout<<"Correct answer: "<<check;
                                    gotoXY(60,23);
                                    cout<<"Next: ";
                                    gotoXY(70,23);
                                    getch();
                                }
                            }
                            else{
                                gotoXY(40,20);
                                cout<<"Not enough reward available for hint :("<<endl;
                                gotoXY(40,22);
                                cout<<"Ans: ";
                                gotoXY(50,18);
                                cin>>ans;
                                if(check.at(0)==ans.at(0)){
                                    gotoXY(40,24);
                                    cout<<"Correct answer!!:)"<<endl;
                                    win++;
                                    //reward=reward+30; 
                                    gotoXY(60,22);
                                    cout<<"Next: ";
                                    gotoXY(70,22);
                                    getch();
                                }
                                else{
                                    gotoXY(40,22);
                                    cout<<"Incorrect answer!!:("<<endl;
                                    lose++;
                                    gotoXY(40,23);
                                    cout<<"Correct answer: "<<check;
                                    gotoXY(60,23);
                                    cout<<"Next: ";
                                    gotoXY(70,23);
                                    getch();
                                }
                            }
                        }
                        else if(ans.at(0)=='E' || ans.at(0)=='e'){
                            clear();
                            result();
                        }
                        else if (ans.at(0)==' ' || ans.at(0)=='\n'){
                            unattempt++;
                            gotoXY(40,22);
                            cout<<"Correct answer: "<<check;
                            gotoXY(60,22);
                            cout<<"Next: ";
                            gotoXY(70,22);
                            getch();
                        }
                        else{
                                    gotoXY(40,22);
                                    cout<<"Incorrect answer!!:("<<endl;
                                    lose++;
                                    gotoXY(40,23);
                                    cout<<"Correct answer: "<<check;
                                    gotoXY(60,23);
                                    cout<<"Next: ";
                                    gotoXY(70,23);
                                    getch();
                            }
                      }while(count!=(12+((chap[j]-1)*12)));
                    j++;
                    }while(j < no_of_chaps);
                    ifstream infile("reward.txt");
            ofstream ofile;
            ofile.open("reward1.txt",ios::app);
            while(infile>>n>>r && !infile.eof()){
                if(name==n){
                    ofile<<name<<" "<<reward<<endl;
                }
                else{
                    ofile<<n<<" "<<r<<endl;
                }
            }
            ofile.close();
            infile.close();
            remove("reward.txt");
            rename("reward1.txt","reward.txt");
            break;
        }
        default:
            {
            gotoXY(50,20);
            cout<<"INVALID CHOICE";
            gotoXY(60,23);
            cout<<"Again: ";
            gotoXY(70,23);
            getch();
            }	
    }
    total=no-1;
    percent=(float(win*100)/total);
    gotoXY(35,20);
    cout<<"Percentage:   "<<  percent <<"%"<<endl;
    ofstream outfile;
    outfile.open("record.txt",ios::app);
    student st;
    outfile<<name<<" "<<" "<<win<<" "<<lose<<" "<<unattempt<<" "<<reward<<" "<<total<<" "<<percent<<" "<<endl;
        outfile.close();
        if(percent>=50){
        gotoXY(70,16);    
        cout<<"Amazing! keep it up <3"<<endl;
        }
    else{
        gotoXY(35,17);
        cout<<"Can do better! <3 "<<endl;
    }
    result();

}


void student::result()
{
    clear();
	int f=10;
    gotoXY(f,11);
    cout<<".---------------------------------------------------------------------------------------------."<<endl;
    gotoXY(f,12);
    cout<<"| .-----------------------------------------------------------------------------------------. |"<<endl;
    gotoXY(f,13);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,14);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,15);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,16);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,17);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,18);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,19);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,20);
    cout<<"| |                                                                                         | |"<<endl;
    gotoXY(f,21);
    cout<<"| .-----------------------------------------------------------------------------------------. |"<<endl;
    gotoXY(f,22);
    cout<<".---------------------------------------------------------------------------------------------."<<endl;
	gotoXY(35,14);
    cout<<"THANKYOU FOR PLAYING BUDDY"<<endl;
    gotoXY(35,15);
    cout<<"Correct answer:   "<<win;
    gotoXY(35,16);
    cout<<"Incorrect answer:   "<<lose;
    gotoXY(35,17);
    cout<<"Unattempt:   "<<unattempt;
    gotoXY(35,18);
    cout<<"Rewards:   "<<reward;
	gotoXY(35,19);
	cout<<"Total question: "<<total;
    gotoXY(35,20);
    cout<<"Percent:   "<<percent;
    gotoXY(60,24);
    cout<<"Next: ";
    gotoXY(70,24);
    getch();
    firstscreen();
}

void student::class_result(){
    clear();
    int f=10,y=14,i=0;
    gotoXY(f,9);
    cout<<".----------------------------------------------------------------------------------------------------.";
    gotoXY(50,10);
    cout<<"RECORD";
    gotoXY(f,11);
    cout<<"| .------------------------------------------------------------------------------------------------. |";
    string u;
    int w,l,un,r,t,p;
    gotoXY(f+1,12);
    cout<<"| |"<<setw(10)<<"Win"<<setw(15)<<"Lose"<<setw(15)<<"Unattempt"<<setw(15)<<"Reward"<<setw(15)<<"Total"<<setw(15)<<"Percent"<<"| |"<<endl;
    ifstream infile("record.txt");
    infile>>u>>w>>l>>un>>r>>t>>p;
    do{
        if(u==name){
            gotoXY(f,y+i);
    cout<<"| |                                                                                               | |";
            gotoXY(f+4,y+i);
            cout<<setw(10)<<w<<setw(15)<<l<<setw(15)<<un<<setw(15)<<r<<setw(15)<<t<<setw(15)<<p<<endl;
            i++;
        }
    }while(infile>>u>>w>>l>>un>>r>>t>>p && !infile.eof());
    infile.close();
    gotoXY(f,y+i);
    cout<<"| .----------------------------------------------------------------------------------------------. |";
    gotoXY(f,y+1+i);
    cout<<".--------------------------------------------------------------------------------------------------.";
    cout<<endl;
    cout<<"Exit: ";
    getch();
    firstscreen(); 
}


void student::zeroscreen()		//simply desgin screen
{
	clear(); 
	welcome();
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	gotoXY(50,14);
	cout<<"1-->  Login";
	gotoXY(50,16);
	cout<<"2-->  Signup";
	gotoXY(42,20);
	cout<<"Select : ";  
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
	int type;
	gotoXY(50,20);
	cin>>type;	
	switch(type)
	{
		case 1:
			{
			clear();
            login();
			break;
			}
	case 2:
			{
			clear();
            signup();
			break;
			}
			
	default:
	        {
            gotoXY(50,20);
            cout<<"INVALID CHOICE";
            _getch();
            zeroscreen();
		}		
	}
}


void student::firstscreen()		//simply desgin screen
{
	clear(); 
	welcome();
    cout<<"\n\t\t\t---------------------------------------------------------------------------------";
    gotoXY(50,14);
	cout<<"1--> Test mode ";
    gotoXY(50,16);
	cout<<"2--> Practice mode ";
	gotoXY(50,18);
	cout<<"3-->  How to play";
	gotoXY(50,20);
	cout<<"4-->  Result Record";  
    gotoXY(50,22);
	cout<<"5-->  Quit"; 
	gotoXY(42,26);
	cout<<"Select : ";    
    cout<<"\n\n\n\t\t\t---------------------------------------------------------------------------------";                               
	int type;
	gotoXY(50,26);
	cin>>type;	
	switch(type)
	{
		case 1:
			{
			student st;
			clear();
			test_quiz();
			break;
			}
        case 2:
			{
			student st;
			clear();
			practice_quiz();
			break;
			}
	    case 3:
			{
			clear();
			cout<<"Instruction";
			info();
			_getch();
			firstscreen();
			break;
			}
	    case 4:
			{
            _getch();
			class_result();
			_getch();
			break;
			}
        case 5:
            {
            clear();
            exit(0);
            }
	    default:
            {
			cout<<"/n INVALID CHOICE";
            _getch();
            firstscreen();
	        }
}
}

void student::welcome(){
    cout<<"\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  "<<endl;
	cout<<"\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ "<<endl;
	cout<<"\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ "<<endl;
	cout<<"\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| "<<endl;
}

int main(){
    student st;
	st.zeroscreen();
	return 0;
}