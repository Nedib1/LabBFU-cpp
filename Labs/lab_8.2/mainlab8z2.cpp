#include <iostream>
#include <string>
#include <fstream>
#include <set>


bool read(int&n, std::string words[5120]){
    std::ifstream in("input.txt");
    if(!in.is_open()){
        std::cout << "File not opened" << std::endl;
        return false;
    }

    n = 0;
    while (!in.eof()){
        in >> words[n];
        n++;
    }


    return true;
}

void write(int&n, std::string words[5120]) {

    for(int i = 0; i < n; i++)
        std::cout << "<" << words[i] << ">" << std::endl;
}

bool ispalindrome(std::string& words) {
    int left = 0, right = words.size() - 1;
    while (left < right) {
        if (tolower(words[left]) != tolower(words[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

int countsogl(const std::string& words) {
    std::string vowels = "aeiouAEIOU";
    int count = 0;
    for (char c : words) {
        if (isalpha(c) && vowels.find(c) == std::string::npos) {
            count++;
        }
    }
    return count;
}

std::string duplicatvowels(const std::string& words) {
    std::string vowels = "aeiouAEIOU";
    std::string result;
    for (char c : words) {
        result += c;
        if (vowels.find(c) != std::string::npos) result += c;
    }
    return result;

}


int main() {

    int n;
    std::string words[5120];

    read(n, words);
    
    bool haspalindrome = false;
    for (int i = 0; i < n; i++){
        if (words[i].size() > 1 && ispalindrome(words[i])) {
            haspalindrome = true;
            break;
        }
    }    

    if  (!haspalindrome) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (countsogl(words[i]) < countsogl(words[j])) std::swap(words[i], words[j]);
            }
        }
        write(n, words);
    }


    else if (haspalindrome) {
        std::set<std::string> modwords;
        for (int i = 0; i < n; i++) {
            modwords.insert(duplicatvowels(words[i]));
        }

        for (auto word = modwords.rbegin(); word != modwords.rend(); word++) std::cout << *word << std::endl;     
    }


    return 0;
}