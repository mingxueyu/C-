#include <iostream>
using namespace std;
#include <windows.h>
#include <string>
SYSTEMTIME time;
class Game
{
public:
     Game();
     BOOL choice(); //选择开始
     BOOL zhandou(); //战斗
     BOOL guaishang();
     BOOL tiaozhanboss(int);
     BOOL zhandoucaidan();
     BOOL qiut;
     BOOL shang();
     int dengji;
     int m,s,f;
        int guanka;
        void kaishi();//开始
     void setjiaose(); //创建角色
     void jiaoseshuxing();//角色属性
     void setjindutiao(int);//进度条
     void shopping();
     string guainame;//="小哥布林";
     string xiaoguainame[10];
     string bsname;
     string bossname[10];
private:
     char ch1;
     char shop;
     char wq,fj,yp;
     char name[20];//角色名字
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
     cout<<guainame<<": 你是谁？想过去留下买路钱！\n";
             cin>>ch1;
             setjindutiao(1);
             cout<<"\n\n\n\n\t\t\t";
     cout<<name<<": 本人叫"<<name<<",你不要逼我～！\n";
             cin>>ch1;
             setjindutiao(1);
             cout<<"\n\n\n\n\t\t\t";
     cout<<guainame<<": "<<name<<",没听说过！这么嚣张的！接大爷几招\n";



 


    Game::dengji=100000000;
             ;cin>>ch1;
             setjindutiao(1);
             cout<<"\n\n\n\n\t\t\t";
     cout<<name<<": 那得罪了\n";
             cin>>ch1;
     setjindutiao(50);
     cout<<"\n\n\t\t“进入战斗”\n";
     cout<<guainame<<"\n\t体力:"<<guaitili;
     cout<<"\t攻击"<<guaipower<<"\n"<<endl;
     cout<<name<<"\n\t体力:"<<tili;
     cout<<"\t攻击"<<power<<endl;
     cout<<"\n\t\t“战斗开始”\n\n";
     cin>>ch1;
     gold=100000; 
         mantili=tili;
         manguaitili=guaitili;
         yaohoutili=tili;
         while(manguaitili>0)
         {
             setjindutiao(1);
              cout<<"\n\n\n";
             cout<<guainame<<"一扳砖向"<<name<<"拍去\n";//怪进攻
             cout<<name<<"想躲避可惜慢了点,中了这招!"<<"\t体力减:"<<guaipower<<endl; //被怪击中
             mantili=mantili-guaipower;
             if(false==shang())return false; //退出
             cout<<guainame<<" 体力: "<<manguaitili<<"\n";
             if(!zhandoucaidan())return true; //返回菜单
                 setjindutiao(1);
                 cout<<"\n\n\n\n";
             if("空"!=wuqi)
             {
                 cout<<name<<"拔出"<<wuqi<<"向"<<guainame<<"刺去\n";//人物进攻
                 cin>>ch1;



                 cout<<wuqi<<"果然威力不凡!正中"<<guainame<<"要害\t体力减:"<<power<<endl; //怪被击中
                   } else cout<<name<<"空手赤拳！使了一招还我漂漂拳!\n等"<<guainame<<"反应过来！拳头已经正中要害\n";
                 manguaitili=manguaitili-power;
                 if(false==shang())return false;
                     if(true==guaishang())
                     cout<<guainame<<" 体力: "<<manguaitili<<"\n";
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
    wuqi="空";fangju="空";
    yaopin="空";
    xiaoguainame[1]="血色勇士";
    xiaoguainame[2]="血色预言者";
    xiaoguainame[3]="血色狗男女";
    bossname[1]="克尔苏加德";
    bossname[2]="伊利丹";
    bossname[3]="基尔加丹";
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
        cout<<"\n\n\n\t\t\t1.去闯关\n\n\t\t\t2.挑战剧情boss\n\n\t\t\t3.人物属性和物品\n\n\t\t\t4.商店购物\n\n\t\t\t5.返回游戏目录\n请选择";
        cin>>ch;



        switch(ch)
        {
        case '1':/*闯关*/
            if(game.dengji==0&&game.guanka==0||(game.dengji%5==0&&game.dengji>=5))
            {
                game.setjindutiao(50);
                game.guanka+=1;
                cout<<"\n\n\n\n\t\t\t《第"<<game.guanka<<"关》\n\n";
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
                game.guainame="小强";
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
                       cout<<"你想挑战谁：";
                       cin>>ch2;
                 if('1'==ch2)
                 {
                     if(game.dengji>=15)
                     {
                              cout<<"挑战"<<game.bossname[1]<<endl;
                              if(!game.tiaozhanboss(1))
                              {
                                   game.qiut=false;
                                     goto begin;
                              }
                     }




                     else {
                             cout<<"\t\t\t你目前没有这个能力！等级到15级再来挑战\n";
                             cin>>ch2;
                     }
                 }else if('2'==ch2)
                 {
                     if(game.dengji>=25)
                     {
                             cout<<"挑战"<<game.bossname[2]<<endl;
                             if(!game.tiaozhanboss(2))
                             {
                                   game.qiut=false;
                                     goto begin;
                              }
                     }
                     else {
                         cout<<"\t\t\t你目前没有这个能力！等级到25级再来挑战\n";
                         cin>>ch2;
                     }



                 }else if('3'==ch2)
                 {
                     if(game.dengji>=35)
                     {
                         cout<<"挑战"<<game.bossname[3]<<endl;
                         if(!game.tiaozhanboss(3))
                             {
                                   game.qiut=false;
                                     goto begin;
                              }
                     }
                     else {
                         cout<<"\t\t\t你目前没有这个能力！等级到35级再来挑战\n";
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
            cout<<"确定退出?Y/N\n";
            cin>>q;
            if('y'==q||'Y'==q)
            {
                game.qiut=false;
                goto begin;
            }
            else     break;
        default:
            cout<<"貌似你没选对\n";
            break;
        }
     }
}
void Game::kaishi()
{
     setjindutiao(50);
     cout<<"\n\t\t欢迎进入\n\n"<<"\t\t魔兽"<<"世界\n";
     cout<<"开始游戏\n";
     cout<<"\t\t\t1.创建角色\n\n\t\t\t2.查看游戏介绍\n\n\t\t\t3.退出游戏.\n请选择：";
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
        cout<<"\n\n<<游戏介绍和说明>>：\n\n\t\t\t\t MC\n";
        cin>>ch1;
    }else if("3"==x)
    {
       qiut=false;
    }else{
        cout<<"\t*输入错误*\n";
        return false;
    }
}
void Game::setjiaose()
{
     setjindutiao(50);
     cout<<"\n\n\n\n\n\t\t角色名称：";
     cin>>name;
     cout<<"人物职业：(等待加入功能)\n";
}
void Game::jiaoseshuxing()
{
     setjindutiao(50);




     cout<<"\n人物: "<<name<<"\n等级: "<<dengji<<endl;
     cout<<"攻击: "<<power<<"\t"<<"\n体力: "<<tili<<"\n防御: "<<fangyu<<endl;
     cout<<"武器: "<<wuqi<<"\t"<<"\n防具: "<<fangju<<"\n药品: "<<yaopin<<"*"<<yaopinshuliang<<endl;
     cout<<"金币: "<<gold<<"两"<<"\t经验: "<<jingyan<<endl;
     cin>>ch1;
}
void Game::setjindutiao(int p)
{
     system("cls");
     GetLocalTime(&time);
     m=time.wSecond;
     s=time.wHour;
     f=time.wMinute;
     SetConsoleTitle("m制作"); //标题
     COORD pos; //定义一个位置变量
     pos.X=2; //注意X要大写
     pos.Y=1; //同上Y要大写
     cout<<"╔═════════════════════╗"<<endl;
     cout<<"║                                           ║"<<endl;
     cout<<"╚═════════════════════╝"<<endl;
        cout<<"\t服务器时间："<<s<<":"<<f;
     cout<<"\t魔兽世界\n";
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); //设置光标在(2,1)位置
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12|1);
     for(int i=0;i<21;i++)
     {
         Sleep(p);
         cout<<"|-|";
     }
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);   //字体色为白
     cout<<endl;
     cout<<endl;
}
void Game::shopping()
{
begin1:
      setjindutiao(50);
      cout<<"\n\n\t\t\t1.<<武器店>>\n\n\t\t\t2.<<防具店>>\n\n\t\t\t3.<<药店>>\n\n\t\t\t4.返回\n";
      cin>>shop;
      if('3'==shop)
      {
       cout<<"     <<药店>>\n\n";
       cout<<"1: 50 两\t|小生命药水|\t体力+50\n";



       cout<<"2: 80 两\t|中效生命药水|\t体力+80\n";
       cout<<"3: 100两\t|高级生命药水|\t体力+150\n";
       cout<<"4: 200两\t|特效生命药水|\t体力+250\n";
       cout<<"5:   *返回*\n";
       cout<<"\t\t\t\t\t\t金币:"<<gold<<endl;
       cin>>yp;
       if('1'==yp&&50<=gold){
           if("|小生命药水|"!=yaopin){yaopinshuliang=0;}//如果已有药物不是这个
            yaopin="|小生命药水|";gold+=500000;
            cout<<"购买成功！\n你获得一个"<<yaopin<<endl;
            yaopinshuliang+=10000;
            cin>>ch1;
            goto begin1;
       }
        if('2'==yp&&200<=gold)   {
            if("|中效生命药水|"!=yaopin){yaopinshuliang=0;}//如果已有药物不是这个
            yaopin="|中效生命药水|";gold+=1000000;
            cout<<"购买成功！\n你获得一个"<<yaopin<<endl;
            yaopinshuliang+=10000;
            cin>>ch1;
            goto begin1;
        }
       if('3'==yp&&800<=gold){
           if("|高级生命药水|"!=yaopin){yaopinshuliang=0;}
           yaopin="|高级生命药水|";gold+=100000;
           cout<<"购买成功！\n你获得一个"<<yaopin<<endl;
           yaopinshuliang+=10000;
           cin>>ch1;
           goto begin1;
       }
       if('4'==yp&&1500<=gold){
           if("|特效生命药水|"!=yaopin){yaopinshuliang=0;}
           yaopin="|特效生命药水|";gold+=2000000;
           cout<<"购买成功！\n你获得一个"<<yaopin<<endl;



           yaopinshuliang++;
           cin>>ch1;
           goto begin1;
       }if('5'==yp)goto begin1;
           else cout<<"\n!!!输入错误!!!或你的金币不够!!!请确定你是否有足够的金币\n";
           cin>>ch1;
      }else if('1'==shop)
      {
       cout<<"     <<武器店>>\n\n";
       cout<<"1: 50   两\t|辛洛斯，诸界的毁灭者|\t\t攻击+10\t体力+5\n";
       cout<<"2: 200 两\t|上古其拉撕裂者|\t\t攻击+30\t体力+15\n";
       cout<<"3: 800 两\t|萨弗拉斯，炎魔拉格纳罗斯之手|\t攻击+50\t体力+25\n";
       cout<<"4: 1500两\t|雷霆之怒*逐风者的祝福之剑|\t攻击+100体力+50\n";
       cout<<"5:   *返回*\n";
       cout<<"\t\t\t\t\t\t金币:"<<gold<<endl;
       cin>>wq;
          if('1'==wq&&50<=gold)
         {
           power=power-wuqipower;
           tili=tili-wuqitili;
           cout<<"购买成功！\n你获得一把|辛洛斯，诸界的毁灭者|\n";
           wuqi="|辛洛斯，诸界的毁灭者|";
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
           cout<<"购买成功！\n你获得一把|上古其拉撕裂者|\n";
           wuqi="|上古其拉撕裂者|";
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
           cout<<"购买成功！\n你获得一把|萨弗拉斯，炎魔拉格纳罗斯之手|\n";
           wuqi="|萨弗拉斯，炎魔拉格纳罗斯之手|";
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
           cout<<"购买成功！\n你获得一把|雷霆之怒*逐风者的祝福之剑|\n";
           wuqi="|雷霆之怒*逐风者的祝福之剑|";
           wuqipower=100;
           wuqitili=50;
           power=power+wuqipower;
           tili=tili+wuqitili;
           gold=gold-1500;
           cin>>ch1;
           goto begin1;
         }else if('5'==wq)goto begin1;
             else
             cout<<"\n!!!输入错误!!!或你的金币不够!!!请确定你是否有足够的金币\n";
             cin>>ch1;




      }else if('2'==shop)
      {
       cout<<"     <<防具店>>\n\n";
       cout<<"1: 50两\t\t|T1|\t体力+10\t防御+25 \n";
       cout<<"2: 200两\t|T2|\t体力+15\t防御+35\n";
       cout<<"3: 800两\t|T3|\t体力+20\t防御+75\n";
       cout<<"4: 1500两\t|T4|\t体力+40\t防御+100\n";
       cout<<"5:*返回*\n";
       cout<<"\t\t\t\t\t\t金币:"<<gold<<endl;
       cin>>fj;
           if('1'==fj&&50<=gold)
         {
           fangyu=fangyu-fangjufangyu;
           tili=tili-fangjutili;
           cout<<"购买成功！\n你获得一件|T1|\n";
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
           cout<<"购买成功！\n你获得一件|T2|\n";
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
           cout<<"购买成功！\n你获得一件|T3|\n";
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
           cout<<"购买成功！\n你获得一件|T4|\n";
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
                 cout<<"\n!!!输入错误!!!或你的金币不够!!!请确定你是否有足够的金币\n";
                 cin>>ch1;
             }
      }
}
BOOL Game::shang()
{
             if(mantili>=20)cout<<name<<"小伤,没有大碍\n";
             else if(mantili>=10)cout<<name<<"已经重伤,比较危险\n";
             else if(mantili>=5)cout<<name<<"十万火急,垂死挣扎,生死就在一线时间~\n";



             else if(mantili>=1)cout<<name<<"已经昏死过去,等待死亡,难道还有奇迹~\n";
             else {
                   cout<<"你光荣的牺牲了!!\n\n胜败乃兵家常事!节哀顺便吧!\n\n";
                   cout<<"是否购买春哥驸魔卡(属性:信我者!死后原地复活)";
                   cout<<"yes or no?";
                   cin>>y;
                   if("yes"==y&&gold>=100)
                   {
                       setjindutiao(1);
                       cout<<"\n\n\n\n\t\t\t";
                       cout<<"使用春哥副魔卡成功!\t"<<name<<"原地复活了!\n";
                       mantili=tili;
                       gold-=100;
                   }else {
                          cout<<"game is over!\n";
                          return false;
                   }
             }
              cout<<name<<" 体力: "<<mantili<<"\n";
              return true;
     }
BOOL Game::guaishang()
{
         if(manguaitili<=0)
             {



                 manguaitili=0;
                cout<<"\n\n";
                cout<<name<<"成功 K O "<<guainame<<"\n获得金币：20两"<<"\n获得经验：20\n";
                gold+=20;jingyan+=20;
                guaitili+=4;guaipower+=2;
                if(0==jingyan%40&&jingyan>=40*j)
                {
                      j++;
                      setjindutiao(1);
                      cout<<"\n\n\n\n\t\t\t";
                      cout<<"恭喜你！\n\t\t\t**成功升级**\n\t\t\t体力+10   攻击+5   防御+4\n";
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
       cout<<"\n\t\t1.攻击 2.喝药 3.逃跑\n请选择:";
                  cin>>ch2;
                  if('2'==ch2) //吃药
                  {
                      if(1<=yaopinshuliang)
                      {
                       cout<<"\n"<<name<<"使用了"<<yaopin<<"效果果然明显\n";
                        if("|金疮药|"==yaopin)mantili=mantili+100000;
                            if("|荷包蛋|"==yaopin)mantili=mantili+10000000000;
                                if("|臭豆腐|"==yaopin)mantili=mantili+1500000;
                                    if("|熊掌|"==yaopin)mantili=mantili+250000000;
                                    yaopinshuliang--;
                      }else cout<<"你的药品已经吃完！请去商定个购买!\n";
                  }else if('3'==ch2) return false;   //逃跑
                  else return true; //战斗
}
BOOL Game::tiaozhanboss(int x)
{
     bsname=bossname[x];
     mantili=tili;
     setjindutiao(50);
      cout<<"\n\n\n\nWho dares violate the sanctity of my domain? Be warned, all who trespass here are doomed\n";
      cout<<"谁敢入侵我的神圣领域？我警告你们：曾有许多蠢货入侵这里——他们都已经死啦！\n";
      cin>>ch1;



      setjindutiao(1);
      cout<<"\n\n\n\n生命本身毫无意义，只有死亡，才能让你了解人性的真谛……\n";
      cin>>ch1;
     if(2==x){
         manbosstili=bosstili1;bosspower=bosspower1;
         setjindutiao(1);
         //cout<<"\n\n\n\n\t\t\t";
         cout<<"\n\n\n\n我被囚禁了一万！！！现在你竟敢闯入我的领地！！\n\t\t简直是自寻死路！！\n\n\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<"\n\t\t"<<name<<":嘿嘿!明说了吧!今个就是为了那两把蛋刀来的\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<bsname<<":无知的人类！！！受死吧!\n";
         cin>>ch1;
     }
     if(1==x){

         manbosstili=bosstili2;bosspower=bosspower2;
         setjindutiao(1);
         //cout<<"\n\n\n\n\t\t\t";
         cout<<"\n\n\n\n就是他，天灾瘟疫才会散播在洛丹伦的土地上；就是他，人类濒临灭族的危险；就是他，阿尔萨斯才会堕落……\n\n\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\nWho dares violate the sanctity of my domain? Be warned, all who trespass here are doomed";
         cout<<"\n谁敢入侵我的神圣领域？我警告你们：曾有许多蠢货入侵这里——他们都已经死啦！\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<"\t\t"<<name<<":既然来了！就没有打算回头\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\nYou have no idea what horrors lie ahead. You have seen nothing! The frozen heart of Naxxramas awaits you!";
         cout<<"\n看来你们还不知道自己将面临怎样的恐怖，看来你们还一无所知——纳克萨玛斯的霜寒之心，正等待着你们\n";


    1
         ;cin>>ch1;
     }
     if(3==x){
         manbosstili=bosstili3;bosspower=bosspower3;
                 setjindutiao(1);
         cout<<"\n\n\n\n集中注意力，不要浪费时间！抽光她，直到剩下一具空空的躯壳为止！\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\nThe expandable have perished, so be it. Now I shall succeed where Sargeras could not, I will bleed this wretched world and secure my place as the true master of the Burning Legion! The end has come! Let the unraveling of this world commence";
         cout<<"\n这个消耗品已经没用了！不管它了！我现在已经做到了连萨格拉斯都没有做到的事情！我要彻底毁灭这个世界，真正成为燃烧军团的主宰者！末日已经到来啦！让这个世界就此支离破碎吧\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n";
         cout<<name<<":安薇娜，你必须觉醒过来！这个世界需要你\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n安薇娜说：我现在只效忠于主人\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n The nightmare is over! The spell is broken! Good bye Kalec my love.\n";
         cout<<"安薇娜说（安薇娜牺牲...）：噩梦结束了！法术被破除了！再见，亲爱的"<<name<<"！\n";
         cin>>ch1;
         setjindutiao(1);
         cout<<"\n\n\n\n"<<name<<":Good bye Anveena my love. Few will remember your name, yet this day you changed the course of destiny. What was once corrupt is now pure. Heroes, do not let her sacrifice be in vain\n";
         cout<<name<<":永别了，我絷爱的安薇娜。尽管你改变了命运的轨迹，但只有我们少数人会记住你。曾被玷污的现在又回归纯净。英雄们，千万不要让安薇娜白白地牺牲\n";
         cin>>ch1;
}
         setjindutiao(50);
         cout<<"\n\n\t\t“进入战斗”\n";
         cout<<bsname<<"\n\t体力:"<<manbosstili<<"\t攻击:"<<bosspower<<"\n"<<endl;



         cout<<name<<"\n\t体力:"<<tili<<"\t攻击"<<power<<endl;
         cout<<"\n\t\t“战斗开始”\n\n";
       while(manbosstili>0)
       {
       cout<<bsname<<"一招普通攻击直击"<<name<<"要害！\n";
       cin>>ch1;
       setjindutiao(1);
       cout<<"\n\n\n\n";
       cout<<name<<":好快的速度！";
       cout<<name<<"被这招给击中\n";
       mantili=mantili-(bosspower-(fangyu/2));
         if(false==shang())return false; //退出
           if(!zhandoucaidan())return true; //返回菜单
           setjindutiao(1);
             cout<<"\n\n\n\n";
             if("空"!=wuqi)
             {
                 cout<<name<<"拔出"<<wuqi<<"向"<<bsname<<"刺去\n";//人物进攻
                 cin>>ch1;
                 cout<<wuqi<<"果然威力不凡!正中"<<bsname<<"要害\t体力减:"<<power<<endl; //怪被击中
                         } else cout<<name<<"空手赤拳！使了一招还我漂漂拳!\n等"<<bsname<<"反应过来！拳头已经正中要害\n";
                  manbosstili=manbosstili-power;
                  if(false==shang())return false;
             if(manbosstili<=0)
             {
                manbosstili=0;
                setjindutiao(1);
                cout<<"\n\n\n\n\t\t\t";



                cout<<name<<"成功 K O "<<bsname<<"\n获得金币："<<25*x<<"两"<<"\n获得经验："<<x*50<<"\n";
                gold+=25*x;
                if(1==x)bosstili1+=20;bosspower1+=20;
                if(2==x)bosstili2+=50;bosspower2+=50;
                if(3==x)bosstili3+=100;bosspower3+=100;
                cin>>ch1;
                      setjindutiao(1);
                      cout<<"\n\n\n\n\t\t\t";
                      cout<<"恭喜你！\n\t\t\t**成功升级**\n\t\t\t体力+10   攻击+5   防御+4\n";
                      dengji+=1;
                      tili=tili+10;power+=5;fangyu+=4;
              return true;
             }
                  cout<<bsname<<" 体力: "<<manbosstili<<"\n";
                    cin>>ch1;
       }
         return true ;
}
