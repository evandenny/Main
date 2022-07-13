#ifndef _pointers_h
#define _pointers_h

#include <string>
#include <thread>
using namespace std;

class pointers {
public:
    int setPointerInt(int * ipnt, int id) {
        ipnt = &id;
        return *ipnt;
    };
    double setPointerDouble(double * dpnt, double id) {
        dpnt = &id;
        return *dpnt;
    };
    string setPointerString(string * spnt, string id) {
        spnt = &id;
        return *spnt;
    };
    char setPointerChar(char * cpnt, char id) {
        cpnt = &id;
        return *cpnt;
    };
    bool setPointerBool(bool * bpnt, bool id) {
        bpnt = &id;
        return *bpnt;
    };
    void setPointerVoid(void * vpnt, void * id) {
        vpnt = id;
    };
private:
    int * ipnt;
    double * dpnt;
    string * spnt;
    char * cpnt;
    bool * bpnt;
    void * vpnt;
};

#endif