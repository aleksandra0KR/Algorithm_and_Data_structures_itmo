#include <iostream>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::regex;

bool right_patern(string& str) {
    regex cheking_pattern(R"([A-Z][a-z]* [A-Z][a-z]* [A-Z][a-z]* [0-9]{2} (\+?7[0-9]{10}|\+7\([0-9]{3}\)\-[0-9]{3}\-[0-9]{2}\-[0-9]{2}|8[0-9]{10}|\+7\([0-9]{3}\)[0-9]{3}\-[0-9]{4}|8[0-9]{10}) g\.[A-Z]{3}, ul\.[A-Z][a-z]*, d\.[0-9]{2,})");
    return regex_match(str, cheking_pattern);
}
int main() {

    cin.tie(0);
    std::ios_base::sync_with_stdio(false);

    int requests;
    cin >> requests;
    cin.ignore();

    for (int i = 0; i < requests; i++) {
        string str;
        getline(cin, str);

        if (right_patern(str)) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}