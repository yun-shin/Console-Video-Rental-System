#include <vector>
#include <ctime>        // ���� ��¥ ���

#include "info.h"


class videoFuc {
public:
    // ������ȭ
    void readVideoFile ();              // ���� ���� ������ȭ
    void readUserFile ();               // ���� ���� ������ȭ
    void saveVideoFile ();              // �������� ����
    void saveUserFile ();               // �������� ����

    // �ʼ����
    void inputVideo ();                 // ���� �߰� �Լ�
    void inputUser ();                  // ���� �߰� �Լ�
    void delVideo ();                   // ���� ���� �Լ�
    void delUser ();                    // ���� ���� �Լ�
    void videoModify ();                // ���� ���� �Լ�
    void userModify ();                 // ���� ���� �Լ�
    void videoTitleSearch ();           // ���� ���� �˻� �Լ�
    void videoDirectorSearch ();        // ���� ���� �˻� �Լ�
    void videoGenreSearch ();           // ���� �帣 �˻� �Լ�
    void videoAgeLimitSearch ();        // ���� �������� �˻� �Լ�
    void videoNationSearch ();          // ���� ���� ���� �˻� �Լ�
    void userNameSearch ();             // ���� �̸� �˻� �Լ�
    void userHomeSearch ();             // ���� �ּ� �˻��Լ�
    void borrowVideo (int num);         // ���� �뿩 ��� �Լ�
    void returnVideo (int num);         // ���� �ݳ� ��� �Լ�
    void fineResult ();                 // ��ü�� ��� �� ��� �Լ�
    int fineCalculation (int num);      // ��ü �Ⱓ ��� �Լ�

    // ��� ����
    void videoMenu ();                  // ���� ���� ��� ����
    void userMenu ();                   // ���� ���� ��� ����
    void Borrow_And_Details ();         // ���� �뿩, ������ ��� ����
    void videoSearchEngine ();          // ���� �˻� ��� ����
    void userSearchEngine ();          // ���� �˻� ��� ����

    // ���
    void videoSituation ();             // ���� �κ� ���
    void printVideo ();                 // ���� ���� ���
    void videoDetails (int num);        // �ش� ��� ���λ��� ���
    void userSituation ();              // ���� �κ� ���
    void printUser ();                  // ���� ���� ���
    void userProportion (int num);      // �ش� ���� ���
    void showAlignment ();              // ���ĺ��� �Լ�


    // ����ó��
    int lengthCheck (string st);        // ���ڿ� ���� ����
    string replaceAll (const string& str, const string& pattern, const string& replace);        // ���ڿ����� ���� ��� �ٲٱ�
        
    // ����, Ŭ���� �� ����
    videoInfo vData;                        // ���� ���� Ŭ����
    userInfo uData;                         // ���� ���� Ŭ����
    vector <videoInfo> videoData;           // ���� ����
    vector <userInfo> userData;             // ���� ����

    // �ð� ����
    time_t now = time (NULL);                       // ����ð�
    time_t reDay;                                   // �ݳ���¥
    struct tm t = *localtime (&now);                // ����ð�
    struct tm past;                                 // �ݳ���¥

    int curr_year = t.tm_year - 100;
    int curr_month = t.tm_mon + 1;
    int curr_day = t.tm_mday;
    int curr_hour = t.tm_hour;
    int curr_minute = t.tm_min;
    int curr_second = t.tm_sec;
};