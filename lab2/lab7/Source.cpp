#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include<Windows.h>

using namespace std;

string toLower(const string& s) {
    string result = s;
    transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) { return tolower(c); });
    return result;
}

vector<string> splitWords(const string& line) {
    vector<string> words;
    string word;
    istringstream stream(line);
    while (stream >> word) {
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        words.push_back(toLower(word));  
    }
    return words;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    multimap<string, int> wordIndex;
    string line;
    int lineNumber = 0;
    cout << "Введіть текст (порожній рядок для завершення):" << endl;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;  
        }
        ++lineNumber;   
        vector<string> words = splitWords(line);
        for (const string& word : words) {
            wordIndex.insert(make_pair(word, lineNumber));
        }
    }
    cout << "\nАлфавітний покажчик:\n";
    string currentWord;
    for (const auto& pair : wordIndex) {
        if (pair.first != currentWord) {
            currentWord = pair.first;
            cout << currentWord << ": ";
            auto range = wordIndex.equal_range(currentWord);
            for (auto it = range.first; it != range.second; ++it) {
                cout << it->second << " ";
            }
            cout << endl;
        }
    }
    cout << "\nВведіть слово для пошуку: ";
    string searchWord;
    cin >> searchWord;
    searchWord = toLower(searchWord);  
    auto range = wordIndex.equal_range(searchWord);
    if (range.first != range.second) {
        cout << "Слово \"" << searchWord << "\" зустрічається у рядках: ";
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->second << " ";
        }
        cout << endl;
    }
    else {
        cout << "Слово \"" << searchWord << "\" не знайдено." << endl;
    }

    return 0;
}
