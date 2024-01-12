// CP2406 Assignment - Kaung Sat Paing - 14399033

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "LogInDataBase.h"

namespace Records {

LogIn& LogInDataBase::addNewUser(const std::string& userName,
                                 const std::string& password,
                                 bool employeeLevel)
    {
        LogIn newUser(userName, password, employeeLevel);
        mLogInDB.push_back(newUser);
        return mLogInDB[mLogInDB.size() - 1];
    }

void LogInDataBase::displayAll() const
    {
        for (const auto& user : mLogInDB) {
            user.display();
        }
    }

LogIn& LogInDataBase::getUser(const std::string& userName,
                              const std::string& password)
{
    for (auto& user : mLogInDB)
        {
            if (user.validate(userName, password))
                {
                    std::cout << "Access granted" << std::endl;
    
                }
        }
        std::cout << "Access denied" << std::endl;
}

}