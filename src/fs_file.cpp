/*
 * fs_file.cpp
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
#include <fstream>
#include <iostream>
#include "fs_file.hpp"
#include <json/json.h>

Fsfile::Fsfile(std::string file_name): m_file_name(file_name)  {
    std::cout << "Starting the constructor !" << std::endl;
}

std::string Fsfile::get_file_name() {
    return m_file_name;
}

bool Fsfile::try_login(std::string login, std::string password) {
    Json::Value root;
    std::ifstream ifs;
    ifs.open(get_file_name());
    Json::CharReaderBuilder builder;
    JSONCPP_STRING errs;

    if (!parseFromStream(builder, ifs, &root, &errs)) {
        std::cout << errs << std::endl;
    }
    auto entriesArray = root["Users"];
    for(int i = 0; i < entriesArray.size(); i++) {
        // std::cout << "ID: " << i << std::endl;
        // std::cout << "Login: " << entriesArray[i]["login"] << std::endl;
        // std::cout << "Password: " << entriesArray[i]["password"] << std::endl;
        if(entriesArray[i]["login"] == login && entriesArray[i]["password"] == password) {
            std::cout << "Acess Granted !!" << std::endl;
            return true;
        }
   }
   std::cout << "Acess Denied !!" << std::endl;
   return false;
}

void Fsfile::save_user(std::string login, std::string password) {
    Json::CharReaderBuilder builder_reader;
    Json::StreamWriterBuilder builder_writer;
    Json::Value root;
    Json::Value item; 
    std::ifstream is;
    std::ofstream ofs;
    JSONCPP_STRING errs;
    is.open(get_file_name());
    parseFromStream(builder_reader, is, &root, &errs);
    is.close();
    item["login"] = login; 
    //Add array member
    item["password"] = password; 
    root["Users"].append(item);
    const std::string json_file = Json::writeString(builder_writer, root);
    ofs.open(get_file_name());
    ofs << json_file;
    ofs.close();  
}


