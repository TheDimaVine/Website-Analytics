#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>

struct Data {
    unsigned int user_id;
    unsigned int product_id;
    unsigned int timestamp;
};

// ������� ��� ������ ������ �� CSV �����
std::vector<Data> readDataFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    std::vector<Data> data;
    if (!infile) {
        std::cerr << "Could not open the file " << filename << "!" << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(infile, line)) { // ��������� ������ ������ �� �����
        std::stringstream ss(line);
        Data entry;
        if (ss >> entry.user_id >> entry.product_id >> entry.timestamp) {
            data.push_back(entry);
        }
    }

    infile.close();
    return data;
}

int main() {
    // ������ ������ ������� � ������� ���
    std::vector<Data> firstDayData = readDataFromFile("FirstDay.txt");
    std::vector<Data> secondDayData = readDataFromFile("SecondDay.txt");

    // ������� ��� �������� ���������� ������� ������ ������������� �� ��� ���
    std::unordered_map<unsigned int, std::unordered_set<unsigned int>> userPagesFirstDay;
    std::unordered_map<unsigned int, std::unordered_set<unsigned int>> userPagesSecondDay;

    // ���������� ������ ������� ���
    for (const auto& entry : firstDayData) {
        userPagesFirstDay[entry.user_id].insert(entry.product_id);
    }

    // ���������� ������ ������� ���
    for (const auto& entry : secondDayData) {
        userPagesSecondDay[entry.user_id].insert(entry.product_id);
    }

    // ��������� �������������, ������� �������� ���� � ����� �� ���� ����
    std::unordered_set<unsigned int> usersVisitedAnyDay;
    std::unordered_set<unsigned int> usersVisitedNewPageSecondDay;

    // ���������� �������������, ���������� ���� � ������ ����
    for (const auto& entry : userPagesFirstDay) {
        usersVisitedAnyDay.insert(entry.first);
    }

    // ���������� �������������, ���������� ���� �� ������ ���� � �������� �� ����� ��������
    for (const auto& entry : userPagesSecondDay) {
        usersVisitedAnyDay.insert(entry.first);
        if (userPagesFirstDay.find(entry.first) != userPagesFirstDay.end()) {
            const auto& pagesFirstDay = userPagesFirstDay[entry.first];
            const auto& pagesSecondDay = entry.second;

            for (const auto& page : pagesSecondDay) {
                if (pagesFirstDay.find(page) == pagesFirstDay.end()) {
                    usersVisitedNewPageSecondDay.insert(entry.first);
                    break;
                }
            }
        }
    }

    // ����� �����������
    std::cout << "Number of users who visited pages on any day: " << usersVisitedAnyDay.size() << std::endl;
    std::cout << "User IDs: ";
    for (const auto& user_id : usersVisitedAnyDay) {
        std::cout << user_id << "| ";
    }
    std::cout << std::endl;

    std::cout << "Number of users who visited new pages on the second day: " << usersVisitedNewPageSecondDay.size() << std::endl;
    std::cout << "User IDs: ";
    for (const auto& user_id : usersVisitedNewPageSecondDay) {
        std::cout << user_id << "| ";
    }
    std::cout << std::endl;

    return 0;
}
