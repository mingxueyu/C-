百度首页
登录 
加入文库VIP 
意见反馈
下载客户端
网页 新闻 贴吧 知道 音乐 图片 视频 地图 文库 | 
 


首页
分类

精品内容 

名师招募

 
机构合作 

频道专区 

云知识 


文库VIP   

个人中心 

百度文库
专业资料
IT/计算机
计算机软件及应用
上传文档 





相关文档推荐 

www.baidu.com搜索推荐
c++实现简单rpg对战代码... 
11页 

C的几个简单代码 
4页 

c语言实现的简单计算器代... 
8页 

C语言简单贪吃蛇游戏代码... 
4页 

喜欢此文档的还喜欢
C语言 简单计算器程序 源... 
2页 
简单易懂的C语言源代码(... 
13页 
C语言必背18个经典程序 
10页 
简单的迷宫小游戏 C语言... 
2页 
c语言程序代码 
23页 
猜你喜欢





加入文库VIP
获取下载特权 >
c++实现简单RPG对战游戏的代码 
qopas |2018-06-26 | 5.0分(高于99%的文档)|12949|183 |简介 | 举报    手机打开


VIP免费文档 


#include<iostream.h> 
#include<time.h> 
#include<stdlib.h> 
enum propte {sw,ar,mg}; 
class container//人物的小包裹,用来装东西的....目前只装两种物品~有兴趣的可以自己加点东西进去`嘿嘿~ 
{ 
friend class player;//定义一个基类 
friend class Swordsman;//定义一个剑士 
friend class Archer;//定义一个弓剑手 
friend class Mage;//定义一个魔法师,其实我们以前玩的都是这样做的~只要把这些类附给一个人物身上就行了 
friend void ShowWindows(player &p1,player &p2);//显示框框~当前状态的函数 
protected: 
int NumHeal;//生命回复剂 
int NumMgWorter;//魔法恢复剂 
public: 
container ();//构造函数,....目前可有可无的样子~~ 
bool IsNumHealEmpoty();//判断还有没有生命恢复剂 
bool IsMWEmpoty();//判断还有没有魔法恢复剂 
void display();//显示当前还有多少魔法恢复剂和生命恢复剂 
}; 
container::container() 
{ 
NumHeal = 0; 
NumMgWorter = 0; 
} 
bool container::IsNumHealEmpoty() 
{ 
return NumHeal == 0?true:false; 
} 
bool container::IsMWEmpoty() 
{ 
return NumMgWorter == 0?true:false; 
} 
void container::display() 
{ 
cout << "还剩下回复剂（HP+100） " << NumHeal << "个" << endl; 
cout << "还剩下魔法剂 (MP+80) " << NumMgWorter << "个" << endl; 
} 


class player//人物的基类 
{ 
friend class Swordsman; 
friend class Archer; 
friend class Mage;//这些都是朋友关系~又是父与子的关系~- -! 好象有点复杂的样子~ 
friend void ShowWindows(player &p1,player &p2);//上面已经说过了~不再重复 

protected: 
int Hp,HpMax,Mp,MpMax,speed,Ap,Dp,EXP,LV;//最大血量和最大魔法值,当前血量,魔法值,等等~望文生意 
char name[10];//人物名称 
propte role;//人物职业类型 
bool death ;//是否死亡函数 
container bag;//人物的小包包~~^^ 
public: 
void IsDead();//判断人物是否死亡 
bool Dead();//确认人物当前死亡状态~有返回值哦~ 
bool UseHeal();//好累...不过还是继续打字~ 使用生命回复剂 
bool UseMW();//....跟上面差不多~ 
void Getbag(player &p);//如果电脑死亡....就拿走他的小包包里面的东西~ 
void Shourole();//显示当前人物的职业~....这个是额外的函数~乱写的~ 
void HpMpfull();//每打完一关敌人~HP,MP全满~ 
virtual bool attack(player &p) = 0; 
virtual bool TSattack(player &p) = 0; 
virtual void IsLvUp() = 0;//上面三个都是纯虚函数~分别代表 人物的普通攻击~特殊攻击和是否升级 
}; 

void player::HpMpfull() 
{ 
Hp = HpMax; 
Mp = MpMax; 
} 
void player::IsDead() 
{ 
if (Hp <= 0 ) 
{ 
death = 1; 
} 
} 
bool player::Dead() 
{ 
return death == 1? true:false; 
} 
bool player::UseHeal() 
{ 
if ( !bag.IsNumHealEmpoty() ) 
{ 
Hp +=100; 
bag.NumHeal --; 
cout << name << "使用了恢复剂，生命值恢复了100点" << endl; 
if (Hp > HpMax) 
{ 
Hp = HpMax; 
} 
return true; 
} 
else 
{ 
co 

ut << "没有回复剂了 " << endl; 
return false; 
} 
} 
bool player::UseMW() 
{ 
if ( !bag.IsMWEmpoty() ) 
{ 
Mp += 80; 
bag.NumMgWorter --; 
cout << name << "使用了魔法恢复剂，魔法值恢复了80点" << endl; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
return true; 
} 
else 
{ 
cout << "没有魔法恢复剂了~" << endl; 
return false; 
} 
} 
void player::Getbag(player &p) 
{ 
cout << name << "获得了对方物品" << endl; 
cout << "获得了回复剂 " << p.bag.NumHeal << "个" << endl; 
cout << "获得了魔法回复剂 " << p.bag.NumMgWorter << "个" << endl; 
bag.NumHeal += p.bag.NumHeal; 
bag.NumMgWorter += p.bag.NumMgWorter; 
} 
void player::Shourole() 
{ 
switch(role) 
{ 
case sw: 
cout << "职业：剑士" << endl; 
break; 
case ar: 
cout << "职业：弓箭手" << endl; 
break; 
case mg: 
cout << "职业：魔法师" << endl; 
break; 
} 
} 

class Swordsman:public player//从基类派生出的一个类,是关于剑士的~ 
{ 

public: 
Swordsman(int i, char *chname)//构造函数~赋予当前人物的属性值 
{ 
role = sw; 
int j; 
for (j=0; j<10; j++) 
{ 
name[j] = chname[j]; 
} 
Hp = 150 + 8 * (i - 1); 
HpMax = 150 + 8 * (i - 1); 
Mp = 80 + 3 * (i - 1); 
MpMax = 80 + 3 * (i - 1); 
Ap = 25 + 4 * (i - 1); 
Dp = 25 + 4 * (i - 1); 
speed = 25 + 2 * (i - 1); 
LV = i; 
death = 0; 
EXP = 0; 
bag.NumHeal = i * 5; 
bag.NumMgWorter = i * 5; 
} 
bool attack(player &p);//剑士的普通攻击 
bool TSattack(player &p);//特殊攻击 
void IsLvUp();//判断下是否升级 
void AI(player &p);//规定了电脑只能是剑士..当然~如果要电脑是其他角色就要写多点代码~可惜我比较懒.. 
}; 

bool Swordsman::attack(player &p) 
{ 
int Hphit; 
int EXPhit; 
cout << name << "攻击" << endl; 
srand(time(NULL)); 
int j = rand()%100; 
if (speed >= p.speed && j <= 25) 
{ 
cout << "挥着大剑向敌人砍去" << endl; 
cout << "会心一击" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << "直接命中敌人脑门,顿时鲜血四溅" << endl; 
cout << "敌人损失Hp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name <<"获得经验 " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else if(speed <= p.speed && (j >25 || j <=50) ) 
{ 
cout << "拿着剑摇摇晃晃的朝敌人砍去。。。" << endl; 
cout << "敌人躲避" << endl; 
return true; 
} 
else if(j < 100 && j > 50) 
{ 
cout << "挥剑向敌人砍去" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 5 - p.Dp) + 2 * (LV - 1); 
cout << "命中敌人" << endl; 
cout << "敌人损失Hp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name << "获得EXP " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else 
return false; 
} 
bool Swordsman::TSattack(player &p 

) 
{ 
srand( time(NULL) ); 
int j = rand()%100; 
int Hphit; 
int EXPhit; 
if ( Mp >= 50 ) 
{ 
cout << "万剑诀" << endl; 
Mp -= 40; 
if (j <= 49 || j >= 60) 
{ 
cout << "完全命中目标 " << endl; 
cout << "敌人完全吸收了伤害" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j/10 + 10 - p.Dp) * 3 + 2 * ( LV -1); 
cout << "敌人损失Hp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << "获得EXP " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else 
{ 
cout << "敌人无意中的躲避, 躲开攻击" << endl; 
cout << "攻击无效" << endl; 
return true; 
} 
} 
else 
{ 
cout << "魔法不足! " << endl; 
return false; 
} 
} 
void Swordsman::IsLvUp() 
{ 
if (EXP >= LV * LV * 75) 
{ 
EXP -= LV * LV * 75; 
++LV; 
HpMax = 150 + 8 * (LV -1); 
MpMax = 80 + 3 * (LV -1); 
Ap += 3; 
Dp += 3; 
speed += 4; 
cout << " 恭喜，"<< name <<"升级了~~ " << " 等级为" << LV << endl; 
} 
} 
void Swordsman::AI(player &p) 
{ 
int Hphit; 
srand( time(NULL) ); 
int j = rand()%100; 
if (Hp <= 70 && j <=90 && !bag.IsNumHealEmpoty() ) 
{ 
cout << "敌人使用了回复剂,体力恢复了100点 " << endl; 
Hp +=100; 
bag.NumHeal --; 
if ( Hp > HpMax ) 
{ 
Hp = HpMax; 
} 
} 
else if ( (Mp>=50 && j<=80) || (p.Hp<=75 && Mp>=50 && j<=50) ) 
{ 
cout << "敌人的特殊攻击(还没想好- -！) " << endl; 
Mp -= 40; 
if ( speed <= p.speed && (j >= 20 || j <= 30) ) 
{ 
cout << p.name << "无意中的走位 " << endl; 
cout << p.name << "躲开了敌人攻击无效 " << endl; 
} 
else 
{ 
cout << p.name << "受到猛烈冲击 " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << p.name << "损失Hp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
else if (Mp < 50 && j <=40 && !bag.IsMWEmpoty() ) 
{ 
cout << "敌人使用魔法剂，魔法值恢复了80点~ " << endl; 
Mp += 80; 
bag.NumMgWorter --; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
} 
else 
{ 
cout << "敌人的普通攻击 " << endl; 
if ( j <= 25 && speed <= p.speed ) 
{ 
cout << p.name << " 躲开攻击 " << endl; 
} 
else 
{ 
cout << p.name <<"受到伤害 " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) + (LV - 1); 
cout << "损失Hp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
} 

class Archer:public player//差不多拉~只是数值和绝招要改改~其他的没什么了~只是少了个AI电脑智能函数 
{ 
public: 
Archer(int i, char *chname) 
{ 
role = ar; 
int j; 
for (j=0; j<10; j++) 
{ 
name[j] = chname[j]; 
} 
Hp = 150 + 8 * (i - 1); 
HpMax = 150 + 8 * (i - 1); 
Mp = 80 + 3 * (i - 1); 
MpMax = 80 + 3 * (i - 1); 
Ap = 25 + 4 * (i - 1); 
Dp = 25 + 4 * (i - 1); 
speed = 25 + 2 * (i - 1); 
LV = i; 
death = 0; 
EXP = LV * LV * 75; 
bag. 





下载文档到电脑，使用更方便
1下载券
下载VIP免费下载

享专业文档下载特权赠共享文档下载特权100W篇文档免费专享
还剩3页未读， 继续阅读 






12
9

分享到：
QQ空间
新浪微博
微信
/6
1下载券立即下载 
加入VIP
免费下载
定制新服务
热门
免费送

客户端

极速收纳
新版
反馈


你可能喜欢
僵尸网游 植物大战僵尸ol小游... c编程实现植物大战僵... 植物大战僵尸迷你游戏... 植物大战僵尸修改器源... 植物大战僵尸源代码 实现植物大战僵尸源代... 
 

僵尸电影 
3.6 分 210人阅读 
 

僵尸真菌 
2.6 分 37人阅读 
 

恶魔不要啊融入网游模式 打僵尸告别单机 
0.0 分 20人阅读 
 

僵尸网络 
5.0 分 3309人阅读 
 

僵尸卡 
3.3 分 22人阅读 
 

网游之僵尸天下 
0.0 分 8人阅读 
更多与“僵尸网游”相关的内容>> 
您的评论 
 
240
发布评论
用户评价(2) 
2017-09-26
回复 (0) 
 
风云起惜云飞扬 
编译不过，还得自己改
2016-12-08
回复 (0) 
 
取名字难到爆炸 
有错啊




?2018 Baidu | 由 百度云 提供计算服务 | 使用百度前必读 | 文库协议 | 广告服务 | 企业文库 | 网站地图 



 1 


     在手机打开 

内容定制新玩法！
下载
1 下载券


选择内容扫一扫
立即发送到手机
×

VIP享无限制发送特权

以下结果由提供：
×

百度翻译

百科词条：
×

百度百科

 


复制 | 发送到手机 | 搜索 | 翻译


文字已复制百度首页
登录 
加入文库VIP 
意见反馈
下载客户端
网页 新闻 贴吧 知道 音乐 图片 视频 地图 文库 | 
 


首页
分类

精品内容 

名师招募

 
机构合作 

频道专区 

云知识 


文库VIP   

个人中心 

百度文库
专业资料
IT/计算机
计算机软件及应用
上传文档 





相关文档推荐 

www.baidu.com搜索推荐
c++实现简单rpg对战代码... 
11页 

C的几个简单代码 
4页 

c语言实现的简单计算器代... 
8页 

C语言简单贪吃蛇游戏代码... 
4页 

喜欢此文档的还喜欢
C语言 简单计算器程序 源... 
2页 
简单易懂的C语言源代码(... 
13页 
C语言必背18个经典程序 
10页 
简单的迷宫小游戏 C语言... 
2页 
c语言程序代码 
23页 
猜你喜欢





加入文库VIP
获取下载特权 >
c++实现简单RPG对战游戏的代码 
qopas |2018-06-26 | 5.0分(高于99%的文档)|12949|183 |简介 | 举报    手机打开


VIP免费文档 


#include<iostream.h> 
#include<time.h> 
#include<stdlib.h> 
enum propte {sw,ar,mg}; 
class container//人物的小包裹,用来装东西的....目前只装两种物品~有兴趣的可以自己加点东西进去`嘿嘿~ 
{ 
friend class player;//定义一个基类 
friend class Swordsman;//定义一个剑士 
friend class Archer;//定义一个弓剑手 
friend class Mage;//定义一个魔法师,其实我们以前玩的都是这样做的~只要把这些类附给一个人物身上就行了 
friend void ShowWindows(player &p1,player &p2);//显示框框~当前状态的函数 
protected: 
int NumHeal;//生命回复剂 
int NumMgWorter;//魔法恢复剂 
public: 
container ();//构造函数,....目前可有可无的样子~~ 
bool IsNumHealEmpoty();//判断还有没有生命恢复剂 
bool IsMWEmpoty();//判断还有没有魔法恢复剂 
void display();//显示当前还有多少魔法恢复剂和生命恢复剂 
}; 
container::container() 
{ 
NumHeal = 0; 
NumMgWorter = 0; 
} 
bool container::IsNumHealEmpoty() 
{ 
return NumHeal == 0?true:false; 
} 
bool container::IsMWEmpoty() 
{ 
return NumMgWorter == 0?true:false; 
} 
void container::display() 
{ 
cout << "还剩下回复剂（HP+100） " << NumHeal << "个" << endl; 
cout << "还剩下魔法剂 (MP+80) " << NumMgWorter << "个" << endl; 
} 


class player//人物的基类 
{ 
friend class Swordsman; 
friend class Archer; 
friend class Mage;//这些都是朋友关系~又是父与子的关系~- -! 好象有点复杂的样子~ 
friend void ShowWindows(player &p1,player &p2);//上面已经说过了~不再重复 

protected: 
int Hp,HpMax,Mp,MpMax,speed,Ap,Dp,EXP,LV;//最大血量和最大魔法值,当前血量,魔法值,等等~望文生意 
char name[10];//人物名称 
propte role;//人物职业类型 
bool death ;//是否死亡函数 
container bag;//人物的小包包~~^^ 
public: 
void IsDead();//判断人物是否死亡 
bool Dead();//确认人物当前死亡状态~有返回值哦~ 
bool UseHeal();//好累...不过还是继续打字~ 使用生命回复剂 
bool UseMW();//....跟上面差不多~ 
void Getbag(player &p);//如果电脑死亡....就拿走他的小包包里面的东西~ 
void Shourole();//显示当前人物的职业~....这个是额外的函数~乱写的~ 
void HpMpfull();//每打完一关敌人~HP,MP全满~ 
virtual bool attack(player &p) = 0; 
virtual bool TSattack(player &p) = 0; 
virtual void IsLvUp() = 0;//上面三个都是纯虚函数~分别代表 人物的普通攻击~特殊攻击和是否升级 
}; 

void player::HpMpfull() 
{ 
Hp = HpMax; 
Mp = MpMax; 
} 
void player::IsDead() 
{ 
if (Hp <= 0 ) 
{ 
death = 1; 
} 
} 
bool player::Dead() 
{ 
return death == 1? true:false; 
} 
bool player::UseHeal() 
{ 
if ( !bag.IsNumHealEmpoty() ) 
{ 
Hp +=100; 
bag.NumHeal --; 
cout << name << "使用了恢复剂，生命值恢复了100点" << endl; 
if (Hp > HpMax) 
{ 
Hp = HpMax; 
} 
return true; 
} 
else 
{ 
co 

ut << "没有回复剂了 " << endl; 
return false; 
} 
} 
bool player::UseMW() 
{ 
if ( !bag.IsMWEmpoty() ) 
{ 
Mp += 80; 
bag.NumMgWorter --; 
cout << name << "使用了魔法恢复剂，魔法值恢复了80点" << endl; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
return true; 
} 
else 
{ 
cout << "没有魔法恢复剂了~" << endl; 
return false; 
} 
} 
void player::Getbag(player &p) 
{ 
cout << name << "获得了对方物品" << endl; 
cout << "获得了回复剂 " << p.bag.NumHeal << "个" << endl; 
cout << "获得了魔法回复剂 " << p.bag.NumMgWorter << "个" << endl; 
bag.NumHeal += p.bag.NumHeal; 
bag.NumMgWorter += p.bag.NumMgWorter; 
} 
void player::Shourole() 
{ 
switch(role) 
{ 
case sw: 
cout << "职业：剑士" << endl; 
break; 
case ar: 
cout << "职业：弓箭手" << endl; 
break; 
case mg: 
cout << "职业：魔法师" << endl; 
break; 
} 
} 

class Swordsman:public player//从基类派生出的一个类,是关于剑士的~ 
{ 

public: 
Swordsman(int i, char *chname)//构造函数~赋予当前人物的属性值 
{ 
role = sw; 
int j; 
for (j=0; j<10; j++) 
{ 
name[j] = chname[j]; 
} 
Hp = 150 + 8 * (i - 1); 
HpMax = 150 + 8 * (i - 1); 
Mp = 80 + 3 * (i - 1); 
MpMax = 80 + 3 * (i - 1); 
Ap = 25 + 4 * (i - 1); 
Dp = 25 + 4 * (i - 1); 
speed = 25 + 2 * (i - 1); 
LV = i; 
death = 0; 
EXP = 0; 
bag.NumHeal = i * 5; 
bag.NumMgWorter = i * 5; 
} 
bool attack(player &p);//剑士的普通攻击 
bool TSattack(player &p);//特殊攻击 
void IsLvUp();//判断下是否升级 
void AI(player &p);//规定了电脑只能是剑士..当然~如果要电脑是其他角色就要写多点代码~可惜我比较懒.. 
}; 

bool Swordsman::attack(player &p) 
{ 
int Hphit; 
int EXPhit; 
cout << name << "攻击" << endl; 
srand(time(NULL)); 
int j = rand()%100; 
if (speed >= p.speed && j <= 25) 
{ 
cout << "挥着大剑向敌人砍去" << endl; 
cout << "会心一击" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << "直接命中敌人脑门,顿时鲜血四溅" << endl; 
cout << "敌人损失Hp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name <<"获得经验 " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else if(speed <= p.speed && (j >25 || j <=50) ) 
{ 
cout << "拿着剑摇摇晃晃的朝敌人砍去。。。" << endl; 
cout << "敌人躲避" << endl; 
return true; 
} 
else if(j < 100 && j > 50) 
{ 
cout << "挥剑向敌人砍去" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 5 - p.Dp) + 2 * (LV - 1); 
cout << "命中敌人" << endl; 
cout << "敌人损失Hp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name << "获得EXP " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else 
return false; 
} 
bool Swordsman::TSattack(player &p 

) 
{ 
srand( time(NULL) ); 
int j = rand()%100; 
int Hphit; 
int EXPhit; 
if ( Mp >= 50 ) 
{ 
cout << "万剑诀" << endl; 
Mp -= 40; 
if (j <= 49 || j >= 60) 
{ 
cout << "完全命中目标 " << endl; 
cout << "敌人完全吸收了伤害" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j/10 + 10 - p.Dp) * 3 + 2 * ( LV -1); 
cout << "敌人损失Hp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << "获得EXP " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else 
{ 
cout << "敌人无意中的躲避, 躲开攻击" << endl; 
cout << "攻击无效" << endl; 
return true; 
} 
} 
else 
{ 
cout << "魔法不足! " << endl; 
return false; 
} 
} 
void Swordsman::IsLvUp() 
{ 
if (EXP >= LV * LV * 75) 
{ 
EXP -= LV * LV * 75; 
++LV; 
HpMax = 150 + 8 * (LV -1); 
MpMax = 80 + 3 * (LV -1); 
Ap += 3; 
Dp += 3; 
speed += 4; 
cout << " 恭喜，"<< name <<"升级了~~ " << " 等级为" << LV << endl; 
} 
} 
void Swordsman::AI(player &p) 
{ 
int Hphit; 
srand( time(NULL) ); 
int j = rand()%100; 
if (Hp <= 70 && j <=90 && !bag.IsNumHealEmpoty() ) 
{ 
cout << "敌人使用了回复剂,体力恢复了100点 " << endl; 
Hp +=100; 
bag.NumHeal --; 
if ( Hp > HpMax ) 
{ 
Hp = HpMax; 
} 
} 
else if ( (Mp>=50 && j<=80) || (p.Hp<=75 && Mp>=50 && j<=50) ) 
{ 
cout << "敌人的特殊攻击(还没想好- -！) " << endl; 
Mp -= 40; 
if ( speed <= p.speed && (j >= 20 || j <= 30) ) 
{ 
cout << p.name << "无意中的走位 " << endl; 
cout << p.name << "躲开了敌人攻击无效 " << endl; 
} 
else 
{ 
cout << p.name << "受到猛烈冲击 " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << p.name << "损失Hp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
else if (Mp < 50 && j <=40 && !bag.IsMWEmpoty() ) 
{ 
cout << "敌人使用魔法剂，魔法值恢复了80点~ " << endl; 
Mp += 80; 
bag.NumMgWorter --; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
} 
else 
{ 
cout << "敌人的普通攻击 " << endl; 
if ( j <= 25 && speed <= p.speed ) 
{ 
cout << p.name << " 躲开攻击 " << endl; 
} 
else 
{ 
cout << p.name <<"受到伤害 " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) + (LV - 1); 
cout << "损失Hp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
} 

class Archer:public player//差不多拉~只是数值和绝招要改改~其他的没什么了~只是少了个AI电脑智能函数 
{ 
public: 
Archer(int i, char *chname) 
{ 
role = ar; 
int j; 
for (j=0; j<10; j++) 
{ 
name[j] = chname[j]; 
} 
Hp = 150 + 8 * (i - 1); 
HpMax = 150 + 8 * (i - 1); 
Mp = 80 + 3 * (i - 1); 
MpMax = 80 + 3 * (i - 1); 
Ap = 25 + 4 * (i - 1); 
Dp = 25 + 4 * (i - 1); 
speed = 25 + 2 * (i - 1); 
LV = i; 
death = 0; 
EXP = LV * LV * 75; 
bag. 



