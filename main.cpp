#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


string encryptUserInput(string userInput);
string decryptUserInput(string userInput1);
void main_p();

int main() {
    main_p();
    return 0;
}


/* Encrypts user_input using substitution.
 *
 * */
string encryptUserInput(string userInput) {
    vector <int> location_alphabet{};
    string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz "};
    string key{"@tskBiPzjWgnCeDhGyIxwmfHXlopvqcdErMFVAuJLKUONRQaSTYZ!"};
    string user_temp{userInput};

    for(auto i{0}; i < userInput.length(); i++ ) {
        location_alphabet.push_back(alphabet.find(userInput[i]));
//        cout << location_alphabet[i] << endl;
        user_temp[i] = key[location_alphabet[i]];
    }

    return user_temp;
}

string decryptUserInput(string userInput1) {
    vector <int> location_key{};
    string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz "};
    string key{"@tskBiPzjWgnCeDhGyIxwmfHXlopvqcdErMFVAuJLKUONRQaSTYZ!"};
    string user_temp{userInput1};

    for(auto i{0}; i < userInput1.length(); i++ ) {
        location_key.push_back(key.find(userInput1[i]));
//        cout << location_key[i] << endl;
        user_temp[i] = alphabet[location_key[i]];
    }

    return user_temp;
}

void main_p() {
    cout << "Please enter sentence you want to encrypt: ";
    string user_input;
    getline(cin, user_input);
    cout << "Encrypting. . . " << endl << encryptUserInput(user_input) << endl << endl;
    string console_output{encryptUserInput(user_input)};
    cout << "Decrypting. . ." << endl << decryptUserInput(console_output) << endl;

}