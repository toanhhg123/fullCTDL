//
//#include <iostream>
//#include <string>
//using namespace std;
//class Doc_gia
//{
//protected:
//    string Ho_ten;
//    string Ngay_lam_the;
//    int So_thang_co_hieu_luc_cua_the;
//
//public:
//    virtual void In_put();
//    virtual void Out_put();
//    virtual float Tinh_tien() = 0;
//    Doc_gia();
//    ~Doc_gia();
//};
//void Doc_gia::In_put()
//{
//    cout << "\n\tNhap ho ten: ";
//    cin.ignore();
//    getline(cin, Ho_ten);
//    cout << "\n\tNhap ngay lam the(dd/mm/yy): ";
//    getline(cin, Ngay_lam_the);
//    cout << "\n\tNhap so thang co hieu luc: ";
//    cin >> So_thang_co_hieu_luc_cua_the;
//}
//void Doc_gia::Out_put()
//{
//    cout << "\n\tHo ten: " << Ho_ten;
//    cout << "\n\tngay lam the: " << Ngay_lam_the;
//    cout << "\n\tso thang co hieu luc: " << So_thang_co_hieu_luc_cua_the;
//}
//Doc_gia::Doc_gia()
//{
//}
//
//Doc_gia::~Doc_gia()
//{
//}
//class Doc_gia_tre_em : public Doc_gia
//{
//private:
//    string Ho_tenNDD;
//
//public:
//    void In_put();
//    void Out_put();
//    float Tinh_tien();
//    Doc_gia_tre_em();
//    ~Doc_gia_tre_em();
//};
//void Doc_gia_tre_em::In_put()
//{
//    Doc_gia::In_put();
//    cout << "\n\tNhap ho ten nguoi dai dien: ";
//    cin.ignore();
//    getline(cin, Ho_tenNDD);
//}
//void Doc_gia_tre_em::Out_put()
//{
//    Doc_gia::Out_put();
//    cout << "\n\tHo ten nguoi dai dien: " << Ho_tenNDD;
//}
//float Doc_gia_tre_em::Tinh_tien()
//{
//    return So_thang_co_hieu_luc_cua_the * 50000;
//}
//Doc_gia_tre_em::Doc_gia_tre_em()
//{
//}
//
//Doc_gia_tre_em::~Doc_gia_tre_em()
//{
//}
//class Doc_gia_nguoi_lon : public Doc_gia
//{
//private:
//    string So_CMND;
//
//public:
//    void In_put();
//    void Out_put();
//    float Tinh_tien();
//    Doc_gia_nguoi_lon();
//    ~Doc_gia_nguoi_lon();
//};
//
//void Doc_gia_nguoi_lon::In_put()
//{
//    Doc_gia::In_put();
//    cout << "\n\tNhap so CMND: ";
//    cin.ignore();
//    getline(cin, So_CMND);
//}
//void Doc_gia_nguoi_lon::Out_put()
//{
//    Doc_gia::Out_put();
//    cout << "\n\tSo CMND: " << So_CMND;
//}
//float Doc_gia_nguoi_lon::Tinh_tien()
//{
//    return So_thang_co_hieu_luc_cua_the * 10000;
//}
//Doc_gia_nguoi_lon::Doc_gia_nguoi_lon()
//{
//}
//
//Doc_gia_nguoi_lon::~Doc_gia_nguoi_lon() {}
//class Thu_vien
//{
//private:
//    Doc_gia* ds_docgia[100];
//public:
//    void In_put(int& n);
//    void Out_put(int n);
//    float Tong_tien_lam_the(int n);
//};
//void Thu_vien::In_put(int& n)
//{
//    int luachon = 1;
//    n = 0;
//    while (luachon != 0)
//    {
//        cout << "\n==============Danh_sach_doc_gia================";
//        cout << "\n\t1. Doc gia tre em";
//        cout << "\n\t2. Doc gia Nguoi Lon";
//        cout << "\n\t0. Thoat chuong trinh";
//        cout << "\n===============================================";
//        cout << "\n\tNhap Lua chon: ";
//        cin >> luachon;
//        system("cls");
//        switch (luachon)
//        {
//        case 1:
//        {
//            ds_docgia[n] = new Doc_gia_tre_em();
//            ds_docgia[n]->In_put();
//            n++;
//            break;
//        case 2:
//        {
//            ds_docgia[n] = new Doc_gia_nguoi_lon;
//            ds_docgia[n]->In_put();
//            n++;
//            break;
//        }
//        }
//        }
//    }
//}
//void Thu_vien::Out_put(int n)
//{
//       
//        for (int i = 0; i < n; i++)
//        {
//            cout << "\n\tDoc gia " << i + 1;
//            ds_docgia[i]->Out_put();
//        }
//       
//}
//    float Thu_vien::Tong_tien_lam_the(int n)
//    {
//        float sum_1 = 0;
//        for (int i = 0; i < n; i++)
//        {
//            sum_1 += ds_docgia[i]->Tinh_tien();
//        }
//       
//        return sum_1 ;
//    }
//    void menu(Thu_vien * &thuvien)
//    {
//        thuvien = new Thu_vien;
//        int luachon = 1;
//        int n;
//        while (luachon != 0)
//        {
//            cout << "\n================menu===============";
//            cout << "\n\t1. Nhap Danh sach Doc gia";
//            cout << "\n\t2. Xuat Danh sach doc gia";
//            cout << "\n\t3. Tong tien lam the ";
//            cout << "\n===================================";
//            cout << "\n\tNhap Lua chon: ";
//            cin >> luachon;
//            system("cls");
//            switch (luachon)
//            {
//            case 1:
//            {
//                thuvien->In_put(n);
//                break;
//            }
//            case 2:
//            {
//                thuvien->Out_put(n);
//                break;
//            }
//            case 3:
//            {
//                cout << "\n\tTong tien lam the La: " << thuvien->Tong_tien_lam_the(n);
//                break;
//            }
//            }
//        }
//
//        delete thuvien;
//    }
//    int main()
//    {
//
//        Thu_vien* thuvien;
//        menu(thuvien);
//        return 0;
//    }