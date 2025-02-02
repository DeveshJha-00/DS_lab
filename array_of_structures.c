#include <stdio.h>
#include <stdlib.h>
#define nameSize 30
#define usnSize 15

struct Student{
	char name[nameSize];
	char usn[usnSize];
	int age;
	double cgpa;
};
typedef struct Student s1;

void read(s1 *s){
	printf("Enter name - ");
	scanf("%s", s->name);
	printf("Enter usn - ");
	scanf("%s", s->usn);
	printf("Enter age - ");
	scanf("%d", &s->age);
	printf("Enter cgpa - ");
	scanf("%lf", &s->cgpa);
	printf("\n");
}
void write(s1 s){
	printf("Name is : %s\n", s.name);
	printf("USN is : %s\n", s.usn);
	printf("Age is : %d\n", s.age);
	printf("CGPA is : %lf\n", s.cgpa);
	printf("\n");
}

void main(){
	int size;
	double cutoff;
	printf("Enter no. of students : ");
	scanf("%d", &size);
	s1 studArr[size];
	for (int i=0; i<size; i++) read(&studArr[i]);
	printf("Student details are - \n");
	for (int i=0; i<size; i++) write(studArr[i]);
	printf("\nEnter the cgpa cutoff - ");
	scanf("%lf", &cutoff);
	for (int i=0; i<size; i++){
		if (studArr[i].cgpa >= cutoff){
			write(studArr[i]);
		}
	}
}
