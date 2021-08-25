//#include<iostream>
//using namespace	std;
//#include<fstream>
//#include<string>
//class sinhvien
//{
//public:
//	void nhaphoten();
//	void docfile(fstream &f);
//	void xuathoten();
//	long hocphi();
//	string Getter_hoten()
//	{
//		return hoten;
//	}
//	void Setter_hoten(string Hoten)
//	{
//		hoten = Hoten;
//	}
//	sinhvien();
//	~sinhvien();
//
//private:
//	string hoten;
//	string mssv;
//	string lop;
//	int diem;
//	int tinchi;
//};
//
//sinhvien::sinhvien()
//{
//}
//
//sinhvien::~sinhvien()
//{
//}
//void sinhvien::docfile(fstream &f)
//{
//			f >> hoten;
//			f >> mssv;
//			f >> lop;
//			f >> diem;
//			f >> tinchi;
//}
//void sinhvien::nhaphoten()
//{
//	cin.ignore();
//	cout << "\nNhap ho ten sv: ";
//	getline(cin, hoten);
//	cout << "\nNhap mssv: ";
//	getline(cin, mssv);
//	cout << "\nNhap lop: ";
//	getline(cin, lop);
//	cout << "\nNhap diem: ";
//	cin >> diem;
//	cout << "\nNhap so tin chi: ";
//	cin >> tinchi;
//}
//void sinhvien::xuathoten()
//{
//	cout << "\n Ho ten : " << hoten;
//	cout << "\n mssv : " << mssv;
//	cout << "\n lop : " << lop;
//	cout << "\n Diem : " << diem;
//	cout << "\n So tin chi hoc ki nay la: "<<tinchi;
//}
//long  sinhvien::hocphi()
//{
//	return tinchi * 600000.0;
//}
//
//sinhvien creat_sinhvien()
//{
//	sinhvien s;
//	s.nhaphoten();
//	return s;
//}
//void doc_dsinhvien(fstream& f, int& n,sinhvien *s)
//{
//	int i = 0;
//	f.open("sinhvien_1.txt");
//	if (!f.is_open())
//	{
//		cout << "\n\nLoi file";
//		return;
//	}
//	else
//	{
//		
//		while (!f.eof())
//		{
//			s[i].docfile(f);
//			i++;
//		}
//	}
//	n = i;
//}
//void xuat_ds_file(sinhvien* s, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "\n\tThong tin sinh vien " << i << "\n";
//		s[i].xuathoten();
//	}
//}
//struct Node
//{
//	sinhvien data;
//	Node* next;
//};
//Node *creat_node(sinhvien s)
//{
//	Node* p = new Node;
//	p->data = s;
//	p->next = NULL;
//	return p;
//}
//struct SLL
//{
//	Node* pHead;
//	Node* pTail;
//};
//void creat_SLL_sinhvien(SLL& list)
//{
//	list.pHead = list.pTail = NULL;
//}
//void add_node_toHead(SLL &list,Node *p)
//{
//	if (list.pHead == NULL)
//		list.pHead = list.pTail = p;
//	else
//	{
//		p->next = list.pHead;
//		list.pHead = p;
//	}
//}
//void inPUT_SLL(SLL& list)
//{
//	int n;
//	cout << "\Nhap so luong sinh vien can them vao SLL: ";
//	cin >> n;
//	for(int i = 0; i < n; i++)
//	{
//		cout << "\n\tNhap sinh vien " << i<<endl;
//		sinhvien s;
//		add_node_toHead(list, creat_node(creat_sinhvien()));
//	}
//}
//void out_put(SLL list)
//{
//	Node* p = list.pHead;
//	while (p!=NULL)
//	{
//		cout << "\n\tdata in SLL_List_SInhvien Is: \n";
//		p->data.xuathoten();
//		p = p->next;
//	}
//}
//void swap_sinhvien(sinhvien& a, sinhvien& b)
//{
//	sinhvien temp = a;
//	a = b;
//	b = temp;
//}
//void menu()
//{
//	int luachon;
//	SLL list;
//	creat_SLL_sinhvien(list);
//	inPUT_SLL(list);
//	while (1)
//	{
//		cout << "\n============Menu===================";
//		cout << "\n1. Xuat sinh vien ";
//		cout << "\n===================================";
//		cout << "\nNhap lua chon cua ban: ";
//		cin >> luachon;
//		system("cls");
//		switch (luachon)
//		{
//		case 1:
//		{
//			out_put(list);
//			break;
//		}
//		default:
//			break;
//		}
//	}
//}
//int main() 
//{
//	/*menu();*/
//	sinhvien s[100];
//	fstream f;
//	int n;
//	doc_dsinhvien(f, n, s);
//	xuat_ds_file(s,n );
//	return 0;
//}