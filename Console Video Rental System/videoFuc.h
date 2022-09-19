#include <vector>
#include <ctime>        // 현재 날짜 사용

#include "info.h"


class videoFuc {
public:
    // 데이터화
    void readVideoFile ();              // 비디오 파일 데이터화
    void readUserFile ();               // 유저 파일 데이터화
    void saveVideoFile ();              // 비디오파일 저장
    void saveUserFile ();               // 유저파일 저장

    // 필수기능
    void inputVideo ();                 // 비디오 추가 함수
    void inputUser ();                  // 유저 추가 함수
    void delVideo ();                   // 비디오 삭제 함수
    void delUser ();                    // 유저 삭제 함수
    void videoModify ();                // 비디오 수정 함수
    void userModify ();                 // 유저 수정 함수
    void videoTitleSearch ();           // 비디오 제목 검색 함수
    void videoDirectorSearch ();        // 비디오 감독 검색 함수
    void videoGenreSearch ();           // 비디오 장르 검색 함수
    void videoAgeLimitSearch ();        // 비디오 연령제한 검색 함수
    void videoNationSearch ();          // 비디오 제작 국가 검색 함수
    void userNameSearch ();             // 유저 이름 검색 함수
    void userHomeSearch ();             // 유저 주소 검색함수
    void borrowVideo (int num);         // 비디오 대여 기능 함수
    void returnVideo (int num);         // 비디오 반납 기능 함수
    void fineResult ();                 // 연체료 계산 및 출력 함수
    int fineCalculation (int num);      // 연체 기간 계산 함수

    // 기능 모음
    void videoMenu ();                  // 비디오 관련 기능 모음
    void userMenu ();                   // 유저 관련 기능 모음
    void Borrow_And_Details ();         // 비디오 대여, 상세정보 기능 모음
    void videoSearchEngine ();          // 비디오 검색 기능 모음
    void userSearchEngine ();          // 유저 검색 기능 모음

    // 출력
    void videoSituation ();             // 비디오 부분 출력
    void printVideo ();                 // 비디오 전문 출력
    void videoDetails (int num);        // 해당 목록 세부사항 출력
    void userSituation ();              // 유저 부분 출력
    void printUser ();                  // 유저 전문 출력
    void userProportion (int num);      // 해당 유저 출력
    void showAlignment ();              // 정렬보기 함수


    // 예외처리
    int lengthCheck (string st);        // 문자열 길이 측정
    string replaceAll (const string& str, const string& pattern, const string& replace);        // 문자열안의 문자 모두 바꾸기
        
    // 변수, 클래스 및 벡터
    videoInfo vData;                        // 비디오 정보 클래스
    userInfo uData;                         // 유저 정보 클래스
    vector <videoInfo> videoData;           // 비디오 벡터
    vector <userInfo> userData;             // 유저 백터

    // 시간 변수
    time_t now = time (NULL);                       // 현재시간
    time_t reDay;                                   // 반납날짜
    struct tm t = *localtime (&now);                // 현재시간
    struct tm past;                                 // 반납날짜

    int curr_year = t.tm_year - 100;
    int curr_month = t.tm_mon + 1;
    int curr_day = t.tm_mday;
    int curr_hour = t.tm_hour;
    int curr_minute = t.tm_min;
    int curr_second = t.tm_sec;
};