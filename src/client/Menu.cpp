
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstdio>
using namespace std;
void main_menu();
int index = 0;
void ExecuteQuery(string query);
 
string get_time() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int y = now->tm_year + 1900;  
    int m = now->tm_mon + 1; 
    int d =  now->tm_mday;
    stringstream ss;
    ss <<0<<m<<0<<d<<y;
    string str = ss.str();
    return str;
        
}
string index_str(){
	stringstream ss;
	int x = index;
	ss <<x;
    string str = ss.str();
    return str;
}

void post_menu(string auth, string ID){
	
	cout<<"1. View\n";
	cout<<"2. Edit\n";
	cout<<"3. Delete\n";
	cout<<"4. Comment\n";
	cout<<"5. Return to Main Menu\n";
	int opt;
	cout<<"* Enter command: ";
	cin>>opt;
	switch(opt){
		case 1:{
		string query =  auth+"_post<-select(Index =="+ID+")posts;";
		ExecuteQuery(query);
		query = "SHOW "+auth+"_post;";
		ExecuteQuery(query);
		post_menu(auth, ID);
		}
		break;
		case 2:{
		string dummy;
		getline(cin, dummy);
		cout<<"* Enter new content:";
		string words;
		getline(cin, words);
		string query = "UPDATE posts SET Contents = \""+words+"\" WHERE Index=="+ID+";"; 
		//(THIS IS JUST A SIMPLE REPLACE, NO TEXT EDITOR FUNCTIONALITY)
		ExecuteQuery(query);
		query = "WRITE posts;";
		ExecuteQuery(query);

		cout<<"Content updated.\n";
		post_menu(auth, ID);
		}
		break;
		case 3:{
		//DB do your thing**************
		string query = "DELETE FROM posts WHERE Index=="+ID+";";
		ExecuteQuery(query);
		query = "WRITE posts;";
		ExecuteQuery(query);
		cout<<"Post Deleted.\n";
		main_menu();
		}
		break;
		case 4:{
		//DB do your thing************
		string query =  auth+"_post<-select(Index =="+ID+")posts;";
		ExecuteQuery(query);
		query = auth+"_comments<- project (Comment1, Comment2)("+auth+"_post);";
		//bring up current comments
		ExecuteQuery(query);
		query = "SHOW "+auth+"_comments;";
		ExecuteQuery(query);
		cout<<"* Would you like to change Comment1 or Comment2(1 or 2): ";
		string num;
		cin>>num;
		string dummy;
		getline(cin, dummy);
		cout<<"* Enter your name & comment: ";
		string words;
		getline(cin, words);
		query = "UPDATE posts SET Comment"+num+" = \""+words+"\" WHERE Index=="+ID+";";
		ExecuteQuery(query);
		//need to add comment on post or comment on comment
		query = "WRITE posts;";
		ExecuteQuery(query);
		post_menu(auth, ID);

		}
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
		string dummy;
		getline(cin, dummy);
		cout<<"\n Enter author: ";
		string auth, query;
		getline(cin, auth);
		cout<<endl<<auth<<"'s Posts\n";
		query = auth+"<- select (Author == \""+auth+"\") posts;";
		ExecuteQuery(query);
		//query = "CREATE TABLE "+auth+" (Author VARCHAR(70), Title VARCHAR(50), Contents VARCHAR(200), Tag1 VARCHAR(20), Tag2 VARCHAR(20), Date VARCHAR(8), Comment1 VARCHAR(20), Comment2 VARCHAR(20)) PRIMARY KEY (Author, Title);";
		//ExecuteQuery(query);
		//query = "INSERT INTO "+auth+" VALUES FROM RELATION project (Author, Title, Content, Tag1, Tag2, Date, Comment1, Comment2)"+auth+"q;" ;
		//ExecuteQuery(query);

		query = auth+"_titles<- project (Title, Index)("+auth+");";
		ExecuteQuery(query);
		query = "SHOW "+auth+"_titles;";
		ExecuteQuery(query);

		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		query = auth+"ID<- select ( Index == "+ID+")"+auth+"_titles;";
		ExecuteQuery(query);
		query = "SHOW "+auth+"ID;";
		ExecuteQuery(query);
		post_menu(auth, ID);
		}
		break;

		case 2: {
		string dummy, title;
		getline(cin, dummy);
		cout<<"\n Enter title: ";
		getline(cin, title);
		string query = title+"<- select (Title == \""+title+"\") posts;";
		ExecuteQuery(query);
		query = title+"_titles<- project (Title, Index)("+title+");";
		ExecuteQuery(query);
		query = "SHOW "+title+"_titles;";
		ExecuteQuery(query);

		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		query = title+"ID<- select ( Index == "+ID+")"+title+"_titles;";
		ExecuteQuery(query);
		query = "SHOW "+title+"ID;";
		ExecuteQuery(query);
		post_menu(title, ID);

		}
		break;

		case 3:{
		int num_tags;
		cout<<"Search by 1 or 2 tags(1 or 2):  \n";
		cin>>num_tags;
		if(num_tags==1){
			string dummy, tag1;
			getline(cin, dummy);
			cout<<"\n Enter tag: ";
			getline(cin, tag1);
			string query = tag1+"<- select (Tag1 == \""+tag1+"\" || Tag2 == \""+tag1+"\" ) posts;";
			ExecuteQuery(query);

			query = tag1+"_titles<- project (Title, Index)("+tag1+");";
			ExecuteQuery(query);
			query = "SHOW "+tag1+"_titles;";
			ExecuteQuery(query);

			cout<<"* Enter ID: ";
			string ID;
			cin>>ID;
			query = tag1+"ID<- select ( Index == "+ID+")"+tag1+"_titles;";
			ExecuteQuery(query);
			query = "SHOW "+tag1+"ID;";
			ExecuteQuery(query);
			post_menu(tag1, ID);


		}
		else if(num_tags==2){
		
		//call DB for Tags*************
			string dummy, tag2, tag3;
			getline(cin, dummy);
			cout<<"Enter two Tags separated by spaces: ";
			cin>>tag2>>tag3;
			string query = tag2+"<- select (Tag1 == \""+tag2+"\" || Tag2 == \""+tag2+"\" ) posts;";
			ExecuteQuery(query);
			query = tag3+"<- "+tag2+"+ (select (Tag1 == \""+tag3+"\" || Tag2 == \""+tag3+"\" ) posts);";
			ExecuteQuery(query);

			query = tag2+tag3+"_titles<- project (Title, Index)("+tag3+");";
			ExecuteQuery(query);
			query = "SHOW "+tag2+tag3+"_titles;";
			ExecuteQuery(query);

			cout<<"* Enter ID: ";
			string ID;
			cin>>ID;
			query = tag2+tag3+"ID<- select ( Index == "+ID+")"+tag2+tag3+"_titles;";
			ExecuteQuery(query);
			query = "SHOW "+tag2+tag3+"ID;";
			ExecuteQuery(query);
			post_menu(tag2+tag3, ID);

		}
		else{
			cout<<"oops";
			main_menu();
		}
		}
		break;

		case 4: {
		cout<<"Enter Date(MMDDYYYY): ";
		string date;
		cin>>date;
		//call DB for Date*************
		string query = "name<- select (Date == \""+date+"\") posts;";
		ExecuteQuery(query);
		query = "_titles<- project (Title, Index)(name);";
		ExecuteQuery(query);
		query = "SHOW _titles;";
		ExecuteQuery(query);

		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		query = "ID<- select ( Index == "+ID+")_titles;";
		ExecuteQuery(query);
		query = "SHOW ID;";
		ExecuteQuery(query);
		post_menu("dd", ID);
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
	string Author, Title, Contents, Tag1, Tag2, Date, query = string("");
	int numTags;
	string dummy;
	getline(cin, dummy);
	cout<<"\n* Enter Author: ";
	getline(cin, Author);
	cout<<"\n* Enter Title: ";
	getline(cin, Title);
	cout<<"\n* Enter Post: ";
	getline(cin, Contents);
	cout<<"\n* Enter First Tag: ";
	getline(cin, Tag1);
	cout<<"\n* Enter Second Tag: ";
	getline(cin,Tag2);
	Date = get_time();
	
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"" + Author +"\", \""
	 	+Title+"\", \""+Contents+"\", \""+Tag1+"\", \""+Tag2+"\", \""
	 	+Date+"\", \"l \", \"l \");";
	ExecuteQuery(query);
	cout<<"Post Created.";
	index++;
	main_menu();

}



void initialize() {
	
	string query = "CREATE TABLE posts (Index INTEGER, Author VARCHAR(70), Title VARCHAR(50), Contents VARCHAR(200), Tag1 VARCHAR(20), Tag2 VARCHAR(20), Date VARCHAR(8), Comment1 VARCHAR(20), Comment2 VARCHAR(20)) PRIMARY KEY (Author, Title);";
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Nikki\", \"good netflix\", \"house of cards\", \"Netflix\", \"KevinSpacey\", \"11121992\", \"f\", \"f\");";
	index++;
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Nikki\", \"MyPets\", \"DixieSophiePippaRuby\", \"Animals\", \"cats\", \"03072015\", \"d\", \"d\");";
	index++;
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Anna\", \"GoodNetflix\", \"PrettyLittleLiars\", \"Netflix\", \"PLL\", \"11121992\", \"d\", \"d\");";
	index++;
	ExecuteQuery(query);	
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"John\", \"GoodNetflix\", \"AttackonTitan\", \"Netflix\", \"Anime\", \"03062015\", \"d\", \"d\");";
	index++;
	ExecuteQuery(query);
	query = "SHOW posts;";
	ExecuteQuery(query);
}
void main_menu(){
	string query = "SHOW posts;";
	ExecuteQuery(query);
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
	initialize();
	main_menu();

}
