#pragma once

char shiftChar(char c, int rshift);
int charIndex(char);
std::string encryptCaesar(std::string, int);
std::string decryptCaesar(std::string plaintext, int rshift);
std::string solve(std::string encrypted_string);
double distance(double v1[], double v2[], int len);
