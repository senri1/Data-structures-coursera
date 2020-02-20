#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int is_valid(const string &str) {
    if(str.size() == 1)
        return 1;
    vector<char> stack(0);
    vector<int> index(0);
    int num_brackets = 3;
    char open_brackets[] = {'(', '[', '{'};
    char close_brackets[] = {')', ']', '}'};
    bool skip = false;
    for(int i = 0; i<str.size(); i++) {
        for(int k = 0; k< num_brackets; k++) {
            if (str[i] == open_brackets[k]) {
                skip = true;
                stack.push_back(str[i]);
                index.push_back(i);
                break;
            }
        }
        if(!skip) {
            for(int j = 0; j< num_brackets; j++) {
                if(str[i] == close_brackets[j]) {
                    if(i == 0)
                        return 1;
                    if(stack.empty())
                        return i + 1;
                    if(stack.back() == open_brackets[j]){
                        stack.pop_back();
                        index.pop_back();
                    }
                    else {
                        return i+1;
                    }
                    break;
                }
            }
        }
        skip = false;
    }
    if(stack.empty())
        return -1;
    else {
        return index.front() + 1;
    }

}


int main() {

    string input; 
    std::cin >> input;
    int valid = is_valid(input);
    if(valid == -1)
        std::cout<< "Success";
    else
        std::cout<< valid;
    return 0;
}
