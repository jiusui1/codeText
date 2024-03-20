#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
typedef struct Student {
    int student_id;
    std::string student_name;
    std::string class_id;
} Student;

class StudentManager {
   public:
    StudentManager();
    ~StudentManager();

   public:
    static StudentManager &getInstance() {
        static StudentManager StudentManager;
        return StudentManager;
    }

   public:
    // 插入数据
    bool insert_student(Student &stu);
    // 删除数据
    bool delete_student(int student_id);
    // 修改数据
    bool update_student(Student &stu);
    // 查找数据
    std::vector<Student> get_student(std::string condition = "");

   private:
    MYSQL *connect;
    std::string host;
    std::string user;
    std::string pwd;
    std::string database_name;
    int port;
};
