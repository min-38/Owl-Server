//
// Created by Kim Minseo on 2024. 12. 29..
//

#ifndef BOOT_H
#define BOOT_H

#include <iostream>
#include "dotenv.h"

enum class State {
    NOT_STARTED,
    LOADING_ENV,
    CONNECTING_DB,
    FINALIZING,
    COMPLETE
};

class Boot {
public:
    // 싱글톤 인스턴스 접근
    static Boot* getInstance() {
        if (instance == nullptr) {
            instance = new Boot();
        }
        return instance;
    }
    // 복사 및 이동 방지
    Boot(const Boot&) = delete;
    Boot& operator=(const Boot&) = delete;
    void init();
private:
    static Boot* instance;
    State state = State::NOT_STARTED;
    Boot();
    ~Boot();
};



#endif //BOOT_H
