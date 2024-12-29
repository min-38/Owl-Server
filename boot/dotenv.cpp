//
// Created by Kim Minseo on 2024. 12. 29..
//

#include "dotenv.h"

#define ENV_PATH "../.env"

DotEnv* DotEnv::instance = nullptr;

DotEnv::DotEnv() {
    std::ifstream file(ENV_PATH);
    if (!file.is_open()) {
        std::cerr << "Failed to open .env file: " << ENV_PATH << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        line.erase(0, line.find_first_not_of(" \t")); // 공백 제거

        // 주석 제거
        if(line[0] == '#') {
            continue;
        }

        size_t pos = line.find('=');
        if (pos != std::string::npos) {
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            envMap[key] = value;
        }
    }
    file.close();
}

std::string DotEnv::get(const std::string& key, const std::string& defaultValue = "") const {
    auto it = envMap.find(key);
    if (it != envMap.end()) return it->second;
    return defaultValue;
}
