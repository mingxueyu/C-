  1 //=======================
  2 //        main.cpp
  3 //=======================
  4 
  5 // main function for the RPG style game
  6 
  7 #include <iostream>
  8 #include <string>
  9 using namespace std;
 10 
 11 #include "swordsman.h"
 12 #include "archer.h"
 13 #include "mage.h"
 14 
 15 int main()
 16 {
 17     string tempName;
 18     bool success=0;        //flag for storing whether operation is successful
 19     cout <<"请输入玩家姓名：";
 20     cin >>tempName;        // get player's name from keyboard input
 21     player *human;        // use pointer of base class, convenience for polymorphism
 22     int tempJob;        // temp choice for job selection
 23     do
 24     {
 25         cout <<"请选择职业： 1 战士, 2 弓箭手, 3 法师"<<endl;
 26         cin>>tempJob;
 27         system("cls");        // clear the screen
 28         switch(tempJob)
 29         {
 30         case 1:
 31             human=new swordsman(1,tempName);    // create the character with user inputted name and job
 32             success=1;        // operation succeed
 33             break;
 34         case 2:
 35             human=new archer(1,tempName);    // create the character with user inputted name and job
 36             success=1;        // operation succeed
 37             break;
 38         case 3:
 39             human=new mage(1,tempName);    // create the character with user inputted name and job
 40             success=1;        // operation succeed
 41             break;
 42         default:
 43             break;                // In this case, success=0, character creation failed
 44         }
 45     }
 46     while(success!=1);        // so the loop will ask user to re-create a character
 47 
 48     int tempCom;            // temp command inputted by user
 49     int nOpp=0;                // the Nth opponent
 50     for(int i=1; nOpp<5; i+=2)    // i is opponent's level
 51     {
 52         nOpp++;
 53         system("cls");
 54         cout<<"STAGE" <<nOpp<<endl;
 55         cout<<"你的对手, 一个 Lv. "<<i<<" 战士"<<endl;
 56         system("pause");
 57         swordsman enemy(i, "Warrior");    // Initialise an opponent, level i, name "Junior"
 58         human->reFill();                // get HP/MP refill before start fight
 59 
 60         while(!human->death() && !enemy.death())    // no died
 61         {
 62             success=0;
 63             while (success!=1)
 64             {
 65                 showinfo(*human,enemy);                // show fighter's information
 66                 cout<<"请选择: "<<endl;
 67                 cout<<"1 攻击; 2 技能; 3 使用体力药水; 4 使用魔法药水; 0 离开游戏"<<endl;
 68                 cin>>tempCom;
 69                 switch(tempCom)
 70                 {
 71                 case 0:
 72                     cout<<"确定退出吗? Y/N"<<endl;
 73                     char temp;
 74                     cin>>temp;
 75                     if(temp=='Y'||temp=='y')
 76                         return 0;
 77                     else
 78                         break;
 79                 case 1:
 80                     success=human->attack(enemy);
 81                     human->isLevelUp();
 82                     enemy.isDead();
 83                     break;
 84                 case 2:
 85                     success=human->specialatt(enemy);
 86                     human->isLevelUp();
 87                     enemy.isDead();
 88                     break;
 89                 case 3:
 90                     success=human->useHeal();
 91                     break;
 92                 case 4:
 93                     success=human->useMW();
 94                     break;
 95                 default:
 96                     break;
 97                 }
 98             }
 99             if(!enemy.death())        // If AI still alive
100                 enemy.AI(*human);
101             else                            // AI died
102             {
103                 cout<<"YOU WIN"<<endl;
104                 human->transfer(enemy);        // player got all AI's items
105             }
106             if (human->death())
107             {
108                 system("cls");
109                 cout<<endl<<setw(50)<<"GAME OVER"<<endl;
110                 delete human;//6_???????????        // player is dead, program is getting to its end, what should we do here?
111                 system("pause");
112                 return 0;
113             }
114         }
115     }
116     delete human;//7_?????????            // You win, program is getting to its end, what should we do here?
117     system("cls");
118     cout<<"恭喜你! 你击败了所有对手!!"<<endl;
119     system("pause");
120     return 0;
121 }


 1 //=======================
 2 //        container.h
 3 //=======================
 4 
 5 // The so-called inventory of a player in RPG games
 6 // contains two items, heal and magic water
 7 
 8 #ifndef _CONTAINER//1_?????????????        // Conditional compilation
 9 #define _CONTAINER
10 
11 class container        // Inventory
12 {
13 protected:
14     int numOfHeal;            // number of heal
15     int numOfMW;            // number of magic water
16 public:
17     container();            // constuctor
18     void set(int heal_n, int mw_n);    // set the items numbers
19     int nOfHeal();            // get the number of heal
20     int nOfMW();            // get the number of magic water
21     void display();            // display the items;
22     bool useHeal();            // use heal
23     bool useMW();            // use magic water
24 };
25 
26 #endif


 1 //=======================
 2 //        container.cpp
 3 //=======================
 4 #include "container.h"
 5 #include <iostream>
 6 using namespace std;
 7 // default constructor initialise the inventory as empty
 8 container::container()
 9 {
10     set(0,0);
11 }
12 
13 // set the item numbers
14 void container::set(int heal_n, int mw_n)
15 {
16     numOfHeal=heal_n;
17     numOfMW=mw_n;
18 }
19 
20 // get the number of heal
21 int container::nOfHeal()
22 {
23     return numOfHeal;
24 }
25 
26 // get the number of magic water
27 int container::nOfMW()
28 {
29     return numOfMW;
30 }
31 
32 // display the items;
33 void container::display()
34 {
35     cout<<"你的物品: "<<endl;
36     cout<<"恢复(HP+100): "<<numOfHeal<<endl;
37     cout<<"魔法药水 (MP+80): "<<numOfMW<<endl;
38 }
39 
40 //use heal
41 bool container::useHeal()
42 {
43     numOfHeal--;//2_????????
44     return 1;        // use heal successfully
45 }
46 
47 //use magic water
48 bool container::useMW()
49 {
50     numOfMW--;
51     return 1;        // use magic water successfully
52 }


 1 //=======================
 2 //        player.h
 3 //=======================
 4 
 5 // The base class of player
 6 // including the general properties and methods related to a character
 7 
 8 #ifndef _PLAYER
 9 #define _PLAYER
10 
11 #include <iomanip>        // use for setting field width
12 #include <time.h>        // use for generating random factor
13 #include "container.h"
14 #include <string>
15 #include <windows.h>
16 using namespace std;
17 
18 enum job {sw, ar, mg};    /* define 3 jobs by enumerate type
19                                sword man, archer, mage */
20 class player
21 {
22     friend void showinfo(player &p1, player &p2);
23     friend class swordsman;
24     friend class archer;
25     friend class mage;
26 
27 protected:
28     int HP, HPmax, MP, MPmax, AP, DP, speed, EXP, LV;
29     // General properties of all characters
30     string name;    // character name
31     job role;        /* character's job, one of swordman, archer and mage,
32                        as defined by the enumerate type */
33     container bag;    // character's inventory
34 
35 public:
36     virtual bool attack(player &p)=0;    // normal attack
37     virtual bool specialatt(player &p)=0;    //special attack
38     virtual void isLevelUp()=0;            // level up judgement
39     /* Attention!
40     These three methods are called "Pure virtual functions".
41     They have only declaration, but no definition.
42     The class with pure virtual functions are called "Abstract class", which can only be used to inherited, but not to constructor objects.
43     The detailed definition of these pure virtual functions will be given in subclasses. */
44 
45     void reFill();        // character's HP and MP resume
46     bool death();        // report whether character is dead
47     void isDead();        // check whether character is dead
48     bool useHeal();        // consume heal, irrelevant to job
49     bool useMW();        // consume magic water, irrelevant to job
50     void transfer(player &p);    // possess opponent's items after victory
51     void showRole();    // display character's job
52 
53 private:
54     bool playerdeath;            // whether character is dead, doesn't need to be accessed or inherited
55 };
56 
57 #endif


  1 //=======================
  2 //        player.cpp
  3 //=======================
  4 
  5 #include "player.h"
  6 #include <iostream>
  7 //using namespace std;
  8 // character's HP and MP resume
  9 void player::reFill()
 10 {
 11     HP=HPmax;        // HP and MP fully recovered
 12     MP=MPmax;
 13 }
 14 
 15 // report whether character is dead
 16 bool player::death()
 17 {
 18     return playerdeath;
 19 }
 20 
 21 // check whether character is dead
 22 void player::isDead()
 23 {
 24     if(HP<=0)        // HP less than 0, character is dead
 25     {
 26         cout<<name<<" 死亡." <<endl;
 27         system("pause");
 28         playerdeath=1;    // give the label of death value 1
 29     }
 30 }
 31 
 32 // consume heal, irrelevant to job
 33 bool player::useHeal()
 34 {
 35     if(bag.nOfHeal()>0)
 36     {
 37         HP=HP+100;
 38         if(HP>HPmax)        // HP cannot be larger than maximum value
 39             HP=HPmax;        // so assign it to HPmax, if necessary
 40         cout<<name<<" 使用恢复, HP 增加 100."<<endl;
 41         bag.useHeal();        // use heal
 42         system("pause");
 43         return 1;    // usage of heal succeed
 44     }
 45     else                // If no more heal in bag, cannot use
 46     {
 47         cout<<"对不起, 你没有足够的恢复."<<endl;
 48         system("pause");
 49         return 0;    // usage of heal failed
 50     }
 51 }
 52 
 53 // consume magic water, irrelevant to job
 54 bool player::useMW()
 55 {
 56     if(bag.nOfMW()>0)
 57     {
 58         MP=MP+100;
 59         if(MP>MPmax)
 60             MP=MPmax;
 61         cout<<name<<" 使用魔法药水, MP 增加 100."<<endl;
 62         bag.useMW();
 63         system("pause");
 64         return 1;    // usage of magic water succeed
 65     }
 66     else
 67     {
 68         cout<<"对不起,你没有足够的魔法药水."<<endl;
 69         system("pause");
 70         return 0;    // usage of magic water failed
 71     }
 72 }
 73 
 74 // possess opponent's items after victory
 75 void player::transfer(player &p)
 76 {
 77     cout<<name<<" 获得"<<p.bag.nOfHeal()<<" 恢复, 和 "<<p.bag.nOfMW()<<" 魔法药水."<<endl;
 78     system("pause");
 79     bag.set(bag.nOfHeal() + p.bag.nOfHeal(), bag.nOfMW() + p.bag.nOfMW());//3_???????????
 80     // set the character's bag, get opponent's items
 81 }
 82 
 83 // display character's job
 84 void player::showRole()
 85 {
 86     switch(role)
 87     {
 88     case sw:
 89         cout<<"战士";
 90         break;
 91     case ar:
 92         cout<<"弓箭手";
 93         break;
 94     case mg:
 95         cout<<"法师";
 96         break;
 97     default:
 98         break;
 99     }
100 }
101 
102 
103 // display character's job
104 void showinfo(player &p1, player &p2)//4_??????????????
105 {
106     system("cls");
107     cout<<"##############################################################"<<endl;
108     cout<<"# 玩家"<<setw(10)<<p1.name<<"   LV. "<<setw(3) <<p1.LV
109         <<"  # 对手"<<setw(10)<<p2.name<<"   LV. "<<setw(3) <<p2.LV<<" #"<<endl;
110     cout<<"# HP "<<setw(3)<<(p1.HP<=999?p1.HP:999)<<'/'<<setw(3)<<(p1.HPmax<=999?p1.HPmax:999)
111         <<" | MP "<<setw(3)<<(p1.MP<=999?p1.MP:999)<<'/'<<setw(3)<<(p1.MPmax<=999?p1.MPmax:999)
112         <<"     # HP "<<setw(3)<<(p2.HP<=999?p2.HP:999)<<'/'<<setw(3)<<(p2.HPmax<=999?p2.HPmax:999)
113         <<" | MP "<<setw(3)<<(p2.MP<=999?p2.MP:999)<<'/'<<setw(3)<<(p2.MPmax<=999?p2.MPmax:999)<<"      #"<<endl;
114     cout<<"# AP "<<setw(3)<<(p1.AP<=999?p1.AP:999)
115         <<" | DP "<<setw(3)<<(p1.DP<=999?p1.DP:999)
116         <<" | speed "<<setw(3)<<(p1.speed<=999?p1.speed:999)
117         <<" # AP "<<setw(3)<<(p2.AP<=999?p2.AP:999)
118         <<" | DP "<<setw(3)<<(p2.DP<=999?p2.DP:999)
119         <<" | speed "<<setw(3)<<(p2.speed<=999?p2.speed:999)<<"  #"<<endl;
120     cout<<"# EXP"<<setw(7)<<p1.EXP<<" 职业: "<<setw(7);
121     p1.showRole();
122     cout<<"   # EXP"<<setw(7)<<p2.EXP<<" 职业: "<<setw(7);
123     p2.showRole();
124     cout<<"    #"<<endl;
125     cout<<"--------------------------------------------------------------"<<endl;
126     p1.bag.display();
127     cout<<"##############################################################"<<endl;
128 }


 1 //=======================
 2 //        swordsman.h
 3 //=======================
 4 
 5 // Derived from base class player
 6 // For the job Swordsman
 7 
 8 #include "player.h"
 9 class swordsman :public player// 5_?????????        // subclass swordsman publicly inherited from base player
10 {
11 public:
12     swordsman(int lv_in=1, string name_in="Not Given");    
13         // constructor with default level of 1 and name of "Not given"
14     void isLevelUp();
15     bool attack (player &p);
16     bool specialatt(player &p);
17         /* These three are derived from the pure virtual functions of base class
18            The definition of them will be given in this subclass. */
19     void AI(player &p);                // Computer opponent
20 };


  1 //=======================
  2 //        swordsman.cpp
  3 //=======================
  4 #include "swordsman.h"
  5 #include <iostream>
  6 
  7 // constructor. default values don't need to be repeated here
  8 swordsman::swordsman(int lv_in, string name_in)
  9 {
 10     role=sw;    // enumerate type of job
 11     LV=lv_in;
 12     name=name_in;
 13     
 14     // Initialising the character's properties, based on his level
 15     HPmax=150+8*(LV-1);        // HP increases 8 point2 per level
 16     HP=HPmax;
 17     MPmax=75+2*(LV-1);        // MP increases 2 points per level
 18     MP=MPmax;
 19     AP=25+4*(LV-1);            // AP increases 4 points per level
 20     DP=25+4*(LV-1);            // DP increases 4 points per level
 21     speed=25+2*(LV-1);        // speed increases 2 points per level
 22     
 23     playerdeath=0;
 24     EXP=(LV-1)*(LV-1)*75;
 25     bag.set(lv_in, lv_in);
 26 }
 27 
 28 void swordsman::isLevelUp()
 29 {
 30     if(EXP>=LV*LV*75)
 31     {
 32         LV++;
 33         AP+=4;
 34         DP+=4;
 35         HPmax+=8;
 36         MPmax+=2;
 37         speed+=2;
 38         cout<<name<<" Level UP!"<<endl;
 39         cout<<"HP 增加 8 变成 "<<HPmax<<endl;
 40         cout<<"MP 增加 2 变成 "<<MPmax<<endl;
 41         cout<<"Speed 增加 2 变成 "<<speed<<endl;
 42         cout<<"AP 增加 4 变成 "<<AP<<endl;
 43         cout<<"DP 增加 5 变成 "<<DP<<endl;
 44         system("pause");
 45         isLevelUp();    // recursively call this function, so the character can level up multiple times if got enough exp
 46     }
 47 }
 48 
 49 bool swordsman::attack(player &p)
 50 {
 51     double HPtemp=0;        // opponent's HP decrement
 52     double EXPtemp=0;        // player obtained exp
 53     double hit=1;            // attach factor, probably give critical attack
 54     srand((unsigned)time(NULL));        // generating random seed based on system time
 55 
 56     // If speed greater than opponent, you have some possibility to do double attack
 57     if ((speed>p.speed) && (rand()%100<(speed-p.speed)))        // rand()%100 means generates a number no greater than 100
 58     {
 59         HPtemp=(int)((1.0*AP/p.DP)*AP*5/(rand()%4+10));        // opponent's HP decrement calculated based their AP/DP, and uncertain chance
 60         cout<<name<<"的攻击伤害了 "<<p.name<<", "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
 61         p.HP=int(p.HP-HPtemp);
 62         EXPtemp=(int)(HPtemp*1.2);
 63     }
 64 
 65     // If speed smaller than opponent, the opponent has possibility to evade
 66     if ((speed<p.speed) && (rand()%50<1))
 67     {
 68         cout<<name<<"的攻击被 "<<p.name<<"躲避"<<endl;
 69         system("pause");
 70         return 1;
 71     }
 72 
 73     // 10% chance give critical attack
 74     if (rand()%100<=10)
 75     {
 76         hit=1.5;
 77         cout<<"关键的攻击: ";
 78     }
 79 
 80     // Normal attack
 81     HPtemp=(int)((1.0*AP/p.DP)*AP*5/(rand()%4+10));
 82     cout<<name<<"使用猛击, "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
 83     EXPtemp=(int)(EXPtemp+HPtemp*1.2);
 84     p.HP=(int)(p.HP-HPtemp);
 85     cout<<name<<" 获得 "<<EXPtemp<<" 经验."<<endl;
 86     EXP=(int)(EXP+EXPtemp);
 87     system("pause");
 88     return 1;        // Attack success
 89 }
 90 
 91 bool swordsman::specialatt(player &p)
 92 {
 93     if(MP<40)
 94     {
 95         cout<<"你没有足够的魔法值!"<<endl;
 96         system("pause");
 97         return 0;        // Attack failed
 98     }
 99     else
100     {
101         MP-=40;            // consume 40 MP to do special attack
102         
103         //10% chance opponent evades
104         if(rand()%100<=10)
105         {
106             cout<<name<<"'s leap attack has been evaded by "<<p.name<<endl;
107             system("pause");
108             return 1;
109         }
110         
111         double HPtemp=0;        
112         double EXPtemp=0;        
113         //double hit=1;            
114         //srand(time(NULL));        
115         HPtemp=(int)(AP*1.2+20);        // not related to opponent's DP
116         EXPtemp=(int)(HPtemp*1.5);        // special attack provides more experience
117         cout<<name<<" 使用技能, "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
118         cout<<name<<" 获得 "<<EXPtemp<<" 经验."<<endl;
119         p.HP=(int)(p.HP-HPtemp);
120         EXP=(int)(EXP+EXPtemp);
121         system("pause");
122     }
123     return 1;    // special attack succeed
124 }
125 
126 // Computer opponent
127 void swordsman::AI(player &p)
128 {
129     if ((HP<(int)((1.0*p.AP/DP)*p.AP*1.5))&&(HP+100<=1.1*HPmax)&&(bag.nOfHeal()>0)&&(HP>(int)((1.0*p.AP/DP)*p.AP*0.5)))
130         // AI's HP cannot sustain 3 rounds && not too lavish && still has heal && won't be killed in next round
131     {
132         useHeal();
133     }
134     else
135     {
136         if(MP>=40 && HP>0.5*HPmax && rand()%100<=30)
137             // AI has enough MP, it has 30% to make special attack
138         {
139             specialatt(p);
140             p.isDead();        // check whether player is dead
141         }
142         else
143         {
144             if (MP<40 && HP>0.5*HPmax && bag.nOfMW())
145                 // Not enough MP && HP is safe && still has magic water
146             {
147                 useMW();
148             }
149             else
150             {
151                 attack(p);    // normal attack
152                 p.isDead();
153             }
154         }
155     }
156 }


 1 //=======================
 2 //        archer.h
 3 //=======================
 4 
 5 // Derived from base class player
 6 // For the job archer
 7 
 8 #include "player.h"
 9 class archer :public player// 5_?????????        // subclass swordsman publicly inherited from base player
10 {
11 public:
12     archer(int lv_in=1, string name_in="Not Given");    
13         // constructor with default level of 1 and name of "Not given"
14     void isLevelUp();
15     bool attack (player &p);
16     bool specialatt(player &p);
17         /* These three are derived from the pure virtual functions of base class
18            The definition of them will be given in this subclass. */
19     void AI(player &p);                // Computer opponent
20 };


  1 //=======================
  2 //        archer.cpp
  3 //=======================
  4 #include "archer.h"
  5 #include <iostream>
  6 #include <cstdio>
  7 #include <windows.h>
  8 // constructor. default values don't need to be repeated here
  9 archer::archer(int lv_in, string name_in)
 10 {
 11     role=sw;    // enumerate type of job
 12     LV=lv_in;
 13     name=name_in;
 14 
 15     // Initialising the character's properties, based on his level
 16     HPmax=150+8*(LV-1);        // HP increases 8 point2 per level
 17     HP=HPmax;
 18     MPmax=75+2*(LV-1);        // MP increases 2 points per level
 19     MP=MPmax;
 20     AP=25+2*(LV-1);            // AP increases 4 points per level
 21     DP=25+6*(LV-1);            // DP increases 4 points per level
 22     speed=25+2*(LV-1);        // speed increases 2 points per level
 23 
 24     playerdeath=0;
 25     EXP=(LV-1)*(LV-1)*75;
 26     bag.set(lv_in, lv_in);
 27 }
 28 
 29 void archer::isLevelUp()
 30 {
 31     if(EXP>=LV*LV*75)
 32     {
 33         LV++;
 34         AP+=4;
 35         DP+=4;
 36         HPmax+=8;
 37         MPmax+=2;
 38         speed+=2;
 39         cout<<name<<" Level UP!"<<endl;
 40         cout<<"HP 增加 8 变成 "<<HPmax<<endl;
 41         cout<<"MP 增加 2 变成 "<<MPmax<<endl;
 42         cout<<"Speed 增加 2 变成 "<<speed<<endl;
 43         cout<<"AP 增加 2 变成 "<<AP<<endl;
 44         cout<<"DP 增加 6 变成 "<<DP<<endl;
 45         system("pause");
 46         isLevelUp();    // recursively call this function, so the character can level up multiple times if got enough exp
 47     }
 48 }
 49 
 50 bool archer::attack(player &p)
 51 {
 52     double HPtemp=0;        // opponent's HP decrement
 53     double EXPtemp=0;        // player obtained exp
 54     double hit=1;            // attach factor, probably give critical attack
 55     srand((unsigned)time(NULL));        // generating random seed based on system time
 56 
 57     // If speed greater than opponent, you have some possibility to do double attack
 58     if ((speed>p.speed) && (rand()%100<(speed-p.speed)))        // rand()%100 means generates a number no greater than 100
 59     {
 60         HPtemp=(int)(DP*5/(rand()%4+10));        // opponent's HP decrement calculated based their AP/DP, and uncertain chance
 61         cout<<name<<"的攻击伤害了 "<<p.name<<", "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
 62         p.HP=int(p.HP-HPtemp);
 63         EXPtemp=(int)(HPtemp*1.2);
 64     }
 65 
 66     // If speed smaller than opponent, the opponent has possibility to evade
 67     if ((speed<p.speed) && (rand()%50<1))
 68     {
 69         cout<<name<<"的攻击被 "<<p.name<<"躲避"<<endl;
 70         system("pause");
 71         return 1;
 72     }
 73 
 74     // 10% chance give critical attack
 75     if (rand()%100<=10)
 76     {
 77         hit=1.5;
 78         cout<<"关键的攻击: ";
 79     }
 80 
 81     // Normal attack
 82     HPtemp=(int)(DP*5/(rand()%4+10));
 83     cout<<name<<"使用猛击, "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
 84     EXPtemp=(int)(EXPtemp+HPtemp*1.2);
 85     p.HP=(int)(p.HP-HPtemp);
 86     cout<<name<<" 获得 "<<EXPtemp<<" 经验."<<endl;
 87     EXP=(int)(EXP+EXPtemp);
 88     system("pause");
 89     return 1;        // Attack success
 90 }
 91 
 92 bool archer::specialatt(player &p)
 93 {
 94     if(MP<40)
 95     {
 96         cout<<"你没有足够的魔法值!"<<endl;
 97         system("pause");
 98         return 0;        // Attack failed
 99     }
100     else
101     {
102         MP-=40;            // consume 40 MP to do special attack
103 
104         //10% chance opponent evades
105         if(rand()%100<=10)
106         {
107             cout<<name<<"'s leap attack has been evaded by "<<p.name<<endl;
108             system("pause");
109             return 1;
110         }
111 
112         double HPtemp=0;
113         double EXPtemp=0;
114         //double hit=1;
115         //srand(time(NULL));
116         HPtemp=(int)(AP*1.2+20);        // not related to opponent's DP
117         EXPtemp=(int)(HPtemp*1.5);        // special attack provides more experience
118         cout<<name<<" 使用技能, "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
119         cout<<name<<" 获得 "<<EXPtemp<<" 经验."<<endl;
120         p.HP=(int)(p.HP-HPtemp);
121         EXP=(int)(EXP+EXPtemp);
122         system("pause");
123     }
124     return 1;    // special attack succeed
125 }
126 
127 // Computer opponent
128 void archer::AI(player &p)
129 {
130     if ((HP<(int)((1.0*p.AP/DP)*p.AP*1.5))&&(HP+100<=1.1*HPmax)&&(bag.nOfHeal()>0)&&(HP>(int)((1.0*p.AP/DP)*p.AP*0.5)))
131         // AI's HP cannot sustain 3 rounds && not too lavish && still has heal && won't be killed in next round
132     {
133         useHeal();
134     }
135     else
136     {
137         if(MP>=40 && HP>0.5*HPmax && rand()%100<=30)
138             // AI has enough MP, it has 30% to make special attack
139         {
140             specialatt(p);
141             p.isDead();        // check whether player is dead
142         }
143         else
144         {
145             if (MP<40 && HP>0.5*HPmax && bag.nOfMW())
146                 // Not enough MP && HP is safe && still has magic water
147             {
148                 useMW();
149             }
150             else
151             {
152                 attack(p);    // normal attack
153                 p.isDead();
154             }
155         }
156     }
157 }


 1 //=======================
 2 //        mage.h
 3 //=======================
 4 
 5 // Derived from base class player
 6 // For the job mage
 7 
 8 #include "player.h"
 9 class mage :public player// 5_?????????        // subclass swordsman publicly inherited from base player
10 {
11 public:
12     mage(int lv_in=1, string name_in="Not Given");    
13         // constructor with default level of 1 and name of "Not given"
14     void isLevelUp();
15     bool attack (player &p);
16     bool specialatt(player &p);
17         /* These three are derived from the pure virtual functions of base class
18            The definition of them will be given in this subclass. */
19     void AI(player &p);                // Computer opponent
20 };


  1 //=======================
  2 //        mage.cpp
  3 //=======================
  4 #include "mage.h"
  5 #include <iostream>
  6 
  7 // constructor. default values don't need to be repeated here
  8 mage::mage(int lv_in, string name_in)
  9 {
 10     role=sw;    // enumerate type of job
 11     LV=lv_in;
 12     name=name_in;
 13     
 14     // Initialising the character's properties, based on his level
 15     HPmax=150+8*(LV-1);        // HP increases 8 point2 per level
 16     HP=HPmax;
 17     MPmax=75+2*(LV-1);        // MP increases 2 points per level
 18     MP=MPmax;
 19     AP=25+6*(LV-1);            // AP increases 4 points per level
 20     DP=25+2*(LV-1);            // DP increases 4 points per level
 21     speed=25+2*(LV-1);        // speed increases 2 points per level
 22     
 23     playerdeath=0;
 24     EXP=(LV-1)*(LV-1)*75;
 25     bag.set(lv_in, lv_in);
 26 }
 27 
 28 void mage::isLevelUp()
 29 {
 30     if(EXP>=LV*LV*75)
 31     {
 32         LV++;
 33         AP+=4;
 34         DP+=4;
 35         HPmax+=8;
 36         MPmax+=2;
 37         speed+=2;
 38         cout<<name<<" Level UP!"<<endl;
 39         cout<<"HP 增加 8 变成 "<<HPmax<<endl;
 40         cout<<"MP 增加 2 变成 "<<MPmax<<endl;
 41         cout<<"Speed 增加 2 变成 "<<speed<<endl;
 42         cout<<"AP 增加 4 变成 "<<AP<<endl;
 43         cout<<"DP 增加 5 变成 "<<DP<<endl;
 44         system("pause");
 45         isLevelUp();    // recursively call this function, so the character can level up multiple times if got enough exp
 46     }
 47 }
 48 
 49 bool mage::attack(player &p)
 50 {
 51     double HPtemp=0;        // opponent's HP decrement
 52     double EXPtemp=0;        // player obtained exp
 53     double hit=1;            // attach factor, probably give critical attack
 54     srand((unsigned)time(NULL));        // generating random seed based on system time
 55 
 56     // If speed greater than opponent, you have some possibility to do double attack
 57     if ((speed>p.speed) && (rand()%100<(speed-p.speed)))        // rand()%100 means generates a number no greater than 100
 58     {
 59         HPtemp=(int)(AP*5/(rand()%4+10));        // opponent's HP decrement calculated based their AP/DP, and uncertain chance
 60         cout<<name<<"的攻击伤害了 "<<p.name<<", "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
 61         p.HP=int(p.HP-HPtemp);
 62         EXPtemp=(int)(HPtemp*1.2);
 63     }
 64 
 65     // If speed smaller than opponent, the opponent has possibility to evade
 66     if ((speed<p.speed) && (rand()%50<1))
 67     {
 68         cout<<name<<"的攻击被 "<<p.name<<"躲避"<<endl;
 69         system("pause");
 70         return 1;
 71     }
 72 
 73     // 10% chance give critical attack
 74     if (rand()%100<=10)
 75     {
 76         hit=1.5;
 77         cout<<"关键的攻击: ";
 78     }
 79 
 80     // Normal attack
 81     HPtemp=(int)(AP*5/(rand()%4+10));
 82     cout<<name<<"使用猛击, "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
 83     EXPtemp=(int)(EXPtemp+HPtemp*1.2);
 84     p.HP=(int)(p.HP-HPtemp);
 85     cout<<name<<" 获得 "<<EXPtemp<<" 经验."<<endl;
 86     EXP=(int)(EXP+EXPtemp);
 87     system("pause");
 88     return 1;        // Attack success
 89 }
 90 
 91 bool mage::specialatt(player &p)
 92 {
 93     if(MP<40)
 94     {
 95         cout<<"你没有足够的魔法值!"<<endl;
 96         system("pause");
 97         return 0;        // Attack failed
 98     }
 99     else
100     {
101         MP-=20;            // consume 40 MP to do special attack
102         
103         //10% chance opponent evades
104         if(rand()%100<=10)
105         {
106             cout<<name<<"'s leap attack has been evaded by "<<p.name<<endl;
107             system("pause");
108             return 1;
109         }
110         
111         double HPtemp=0;        
112         double EXPtemp=0;        
113         //double hit=1;            
114         //srand(time(NULL));        
115         HPtemp=(int)(AP*1.2+20);        // not related to opponent's DP
116         EXPtemp=(int)(HPtemp*1.5);        // special attack provides more experience
117         cout<<name<<" 使用技能, "<<p.name<<"的 HP 下降 "<<HPtemp<<endl;
118         cout<<name<<" 获得 "<<EXPtemp<<" 经验."<<endl;
119         p.HP=(int)(p.HP-HPtemp);
120         EXP=(int)(EXP+EXPtemp);
121         system("pause");
122     }
123     return 1;    // special attack succeed
124 }
125 
126 // Computer opponent
127 void mage::AI(player &p)
128 {
129     if ((HP<(int)((1.0*p.AP/DP)*p.AP*1.5))&&(HP+100<=1.1*HPmax)&&(bag.nOfHeal()>0)&&(HP>(int)((1.0*p.AP/DP)*p.AP*0.5)))
130         // AI's HP cannot sustain 3 rounds && not too lavish && still has heal && won't be killed in next round
131     {
132         useHeal();
133     }
134     else
135     {
136         if(MP>=40 && HP>0.5*HPmax && rand()%100<=30)
137             // AI has enough MP, it has 30% to make special attack
138         {
139             specialatt(p);
140             p.isDead();        // check whether player is dead
141         }
142         else
143         {
144             if (MP<40 && HP>0.5*HPmax && bag.nOfMW())
145                 // Not enough MP && HP is safe && still has magic water
146             {
147                 useMW();
148             }
149             else
150             {
                 attack(p);    // normal attack
                 p.isDead();
             }
         }
     }
 }
