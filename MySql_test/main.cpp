#include <iostream>
#include "StudentManager.hpp"

int main() {
    Student stu{3, "������", "�������ѧ�뼼��"};
    Student stu1{4, "������", "����2002��"};
    // StudentManager::getInstance().insert_student(stu1);	//��
    // StudentManager::getInstance().delete_student(111);	//ɾ
    // StudentManager::getInstance().update_student(stu1);		//��
    std::vector<Student> stulist = StudentManager::getInstance().get_student();
    if (stulist.size() == 0) {
        std::cout << "���ݿ�������Ϊ��!" << std::endl;
        return 0;
    }
    int number = 1;
    for (Student student : stulist) {
        std::cout << "row" << number++ << ": " << student.student_id << " , " << student.student_name << " , " << student.class_id << std::endl;
    }
    return 0;
}