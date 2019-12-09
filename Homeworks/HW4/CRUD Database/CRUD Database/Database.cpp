//
//  Database.cpp
//  CRUD Database
//
//  Created by Stefano Fochesatto on 12/8/19.
//  Copyright © 2019 Stefano Fochesatto. All rights reserved.
//

#include "Database.hpp"

std::map<std::string, Database_record> Database_student;
bool CreateRecord(const std::string &key){
    auto it = Database_student.find(key);
    if (it == Database_student.end()){
        Database_record initial;
        Database_student.insert({key,initial});
        return true;
    }
    else
        std::cout <<"ERROR Dupl Record"<< std::endl;
        return false;
}



bool ReadRecord(const std::string &key, Database_record &record){
    auto it = Database_student.find(key);
      if (it == Database_student.end()){
      std::cout <<"ERROR Key Not Found"<< std::endl;
        return false;
      }
    else
        record = Database_student[key];
        return true;
}


bool UpdateRecord(const std::string &key,const Database_record &record){
    auto it = Database_student.find(key);
         if (it == Database_student.end()){
             std::cout <<"ERROR Key Not Found"<< std::endl;
             return false;
         }
    Database_student[key] = record;
    return true;
}






bool DeleteRecord(const std::string &key){
      auto it = Database_student.find(key);
           if (it == Database_student.end()){
               std::cout <<"ERROR Key Not Found"<< std::endl;
               return false;
           }
    Database_student.erase(key);
    return true;
}


bool InputRecord(Database_record &record){
      auto it = Database_student.find(record.student_Name);
    if (it == Database_student.end()){
        Database_student.insert ( std::pair<std::string,Database_record>(record.student_Name,record));
                  return true;
              }
   else
        std::cout <<"Duplicate key found!!!"<< std::endl;
        return false;
}






void PrintRecord(const std::string &key){
    std::cout << "Name" <<std::setw(26)<<"AssignmentScores"<<std::setw(26)<<"FinalGrade"<<std::setw(26)<<"Pass/Fail"<<std::endl;
    for(auto const& pair: Database_student){
         const char separator    = ' ';
        std::cout<< std::left <<std::setw(6)<<std::setfill(separator)<<pair.first;
        for (auto const& i: pair.second.assignment_Scores){
            std::cout<<std::right <<std::setw(8)<<std::setfill(separator)<< i<< std::endl;
        }
        std::cout<< std::setw(32)<<pair.second.student_Final<< std::endl;
         
                std::cout<< std::setw(32)<<pair.second.passFail<< std::endl;
        
        std::cout << std::endl;
    }
}

