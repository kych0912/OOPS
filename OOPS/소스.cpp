#include <iostream>
#include <string>
#include <random>
using namespace std;
class Soldier {
private:
	string name;
	int grade; // 1 : �̵, 2 : �Ϻ�, 3 : ��, 4 : ����
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
	cout << "2�ߴ� �ο� : " << soldier_count << "\n";
}












Soldier::Soldier() {
	soldier_count++;

	this->name = "����";
	this->grade = 1;
	this->hobby = "����";
}
Soldier::Soldier(const string& name, int grade, const string& hobby){
	cout << name << "���� �Դ븦 ȯ���մϴ�\n";
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

	if (name == "������")
		cout << name << " �Ǻ�����\n";
	else
		cout << name << " ����\n";
}

void Hobby(Soldier* s) {
	for (auto i = 0; i < 6; i++) {
		if (s[i].getGrade() == 1)
			cout << s[i].getName() << " �̵�� ���(Ư��)�� ";
		else if (s[i].getGrade() == 2)
			cout << s[i].getName() << " �Ϻ��� ���(Ư��)�� ";
		else if (s[i].getGrade() == 3)
			cout << s[i].getName() << " ���� ���(Ư��)�� ";
		else if (s[i].getGrade() == 4)
			cout << s[i].getName() << " ������ ���(Ư��)�� ";
		cout << s[i].getHobby() << "�Դϴ�." << endl;
	}
}
void Army(Soldier* s) {
	Soldier::PrintSoldierCount();

	for (auto i = 0; i < 6; i++)
		cout << s[i].getName() << endl;

	Soldier s7("������", 4, "�۾�");
	cout << s7.getName() << "�� Ư��� " << s7.getHobby() << "\n";

	Soldier::PrintSoldierCount();
}
void Matrix(Soldier* s) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 5);

	int rowNums = 2;
	int colNums = 3;

	do {
		cout << "�� �Է� : ";
		cin >> rowNums;
		cout << "�� �Է� : ";
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
		string badWords[] = { "�ٺ�", "����", "��ģ", "����" };
		for (auto word : badWords)
			if (sentence.find(word) < sentence.size()) {
				//cout << sentence.find(word) << " / " << sentence.size() << endl;
				bad = true;
			}

		if (bad) { cout << "(���ۺҰ�) **********************" << endl; }
		else { cout << "(���۵�) " << sentence << endl; }
	};

	do {
		cout << "������ �Է� : ";
		getline(cin, input);

		IsTermOfAbuse(input);
	} while (input != "��");
}
int main1222() {
	int menu = 0;
	Soldier* soldiers = new Soldier[]{
		Soldier("������", 1, "�Ѹ�����"), Soldier("����ȣ", 1, "�౸"),
		Soldier("�ڹμ�", 2, "����"), Soldier("�Ӵ���",2, "����ġ��"),
		Soldier("�����", 3, "����Ÿ��"), Soldier("���ϱ�",4, "������ ��û")
	};

	for (;;) {
		cout << "1) 2�ߴ� 2) ���/Ư�� 3) �δ����� 4) �ǽð� ���������� 5) ���� ? ";
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
			cout << "* ������ ���ϵ帳�ϴ� *\n";
			break;
		}
		else
			cout << "�޴����� ����ּ���.\n";
	}
	delete[] soldiers;
	soldiers = nullptr;
	Soldier::PrintSoldierCount();

	return 0;
}