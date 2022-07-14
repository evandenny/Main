#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <pthread.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdio>

using namespace std;

class createUser {
public:
    createUser() {
        name = "";
        username = "";
        email = "";
        phone = "";
        address = "";
        password = "";
        age = 0;
        user_type type = free;
        pkey = "";
    }
    void set_password(string password) {
        this->password = password;
    }
    string in_password() {
        cin >> password;
        return password;
    }
    string confirm_password(string password) {
        string password_confirm;
        cout << "Confirm password: ";
        cin >> password_confirm;
        if (password != password_confirm) {
            cout << "Password does not match. Try again." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            input_password();
        } else if (password == password_confirm) {
            pkey = password_confirm;
        }
        return password_confirm;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    string get_pkey() {
        return pkey;
    }
    void input_password() {
        string pass;
        string password_confirm;
        passwordPrompt();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Enter password: ";
        pass = in_password();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        set_password( confirm_password(pass) ); // set password to the password that was inputted by the user and confirmed by the function confirm_password()
    }
    string get_username() {
        return username;
    }
    string get_name() {
        return name;
    }
    string get_email() {
        return email;
    }
    string get_phone() {
        return phone;
    }
    string get_address() {
        return address;
    }
    string set_age() {
        string age;
        cout << "Enter age: ";
        cin >> age;
        return age;
    }
    void set_user_type() {
        cout << "Your user type is currently FREE. If you would like to upgrade to a STANDARD or PREMIUM user, please do so after finishing your registration." << endl;
        user_type type = free;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    };
    void set_new_password();
    void login();
    void create_user() {
        cout << "CREATE USER ACCOUNT" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        set_name();
        set_username();
        set_email();
        set_phone();
        set_address();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        print_info();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        input_password();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        moreinfo();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        set_user_type();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        set_age();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        system("clear");
        cout << "User account created successfully." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        system("clear");
    }
    void print_info() {
        cout << "You entered the following information:" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "Your name: " << name << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "Located at: " << address << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "We can reach you at: " << phone << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "Or at the email address: " << email << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cout << "Your username is: " << username << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    void set_name() {
        cout << "Enter name: ";
        cin >> name;
    }
    void set_username() {
        cout << "Enter username: ";
        cin >> username;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    void set_email() {
        cout << "Enter email: ";
        cin >> email;
    }
    void set_phone() {
        cout << "Enter phone: ";
        cin >> phone;
    }
    void set_address() {
        cout << "Enter address: ";
        cin >> address;
    }
    void passwordPrompt() {
        cout << "Now create your password." << endl;
    }
    void moreinfo() {
        cout << "We just need a little bit more information to create your account." << endl;
    }
private:
    string name;
    string username;
    string password;
    string email;
    string phone;
    string address;
    string pkey;
    int age;
    enum user_type {
        admin,
        premium,
        standard,
        free
    };
    user_type type;
};

int main () {
    createUser user;
    user.create_user();
    return 0;
}