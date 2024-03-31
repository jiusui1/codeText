#include <atomic>
#include <iostream>
#include <mutex>
using namespace std;
#if 0
//单例模式---饿汉式
class TaskQueue {
   public:
    static TaskQueue *Getinstance() {
        return m_task;
    }
    void print() {
        cout << "这是一个单例" << endl;
    }

   private:
    TaskQueue() = default;
    TaskQueue(const TaskQueue &task) = delete;
    TaskQueue &operator=(const TaskQueue &task) = delete;
    static TaskQueue *m_task;
};

TaskQueue *TaskQueue::m_task = new TaskQueue();
#endif

#if 0
//单例模式---懒汉式
class TaskQueue {
   public:
    static TaskQueue *Getinstance() {
        if (m_task == nullptr)
            m_task = new TaskQueue();
        return m_task;
    }
    void print() {
        cout << "这是一个单例" << endl;
    }

   private:
    TaskQueue() = default;
    TaskQueue(const TaskQueue &task) = delete;
    TaskQueue &operator=(const TaskQueue &task) = delete;
    static TaskQueue *m_task;
};
TaskQueue *TaskQueue::m_task = nullptr;

#endif

#if 0
// 双重检查锁定解决懒汉式带来的线程安全问题
// 使用原子变量解决双重检查锁定带来的小问题
class TaskQueue {
   public:
    static TaskQueue *Getinstance() {
        TaskQueue *task = m_task.load();  // 加载实例
        if (task == nullptr) {
            m_mutex.lock();
            task = m_task.load();  // 加载实例
            if (task == nullptr) {
                task = new TaskQueue();
                m_task.store(task);
            }
            m_mutex.unlock();
        }
        return task;
    }
    void print() {
        cout << "这是一个单例" << endl;
    }

   private:
    TaskQueue() = default;
    TaskQueue(const TaskQueue &task) = delete;
    TaskQueue &operator=(const TaskQueue &task) = delete;
    // static TaskQueue *m_task;
    static mutex m_mutex;
    static atomic<TaskQueue *> m_task;
};
// TaskQueue *TaskQueue::m_task = nullptr;
atomic<TaskQueue *> TaskQueue::m_task;
mutex TaskQueue::m_mutex;

#endif

#if 1
// 使用静态局部对象解决线程安全问题--懒汉式
class TaskQueue {
   public:
    static TaskQueue *Getinstance() {
        static TaskQueue task;
        return &task;
    }
    void print() {
        cout << "这是一个单例" << endl;
    }

   private:
    TaskQueue() = default;
    TaskQueue(const TaskQueue &task) = delete;
    TaskQueue &operator=(const TaskQueue &task) = delete;
};

#endif

int main(int argc, char const *argv[]) {
    TaskQueue::Getinstance()->print();
    return 0;
}
