#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct nameType{
    string studentFName;
    string studentLName;
};

struct studentType{
    nameType name;
    int testScore;
    char grade;
};

const int STUD_NUM = 20;
studentType classList[STUD_NUM];

void assignGrade(studentType &s);
void postAllData();
void getData();
int highestScore();
void nameHighestScore(int best);
string getName(const nameType &n);

int main(){
    getData();

    cout << "----------Students----------" << endl;
    postAllData();
    
    int best = highestScore();
    cout << "--------Best Score---------" << endl;
    cout << "Score: " << best << "\nAchieved by:\n";
    nameHighestScore(best);

    return 0;
}

void getData(){
    cout << "Enter " << STUD_NUM << " student data (First [Last] Score): " << endl;
    for (int i = 0; i < STUD_NUM; i++){
        cout << "Student " << i + 1 << ": ";
        cin >> classList[i].name.studentFName;

        string temp;
        cin >> temp; 

        if (isdigit(temp[0])){
            classList[i].name.studentLName = "";
        } else {
            classList[i].name.studentLName = temp;
            cin >> temp;
        }

        bool valid = false;
        while(!valid){
            valid = true;
            for (int j = 0; j < (int)temp.length(); j++) {
                if (!isdigit(temp[j])) {
                    valid = false;
                    cout << "Invalid input. Please enter a number: ";
                    cin >> temp;
                    break;
                }
            }
        }
        classList[i].testScore = stoi(temp);
        assignGrade(classList[i]);
    }
}

void assignGrade(studentType &student){
    int score = student.testScore;
    if (score >= 80){
        student.grade = 'A';
    } else if (score >= 60){
        student.grade = 'B';
    } else if (score >= 40){
        student.grade = 'C';
    } else if (score >= 20){
        student.grade = 'D';
    } else{
        student.grade = 'E';
    }
}

int highestScore(){
    int max = classList[0].testScore;
    for (int i = 1; i < STUD_NUM; i++){
        if (classList[i].testScore > max){
            max = classList[i].testScore;
        }
    }
    return max;
}

void nameHighestScore(int max){
    for (int i = 0; i < STUD_NUM; i++){
        if (classList[i].testScore == max){
            cout << " - " << getName(classList[i].name) << endl;
        }
    }
}

string getName(const nameType &n){
    if (n.studentLName.empty()){
        return n.studentFName;
    };
    return n.studentLName + ", " + n.studentFName;
}

void postAllData(){
    for (int i = 0; i < STUD_NUM; i++){
        cout << "   Name: " << getName(classList[i].name) 
             << "\n   Score: " << classList[i].testScore 
             << "\n   Grade: " << classList[i].grade
             << "\n----------------------------\n";
    }
}