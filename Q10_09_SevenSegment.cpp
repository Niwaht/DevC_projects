#include <iostream>
#include <vector>
#include <string>
using namespace std;

// A standard form used for conversion to result
const string segmentPatterns[10] = {
    "010101111", // 0
    "000001001", // 1
    "010011110", // 2
    "010011011", // 3
    "000111001", // 4
    "010110011", // 5
    "010110111", // 6
    "010001001", // 7
    "010111111", // 8
    "010111011"  // 9
};

// Function for conversion
vector<string> convertToCode(vector<string> v, int length)
{
	vector<string> dgcodes;
    vector<string>::iterator it;
    string dgcode[length], str[3];
    
    int i = 0, j = 0, k = 0;
    for (it = v.begin(); it != v.end(); it++){
        // Read vector line to str[i] variable
        str[i]= *it;
        i++;
    }
    
    int len = str[0].length();
    i=0;

    while(j<=len) {

        // cout << "process: " << str[i] << '\n';
        // cout << "<1>i: " << i << ", j: " << j << ", k: " << k << '\n';

        if ((str[i][j] == '_')||(str[i][j] == '|')) {
            // cout << "1" << str[i][j] << '\n';
            dgcode[k] += "1";
        }
        else {
            // cout << "0" << str[i][j] << '\n';
            dgcode[k] += "0";
        }

        // cout << "<2>i: " << i << ", j: " << j << ", k: " << k << '\n';
        if ((j==(k*4)+2)&&(i!=2)) {         //if j reach last column fetch next row (2, 6, 10, 14,...)
            i++;        //set i to next row
            j=(k*4);    //set j to first column
        }
        else if ((i==2)&&(j==(k*4)+2)) {   //if j reach end of character fetch next character (i=2)&& j in (2, 6, 10, 14, ...)
                k++;    //set k to next character
                j=(k*4);//set j to first column
                i=0;    //set i to first row
            }
            else  //if not finish in row just increment j
                j++;    //set j to next column
    } //--while--

    for (int i=0; i<length; i++)
        dgcodes.push_back(dgcode[i]);
    
    return dgcodes;
}    

int convertToInteger(vector<string> codes)
{
	int num = 0;
    for (string code : codes) {
	    for (int i = 0; i < 10; i++) { // Adjusted range
	        if (code == segmentPatterns[i]) { // Compare correctly
	            num *= 10;
	            num += i; // Append the matching digit
	        }
	    }
	}
	return num;
}

int main() {
	// Input
    int n, m;
    cin >> n >> m;
	vector<string> num1(3), num2(3);
	
	cin.ignore();
	for(int i = 0; i < 3; i++) getline(cin, num1[i]);
	for(int i = 0; i < 3; i++) getline(cin, num2[i]);
	
    // Conversion
    vector<string> con1 = convertToCode(num1, n);
    vector<string> con2 = convertToCode(num2, m);
    
	int res1 = convertToInteger(con1);
    int res2 = convertToInteger(con2);
    
    // Output
    // cout << "Number 1: " << res1 << endl;
    // cout << "Number 2: " << res2 << endl;
    cout << res1 + res2 << endl;
    
    return 0;
}