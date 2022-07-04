#include <iostream>
#include <string>
#include <random>
using namespace std;
class Soldier {
private:
	string name;
	int grade; // 1 : 이등병, 2 : 일병, 3 : 상병, 4 : 병장
	string hobby;

public:
	Soldier();
	Soldier(const string& name, int grade, const string& hobby);
	Soldier(const Soldier& std);
	~Soldier();

	string getName() const {
		return name;
	}
	int getGrade() const {
		return grade;
	}
	string getHobby() const {
		return hobby;
	}

	static int soldier_count;
	static void PrintSoldierCount();
};
int Soldier::soldier_count = 0;
void Soldier::PrintSoldierCount() {
	cout << "2중대 인원 : " << soldier_count << "\n";
}












Soldier::Soldier() {
	soldier_count++;

	this->name = "무명";
	this->grade = 1;
	this->hobby = "없음";
}
Soldier::Soldier(const string& name, int grade, const string& hobby){
	cout << name << "님의 입대를 환영합니다\n";
	soldier_count++;

	this->name = name;
	this->grade = grade;
	this->hobby = hobby;
}
Soldier::Soldier(const Soldier& std) {
	soldier_count++;

	this->name = std.name;
	this->grade = std.grade;
	this->hobby = std.hobby;
}
Soldier::~Soldier() {
	soldier_count--;

	if (name == "성윤모")
		cout << name << " 의병제대\n";
	else
		cout << name << " 전역\n";
}

void Hobby(Soldier* s) {
	for (auto i = 0; i < 6; i++) {
		if (s[i].getGrade() == 1)
			cout << s[i].getName() << " 이등병의 취미(특기)는 ";
		else if (s[i].getGrade() == 2)
			cout << s[i].getName() << " 일병의 취미(특기)는 ";
		else if (s[i].getGrade() == 3)
			cout << s[i].getName() << " 상병의 취미(특기)는 ";
		else if (s[i].getGrade() == 4)
			cout << s[i].getName() << " 병장의 취미(특기)는 ";
		cout << s[i].getHobby() << "입니다." << endl;
	}
}
void Army(Soldier* s) {
	Soldier::PrintSoldierCount();

	for (auto i = 0; i < 6; i++)
		cout << s[i].getName() << endl;

	Soldier s7("심진우", 4, "작업");
	cout << s7.getName() << "의 특기는 " << s7.getHobby() << "\n";

	Soldier::PrintSoldierCount();
}
void Matrix(Soldier* s) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 5);

	int rowNums = 2;
	int colNums = 3;

	do {
		cout << "행 입력 : ";
		cin >> rowNums;
		cout << "열 입력 : ";
		cin >> colNums;
	} while (rowNums <= 0 || colNums <= 0);

	int** arr = new int* [rowNums];

	for (int i = 0; i < rowNums; i++) {
		arr[i] = new int[colNums];
	}
	for (int i = 0; i < rowNums; i++) {
		for (int k = 0; k < colNums; k++) {
			arr[i][k] = dis(gen);
		}
	}
	for (int i = 0; i < rowNums; i++) {
		for (int k = 0; k < colNums; k++) {
			//cout << arr[i][k] << " ";
			cout << s[arr[i][k]].getName() << " ";
		}
		cout << "\n";
	}

	for (int i = 0; i < rowNums; i++) {
		delete[] arr[i];	
	}
	delete[] arr;
	arr = nullptr;
}
void Letter() {
	string input = "";
	auto IsTermOfAbuse = [](const string& sentence)->void {
		bool bad = false;
		string badWords[] = { "바보", "병신", "미친", "나쁜" };
		for (auto word : badWords)
			if (sentence.find(word) < sentence.size()) {
				//cout << sentence.find(word) << " / " << sentence.size() << endl;
				bad = true;
			}

		if (bad) { cout << "(전송불가) **********************" << endl; }
		else { cout << "(전송됨) " << sentence << endl; }
	};

	do {
		cout << "성윤모 입력 : ";
		getline(cin, input);

		IsTermOfAbuse(input);
	} while (input != "끝");
}
int main1222() {
	int menu = 0;
	Soldier* soldiers = new Soldier[]{
		Soldier("성윤모", 1, "롤리폴리"), Soldier("차병호", 1, "축구"),
		Soldier("박민석", 2, "복싱"), Soldier("임다혜",2, "뺑끼치기"),
		Soldier("김상훈", 3, "무에타이"), Soldier("최일구",4, "격투기 시청")
	};

	for (;;) {
		cout << "1) 2중대 2) 취미/특기 3) 부대정렬 4) 실시간 마음의편지 5) 종료 ? ";
		cin >> menu;

		if (menu == 1)
			Army(soldiers);
		else if (menu == 2)
			Hobby(soldiers);
		else if (menu == 3)
			Matrix(soldiers);
		else if (menu == 4)
			Letter();
		else if (menu == 5) {
			cout << "* 전역을 축하드립니다 *\n";
			break;
		}
		else
			cout << "메뉴에서 골라주세요.\n";
	}
	delete[] soldiers;
	soldiers = nullptr;
	Soldier::PrintSoldierCount();

	return 0;
}