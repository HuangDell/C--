#include <string>
#include <conio.h>
#include <cctype>
#include "DataBase.cpp"
class Menu
{
    string input;
    Judge judge;
    DataBase data;
    
    public:
    void printMenu()
    {
        printf("1.��Ӷ���ʽ\t\t2.�鿴����ʽ\t\t3.�ӷ�����\n");
        printf("4.��������\t\t  5.�˷�����\t\t  6.��ֵ\n");
    }

    bool isLegal(string choose)
    {
        if (!isdigit(choose[0]) && choose.size() > 1)
            return false;
        return true;
    }

    void Mode1()
    {
        vector<double> poly;
        judge.clear();
        system("cls");
        printf("������һ������ʽ(��ʽ:����(��ѡ)=(ϵ��,ָ��))\n");
        mode1:
        cin >> input;
        poly = judge.polynomial(input);
        if (!poly.empty())
        {
            Polynomial polynomial(poly, judge.getName());
            data.addPoly(polynomial);
            printf("������Ķ���ʽ�ǣ�%s=", judge.getName().c_str());
            cout << polynomial.to_string() << endl;
            printf("�������������\n");
            getch();
        }
        else
        {
            printf("�����ʽ�������������룡\n");
            goto mode1;
        }
    }
    void Mode2()
    {
        system("cls");
        auto data_poly=data.getData();
        printf("Ŀǰ����Ķ���ʽ�У�");
        for (auto temp:data_poly)
            printf("%s=%s\n",temp.getName().c_str(),temp.to_string().c_str());
        printf("�������������\n");
        getch();
    }
};