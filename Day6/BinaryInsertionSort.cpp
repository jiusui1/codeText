#include <iostream>
#include <vector>

void binaryInsertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int left = 0, right = i - 1;

        // 二分查找找到插入位置
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // 插入位置后的元素依次向后移动一位
        for (int j = i; j > left; --j) {
            arr[j] = arr[j - 1];
        }

        // 将元素插入到正确位置
        arr[left] = key;
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    // 对数组进行折半插入排序
    binaryInsertionSort(arr);

    // 输出排序后的数组
    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
