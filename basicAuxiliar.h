#include <iostream>
#include <string>
#include <map>

using namespace std;

//Convertir string a integer--------------------
int strToInt(string str){
	int result = 0;
	int i = 0;
	while (i < str.length() && isdigit(str[i])) {
		if (i != ' '){
			result = result * 10 + (str[i] - '0');	
		}
        
        i++;
    }
    return result;
};

