#include <stdio.h>
struct student{
    int ID;
    char *name;
    int grade;
}; //Define a structure before you use it!! 

//TODO: define a function that takes a student struct and prints out the student's info
void print(struct student s){
    printf("ID: %d  ", s.ID);
    printf("grade: %d ", s.grade);
    printf("name: %s \n", s.name);
}

//TODO: define a function that takes an array of student structs and prints out the info of students who have a grade > 40
// one student per line. 
void pass_check(struct student s[], int len){
    for (int i =0; i<len; i++){
        if (s[i].grade > 40){
            print(s[i]);
        }
    }
}

void main(){
    struct student song; //declare a student variable
    //initialize
    song.ID = 1024; 
    song.name = "song liu";
    song.grade = 70; 

    printf("%s\n", song.name); //displays "song liu"
    
    //declare + initialize in one line. 
    struct student song2 = {1024, "song liu", 30};

    printf("%s\n", song2.name); //displays "song liu"

    //TODO: test your print function here. 
    print(song);
    
    struct student sarray[] = {song, song2};
    pass_check(sarray, 2);
    
}