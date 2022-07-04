#include <iostream>
#include <random>
//#include <cstdlib>
//#include <ctime>
using namespace std;

class RandomInteger
{
private:
    int low;       // ������ ���
    int high;      // ������ ���    
    int value;     // ������ ���
public:
    RandomInteger(int low, int high);  // ������
    ~RandomInteger();  // �Ҹ���
    // �ռ� ���� �������� ���� ����
    RandomInteger(const RandomInteger& random) = delete;
    void print() const;   // ������ ��� �Լ�
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
    // 100~200 ������ ���� ���� ����
    RandomInteger r1(100, 200);
    cout << "100~200 ������ ������ ����: ";
    r1.print();
    // 400~600 ������ ���� ���� ����
    RandomInteger r2(400, 600);
    cout << "400~600 ������ ������ ����: ";
    r2.print();
    // 1500~2000 ������ ���� ���� ���� 
    RandomInteger r3(1500, 2000);
    cout << "1500~2000 ������ ������ ����: ";
    r3.print();
    r3.setNumber(99);
    r3.print();
    //RandomInteger r4(r1);
    const RandomInteger r4(100, 500);
    r4.print();
    //r4.setNumber(19);
    return 0;
}