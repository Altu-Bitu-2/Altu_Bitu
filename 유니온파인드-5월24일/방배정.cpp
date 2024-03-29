﻿#include <iostream> //입출력 사용
#include <vector>//vector 사용
#include <unordered_map> //unordered_map사용

using namespace std; //std namespace 사용중
typedef long long ll; //long long 형 ll로 이름 고정

unordered_map <ll, ll> parent; //unordered_map선언

ll findParent(ll node) { //Find 연산
    if (parent.find(node) == parent.end()) { //해당 방번호가 처음이면
        parent[node] = node + 1; //방번호+1로 루트연결해주고
        return node; //방번호 return
    }
    return parent[node] = findParent(parent[node]); //부모로 연결
}

vector<ll> assignRoom(vector<ll>& room_number) { //방 배정결과 return하는 함수
    vector<ll> answer(room_number.size(), 0); //answer배열 0으로 초기화
    for (int i = 0; i < room_number.size(); i++) { //개수만큼 반복
        answer[i] = findParent(room_number[i]); //방배정 결과 answer에 받기
    } 
    return answer; //배열째로 return
}

vector<ll> solution(ll k, vector<ll> room_number) { //k와 원하는 방번호 배열 입력받는 함수
    vector<ll> answer = assignRoom(room_number); //answer배열 값 받고
    return answer; //answer return
}

/**
 * [호텔 방 배정]
 *
 * - 방을 배정할 때마다 이번에 배정한 방의 다음 방을 집합의 루트 정점으로 만들어 바로 접근할 수 있도록 설정
 * - parent를 벡터(혹은 배열)로 사용하면 전체 방 개수(k)의 최대가 10^12이기 때문에 메모리 초과
 * -> 따라서 필요한 방의 parent정보만 저장하기 위해 map을 사용해야 함.
 * -> 이때 키 값이 정렬될 필욘 없으므로 unordered_map 사용. map은 시간초과남!
 *
 * (참고) 백준의 10775와 매우 유사한 문제
 */

 //디버깅을 위한 메인 코드 - 프로그래머스에는 제출 X
int main() { //main 함수
    ll k = 10; //방은 10번방까지 있음
    vector<ll> room_number = { 1, 3, 4, 1, 3, 1 }; //원하는 방번호 배열
    vector<ll> result = solution(k, room_number); //연산 결과 받기
    for (int i = 0; i < result.size(); i++) { //크기만큼 반복
        cout << result[i] << ' '; //출력
    }
    return 0; //0을 return
}
