#include <iostream>
#include "StudentManager.hpp"

int main() {
    Student stu{3, "彭于晏", "计算机科学与技术"};
    Student stu1{4, "雷龙吉", "物联2002班"};
    // StudentManager::getInstance().insert_student(stu1);	//增
    // StudentManager::getInstance().delete_student(111);	//删
    // StudentManager::getInstance().update_student(stu1);		//改
    std::vector<Student> stulist = StudentManager::getInstance().get_student();
    if (stulist.size() == 0) {
        std::cout << "数据库中数据为空!" << std::endl;
        return 0;
    }
    int number = 1;
    for (Student student : stulist) {
        std::cout << "row" << number++ << ": " << student.student_id << " , " << student.student_name << " , " << student.class_id << std::endl;
    }
    return 0;
}