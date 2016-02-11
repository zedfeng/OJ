#include<iostream>
#include<iomanip>
using namespace std;
const int kMaxLen = 101;
char grade[kMaxLen];
int main(){
	double gpa;
	while (gets(grade)){
		gpa = 0.0;
		int i = 0, count = 0;
		bool flag = true;
		while (grade[i] != '\0'){
			if (grade[i] != ' '){
				switch (grade[i]){
				case 'A':
					gpa += 4.0;
					count++;
					break;
				case 'B':
					gpa += 3.0;
					count++;
					break;
				case 'C':
					gpa += 2.0;
					count++;
					break;
				case 'D':
					gpa += 1.0;
					count++;
					break;
				case 'F':
					gpa += 0.0;
					count++;
					break;
				default:
					flag = false;
				}
			}
			i++;
		}
		if (!flag){
			cout << "Unknown letter grade in input" << endl;
		}
		else{
			cout << fixed << setprecision(2) << gpa / count << endl;
		}
	}
	return 0;
}