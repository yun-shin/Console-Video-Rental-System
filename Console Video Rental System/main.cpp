
#include <iostream>
#include <fstream>      // 파일 입출력
#include <vector>       // vector 사용
#include <algorithm>    // sort 사용

#include <string>       // string  함수이용 (stoi)
#include <cstring> // strtok 사용, stcmp는 두 문자열을 비교 아스키 상으로 크면 1, 같으면 0, 작으면 -1 반환
#include < windows.h > // system("pause"); 사용

#include "Compare.h"

// 비디오 검색, 대여된 목록, 대여가능한 비디오 목록, 가입자 정보 추가, 비디오 추가
//이름 나이 집주소 전화번호 빌려간비디오 빌린날짜 반납날짜 연체료 포인트

int main (void) {
    videoFuc v;
    int menu;

    while (true) {
        system ("cls");

        cout << "비디오 대여 프로그램" << endl;
        cout << "1. 비디오 메뉴" << endl;
        cout << "2. 가입자 메뉴" << endl;
        cout << "3. 비디오 세부사항 / 대여 / 반납" << endl;
        cout << "4. 연체료 내역" << endl;
        cout << "5. 정렬보기" << endl;

        cin >> menu;

        v.readVideoFile ();
        v.readUserFile ();
        v.fineResult ();

        switch (menu) {
        case 1:
            v.videoMenu ();
            break;

        case 2:
            v.userMenu ();
            break;

        case 3:
            v.Borrow_And_Details ();
            break;

        case 4:
            sort (v.userData.begin (), v.userData.end (), fineCompare ());
            v.userSituation ();
            system ("pause");
            break;

        case 5:
            v.showAlignment ();
            break;

        default:
            cout << "잘못입력하셨습니다. 다시 입력해주세요." << endl;        // 숫자 외의 이상한거 입력하면 다시 반복
            cin.clear ();                           // 에러비트 초기화
            cin.ignore (1000, '\n');                // 문자 1000개 혹은 '\n'을 읽고 버립니다.(입력 버퍼 초기화)
            system ("pause");
            break;
        }

    }
    return 0;
}

