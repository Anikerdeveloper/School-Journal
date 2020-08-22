#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class TFR
{
private:
	bool HasTheDesiredAttribute(string AttributeName);
	string GetAttributeValue(string AttributeName);//�������� ��������
public:
	void TFRFile(string File);//��������� ������ �� ����
	string GetTagFromLine();//��������� ���� ������ (������ ��� ������ �������)
	string GetFromMultipleTags(int SIZE, string Tag, string AttributeName[], string AttributeValue[]);
	int TagCount(string Tag);//���������� ����� � �����
	string ReadFromTag(string Tag); //��������� ��������� ������ �� ����
	string GetMultiLine(string Tag); //��������� �������������� ������ �� ����
	string GetMultiLineOfAttribute(string Tag, string AttributeName, string AttributeValue);
	string GetLineOfAttribute(string Tag, string AttributeName, string AttributeValue); //��������� ������ � ������ �����, ���������, ��������� ��������
};

