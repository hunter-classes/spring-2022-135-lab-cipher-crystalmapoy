#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cfloat>

#include "funcs.h"


char shiftChar(char c, int rshift){
    for (int i = 1; i <= rshift; i++){
        if (isalpha(c) == true){ 
            if (c == 'z' || c == 'Z'){
                if (c == 'z'){
                    c = 'a';
                }
                else if (c == 'Z'){
                    c = 'A';
                }
            }
            else {
            c = c + 1; 
            }
        }
        else { 
            c = c;
        }
    }
    return c;
}

std::string encryptCaesar(std::string c, int rshift) {
    std::string result = "";

    int index = -1;

    while (c[++index])
        result += shiftChar(c[index], rshift);

    return result;
}

std::string decryptCaesar(std::string plaintext, int rshift){
    std::string s = "";
    int i = -1;
    while(plaintext[++i]){
        s = s + shiftChar(plaintext[i], -rshift);
    }
    return s;
}

double distance(std::vector <double> v1, std::vector <double> v2, int len){
  double distance;

  for(int i = 0; i < len; i++){
    if(v1[i] != 0){
      distance += pow(v1[i], 2) - pow(v2[i], 2);
    }
  }
    
  return sqrt(distance);
}


std::string solve(std::string encrypted_string){
  std::vector <double> englishFrequencies = {0.082, 0.015, 0.027, 0.047,
			      0.13, 0.022, 0.02, 0.062,
			      0.069, 0.0016, 0.0081, 0.04,
			      0.027, 0.067, 0.078, 0.019,
			      0.0011, 0.059, 0.062, 0.096,
			      0.027, 0.0097, 0.024, 0.0015,
			      0.02, 0.0078};
    std::vector <double> letterFrequencies = {0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0};
  int characters = 0;
  int rotate = 0;
  std::string rotation;

  std::string lower = "abcdefghijklmnopqrstuvwxyz";
  std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  double min = DBL_MAX;

  for(int i = 0; i < 26; i++){
        rotation = encryptCaesar(encrypted_string, i);
    for(int j = 0; j < encrypted_string.length(); j++){
        if(lower.find(rotation[j])!= std::string::npos){
	        letterFrequencies[lower.find(rotation[j])] += 1;
	        characters += 1;
        }
      else if(upper.find(rotation[j]) != std::string::npos){
	    letterFrequencies[upper.find(rotation[j])] += 1;
	    characters += 1;
	    }
    }

    int sum = 0;

    for(int j = 0; j < 26; j++){
      if (letterFrequencies[j] > 0){
	letterFrequencies[j] = letterFrequencies[j] / characters;
      }
    }

    if(min > distance(letterFrequencies, englishFrequencies, 26)){
	min = distance(letterFrequencies, englishFrequencies, 26);
	rotate = i;
      }

    letterFrequencies = {0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0,0, 0, 0,
			      0, 0, 0, 0,
			      0, 0};
    characters = 0;
  }
  std::string decrypted = decryptCaesar(encrypted_string, 26 - rotate);

  return decrypted;
}
