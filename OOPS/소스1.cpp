#include <iostream>
#include <random>
//#include <cstdlib>
//#include <ctime>
using namespace std;

class RandomInteger
{
private:
    int low;       // 데이터 멤버
    int high;      // 데이터 멤버    
    int value;     // 데이터 멤버
public:
    RandomInteger(int low, int high);  // 생성자
    ~RandomInteger();  // 소멸자
    // 합성 복사 생성자의 생성 막기
    RandomInteger(const RandomInteger& random) = delete;
    void print() const;   // 접근자 멤버 함수
    void setNumber(int x);
};
RandomInteger::RandomInteger(int lw, int hh) :low(lw), high(hh)
{
    //unsigned int seed = time(0);
    //cout << seed << "\n";
    //srand(seed);

    //srand(time(0));
    //int temp = rand();

    random_device rd;
    mt19937 gen(rd());

    //mt19937 gen(time(0));
    uniform_int_distribution<> dist(low, high);

    int temp = dist(gen);
    value = temp;
}
RandomInteger::~RandomInteger()
{
}
void RandomInteger::print() const
{
    cout << value << endl;
}
void RandomInteger::setNumber(int x)
{
    value = x;
}
int main()
{
    // 100~200 범위의 랜덤 숫자 생성
    RandomInteger r1(100, 200);
    cout << "100~200 사이의 랜덤한 숫자: ";
    r1.print();
    // 400~600 범위의 랜덤 숫자 생성
    RandomInteger r2(400, 600);
    cout << "400~600 사이의 랜덤한 숫자: ";
    r2.print();
    // 1500~2000 범위의 랜덤 숫자 생성 
    RandomInteger r3(1500, 2000);
    cout << "1500~2000 사이의 랜덤한 숫자: ";
    r3.print();
    r3.setNumber(99);
    r3.print();
    //RandomInteger r4(r1);
    const RandomInteger r4(100, 500);
    r4.print();
    //r4.setNumber(19);
    return 0;
}