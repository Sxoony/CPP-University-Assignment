#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	int score[5];//array of 5 elements. 0 to 4 for indexing.
	float average,totalscore;
	int i, highest, lowest;
	totalscore = 0;
	highest = -1;//no student can get lower than 0, so the initial value will never be the highest among the marks
	lowest = 101;//no student can get higher than 100, so the initial value will never be the lowest among the marks.
	cout << "Enter the scores for 5 students:\n";
	for (i = 0; i < 5; i++) {
		cout << "Enter the scores for student "<<i+1<<": ";
		cin >> score[i];
		if ((score[i] > -1) && (score[i] < 101)) { //make sure that no score can be higher or lower than 100 or 0
			totalscore = totalscore + score[i];
			if (highest < score[i]) {// for the first time, it will be like "if -1 is smaller than score[1] (which will be true), change the highest to the new higher value.
				highest = score[i];
			}
			if (lowest > score[i]) {//same as highest, but in reverse.
				lowest = score[i];
			}
		}
		else {
			cout << "Invalid score entered. Try again.\n";
			i--;//so that the loop will go on until the correct scores are entered. 
		}
	}
	cout << endl;
	cout << "Scores Entered:\n";
	for (i = 0; i < 5; i++) {
		cout << "Student " << i + 1 << ": " << score[i]<<endl;//display all entered scores.
	}
	cout << endl;
	average = totalscore / 5.00; //i will be equal to 5 as well.
	cout << "Average Score: " << average<<endl;
	cout << "Highest Score: " << highest<<endl;
	cout << "Lowest Score: " << lowest<<endl;


}