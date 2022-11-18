#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
class QL_TINH
{
public:
   char ten[30];
   float dien_tich;
   long dan_so;
   void nhap()
   {
      cin.ignore(1);
      cout << "TEN TINH : ";
      cin.getline(ten, 30);
      cout << "\n DIEN TICH : ";
      cin >> dien_tich;
      cout << "\n DAN SO : ";
      cin >> dan_so;
   }

   void In()
   {
      cout << setw(5) << ten << setw(15) << dien_tich << setw(15) << dan_so << endl;
   }
   virtual void Tong_DT()
   {
      cout << "=> TONG DIEN TICH : ";
   }
   virtual void DT_Max()
   {
      cout << "=> TINH CO DIEN TICH LON NHAT  " << endl;
   }
   virtual void DS_Max()
   {
      cout << "=> TINH CO DAN SO LON NHAT  " << endl;
   }
   virtual void SapXep()
   {
      cout << "=> TINH CO DIEN TICH TANG DAN  " << endl;
   }
};

class DS_TINH : public QL_TINH
{
public:
   int n;
   QL_TINH ST[63];
   void nhap()
   {
      cout << "=> Nhap so tinh : ";
      cin >> n;
      for (int i = 0; i < n; i++)
      {
         cout << "\n Tinh thu " << i + 1 << endl;
         ST[i].nhap();
      }
   }
   void In()
   {
      cout << "======DANH SACH VUA NHAP======" << endl;
      cout << setw(10) << "TEN TINH" << setw(15) << "DIEN TICH" << setw(10) << "DAN SO" << endl;
      for (int i = 0; i < n; i++)
      {
         ST[i].In();
      }
   }
   friend istream &operator>>(istream &is, DS_TINH &p)
   {
      p.nhap();
      return is;
   }
   friend ostream &operator<<(ostream &os, DS_TINH &p)
   {
      p.In();
      return os;
   }
   void Tong_DT();
   void DT_Max();
   void DS_Max();
   void SapXep();
   void menu();
   void Press();
};
void DS_TINH::Tong_DT()
{
   {
      float tong = 0;
      for (int i = 0; i < n; i++)
      {
         tong += ST[i].dien_tich;
      }
      QL_TINH::Tong_DT();
      cout << tong << " (M^2)" << endl;
   }
}
void DS_TINH::DT_Max()
{
   float Max = ST[0].dien_tich;
   int moi = 0;
   for (int i = 0; i < n; i++)
   {
      if (Max < ST[i].dien_tich)
      {
         Max = ST[i].dien_tich;
         moi = i;
      }
   }
   QL_TINH::DT_Max();
   ST[moi].In();
   cout << endl;
}
void DS_TINH::DS_Max()
{
   float Max = ST[0].dan_so;
   int moi = 0;
   for (int i = 0; i < n; i++)
   {
      if (Max < ST[i].dan_so)
      {
         Max = ST[i].dan_so;
         moi = i;
      }
   }
   QL_TINH::DS_Max();
   ST[moi].In();
   cout << endl;
}
void DS_TINH::SapXep()
{
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (ST[i].dien_tich > ST[j].dien_tich)
         {
            QL_TINH temp = ST[i];
            ST[i] = ST[j];
            ST[j] = temp;
         }
      }
   }
   ST[n].SapXep();
   for (int i = 0; i < n; i++)
   {
      ST[i].In();
   }
}
void DS_TINH::menu()
{
   cout << "***************************************************************" << endl;
   cout << "*                   NHẬP LỰA CHỌN CỦA BẠN                     *" << endl;
   cout << "* 1. Tổng diện tích                                           *" << endl;
   cout << "* 2. Diện tích lớn nhất                                       *" << endl;
   cout << "* 3. Dân số lớn nhất                                          *" << endl;
   cout << "* 4. Sắp xếp diện tích tăng                                   *" << endl;
   cout << "* 5. Danh sách vừa nhập                                       *" << endl;
   cout << "***************************************************************" << endl;
}
void DS_TINH ::Press()
{
   system("pause");
}
int main()
{
   QL_TINH *CT;
   DS_TINH b;
   CT = &b;
   cin >> b;
   system("cls");
   int Option;
   char LC;
   do
   {
      b.menu();
      cout << "NHẬP LỰA CHỌN : ";
      cin >> Option;
      switch (Option)
      {
      case 1:
         CT->Tong_DT();
         break;
      case 2:
         CT->DT_Max();
         break;
      case 3:
         CT->DS_Max();
         break;
      case 4:
         CT->SapXep();
         break;
      case 5:
         cout << b;
      default:
         cout << "No option";
         break;
      }
      cout << endl;
      cout << "Bạn muốn lựa chọn thêm không (y/n): ";
      cin >> LC;
      if (LC == 'N' || LC == 'n')
      {
         cout << endl;
         cout << "GOOD BYE ";
         cout << endl;
      }
   } while (LC == 'y' || LC == 'Y');
   b.Press();
   return 0;
}