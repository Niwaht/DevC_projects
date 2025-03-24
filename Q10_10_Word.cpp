#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// Directions for searching (right, left, down, up, diagonals)
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

// Change everything to lowercase for easier comparison
string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

// Check letters around a letter to find word
bool searchWord(vector<string>& table, string word, int x, int y, int dirX, int dirY) {
    int len = word.size();
    int m = table.size(), n = table[0].size();

    for (int i = 0; i < len; i++) {
        int nx = x + i * dirX;
        int ny = y + i * dirY;

        if (nx < 0 || ny < 0 || nx >= m || ny >= n || tolower(table[nx][ny]) != word[i])
            return false;
    }
    return true;
}

// Find index that contains word
void findWords(vector<string>& table, vector<string>& keywords) {
    int m = table.size();
    int n = table[0].size();

    // Conversion to lowercase (for easier comparison)
    for (string &row : table) row = toLower(row);

    for (string word : keywords) {
        word = toLower(word);
        bool found = false;

        for (int i = 0; i < m && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (table[i][j] == word[0]) {
                    // Search in 8 directions
                    for (int d = 0; d < 8; d++) {
                        if (searchWord(table, word, i, j, dx[d], dy[d])) {
                        	// Output if found
                            cout << i << " " << j << endl;
                            found = true;
                            break;
                        }
                    }
                }
            }
        }
        // Output if not found
        if (!found) {
            cout << word << " not found\n";
        }
    }
}

int main() {
	// Input
    int m, n;
    cin >> m >> n;

    vector<string> table(m);
    for (int i = 0; i < m; i++) cin >> table[i];

    int c;
    cin >> c;
    vector<string> keywords(c);
    for (int i = 0; i < c; i++) cin >> keywords[i];

	// Processing
    findWords(table, keywords);

    return 0;
}