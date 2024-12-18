#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void heapify(int *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    std::fstream inputFile("in.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return 1;
    }

    std::vector<int> list1;
    std::vector<int> list2;

    int n = 0;
    std::string line;
    while (std::getline(inputFile, line)) {
        n++;
        int space = line.find(' ');
        list1.push_back(std::stoi(line.substr(0, space)));
        list2.push_back(std::stoi(line.substr(space + 1)));
    }

    heapSort(&list1[0], n);
    heapSort(&list2[0], n);

    int total = 0;

    for (int i = 0; i < n; i++) {
        int diff = list1[i] - list2[i];
        if (diff < 0) {
            diff *= -1;
        }
        total += diff;
    }

    std::cout << total << std::endl;

    return 0;
}
