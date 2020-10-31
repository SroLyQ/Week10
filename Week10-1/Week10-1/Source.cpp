#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
struct A {
	bool operator < (const A&o)const {
		if (score != o.score) return score > o.score;
		else return name[0] < o.name[0];
	}
	char name[150];
	int score;
	char grade;
};
A a[1000];
void checkGrade(int n) {
	for (int i = 0;i < n;i++) {
		if (a[i].score >= 80)
			a[i].grade = 'A';
		if (a[i].score >= 70 && a[i].score < 80)
			a[i].grade = 'B';
		if (a[i].score >= 60 && a[i].score < 70)
			a[i].grade = 'C';
		if (a[i].score >= 50 && a[i].score < 60)
			a[i].grade = 'D';
		if (a[i].score < 50) 
			a[i].grade = 'F';
	}
}
int main() {
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		scanf("%s %d", a[i].name, &a[i].score);
	}
	sort(a, a + n);
	checkGrade(n);
	printf("\n-----------------------------\n\n");
	for (i = 0;i < n;i++) {
		printf("%s %d %c\n", a[i].name, a[i].score, a[i].grade);
	}
	return 0;
}