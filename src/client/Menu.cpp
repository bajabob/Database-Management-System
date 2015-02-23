#include "Menu.h"
#include<iostream>
#include <string>

using namespace std;
void main_menu();
void post_menu(){
	cout<<"[Post title]\n"; //to be replaced
	cout<<"1. View\n";
	cout<<"2. Edit\n";
	cout<<"3. Delete\n";
	cout<<"4. Comment\n";
	cout<<"5. Return to Main Menu\n";
	int opt;
	cout<<"* Enter command: ";
	cin>>opt;
	switch(opt){
		case 1:
		//call DB*********
		break;

		case 2:
		//call DB*********
		//(THIS IS JUST A SIMPLE REPLACE, NO TEXT EDITOR FUNCTIONALITY)
		break;

		case 3:
		//DB do your thing**************
		break;

		case 4:
		//DB do your thing************
		//bring up current comments
		//need to add comment on post or comment on comment
		break;

		case 5:
		main_menu();
		break;

		default:
		main_menu();
		break;
	}
}
void search_post(){
	cout<<"[Search Menu]\n";
	cout<<"Search by: \n";
	cout<<"1. Author \n";
	cout<<"2. Title \n";
	cout<<"3. Tag(s)\n";
	cout<<"4. Date\n";
	cout<<"5. Return to Main Menu\n";

	cout<<"* Enter command: ";
	int opt;
	cin>>opt;
	switch(opt){
		case 1: {
		cout<<"\n Enter author: ";
		string auth;
		cin>>auth;
		//call to DB for auth's posts**********
		//AFTER WE GET POSTS FROM DB:
		//"cout all the posts for auth *numbered "
		cout<<"* Enter ID: ";
		int ID;
		cin>>ID;
		cout<<"//somehow tell DB we want ID";
		}
		break;

		case 2: {
		cout<<"\n Enter title: ";
		string title;
		cin>>title;
		cout<<"//call to DB for title***********";
		cout<<"* Enter ID: ";
		int ID_title;
		cin>>ID_title;
		cout<<"//pull up from DB";
		}
		break;

		case 3:{
		cout<<"Enter Tag(s) separated by spaces \n";
		//call DB for Tags*************
		cout<<"* Enter ID: ";
		int ID_Tag;
		cin>>ID_Tag;
		//somehow tell DB we want tag
		}
		break;

		case 4: {
		cout<<"Enter Date(MMDDYYYY): ";
		int date;
		cin>>date;
		//call DB for Date*************
		cout<<"* Enter ID: ";
		int ID_date;
		cin>>ID_date;
		//somehow tell DB we want date
		}
		break;

		case 5:{
		main_menu();
		}
		break;

		default:
		main_menu();
		break;

	}
}

void add_post(){
	// call DB to add post**********
	cout<<"this will be added later";
}

void main_menu(){
	cout<<"[Main Menu]\n";
	cout<<"1. Make a new post\n";
	cout<<"2. Search for a post\n";
	cout<<"3. Exit\n";
	cout<<"* Enter command: ";
	int opt;
	cin>>opt;

	switch(opt){
		case 1:{
		add_post();
		}
		break;

		case 2:{
		search_post();
		}
		break;

		case 3:{
		cout<<"\ngoodbye.";
		}
		break;

		default:{
		cout<<"\nnot an option, goodbye.";
		}
		break;

	}


} 
int main(){
	main_menu();
	return 0;
}
