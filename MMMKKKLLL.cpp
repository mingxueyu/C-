#include <iostream>
using namespace std;
#include <windows.h>
#include <string>
SYSTEMTIME time;
class Game
{
public:
     Game();
     BOOL choice(); //ѡ��ʼ
     BOOL zhandou(); //ս��
     BOOL guaishang();
     BOOL tiaozhanboss(int);
     BOOL zhandoucaidan();
     BOOL qiut;
     BOOL shang();
     int dengji;
     int m,s,f;
        int guanka;
        void kaishi();//��ʼ
     void setjiaose(); //������ɫ
     void jiaoseshuxing();//��ɫ����
     void setjindutiao(int);//������
     void shopping();
     string guainame;//="С�粼��";
     string xiaoguainame[10];
     string bsname;
     string bossname[10];
private:
     char ch1;
     char shop;
     char wq,fj,yp;
     char name[20];//��ɫ����
     int tili,i,j;
     int bosstili,bosspower;
     int manbosstili,yaohoutili,yaopinshuliang;
     int power,fangyu,guaitili,guaipower,wuqipower,wuqitili,fangjutili,fangjupower,fangjufangyu;
     int bosspower1,bosstili1,bosspower2,bosstili2,bosspower3,bosstili3;
     int mantili,gold,jingyan,manguaitili;
     string fangju;
     string wuqi;
     string y;
     string x;
     string yaopin;

};

BOOL Game::zhandou()
{
     setjindutiao(50);
     cout<<"\n\n\n\n\t\t\t";
     cout<<guainame<<": ����˭�����ȥ������·Ǯ��\n";
             cin>>ch1;
             setjindutiao(1);
             cout<<"\n\n\n\n\t\t\t";
     cout<<name<<": ���˽�"<<name<<",�㲻Ҫ���ҡ���\n";
             cin>>ch1;
             setjindutiao(1);
             cout<<"\n\n\n\n\t\t\t";
     cout<<guainame<<": "<<name<<",û��˵������ô���ŵģ��Ӵ�ү����\n";



 


    Game::dengji=100000000;
             ;cin>>ch1;
             setjindutiao(1);
             cout<<"\n\n\n\n\t\t\t";
     cout<<name<<": �ǵ�����\n";
             cin>>ch1;
     setjindutiao(50);
     cout<<"\n\n\t\t������ս����\n";
     cout<<guainame<<"\n\t����:"<<guaitili;
     cout<<"\t����"<<guaipower<<"\n"<<endl;
     cout<<name<<"\n\t����:"<<tili;
     cout<<"\t����"<<power<<endl;
     cout<<"\n\t\t��ս����ʼ��\n\n";
     cin>>ch1;
     gold=100000; 
         mantili=tili;
         manguaitili=guaitili;
         yaohoutili=tili;
         while(manguaitili>0)
         {
             setjindutiao(1);
              cout<<"\n\n\n";
             cout<<guainame<<"һ��ש��"<<name<<"��ȥ\n";//�ֽ���
             cout<<name<<"���ܿ�ϧ���˵�,��������!"<<"\t������:"<<guaipower<<endl; //���ֻ���
             mantili=mantili-guaipower;
             if(false==shang())return false; //�˳�
             cout<<guainame<<" ����: "<<manguaitili<<"\n";
             if(!zhandoucaidan())return true; //���ز˵�
                 setjindutiao(1);
                 cout<<"\n\n\n\n";
             if("��"!=wuqi)
             {
                 cout<<name<<"�γ�"<<wuqi<<"��"<<guainame<<"��ȥ\n";//�������
                 cin>>ch1;



                 cout<<wuqi<<"��Ȼ��������!����"<<guainame<<"Ҫ��\t������:"<<power<<endl; //�ֱ�����
                   } else cout<<name<<"���ֳ�ȭ��ʹ��һ�л���ƯƯȭ!\n��"<<guainame<<"��Ӧ������ȭͷ�Ѿ�����Ҫ��\n";
                 manguaitili=manguaitili-power;
                 if(false==shang())return false;
                     if(true==guaishang())
                     cout<<guainame<<" ����: "<<manguaitili<<"\n";
                     cin>>ch1;
         }     return true;
}
Game::Game():qiut(true),wuqipower(0),wuqitili(0),fangjutili(0),fangjupower(0),fangjufangyu(0)
{
    power=20;tili=40;
    dengji=0;
    fangyu=0;
    jingyan=0;
    gold=0;
    guanka=0;
    yaopinshuliang=0;
    guaipower=2;guaitili=20;
    bosspower1=30;bosstili1=500;
    bosspower2=60;bosstili2=120;
    bosspower3=100;bosstili3=3000;
    j=1;
    wuqi="��";fangju="��";
    yaopin="��";
    xiaoguainame[1]="Ѫɫ��ʿ";
    xiaoguainame[2]="ѪɫԤ����";
    xiaoguainame[3]="Ѫɫ����Ů";
    bossname[1]="�˶��ռӵ�";
    bossname[2]="������";
    bossname[3]="�����ӵ�";
}
int main()
{
begin:
     Game game;
     game.kaishi();
     if(!game.choice())goto begin;
     char ch,ch2;
     int M;
     while(game.qiut)
     {
        game.setjindutiao(50);
        cout<<"\n\n\n\t\t\t1.ȥ����\n\n\t\t\t2.��ս����boss\n\n\t\t\t3.�������Ժ���Ʒ\n\n\t\t\t4.�̵깺��\n\n\t\t\t5.������ϷĿ¼\n��ѡ��";
        cin>>ch;



        switch(ch)
        {
        case '1':/*����*/
            if(game.dengji==0&&game.guanka==0||(game.dengji%5==0&&game.dengji>=5))
            {
                game.setjindutiao(50);
                game.guanka+=1;
                cout<<"\n\n\n\n\t\t\t����"<<game.guanka<<"�ء�\n\n";
                cin>>ch;
            }
            if(game.guanka==1)
            {
                 game.guainame=game.xiaoguainame[1];
                if(game.zhandou())break;
                else game.qiut=false; goto begin;
            }else if(game.guanka==2)
            {
                 game.guainame=game.xiaoguainame[2];
                if(game.zhandou())break;
                else game.qiut=false; goto begin;
            }else if(game.guanka==3)
            {
                game.guainame=game.xiaoguainame[3];
                if(game.zhandou())break;
                else game.qiut=false; goto begin;
            }else
                game.guainame="Сǿ";
                if(game.zhandou())break;
                else game.qiut=false;



                goto begin;
       case '2':
                  game.setjindutiao(1);
                 for( M=1;M<4;M++)
                   {
                       cout<<"\n\n\n\n\t\t\t";
                       cout<<M<<"."<<game.bossname[M]<<"\n";
                   }
                       cout<<"������ս˭��";
                       cin>>ch2;
                 if('1'==ch2)
                 {
                     if(game.dengji>=15)
                     {
                              cout<<"��ս"<<game.bossname[1]<<endl;
                              if(!game.tiaozhanboss(1))
                              {
                                   game.qiut=false;
                                     goto begin;
                              }
                     }




                     else {
                             cout<<"\t\t\t��Ŀǰû������������ȼ���15��������ս\n";
                             cin>>ch2;
                     }
                 }else if('2'==ch2)
                 {
                     if(game.dengji>=25)
                     {
                             cout<<"��ս"<<game.bossname[2]<<endl;
                             if(!game.tiaozhanboss(2))
                             {
                                   game.qiut=false;
                                     goto begin;
                              }
                     }
                     else {
                         cout<<"\t\t\t��Ŀǰû������������ȼ���25��������ս\n";
                         cin>>ch2;
                     }



                 }else if('3'==ch2)
                 {
                     if(game.dengji>=35)
                     {
                         cout<<"��ս"<<game.bossname[3]<<endl;
                         if(!game.tiaozhanboss(3))
                             {
                                   game.qiut=false;
                                     goto begin;
                              }
                     }
                     else {
                         cout<<"\t\t\t��Ŀǰû������������ȼ���35��������ս\n";
                         cin>>ch2;
                     }
                 }
                  break;
            case '3':
            game.jiaoseshuxing();
            break;
        case '4':
            game.shopping();
            break;



        case '5':
            char q;
            cout<<"ȷ���˳�?Y/N\n";
            cin>>q;
            if('y'==q||'Y'==q)
            {
                game.qiut=false;
                goto begin;
            }
            else     break;
        default:
            cout<<"ò����ûѡ��\n";
            break;
        }
     }
}
void Game::kaishi()
{
     setjindutiao(50);
     cout<<"\n\t\t��ӭ����\n\n"<<"\t\tħ��"<<"����\n";
     cout<<"��ʼ��Ϸ\n";
     cout<<"\t\t\t1.������ɫ\n\n\t\t\t2.�鿴��Ϸ����\n\n\t\t\t3.�˳���Ϸ.\n��ѡ��";
     cin>>x;

}
BOOL Game::choice()
{
        if("1"==x)
    {
        setjiaose();
    }
    else if("2"==x)
    {
        setjindutiao(50);
        cout<<"\n\n<<��Ϸ���ܺ�˵��>>��\n\n\t\t\t\t MC\n";
        cin>>ch1;
    }else if("3"==x)
    {
       qiut=false;
    }else{
        cout<<"\t*�������*\n";
        return false;
    }
}
void Game::setjiaose()
{
     setjindutiao(50);
     cout<<"\n\n\n\n\n\t\t��ɫ���ƣ�";
     cin>>name;
     cout<<"����ְҵ��(�ȴ����빦��)\n";
}
void Game::jiaoseshuxing()
{
     setjindutiao(50);




     cout<<"\n����: "<<name<<"\n�ȼ�: "<<dengji<<endl;
     cout<<"����: "<<power<<"\t"<<"\n����: "<<tili<<"\n����: "<<fangyu<<endl;
     cout<<"����: "<<wuqi<<"\t"<<"\n����: "<<fangju<<"\nҩƷ: "<<yaopin<<"*"<<yaopinshuliang<<endl;
     cout<<"���: "<<gold<<"��"<<"\t����: "<<jingyan<<endl;
     cin>>ch1;
}
void Game::setjindutiao(int p)
{
     system("cls");
     GetLocalTime(&time);
     m=time.wSecond;
     s=time.wHour;
     f=time.wMinute;
     SetConsoleTitle("m����"); //����
     COORD pos; //����һ��λ�ñ���
     pos.X=2; //ע��XҪ��д
     pos.Y=1; //ͬ��YҪ��д
     cout<<"�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�["<<endl;
     cout<<"�U                                           �U"<<endl;
     cout<<"�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a"<<endl;
        cout<<"\t������ʱ�䣺"<<s<<":"<<f;
     cout<<"\tħ������\n";
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); //���ù����(2,1)λ��
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12|1);
     for(int i=0;i<21;i++)
     {
         Sleep(p);
         cout<<"|-|";
     }
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);   //����ɫΪ��
     cout<<endl;
     cout<<endl;
}
void Game::shopping()
{
begin1:
      setjindutiao(50);
      cout<<"\n\n\t\t\t1.<<������>>\n\n\t\t\t2.<<���ߵ�>>\n\n\t\t\t3.<<ҩ��>>\n\n\t\t\t4.����\n";
      cin>>shop;
      if('3'==shop)
      {
       cout<<"     <<ҩ��>>\n\n";
       cout<<"1: 50 ��\t|С����ҩˮ|\t����+50\n";



       cout<<"2: 80 ��\t|��Ч����ҩˮ|\t����+80\n";
       cout<<"3: 100��\t|�߼�����ҩˮ|\t����+150\n";
       cout<<"4: 200��\t|��Ч����ҩˮ|\t����+250\n";
       cout<<"5:   *����*\n";
       cout<<"\t\t\t\t\t\t���:"<<gold<<endl;
       cin>>yp;
       if('1'==yp&&50<=gold){
           if("|С����ҩˮ|"!=yaopin){yaopinshuliang=0;}//�������ҩ�ﲻ�����
            yaopin="|С����ҩˮ|";gold+=500000;
            cout<<"����ɹ���\n����һ��"<<yaopin<<endl;
            yaopinshuliang+=10000;
            cin>>ch1;
            goto begin1;
       }
        if('2'==yp&&200<=gold)   {
            if("|��Ч����ҩˮ|"!=yaopin){yaopinshuliang=0;}//�������ҩ�ﲻ�����
            yaopin="|��Ч����ҩˮ|";gold+=1000000;
            cout<<"����ɹ���\n����һ��"<<yaopin<<endl;
            yaopinshuliang+=10000;
            cin>>ch1;
            goto begin1;
        }
       if('3'==yp&&800<=gold){
           if("|�߼�����ҩˮ|"!=yaopin){yaopinshuliang=0;}
           yaopin="|�߼�����ҩˮ|";gold+=100000;
           cout<<"����ɹ���\n����һ��"<<yaopin<<endl;
           yaopinshuliang+=10000;
           cin>>ch1;
           goto begin1;
       }
       if('4'==yp&&1500<=gold){
           if("|��Ч����ҩˮ|"!=yaopin){yaopinshuliang=0;}
           yaopin="|��Ч����ҩˮ|";gold+=2000000;
           cout<<"����ɹ���\n����һ��"<<yaopin<<endl;



           yaopinshuliang++;
           cin>>ch1;
           goto begin1;
       }if('5'==yp)goto begin1;
           else cout<<"\n!!!�������!!!����Ľ�Ҳ���!!!��ȷ�����Ƿ����㹻�Ľ��\n";
           cin>>ch1;
      }else if('1'==shop)
      {
       cout<<"     <<������>>\n\n";
       cout<<"1: 50   ��\t|����˹�����Ļ�����|\t\t����+10\t����+5\n";
       cout<<"2: 200 ��\t|�Ϲ�����˺����|\t\t����+30\t����+15\n";
       cout<<"3: 800 ��\t|������˹����ħ��������˹֮��|\t����+50\t����+25\n";
       cout<<"4: 1500��\t|����֮ŭ*����ߵ�ף��֮��|\t����+100����+50\n";
       cout<<"5:   *����*\n";
       cout<<"\t\t\t\t\t\t���:"<<gold<<endl;
       cin>>wq;
          if('1'==wq&&50<=gold)
         {
           power=power-wuqipower;
           tili=tili-wuqitili;
           cout<<"����ɹ���\n����һ��|����˹�����Ļ�����|\n";
           wuqi="|����˹�����Ļ�����|";
           wuqipower=100000;
           wuqitili=500000;
           power=power+wuqipower;
           tili=tili+wuqitili;
           gold=gold+5000000;
           cin>>ch1;
           goto begin1;
         }else if('2'==wq&&200<=gold)
         {
           power=power-wuqipower;
           tili=tili-wuqitili;
           cout<<"����ɹ���\n����һ��|�Ϲ�����˺����|\n";
           wuqi="|�Ϲ�����˺����|";
           wuqipower=30;




           wuqitili=15;
           power=power+wuqipower;
           tili=tili+wuqitili;
           gold=gold-200;
           cin>>ch1;
           goto begin1;
         }else if('3'==wq&&800<=gold)
         {
           power=power-wuqipower;
           tili=tili-wuqitili;
           cout<<"����ɹ���\n����һ��|������˹����ħ��������˹֮��|\n";
           wuqi="|������˹����ħ��������˹֮��|";
           wuqipower=50;
           wuqitili=25;
           power=power+wuqipower;
           tili=tili+wuqitili;
           gold=gold-800;
           cin>>ch1;
           goto begin1;
         }else if('4'==wq&&1500<=gold)
         {
           power=power-wuqipower;
           tili=tili-wuqitili;
           cout<<"����ɹ���\n����һ��|����֮ŭ*����ߵ�ף��֮��|\n";
           wuqi="|����֮ŭ*����ߵ�ף��֮��|";
           wuqipower=100;
           wuqitili=50;
           power=power+wuqipower;
           tili=tili+wuqitili;
           gold=gold-1500;
           cin>>ch1;
           goto begin1;
         }else if('5'==wq)goto begin1;
             else
             cout<<"\n!!!�������!!!����Ľ�Ҳ���!!!��ȷ�����Ƿ����㹻�Ľ��\n";
             cin>>ch1;




      }else if('2'==shop)
      {
       cout<<"     <<���ߵ�>>\n\n";
       cout<<"1: 50��\t\t|T1|\t����+10\t����+25 \n";
       cout<<"2: 200��\t|T2|\t����+15\t����+35\n";
       cout<<"3: 800��\t|T3|\t����+20\t����+75\n";
       cout<<"4: 1500��\t|T4|\t����+40\t����+100\n";
       cout<<"5:*����*\n";
       cout<<"\t\t\t\t\t\t���:"<<gold<<endl;
       cin>>fj;
           if('1'==fj&&50<=gold)
         {
           fangyu=fangyu-fangjufangyu;
           tili=tili-fangjutili;
           cout<<"����ɹ���\n����һ��|T1|\n";
           fangju="|T1|";
           fangjutili=10;
           fangjufangyu=25;
           fangyu=fangyu+fangjufangyu;
           tili=tili+fangjutili;
           gold=gold-50;
           cin>>ch1;
           goto begin1;
         }else   if('2'==fj&&200<=gold)
         {
           fangyu=fangyu-fangjufangyu;
           tili=tili-fangjutili;
           cout<<"����ɹ���\n����һ��|T2|\n";
           fangju="|T2|";
           fangjutili=15;
           fangjufangyu=35;
           fangyu=fangyu+fangjufangyu;
           tili=tili+fangjutili;
           gold=gold-200;
           cin>>ch1;
           goto begin1;
         }else if('3'==fj&&800<=gold)



         {
           fangyu=fangyu-fangjufangyu;
           tili=tili-fangjutili;
           cout<<"����ɹ���\n����һ��|T3|\n";
           fangju="|T3|";
           fangjutili=20;
           fangjufangyu=75;
           fangyu=fangyu+fangjufangyu;
           tili=tili+fangjutili;
           gold=gold-800;
           cin>>ch1;
           goto begin1;
         }else if('4'==fj&&1500<=gold)
         {
           fangyu=fangyu-fangjufangyu;
           tili=tili-fangjutili;
           cout<<"����ɹ���\n����һ��|T4|\n";
           fangju="|T4|";
           fangjutili=40;
           fangjufangyu=100;
           fangyu=fangyu+fangjufangyu;
           tili=tili+fangjutili;
           gold=gold-1500;
           cin>>ch1;
           goto begin1;
         }else if('5'==fj)goto begin1;
             else
             {
                 cout<<"\n!!!�������!!!����Ľ�Ҳ���!!!��ȷ�����Ƿ����㹻�Ľ��\n";
                 cin>>ch1;
             }
      }
}
BOOL Game::shang()
{
             if(mantili>=20)cout<<name<<"С��,û�д�\n";
             else if(mantili>=10)cout<<name<<"�Ѿ�����,�Ƚ�Σ��\n";
             else if(mantili>=5)cout<<name<<"ʮ���,��������,��������һ��ʱ��~\n";



             else if(mantili>=1)cout<<name<<"�Ѿ�������ȥ,�ȴ�����,�ѵ������漣~\n";
             else {
                   cout<<"����ٵ�������!!\n\nʤ���˱��ҳ���!�ڰ�˳���!\n\n";
                   cout<<"�Ƿ��򴺸���ħ��(����:������!����ԭ�ظ���)";
                   cout<<"yes or no?";
                   cin>>y;
                   if("yes"==y&&gold>=100)
                   {
                       setjindutiao(1);
                       cout<<"\n\n\n\n\t\t\t";
                       cout<<"ʹ�ô��縱ħ���ɹ�!\t"<<name<<"ԭ�ظ�����!\n";
                       mantili=tili;
                       gold-=100;
                   }else {
                          cout<<"game is over!\n";
                          return false;
                   }
             }
              cout<<name<<" ����: "<<mantili<<"\n";
              return true;
     }
BOOL Game::guaishang()
{
         if(manguaitili<=0)
             {



                 manguaitili=0;
                cout<<"\n\n";
                cout<<name<<"�ɹ� K O "<<guainame<<"\n��ý�ң�20��"<<"\n��þ��飺20\n";
                gold+=20;jingyan+=20;
                guaitili+=4;guaipower+=2;
                if(0==jingyan%40&&jingyan>=40*j)
                {
                      j++;
                      setjindutiao(1);
                      cout<<"\n\n\n\n\t\t\t";
                      cout<<"��ϲ�㣡\n\t\t\t**�ɹ�����**\n\t\t\t����+10   ����+5   ����+4\n";
                      dengji+=1;
                      tili=tili+10;power+=5;fangyu+=4;

                     return false;
                }
             }
         return true;
}




BOOL Game::zhandoucaidan()
{
      char ch2;
       cout<<"\n\t\t1.���� 2.��ҩ 3.����\n��ѡ��:";
                  cin>>ch2;
                  if('2'==ch2) //��ҩ
                  {
                      if(1<=yaopinshuliang)
                      {
                       cout<<"\n"<<name<<"ʹ����"<<yaopin<<"Ч����Ȼ����\n";
                        if("|��ҩ|"==yaopin)mantili=mantili+100000;
                            if("|�ɰ���|"==yaopin)mantili=mantili+10000000000;
                                if("|������|"==yaopin)mantili=mantili+1500000;
                                    if("|����|"==yaopin)mantili=mantili+250000000;
                                    yaopinshuliang--;
                      }else cout<<"���ҩƷ�Ѿ����꣡��ȥ�̶�������!\n";
                  }else if('3'==ch2) return false;   //����
                  else return true; //ս��
}
BOOL Game::tiaozhanboss(int x)
{
     bsname=bossname[x];
     mantili=tili;
     setjindutiao(50);
      cout<<"\n\n\n\nWho dares violate the sanctity of my domain? Be warned, all who trespass here are doomed\n";
      cout<<"˭�������ҵ���ʥ�����Ҿ������ǣ�����������������������Ƕ��Ѿ�������\n";
      cin>>ch1;



      setjindutiao(1);
      cout<<"\n\n\n\n��������������壬ֻ�����������������˽����Ե����С���\n";
      cin>>ch1;
     if(2==x){
         manbosstili=bosstili1;bosspower=bosspower1;
         setjindutiao(1);
         //cout<<"\n\n\n\n\t\t\t";
         cout<<"\n\n\n\n�ұ�������һ�򣡣��������㾹�Ҵ����ҵ���أ���\n\t\t��ֱ����Ѱ��·����\n\n\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<"\n\t\t"<<name<<":�ٺ�!��˵�˰�!�������Ϊ�������ѵ�������\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<bsname<<":��֪�����࣡����������!\n";
         cin>>ch1;
     }
     if(1==x){

         manbosstili=bosstili2;bosspower=bosspower2;
         setjindutiao(1);
         //cout<<"\n\n\n\n\t\t\t";
         cout<<"\n\n\n\n���������������߲Ż�ɢ�����嵤�׵������ϣ���������������������Σ�գ���������������˹�Ż���䡭��\n\n\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\nWho dares violate the sanctity of my domain? Be warned, all who trespass here are doomed";
         cout<<"\n˭�������ҵ���ʥ�����Ҿ������ǣ�����������������������Ƕ��Ѿ�������\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<"\t\t"<<name<<":��Ȼ���ˣ���û�д����ͷ\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\nYou have no idea what horrors lie ahead. You have seen nothing! The frozen heart of Naxxramas awaits you!";
         cout<<"\n�������ǻ���֪���Լ������������Ŀֲ����������ǻ�һ����֪�����ɿ�����˹��˪��֮�ģ����ȴ�������\n";


    1
         ;cin>>ch1;
     }
     if(3==x){
         manbosstili=bosstili3;bosspower=bosspower3;
                 setjindutiao(1);
         cout<<"\n\n\n\n����ע��������Ҫ�˷�ʱ�䣡�������ֱ��ʣ��һ�߿տյ�����Ϊֹ��\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\nThe expandable have perished, so be it. Now I shall succeed where Sargeras could not, I will bleed this wretched world and secure my place as the true master of the Burning Legion! The end has come! Let the unraveling of this world commence";
         cout<<"\n�������Ʒ�Ѿ�û���ˣ��������ˣ��������Ѿ���������������˹��û�����������飡��Ҫ���׻���������磬������Ϊȼ�վ��ŵ������ߣ�ĩ���Ѿ������������������ʹ�֧�������\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<name<<":��ޱ�ȣ��������ѹ��������������Ҫ��\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n��ޱ��˵��������ֻЧ��������\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n The nightmare is over! The spell is broken! Good bye Kalec my love.\n";
         cout<<"��ޱ��˵����ޱ������...����ج�ν����ˣ��������Ƴ��ˣ��ټ����װ���"<<name<<"��\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n"<<name<<":Good bye Anveena my love. Few will remember your name, yet this day you changed the course of destiny. What was once corrupt is now pure. Heroes, do not let her sacrifice be in vain\n";
         cout<<name<<":�����ˣ����갮�İ�ޱ�ȡ�������ı������˵Ĺ켣����ֻ�����������˻��ס�㡣�������۵������ֻع鴿����Ӣ���ǣ�ǧ��Ҫ�ð�ޱ�Ȱװ׵�����\n";
         cin>>ch1;
}
         setjindutiao(50);
         cout<<"\n\n\t\t������ս����\n";
         cout<<bsname<<"\n\t����:"<<manbosstili<<"\t����:"<<bosspower<<"\n"<<endl;



         cout<<name<<"\n\t����:"<<tili<<"\t����"<<power<<endl;
         cout<<"\n\t\t��ս����ʼ��\n\n";
       while(manbosstili>0)
       {
       cout<<bsname<<"һ����ͨ����ֱ��"<<name<<"Ҫ����\n";
       cin>>ch1;
       setjindutiao(1);
       cout<<"\n\n\n\n";
       cout<<name<<":�ÿ���ٶȣ�";
       cout<<name<<"�����и�����\n";
       mantili=mantili-(bosspower-(fangyu/2));
         if(false==shang())return false; //�˳�
           if(!zhandoucaidan())return true; //���ز˵�
           setjindutiao(1);
             cout<<"\n\n\n\n";
             if("��"!=wuqi)
             {
                 cout<<name<<"�γ�"<<wuqi<<"��"<<bsname<<"��ȥ\n";//�������
                 cin>>ch1;
                 cout<<wuqi<<"��Ȼ��������!����"<<bsname<<"Ҫ��\t������:"<<power<<endl; //�ֱ�����
                         } else cout<<name<<"���ֳ�ȭ��ʹ��һ�л���ƯƯȭ!\n��"<<bsname<<"��Ӧ������ȭͷ�Ѿ�����Ҫ��\n";
                  manbosstili=manbosstili-power;
                  if(false==shang())return false;
             if(manbosstili<=0)
             {
                manbosstili=0;
                setjindutiao(1);
                cout<<"\n\n\n\n\t\t\t";



                cout<<name<<"�ɹ� K O "<<bsname<<"\n��ý�ң�"<<25*x<<"��"<<"\n��þ��飺"<<x*50<<"\n";
                gold+=25*x;
                if(1==x)bosstili1+=20;bosspower1+=20;
                if(2==x)bosstili2+=50;bosspower2+=50;
                if(3==x)bosstili3+=100;bosspower3+=100;
                cin>>ch1;
                      setjindutiao(1);
                      cout<<"\n\n\n\n\t\t\t";
                      cout<<"��ϲ�㣡\n\t\t\t**�ɹ�����**\n\t\t\t����+10   ����+5   ����+4\n";
                      dengji+=1;
                      tili=tili+10;power+=5;fangyu+=4;
              return true;
             }
                  cout<<bsname<<" ����: "<<manbosstili<<"\n";
                    cin>>ch1;
       }
         return true ;
}
