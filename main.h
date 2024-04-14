#ifndef MAIN_H
#define MAIN_H

#include <string>

std::string inputText(const std::string &pot);
void izpis_KMPnext(const int* polje, int len);
std::string reverseString(std::string& str);
void Izpis_Stevil(std::string* polje, unsigned int velikost);
void Izpis_Stevil1(std::string* polje, unsigned int velikost);
int sestej(int a, int b);
void KMP(const std::string& text, const std::string& vzorec);
void Sunday(const std::string& text, const std::string& vzorec);

#endif // MAIN_H

