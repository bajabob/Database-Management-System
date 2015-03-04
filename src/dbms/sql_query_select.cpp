#include "sql_query_select.h"

SQLQuerySelect::SQLQuerySelect(SQLRelation &rel):relation(rel)
	 {
		tups = relation.get_tuples();

	} 
	
int SQLQuerySelect::conv_attr(SQLTuple tup, string operand){
	if(isalpha(operand[0])){
		return stoi(tup.get_data(operand));
	}
	else{
		return stoi(operand);
	}
	
}
	
bool SQLQuerySelect::sel_greater(SQLTuple tup,string attr_1,string num){
	int comp_1;
	int comp_2;
	if(num[0] == '\"' ,attr_1[0]== '\"'){
		cout<<"\nnot a Integer";
		return false;
	}
	comp_1 = conv_attr(tup, attr_1);
	comp_2 = conv_attr(tup, num);
	if(comp_1 > comp_2)
		return true;
	else
		return false;
}
	
bool SQLQuerySelect::sel_greater_equal(SQLTuple tup,string attr_1,string num){
	int comp_1;
	int comp_2;
	if(num[0] == '\"' ,attr_1[0]== '\"'){
		cout<<"\nnot a Integer";
		return false;
	}
	comp_1 = conv_attr(tup, attr_1);
	comp_2 = conv_attr(tup, num);
	if(comp_1 >= comp_2)
		return true;
	else
		return false;
}	
	

bool SQLQuerySelect::sel_lesser(SQLTuple tup,string attr_1,string num){
	int comp_1;
	int comp_2;
	if(num[0] == '\"' ,attr_1[0]== '\"'){
		cout<<"\nnot a Integer";
		return false;
	}
	comp_1 = conv_attr(tup, attr_1);
	comp_2 = conv_attr(tup, num);
	if(comp_1 < comp_2)
		return true;
	else
		return false;
}	
	
	bool SQLQuerySelect::sel_lesser_equal(SQLTuple tup,string attr_1,string num){
		int comp_1;
		int comp_2;
		if(num[0] == '\"' ,attr_1[0]== '\"'){
			cout<<"\nnot a Integer";
			return false;
		}
		comp_1 = conv_attr(tup, attr_1);
		comp_2 = conv_attr(tup, num);		
		if(comp_1 <= comp_2)
			return true;
		else
			return false;
	}		
	
string SQLQuerySelect::conv_attr_2(SQLTuple tup, string operand){	
	
	if(isalpha(operand[0])){
		string comp= tup.get_data(operand);
		comp = "\"" + comp + "\"";
		return comp;
	}
	else if(operand[0]!= '\"'){
		string comp = "\"" + operand + "\"";
		return comp;
	}
	else{
		return operand;
	}	
}
	
bool SQLQuerySelect::sel_equals(SQLTuple tup,string op1,string op2){
	string comp_1= conv_attr_2(tup,op1);
	string comp_2= conv_attr_2(tup,op2);
	
	if(comp_1 == comp_2)
		return true;
	else
		return false;
}
	
bool SQLQuerySelect::sel_not(SQLTuple tup,string op1,string op2){
	string comp_1= conv_attr_2(tup,op1);
	string comp_2= conv_attr_2(tup,op2);
	
	if(comp_1 != comp_2)
		return true;
	else
		return false;
}
					
bool SQLQuerySelect::comparison(SQLTuple tup,string comp){
	bool no_attr = false;// flag
	string op1, op2, op3;
	int i=0;
	if(comp[i]=='\"') {
		op1+='\"';
		i++;
		while(comp[i]!='\"') {
			op1+=comp[i];
			i++;
		}
		op1+='\"';
		i++;
		i++;
	} else {
		while(comp[i]!=' ') {
			op1+=comp[i];
			i++;
		}
		i++;
	}
	while(comp[i]!=' ') {
			op2+=comp[i];
			i++;
	}
	i++;
	if(comp[i]=='\"') {
		op3+='\"';
		i++;
		while(comp[i]!='\"') {
			op3+=comp[i];
			i++;
		}
		op3+='\"';
		i++;
		i++;
	} else {
		while(comp[i]!=' ') {
			op3+=comp[i];
			i++;
		}
		i++;
	}
	if(op2 == ">"){
		return sel_greater(tup,op1,op3);
	} else if(op2 == "<"){
		return sel_lesser(tup,op1,op3);
	} else if(op2 == "<="){
		return sel_lesser_equal(tup,op1,op3);
	} else if(op2 == ">="){
		return sel_greater_equal(tup,op1,op3);	
	} else if(op2 == "!="){
		return sel_not(tup,op1,op3);
	} else if(op2 == "=="){
		return sel_equals(tup,op1,op3);
	}
	else{
		cout<<"\noperator does not match acceptable choices";
		return false;
	}

}		
				
bool SQLQuerySelect::operation(vector<string> ops){
	
	for(int t=0;t< relation.get_tuples().size();++t){
		stack<bool> opers;
		for(int i=0; i<ops.size() ;++i){
			if(ops[i] == "&&"){
				bool oper_1 = opers.top();
				opers.pop();
				bool oper_2 = opers.top();
				opers.pop();
				opers.push(oper_1 && oper_2);			
			} else if(ops[i] == "||"){
				bool oper_1= opers.top();
				opers.pop();
				bool oper_2= opers.top();
				opers.pop();
				opers.push(oper_1 || oper_2);		
			} else{	
					opers.push(comparison(relation.get_tuples()[t], ops[i]));
			}	
		}
		show_row.push_back(opers.top());
		opers.pop();	
	}	

}
	
void SQLQuerySelect::select_cmd(vector<string> ops ){
	operation( ops);
	string attr;
	for(int j=0;j<relation.get_attribute_names().size() ;++j){
		if(relation.get_attributes()[j].get_index()== 1){
			attr = relation.get_attribute_names()[j];
			break;
		}
		else{
			attr = relation.get_attribute_names()[j];	
		}
	}
	if(tups.size()!=show_row.size())
		cout<<"\nProblem in select cmd function";
	for(int i =0;i<tups.size() ;++i){
		if(!show_row[i]){ 
			string data = tups[i].get_data(attr);
			where_obj temp(attr,data);
			where.push_back(temp);
		}
	}
	select = relation.get_attribute_names();

}	
	
SQLRelation SQLQuerySelect::update_cmd(vector<string> ops, vector<where_obj> updata){
	operation(ops);
	if(tups.size()!=show_row.size())
		cout<<"\nProblem in update cmd function";
	for(int i = 0 ;i < show_row.size() ; ++i){
		if(show_row[i]){
			for(int p =0; p<updata.size() ;++p){
				SQLAttribute attr = relation.get_sqlattr(updata[p].attr);
				relation.update_tuple(attr,updata[p].where,i);
			}

		}else{
			//do nothing
		}
	}
	return relation;
}

void SQLQuerySelect::delete_cmd(string name, vector<string> ops){
	operation(ops);
	string attr;
	for(int j=0;j<relation.get_attribute_names().size() ;++j){
		if(relation.get_attributes()[j].get_index()== 1){
			attr = relation.get_attribute_names()[j];
			break;
		}
		else{
			attr = relation.get_attribute_names()[j];	
		}
	}
	for(int i =0;i<tups.size() ;++i){
		if(show_row[i]){ 
			string data = tups[i].get_data(attr);
			where.push_back(where_obj(attr,data));
		}
	}
	select = relation.get_attribute_names();
}

void SQLQuerySelect::projet_cmd(vector<string> columns){
	vector<string> attr = relation.get_attribute_names();
	for(int i =0;i<tups.size() ;++i){
		string data = tups[i].get_data(attr[0]);
		where.push_back(where_obj(attr[0],data));
	}
	for(int j= 0;j<columns.size();++j){
		for(int p = 0; p <attr.size();++p){
			if(attr[p]== columns[j])
				select.push_back(columns[j]);
		}
	}
}