#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct sinhvien
{
	char mssv[15];
	char hoten[30];
	char lop[10];
	int diem;
};
sinhvien creat_sinhvien() {
	sinhvien s;
	cin.ignore();
	cout << "\nnhap data sinh vien"<<endl;
	gets_s(s.mssv);
	gets_s(s.hoten);
	gets_s(s.lop);
	cin >> s.diem;
	return s;
}
struct Node
{
	sinhvien data;
	Node* next;
};
Node* creat_node(Node*& p, sinhvien data)
{
	p = new Node;
	p->data = data;
	p->next = NULL;
	return p;
}
struct SLL
{
	Node* pHead;
	Node* pTail;
};
void creat_SLL(SLL& list)
{
	list.pHead = list.pTail = NULL;
}
void add_NodetoHead_SLL(SLL& list, Node* p)
{
	if (list.pHead == NULL)
		list.pHead = list.pTail = p;
	else
	{
		p->next = list.pHead;
		list.pHead = p;
	}
}
void in_put_file(SLL& list) {
	fstream f("sinhvien.txt");
	if (!f.is_open())
	{
		cout << "\nLoi File";
		return;
	}
	else
	{
		creat_SLL(list);
		sinhvien s;
		Node* p;
		while (!f.eof())
		{
			f >> s.mssv;
			f >> s.hoten;
			f >> s.lop;
			f >> s.diem;
			p=creat_node(p, s);
			add_NodetoHead_SLL(list, p);
		}

	}
}
void xuat_1sinhvien(sinhvien s)
{
	cout << "\n" << s.mssv << "\t" << s.hoten << "\t" << s.lop << "\t" << s.diem;
}
void xuat_sinhvien(SLL list)
{
	Node* p = list.pHead;
	while (p != NULL)
	{
		xuat_1sinhvien(p->data);
		p = p->next;
	}
}
void swap(sinhvien& a, sinhvien& b) {
	sinhvien temp;
	temp = a;
	a = b;
	b = temp;
}
void sort_sinhvien(SLL list)
{
	for (Node* p = list.pHead; p != NULL; p = p->next)
		for (Node* p1 = p->next; p1 != NULL; p1 = p1->next)
			if (p->data.diem > p1->data.diem)
				swap(p->data, p1->data);
	cout << "\nDanh sach sau khi sap xep la: ";
	xuat_sinhvien(list);
}
void max_sinhvien(SLL list)
{
	Node* p = list.pHead;
	sinhvien max = p->data;
	while (p!=NULL)
	{
		if (p->data.diem > max.diem)
			max = p->data;
		p = p->next;
	}
	cout << "\nSinh vien co diem cao nhat la: ";
	xuat_1sinhvien(max);
}
Node* sreach_sinhvien(SLL list, int vitri)
{	
	Node* p = list.pHead;
	if (p == NULL)
		return NULL;
	int count = 0;
	while (p!=NULL)
	{
		if (count == vitri)
			return p;
		count++;
		p = p->next;
	}
	return NULL;
}
void delete_sinhvien(SLL list,int vitri)
{
	Node* p = sreach_sinhvien(list, vitri);
	if (list.pHead == NULL || p == NULL)
	{
		cout << "\nDanh sach rong hoac khong tim thay sinh vien";
		return;
	}
	else if (p == list.pHead)
	{
		list.pHead = list.pHead->next;
		delete p;
	}
	else if (p == list.pTail)
	{
		Node* p1 = sreach_sinhvien(list, vitri - 1);
		p1->next = NULL;
		list.pTail = p1;
		delete p;
	}
	else
	{
		Node* p1 = sreach_sinhvien(list, vitri - 1);
		p1->next = p->next;
		delete p;
	}
	cout << "\ndanh sach sinh vien sau Khi xoa la: ";
	xuat_sinhvien(list);
}
void Add_Node_index(SLL list, int vitri, Node* new_Node)
{
	Node* p = sreach_sinhvien(list, vitri);
	if (list.pHead == NULL || p == NULL || new_Node == NULL)
	{
		cout << "\nERRO";
		return;
	}
	else
	{
		new_Node->next = p->next;
		p->next = new_Node;
	}
	cout << "\nDanh sach sinh vien sau khi them la :";
	xuat_sinhvien(list);
}
void menu() {
	int luachon=1;
	SLL list;
	creat_SLL(list);
	in_put_file(list);
	while (luachon!=0)
	{
		cout << "\n===============Menu================";
		cout << "\n1. Nhap va Xuat file ";
		cout << "\n2. Sap xep sinh vien tang dan theo diem";
		cout << "\n3. Xuat soinh vien co diem cao nhat";
		cout << "\n4. Tim sinh vien tai mot vi tri index";
		cout << "\n5. xoa sinh vien tai vi tri index";
		cout << "\n6. Them sinh vien tai vitri index";
		cout << "\n=====================================";
		cout << "\nNhap lua chon: ";
		cin >> luachon;
		system("cls");
		xuat_sinhvien(list);
		switch (luachon)
		{
		case 1:
		{
			in_put_file(list);
			xuat_sinhvien(list);
			break;
		}
		case 2:
		{
			sort_sinhvien(list);
			break;
		}
		case 3:
			max_sinhvien(list);
			break;
		case 4:
		{
			Node* p = sreach_sinhvien(list, 3);
			cout << "\nsinh vien tai vi  tri index la: ";
			xuat_1sinhvien(p->data);
			break;
		}
		case 5:
		{
			delete_sinhvien(list, 1);
			break;
		}
		case 6:
		{
			Node* p = creat_node(p,creat_sinhvien());
			Add_Node_index(list, 8, p);
			break;
		}
		case 0:
			return;
		default:
			cout << "\nKhong co lua chon nay";
			break;
		}
	}

}

