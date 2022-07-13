#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

enum lesson_type {
    math,
    science,
    history,
    english
};

class Classroom {
public:
    Classroom(string lesson, string teacher, string room, string lessonPlan, int numStudents, char averageGrade, char averageGradeModifier, bool distraction = false    [''saxxxxxxxxxxxxxxxxxxxxxxxx=x=axxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx]) {
        this->lesson = lesson;
        this->teacher = teacher;
        this->room = room;
        this->lessonPlan = lessonPlan;
        this->numStudents = numStudents;
        this->averageGrade = averageGrade;
    }
    ~Classroom();
    // getters
    string getLesson() {
        return lesson;
    }
    string getTeacher() {
        return teacher;
    }
    string getRoom() {
        return room;
    }
    string getLessonPlan() {
        return lessonPlan;
    }
    int getNumStudents() {
        return numStudents;
    }
    enum lesson_type getLessonType() {
        return _lesson;
    }
    bool getDistraction() {
        return distraction;
    }
    // setters
    void setLesson(string l) {
        lesson = l;
    }
    void setTeacher(string t) {
        teacher = t;
    }
    void setRoom(string r) {
        room = r;
    }
    void setLessonPlan(string lp) {
        lesson_plan = lp;
    }
    void setnum_students(int n) {
        num_students = n;
    }
    void setLessonType(enum lesson_type _lesson) {
        lesson_type = _lesson;
    }
    void setDistraction(bool d) {
        distraction = d;
    }
    void setAverageGrade(char a, b) {
        average_grade = a;
        average_grade_mod = b;
        average_grade_full = a + b;
    }; // end setAverageGrade/mod/full
    string announceAverageGrade() {
        string annoucement;
        announcement = "The Average Grade for the class of room " + room + " is " + setAverageGrade(average_grade, average_grade_mod);
        cout << announcement << endl;
    }; 
    string getLessonPlan(enum lesson_type _lesson) {
        switch (lesson) {
            case "math":
                lessonPlan = "Addition, Subtraction, Multiplication, Division";
                break;
            case "science":
                lessonPlan = "Astronomy, Stars, Planets, Galaxies";
                break;
            case "history":
                lessonPlan = "World War II, Major Events, Drugs, Movie Time!";
                break;
            case "english":
                lessonPlan = "Vocabulary, Grammar, Spelling, Punctuation";
                break;
        }; // end switch
        return lessonPlan; // return the lesson plan
    }; // lesson plan returned
    void teach() {

    }
//private:
    string lesson;
    string teacher;
    string room;
    string lessonPlan;
    enum lesson_type _lesson;
    int num_students;
    char average_grade;
    char average_grade_mod;
    string average_grade_full;
    bool distraction;
};
