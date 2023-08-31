#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

string username[]={"user_name"};
string userpass[]={"user_pass"};
int user_login(string name,string pass){
	int index=0;
	fstream usrlogin;
	usrlogin.open("userlog.txt",ios ::in);
	while(username[0] != "\0"){
		usrlogin >> username[0];
		index++;
		if(username[0]==name)
		{
			fstream usrpass;
			usrpass.open("userpass.txt" , ios :: in );
			cout << index << endl;
			for(int i=0 ; i<index ; i++){
				usrpass >> userpass[0];
			}
			if(userpass[0]== pass)
			{
				cout << "Login SUCCESS NOW U Can use as user"<< endl;
				usrpass.close();
				usrlogin.close();
				break;	
			}
			else
			{
				cout << "Wrong Password! Enter username and password again" <<endl;
				usrpass.close();
                                usrlogin.close();
				break;
			}
		}
		
		

}
cout << "Your User name might be incorrect or not found" <<endl;
cout << "Please Renter User Name or creat new user account" <<endl;
cout << "To Creat New User Please Enter 2"<<endl;
usrlogin.close();
cin >> index;
return index;
}
