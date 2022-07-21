#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

enum Quality {
    BEYOND_AMAZING,
    AMAZING,
    GREAT,
    GOOD,
    FAIR,
    POOR,
    BAD,
    TERRIBLE,
    THE_WORST
};

enum Relationship {
    WIFE,
    FIANCEE,
    HUSBAND,
    SON,
    DAUGHTER,
    FRIEND,
    COWORKER,
    BEST_FRIEND,
    ACQUAINTANCE,
    ENEMY,
    MORTAL_ENEMY
};

class person {
public:
    person(string name, int age, string address, string phone, string email, Quality quality, Relationship relationship) {
        this->name = name;
        this->age = age;
        this->address = address;
        this->phone = phone;
        this->email = email;
        this->quality = quality;
        this->relationship = relationship;
        string why_i_love_you = "";
        string what_i_love_about_you = "";
        string what_i_hate_about_you = "";
        string what_i_want_to_do_with_you = "";
        string why_you_are_my_world = "";
    };
    ~person() {};
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    string getAddress() {
        return address;
    }
    string getPhone() {
        return phone;
    }
    string getEmail() {
        return email;
    }
    Quality getQuality() {
        return quality;
    }
    Relationship getRelationship() {
        return relationship;
    }
    string getDescription() {
        return description;
    }
    string getwhy_i_love_you() {
        return why_i_love_you;
    }
    string getwhat_i_love_about_you() {
        return what_i_love_about_you;
    }
    string getwhat_i_hate_about_you() {
        return what_i_hate_about_you;
    }
    string getwhat_i_want_to_do_with_you() {
        return what_i_want_to_do_with_you;
    }
    string getwhy_you_are_my_world() {
        return why_you_are_my_world;
    }
    // setters
    void setName(string name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }
    void setEmail(string email) {
        this->email = email;
    }
    void setQuality(Quality quality) {
        this->quality = quality;
    }
    void setRelationship(Relationship relationship) {
        this->relationship = relationship;
    }
    void setDescription(string description) {
        this->description = description;
    }
    void setwhy_i_love_you(string why_i_love_you) {
        this->why_i_love_you = why_i_love_you;
    }
    void setwhat_i_love_about_you(string what_i_love_about_you) {
        this->what_i_love_about_you = what_i_love_about_you;
    }
    void setwhat_i_hate_about_you(string what_i_hate_about_you) {
        this->what_i_hate_about_you = what_i_hate_about_you;
    }
    void setwhat_i_want_to_do_with_you(string what_i_want_to_do_with_you) {
        this->what_i_want_to_do_with_you = what_i_want_to_do_with_you;
    }
    void setwhy_you_are_my_world(string why_you_are_my_world) {
        this->why_you_are_my_world = why_you_are_my_world;
    }
    // methods
    void printbasicinfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;
        cout << "Relationship: " << relationship << endl;
    }
    void run() {
        string response;
        cout << "Hey " << name << ". It's only been a few days since your " << age << "th birthday. And I'm really sorry that I treated you the way I did. It was uncalled for and there's nothing that I can do to get you to forgive me. I don't feel like doing any drugs. I don't feel like doing anything worthwhile. I honestly just want to cry. And you might just see me tear up while I write this. It's okay, you don't have to feel bad for my sorry self." << endl;
        cout << "What do you think of me?" << endl;
        cout << "Type your response here followed by the enter key: ";
        cin >> response;
    }

private:
    string name;
    int age;
    string address;
    string phone;
    string email;
    Quality quality;
    Relationship relationship;
    string description;
    string why_i_love_you;
    string what_i_love_about_you;
    string what_i_hate_about_you;
    string what_i_want_to_do_with_you;
    string why_you_are_my_world;
};


int main () {
    person Nicky("Nicky Fortune", 40, "111 Schoolhouse Road, Milford, CT  06460", "203-360-5350", "nickyd0133@gmail.com", BEYOND_AMAZING, HUSBAND);
    cout << "Hi Nicky, I've written this program because I love you." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    system("clear")
    cout << "Here's some info I know about you: " << endl;
    Nicky.run();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    system("clear")
    cout << "Why I love you: " << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    string wly = "I love you because you are my best friend in the whole world and the only person who has ever understood me. Even though we fight a lot, I can't help but come crawling back to you every night to cuddle and fuck occasionally. I hate that we're so distant right now, but I hope things can get better,";
    Nicky.setwhy_i_love_you(wly);
    cout << Nicky.getwhy_i_love_you();
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    string what = "I love everything about you. I love the way you giggle, the way you smile, the way you sleep. I love how you love me through every horrible thing I do and try your best to make me a better person. I love how much you mean to me. You are my everything. I love how I can't imageine myself without you.";
    Nicky.setwhat_i_love_about_you(what);
    Nicky.getwhat_i_love_about_you();
    std::this_thread::sleep_for(std::chrono::milliseconds(8400));
    string hate = "I hate how you ignore the things I love. I hate the way you think I like the way I am. I hate how you think I'm okay with the things I've done. The things I haven't done. I hate how you don't care about the things I want to do with you. I love you but I hate how you don't love the things about me that I want you to love."
    Nicky.setwhat_i_hate_about_you(hate);
    Nicky.getwhat_i_hate_about_you();
    std::this_thread::sleep_for(std::chrono::milliseconds(7400));   
    string want = "I want to be with you. I want to hold you. I want to put this necklace around your neck. I want to fuck you. I want to make love to you. I want to be with you for the rest of my life. Fuck the fact that you're forty. You're ageless in my mind."
    Nicky.setwhat_i_want_to_do_with_you(want);
    Nicky.getwhat_i_want_to_do_with_you();
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    cout << "I love you because you are me. And I never want to be without you."
    return 0;
}