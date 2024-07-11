#include <Windows.h>
#include <iostream>
#include <String.h>

using namespace std;
#define MAX_TASK_LIST 10000
struct task{
	long int id;
	string name;
	string status;
	string date;
	string folder;
	
}task [MAX_TASK_LIST] ;
void addTask(int);
void listTask(int);
void chgtskstatus(int);
void chgtskfolder(int);
void currentTask(int);
void option();

int main(int argc, char* argv[]){
	
	printf(" %2s\n","To do list!");	
	int data;
	int count=1;
	option();
	while(data!=0){
		printf("> ");
		cin >>data;
		
		switch(data){
			case 1:
				addTask(count);
				count++;
				break;
			case 2:
				listTask(count);
				break;
			case 3:
				int s;
				cout<<"Task [Status]> ";
				cin>>s;
				chgtskstatus(s);
				break;
			case 4:
				int f;
				cout<<"Task [Folder]> ";
				cin>>f;
				chgtskfolder(f);
				break;
			case 5:
				
//				int c;
//				cout<<"Task [Current]> ";
//				cin>>c;
				cout<<count<<endl;
				currentTask(--count);
				break;
			default:
				printf("Quitting.....");
				data=0;
				break;
		}											
	}
}

void option(){
	
	printf("1. Add Task \n2. List All Tasks\n3. Change task Status\n4. Change task folder\n5. Current Task\n");
	return;
}

void addTask(int row){
	string name,status,date;
	task[row].id=row;
	cout<< "[+] Add Task"<<endl;
	
	task[row].date="";
	task[row].status="";
	cout<< "Name  [+] ";
	cin.ignore(256, '\n');
	getline(cin,task[row].name,'\n');
	
	
	return;	
}

void listTask(int num){
	cout<< "[-] Tasks "<<endl;
	for(int i=1;i<num;i++){
		cout<<"===+=== Task ["<<task[i].id<<"]===+==="<<endl;
			cout<<"Date   : "<<task[i].date<<endl;
			cout<<"Name   : "<<task[i].name<<endl;
			cout<<"Status : "<<task[i].status<<endl;
	}
	return;
}

void currentTask(int num){
	cout<< "["<<num<<"] Task "<<endl;
	cout<<"===+=== Task ["<<task[num].id<<"]===+==="<<endl;
			cout<<"Date   : "<<task[num].date<<endl;
			cout<<"Name   : "<<task[num].name<<endl;
			cout<<"Status : "<<task[num].status<<endl;
	
	return;
}

void chgtskstatus(int num){
	cout<<"[!] Change Status Task ["<<num<<"] ";
	cin.ignore(256,'\n');
	getline(cin,task[num].status,'\n');
}

void chgtskfolder(int num){
	cout<<"[!] Change folder Task ["<<num<<"] ";
	cin.ignore(256,'\n');
	getline(cin,task[num].folder,'\n');
}

