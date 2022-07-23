#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define stringify(  x  ) #x
 
using namespace std;

enum lesson_type {
    math,
    science,
    history,
    english
};

class Classroom {
public:
    Classroom(string lesson, string teacher, string room, string lessonPlan, int numStudents, char averageGrade, char averageGradeModifier, bool distraction = false) {
        this->lesson = lesson;
        this->teacher = teacher;
        this->room = room;
        this->lessonPlan = lessonPlan;
        this->num_students = num_students;
        this->average_grade = average_grade;
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
        return num_students;
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
        lessonPlan = lp;
    }
    void setnum_students(int n) {
        num_students = n;
    }
    void setLessonTypeEng() {
        _lesson = english;
    }
    void setLessonTypeMath() {
        _lesson = math;
    }
    void setLessonTypeSci() {
        _lesson = science;
    }
    void setLessonTypeHist() {
        _lesson = history;
    }
    void setDistraction(bool d) {
        distraction = d;
    }
    void setAverageGrade(char a, char b) {
        average_grade = a;
        average_grade_mod = b;
        average_grade_full = a + b;
    }; // end setAverageGrade/mod/full
    string announceAverageGrade() {
        string announcement;
        announcement = "The Average Grade for the class of room " + room + " is " + stringify(setAverageGrade(average_grade, average_grade_mod));
        cout << announcement << endl;
    }; 
    string getLessonPlan(enum lesson_type _lesson) {
        switch (_lesson) {
            case 0:
                lessonPlan = "Addition, Subtraction, Multiplication, Division";
                break;
            case 1:
                lessonPlan = "Astronomy, Stars, Planets, Galaxies";
                break;
            case 2:
                lessonPlan = "World War II, Major Events, Drugs, Movie Time!";
                break;
            case 3:
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
    lesson_type _lesson;
    int num_students;
    char average_grade;
    char average_grade_mod;
    string average_grade_full;
    bool distraction;
};
