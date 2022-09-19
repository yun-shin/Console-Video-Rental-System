#pragma once

#include <functional>
#include "videoFuc.h"

// 비디오 정렬

struct titleCompare {                                                                                                       // 비디오 제목 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.title < b.title; }
};

struct directorCompare {                                                                                                       // 감독 이름 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.director < b.director; }
};

struct genreCompare {                                                                                                       // 장르 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.genre < b.genre; }
};

struct timeCompare {                                                                                                       // 러닝타임 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.time < b.time; }
};

struct ageLimitCompare {                                                                                                       // 연령제한 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.ageLimit < b.ageLimit; }
};

struct nationCompare {                                                                                                       // 국가 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.nation < b.nation; }
};

struct personCompare {                                                                                                       // 빌려간 사람 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.person < b.person; }
};

struct rentCountCompare {                                                                                                       // 빌린 횟수 내림차순 정렬
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.rentCount < b.rentCount; }
};

// 유저 정렬
struct nameCompare {                                                                                                       // 이름 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.name < b.name; }
};

struct homeCompare {                                                                                                       // 주소 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.home < b.home; }
};

struct borrowVideoCompare {                                                                                                       // 빌린 비디오 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.borrowVideo < b.borrowVideo; }
};

struct borrowDayCompare {                                                                                                       // 빌린 날짜 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.borrowDay < b.borrowDay; }
};

struct returnDayCompare {                                                                                                       // 반납 날짜 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.returnDay < b.returnDay; }
};

struct ageCompare {                                                                                                       // 나이 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.age < b.age; }
};

struct pointCompare {                                                                                                       // 포인트 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.point < b.point; }
};

struct fineCompare {                                                                                                       // 연체료 내림차순 정렬
    bool operator()(const userInfo& a, const userInfo& b) const { return a.fine > b.fine; }
};

// 객체를 위한 구조체를 정의해주시고, 그 안에 operator() 함수를 만들어주면 함수 객체 준비는 끝입니다.