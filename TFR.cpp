#include "TFR.h"

string FileLink = "";
string Buff;

bool TFR::HasTheDesiredAttribute(string AttributeName) {
    string Attribute = "";
    bool HasOrNot = false;
    for (int i = 1; i < Buff.length(); i++)
    {
        if (Buff[i] != ' ' && Buff[i] != '>' && Buff[i] != '=')
        {
            Attribute += Buff[i];
        }
        else if (Buff[i] == '=' && Attribute == AttributeName)
        {
            HasOrNot = true;
            break;
        }
        else if (Buff[i] == ' ')
        {
            Attribute = "";
        }
        else if (Buff[i] == '>')
        {
            break;
        }
    }
    return HasOrNot;
}

string TFR::GetAttributeValue(string AttributeName) { //Значение атрибута
    string Attribute = "";
    string AttributeV = "";
    int BuffL = Buff.length();
    for (int i = 1; i < BuffL; i++)
    {
        if (Buff[i] != ' ' && Buff[i] != '>' && Buff[i] != '=')
        {
            Attribute += Buff[i];
        }
        else if (Buff[i] == '=' && Attribute == AttributeName)
        {
            for (int j = i + 1; j < BuffL; j++)
            {
                if (Buff[j] != ' ' && Buff[j] != '>') {
                    AttributeV += Buff[j];
                }
                else {
                    break;
                }
            }
            break;
        }
        else if (Buff[i] == ' ')
        {
            Attribute = "";
        }
        else if (Buff[i] == '>')
        {
            break;
        }
    }
    return AttributeV;
}

void TFR::TFRFile(string File) { //Получение ссылки на файл
    FileLink = File;
}

string TFR::GetTagFromLine() { //Получение тэга строки (больше для работы системы)
    string TagInLine = "";
    if (Buff[0] == '<') {
        for (int i = 1; i < Buff.length(); i++)
        {
            if (Buff[i] != '>' && Buff[i] != ' ')
            {
                TagInLine += Buff[i];
            }
            else {
                break;
            }
        }
    }
    return TagInLine;
}
string TFR::GetFromMultipleTags(int SIZE,string Tag,string AttributeName[],string AttributeValue[]) {
    bool Has = false;
    string TextInLine = "";
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            if (Tag == GetTagFromLine())
            {
                for (int i = 0; i < SIZE; i++)
                {
                    if (GetAttributeValue(AttributeName[i]) == AttributeValue[i]) {
                        Has = true;
                    }
                    else if (i == 0 || Has) {
                        Has = false;
                        break;
                    }
                }

                for (int i = 0; i < Buff.length(); i++)
                {
                    if (Buff[i] == '>' && Has) {
                        for (int j = i + 1; j < Buff.length(); j++)
                        {
                            TextInLine += Buff[j];
                        }
                        break;
                    }
                }
            }
        }
        ofile.close();
        return TextInLine;
    }
}

int TFR::TagCount(string Tag) { //Количество тэгов в файле
    string LBuff;
    string TagInLine = "";
    int Count = 0;
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            if (Tag == GetTagFromLine())
            {
                Count++;
            }
        }
        ofile.close();
        return Count;
    }
}




string TFR::ReadFromTag(string Tag) { //Получение одиночной строки по тэгу
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();
            for (int i = 0; i < BuffL; i++)
            {
                if (Buff[i] == '>' && Tag == GetTagFromLine()) {
                    for (int j = i + 1; j < BuffL; j++)
                    {
                        TextInLine += Buff[j];
                    }
                    ofile.close();
                    return TextInLine;
                }
            }
        }
    }
}

string TFR::GetMultiLine(string Tag) { //Получение многострочного текста по тэгу
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);

    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();

           if (Buff[0] == '<')
            {
                for (int i = 1; i < BuffL; i++)
                {
                    if (Buff[i] == '>' && Tag == GetTagFromLine()) {
                        for (int j = i + 1; j < BuffL; j++)
                        {
                            TextInLine += Buff[j];
                        }
                        break;
                    }
                }
            }
            else {
                TextInLine += '\n' + Buff;
            }
        }
        ofile.close();
        return TextInLine;
    }
}

string TFR::GetMultiLineOfAttribute(string Tag, string AttributeName, string AttributeValue) { //Получение многострочного текста по тэгу
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);

    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();

            if (Buff[0] == '<')
            {
                for (int i = 1; i < BuffL; i++)
                {
                    if (Buff[i] == '>' && Tag == GetTagFromLine() && HasTheDesiredAttribute(AttributeName) && AttributeValue == GetAttributeValue(AttributeName)) {
                        for (int j = i + 1; j < BuffL; j++)
                        {
                            TextInLine += Buff[j];
                        }
                        break;
                    }
                }
            }
            else {
                TextInLine += '\n' + Buff;
            }
        }
        ofile.close();
        return TextInLine;
    }
}

string TFR::GetLineOfAttribute(string Tag, string AttributeName, string AttributeValue) { //Получение строки с нужным тэгом, атрибутом, значением атрибута
    string AttributeN = "";
    string AttributeV = "";
    string TextInLine;
    int BuffL = 0;
    ifstream ofile(FileLink);
    if (ofile.is_open()) {
        while (!ofile.eof())
        {
            getline(ofile, Buff, '\n');
            BuffL = Buff.length();
            if (Tag == GetTagFromLine() && HasTheDesiredAttribute(AttributeName) && AttributeValue == GetAttributeValue(AttributeName))
            {
                for (int i = 0; i < BuffL; i++)
                {
                    if (Buff[i] == '>') {
                        for (int j = i + 1; j < BuffL; j++)
                        {
                            TextInLine += Buff[j];
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    ofile.close();
    return TextInLine;
}
