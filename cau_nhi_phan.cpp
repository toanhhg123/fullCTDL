//#include <iostream>
//#include<fstream>
//using namespace std;
//#define LOI -999999
//struct Tree
//{
//    int data;
//    Tree* pLeft;
//    Tree* pRight;
//};
//void create_tree(Tree*& t)
//{
//    t = NULL;
//}
//void Add_data_inTree(Tree*& t, int data)
//{
//    if (t == NULL)
//    {
//        t = new Tree;
//        t->data = data;
//        t->pLeft = t->pRight = NULL;
//        return;
//    }
//    else
//    {
//        if (data > t->data)
//            Add_data_inTree(t->pRight, data);
//        else if (data < t->data)
//            Add_data_inTree(t->pLeft, data);
//    }
//}
//void input_file(Tree*& t) {
//    create_tree(t);
//    fstream f("cay_nhi_phan.txt");
//    if (!f.is_open())
//    {
//        cout << "\nLoi file";
//        return;
//    }
//    else
//    {
//        int data;
//        while (!f.eof())
//        {
//            f >> data;
//            Add_data_inTree(t, data);
//        }
//    }
//    f.close();
//}
//void In_put(Tree*& t)
//{
//    create_tree(t);
//    int n;
//    cout << "\nNhap so luong data truyen vao Tree: ";
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int data;
//        cin >> data;
//        Add_data_inTree(t, data);
//    }
//}
//void out_put_NLR(Tree*& t)
//{
//    if (t == NULL)
//        return;
//    cout << "\t" << t->data;
//    out_put_NLR(t->pLeft);
//    out_put_NLR(t->pRight);
//}
//int Max_inTree(Tree*& t)
//{
//    if (t == NULL)
//        return LOI;
//    else if (t->pRight == NULL)
//        return t->data;
//    Max_inTree(t->pRight);
//}
//int Min_inTree(Tree* t)
//{
//    if (t == NULL)
//        return LOI;
//    else if (t->pLeft == NULL)
//        return t->data;
//    Max_inTree(t->pLeft);
//}
//void tree_has_2child(Tree* t)
//{
//    if (t == NULL)
//        return;
//    else if (t->pLeft != NULL && t->pRight != NULL)
//        cout << "\t" << t->data;
//    tree_has_2child(t->pLeft);
//    tree_has_2child(t->pRight);
//}
//void tree_has_1child(Tree* t)
//{
//    if (t == NULL)
//        return;
//    else if ((t->pLeft == NULL && t->pRight != NULL) || (t->pLeft != NULL && t->pRight == NULL))
//        cout << "\t" << t->data;
//    tree_has_1child(t->pLeft);
//    tree_has_1child(t->pRight);
//}
//void support_delete_Node(Tree*& tree_right, int& data)
//{
//    if (tree_right->pLeft == NULL)
//    {
//        data = tree_right->data;
//        return;
//    }
//    support_delete_Node(tree_right->pLeft, data);
//}
//void delete_Node_inTree(Tree*& t, int data)
//{
//    if (t == NULL)
//        return;
//    else
//    {
//        if (data > t->data)
//            delete_Node_inTree(t->pRight, data);
//        else if (data < t->data)
//            delete_Node_inTree(t->pLeft, data);
//        else if (data == t->data && t->pRight == NULL)
//            t = t->pLeft;
//        else if (data == t->data && t->pLeft == NULL)
//            t = t->pRight;
//        else if (data == t->data)
//        {
//            int data;
//            support_delete_Node(t->pRight, data);
//            t->data = data;
//        }
//    }
//}
//void tree_is_leaf(Tree* t)
//{
//    if (t == NULL)
//        return;
//    else if (t->pLeft == NULL && t->pRight == NULL)
//        cout << "\t" << t->data;
//    tree_is_leaf(t->pLeft);
//    tree_is_leaf(t->pRight);
//}
//void menu()
//{
//    int luachon = 1;
//    Tree* t;
//    create_tree(t);
//    input_file(t);
//    while (luachon != 0)
//    {
//        cout << "\n==============Menu===================";
//        cout << "\n1. Input and out_put_NLR";
//        cout << "\n2. Tim Max trong cay";
//        cout << "\n3. Tim Min trong cay";
//        cout << "\n4. Tim cay co 2 con";
//        cout << "\n5. Tim cay co 1 con";
//        cout << "\n6. Tim la cay";
//        cout << "\n7. Xoa Node bat ki";
//        cout << "\n0. KT_chuong trinh";
//        cout << "\n=====================================";
//        cout << "\nNhap lua chon cua ban: ";
//        cin >> luachon;
//        system("cls");
//        out_put_NLR(t);
//        switch (luachon)
//        {
//        case 1:
//        {
//            In_put(t);
//            out_put_NLR(t);
//            break;
//        }
//        case 2:
//        {
//            if (Max_inTree(t) == LOI)
//                cout << "\nNot found data in Tree";
//            else
//                cout << "\nMax = " << Max_inTree(t);
//            break;
//        }
//        case 3:
//        {
//            if (Min_inTree(t) == LOI)
//                cout << "\nNot found data in Tree";
//            else
//                cout << "\nMin = " << Min_inTree(t);
//            break;
//        }
//        case 4:
//        {
//            cout << "\nTree has two child : ";
//            tree_has_2child(t);
//            break;
//        }
//        case 5:
//        {
//            cout << "\nTree has one child : ";
//            tree_has_1child(t);
//            break;
//        }
//        case 6:
//        {
//            cout << "\nTree is leaf : ";
//            tree_is_leaf(t);
//            break;
//        }
//        case 7:
//        {
//            delete_Node_inTree(t, 9);
//            cout << "\ndanh sach sau khi xoa : ";
//            out_put_NLR(t);
//            break;
//        }
//        case 0:
//        {
//            return;
//        }
//        default:
//            cout << "\nKhong co lua chon nay!!!!!!!!";
//            break;
//        }
//    }
//}
//int main()
//{
//    menu();
//    system("pause");
//    return 0;
//}