#include <iostream>

using namespace std;

class videoInfo {
public:
    string title, director, genre, time, ageLimit, nation, person;          // �����̸� ���� �帣 ����Ÿ�� ���忬�� ��������� �뿩Ƚ��
    int videoAdress = 0, borrowAdress = 0, rentCount = 0;                   // ���� �ּ�, ����������ּ�
};

class userInfo {
public:
    string name, home, Pnum, borrowVideo, borrowDay, returnDay;              // ������ �Ż�����, ������ ����,  ������ ��¥, �ݳ���¥
    int fine = 0, age = 0, point = 0, userAdress = 0;                                                       // ���� ��ü��, ����, ����Ʈ
};