
#include <iostream>
#include <fstream>      // 파일 입출력
#include <vector>       // vector 사용
#include <algorithm>    // sort 사용

#include <string>       // string  함수이용 (stoi)
#include <cstring> // strtok 사용, stcmp는 두 문자열을 비교 아스키 상으로 크면 1, 같으면 0, 작으면 -1 반환
#include < windows.h > // system("pause"); 사용
#include <ctime>        // 현재 날짜 사용

#include "Compare.h"

void videoFuc::readVideoFile () {                                                        // 파일을 프로그램의 데이터화 시키는 함수
#pragma warning(disable: 4996)                                                              // 오류 제거
    ifstream video_f ("video.bat");

    videoData.reserve (videoData.size () + 1);
    videoData.clear ();

    string line;
    char temp[255];

    if (video_f.is_open ()) {                                                                 // 파일 유무 확인
        for (int i = 0; !video_f.eof (); i++) {                                                // 비디오 정보 데이터화
            getline (video_f, line);                                                               // 한 줄을 받음
            if (line.length () > 5) {                                                        // 첫번째 빈칸 안읽음

                strcpy (temp, line.c_str ());                                                // c타입 문자열로 변환

                char* tok = strtok (temp, " ");                                              //구분자는 " "입니다.

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
                    if (i == 9) { i = 1; }                                                          // i를 초기화 시켜 나눈 문자열들이 올바르게 들어가게 함
                }

                vData.videoAdress = i;
                videoData.push_back (vData);
            }
        }

        video_f.close ();
        sort (videoData.begin (), videoData.end (), titleCompare ());
        saveVideoFile ();
    }
    else {                                                                                  // 파일이 없으면 생성하고 종료.
        cout << "파일이 없습니다. 다시 생성합니다." << endl;
        ofstream video ("video.bat", ios::app);
        video.close ();
        system ("pause");                                                               // 파일을 생산하는 것을 보여주기 위한 퍼즈
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
        for (int i = 0; !user_f.eof (); i++) {                                                // 사용자 정보 데이터화
            getline (user_f, line);                                                               // 한 줄을 받음
            if (line.length () > 5) {                                                        // 첫번째 빈칸 안읽음

                strcpy (temp, line.c_str ());                                                // c타입 문자열로 변환

                char* tok = strtok (temp, " ");                                              //구분자는 " "입니다.

                for (int i = 1; tok != NULL; i++) {
                    if (i % 9 == 0) {
                        uData.point = stoi (tok);                                           // stoi 는 매개변수를 해당 자료형으로 변환
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
                    if (i == 9) { i = 1; }                                                          // i를 초기화 시켜 나눈 문자열들이 올바르게 들어가게 함
                }

                uData.userAdress = i;
                userData.push_back (uData);
            }
        }

        user_f.close ();
        sort (userData.begin (), userData.end (), nameCompare ());
        saveVideoFile ();
    }
    else {                                                                                  // 파일이 없으면 생성하고 종료.
        cout << "파일이 없습니다. 다시 생성합니다." << endl;
        ofstream user ("user.bat", ios::app);
        user.close ();
        system ("pause");                                                               // 파일을 생산하는 것을 보여주기 위한 퍼즈
        return;
    }
}

void videoFuc::videoMenu () {
    system ("cls");
    int menu;

    cout << "비디오의 어떤 메뉴를 실행하시겠습니까?" << endl;
    cout << "1. 비디오 추가" << endl;
    cout << "2. 비디오 삭제" << endl;
    cout << "3. 비디오 정보 수정" << endl;
    cout << "4. 비디오 검색" << endl;
    cout << "5. 비디오 전문 출력" << endl;
    cout << "0. 이전으로" << endl;
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
        cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
        cin.clear ();                           // 에러비트 초기화
        cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
        system ("pause");
        break;
    }
}

void videoFuc::userMenu () {
    system ("cls");
    int menu;

    cout << "가입자 정보의 어떤 메뉴를 실행하시겠습니까?" << endl;
    cout << "1. 가입자 추가" << endl;
    cout << "2. 가입자 삭제" << endl;
    cout << "3. 가입자 정보 수정" << endl;
    cout << "4. 가입자 검색" << endl;
    cout << "5. 가입자 전문 출력" << endl;
    cout << "0. 이전으로" << endl;
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
        cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
        cin.clear ();                           // 에러비트 초기화
        cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
        system ("pause");
        break;
    }
}

void videoFuc::inputVideo () {
    system ("cls");

    ofstream video;
    video.open ("video.bat", ios::app);
    int count = 0, check = 0;

    cout << "추가할 항목을 입력해주세요. " << endl;
    cout << "\t (ex) 마샤와_곰 알레_쿠조브코프 애니메이션 73분 ALL 러시아" << endl;
    cout << "\t \t 띄어쓰기는 '_'로 대체, 최대 14글자" << endl << endl;
    cout << "제목 \t 감독 \t 장르 \t 러닝타임 \t 등급 \t 국가" << endl;

    cin >> vData.title;            
    cin >> vData.director;
    cin >> vData.genre;
    cin >> vData.time;
    cin >> vData.ageLimit;
    cin >> vData.nation;

    check = lengthCheck (vData.title);          if (check == -1) { system ("pause"); return; }                             // 한글 14글자 이상이면 잠시 멈추고 함수 종료
    check = lengthCheck (vData.director);       if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.genre);          if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.time);           if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.ageLimit);       if (check == -1) { system ("pause"); return; }
    check = lengthCheck (vData.nation);         if (check == -1) { system ("pause"); return; }  

    vData.person = "없음";
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

    //str.c_str() : C++ string -> const char* 으로 변환해주는 함수

    video.close ();    //꼭 닫아주기

    cout << "저장되었습니다." << endl;
    system ("pause");
}

void videoFuc::inputUser () {
    system ("cls");

    ofstream user;
    user.open ("user.bat", ios::app);
    int count = 0, check = 0;

    cout << "추가할 항목을 입력해주세요. " << endl;
    cout << "\t (ex) 신윤수 23 인천 010-3372-5014" << endl;
    cout << "\t \t 띄어쓰기는 '_'로 대체, 한글 14글자 이내" << endl << endl;
    cout << "이름 \t 나이 \t 집주소 \t 번호" << endl;

    cin >> uData.name;
    cin >> uData.age;
    cin >> uData.home;
    cin >> uData.Pnum;

    uData.borrowVideo = "없음";
    uData.borrowDay = "00.00.00";
    uData.returnDay = "00.00.00";
    uData.fine = 0;
    uData.point = 0;

    check = lengthCheck (uData.name);          if (check == -1) { system ("pause"); return; }                             // 한글 14글자 이상이면 잠시 멈추고 함수 종료
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

    //str.c_str() : C++ string -> const char* 으로 변환해주는 함수

    user.close ();    //꼭 닫아주기

    cout << "저장되었습니다." << endl;
    system ("pause");

}

void videoFuc::delVideo () {
    system ("cls");

    int eraseNum;
    ofstream video;

    videoSituation ();                                              // 목록출력

    cout << endl << "목록표의 몇 번째를 삭제하시겠습니까? \t \t \t \t 0.이전으로" << endl;
    cin >> eraseNum;

    if (eraseNum == 0) {                                                                                                    // '0' 입력받으면 종료
        return;
    }

    if (videoData.size () >= eraseNum &&  eraseNum > 0) {
        video.open ("video.bat");
        for (int i = 0; i < videoData.size (); i++) {                                                                                 // 카운터를 파일 끝으로 함 -> 벡터의 사이즈로 함
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
        cout << "다시 입력해 주세요." << endl;
        system ("pause");
        video.close ();
        return;
    }

    cout << "삭제되었습니다." << endl;
    system ("pause");
}

void videoFuc::delUser () {
    system ("cls");

    int eraseNum;
    ofstream user;

    userSituation ();                                              // 목록출력

    cout << endl << "목록표의 몇 번째를 삭제하시겠습니까? \t \t \t \t 0.이전으로" << endl;
    cin >> eraseNum;

    if (eraseNum == 0) {                                                                                                    // '0' 입력받으면 종료
        return;
    }

    if (userData.size () >= eraseNum && eraseNum > 0) {
        user.open ("user.bat");
        for (int i = 0; i < userData.size (); i++) {                                                                                 // 카운터를 파일 끝으로 함 -> 벡터의 사이즈로 함
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
        cout << "다시 입력해 주세요." << endl;
        system ("pause");
        return;
    }

    cout << "삭제되었습니다." << endl;
    system ("pause");
}

void videoFuc::videoModify () {
    int mAdress = 0;
    string mtitle, mdirector, mgenre, mtime, mageLimit, mnation;

    printVideo ();

    cout << "수정을 원하는 구분번호 입력해 주세요. \t \t \t \t 0. 이전으로" << endl;
    cin >> mAdress;
    cout << endl;

    if (mAdress == 0) { return; }                           // 이전으로 메뉴
    else if (!(mAdress <= videoData.size ())) {             // 벡터 크기보다 더 큰 숫자 입력 시
        cout << "유효한 번호를 입력해주세요." << endl;
        return;
    }
    else {
        cout << "수정을 원하는 부분만 입력해 주세요. 수정을 원하지 않은 곳은 '0'을 입력해주세요." << endl;
        cout << "\t \t \t \t \t 아래 예시부분만 수정이 가능합니다." << endl;
        cout << "(ex)   제목     감독    장르  러닝타임 등급 국가" << endl;
        cout << "     극한직업  이병헌  코미디  111:00   15  한국" << endl;
        cout << "                                                     '0 0 액션 0 0 0' 입력하면" << endl;
        cout << "     극한직업  이병헌   액션   111:00   15  한국" << endl;
        cout << "                                                     으로 수정됨" << endl;
        cin >> mtitle >> mdirector >> mgenre >> mtime >> mageLimit >> mnation;

        if (mtitle.compare ("0")) { videoData[mAdress - 1].title = mtitle; }                        // '0' 입력하면 수정안함
        if (mdirector.compare ("0")) { videoData[mAdress - 1].director = mdirector;  }
        if (mgenre.compare ("0")) { videoData[mAdress - 1].genre = mgenre; }
        if (mtime.compare ("0")) { videoData[mAdress - 1].time = mtime; }
        if (mageLimit.compare ("0")) { videoData[mAdress - 1].ageLimit = mageLimit; }
        if (mnation.compare ("0")) { videoData[mAdress - 1].nation = mnation; }

        saveVideoFile ();
        cout << "수정이 완료되었습니다." << endl;
        system ("pause");
    }
}

void videoFuc::userModify () {
    int mAdress = 0;
    string mname, mhome, mPnum;
    int mage;

    printUser ();

    cout << "수정을 원하는 구분번호 입력해 주세요. \t \t \t \t 0. 이전으로" << endl;
    cin >> mAdress;
    cout << endl;

    if (mAdress == 0) { return; }
    else if (!(mAdress <= userData.size ())) {              // 벡터 크기보다 더 큰 숫자 입력 시
        cout << "유효한 번호를 입력해주세요." << endl;
        return;
    }
    else {
        cout << "수정을 원하는 부분만 입력해 주세요. 수정을 원하지 않은 곳은 '0'을 입력해주세요." << endl;
        cout << " \t \t \t \t \t 아래 예시부분만 수정이 가능합니다." << endl;
        cout << "(ex)   이름   나이   주소     전화번호 " << endl;
        cout << "      신윤수   23    인천  010-1234-5678" << endl;
        cout << "                                            '0 0 강원도 0' 입력하면" << endl;
        cout << "      신윤수   23   강원도 010-1234-5678" << endl;
        cout << "                                            으로 수정됨" << endl;

        cin >> mname >> mage >> mhome >> mPnum;

        if (mname.compare ("0")) { userData[mAdress - 1].name = mname; }                        // '0' 입력하면 수정안함
        if (mage != 0) { userData[mAdress - 1].age = mage; }
        if (mhome.compare ("0")) { userData[mAdress - 1].home = mhome; }
        if (mPnum.compare ("0")) { userData[mAdress - 1].Pnum = mPnum; }

        saveUserFile ();
        cout << "수정이 완료되었습니다." << endl;
        system ("pause");
    }
}

void videoFuc::videoSearchEngine () {
    system ("cls");

    int choice;

    cout << "검색 필터를 설정해주세요." << endl;
    cout << "1. 비디오 제목" << endl;
    cout << "2. 비디오 감독" << endl;
    cout << "3. 비디오 장르" << endl;
    cout << "4. 비디오 연령제한" << endl;
    cout << "5. 비디오 제작국가" << endl;
    cout << "0. 이전으로" << endl;
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
        cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
        cin.clear ();                           // 에러비트 초기화
        cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
        system ("pause");
        break;
    }
}

void videoFuc::userSearchEngine () {
    system ("cls");

    int choice;

    cout << "검색 필터를 설정해주세요." << endl;
    cout << "1. 가입자 이름" << endl;
    cout << "2. 가입자 주소" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        userNameSearch ();
        break;

    case 2:
        userHomeSearch ();
        break;

    default:
        cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
        cin.clear ();                           // 에러비트 초기화
        cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
        system ("pause");
        break;
    }
}

void videoFuc::videoTitleSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};                // check은 중복제거 하는 배열
    char str[50] = { NULL };
    string searchTitle, similarName[50], temp;

    cout << endl << "검색할 비디오 제목" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchTitle);

    if (searchTitle.length() > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    temp = searchTitle;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // 문자열 공백 없엠
    searchTitle = replaceAll (searchTitle, " ", "_");                           // 띄어쓰기를 '_'로 바꿈

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (20); cout << "감독";
    cout.width (20); cout << "장르";
    cout.width (12); cout << "러닝타임";
    cout.width (8); cout << "등급";
    cout.width (15); cout << "국가";
    cout.width (20); cout << "빌려간 사람";
    cout.width (12); cout << "빌린 횟수" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {

        if (!videoData[i].title.compare (searchTitle)) {
            videoDetails (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (videoData[i].title.find (similarName[ii]) >= 0 && videoData[i].title.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::videoDirectorSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchDirector, similarName[50], temp;

    cout << endl << "검색할 비디오 감독이름" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchDirector);

    if (searchDirector.length () > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    temp = searchDirector;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());                     // 문자열 공백 없엠
    searchDirector = replaceAll (searchDirector, " ", "_");                           // 띄어쓰기를 '_'로 바꿈

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;
    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (20); cout << "감독";
    cout.width (20); cout << "장르";
    cout.width (12); cout << "러닝타임";
    cout.width (8); cout << "등급";
    cout.width (15); cout << "국가";
    cout.width (20); cout << "빌려간 사람";
    cout.width (12); cout << "빌린 횟수" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {

        if (!videoData[i].title.compare (searchDirector)) {
            videoDetails (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (videoData[i].director.find (similarName[ii]) >= 0 && videoData[i].director.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
}

    delete[] check;
    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::videoGenreSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchGenre, similarName[50];

    cout << endl << "검색할 비디오 장르" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchGenre);

    if (searchGenre.length () > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    searchGenre.erase (remove (searchGenre.begin (), searchGenre.end (), ' '), searchGenre.end ());                     // 문자열 공백 없엠

    for (int i = 0; i < searchGenre.length () / 2; i++) {
        similarName[i] = searchGenre.substr (count, 2);

        count = count + 2;
    }

    count = 0;
    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (20); cout << "감독";
    cout.width (20); cout << "장르";
    cout.width (12); cout << "러닝타임";
    cout.width (8); cout << "등급";
    cout.width (15); cout << "국가";
    cout.width (20); cout << "빌려간 사람";
    cout.width (12); cout << "빌린 횟수" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (!videoData[i].genre.compare(searchGenre)) {
            videoDetails (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < searchGenre.length () / 2; ii++) {
            if (videoData[i].genre.find (similarName[ii]) >= 0 && videoData[i].genre.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::videoAgeLimitSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchAgeLimit, similarName[50];

    cout << endl << "검색할 비디오 등급" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchAgeLimit);

    if (searchAgeLimit.length () > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    searchAgeLimit.erase (remove (searchAgeLimit.begin (), searchAgeLimit.end (), ' '), searchAgeLimit.end ());                     // 문자열 공백 없엠

    for (int i = 0; i < searchAgeLimit.length () / 2; i++) {
        similarName[i] = searchAgeLimit.substr (count, 2);

        count = count + 2;
    }

    count = 0;
    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (20); cout << "감독";
    cout.width (20); cout << "장르";
    cout.width (12); cout << "러닝타임";
    cout.width (8); cout << "등급";
    cout.width (15); cout << "국가";
    cout.width (20); cout << "빌려간 사람";
    cout.width (12); cout << "빌린 횟수" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (!videoData[i].ageLimit.compare (searchAgeLimit)) {
            videoDetails (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < searchAgeLimit.length () / 2; ii++) {
            if (videoData[i].ageLimit.find (similarName[ii]) >= 0 && videoData[i].ageLimit.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::videoNationSearch () {
    system ("cls");

    int count = 0, * check = new int[videoData.size ()]{-1};
    char str[50] = {NULL};
    string searchNation, similarName[50], temp;

    cout << endl << "검색할 비디오 제작 국가" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchNation);

    if (searchNation.length () > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    temp = searchNation;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // 문자열 공백 없엠
    searchNation = replaceAll (searchNation, " ", "_");                           // 띄어쓰기를 '_'로 바꿈

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (20); cout << "감독";
    cout.width (20); cout << "장르";
    cout.width (12); cout << "러닝타임";
    cout.width (8); cout << "등급";
    cout.width (15); cout << "국가";
    cout.width (20); cout << "빌려간 사람";
    cout.width (12); cout << "빌린 횟수" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {

        if (!videoData[i].nation.compare (searchNation)) {
            videoDetails (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < videoData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (videoData[i].nation.find (similarName[ii]) >= 0 && videoData[i].nation.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            videoDetails (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::userNameSearch () {
    system ("cls");

    int count = 0, * check = new int[userData.size ()]{-1};
    char str[50] = {NULL};
    string searchName, similarName[50], temp;

    cout << endl << "검색할 가입자 이름" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchName);

    if (searchName.length () > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    temp = searchName;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // 문자열 공백 없엠
    searchName = replaceAll (searchName, " ", "_");                           // 띄어쓰기를 '_'로 바꿈

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (12); cout << "이름";
    cout.width (8); cout << "나이";
    cout.width (30); cout << "빌린 비디오";
    cout.width (12); cout << "반납 날짜";
    cout.width (12); cout << "연체료";
    cout.width (12); cout << "포인트" << endl << endl;

    for (int i = 0; i < userData.size (); i++) {

        if (!userData[i].name.compare (searchName)) {
            userProportion (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < userData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (userData[i].name.find (similarName[ii]) >= 0 && userData[i].name.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            userProportion (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::userHomeSearch () {
    system ("cls");

    int count = 0, * check = new int[userData.size ()]{-1};
    char str[50] = {NULL};
    string searchHome, similarName[50], temp;

    cout << endl << "검색할 가입자 이름" << endl;
    cout << "'_' 사용 금지, 14자 내외" << endl;
    cin.clear ();                           // 에러비트 초기화
    cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
    getline (cin, searchHome);

    if (searchHome.length () > 30) {
        cout << "너무 깁니다." << endl;
        system ("pause");
        return;
    }

    temp = searchHome;
    temp.erase (remove (temp.begin (), temp.end (), ' '), temp.end ());              // 문자열 공백 없엠
    searchHome = replaceAll (searchHome, " ", "_");                           // 띄어쓰기를 '_'로 바꿈

    for (int i = 0; i < temp.length () / 2; i++) {
        similarName[i] = temp.substr (count, 2);

        count = count + 2;
    }

    count = 0;

    cout << endl << endl;
    cout.width (8); cout << "구분";
    cout.width (12); cout << "이름";
    cout.width (8); cout << "나이";
    cout.width (30); cout << "빌린 비디오";
    cout.width (12); cout << "반납 날짜";
    cout.width (12); cout << "연체료";
    cout.width (12); cout << "포인트" << endl << endl;

    for (int i = 0; i < userData.size (); i++) {

        if (!userData[i].home.compare (searchHome)) {
            userProportion (i);
            check[i] = i;                                               // 배열에 저장
        }
    }

    cout << endl;

    for (int i = 0; i < userData.size (); i++) {
        if (i == check[i]) { continue; }

        for (int ii = 0; ii < temp.length () / 2; ii++) {
            if (userData[i].home.find (similarName[ii]) >= 0 && userData[i].home.find (similarName[ii]) < 30) { count++; }  // string 함수 중 find는 string 안에 해당 글자가 존재하면 0 반환, 30보다 작은건 오류방지
        }

        if (count > 0) {
            userProportion (i);
            count = 0;
        }
    }

    delete[] check;
    cout << "검색 완료." << endl;
    system ("pause");
}

void videoFuc::Borrow_And_Details () {
    system ("cls");

    videoSituation ();
    int num, choice;

    cout << "원하는 목록 번호를 입력해주세요." << endl;
    cin >> num;

    if (num <= videoData.size () && num > 0) {                               // 비디오 목록이 1번부터 시작하므로 0 이상 size 미만
        cout << "1. 해당 비디오 상세정보" << endl;
        cout << "2. 해당 비디오 대여" << endl;
        cout << "3. 비디오 반납" << endl;
        cout << "0. 이전으로" << endl;
        cin >> choice;

        switch (choice) {
        case 0:
            return;
            break;

        case 1:
            cout << endl << endl;
            cout << "\t \t \t 목록" << endl << endl;

            cout.width (8); cout << "구분";
            cout.width (30); cout << "제목";
            cout.width (20); cout << "감독";
            cout.width (20); cout << "장르";
            cout.width (12); cout << "러닝타임";
            cout.width (8); cout << "등급";
            cout.width (15); cout << "국가";
            cout.width (20); cout << "빌려간 사람";
            cout.width (12); cout << "빌린 횟수" << endl << endl;
            videoDetails (num - 1);
            system ("pause");
            break;

        case 2:
            if (videoData[num - 1].borrowAdress <= 0) { borrowVideo (num); }
            else {
                cout << "이미 대여된 비디오 입니다." << endl;
                system ("pause");
                return;
            }
            break;

        case 3:
            returnVideo (num);
            break;

        default:
            cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
            cin.clear ();                           // 에러비트 초기화
            cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
            system ("pause");
            break;
        }
    }
    else {
        cout << "잘못입력하셨습니다." << endl;
        system ("pause");
        cin.clear ();                           // 에러비트 초기화
        cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
        return;
    }

   
}

void videoFuc::borrowVideo (int num) {                                                          // 비디오 빌리는 시스템 
    system ("cls");

    string bname;
    int count = 0, choice, vadress, choice1;

    cout << "비디오를 빌려갈 사람의 이름을 입력해주세요." << endl;
    cin >> bname;

    for (int i = 0; i < userData.size (); i++) {
        if (bname == userData[i].name) {                                                // 이름이 같은지 판단
            userProportion (i);                                                         // 같은 이름 출력
            count++;                                                                    // 중복된 개수 체크
            vadress = i;                                                                // 해당 주소 저장

        }
    }

    if (count > 1) {                                                                // count가 1보다 크면 중복이 존재
        cout << endl << "중복된 이름이 있습니다. 누구입니까?" << endl;
        cout << "해당하는 사람의 구분번호를 입력해주세요." << endl;
        cin >> choice;

        if (userData[choice - 1].borrowVideo.compare ("없음")) {
            cout << "이미 대여한 비디오가 있습니다." << endl;
            system ("pause");
            return;
        }
        
        if (!videoData[num - 1].ageLimit.compare ("ALL") || userData[choice - 1].age >= stoi (videoData[num - 1].ageLimit)) {                                           // 연령제한이 'ALL'이거나 사용자 연령이 더 크면 대여 가능
            videoData[num - 1].borrowAdress = choice - 1;
            videoData[num - 1].person = userData[choice - 1].name;
            userData[choice - 1].borrowDay = to_string (curr_year) + "." + to_string (curr_month) + "." + to_string (curr_day);

            t.tm_mday += 7;                                                                                                                                                     // 반납기간은 일주일
            mktime (&t);                                                                                                                                                        // 날짜 재계산

            if (curr_month < 10) {                                                                                                                                              //  그냥 하면 '9'가 입력, '09'로 입력시킴
                to_string (curr_month) = "0" + to_string (curr_month);
            }

            if (curr_day < 10) {
                to_string (curr_day) = "0" + to_string (curr_day);
            }

            userData[choice - 1].returnDay = to_string (t.tm_year - 100) + "." + to_string (t.tm_mon + 1) + "." + to_string (t.tm_mday);                            // to_string 은 자료형을  string 으로 바꾸어줌
            userData[choice - 1].point += 10;
            userData[choice - 1].borrowVideo = videoData[num - 1].title;

            if (userData[choice - 1].point >= 200) {                                                // 포인트 소모
                cout << "200 포인트를 소모하고 무료로 대여하시겠습니까?" << endl;
                cout << "\t \t \t 현재 포인트 : " << userData[choice - 1].point << endl;
                cout << "1. 포인트 사용" << endl;
                cout << "2. 사용 안함" << endl;
                cin >> choice1;

                if (choice1 == 1) {
                    userData[choice - 1].point -= 200;
                    cout << "잔여 포인트 : " << userData[choice - 1].point << endl;

                    saveVideoFile ();                                                                       // 파일 저장
                    saveUserFile ();

                    cout << endl << "대여가 완료되었습니다." << endl;
                    system ("pause");
                    return;
                }
                else {
                    saveVideoFile ();                                                                       // 파일 저장
                    saveUserFile ();

                    cout << endl << "대여가 완료되었습니다." << endl;
                    system ("pause");
                    return;
                }
            }
            else {
                saveVideoFile ();                                                                       // 파일 저장
                saveUserFile ();

                cout << endl << "대여가 완료되었습니다." << endl;
                system ("pause");
            }
        }
        else {                                                                                                                                                        // 사용자 연령이 작으면 대여 불가
            cout << "연령제한이 있습니다. " << videoData[num - 1].ageLimit << "세" << endl;
            system ("pause");
            return;
        }   
    }
    else if (count == 1) {                                                      // count가 1이면 중복없으니까 바로 저장, 중복이 없으니 출력된 유저 주소로 진행
        if (userData[vadress].borrowVideo.compare ("없음")) {
            cout << "이미 대여한 비디오가 있습니다." << endl;
            system ("pause");
            return;
        }

        if (!videoData[num - 1].ageLimit.compare ("ALL") || userData[vadress].age >= stoi (videoData[num - 1].ageLimit)) {
            videoData[num - 1].borrowAdress = vadress;
            videoData[num - 1].person = userData[vadress].name;
            videoData[num - 1].rentCount += 1;

            t.tm_mday += 7;                                                                                                                                                     // 반납기간은 일주일
            mktime (&t);                                                                                                                                                        // 날짜 재계산

            if (curr_month < 10) {                                                                                                                                              //  그냥 하면 '9'가 입력, '09'로 입력시킴
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
                cout << endl << endl <<  "200 포인트를 소모하고 무료로 대여하시겠습니까?" << endl;
                cout << "\t \t \t 현재 포인트 : " << userData[vadress].point << endl;
                cout << "1. 포인트 사용" << endl;
                cout << "2. 사용 안함" << endl;
                cin >> choice;

                if (choice == 1) {
                    userData[vadress].point = userData[vadress].point - 200;
                    cout << "잔여 포인트 : " << userData[vadress].point << endl;

                    saveVideoFile ();                                                                       // 파일 저장
                    saveUserFile ();

                    cout << endl << "대여가 완료되었습니다." << endl;
                    system ("pause");
                    return;
                }
                else {
                    saveVideoFile ();                                                                       // 파일 저장
                    saveUserFile ();

                    cout << endl << "대여가 완료되었습니다." << endl;
                    system ("pause");
                    return;
                }
            }
            else {
                saveVideoFile ();                                                                       // 파일 저장
                saveUserFile ();

                cout << endl << "대여가 완료되었습니다." << endl;
                system ("pause");
            }
        }
        else {
            cout << endl << "연령제한이 있습니다. " << stoi (videoData[num - 1].ageLimit) << "세" << endl;
            system ("pause");
            return;
        }
    }
    else {                                                                     // 이상한거 입력하면 함수 종료        
        cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;
        system ("pause");
        return;
    } 
}

void videoFuc::returnVideo (int num) {                                      // 유저 데이터 [ 비디오 데이터에 저장해둔 유저 데이터 주소 ].나머지 변수
    if (!videoData[num - 1].person.compare("없음")) {                             // 빌린사람 없으면 함수종료
        system ("cls");

        cout << "대여되지 않은 비디오입니다." << endl;
        system ("pause");
        return;
    }
    else {
        if (userData[videoData[num - 1].borrowAdress].fine > 0) {                       // 연체료 출력
            cout << "연체료는 " << userData[videoData[num - 1].borrowAdress].fine << "입니다." << endl;
            system ("pause");
        }

        userData[videoData[num - 1].borrowAdress].borrowDay = "00.00.00";
        userData[videoData[num - 1].borrowAdress].returnDay = "00.00.00";
        userData[videoData[num - 1].borrowAdress].borrowVideo = "없음";
        userData[videoData[num - 1].borrowAdress].fine = 0;

        videoData[num - 1].borrowAdress = -1;
        videoData[num - 1].person = "없음";

        saveVideoFile ();                                                                       // 파일 저장
        saveUserFile ();

        cout << endl << "반납이 완료되었습니다." << endl;
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
        if (userData[i].returnDay.compare("00.00.00")) {                                                                 // 반납날짜가 00.00.00, 즉 초기값이면 무시
            array = new int[i + 1];                                                                              // 연체료값을 저장하는 동적배열 할당

            array[i] = fineCalculation (i);

            if (array[i] > 0) {                                                                                           // 연체료가 0보다 크면 출력
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

    strcpy (temp, userData[num].returnDay.c_str ());                                                // c타입 문자열로 변환

    char* tok = strtok (temp, ".");                                              //구분자는 "."입니다.

    for (int i = 1; tok != NULL; i++) {                                 // 저장되어 있던 반납날짜 시간을 연, 달, 날 로 나눔
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

    past.tm_year = year + 100;                                  // 기존 값에서 100을 뺀 값이라서 다시 더해줌
    past.tm_mon = month - 1;
    past.tm_mday = day;
    past.tm_hour = 0;
    past.tm_min = 0;
    past.tm_sec = 0;
    past.tm_isdst = 0;

    reDay = mktime (&past);

    result = difftime (now, reDay);                             // 두 시간차이를 초단위로 계산해줌
    result = result / (60 * 60 * 24);                           // 초단위로 계산한 값을 *60(분) *60(시) *24(날)

    return result;
}

void videoFuc::showAlignment () {
    system ("cls");

    int choice;

    cout << "원하는 정렬보기 메뉴를 선택해주세요." << endl;
    cout << "1. 비디오 제목 정렬 (기본정렬)" << endl;
    cout << "2. 비디오 감독 정렬" << endl;
    cout << "3. 비디오 장르 정렬" << endl;
    cout << "4. 비디오 러닝타임 정렬" << endl;
    cout << "5. 비디오 연령제한 정렬" << endl;
    cout << "6. 비디오 제작 국가 정렬" << endl;
    cout << "7. 비디오 빌린 사람 정렬" << endl;
    cout << "8. 비디오 인기 정렬" << endl << endl;

    cout << "9. 가입자 이름 정렬 (기본정렬)" << endl;
    cout << "10. 가입자 주소 정렬" << endl;
    cout << "11. 가입자 대여 비디오 정렬" << endl;
    cout << "12. 가입자 빌린 날짜 정렬" << endl;
    cout << "13. 가입자 반납날짜 정렬" << endl;
    cout << "14. 가입자 나이 정렬" << endl;
    cout << "15. 가입자 포인트 정렬" << endl;
    cout << "16. 가입자 연체료 정렬 (메인메뉴와 같음)" << endl;
    cout << "0. 이전으로" << endl;
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
        cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
        cin.clear ();                           // 에러비트 초기화
        cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
        system ("pause");
        break;
    }
}

void videoFuc::videoSituation () {                                                              // 비디오 현황을 중요한 부분만 추려 출력
    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;

    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (8); cout << "등급";
    cout.width (30); cout << "빌려간 사람" << endl << endl;

    for (int i = 0; i < videoData.size (); i++) {
        cout.width (8); cout << videoData[i].videoAdress;
        cout.width (30); cout << videoData[i].title;
        cout.width (8); cout << videoData[i].ageLimit;
        cout.width (30); cout << videoData[i].person;
        cout << endl;
    }
}

void videoFuc::videoDetails (int num) {                                                                              // 비디오 현황 상세정보 출력   
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
        cout << "다시 입력해주세요." << endl;
        return;
    }
}                                                                   

void videoFuc::printVideo () {                                                                              // 비디오 현황 상세정보 출력
    system ("cls");

    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;

    cout.width (8); cout << "구분";
    cout.width (30); cout << "제목";
    cout.width (20); cout << "감독";
    cout.width (20); cout << "장르";
    cout.width (12); cout << "러닝타임";
    cout.width (8); cout << "등급";
    cout.width (15); cout << "국가";
    cout.width (20); cout << "빌려간 사람";
    cout.width (12); cout << "빌린 횟수" << endl << endl;

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

void videoFuc::userSituation () {                                                                              // 유저 현황 부분 출력
    system ("cls");

    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;

    cout.width (8); cout << "구분";
    cout.width (12); cout << "이름";
    cout.width (8); cout << "나이";
    cout.width (30); cout << "빌린 비디오";
    cout.width (12); cout << "반납 날짜";
    cout.width (12); cout << "연체료";
    cout.width (12); cout << "포인트" << endl << endl;

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

void videoFuc::userProportion (int num) {                                                       // 해당 유저 출력
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
        cout << "다시 입력해주세요." << endl;
        return;
    }

}

void videoFuc::printUser () {                                                                              // 유저 현황 상세정보 출력
    system ("cls");

    cout << endl << endl;
    cout << "\t \t \t 목록" << endl << endl;

    cout.width (8); cout << "구분";
    cout.width (12); cout << "이름";
    cout.width (8); cout << "나이";
    cout.width (30); cout << "집 주소";
    cout.width (20); cout << "전화번호";
    cout.width (30); cout << "빌린 비디오";
    cout.width (12); cout << "빌린 날짜";
    cout.width (12); cout << "반납 날짜";
    cout.width (12); cout << "연체료";
    cout.width (12); cout << "포인트" << endl << endl;

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
        cout << "너무 깁니다." << endl;
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