#ifndef __UDFUNC__H__
#define __UDFUNC__H__

#pragma once

std::mt19937 seeded_eng() {
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    return std::mt19937(seed);
}

class Random {
private:
    std::mt19937 eng = seeded_eng();
public:
auto operator()(int a, int b) {
        std::uniform_int_distribution<int> dist(a, b);
        return dist(eng);
    }
};

#endif  //!__UDFUNC__H__