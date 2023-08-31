#include"admin.hpp"
#include"user.hpp"
int diff(string usrname);
void list();
void view(string name);
void del(string name);

int main(){
int mainctl=1;
while(mainctl==1){
	int new_acc=0;
	bool pro_ctl=true;
	string name,pass;
	int permission=0;
	int acc_diff=0;
	cout << "If u don't want to use this program input 0 to stop or 1 to continue"<<endl;
	cin >> mainctl;
	cout << "Enter Username and Password :: "<<endl;
	cin >> name;
	cin >> pass;
	acc_diff = diff(name);
if(mainctl==0){
	break;
}
else if (new_acc==2){
//need to creat function for new acc
}
else if (acc_diff==1){
		cout<<"Login as Admin-acc"<<endl;
		permission=admin_login(name,pass);
		if(permission == 1){
			while (pro_ctl){
			cout << "press 1 to see list"<< endl;
			cout << "press 2 to view the desire book" << endl;
			cout << "press 3 to delete the desire book" << endl;
			cout << "press 4 to exit"<< endl;
			cout << "Warning! to view the desire book, you need to view the list of books" << endl;
			int choi;
			cin >> choi;
			string bname="";
			switch (choi){
				case 1:
					list();
					break;
					
				case 2:
					cout << "Enter the exact book name or type exit to go back and view the book list" << endl;
					cin >> bname;
					if (bname == "exit")
					{
						break;
					} else if (bname.empty())
					{
						cout << "Invalid input! Input procress again!";
						break;
					}
					
					else
					{
						view(bname);
					}
				case 3:
					cout << "Enter the exact book name or type exit to go back and view the book list" << endl;
					cin >> bname;
					if (bname == "exit")
					{
						break;
					}else if (bname.empty())
					{
						cout << "Invalid input! Input procress again!";
						break;
					}
					else
					{
						del(bname);
					}

				case 4:
					pro_ctl=false;
						
				default:
					cout << "Invalid Input! Try Again!" << endl;

			}	
			}	
	
		}
		else{
				cout << "WoW you know how this program works but not the password. Goodbye Great Guess but no permission!" <<endl;
				mainctl=0;
		}
	}
	else{
		cout<<"Login as User-acc"<<endl;
		new_acc = user_login(name,pass);
		if (new_acc==1)
		{	
			while (pro_ctl){
			cout << "press 1 to see list"<< endl;
                	cout << "press 2 to view the desire book" << endl;
               		cout << "press 3 to exit"<< endl;
                        cout << "Warning! to view the desire book, you need to view the list of books" << endl;
			int choi;
                        cin >> choi;
                        string bname="";
                        switch (choi){
                                case 1:
                                        list();
                                        break;

                                case 2:
                                        cout << "Enter the exact book name or type exit to go back and view the book list" << endl;
                                        cin >> bname;
                                        if (bname == "exit")
                                        {
                                                break;
                                        } else if (bname.empty())
                                        {
                                                cout << "Invalid input! Input procress again!";
                                                break;
                                        }

                                        else
                                        {
                                                view(bname);
                                        }
				case 3:
                                        pro_ctl=false;

                                default:
                                        cout << "Invalid Input! Try Again!" << endl;
			}
			}

		}
		else
		{
			cout << "Your User name might be incorrect or not found" <<endl;
			cout << "Please Renter User Name or creat new user account" <<endl;
			cout << "To Creat New User Please Enter 2"<<endl;
			cin >> new_acc;
		}
	}
	
return 0;
}
}

int diff(string usrname){
	int access=0;
	for(int i=0; i<usrname.length() ; i++){	
		if (usrname[i]=='$'){
			access=1;
			break;
		}
		else{
			access=0;
		}
	}
return access;
			
}

void list(){
	string lst;
	system("ls books/ > temp.txt");
	ifstream list;
	list.open("temp.txt");
	while(getline(list,lst)){
		cout << lst << endl;
		}
	list.close();
}


void view(string name){
	string req="evince books/"+name;
	const char *smth= req.c_str();
	system(smth);
}


void del(string name){
	string req="rm books/"+ name;
	const char *smth= req.c_str();
	system(smth);


}
