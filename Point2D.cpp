#include "Point2D.h"

using namespace std;

// ����������� ��������� ������������ ���� ������ � ����� ��������������,
// ��� ����������� ��� ������ - ��������������� (���������� �� ����� ���������)
unsigned int Point2D::instantinationCount = 0;
unsigned int Point2D::instanceCount = 0;

Point2D::Point2D() {
    // ��� ��������� � ������ ������� ������ ������� ���� Point2D
    // �������� ������� �������� ����������� � �������� ����� ����������� ����������� ���� �������� �� �������
    instantinationCount++;
    instanceCount++;
    this->setX(0);
    this->setY(0);
    this->color = new char[25];
    this->setColor("black");
}

// ���������� ������������ �� ����� �����������
Point2D::Point2D(int x, int y, const char* color) {
    instantinationCount++;
    instanceCount++;
    this->setX(x);
    this->setY(y);
    this->color = new char[25];
    this->setColor(color);
}

Point2D::Point2D(Point2D& p)
{
    instantinationCount++;
    instanceCount++;
    this->setX(p.getX());
    this->setY(p.getY());
    this->color = new char[25];
    this->setColor(p.getColor());
}

Point2D::~Point2D() {
    // ��� �������� �� ������ ������� ������� ���� Point2D ������� ����������� ��������� ��� �������� �� �������
    instanceCount--;
    delete[] color;
}

void Point2D::validate(int value, char fieldName)
{
    if (value < 0)
    {
        // throw exception("value of the field "s + fieldName + " must be greather or equals 0"s);
        // TODO � ����� ������ ��������� �� ������ ��������� �������� value, �� ��������� ���������
        // ���������: ����� ������ ����� �������� ���������� ��� ������� ��������, � ������ ����� ����������� ������� m;
        // ����� ����� ����������� ������ ����������� ������� ����� ��� �������� ������� m, �������� ��� ������������

        // ���������� ���� ���������� value � ������
        string valueString = to_string(value);
        // ������ ��������� �� ������ � ������ �������� ��� �������� 19 ��� "����������" ����� ����,
        // ������� ������������������� ������� ����������� (x ��� y)
        const char* message = "value of the field   must be greather or equals 0, not ";
        // ������ ������� ��������� ����� �������
        const int messageTemplateLength = strlen(message);
        // ����� ���������� ���� ������ valueString � const char*
        // � ���������� ����� ���� ������
        int valueStringLength = strlen(valueString.c_str());
        // char m[50];
        // ���������� ��������� ����� ������ ��������� �� ������,
        // ��� 1 - ���������� ����� �������, ����� ����� � ��������� �������������� �������
        // �������� ������ ��������� ������ \0
        int messageLength = messageTemplateLength + valueStringLength + 1;
        // �������� �������, � ������� ����� �������� ��� ������� ��������� �� ������
        // (������ ��� ���� �������� �����������, � ������� ����� new, ������ ��� ����� ����� ������� ����� ������
        // ������ �� ����� ���������� ���������, ����� ��������� ������ ��������� �������� value)
        char* m = new char[messageLength];
        // ������ � �������� ������ ���� �������� �������
        for (int i = 0; i < messageTemplateLength; i++)
        {
            m[i] = message[i];
        }
        // ����������� � ������ ����� ����, �������� ��� �������� �� ������ ���������
        m[19] = fieldName;
        // ���������� � ����� ������� ��������� �� ������ �������� �� ������,
        // ������������ ��������, �� ��������� ��������
        for (int i = messageTemplateLength; i < messageLength - 1; i++)
        {
            m[i] = valueString[i - messageTemplateLength];
        }
        // �������� ������ ��������� ������ \0
        m[messageLength - 1] = '\0';
        throw exception(m);
    }
}

void Point2D::setX(int x) {
    validate(x, 'x');
    this->x = x;
}

void Point2D::setY(int y) {
    validate(y, 'y');
    this->y = y;
}

void Point2D::setColor(const char* newColor) {
    if (newColor == nullptr)
    {
        throw exception("null pointer exception");
    }
    /* delete[] color;
    int length = strlen(newColor);
    color = new char[length + 1];
    for (int i = 0; i <= length; i++)
    {
        color[i] = newColor[i];
    } */
    for (int i = 0; i <= strlen(color); i++)
    {
        color[i] = newColor[i];
    }
}