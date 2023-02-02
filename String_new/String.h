#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>

using std::cin;
using std::cout;
using std::endl;
class String;
String operator+(const String& left, const String& right);
class String
{
	size_t SI;
	char* str;

public:
	size_t get_SI() const;
	const char* get_str() const;
	char* get_str();
	explicit String(size_t size = 80);// :SI(size), str(new char[SI] {});
	String(const char* st); // :SI(strlen(st) + 1), str(new char[SI] {});
	String(const String& other); // :SI(other.SI), str(new char[SI] {})
	String(String&& other);
	~String();
	String& operator=(const String& other);
	String& operator+=(const String& other);
	String& operator=(String&& other);
	char& operator[](int i);
	const char& operator[](int i) const;
	void print();

};
String operator+(const String& left, const String& right);
std::ostream& operator << (std::ostream& os, const String& obj);

