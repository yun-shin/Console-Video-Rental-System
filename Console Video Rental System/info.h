#include <iostream>

using namespace std;

class videoInfo {
public:
    string title, director, genre, time, ageLimit, nation, person;          // 비디오이름 감독 장르 러닝타임 권장연령 빌려간사람 대여횟수
    int videoAdress = 0, borrowAdress = 0, rentCount = 0;                   // 비디오 주소, 빌려간사람주소
};

class userInfo {
public:
    string name, home, Pnum, borrowVideo, borrowDay, returnDay;              // 가입자 신상정보, 빌려간 비디오,  빌려간 날짜, 반납날짜
    int fine = 0, age = 0, point = 0, userAdress = 0;                                                       // 현재 연체료, 나이, 포인트
};