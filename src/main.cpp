/*
 * main.cpp
 * 
 * Copyright 2021 Caio Felipe Cruz  <caio.crux@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <iostream>
#include "fs_file.hpp"

int main(int argc, char **argv) {
    Fsfile test("register.txt");
    std::string login;
    std::string password;
    int user_option = 0;
    std::cout << "Welcome to Mashina System!" << std::endl;
    std::cout << "What do you want to do ?" << std::endl;
    std::cout << "(1) Register a new login" << std::endl;
    std::cout << "(2) Login in Sytem" << std::endl;
    std::cin >> user_option;
    switch (user_option) {
        case 1:
            std::cout << "Register new user:" << std::endl;
            std::cout << "login: ";
            std::cin >> login;
            std::cout << "password: ";
            std::cin >> password;
            test.save_user(login, password);
            break;
        case 2:
            std::cout << "Login in System:" << std::endl;
            std::cout << "login: ";
            std::cin >> login;
            std::cout << "password: ";
            std::cin >> password;
            test.try_login(login, password);

            break;
        default:
            std::cout << "Option not found !" << std::endl;
    }
    std::cout << "Leaving the system" << std::endl;
    return EXIT_SUCCESS;
}
