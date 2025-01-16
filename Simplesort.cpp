#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

int main() {
    using std::cout;
    using std::string;

    string directoryPath;
    std::vector<std::pair<fs::path, uintmax_t>> files;

    
    cout << "Enter the directory path: ";
    std::getline(std::cin, directoryPath);
    
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        cout << "invalid path.\n";
        return 1; 
    }
                                                               //0_o
    
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (fs::is_regular_file(entry)) { 
            files.push_back({entry.path(), fs::file_size(entry)}); 
        }
    }

    
    std::sort(files.begin(), files.end(), [](const auto& a, const auto& b) {
        return a.second < b.second; 
    });

    
    for (const auto& file : files) { 
        cout << "File: " << file.first << ", Size: " << file.second << " bytes\n"; 
    }

    cout << "\n";
    std::cin.get(); 

    return 0;
}
