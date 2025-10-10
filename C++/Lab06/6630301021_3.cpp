//6630301021 Aphinan Thianhao

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> operands;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            int number = 0;
            for (size_t i = 0; i < token.size(); ++i) {
                number = number * 10 + (token[i] - '0');
            }
            operands.push(number);
        } else {
            int right = operands.top();
            operands.pop();
            int left = operands.top();
            operands.pop();

            if (token == "+") {
                operands.push(left + right);
            } else if (token == "-") {
                operands.push(left - right);
            } else if (token == "*") {
                operands.push(left * right);
            }
        }
    }
    return operands.top();
}

int main() {
	
    cout << "Input : ";

    string input;
    getline(cin, input, '.');

    input.erase(0, input.find_first_not_of(' '));
    input.erase(input.find_last_not_of(' ') + 1);
    
    stringstream cleanStream(input);
    stringstream resultStream;
    string token;
    bool firstToken = true;

    while (cleanStream >> token) {
        if (!firstToken) {
            resultStream << ' ';
        }
        resultStream << token;
        firstToken = false;
    }
    string cleanedInput = resultStream.str();

    int result = evaluatePostfix(cleanedInput);

    cout << "Output : " << result << endl;

    return 0;
}
