#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


int admin_login(string name,string pass){
	string admin[]={"ad_name","ad_pass"};
	fstream adlogin;
	adlogin.open("adminlog.txt",ios ::in);
		
	for(int i=0 ;i<2;i++){
        	adlogin >> admin[i];
	}
		
	if(name ==admin[0] & pass==admin[1]){
		cout <<"Login as admin is sucess"<<endl;
		adlogin.close();
		return 1;

	}
	else{
		adlogin.close();
	 	return 0;
	}

}
