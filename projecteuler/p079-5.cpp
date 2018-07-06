#include <iostream>
#include <vector>
#include <ctime>

std::vector<bool> uniqueDigits(int* number, int limit) {
    std::vector<bool> result(10, false);
    for(int i = 0; i < limit; ++i) {
        int x = number[i] / 100;
        int y = number[i] / 10 % 10;
        int z = number[i] % 10;
        result[x] = true;
        result[y] = true;
        result[z] = true;
    }
    return result;
}

std::vector<std::vector<int>> comesBefore(int* arr, int limit) {
    std::vector<std::vector<int>> result(10, std::vector<int>(10, 0));
    for(int i = 0; i < limit; ++i) {
        int x = arr[i] / 100;
        int y = arr[i] / 10 % 10;
        int z = arr[i] % 10;
        if(result[x][y] == 0)
            ++result[x][y];
        if(result[x][z] == 0)
            ++result[x][z];
        if(result[y][z] == 0)
            ++result[y][z];
    }
    return result;
}

int numberOfEntries(std::vector<int>& arr) {
    int result = 0;
    for(auto i : arr)
        result += i;
    return result;
}

int main(int argc, const char * argv[]) {
    
    time_t start, finish;
    start = clock();
    
    int successfulLogins[] = {319, 680, 180, 690, 129, 620, 762, 689, 762, 318,
        368, 710, 720, 710, 629, 168, 160, 689, 716, 731,
        736, 729, 316, 729, 729, 710, 769, 290, 719, 680,
        318, 389, 162, 289, 162, 718, 729, 319, 790, 680,
        890, 362, 319, 760, 316, 729, 380, 319, 728, 716};
    
    std::vector<std::vector<int>> grid = comesBefore(successfulLogins, 50);
    std::vector<bool> uDigits = uniqueDigits(successfulLogins, 50);
    int numberOfDigits = 0;
    for(auto i : uDigits)
        if(i)
            ++numberOfDigits;
    std::vector<int> result(numberOfDigits, 0);
    for(int i = 0; i < 10; ++i) {
        int x = numberOfEntries(grid[i]);
        if(!uDigits[i])
            continue;
        result[numberOfDigits - x - 1] = i;
    }
    for(auto i : result)
        std::cout << i;
    std::cout << std::endl;
    
    finish = clock();
    std::cout << "Completed in " << float(finish - start) / CLOCKS_PER_SEC << " seconds.\n";
    
    return 0;
}