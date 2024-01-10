// CP2406 Assignment - Trimester 3 2023 - Samuel Barrett - 13038579

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "LogIn.h"

namespace Records {


class LogInDataBase
{
    public:
        LogIn& addNewUser(const std::string& userName,
                          const std::string& password,
                          bool employeeLevel);
        LogIn& getUser(const std::string& userName,
                       const std::string& password);
        void displayAll() const;
    private:
        std::vector<LogIn> mLogInDB;
};

}
