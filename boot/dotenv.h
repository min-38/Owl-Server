//
// Created by Kim Minseo on 2024. 12. 29..
//

#ifndef DOTENV_H
#define DOTENV_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>

class DotEnv {
public:
    // 싱글톤 인스턴스 접근
    static DotEnv* getInstance() {
        if (instance == nullptr) {
            instance = new DotEnv();
        }
        return instance;
    }

    void printAllConfig() {
        for(auto & it : envMap) {
            std::cout << it.first << "=" << it.second << std::endl;
        }
    }

    // 환경 변수 가져오기
    std::string get(const std::string &key, const std::string &defaultValue) const;

    // 복사 및 이동 방지
    DotEnv(const DotEnv&) = delete;
    DotEnv& operator=(const DotEnv&) = delete;
private:
    std::map<std::string, std::string> envMap;
    static DotEnv *instance;

    // 생성자: .env 파일 읽기
    DotEnv();
};

#endif //DOTENV_H
