#include <iostream>
#include <vector>

// 堆调整，将以root为根的子树调整为最大堆
void maxHeapify(std::vector<int>& arr, int root, int size) {
    int largest = root; // 初始化最大值的索引为root
    int left = 2 * root + 1; // 左子节点的索引
    int right = 2 * root + 2; // 右子节点的索引

    // 找到根、左子节点、右子节点中的最大值
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大值不是根节点，则交换最大值和根节点，并继续向下调整
    if (largest != root) {
        std::swap(arr[root], arr[largest]);
        maxHeapify(arr, largest, size);
    }
}

// 堆排序
void heapSort(std::vector<int>& arr) {
    int size = arr.size();

    // 构建最大堆
    for (int i = size / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, i, size);
    }

    // 依次将堆顶元素与堆的最后一个元素交换，并调整堆
    for (int i = size - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]); // 将堆顶元素移动到数组末尾
        maxHeapify(arr, 0, i); // 调整剩余元素为最大堆
    }
}

int main() {
    std::vector<int> arr = {64, 25, 12, 22, 11};

    // 对数组进行堆排序
    heapSort(arr);

    // 输出排序后的数组
    std::cout << "排序后的数组: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
