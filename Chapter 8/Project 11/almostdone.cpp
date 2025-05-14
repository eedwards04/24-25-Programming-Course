#include <iostream>
#include <string>

using namespace std;

// Decrypt function
string decryptMessage(const string& encrypted, int key) {
    string decrypted;

    for (char ch : encrypted) {
        int val = static_cast<int>(ch);
        if (val - key < 32) {
            decrypted += static_cast<char>(127 - (32 - (val - key)));
        } else {
            decrypted += static_cast<char>(val - key);
        }
    }

    return decrypted;
}

int main() {
    string encryptedMessage = ":mmZ\\dxZmx]Zpgy";

    cout << "Trying all keys (1 to 100)...\n\n";
    for (int key = 1; key <= 100; key++) {
        string decrypted = decryptMessage(encryptedMessage, key);
        cout << "Key " << key << ": " << decrypted << endl;
    }

    return 0;
}
 