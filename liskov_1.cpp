#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class FileReader {
public:
    virtual vector<string> readFile(const string& filename) const {
        vector<string> data;
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                data.push_back(line);
            }
            file.close();
        } else {
            throw runtime_error("Failed to open file: " + filename); // Now base class also throws exception
        }

        return data;
    }
};

class CSVReader : public FileReader {
public:
    vector<string> readFile(const string& filename) const override {
        vector<string> data;
        ifstream file(filename);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                // Process CSV line
                if (line.empty() || line[0] == '#') // Skip empty lines or comments
                    continue;
                data.push_back(line);
            }
            file.close();
        } else {
            throw runtime_error("Failed to open file: " + filename);
        }

        return data;
    }
};

int main() {
    FileReader fileReader;
    CSVReader csvReader;

    try {
        vector<string> data = fileReader.readFile("data.txt");
        for (const auto& line : data) {
            cout << line << endl;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    try {
        vector<string> data = csvReader.readFile("data.csv");
        for (const auto& line : data) {
            cout << line << endl;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
