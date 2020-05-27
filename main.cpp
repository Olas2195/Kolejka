#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class kolejka {
	ifstream plik1;
	ofstream plik2;
	queue <int> kolejka1;
	int liczba;
	
	 public:
	 	kolejka();
	 	~kolejka();
	 	
	 	void wczytaj();
	 	void zapisz();
};

kolejka::kolejka() {
	plik1.open("we.txt");
	plik2.open("wy.txt");	
}

kolejka::~kolejka() {
	plik1.close();
	plik2.close();
}

void kolejka::wczytaj() {
	if(plik1.good()) {
		while(!plik1.eof()) {
			plik1>>liczba;
			kolejka1.push(liczba);
		}
	}
}

void kolejka::zapisz() {
	cout<<"[\n";
	plik2<<"[\n";
	while(!kolejka1.empty()) {
		plik2<<"{\"liczba\":"<<kolejka1.front()<<"},\n";
		cout<<"{\"liczba\":"<<kolejka1.front()<<"},\n";		
		kolejka1.pop();
	}
	cout<<"]";
	plik2<<"]";
}

int main(int argc, char** argv) {
	kolejka k1;
	k1.wczytaj();
	k1.zapisz();
	
	return 0;
}
