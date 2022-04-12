#include <iostream>  //입출력 사용
#include <vector> //vector 사용

using namespace std;  //std namespace 사용중
typedef long long ll;  //ll을 long long형으로 고정해놓음

ll greedyOil(vector<pair<ll, ll>>& city, int n) {  //vector와 정수를 인자로 받는 함수
    ll cur_cost = city[0].second, tot_cost = 0;  //현재 기름값과 총 가격 초기화

    for (int i = 0; i < n; i++) {  //n번 반복
        if (city[i].second < cur_cost) { //이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second; //현재 기름값을 이 도시의 기름값으로
        }
        tot_cost += (cur_cost * city[i].first); //이동 비용
    }
    return tot_cost;  //총 가격 return
}

/**
 * [주유소]
 *
 * 최대한 가격이 싼 곳에서 많은 기름을 넣어야 한다.
 * 따라서 첫번째 도시부터 현재까지 가장 싼 가격을 저장하고, 이동에 필요한만큼만 기름을 채운다.
 * 이렇게 하면 지금까지 지나 온 도시 중 가장 싼 곳에서 최대한 많이 살 수 있다.
 *
 * !주의! 도시 사이의 간격이 최대 10^9이고, 리터당 가격이 최대 10^9이므로
 *       가능한 정답의 최댓값은 10^18으로 int 범위 넘어감! -> long long 써야 함
 */

int main() {  //main함수
    int n;  //정수형 변수 선언

    //입력
    cin >> n; //도시 수 입력받기
    vector<pair<ll, ll>> city(n, { 0, 0 });  //long long형 쌍으로 city 선언
    for (int i = 0; i < n - 1; i++) {  //도로 수는 n-1개
        cin >> city[i].first; //도로 길이 입력받기
    }
    for (int i = 0; i < n; i++) {  //도시 수는 n개
        cin >> city[i].second;  //기름값 입력받기
    }

    //연산 & 출력
    cout << greedyOil(city, n);  //최소 가격 출력
    return 0; //0을 return
}