//
// Created by Kim Minseo on 2024. 12. 29..
//

#include "boot.h"

Boot* Boot::instance = nullptr;

Boot::Boot() {
    state = State::NOT_STARTED;
}
Boot::~Boot() {
    state = State::NOT_STARTED;
}

void Boot::init() {
    if(state == State::NOT_STARTED) {
        state = State::LOADING_ENV;
        std::cout << "Loading environment..." << std::endl;
        DotEnv::getInstance()->printAllConfig();
        std::cout << "Loaded environment" << std::endl;

        std::cout << "Configuration loaded!" << std::endl;
    }
}
