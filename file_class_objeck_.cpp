#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Date_of_birth
{
private:
	int day;
	int month;
	int years;
public:
	int Getter_day()
	{
		return day;
	}
	int Getter_month()
	{
		return month;
	}
	int Getter_years()
	{
		return years;
	}
	void Setter_DMY(int ngay, int thang, int nam)
	{
		day = ngay;
		month = thang;
		years = nam;
	}
};


class Nhan_vien
{
public:
	virtual void Doc_file(fstream &f);
	virtual void Xuat_file();
	string Getter_MaNV()
	{
		return Ma_nv;
	}
protected:
	string Ma_nv;
	string Ten_nx;
	Date_of_birth Ns;
	float He_so_luong;
	float Luong_co_ban;
	string diachi;
};
void Nhan_vien::Doc_file(fstream &f)
{
	getline(f, Ma_nv,',');
	f.seekg(1, 1);
	getline(f, Ten_nx, ',');
	f.seekg(1, 1);
	int x,y,z;
	f >> x;
	f.seekg(1, 1);
	f >> y;
	f.seekg(1, 1);
	f >> z;
	Ns.Setter_DMY(x, y, z);
	f.seekg(1, 1);
	f >> He_so_luong;
	f.seekg(1, 1);
	f >> Luong_co_ban;
	f.seekg(1, 1);
	getline(f, diachi,',');
}
void Nhan_vien::Xuat_file()
{
	cout << "\n" << Ma_nv << "\t" << Ten_nx << "\t" << Ns.Getter_day() << "/"  << Ns.Getter_month()<<"/" << Ns.Getter_years()<< "\t" << He_so_luong << "\t" << size_t (Luong_co_ban) << "\t" << diachi;
}

class Programmer : public Nhan_vien
{
public:
	void Doc_file(fstream& f);
	void Xuat_file();

private:
	float Tien_lam_ngoai_gio;
};
void Programmer::Doc_file(fstream &f)
{
	Nhan_vien::Doc_file(f);
	f.seekg(1, 1);
	f >> Tien_lam_ngoai_gio;

}
void Programmer::Xuat_file()
{
	Nhan_vien::Xuat_file();
	cout << "\t" << size_t(Tien_lam_ngoai_gio);
}
class Designer : public Nhan_vien
{
public:
	void Doc_file(fstream& f);
	void Xuat_file();

private:
	string Tien_bonus;
};
void Designer::Doc_file(fstream& f)
{
	Nhan_vien::Doc_file(f);
	f.seekg(1, 1);
	getline(f,Tien_bonus);

}
void Designer::Xuat_file()
{
	Nhan_vien::Xuat_file();
	cout << "\t" << (Tien_bonus);
}
void docfile(fstream& f, Nhan_vien *x[], int &n)
{
	n = 0;
	f.open("nhanvien.txt");
	if (!f.is_open()) {
		cout << "\nLoi file";
	}
	else
	{
		char c;
		
		while (!f.eof())
		{
			f >> c;
			f.seekg(-1, 1);
			if (c == 'P')
			{
				x[n] = new Programmer;
				x[n]->Doc_file(f);
				n++;
			}
			else
			{
				x[n] = new Designer;
				x[n]->Doc_file(f);
				n++;
			}
		}
	}
	f.close();
}
void xuat_nhanvien(int n, Nhan_vien *x[])
{
	for (int i = 0; i < n; i++)
		x[i]->Xuat_file();
}
int main()
{
	fstream f;
	Nhan_vien* x[100];
	int n;
	docfile(f, x, n);
	xuat_nhanvien(n,x);
	return 0;
}
