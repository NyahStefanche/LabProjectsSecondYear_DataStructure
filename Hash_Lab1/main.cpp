//�� ��� � �������(�� ������ �� � �����) ��������� �8,1���.
#include <iostream>
#include "Hash.h"
#include <string>
using namespace std;
//��������������� ���� �� ������������
struct course { string title; int hours; };

//������������ ���� �� ����������
struct student { string name; int year; float grade; };
//������ ������� �� ������� �� ����� ���������� �����
void print_info_student(Hash<student> s1)
{
	int fac_number;
	cin >> fac_number;
	student s;
	if (s1.GetInfo(fac_number, s))
	{
		cout << s.name << " " << s.year<<" "<< s.grade << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}
//������ ����� �� ���� ����������
void add_course(Hash<course>& t)
{
	int num;
	course c;
	cin >> num >> c.title >> c.hours;
	if (t.Add(num, c))cout << "Added" << endl;
	else cout << "Error" << endl;
}
//������ ����� �� ��� �������
void add_student(Hash<student>& h)
{
	int fn;
	student s;
	cin >> fn >> s.name >> s.year >> s.grade;
	if (h.Add(fn, s))cout << "Added" << endl;
	else cout << "Error" << endl;
}

//����� �� ���������� �� ����������
void print_info_course(Hash<course> h)
{
	int number_course;
	cin >> number_course;
	course c;
	if (h.GetInfo(number_course, c))
	{
		cout << c.title << " " << c.hours << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}

//��������� �� ������� � ����� ����
void update_year(Hash<student>& h, Hash<student>& ha)
{
	int fn;
	cin >> fn;
	student s;
	if (!h.GetInfo(fn, s))
	{
		cout << "not found"<< endl;
		return;
	}
	if (s.year <= 3)
	{
		s.year++;
		h.UpdateInfo(fn, s);
	}
	else //��������� � � 4-�� ����
	{
		h.Del(fn);
		ha.Add(fn, s);
	}
}
//������� � ��������� �� ���������� �� ����� ����� �� ������������
void update_hours(Hash<course>& h)
{
	int num_course;
	cin >> num_course;
	course c;
	if (!h.GetInfo(num_course, c))
	{
		cout << "not found" << endl;
		return;
	}
	else
	{
		cout << "Found" << endl;
		cin >> c.hours;
		h.UpdateInfo(num_course, c);
	}
}

//���������� �� �������� � ����, ��-����� �� k
template<class T>
void archive(Hash<T>& h, Hash<T>& ha, int k)
{
	T info_data;
	for (int num = 1; num < k; num++)
	{
		if (h.GetInfo(num, info_data))
		{
			h.Del(num);
			ha.Add(num, info_data);
		}
	}
}

int main()
{
	Hash<course> hc(103), hca(53);
	Hash<student> hs(1003), hsa(503);
	add_student(hs);
	add_course(hc);
	print_info_course(hc);
	print_info_student(hs);
	update_year(hs, hsa);
	update_hours(hc);
	int num_course;
	cin >> num_course;
	archive(hc, hca, num_course);
	int fn;
	cin >> fn;
	archive(hs, hsa, fn);
	return 0;
}
