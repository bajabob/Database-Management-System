<<<<<<< HEAD

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
    int y = now->tm_year + 1900; //year 
    int m = now->tm_mon + 1; //month
    int d =  now->tm_mday;//date
    stringstream ss; //convert int to string
    ss <<0<<m<<0<<d<<y;
    string str = ss.str();
    return str;
        
}
string index_str(){
	//convert int to string
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
		//show the post and all its attributes
		string query =  auth+"_post<-select(Index =="+ID+")posts;";
		ExecuteQuery(query);
		//print
		query = "SHOW "+auth+"_post;";
		ExecuteQuery(query);
		post_menu(auth, ID);
		}
		break;
		case 2:{
		string dummy;
		getline(cin, dummy);
		//clear for getline
		cout<<"* Enter new content:";
		string words;
		getline(cin, words);
		//(THIS IS JUST A SIMPLE REPLACE, NO TEXT EDITOR FUNCTIONALITY)
		//change contents attribute to words
		string query = "UPDATE posts SET Contents = \""+words+"\" WHERE Index=="+ID+";"; 
		ExecuteQuery(query);
		//print to screen
		query = "WRITE posts;";
		ExecuteQuery(query);
		cout<<"Content updated.\n";
		//bring up other options
		post_menu(auth, ID);
		}
		break;
		case 3:{
		//DB do your thing**************
		//delete the post
		string query = "DELETE FROM posts WHERE Index=="+ID+";";
		ExecuteQuery(query);
		query = "WRITE posts;";
		ExecuteQuery(query);
		cout<<"Post Deleted.\n";
		//go back to main since there is no more post to look at
		main_menu();
		}
		break;
		case 4:{
		//show current posts
		string query =  auth+"_post<-select(Index =="+ID+")posts;";
		ExecuteQuery(query);
		//just want the comments
		query = auth+"_comments<- project (Comment1, Comment2)("+auth+"_post);";
		ExecuteQuery(query);
		//print comments
		query = "SHOW "+auth+"_comments;";
		ExecuteQuery(query);
		//pick one 
		cout<<"* Would you like to change Comment1 or Comment2(1 or 2): ";
		string num;
		cin>>num;
		//clear for next gitline
		string dummy;
		getline(cin, dummy);
		//no periods pls
		cout<<"* Enter your name & comment: ";
		string words;
		getline(cin, words);
		//change the comment
		query = "UPDATE posts SET Comment"+num+" = \""+words+"\" WHERE Index=="+ID+";";
		ExecuteQuery(query);
		//save it permanently
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
		//clears left over character from cin
		string dummy;
		getline(cin, dummy);
		cout<<"\n Enter author: ";
		string auth, query;
		getline(cin, auth);
		cout<<endl<<auth<<"'s Posts\n";
		//put posts by auth into relation auth
		query = auth+"<- select (Author == \""+auth+"\") posts;";
		ExecuteQuery(query);
		//put only Title and Index column into auth_titles
		query = auth+"_titles<- project (Title, Index)("+auth+");";
		ExecuteQuery(query);
		//print to screen auth_titles
		query = "SHOW "+auth+"_titles;";
		ExecuteQuery(query);
		//make the user choose which post to see
		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		//put into authID the one post they wanted to see
		//still only shows index and title
		query = auth+"ID<- select ( Index == "+ID+")"+auth+"_titles;";
		ExecuteQuery(query);
		//print authID to the screen
		query = "SHOW "+auth+"ID;";
		ExecuteQuery(query);
		//bring up options for the selected post
		post_menu(auth, ID);
		}
		break;

		case 2: {
		//make sure we are clear to getline
		string dummy, title;
		getline(cin, dummy);
		//title to search by
		cout<<"\n Enter title: ";
		getline(cin, title);
		//put posts with the Title title into relation title
		string query = title+"<- select (Title == \""+title+"\") posts;";
		ExecuteQuery(query);
		//we only want the title and index displayed
		query = title+"_titles<- project (Title, Index)("+title+");";
		ExecuteQuery(query);
		//print titles and index to screen
		query = "SHOW "+title+"_titles;";
		ExecuteQuery(query);
		//pick one user
		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		//select the single title
		query = title+"ID<- select ( Index == "+ID+")"+title+"_titles;";
		ExecuteQuery(query);
		//print it to the screen
		query = "SHOW "+title+"ID;";
		ExecuteQuery(query);
		//options for chosen post
		post_menu(title, ID);

		}
		break;

		case 3:{
		int num_tags;
		cout<<"Search by 1 or 2 tags(1 or 2):  \n";
		cin>>num_tags;
		if(num_tags==1){
			//clear any extra characters
			string dummy, tag1;
			getline(cin, dummy);
			cout<<"\n Enter tag: ";
			getline(cin, tag1);
			//we want to search for tag1
			string query = tag1+"<- select (Tag1 == \""+tag1+"\" || Tag2 == \""+tag1+"\" ) posts;";
			ExecuteQuery(query);
			//we only want the title and Index
			query = tag1+"_titles<- project (Title, Index)("+tag1+");";
			ExecuteQuery(query);
			//print it
			query = "SHOW "+tag1+"_titles;";
			ExecuteQuery(query);
			//pick one user!
			cout<<"* Enter ID: ";
			string ID;
			cin>>ID;
			//only the one
			query = tag1+"ID<- select ( Index == "+ID+")"+tag1+"_titles;";
			ExecuteQuery(query);
			//print it
			query = "SHOW "+tag1+"ID;";
			ExecuteQuery(query);
			//bring up its menu
			post_menu(tag1, ID);


		}
		else if(num_tags==2){
		
			string dummy, tag2, tag3;
			getline(cin, dummy);
			cout<<"Enter two Tags separated by spaces: ";
			cin>>tag2>>tag3;
			//get matches for tag2
			string query = tag2+"<- select (Tag1 == \""+tag2+"\" || Tag2 == \""+tag2+"\" ) posts;";
			ExecuteQuery(query);
			//add matches for tag3
			query = tag3+"<- "+tag2+"+ (select (Tag1 == \""+tag3+"\" || Tag2 == \""+tag3+"\" ) posts);";
			ExecuteQuery(query);
			//we want only the title and index
			query = tag2+tag3+"_titles<- project (Title, Index)("+tag3+");";
			ExecuteQuery(query);
			//print
			query = "SHOW "+tag2+tag3+"_titles;";
			ExecuteQuery(query);
			//pick one
			cout<<"* Enter ID: ";
			string ID;
			cin>>ID;
			//get only 1
			query = tag2+tag3+"ID<- select ( Index == "+ID+")"+tag2+tag3+"_titles;";
			ExecuteQuery(query);
			//print the 1
			query = "SHOW "+tag2+tag3+"ID;";
			ExecuteQuery(query);
			//bring up its menu
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
		//search for the date
		string query = "name<- select (Date == \""+date+"\") posts;";
		ExecuteQuery(query);
		//only show title and index
		query = "_titles<- project (Title, Index)(name);";
		ExecuteQuery(query);
		//print it
		query = "SHOW _titles;";
		ExecuteQuery(query);
		//pick one
		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		//select the 1
		query = "ID<- select ( Index == "+ID+")_titles;";
		ExecuteQuery(query);
		//print the 1
		query = "SHOW ID;";
		ExecuteQuery(query);
		//bring up its menu
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
	//clear cin
	string dummy;
	getline(cin, dummy);
	//get all attributes except comments
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
	//put it into db
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"" + Author +"\", \""
	 	+Title+"\", \""+Contents+"\", \""+Tag1+"\", \""+Tag2+"\", \""
	 	+Date+"\", \"l \", \"l \");";
	ExecuteQuery(query);
	cout<<"Post Created.";
	//save it
	query = "WRITE posts;";
	ExecuteQuery(query);
	//increment our index
	index++;
	main_menu();

}



void initialize() {
	//make it have a few values so can test right away
	string query = "CREATE TABLE posts (Index INTEGER, Author VARCHAR(70), Title VARCHAR(50), Contents VARCHAR(200), Tag1 VARCHAR(20), Tag2 VARCHAR(20), Date VARCHAR(8), Comment1 VARCHAR(20), Comment2 VARCHAR(20)) PRIMARY KEY (Author, Title);";
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Nikki\", \"good netflix\", \"house of cards\", \"Netflix\", \"KevinSpacey\", \"11121992\", \" \", \" \");";
	index++;//increment index
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Nikki\", \"My Pets\", \"Dixie Sophie Pippa Ruby\", \"Animals\", \"cats\", \"03072015\", \" \", \" \");";
	index++;
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Anna\", \"Good Netflix\", \"Pretty Little Liars\", \"Netflix\", \"PLL\", \"11121992\", \" \", \" \");";
	index++;
	ExecuteQuery(query);	
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"John\", \"Good Netflix\", \"Attack on Titan\", \"Netflix\", \"Anime\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;	
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Bob\", \"Motor Cycles\", \"I have a white helmet\", \"team6\", \"Bikes\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Raf\", \"Motor Cycles\", \"I wrote json code because im cool\", \"team6\", \"Bikes\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Michael\", \"I write code\", \"I wrote the parser\", \"team6\", \"Football\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;
	query = "WRITE posts;";
	ExecuteQuery(query);
	//save
	
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
=======

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
    int y = now->tm_year + 1900; //year 
    int m = now->tm_mon + 1; //month
    int d =  now->tm_mday;//date
    stringstream ss; //convert int to string
    ss <<0<<m<<0<<d<<y;
    string str = ss.str();
    return str;
        
}
string index_str(){
	//convert int to string
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
		//show the post and all its attributes
		string query =  auth+"_post<-select(Index =="+ID+")posts;";
		ExecuteQuery(query);
		//print
		query = "SHOW "+auth+"_post;";
		ExecuteQuery(query);
		post_menu(auth, ID);
		}
		break;
		case 2:{
		string dummy;
		getline(cin, dummy);
		//clear for getline
		cout<<"* Enter new content:";
		string words;
		getline(cin, words);
		//(THIS IS JUST A SIMPLE REPLACE, NO TEXT EDITOR FUNCTIONALITY)
		//change contents attribute to words
		string query = "UPDATE posts SET Contents = \""+words+"\" WHERE Index=="+ID+";"; 
		ExecuteQuery(query);
		//print to screen
		query = "WRITE posts;";
		ExecuteQuery(query);
		cout<<"Content updated.\n";
		//bring up other options
		post_menu(auth, ID);
		}
		break;
		case 3:{
		//DB do your thing**************
		//delete the post
		string query = "DELETE FROM posts WHERE Index=="+ID+";";
		ExecuteQuery(query);
		query = "WRITE posts;";
		ExecuteQuery(query);
		cout<<"Post Deleted.\n";
		//go back to main since there is no more post to look at
		main_menu();
		}
		break;
		case 4:{
		//show current posts
		string query =  auth+"_post<-select(Index =="+ID+")posts;";
		ExecuteQuery(query);
		//just want the comments
		query = auth+"_comments<- project (Comment1, Comment2)("+auth+"_post);";
		ExecuteQuery(query);
		//print comments
		query = "SHOW "+auth+"_comments;";
		ExecuteQuery(query);
		//pick one 
		cout<<"* Would you like to change Comment1 or Comment2(1 or 2): ";
		string num;
		cin>>num;
		//clear for next gitline
		string dummy;
		getline(cin, dummy);
		//no periods pls
		cout<<"* Enter your name & comment: ";
		string words;
		getline(cin, words);
		//change the comment
		query = "UPDATE posts SET Comment"+num+" = \""+words+"\" WHERE Index=="+ID+";";
		ExecuteQuery(query);
		//save it permanently
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
		//clears left over character from cin
		string dummy;
		getline(cin, dummy);
		cout<<"\n Enter author: ";
		string auth, query;
		getline(cin, auth);
		cout<<endl<<auth<<"'s Posts\n";
		//put posts by auth into relation auth
		query = auth+"<- select (Author == \""+auth+"\") posts;";
		ExecuteQuery(query);
		//put only Title and Index column into auth_titles
		query = auth+"_titles<- project (Title, Index)("+auth+");";
		ExecuteQuery(query);
		//print to screen auth_titles
		query = "SHOW "+auth+"_titles;";
		ExecuteQuery(query);
		//make the user choose which post to see
		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		//put into authID the one post they wanted to see
		//still only shows index and title
		query = auth+"ID<- select ( Index == "+ID+")"+auth+"_titles;";
		ExecuteQuery(query);
		//print authID to the screen
		query = "SHOW "+auth+"ID;";
		ExecuteQuery(query);
		//bring up options for the selected post
		post_menu(auth, ID);
		}
		break;

		case 2: {
		//make sure we are clear to getline
		string dummy, title;
		getline(cin, dummy);
		//title to search by
		cout<<"\n Enter title: ";
		getline(cin, title);
		//put posts with the Title title into relation title
		string query = title+"<- select (Title == \""+title+"\") posts;";
		ExecuteQuery(query);
		//we only want the title and index displayed
		query = title+"_titles<- project (Title, Index)("+title+");";
		ExecuteQuery(query);
		//print titles and index to screen
		query = "SHOW "+title+"_titles;";
		ExecuteQuery(query);
		//pick one user
		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		//select the single title
		query = title+"ID<- select ( Index == "+ID+")"+title+"_titles;";
		ExecuteQuery(query);
		//print it to the screen
		query = "SHOW "+title+"ID;";
		ExecuteQuery(query);
		//options for chosen post
		post_menu(title, ID);

		}
		break;

		case 3:{
		int num_tags;
		cout<<"Search by 1 or 2 tags(1 or 2):  \n";
		cin>>num_tags;
		if(num_tags==1){
			//clear any extra characters
			string dummy, tag1;
			getline(cin, dummy);
			cout<<"\n Enter tag: ";
			getline(cin, tag1);
			//we want to search for tag1
			string query = tag1+"<- select (Tag1 == \""+tag1+"\" || Tag2 == \""+tag1+"\" ) posts;";
			ExecuteQuery(query);
			//we only want the title and Index
			query = tag1+"_titles<- project (Title, Index)("+tag1+");";
			ExecuteQuery(query);
			//print it
			query = "SHOW "+tag1+"_titles;";
			ExecuteQuery(query);
			//pick one user!
			cout<<"* Enter ID: ";
			string ID;
			cin>>ID;
			//only the one
			query = tag1+"ID<- select ( Index == "+ID+")"+tag1+"_titles;";
			ExecuteQuery(query);
			//print it
			query = "SHOW "+tag1+"ID;";
			ExecuteQuery(query);
			//bring up its menu
			post_menu(tag1, ID);


		}
		else if(num_tags==2){
		
			string dummy, tag2, tag3;
			getline(cin, dummy);
			cout<<"Enter two Tags separated by spaces: ";
			cin>>tag2>>tag3;
			//get matches for tag2
			string query = tag2+"<- select (Tag1 == \""+tag2+"\" || Tag2 == \""+tag2+"\" ) posts;";
			ExecuteQuery(query);
			//add matches for tag3
			query = tag3+"<- "+tag2+"+ (select (Tag1 == \""+tag3+"\" || Tag2 == \""+tag3+"\" ) posts);";
			ExecuteQuery(query);
			//we want only the title and index
			query = tag2+tag3+"_titles<- project (Title, Index)("+tag3+");";
			ExecuteQuery(query);
			//print
			query = "SHOW "+tag2+tag3+"_titles;";
			ExecuteQuery(query);
			//pick one
			cout<<"* Enter ID: ";
			string ID;
			cin>>ID;
			//get only 1
			query = tag2+tag3+"ID<- select ( Index == "+ID+")"+tag2+tag3+"_titles;";
			ExecuteQuery(query);
			//print the 1
			query = "SHOW "+tag2+tag3+"ID;";
			ExecuteQuery(query);
			//bring up its menu
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
		//search for the date
		string query = "name<- select (Date == \""+date+"\") posts;";
		ExecuteQuery(query);
		//only show title and index
		query = "_titles<- project (Title, Index)(name);";
		ExecuteQuery(query);
		//print it
		query = "SHOW _titles;";
		ExecuteQuery(query);
		//pick one
		cout<<"* Enter ID: ";
		string ID;
		cin>>ID;
		//select the 1
		query = "ID<- select ( Index == "+ID+")_titles;";
		ExecuteQuery(query);
		//print the 1
		query = "SHOW ID;";
		ExecuteQuery(query);
		//bring up its menu
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
	//clear cin
	string dummy;
	getline(cin, dummy);
	//get all attributes except comments
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
	//put it into db
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"" + Author +"\", \""
	 	+Title+"\", \""+Contents+"\", \""+Tag1+"\", \""+Tag2+"\", \""
	 	+Date+"\", \"l \", \"l \");";
	ExecuteQuery(query);
	cout<<"Post Created.";
	//save it
	query = "WRITE posts;";
	ExecuteQuery(query);
	//increment our index
	index++;
	main_menu();

}



void initialize() {
	//make it have a few values so can test right away
	string query = "CREATE TABLE posts (Index INTEGER, Author VARCHAR(70), Title VARCHAR(50), Contents VARCHAR(200), Tag1 VARCHAR(20), Tag2 VARCHAR(20), Date VARCHAR(8), Comment1 VARCHAR(20), Comment2 VARCHAR(20)) PRIMARY KEY (Author, Title);";
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Nikki\", \"good netflix\", \"house of cards\", \"Netflix\", \"KevinSpacey\", \"11121992\", \" \", \" \");";
	index++;//increment index
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Nikki\", \"My Pets\", \"Dixie Sophie Pippa Ruby\", \"Animals\", \"cats\", \"03072015\", \" \", \" \");";
	index++;
	ExecuteQuery(query);
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Anna\", \"Good Netflix\", \"Pretty Little Liars\", \"Netflix\", \"PLL\", \"11121992\", \" \", \" \");";
	index++;
	ExecuteQuery(query);	
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"John\", \"Good Netflix\", \"Attack on Titan\", \"Netflix\", \"Anime\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;	
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Bob\", \"Motor Cycles\", \"I have a white helmet\", \"team6\", \"Bikes\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Raf\", \"Motor Cycles\", \"I wrote json code because im cool\", \"team6\", \"Bikes\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;
	query = "INSERT INTO posts VALUES FROM ("+index_str()+", \"Michael\", \"I write code\", \"I wrote the parser\", \"team6\", \"Football\", \"03062015\", \" \", \" \");";
	ExecuteQuery(query);
	index++;
	query = "WRITE posts;";
	ExecuteQuery(query);
	//save
	
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
>>>>>>> 39450bc1d57b221284ab7a9920ee498884a05892
