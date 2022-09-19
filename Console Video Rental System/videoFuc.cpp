
#include <iostream>
#include <fstream>      // ���� �����
#include <vector>       // vector ���
#include <algorithm>    // sort ���

#include <string>       // string  �Լ��̿� (stoi)
#include <cstring> // strtok ���, stcmp�� �� ���ڿ��� �� �ƽ�Ű ������ ũ�� 1, ������ 0, ������ -1 ��ȯ
#include < windows.h > // system("pause"); ���
#include <ctime>        // ���� ��¥ ���

#include "Compare.h"

void videoFuc::readVideoFile () {                                                        // ������ ���α׷��� ������ȭ ��Ű�� �Լ�
#pragma warning(disable: 4996)                                                              // ���� ����
    ifstream video_f ("video.bat");

    videoData.reserve (videoData.size () + 1);
    videoData.clear ();

    string line;
    char temp[255];

    if (video_f.is_open ()) {                                                                 // ���� ���� Ȯ��
        for (int i = 0; !video_f.eof (); i++) {                                                // ���� ���� ������ȭ
            getline (video_f, line);                                                               // �� ���� ����
            if (line.length () > 5) {                                                        // ù��° ��ĭ ������

                strcpy (temp, line.c_str ());                                                // cŸ�� ���ڿ��� ��ȯ

                char* tok = strtok (temp, " ");                                              //�����ڴ� " "�Դϴ�.

                for (int i = 1; tok != NULL; i++) {
                    if (i % 9 == 0) {
                        vData.borrowAdress = stoi (tok);
                    }
                    else if (i % 8 == 0) {
                        vData.rentCount = stoi (tok);
                    }
                    else if (i % 7 == 0) {
                        vData.person = tok;
                    }
                    else if (i % 6 == 0) {
                        vData.nation = tok;
                    }
                    else if (i % 5 == 0) {
                        vData.ageLimit = tok;
                    }
                    else if (i % 4 == 0) {
                        vData.time = tok;
                    }
                    else if (i % 3 == 0) {
                        vData.genre = tok;
                    }
                    else if (i % 2 == 0) {
                        vData.director = tok;
                    }
                    else {
                        vData.title = tok;
                    }

                    tok = strtok (NULL, " ");
                    if (i == 9) { i = 1; }                                                          // i�� �ʱ�ȭ ���� ���� ���ڿ����� �ùٸ��� ���� ��
                }

                vData.videoAdress = i;
                videoData.push_back (vData);
            }
        }

        video_f.close ();
        sort (videoData.begin (), videoData.end (), titleCompare ());
        saveVideoFile ();
    }
    else {                                                                                  // ������ ������ �����ϰ� ����.
        cout << "������ �����ϴ�. �ٽ� �����մϴ�." << endl;
        ofstream video ("video.bat", ios::app);
        video.close ();
        system ("pause");                                                               // ������ �����ϴ� ���� �����ֱ� ���� ����
        return;
    }
}

void videoFuc::readUserFile () {
#pragma warning(disable: 4996)   
    ifstream user_f ("user.bat");

    userData.reserve (userData.size () + 1);
    userData.clear ();

    string line;
    char temp[1000];

    if (user_f.is_open ()) {
        for (int i = 0; !user_f.eof (); i++) {                                                // ����� ���� ������ȭ
            getline (user_f, line);                                                               // �� ���� ����
            if (line.length () > 5) {                                                        // ù��° ��ĭ ������

                strcpy (temp, line.c_str ());                                                // cŸ�� ���ڿ��� ��ȯ

                char* tok = strtok (temp, " ");                                              //�����ڴ� " "�Դϴ�.

                for (int i = 1; tok != NULL; i++) {
                    if (i % 9 == 0) {
                        uData.point = stoi (tok);                                           // stoi �� �Ű������� �ش� �ڷ������� ��ȯ
                    }
                    else if (i % 8 == 0) {
                        uData.fine = stoi (tok);
                    }
                    else if (i % 7 == 0) {
                        uData.returnDay = tok;
                    }
                    else if (i % 6 == 0) {
                        uData.borrowDay = tok;
                    }
                    else if (i % 5 == 0) {
                        uData.borrowVideo = tok;
                    }
                    else if (i % 4 == 0) {
                        uData.Pnum = tok;
                    }
                    else if (i % 3 == 0) {
                        uData.home = tok;
                    }
                    else if (i % 2 == 0) {
                        uData.age = stoi (tok);
                    }
                    else {
                        uData.name = tok;
                    }

                    tok = strtok (NULL, " ");
                    if (i == 9) { i = 1; }                                                          // i�� �ʱ�ȭ ���� ���� ���ڿ����� �ùٸ��� ���� ��
                }

                uData.userAdress = i;
                userData.push_back (uData);
            }
        }

        user_f.close ();
        sort (userData.begin (), userData.end (), nameCompare ());
        saveVideoFile ();
    }
    else {                                                                                  // ������ ������ �����ϰ� ����.
        cout << "������ �����ϴ�. �ٽ� �����մϴ�." << endl;
        ofstream user ("user.bat", ios::app);
        user.close ();
        system ("pause");                                                               // ������ �����ϴ� ���� �����ֱ� ���� ����
        return;
    }
}

void videoFuc::videoMenu () {
    system ("cls");
    int menu;

    cout << "������ � �޴��� �����Ͻðڽ��ϱ�?" << endl;
    cout << "1. ���� �߰�" << endl;
    cout << "2. ���� ����" << endl;
    cout << "3. ���� ���� ����" << endl;
    cout << "4. ���� �˻�" << endl;
    cout << "5. ���� ���� ���" << endl;
    cout << "0. ��������" << endl;
    cin >> menu;

    switch (menu) {
    case 0:
        return;
        break;

    case 1:
        inputVideo ();
        break;

    case 2:
        delVideo ();
        break;

    case 3:
        videoModify ();
        break;

    case 4:
        videoSearchEngine ();
        break;

    case 5:
        printVideo ();
        system ("pause");
        break;

    default:
        cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;        // ���� ���� �̻��Ѱ� �Է��ϸ� �ٽ� �ݺ�
        cin.clear ();                           // ������Ʈ �ʱ�ȭ
        cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
        system ("pause");
        break;
    }
}

void videoFuc::userMenu () {
    system ("cls");
    int menu;

    cout << "������ ������ � �޴��� �����Ͻðڽ��ϱ�?" << endl;
    cout << "1. ������ �߰�" << endl;
    cout << "2. ������ ����" << endl;
    cout << "3. ������ ���� ����" << endl;
    cout << "4. ������ �˻�" << endl;
    cout << "5. ������ ���� ���" << endl;
    cout << "0. ��������" << endl;
    cin >> menu;

    switch (menu) {
    case 0:
        return;
        break;

    case 1:
        inputUser ();
        break;

    case 2:
        delUser ();
        break;

    case 3:
        userModify ();
        break;

    case 4:
        userSearchEngine ();
        break;

    case 5:
        printUser ();
        system ("pause");
        break;

    default:
        cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;        // ���� ���� �̻��Ѱ� �Է��ϸ� �ٽ� �ݺ�
        cin.clear ();                           // ������Ʈ �ʱ�ȭ
        cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
        system ("pause");
        break;
    }
}

void videoFuc::inputVideo () {
    system ("cls");

    ofstream video;
    video.open ("video.bat", ios::app);
    int count = 0, check = 0;

    cout << "�߰��� �׸��� �Է����ּ���. " << endl;
    cout << "\t (ex) ������_�� �˷�_���������� �ִϸ��̼� 73�� ALL ���þ�" << endl;
    cout << "\t \t ����� '_'�� ��ü, �ִ� 14����" << endl << endl;
    cout << "���� \t ���� \t �帣 \t ����Ÿ�� \t ��� \t ����" << endl;

    cin >> vData.title;            
    cin >> vData.director;
    cin >> vData.genre;
    cin >> vData.time;
    cin >> vData.ageLimit;
    cin >> vData.nation;

    check = lengthCheck (vData.title);          if (check == -1) { system ("pause"); return; }                             // �ѱ� 14���� �̻��̸� ��� ���߰� �Լ� ����
    check = lengthCheck (vData.director);       if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.genre);          if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.time);           if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.ageLimit);       if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.nation);         if (check == -1) { system ("pause"); return; }  

    vData.person = "����";
    vData.rentCount = 0;
    vData.borrowAdress = -1;

    video << "\n";
    video.write (vData.title.c_str (), vData.title.size ());
    video << " ";
    video.write (vData.director.c_str (), vData.director.size ());
    video << " ";
    video.write (vData.genre.c_str (), vData.genre.size ());
    video << " ";
    video.write (vData.time.c_str (), vData.time.size ());
    video << " ";
    video.write (vData.ageLimit.c_str (), vData.ageLimit.size ());
    video << " ";
    video.write (vData.nation.c_str (), vData.nation.size ());
    video << " ";
    video.write (vData.person.c_str (), vData.person.size ());
    video << " ";
    video << vData.rentCount;
    video << " ";
    video << vData.borrowAdress;

    //str.c_str() : C++ string -> const char* ���� ��ȯ���ִ� �Լ�

    video.close ();    //�� �ݾ��ֱ�

    cout << "����Ǿ����ϴ�." << endl;
    system ("pause");
}

void videoFuc::inputUser () {
    system ("cls");

    ofstream user;
    user.open ("user.bat", ios::app);
    int count = 0, check = 0;

    cout << "�߰��� �׸��� �Է����ּ���. " << endl;
    cout << "\t (ex) ������ 23 ��õ 010-3372-5014" << endl;
    cout << "\t \t ����� '_'�� ��ü, �ѱ� 14���� �̳�" << endl << endl;
    cout << "�̸� \t ���� \t ���ּ� \t ��ȣ" << endl;

    cin >> uData.name;
    cin >> uData.age;
    cin >> uData.home;
    cin >> uData.Pnum;

    uData.borrowVideo = "����";
    uData.borrowDay = "00.00.00";
    uData.returnDay = "00.00.00";
    uData.fine = 0;
    uData.point = 0;

    check = lengthCheck (uData.name);          if (check == -1) { system ("pause"); return; }                             // �ѱ� 14���� �̻��̸� ��� ���߰� �Լ� ����
    check = lengthCheck (uData.home);          if (check == -1) { system ("pause"); return; }
    check = lengthCheck (uData.Pnum);          if (check == -1) { system ("pause"); return; }

    user << "\n";
    user.write (uData.name.c_str (), uData.name.size ());
    user << " ";
    user << uData.age;
    user << " ";
    user.write (uData.home.c_str (), uData.home.size ());
    user << " ";
    user.write (uData.Pnum.c_str (), uData.Pnum.size ());
    user << " ";
    user.write (uData.borrowVideo.c_str (), uData.borrowVideo.size ());
    user << " ";
    user.write (uData.borrowDay.c_str (), uData.borrowDay.size ());
    user << " ";
    user.write (uData.returnDay.c_str (), uData.returnDay.size ());
    user << " ";
    user << uData.fine;
    user << " ";
    user << uData.point;

    //str.c_str() : C++ string -> const char* ���� ��ȯ���ִ� �Լ�

    user.close ();    //�� �ݾ��ֱ�

    cout << "����Ǿ����ϴ�." << endl;
    system ("pause");

}

void videoFuc::delVideo () {
    system ("cls");

    int eraseNum;
    ofstream video;

    videoSituation ();                                              // ������

    cout << endl << "���ǥ�� �� ��°�� �����Ͻðڽ��ϱ�? \t \t \t \t 0.��������" << endl;
    cin >> eraseNum;

    if (eraseNum == 0) {                                                                                                    // '0' �Է¹����� ����
        return;
    }

    if (videoData.size () >= eraseNum &&  eraseNum > 0) {
        video.open ("video.bat");
        for (int i = 0; i < videoData.size (); i++) {                                                                                 // ī���͸� ���� ������ �� -> ������ ������� ��
            if (i == eraseNum - 1) continue;

            video << "\n";
            video.write (videoData[i].title.c_str (), videoData[i].title.size ());
            video << " ";
            video.write (videoData[i].director.c_str (), videoData[i].director.size ());
            video << " ";
            video.write (videoData[i].genre.c_str (), videoData[i].genre.size ());
            video << " ";
            video.write (videoData[i].time.c_str (), videoData[i].time.size ());
            video << " ";
            video.write (videoData[i].ageLimit.c_str (), videoData[i].ageLimit.size ());
            video << " ";
            video.write (videoData[i].nation.c_str (), videoData[i].nation.size ());
            video << " ";
            video.write (videoData[i].person.c_str (), videoData[i].person.size ());
            video << " ";
            video << videoData[i].rentCount;
            video << " ";
            video << videoData[i].borrowAdress;
        }
        video.close ();
    }
    else {
        cout << "�ٽ� �Է��� �ּ���." << endl;
        system ("pause");
        video.close ();
        return;
    }

    cout << "�����Ǿ����ϴ�." << endl;
    system ("pause");
}

void videoFuc::delUser () {
    system ("cls");

    int eraseNum;
    ofstream user;

    userSituation ();                                              // ������

    cout << endl << "���ǥ�� �� ��°�� �����Ͻðڽ��ϱ�? \t \t \t \t 0.��������" << endl;
    cin >> eraseNum;

    if (eraseNum == 0) {                                                                                                    // '0' �Է¹����� ����
        return;
    }

    if (userData.size () >= eraseNum && eraseNum > 0) {
        user.open ("user.bat");
        for (int i = 0; i < userData.size (); i++) {                                                                                 // ī���͸� ���� ������ �� -> ������ ������� ��
            if (i == eraseNum - 1) continue;

            user << "\n";
            user.write (userData[i].name.c_str (), userData[i].name.size ());
            user << " ";
            user << userData[i].age;
            user << " ";
            user.write (userData[i].home.c_str (), userData[i].home.size ());
            user << " ";
            user.write (userData[i].Pnum.c_str (), userData[i].Pnum.size ());
            user << " ";
            user.write (userData[i].borrowVideo.c_str (), userData[i].borrowVideo.size ());
            user << " ";
            user.write (userData[i].borrowDay.c_str (), userData[i].borrowDay.size ());
            user << " ";
            user.write (userData[i].returnDay.c_str (), userData[i].returnDay.size ());
            user << " ";
            user << userData[i].fine;
            user << " ";
            user << userData[i].point;
        }

        user.close ();
    }
    else {
        user.close ();
        cout << "�ٽ� �Է��� �ּ���." << endl;
        system ("pause");
        return;
    }

    cout << "�����Ǿ����ϴ�." << endl;
    system ("pause");
}

void videoFuc::videoModify () {
    int mAdress = 0;
    string mtitle, mdirector, mgenre, mtime, mageLimit, mnation;

    printVideo ();

    cout << "������ ���ϴ� ���й�ȣ �Է��� �ּ���. \t \t \t \t 0. ��������" << endl;
    cin >> mAdress;
    cout << endl;

    if (mAdress == 0) { return; }                           // �������� �޴�
    else if (!(mAdress <= videoData.size ())) {             // ���� ũ�⺸�� �� ū ���� �Է� ��
        cout << "��ȿ�� ��ȣ�� �Է����ּ���." << endl;
        return;
    }
    else {
        cout << "������ ���ϴ� �κи� �Է��� �ּ���. ������ ������ ���� ���� '0'�� �Է����ּ���." << endl;
        cout << "\t \t \t \t \t �Ʒ� ���úκи� ������ �����մϴ�." << endl;
        cout << "(ex)   ����     ����    �帣  ����Ÿ�� ��� ����" << endl;
        cout << "     ��������  �̺���  �ڹ̵�  111:00   15  �ѱ�" << endl;
        cout << "                                                     '0 0 �׼� 0 0 0' �Է��ϸ�" << endl;
        cout << "     ��������  �̺���   �׼�   111:00   15  �ѱ�" << endl;
        cout << "                                                     ���� ������" << endl;
        cin >> mtitle >> mdirector >> mgenre >> mtime >> mageLimit >> mnation;

        if (mtitle.compare ("0")) { videoData[mAdress - 1].title = mtitle; }                        // '0' �Է��ϸ� ��������
        if (mdirector.compare ("0")) { videoData[mAdress - 1].director = mdirector;  }
        if (mgenre.compare ("0")) { videoData[mAdress - 1].genre = mgenre; }
        if (mtime.compare ("0")) { videoData[mAdress - 1].time = mtime; }
        if (mageLimit.compare ("0")) { videoData[mAdress - 1].ageLimit = mageLimit; }
        if (mnation.compare ("0")) { videoData[mAdress - 1].nation = mnation; }

        saveVideoFile ();
        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        system ("pause");
    }
}

void videoFuc::userModify () {
    int mAdress = 0;
    string mname, mhome, mPnum;
    int mage;

    printUser ();

    cout << "������ ���ϴ� ���й�ȣ �Է��� �ּ���. \t \t \t \t 0. ��������" << endl;
    cin >> mAdress;
    cout << endl;

    if (mAdress == 0) { return; }
    else if (!(mAdress <= userData.size ())) {              // ���� ũ�⺸�� �� ū ���� �Է� ��
        cout << "��ȿ�� ��ȣ�� �Է����ּ���." << endl;
        return;
    }
    else {
        cout << "������ ���ϴ� �κи� �Է��� �ּ���. ������ ������ ���� ���� '0'�� �Է����ּ���." << endl;
        cout << " \t \t \t \t \t �Ʒ� ���úκи� ������ �����մϴ�." << endl;
        cout << "(ex)   �̸�   ����   �ּ�     ��ȭ��ȣ " << endl;
        cout << "      ������   23    ��õ  010-1234-5678" << endl;
        cout << "                                            '0 0 ������ 0' �Է��ϸ�" << endl;
        cout << "      ������   23   ������ 010-1234-5678" << endl;
        cout << "                                            ���� ������" << endl;

        cin >> mname >> mage >> mhome >> mPnum;

        if (mname.compare ("0")) { userData[mAdress - 1].name = mname; }                        // '0' �Է��ϸ� ��������
        if (mage != 0) { userData[mAdress - 1].age = mage; }
        if (mhome.compare ("0")) { userData[mAdress - 1].home = mhome; }
        if (mPnum.compare ("0")) { userData[mAdress - 1].Pnum = mPnum; }

        saveUserFile ();
        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        system ("pause");
    }
}

void videoFuc::videoSearchEngine () {
    system ("cls");

    int choice;

    cout << "�˻� ���͸� �������ּ���." << endl;
    cout << "1. ���� ����" << endl;
    cout << "2. ���� ����" << endl;
    cout << "3. ���� �帣" << endl;
    cout << "4. ���� ��������" << endl;
    cout << "5. ���� ���۱���" << endl;
    cout << "0. ��������" << endl;
    cin >> choice;

    switch (choice) {
    case 0:
        return;
        break;

    case 1:
        videoTitleSearch ();
        break;

    case 2:
        videoDirectorSearch ();
        break;

    case 3:
        videoGenreSearch ();
        break;

    case 4:
        videoAgeLimitSearch ();
        break;

    case 5:
        videoNationSearch ();
        break;

    default:
        cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;        // ���� ���� �̻��Ѱ� �Է��ϸ� �ٽ� �ݺ�
        cin.clear ();                           // ������Ʈ �ʱ�ȭ
        cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
        system ("pause");
        break;
    }
}

void videoFuc::userSearchEngine () {
    system ("cls");

    int choice;

    cout << "�˻� ���͸� �������ּ���." << endl;
    cout << "1. ������ �̸�" << endl;
    cout << "2. ������ �ּ�" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        userNameSearch ();
        break;

    case 2:
        userHomeSearch ();
        break;

    default:
        cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;        // ���� ���� �̻��Ѱ� �Է��ϸ� �ٽ� �ݺ�
        cin.clear ();                           // ������Ʈ �ʱ�ȭ
        cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
        system ("pause");
        break;
    }
}

void videoFuc::videoTitleSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};                // check�� �ߺ����� �ϴ� �迭
    char str[50] = { NULL };
    string searchTitle, similarName[50], temp;

    cout << endl << "�˻��� ���� ����" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchTitle);

    if (searchTitle.length() > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    temp = searchTitle;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // ���ڿ� ���� ����
    searchTitle = replaceAll (searchTitle, " ", "_");                           // ���⸦ '_'�� �ٲ�

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;
    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (20); cout << "����";
    cout.width (20); cout << "�帣";
    cout.width (12); cout << "����Ÿ��";
    cout.width (8); cout << "���";
    cout.width (15); cout << "����";
    cout.width (20); cout << "������ ���";
    cout.width (12); cout << "���� Ƚ��" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {

        if (!videoData[i].title.compare (searchTitle)) {
            videoDetails (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (videoData[i].title.find (similarName[ii]) >= 0 && videoData[i].title.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::videoDirectorSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchDirector, similarName[50], temp;

    cout << endl << "�˻��� ���� �����̸�" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchDirector);

    if (searchDirector.length () > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    temp = searchDirector;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());                     // ���ڿ� ���� ����
    searchDirector = replaceAll (searchDirector, " ", "_");                           // ���⸦ '_'�� �ٲ�

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;
    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;
    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (20); cout << "����";
    cout.width (20); cout << "�帣";
    cout.width (12); cout << "����Ÿ��";
    cout.width (8); cout << "���";
    cout.width (15); cout << "����";
    cout.width (20); cout << "������ ���";
    cout.width (12); cout << "���� Ƚ��" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {

        if (!videoData[i].title.compare (searchDirector)) {
            videoDetails (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (videoData[i].director.find (similarName[ii]) >= 0 && videoData[i].director.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
}

    delete[] check;
    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::videoGenreSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchGenre, similarName[50];

    cout << endl << "�˻��� ���� �帣" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchGenre);

    if (searchGenre.length () > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    searchGenre.erase (remove (searchGenre.begin (), searchGenre.end (), ' '), searchGenre.end ());                     // ���ڿ� ���� ����

    for (int i = 0; i < searchGenre.length () / 2; i++) {
        similarName[i] = searchGenre.substr (count, 2);

        count = count + 2;
    }

    count = 0;
    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;
    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (20); cout << "����";
    cout.width (20); cout << "�帣";
    cout.width (12); cout << "����Ÿ��";
    cout.width (8); cout << "���";
    cout.width (15); cout << "����";
    cout.width (20); cout << "������ ���";
    cout.width (12); cout << "���� Ƚ��" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (!videoData[i].genre.compare(searchGenre)) {
            videoDetails (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < searchGenre.length () / 2; ii++) {
            if (videoData[i].genre.find (similarName[ii]) >= 0 && videoData[i].genre.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::videoAgeLimitSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchAgeLimit, similarName[50];

    cout << endl << "�˻��� ���� ���" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchAgeLimit);

    if (searchAgeLimit.length () > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    searchAgeLimit.erase (remove (searchAgeLimit.begin (), searchAgeLimit.end (), ' '), searchAgeLimit.end ());                     // ���ڿ� ���� ����

    for (int i = 0; i < searchAgeLimit.length () / 2; i++) {
        similarName[i] = searchAgeLimit.substr (count, 2);

        count = count + 2;
    }

    count = 0;
    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;
    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (20); cout << "����";
    cout.width (20); cout << "�帣";
    cout.width (12); cout << "����Ÿ��";
    cout.width (8); cout << "���";
    cout.width (15); cout << "����";
    cout.width (20); cout << "������ ���";
    cout.width (12); cout << "���� Ƚ��" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (!videoData[i].ageLimit.compare (searchAgeLimit)) {
            videoDetails (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < searchAgeLimit.length () / 2; ii++) {
            if (videoData[i].ageLimit.find (similarName[ii]) >= 0 && videoData[i].ageLimit.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::videoNationSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchNation, similarName[50], temp;

    cout << endl << "�˻��� ���� ���� ����" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchNation);

    if (searchNation.length () > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    temp = searchNation;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // ���ڿ� ���� ����
    searchNation = replaceAll (searchNation, " ", "_");                           // ���⸦ '_'�� �ٲ�

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;
    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (20); cout << "����";
    cout.width (20); cout << "�帣";
    cout.width (12); cout << "����Ÿ��";
    cout.width (8); cout << "���";
    cout.width (15); cout << "����";
    cout.width (20); cout << "������ ���";
    cout.width (12); cout << "���� Ƚ��" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {

        if (!videoData[i].nation.compare (searchNation)) {
            videoDetails (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (videoData[i].nation.find (similarName[ii]) >= 0 && videoData[i].nation.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::userNameSearch () {
    system ("cls");

    int count = 0, * check = new int[userData.size ()]{-1};
    char str[50] = {NULL};
    string searchName, similarName[50], temp;

    cout << endl << "�˻��� ������ �̸�" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchName);

    if (searchName.length () > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    temp = searchName;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // ���ڿ� ���� ����
    searchName = replaceAll (searchName, " ", "_");                           // ���⸦ '_'�� �ٲ�

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout.width (8); cout << "����";
    cout.width (12); cout << "�̸�";
    cout.width (8); cout << "����";
    cout.width (30); cout << "���� ����";
    cout.width (12); cout << "�ݳ� ��¥";
    cout.width (12); cout << "��ü��";
    cout.width (12); cout << "����Ʈ" << endl << endl;

    for (int i = 0; i < userData.size (); i++) {

        if (!userData[i].name.compare (searchName)) {
            userProportion (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < userData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (userData[i].name.find (similarName[ii]) >= 0 && userData[i].name.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            userProportion (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::userHomeSearch () {
    system ("cls");

    int count = 0, * check = new int[userData.size ()]{-1};
    char str[50] = {NULL};
    string searchHome, similarName[50], temp;

    cout << endl << "�˻��� ������ �̸�" << endl;
    cout << "'_' ��� ����, 14�� ����" << endl;
    cin.clear ();                           // ������Ʈ �ʱ�ȭ
    cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
    getline (cin, searchHome);

    if (searchHome.length () > 30) {
        cout << "�ʹ� ��ϴ�." << endl;
        system ("pause");
        return;
    }

    temp = searchHome;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // ���ڿ� ���� ����
    searchHome = replaceAll (searchHome, " ", "_");                           // ���⸦ '_'�� �ٲ�

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout.width (8); cout << "����";
    cout.width (12); cout << "�̸�";
    cout.width (8); cout << "����";
    cout.width (30); cout << "���� ����";
    cout.width (12); cout << "�ݳ� ��¥";
    cout.width (12); cout << "��ü��";
    cout.width (12); cout << "����Ʈ" << endl << endl;

    for (int i = 0; i < userData.size (); i++) {

        if (!userData[i].home.compare (searchHome)) {
            userProportion (i);
            check[i] = i;                                               // �迭�� ����
        }
    }

    cout << endl;

    for (int i = 0; i < userData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (userData[i].home.find (similarName[ii]) >= 0 && userData[i].home.find (similarName[ii]) < 30) { count++; }  // string �Լ� �� find�� string �ȿ� �ش� ���ڰ� �����ϸ� 0 ��ȯ, 30���� ������ ��������
        }

        if (count > 0) {
            userProportion (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "�˻� �Ϸ�." << endl;
    system ("pause");
}

void videoFuc::Borrow_And_Details () {
    system ("cls");

    videoSituation ();
    int num, choice;

    cout << "���ϴ� ��� ��ȣ�� �Է����ּ���." << endl;
    cin >> num;

    if (num <= videoData.size () && num > 0) {                               // ���� ����� 1������ �����ϹǷ� 0 �̻� size �̸�
        cout << "1. �ش� ���� ������" << endl;
        cout << "2. �ش� ���� �뿩" << endl;
        cout << "3. ���� �ݳ�" << endl;
        cout << "0. ��������" << endl;
        cin >> choice;

        switch (choice) {
        case 0:
            return;
            break;

        case 1:
            cout << endl << endl;
            cout << "\t \t \t ���" << endl << endl;

            cout.width (8); cout << "����";
            cout.width (30); cout << "����";
            cout.width (20); cout << "����";
            cout.width (20); cout << "�帣";
            cout.width (12); cout << "����Ÿ��";
            cout.width (8); cout << "���";
            cout.width (15); cout << "����";
            cout.width (20); cout << "������ ���";
            cout.width (12); cout << "���� Ƚ��" << endl << endl;
            videoDetails (num - 1);
            system ("pause");
            break;

        case 2:
            if (videoData[num - 1].borrowAdress <= 0) { borrowVideo (num); }
            else {
                cout << "�̹� �뿩�� ���� �Դϴ�." << endl;
                system ("pause");
                return;
            }
            break;

        case 3:
            returnVideo (num);
            break;

        default:
            cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;        // ���� ���� �̻��Ѱ� �Է��ϸ� �ٽ� �ݺ�
            cin.clear ();                           // ������Ʈ �ʱ�ȭ
            cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
            system ("pause");
            break;
        }
    }
    else {
        cout << "�߸��Է��ϼ̽��ϴ�." << endl;
        system ("pause");
        cin.clear ();                           // ������Ʈ �ʱ�ȭ
        cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
        return;
    }

   
}

void videoFuc::borrowVideo (int num) {                                                          // ���� ������ �ý��� 
    system ("cls");

    string bname;
    int count = 0, choice, vadress, choice1;

    cout << "������ ������ ����� �̸��� �Է����ּ���." << endl;
    cin >> bname;

    for (int i = 0; i < userData.size (); i++) {
        if (bname == userData[i].name) {                                                // �̸��� ������ �Ǵ�
            userProportion (i);                                                         // ���� �̸� ���
            count++;                                                                    // �ߺ��� ���� üũ
            vadress = i;                                                                // �ش� �ּ� ����

        }
    }

    if (count > 1) {                                                                // count�� 1���� ũ�� �ߺ��� ����
        cout << endl << "�ߺ��� �̸��� �ֽ��ϴ�. �����Դϱ�?" << endl;
        cout << "�ش��ϴ� ����� ���й�ȣ�� �Է����ּ���." << endl;
        cin >> choice;

        if (userData[choice - 1].borrowVideo.compare ("����")) {
            cout << "�̹� �뿩�� ������ �ֽ��ϴ�." << endl;
            system ("pause");
            return;
        }
        
        if (!videoData[num - 1].ageLimit.compare ("ALL") || userData[choice - 1].age >= stoi (videoData[num - 1].ageLimit)) {                                           // ���������� 'ALL'�̰ų� ����� ������ �� ũ�� �뿩 ����
            videoData[num - 1].borrowAdress = choice - 1;
            videoData[num - 1].person = userData[choice - 1].name;
            userData[choice - 1].borrowDay = to_string (curr_year) + "." + to_string (curr_month) + "." + to_string (curr_day);

            t.tm_mday += 7;                                                                                                                                                     // �ݳ��Ⱓ�� ������
            mktime (&t);                                                                                                                                                        // ��¥ ����

            if (curr_month < 10) {                                                                                                                                              //  �׳� �ϸ� '9'�� �Է�, '09'�� �Է½�Ŵ
                to_string (curr_month) = "0" + to_string (curr_month);
            }

            if (curr_day < 10) {
                to_string (curr_day) = "0" + to_string (curr_day);
            }

            userData[choice - 1].returnDay = to_string (t.tm_year - 100) + "." + to_string (t.tm_mon + 1) + "." + to_string (t.tm_mday);                            // to_string �� �ڷ�����  string ���� �ٲپ���
            userData[choice - 1].point += 10;
            userData[choice - 1].borrowVideo = videoData[num - 1].title;

            if (userData[choice - 1].point >= 200) {                                                // ����Ʈ �Ҹ�
                cout << "200 ����Ʈ�� �Ҹ��ϰ� ����� �뿩�Ͻðڽ��ϱ�?" << endl;
                cout << "\t \t \t ���� ����Ʈ : " << userData[choice - 1].point << endl;
                cout << "1. ����Ʈ ���" << endl;
                cout << "2. ��� ����" << endl;
                cin >> choice1;

                if (choice1 == 1) {
                    userData[choice - 1].point -= 200;
                    cout << "�ܿ� ����Ʈ : " << userData[choice - 1].point << endl;

                    saveVideoFile ();                                                                       // ���� ����
                    saveUserFile ();

                    cout << endl << "�뿩�� �Ϸ�Ǿ����ϴ�." << endl;
                    system ("pause");
                    return;
                }
                else {
                    saveVideoFile ();                                                                       // ���� ����
                    saveUserFile ();

                    cout << endl << "�뿩�� �Ϸ�Ǿ����ϴ�." << endl;
                    system ("pause");
                    return;
                }
            }
            else {
                saveVideoFile ();                                                                       // ���� ����
                saveUserFile ();

                cout << endl << "�뿩�� �Ϸ�Ǿ����ϴ�." << endl;
                system ("pause");
            }
        }
        else {                                                                                                                                                        // ����� ������ ������ �뿩 �Ұ�
            cout << "���������� �ֽ��ϴ�. " << videoData[num - 1].ageLimit << "��" << endl;
            system ("pause");
            return;
        }   
    }
    else if (count == 1) {                                                      // count�� 1�̸� �ߺ������ϱ� �ٷ� ����, �ߺ��� ������ ��µ� ���� �ּҷ� ����
        if (userData[vadress].borrowVideo.compare ("����")) {
            cout << "�̹� �뿩�� ������ �ֽ��ϴ�." << endl;
            system ("pause");
            return;
        }

        if (!videoData[num - 1].ageLimit.compare ("ALL") || userData[vadress].age >= stoi (videoData[num - 1].ageLimit)) {
            videoData[num - 1].borrowAdress = vadress;
            videoData[num - 1].person = userData[vadress].name;
            videoData[num - 1].rentCount += 1;

            t.tm_mday += 7;                                                                                                                                                     // �ݳ��Ⱓ�� ������
            mktime (&t);                                                                                                                                                        // ��¥ ����

            if (curr_month < 10) {                                                                                                                                              //  �׳� �ϸ� '9'�� �Է�, '09'�� �Է½�Ŵ
                to_string (curr_month) = "0" + to_string (curr_month);
            }

            if (curr_day < 10) {
                to_string (curr_day) = "0" + to_string (curr_day);
            }

            userData[vadress].borrowDay = to_string (curr_year) + "." + to_string (curr_month) + "." + to_string (curr_day);
            userData[vadress].returnDay = to_string (t.tm_year - 100) + "." + to_string (t.tm_mon + 1) + "." + to_string (t.tm_mday);
            userData[vadress].point += 10;
            userData[vadress].borrowVideo = videoData[num - 1].title;

            if (userData[vadress].point >= 200) {
                cout << endl << endl <<  "200 ����Ʈ�� �Ҹ��ϰ� ����� �뿩�Ͻðڽ��ϱ�?" << endl;
                cout << "\t \t \t ���� ����Ʈ : " << userData[vadress].point << endl;
                cout << "1. ����Ʈ ���" << endl;
                cout << "2. ��� ����" << endl;
                cin >> choice;

                if (choice == 1) {
                    userData[vadress].point = userData[vadress].point - 200;
                    cout << "�ܿ� ����Ʈ : " << userData[vadress].point << endl;

                    saveVideoFile ();                                                                       // ���� ����
                    saveUserFile ();

                    cout << endl << "�뿩�� �Ϸ�Ǿ����ϴ�." << endl;
                    system ("pause");
                    return;
                }
                else {
                    saveVideoFile ();                                                                       // ���� ����
                    saveUserFile ();

                    cout << endl << "�뿩�� �Ϸ�Ǿ����ϴ�." << endl;
                    system ("pause");
                    return;
                }
            }
            else {
                saveVideoFile ();                                                                       // ���� ����
                saveUserFile ();

                cout << endl << "�뿩�� �Ϸ�Ǿ����ϴ�." << endl;
                system ("pause");
            }
        }
        else {
            cout << endl << "���������� �ֽ��ϴ�. " << stoi (videoData[num - 1].ageLimit) << "��" << endl;
            system ("pause");
            return;
        }
    }
    else {                                                                     // �̻��Ѱ� �Է��ϸ� �Լ� ����        
        cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;
        system ("pause");
        return;
    } 
}

void videoFuc::returnVideo (int num) {                                      // ���� ������ [ ���� �����Ϳ� �����ص� ���� ������ �ּ� ].������ ����
    if (!videoData[num - 1].person.compare("����")) {                             // ������� ������ �Լ�����
        system ("cls");

        cout << "�뿩���� ���� �����Դϴ�." << endl;
        system ("pause");
        return;
    }
    else {
        if (userData[videoData[num - 1].borrowAdress].fine > 0) {                       // ��ü�� ���
            cout << "��ü��� " << userData[videoData[num - 1].borrowAdress].fine << "�Դϴ�." << endl;
            system ("pause");
        }

        userData[videoData[num - 1].borrowAdress].borrowDay = "00.00.00";
        userData[videoData[num - 1].borrowAdress].returnDay = "00.00.00";
        userData[videoData[num - 1].borrowAdress].borrowVideo = "����";
        userData[videoData[num - 1].borrowAdress].fine = 0;

        videoData[num - 1].borrowAdress = -1;
        videoData[num - 1].person = "����";

        saveVideoFile ();                                                                       // ���� ����
        saveUserFile ();

        cout << endl << "�ݳ��� �Ϸ�Ǿ����ϴ�." << endl;
        system ("pause");
    }   
}

void videoFuc::saveVideoFile () {
    ofstream video;
    video.open ("video.bat");

    for (int i = 0; i < videoData.size (); i++) {
        video << "\n";
        video.write (videoData[i].title.c_str (), videoData[i].title.size ());
        video << " ";
        video.write (videoData[i].director.c_str (), videoData[i].director.size ());
        video << " ";
        video.write (videoData[i].genre.c_str (), videoData[i].genre.size ());
        video << " ";
        video.write (videoData[i].time.c_str (), videoData[i].time.size ());
        video << " ";
        video.write (videoData[i].ageLimit.c_str (), videoData[i].ageLimit.size ());
        video << " ";
        video.write (videoData[i].nation.c_str (), videoData[i].nation.size ());
        video << " ";
        video.write (videoData[i].person.c_str (), videoData[i].person.size ());
        video << " ";
        video << videoData[i].rentCount;
        video << " ";
        video << videoData[i].borrowAdress;
    }

    video.close ();
}

void videoFuc::saveUserFile () {
    ofstream user;
    user.open ("user.bat");

    for (int i = 0; i < userData.size (); i++) {
        user << "\n";
        user.write (userData[i].name.c_str (), userData[i].name.size ());
        user << " ";
        user << userData[i].age;
        user << " ";
        user.write (userData[i].home.c_str (), userData[i].home.size ());
        user << " ";
        user.write (userData[i].Pnum.c_str (), userData[i].Pnum.size ());
        user << " ";
        user.write (userData[i].borrowVideo.c_str (), userData[i].borrowVideo.size ());
        user << " ";
        user.write (userData[i].borrowDay.c_str (), userData[i].borrowDay.size ());
        user << " ";
        user.write (userData[i].returnDay.c_str (), userData[i].returnDay.size ());
        user << " ";
        user << userData[i].fine;
        user << " ";
        user << userData[i].point;
    }

    user.close ();
}

void videoFuc::fineResult () {
    int* array = new int[5];
    string present = to_string (curr_year) + "." + to_string (curr_month) + "." + to_string (curr_day);

    for (int i = 0; i < userData.size (); i++) {
        if (userData[i].returnDay.compare("00.00.00")) {                                                                 // �ݳ���¥�� 00.00.00, �� �ʱⰪ�̸� ����
            array = new int[i + 1];                                                                              // ��ü�ᰪ�� �����ϴ� �����迭 �Ҵ�

            array[i] = fineCalculation (i);

            if (array[i] > 0) {                                                                                           // ��ü�ᰡ 0���� ũ�� ���
                userData[i].fine = array[i] * 100;
            }
        }       
    }

    delete[] array;
    saveUserFile ();
}

int videoFuc::fineCalculation (int num) {
    int difference;
    double result;
    char temp[1000];
    int year, month, day;

    strcpy (temp, userData[num].returnDay.c_str ());                                                // cŸ�� ���ڿ��� ��ȯ

    char* tok = strtok (temp, ".");                                              //�����ڴ� "."�Դϴ�.

    for (int i = 1; tok != NULL; i++) {                                 // ����Ǿ� �ִ� �ݳ���¥ �ð��� ��, ��, �� �� ����
        if (i % 3 == 0) {
            day = stoi (tok);
        }
        else if (i % 2 == 0) {
            month = stoi (tok);
        }
        else {
            year = stoi (tok);
        }

        tok = strtok (NULL, ".");
    }

    past.tm_year = year + 100;                                  // ���� ������ 100�� �� ���̶� �ٽ� ������
    past.tm_mon = month - 1;
    past.tm_mday = day;
    past.tm_hour = 0;
    past.tm_min = 0;
    past.tm_sec = 0;
    past.tm_isdst = 0;

    reDay = mktime (&past);

    result = difftime (now, reDay);                             // �� �ð����̸� �ʴ����� �������
    result = result / (60 * 60 * 24);                           // �ʴ����� ����� ���� *60(��) *60(��) *24(��)

    return result;
}

void videoFuc::showAlignment () {
    system ("cls");

    int choice;

    cout << "���ϴ� ���ĺ��� �޴��� �������ּ���." << endl;
    cout << "1. ���� ���� ���� (�⺻����)" << endl;
    cout << "2. ���� ���� ����" << endl;
    cout << "3. ���� �帣 ����" << endl;
    cout << "4. ���� ����Ÿ�� ����" << endl;
    cout << "5. ���� �������� ����" << endl;
    cout << "6. ���� ���� ���� ����" << endl;
    cout << "7. ���� ���� ��� ����" << endl;
    cout << "8. ���� �α� ����" << endl << endl;

    cout << "9. ������ �̸� ���� (�⺻����)" << endl;
    cout << "10. ������ �ּ� ����" << endl;
    cout << "11. ������ �뿩 ���� ����" << endl;
    cout << "12. ������ ���� ��¥ ����" << endl;
    cout << "13. ������ �ݳ���¥ ����" << endl;
    cout << "14. ������ ���� ����" << endl;
    cout << "15. ������ ����Ʈ ����" << endl;
    cout << "16. ������ ��ü�� ���� (���θ޴��� ����)" << endl;
    cout << "0. ��������" << endl;
    cin >> choice;

    system ("cls");

    switch (choice) {
    case 0:
        return;
        break;

    case 1:
        sort (videoData.begin (), videoData.end (), titleCompare ());
        printVideo ();
        system ("pause");
        break;

    case 2:
        sort (videoData.begin (), videoData.end (), directorCompare ());
        printVideo ();
        system ("pause");
        break;

    case 3:
        sort (videoData.begin (), videoData.end (), genreCompare ());
        userSituation ();
        system ("pause");
        break;

    case 4:
        sort (videoData.begin (), videoData.end (), timeCompare ());
        printVideo ();
        system ("pause");
        break;

    case 5:
        sort (videoData.begin (), videoData.end (), ageLimitCompare ());
        printVideo ();
        system ("pause");
        break;

    case 6:
        sort (videoData.begin (), videoData.end (), nationCompare ());
        printVideo ();
        system ("pause");
        break;

    case 7:
        sort (videoData.begin (), videoData.end (), personCompare ());
        printVideo ();
        system ("pause");
        break;

    case 8:
        sort (videoData.begin (), videoData.end (), rentCountCompare ());
        printVideo ();
        system ("pause");
        break;

    case 9:
        sort (userData.begin (), userData.end (), nameCompare ());
        printVideo ();
        system ("pause");
        break;

    case 10:
        sort (userData.begin (), userData.end (), homeCompare ());
        printUser ();
        system ("pause");
        break;

    case 11:
        sort (userData.begin (), userData.end (), borrowVideoCompare ());
        userSituation ();
        system ("pause");
        break;

    case 12:
        sort (userData.begin (), userData.end (), borrowDayCompare ());
        printUser ();
        system ("pause");
        break;

    case 13:
        sort (userData.begin (), userData.end (), returnDayCompare ());
        userSituation ();
        system ("pause");
        break;

    case 14:
        sort (userData.begin (), userData.end (), ageCompare ());
        userSituation ();
        system ("pause");
        break;

    case 15:
        sort (userData.begin (), userData.end (), pointCompare ());
        userSituation ();
        system ("pause");
        break;

    case 16:
        sort (userData.begin (), userData.end (), fineCompare ());
        userSituation ();
        system ("pause");
        break;

    default:
        cout << "�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���." << endl;        // ���� ���� �̻��Ѱ� �Է��ϸ� �ٽ� �ݺ�
        cin.clear ();                           // ������Ʈ �ʱ�ȭ
        cin.ignore (1000, '\n');                // ���� 1000�� Ȥ�� '\n'�� �а� �����ϴ�.(�Է� ���� �ʱ�ȭ)
        system ("pause");
        break;
    }
}

void videoFuc::videoSituation () {                                                              // ���� ��Ȳ�� �߿��� �κи� �߷� ���
    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;

    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (8); cout << "���";
    cout.width (30); cout << "������ ���" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {
        cout.width (8); cout << videoData[i].videoAdress;
        cout.width (30); cout << videoData[i].title;
        cout.width (8); cout << videoData[i].ageLimit;
        cout.width (30); cout << videoData[i].person;
        cout << endl;
    }
}

void videoFuc::videoDetails (int num) {                                                                              // ���� ��Ȳ ������ ���   
    if (num < videoData.size ()) {
        cout.width (8); cout << videoData[num].videoAdress;
        cout.width (30); cout << videoData[num].title;
        cout.width (20); cout << videoData[num].director;
        cout.width (20); cout << videoData[num].genre;
        cout.width (12); cout << videoData[num].time;
        cout.width (8); cout << videoData[num].ageLimit;
        cout.width (15); cout << videoData[num].nation;
        cout.width (20); cout << videoData[num].person;
        cout.width (12); cout << videoData[num].rentCount;
        cout << endl;
    }
    else {
        cout << "�ٽ� �Է����ּ���." << endl;
        return;
    }
}                                                                   

void videoFuc::printVideo () {                                                                              // ���� ��Ȳ ������ ���
    system ("cls");

    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;

    cout.width (8); cout << "����";
    cout.width (30); cout << "����";
    cout.width (20); cout << "����";
    cout.width (20); cout << "�帣";
    cout.width (12); cout << "����Ÿ��";
    cout.width (8); cout << "���";
    cout.width (15); cout << "����";
    cout.width (20); cout << "������ ���";
    cout.width (12); cout << "���� Ƚ��" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {                                                 
        cout.width (8); cout << videoData[i].videoAdress;
        cout.width (30); cout << videoData[i].title;
        cout.width (20); cout << videoData[i].director;
        cout.width (20); cout << videoData[i].genre;
        cout.width (12); cout << videoData[i].time;
        cout.width (8); cout << videoData[i].ageLimit;
        cout.width (15); cout << videoData[i].nation;
        cout.width (20); cout << videoData[i].person;
        cout.width (12); cout << videoData[i].rentCount;
        //cout.width (12); cout << videoData[i].borrowAdress;
        cout << endl;
    }
    cout << endl;
}                                                   

void videoFuc::userSituation () {                                                                              // ���� ��Ȳ �κ� ���
    system ("cls");

    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;

    cout.width (8); cout << "����";
    cout.width (12); cout << "�̸�";
    cout.width (8); cout << "����";
    cout.width (30); cout << "���� ����";
    cout.width (12); cout << "�ݳ� ��¥";
    cout.width (12); cout << "��ü��";
    cout.width (12); cout << "����Ʈ" << endl << endl;

    for (int i = 0; i < userData.size (); i++) {
        cout.width (8); cout << userData[i].userAdress;
        cout.width (12); cout << userData[i].name;
        cout.width (8); cout << userData[i].age;
        cout.width (30); cout << userData[i].borrowVideo;
        cout.width (12); cout << userData[i].returnDay;
        cout.width (12); cout << userData[i].fine;
        cout.width (12); cout << userData[i].point;
        cout << endl;
    }
}

void videoFuc::userProportion (int num) {                                                       // �ش� ���� ���
    if (num < userData.size ()) {
        cout.width (8); cout << userData[num].userAdress;
        cout.width (12); cout << userData[num].name;
        cout.width (8); cout << userData[num].age;
        cout.width (30); cout << userData[num].borrowVideo;
        cout.width (12); cout << userData[num].fine;
        cout.width (12); cout << userData[num].point;
        cout << endl;
    }
    else {
        cout << "�ٽ� �Է����ּ���." << endl;
        return;
    }

}

void videoFuc::printUser () {                                                                              // ���� ��Ȳ ������ ���
    system ("cls");

    cout << endl << endl;
    cout << "\t \t \t ���" << endl << endl;

    cout.width (8); cout << "����";
    cout.width (12); cout << "�̸�";
    cout.width (8); cout << "����";
    cout.width (30); cout << "�� �ּ�";
    cout.width (20); cout << "��ȭ��ȣ";
    cout.width (30); cout << "���� ����";
    cout.width (12); cout << "���� ��¥";
    cout.width (12); cout << "�ݳ� ��¥";
    cout.width (12); cout << "��ü��";
    cout.width (12); cout << "����Ʈ" << endl << endl;

    for (int i = 0; i < userData.size (); i++) {                                               
        cout.width (8); cout << userData[i].userAdress;
        cout.width (12); cout << userData[i].name;
        cout.width (8); cout << userData[i].age;
        cout.width (30); cout << userData[i].home;
        cout.width (20); cout << userData[i].Pnum;
        cout.width (30); cout << userData[i].borrowVideo;
        cout.width (12); cout << userData[i].borrowDay;
        cout.width (12); cout << userData[i].returnDay;
        cout.width (12); cout << userData[i].fine;
        cout.width (12); cout << userData[i].point;
        cout << endl;
    }      
    cout << endl;
}

int videoFuc::lengthCheck (string st) {
    if (st.length () > 28) {
        cout << "�ʹ� ��ϴ�." << endl;
        return -1;
    }
}

string videoFuc::replaceAll (const string& str, const string& pattern, const string& replace) {
    string result = str;
    string::size_type pos = 0;
    string::size_type offset = 0;

    while ((pos = result.find (pattern, offset)) != string::npos) {
        result.replace (result.begin () + pos, result.begin () + pos + pattern.size (), replace);
        offset = pos + replace.size ();
    }

    return result;
}