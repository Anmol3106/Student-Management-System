// I started this Project on Date : 20-03-2026. This is a simple Student Management System in C++. It allows you to add, display, and manage student records. The project uses file handling to store student data persistently. The user interface is console-based, and it provides options for various operations related to student management.

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

void Red(){ cout<<"\033[1;31m"; }
void Green(){ cout<<"\033[1;32m"; }
void Yellow(){ cout<<"\033[1;33m"; }
void ResetColor(){ cout<<"\033[0m"; }

struct StudentData{
    string name;
    string rollNumber;
    string course;
    string email;

    void printDetails(){
        Green();
        cout<<endl<<endl;
        cout <<"-----------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Email: " << email << endl;
        cout <<"-----------------------------" << endl;
        ResetColor();
    }
};

class StudentManagementSystem{
    private:
        vector<StudentData> ListOfStudents;
    protected:
        void ReadFromFile();
        void WriteToFile();
    public:
        void MainMenu();
        void AddStudent();
        void DisplayStudents();
        void SearchStudentUsingRoll();
        void EditStudentDetails();
        void DeleteStudent();
};

void StudentManagementSystem::ReadFromFile(){
    ifstream fin("StudentData.txt");
    if(fin.is_open()){
        StudentData DataBase;
        while(
            getline(fin,DataBase.name)&&
            getline(fin,DataBase.rollNumber)&&
            getline(fin,DataBase.course)&&
            getline(fin,DataBase.email))
        ListOfStudents.push_back(DataBase);
        
        fin.close();
    }
    else{
        Red();
        cout<<"|----------------------------|"<<endl;
        cout<<"|  File Not Exist here!!     |"<<endl;
        cout<<"|----------------------------|"<<endl;
        ResetColor();
    }
}

void StudentManagementSystem::WriteToFile(){
    ofstream outfile("StudentData.txt");
    if(outfile.is_open()){
        for(StudentData DataBase : ListOfStudents){
            outfile<<DataBase.name<<endl;
            outfile<<DataBase.rollNumber<<endl;
            outfile<<DataBase.course<<endl;
            outfile<<DataBase.email<<endl;
        }
        outfile.close();
    }
    else{
        Red();
        cout<<"|----------------------------|"<<endl;
        cout<<"|  Unable To Open File!!     |"<<endl;
        cout<<"|----------------------------|"<<endl;
        ResetColor();
    }
}

void StudentManagementSystem::MainMenu(){
    int choice;
    ReadFromFile();
    while(true){
        Green();
        cout<<"-----------------------------"<<endl;
        cout<<"Enter 1 To Add Student Data "<<endl;
        cout<<"Enter 2 To Print All Student Data "<<endl;
        cout<<"Enter 3 To Search Student "<<endl;
        cout<<"Enter 4 To Edit Student Data "<<endl;
        cout<<"Enter 5 To Delete Student Data "<<endl;
        cout<<"Enter 6 To Exit Terminal "<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        ResetColor();
        switch(choice){
            case 1:
                AddStudent();
                break;
            case 2:
                DisplayStudents();
                break;
            case 3:
                SearchStudentUsingRoll();
                break;
            case 4:
                EditStudentDetails();
                break;
            case 5:
                DeleteStudent();
                break;
            case 6:
                cout<<"Exiting Terminal..."<<endl;
                return;
            default:
                Red();
                cout<<"|----------------------------------|"<<endl;
                cout<<"| Invalid Choice! Please Try Again |"<<endl;
                cout<<"|----------------------------------|"<<endl;
                ResetColor();
        }

        

    }
}

void StudentManagementSystem::AddStudent(){
    StudentData InputData;
    cin.ignore();
    Yellow();
    cout<<"-----------------------------------"<<endl;
    cout<<"Enter Student Name:- ";
    getline(cin,InputData.name);
    cout<<"Enter Student Roll no.:- ";
    getline(cin,InputData.rollNumber);
    cout<<"Enter Student Course:- ";
    getline(cin,InputData.course);
    cout<<"Enter Student Email:- ";
    getline(cin,InputData.email);
    cout<<"-----------------------------------"<<endl;
    ResetColor();
    ListOfStudents.push_back(InputData);
    WriteToFile();
}

void StudentManagementSystem::DisplayStudents(){
    if(ListOfStudents.empty()){
        Red();
        cout<<"|----------------------------|"<<endl;
        cout<<"|  Student Databse is Empty  |"<<endl;
        cout<<"|----------------------------|"<<endl;
        ResetColor();
    }
    else{
        int count=1;
        Green();
        for(StudentData DataBase: ListOfStudents){
            cout<<"Record No. "<<count++<<endl;
            DataBase.printDetails();
        }
        ResetColor();
    }
}

void StudentManagementSystem::SearchStudentUsingRoll(){
    string Rollno;
    bool flag=true;
    cin.ignore();
    Yellow();
    cout<<"Enter Student Roll no. to Search:- ";
    getline(cin,Rollno);
    if(ListOfStudents.empty()){
        Red();
        cout<<"|----------------------------|"<<endl;
        cout<<"|  Student Databse is Empty  |"<<endl;
        cout<<"|----------------------------|"<<endl;
        ResetColor();
    }    
    else{    
        for(StudentData DataBase: ListOfStudents){
            if(DataBase.rollNumber==Rollno){
                Green();
                cout<<"Student Found!"<<endl;
                DataBase.printDetails();
                ResetColor();
                flag=false;
                break;
            }
        }
       if(flag){
            Red();
            cout<<"|----------------------------|"<<endl;
            cout<<"|    Student Not Found!!     |"<<endl;
            cout<<"|----------------------------|"<<endl;
            ResetColor();
        }
    }
}

void StudentManagementSystem::EditStudentDetails(){
    string Rollno;
    bool flag=true;
    cin.ignore();
    Yellow();
    cout<<"Enter Student Roll no. to Search:- ";
    getline(cin,Rollno);
    if(ListOfStudents.empty()){
        Red();
        cout<<"|----------------------------|"<<endl;
        cout<<"|  Student Databse is Empty  |"<<endl;
        cout<<"|----------------------------|"<<endl;
        ResetColor();
    }    
    else{
        for(int x = 0 ; x<ListOfStudents.size() ; x++){
            if(ListOfStudents[x].rollNumber==Rollno){
                cin.ignore();
                cout<<"-----------------------------";
                cout<<"Enter Student Name:- ";
                getline(cin,ListOfStudents[x].name);
                cout<<"Enter Student Course:- ";
                getline(cin,ListOfStudents[x].course);
                cout<<"Enter Student Email:- ";
                getline(cin,ListOfStudents[x].email);
                cout<<"-----------------------------";
                flag=false;
                break;
            }
        }    
        if(flag){
            Red();
            cout<<"|----------------------------|"<<endl;
            cout<<"|    Student Not Found!!     |"<<endl;
            cout<<"|----------------------------|"<<endl;
            ResetColor();
        }
    }
}

void StudentManagementSystem::DeleteStudent(){
    string Rollno;
    bool flag=true;
    cin.ignore();
    Yellow();
    cout<<"Enter Student Roll no. to Search:- ";
    getline(cin,Rollno);
    if(ListOfStudents.empty()){
        Red();
        cout<<"|----------------------------|"<<endl;
        cout<<"|  Student Databse is Empty  |"<<endl;
        cout<<"|----------------------------|"<<endl;
        ResetColor();
    }    
    else{
        vector<StudentData>::iterator it = ListOfStudents.begin();
        for( ; it!=ListOfStudents.end();it++){
            if(it->rollNumber==Rollno){
                Red();
                it->printDetails();
                ListOfStudents.erase(it);
                cout<<"|-----------------------|"<<endl;
                cout<<"|Deletion is Successfull|"<<endl;
                cout<<"|-----------------------|"<<endl;
                ResetColor();
                flag=false;
                break;
            }
        }
        if(flag){
            Red();
            cout<<"|----------------------------|"<<endl;
            cout<<"|    Student Not Found!!     |"<<endl;
            cout<<"|----------------------------|"<<endl;
            ResetColor();
        }
    }
}

int main(){
    StudentManagementSystem s1;
    s1.MainMenu();
    cout<<endl;
    return 0;
}