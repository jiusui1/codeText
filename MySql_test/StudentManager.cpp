#include "StudentManager.h"

StudentManager::StudentManager() {
    // 初始化连接对象
    connect = mysql_init(NULL);
    host = "127.0.0.1";
    user = "root";
    pwd = "123456";
    database_name = "database_test";
    port = 3306;
    // 设置字符编码
    mysql_options(connect, MYSQL_SET_CHARSET_NAME, "GBK");

    // 设置连接
    if (!mysql_real_connect(connect, host.c_str(), user.c_str(), pwd.c_str(), database_name.c_str(), port, NULL, 0)) {
        std::cout << "数据库链接失败!" << std::endl;
        std::cout << "错误原因为：" << mysql_error(connect) << std::endl;
    } else {
        std::cout << "数据库链接成功!" << std::endl;
    }
}

StudentManager::~StudentManager() {
    // 关闭数据库连接对象
    mysql_close(connect);
}

bool StudentManager::insert_student(Student &stu) {
    // 创建数据库语句
    char sql[1024];
    sprintf(sql, "INSERT INTO students values(%d,'%s','%s')", stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());

    if (mysql_query(connect, sql)) {
        // 如果出错了
        std::cout << "database fail insert :" << mysql_error(connect) << std::endl;
        return false;
    }
    // 成功插入
    std::cout << "database insert sucess:" << stu.student_id << ", " << stu.student_name << ", " << stu.class_id << std::endl;
    return true;
}

bool StudentManager::delete_student(int student_id) {
    // 创建数据库语句
    char sql[1024];
    sprintf(sql, "DELETE FROM students WHERE student_id = %d", student_id);

    if (mysql_query(connect, sql)) {
        // 如果出错了
        std::cout << "database fail delete :" << mysql_error(connect) << std::endl;
        return false;
    }
    // 成功删除
    std::cout << "database delete sucess, the student_id: " << student_id << std::endl;
    return true;
}

bool StudentManager::update_student(Student &stu) {
    // 创建数据库语句
    char sql[1024];
    sprintf(sql, "UPDATE students SET student_name = '%s',class_id = '%s' WHERE student_id = %d", stu.student_name.c_str(), stu.class_id.c_str(), stu.student_id);

    if (mysql_query(connect, sql)) {
        // 如果出错了
        std::cout << "database fail update :" << mysql_error(connect) << std::endl;
        return false;
    }
    std::cout << "database update sucess , the new student: " << stu.student_id << ", " << stu.student_name << ", " << stu.class_id << std::endl;
    return true;
}

std::vector<Student> StudentManager::get_student(std::string condition) {
    std::vector<Student> stulist;
    // 创建数据库语句
    char sql[1024];
    sprintf(sql, "SELECT * FROM students %s ", condition.c_str());

    if (mysql_query(connect, sql)) {
        // 如果出错了
        std::cout << "database fail select :" << mysql_error(connect) << std::endl;
        return {};
    }
    // 查找成功
    std::cout << "database select sucess!" << mysql_error(connect) << std::endl;
    MYSQL_RES *res = mysql_store_result(connect);

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        Student stu;
        stu.student_id = atoi(row[0]);  // 数据库第一列
        stu.student_name = row[1];      // 数据库第二列
        stu.class_id = row[2];          // 数据库第三列
        stulist.push_back(stu);
    }
    return stulist;
}
