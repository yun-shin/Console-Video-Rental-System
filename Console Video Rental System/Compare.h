#pragma once

#include <functional>
#include "videoFuc.h"

// ���� ����

struct titleCompare {                                                                                                       // ���� ���� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.title < b.title; }
};

struct directorCompare {                                                                                                       // ���� �̸� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.director < b.director; }
};

struct genreCompare {                                                                                                       // �帣 �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.genre < b.genre; }
};

struct timeCompare {                                                                                                       // ����Ÿ�� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.time < b.time; }
};

struct ageLimitCompare {                                                                                                       // �������� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.ageLimit < b.ageLimit; }
};

struct nationCompare {                                                                                                       // ���� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.nation < b.nation; }
};

struct personCompare {                                                                                                       // ������ ��� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.person < b.person; }
};

struct rentCountCompare {                                                                                                       // ���� Ƚ�� �������� ����
    bool operator()(const videoInfo& a, const videoInfo& b) const { return a.rentCount < b.rentCount; }
};

// ���� ����
struct nameCompare {                                                                                                       // �̸� �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.name < b.name; }
};

struct homeCompare {                                                                                                       // �ּ� �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.home < b.home; }
};

struct borrowVideoCompare {                                                                                                       // ���� ���� �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.borrowVideo < b.borrowVideo; }
};

struct borrowDayCompare {                                                                                                       // ���� ��¥ �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.borrowDay < b.borrowDay; }
};

struct returnDayCompare {                                                                                                       // �ݳ� ��¥ �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.returnDay < b.returnDay; }
};

struct ageCompare {                                                                                                       // ���� �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.age < b.age; }
};

struct pointCompare {                                                                                                       // ����Ʈ �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.point < b.point; }
};

struct fineCompare {                                                                                                       // ��ü�� �������� ����
    bool operator()(const userInfo& a, const userInfo& b) const { return a.fine > b.fine; }
};

// ��ü�� ���� ����ü�� �������ֽð�, �� �ȿ� operator() �Լ��� ������ָ� �Լ� ��ü �غ�� ���Դϴ�.