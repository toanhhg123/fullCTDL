//#include <iostream>
//#include <string>
//using namespace std;
//class Xe
//{
//protected:
//    /* data */
//    string Ten_nguoi_thue;
//    int So_gio_thue;
//
//public:
//    void In_put();
//    void Out_put();
//    Xe(/* args */);
//    ~Xe();
//};
//void Xe::In_put()
//{
//    cin.ignore();
//    cout << "\n\tNhap ho ten nguoi thue: ";
//    getline(cin, Ten_nguoi_thue);
//    cout << "\n\tNhap so gio thue: ";
//    cin >> So_gio_thue;
//}
//void Xe::Out_put()
//{
//    cout << "\n\tHo ten: " << Ten_nguoi_thue;
//    cout << "\n\tSo gio thue: " << So_gio_thue;
//}
//Xe::Xe(/* args */)
//{
//}
//
//Xe::~Xe()
//{
//}
//class Xe_dap : public Xe
//{
//private:
//public:
//    Xe_dap();
//    ~Xe_dap();
//    long Tinh_tien_thue_xe();
//};
//long Xe_dap::Tinh_tien_thue_xe()
//{
//    return 10000.0 + (So_gio_thue - 1.0) * 8000.0;
//}
//Xe_dap::Xe_dap()
//{
//}
//
//Xe_dap::~Xe_dap()
//{
//}
//class Xe_may : public Xe
//{
//private:
//    int Loai_xe;
//    string Bien_so;
//
//public:
//    void In_put();
//    void Out_put();
//    int Getter_Loai_xe() { return Loai_xe; };
//    long Tinh_tien_thue_xe();
//    Xe_may();
//    ~Xe_may();
//};
//void Xe_may::In_put()
//{
//    Xe::In_put();
//    cout << "\n\tNhap loai xe: ";
//    cin >> Loai_xe;
//    cin.ignore();
//    cout << "\n\tNhap bien so cua xe: ";
//    getline(cin, Bien_so);
//}
//void Xe_may::Out_put()
//{
//    Xe::Out_put();
//    cout << "\n\tLoai xe: " << Loai_xe;
//    cout << "\n\tBien so: " << Bien_so;
//}
//long Xe_may::Tinh_tien_thue_xe()
//{
//    if (Loai_xe == 100)
//        return 150000 + (So_gio_thue - 1) * 100000;
//    return 200000 + (So_gio_thue - 1) * 100000;
//}
//Xe_may::Xe_may()
//{
//}
//
//Xe_may::~Xe_may() {}
//void xuat_thong_tin_xe(Xe_dap* ds_xedap[], int n, Xe_may* ds_xemay[],int m)
//{
//    cout << "\n===================================";
//    for (int i = 0; i < n; i++)
//    {
//        cout << "\n\tThong tin xe dap thu " << i + 1;
//        ds_xedap[i]->Out_put();
//    }
//    cout << "\n===================================";
//    for (int i = 0; i < m; i++)
//    {
//        cout << "\n\tThong tin xe may thu " << i + 1;
//        ds_xemay[i]->Out_put();
//    }
//
//}
//long Tong_tien_thue_xe(Xe_dap* ds_xedap[], int n, Xe_may* ds_xemay[], int m)
//{
//    long sum_1 = 0;
//    cout << "\n===================================";
//    for (int i = 0; i < n; i++)
//    {
//        sum_1 += ds_xedap[i]->Tinh_tien_thue_xe();
//    }
//    long sum_2 = 0;
//    cout << "\n===================================";
//    for (int i = 0; i < m; i++)
//    {
//        sum_2 += ds_xemay[i]->Tinh_tien_thue_xe();
//    }
//    return size_t(sum_1 + sum_2);
//
//}
//long Tong_tien_thue_xe_250( Xe_may* ds_xemay[], int m)
//{
//    long sum_2 = 0;
//    cout << "\n===================================";
//    for (int i = 0; i < m; i++)
//    {
//        if (ds_xemay[i]->Getter_Loai_xe() == 250)
//            sum_2 += ds_xemay[i]->Tinh_tien_thue_xe();
//    }
//    return sum_2;
//
//}
//void menu(Xe_dap* ds_xedap[], int& n, Xe_may* ds_xemay[], int& m)
//{
//    int luachon;
//    n = 0, m = 0;
//    while (1)
//    {
//        cout << "\n============Quan_Li_Xe=====================";
//        cout << "\n\t1. Nhap thong tin xe dap va xe may";
//        cout << "\n\t2. Xuat thong tin xe";
//        cout << "\n\t3. Xuat tong tien thue xe";
//        cout << "\n\t4. Tinh vien thue xe 250 Phan khoi";
//        cout << "\n===========================================";
//        cout << "\n\tNhap lua chon cua ban: ";
//        cin >> luachon;
//        system("cls");
//        switch (luachon)
//        {
//        case 1:
//        {
//            while (luachon != 0)
//            {
//                cout << "\n\t1. Nhap thong tin xe dap";
//                cout << "\n\t2. Nhap Thong Tin xe may";
//                cout << "\nNhap Lua chon cua ban: ";
//                cin >> luachon;
//                switch (luachon)
//                {
//                case 1:
//                    ds_xedap[n] = new Xe_dap();
//                    ds_xedap[n]->In_put();
//                    n++;
//                    break;
//                case 2:
//                    ds_xemay[m] = new Xe_may();
//                    ds_xemay[m]->In_put();
//                    m++;
//                    break;
//                default:
//                    break;
//                }
//            }
//
//            break;
//        }
//        case 2:
//            xuat_thong_tin_xe(ds_xedap, n, ds_xemay, m);
//            break;
//        case 3:
//            cout << "\n\tTong tien thue xe la : " << Tong_tien_thue_xe(ds_xedap, n, ds_xemay, m);
//            break;
//        case 4:
//            cout << "\n\tTong tien thue xe 250 la : " << Tong_tien_thue_xe_250( ds_xemay, m);
//            break;
//        default:
//            break;
//        }
//    }
//}
//int main()
//{
//    Xe_dap *ds_xedap[100];
//    Xe_may *ds_xemay[100];
//    int n, m;
//    menu(ds_xedap, n, ds_xemay, m);
//    return 0;
//}