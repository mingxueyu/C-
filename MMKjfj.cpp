�ٶ���ҳ
��¼ 
�����Ŀ�VIP 
�������
���ؿͻ���
��ҳ ���� ���� ֪�� ���� ͼƬ ��Ƶ ��ͼ �Ŀ� | 
 


��ҳ
����

��Ʒ���� 

��ʦ��ļ

 
�������� 

Ƶ��ר�� 

��֪ʶ 
�H

�Ŀ�VIP   

�������� 

�ٶ��Ŀ�
רҵ����
IT/�����
����������Ӧ��
�ϴ��ĵ� 





����ĵ��Ƽ� 

www.baidu.com�����Ƽ�
c++ʵ�ּ�rpg��ս����... 
11ҳ 

C�ļ����򵥴��� 
4ҳ 

c����ʵ�ֵļ򵥼�������... 
8ҳ 

C���Լ�̰������Ϸ����... 
4ҳ 

ϲ�����ĵ��Ļ�ϲ��
C���� �򵥼��������� Դ... 
2ҳ 
���׶���C����Դ����(... 
13ҳ 
C���Աر�18��������� 
10ҳ 
�򵥵��Թ�С��Ϸ C����... 
2ҳ 
c���Գ������ 
23ҳ 
����ϲ��





�����Ŀ�VIP
��ȡ������Ȩ >
c++ʵ�ּ�RPG��ս��Ϸ�Ĵ��� 
qopas |2018-06-26 | 5.0��(����99%���ĵ�)|12949|183 |��� | �ٱ�    �{�ֻ���


VIP����ĵ� 


#include<iostream.h> 
#include<time.h> 
#include<stdlib.h> 
enum propte {sw,ar,mg}; 
class container//�����С����,����װ������....Ŀǰֻװ������Ʒ~����Ȥ�Ŀ����Լ��ӵ㶫����ȥ`�ٺ�~ 
{ 
friend class player;//����һ������ 
friend class Swordsman;//����һ����ʿ 
friend class Archer;//����һ�������� 
friend class Mage;//����һ��ħ��ʦ,��ʵ������ǰ��Ķ�����������~ֻҪ����Щ�฽��һ���������Ͼ����� 
friend void ShowWindows(player &p1,player &p2);//��ʾ���~��ǰ״̬�ĺ��� 
protected: 
int NumHeal;//�����ظ��� 
int NumMgWorter;//ħ���ָ��� 
public: 
container ();//���캯��,....Ŀǰ���п��޵�����~~ 
bool IsNumHealEmpoty();//�жϻ���û�������ָ��� 
bool IsMWEmpoty();//�жϻ���û��ħ���ָ��� 
void display();//��ʾ��ǰ���ж���ħ���ָ����������ָ��� 
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
cout << "��ʣ�»ظ�����HP+100�� " << NumHeal << "��" << endl; 
cout << "��ʣ��ħ���� (MP+80) " << NumMgWorter << "��" << endl; 
} 


class player//����Ļ��� 
{ 
friend class Swordsman; 
friend class Archer; 
friend class Mage;//��Щ�������ѹ�ϵ~���Ǹ����ӵĹ�ϵ~- -! �����е㸴�ӵ�����~ 
friend void ShowWindows(player &p1,player &p2);//�����Ѿ�˵����~�����ظ� 

protected: 
int Hp,HpMax,Mp,MpMax,speed,Ap,Dp,EXP,LV;//���Ѫ�������ħ��ֵ,��ǰѪ��,ħ��ֵ,�ȵ�~�������� 
char name[10];//�������� 
propte role;//����ְҵ���� 
bool death ;//�Ƿ��������� 
container bag;//�����С����~~^^ 
public: 
void IsDead();//�ж������Ƿ����� 
bool Dead();//ȷ�����ﵱǰ����״̬~�з���ֵŶ~ 
bool UseHeal();//����...�������Ǽ�������~ ʹ�������ظ��� 
bool UseMW();//....��������~ 
void Getbag(player &p);//�����������....����������С��������Ķ���~ 
void Shourole();//��ʾ��ǰ�����ְҵ~....����Ƕ���ĺ���~��д��~ 
void HpMpfull();//ÿ����һ�ص���~HP,MPȫ��~ 
virtual bool attack(player &p) = 0; 
virtual bool TSattack(player &p) = 0; 
virtual void IsLvUp() = 0;//�����������Ǵ��麯��~�ֱ���� �������ͨ����~���⹥�����Ƿ����� 
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
cout << name << "ʹ���˻ָ���������ֵ�ָ���100��" << endl; 
if (Hp > HpMax) 
{ 
Hp = HpMax; 
} 
return true; 
} 
else 
{ 
co 

ut << "û�лظ����� " << endl; 
return false; 
} 
} 
bool player::UseMW() 
{ 
if ( !bag.IsMWEmpoty() ) 
{ 
Mp += 80; 
bag.NumMgWorter --; 
cout << name << "ʹ����ħ���ָ�����ħ��ֵ�ָ���80��" << endl; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
return true; 
} 
else 
{ 
cout << "û��ħ���ָ�����~" << endl; 
return false; 
} 
} 
void player::Getbag(player &p) 
{ 
cout << name << "����˶Է���Ʒ" << endl; 
cout << "����˻ظ��� " << p.bag.NumHeal << "��" << endl; 
cout << "�����ħ���ظ��� " << p.bag.NumMgWorter << "��" << endl; 
bag.NumHeal += p.bag.NumHeal; 
bag.NumMgWorter += p.bag.NumMgWorter; 
} 
void player::Shourole() 
{ 
switch(role) 
{ 
case sw: 
cout << "ְҵ����ʿ" << endl; 
break; 
case ar: 
cout << "ְҵ��������" << endl; 
break; 
case mg: 
cout << "ְҵ��ħ��ʦ" << endl; 
break; 
} 
} 

class Swordsman:public player//�ӻ�����������һ����,�ǹ��ڽ�ʿ��~ 
{ 

public: 
Swordsman(int i, char *chname)//���캯��~���赱ǰ���������ֵ 
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
bool attack(player &p);//��ʿ����ͨ���� 
bool TSattack(player &p);//���⹥�� 
void IsLvUp();//�ж����Ƿ����� 
void AI(player &p);//�涨�˵���ֻ���ǽ�ʿ..��Ȼ~���Ҫ������������ɫ��Ҫд������~��ϧ�ұȽ���.. 
}; 

bool Swordsman::attack(player &p) 
{ 
int Hphit; 
int EXPhit; 
cout << name << "����" << endl; 
srand(time(NULL)); 
int j = rand()%100; 
if (speed >= p.speed && j <= 25) 
{ 
cout << "���Ŵ�����˿�ȥ" << endl; 
cout << "����һ��" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << "ֱ�����е�������,��ʱ��Ѫ�Ľ�" << endl; 
cout << "������ʧHp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name <<"��þ��� " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else if(speed <= p.speed && (j >25 || j <=50) ) 
{ 
cout << "���Ž�ҡҡ�λεĳ����˿�ȥ������" << endl; 
cout << "���˶��" << endl; 
return true; 
} 
else if(j < 100 && j > 50) 
{ 
cout << "�ӽ�����˿�ȥ" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 5 - p.Dp) + 2 * (LV - 1); 
cout << "���е���" << endl; 
cout << "������ʧHp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name << "���EXP " << EXP - EXPhit << endl; 
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
cout << "�򽣾�" << endl; 
Mp -= 40; 
if (j <= 49 || j >= 60) 
{ 
cout << "��ȫ����Ŀ�� " << endl; 
cout << "������ȫ�������˺�" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j/10 + 10 - p.Dp) * 3 + 2 * ( LV -1); 
cout << "������ʧHp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << "���EXP " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else 
{ 
cout << "���������еĶ��, �㿪����" << endl; 
cout << "������Ч" << endl; 
return true; 
} 
} 
else 
{ 
cout << "ħ������! " << endl; 
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
cout << " ��ϲ��"<< name <<"������~~ " << " �ȼ�Ϊ" << LV << endl; 
} 
} 
void Swordsman::AI(player &p) 
{ 
int Hphit; 
srand( time(NULL) ); 
int j = rand()%100; 
if (Hp <= 70 && j <=90 && !bag.IsNumHealEmpoty() ) 
{ 
cout << "����ʹ���˻ظ���,�����ָ���100�� " << endl; 
Hp +=100; 
bag.NumHeal --; 
if ( Hp > HpMax ) 
{ 
Hp = HpMax; 
} 
} 
else if ( (Mp>=50 && j<=80) || (p.Hp<=75 && Mp>=50 && j<=50) ) 
{ 
cout << "���˵����⹥��(��û���- -��) " << endl; 
Mp -= 40; 
if ( speed <= p.speed && (j >= 20 || j <= 30) ) 
{ 
cout << p.name << "�����е���λ " << endl; 
cout << p.name << "�㿪�˵��˹�����Ч " << endl; 
} 
else 
{ 
cout << p.name << "�ܵ����ҳ�� " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << p.name << "��ʧHp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
else if (Mp < 50 && j <=40 && !bag.IsMWEmpoty() ) 
{ 
cout << "����ʹ��ħ������ħ��ֵ�ָ���80��~ " << endl; 
Mp += 80; 
bag.NumMgWorter --; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
} 
else 
{ 
cout << "���˵���ͨ���� " << endl; 
if ( j <= 25 && speed <= p.speed ) 
{ 
cout << p.name << " �㿪���� " << endl; 
} 
else 
{ 
cout << p.name <<"�ܵ��˺� " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) + (LV - 1); 
cout << "��ʧHp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
} 

class Archer:public player//�����~ֻ����ֵ�;���Ҫ�ĸ�~������ûʲô��~ֻ�����˸�AI�������ܺ��� 
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





�����ĵ������ԣ�ʹ�ø�����
1����ȯ
����VIP�������

��רҵ�ĵ�������Ȩ�������ĵ�������Ȩ100Wƪ�ĵ����ר��
��ʣ3ҳδ���� �����Ķ� 






12
9

������
QQ�ռ�
����΢��
΢��
/6
1����ȯ�������� 
����VIP
�������
�����·���
����
�����

�ͻ���

��������
�°�
����


�����ϲ��
��ʬ���� ֲ���ս��ʬolС��... c���ʵ��ֲ���ս��... ֲ���ս��ʬ������Ϸ... ֲ���ս��ʬ�޸���Դ... ֲ���ս��ʬԴ���� ʵ��ֲ���ս��ʬԴ��... 
 

��ʬ��Ӱ 
3.6 �� 210���Ķ� 
 

��ʬ��� 
2.6 �� 37���Ķ� 
 

��ħ��Ҫ����������ģʽ ��ʬ��𵥻� 
0.0 �� 20���Ķ� 
 

��ʬ���� 
5.0 �� 3309���Ķ� 
 

��ʬ�� 
3.3 �� 22���Ķ� 
 

����֮��ʬ���� 
0.0 �� 8���Ķ� 
�����롰��ʬ���Ρ���ص�����>> 
�������� 
 
240
��������
�û�����(2) 
2017-09-26
�ظ� (0) 
 
������ϧ�Ʒ��� 
���벻���������Լ���
2016-12-08
�ظ� (0) 
 
ȡ�����ѵ���ը 
�д�




?2018 Baidu | �� �ٶ��� �ṩ������� | ʹ�ðٶ�ǰ�ض� | �Ŀ�Э�� | ������ | ��ҵ�Ŀ� | ��վ��ͼ 



 1 


    �{ ���ֻ��� 

���ݶ������淨��
������
1 ����ȯ


ѡ������ɨһɨ
�������͵��ֻ�
��

VIP�������Ʒ�����Ȩ

���½�����ṩ��
��

�ٶȷ���

�ٿƴ�����
��

�ٶȰٿ�

 


���� | ���͵��ֻ� | ���� | ����


�����Ѹ��ưٶ���ҳ
��¼ 
�����Ŀ�VIP 
�������
���ؿͻ���
��ҳ ���� ���� ֪�� ���� ͼƬ ��Ƶ ��ͼ �Ŀ� | 
 


��ҳ
����

��Ʒ���� 

��ʦ��ļ

 
�������� 

Ƶ��ר�� 

��֪ʶ 
�H

�Ŀ�VIP   

�������� 

�ٶ��Ŀ�
רҵ����
IT/�����
����������Ӧ��
�ϴ��ĵ� 





����ĵ��Ƽ� 

www.baidu.com�����Ƽ�
c++ʵ�ּ�rpg��ս����... 
11ҳ 

C�ļ����򵥴��� 
4ҳ 

c����ʵ�ֵļ򵥼�������... 
8ҳ 

C���Լ�̰������Ϸ����... 
4ҳ 

ϲ�����ĵ��Ļ�ϲ��
C���� �򵥼��������� Դ... 
2ҳ 
���׶���C����Դ����(... 
13ҳ 
C���Աر�18��������� 
10ҳ 
�򵥵��Թ�С��Ϸ C����... 
2ҳ 
c���Գ������ 
23ҳ 
����ϲ��





�����Ŀ�VIP
��ȡ������Ȩ >
c++ʵ�ּ�RPG��ս��Ϸ�Ĵ��� 
qopas |2018-06-26 | 5.0��(����99%���ĵ�)|12949|183 |��� | �ٱ�    �{�ֻ���


VIP����ĵ� 


#include<iostream.h> 
#include<time.h> 
#include<stdlib.h> 
enum propte {sw,ar,mg}; 
class container//�����С����,����װ������....Ŀǰֻװ������Ʒ~����Ȥ�Ŀ����Լ��ӵ㶫����ȥ`�ٺ�~ 
{ 
friend class player;//����һ������ 
friend class Swordsman;//����һ����ʿ 
friend class Archer;//����һ�������� 
friend class Mage;//����һ��ħ��ʦ,��ʵ������ǰ��Ķ�����������~ֻҪ����Щ�฽��һ���������Ͼ����� 
friend void ShowWindows(player &p1,player &p2);//��ʾ���~��ǰ״̬�ĺ��� 
protected: 
int NumHeal;//�����ظ��� 
int NumMgWorter;//ħ���ָ��� 
public: 
container ();//���캯��,....Ŀǰ���п��޵�����~~ 
bool IsNumHealEmpoty();//�жϻ���û�������ָ��� 
bool IsMWEmpoty();//�жϻ���û��ħ���ָ��� 
void display();//��ʾ��ǰ���ж���ħ���ָ����������ָ��� 
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
cout << "��ʣ�»ظ�����HP+100�� " << NumHeal << "��" << endl; 
cout << "��ʣ��ħ���� (MP+80) " << NumMgWorter << "��" << endl; 
} 


class player//����Ļ��� 
{ 
friend class Swordsman; 
friend class Archer; 
friend class Mage;//��Щ�������ѹ�ϵ~���Ǹ����ӵĹ�ϵ~- -! �����е㸴�ӵ�����~ 
friend void ShowWindows(player &p1,player &p2);//�����Ѿ�˵����~�����ظ� 

protected: 
int Hp,HpMax,Mp,MpMax,speed,Ap,Dp,EXP,LV;//���Ѫ�������ħ��ֵ,��ǰѪ��,ħ��ֵ,�ȵ�~�������� 
char name[10];//�������� 
propte role;//����ְҵ���� 
bool death ;//�Ƿ��������� 
container bag;//�����С����~~^^ 
public: 
void IsDead();//�ж������Ƿ����� 
bool Dead();//ȷ�����ﵱǰ����״̬~�з���ֵŶ~ 
bool UseHeal();//����...�������Ǽ�������~ ʹ�������ظ��� 
bool UseMW();//....��������~ 
void Getbag(player &p);//�����������....����������С��������Ķ���~ 
void Shourole();//��ʾ��ǰ�����ְҵ~....����Ƕ���ĺ���~��д��~ 
void HpMpfull();//ÿ����һ�ص���~HP,MPȫ��~ 
virtual bool attack(player &p) = 0; 
virtual bool TSattack(player &p) = 0; 
virtual void IsLvUp() = 0;//�����������Ǵ��麯��~�ֱ���� �������ͨ����~���⹥�����Ƿ����� 
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
cout << name << "ʹ���˻ָ���������ֵ�ָ���100��" << endl; 
if (Hp > HpMax) 
{ 
Hp = HpMax; 
} 
return true; 
} 
else 
{ 
co 

ut << "û�лظ����� " << endl; 
return false; 
} 
} 
bool player::UseMW() 
{ 
if ( !bag.IsMWEmpoty() ) 
{ 
Mp += 80; 
bag.NumMgWorter --; 
cout << name << "ʹ����ħ���ָ�����ħ��ֵ�ָ���80��" << endl; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
return true; 
} 
else 
{ 
cout << "û��ħ���ָ�����~" << endl; 
return false; 
} 
} 
void player::Getbag(player &p) 
{ 
cout << name << "����˶Է���Ʒ" << endl; 
cout << "����˻ظ��� " << p.bag.NumHeal << "��" << endl; 
cout << "�����ħ���ظ��� " << p.bag.NumMgWorter << "��" << endl; 
bag.NumHeal += p.bag.NumHeal; 
bag.NumMgWorter += p.bag.NumMgWorter; 
} 
void player::Shourole() 
{ 
switch(role) 
{ 
case sw: 
cout << "ְҵ����ʿ" << endl; 
break; 
case ar: 
cout << "ְҵ��������" << endl; 
break; 
case mg: 
cout << "ְҵ��ħ��ʦ" << endl; 
break; 
} 
} 

class Swordsman:public player//�ӻ�����������һ����,�ǹ��ڽ�ʿ��~ 
{ 

public: 
Swordsman(int i, char *chname)//���캯��~���赱ǰ���������ֵ 
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
bool attack(player &p);//��ʿ����ͨ���� 
bool TSattack(player &p);//���⹥�� 
void IsLvUp();//�ж����Ƿ����� 
void AI(player &p);//�涨�˵���ֻ���ǽ�ʿ..��Ȼ~���Ҫ������������ɫ��Ҫд������~��ϧ�ұȽ���.. 
}; 

bool Swordsman::attack(player &p) 
{ 
int Hphit; 
int EXPhit; 
cout << name << "����" << endl; 
srand(time(NULL)); 
int j = rand()%100; 
if (speed >= p.speed && j <= 25) 
{ 
cout << "���Ŵ�����˿�ȥ" << endl; 
cout << "����һ��" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << "ֱ�����е�������,��ʱ��Ѫ�Ľ�" << endl; 
cout << "������ʧHp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name <<"��þ��� " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else if(speed <= p.speed && (j >25 || j <=50) ) 
{ 
cout << "���Ž�ҡҡ�λεĳ����˿�ȥ������" << endl; 
cout << "���˶��" << endl; 
return true; 
} 
else if(j < 100 && j > 50) 
{ 
cout << "�ӽ�����˿�ȥ" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j%10 + 5 - p.Dp) + 2 * (LV - 1); 
cout << "���е���" << endl; 
cout << "������ʧHp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << name << "���EXP " << EXP - EXPhit << endl; 
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
cout << "�򽣾�" << endl; 
Mp -= 40; 
if (j <= 49 || j >= 60) 
{ 
cout << "��ȫ����Ŀ�� " << endl; 
cout << "������ȫ�������˺�" << endl; 
Hphit = p.Hp; 
p.Hp = p.Hp - (Ap + j/10 + 10 - p.Dp) * 3 + 2 * ( LV -1); 
cout << "������ʧHp " << Hphit - p.Hp << endl; 
EXPhit = EXP; 
EXP += Hphit - p.Hp; 
cout << "���EXP " << EXP - EXPhit << endl; 
p.IsDead(); 
return true; 
} 
else 
{ 
cout << "���������еĶ��, �㿪����" << endl; 
cout << "������Ч" << endl; 
return true; 
} 
} 
else 
{ 
cout << "ħ������! " << endl; 
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
cout << " ��ϲ��"<< name <<"������~~ " << " �ȼ�Ϊ" << LV << endl; 
} 
} 
void Swordsman::AI(player &p) 
{ 
int Hphit; 
srand( time(NULL) ); 
int j = rand()%100; 
if (Hp <= 70 && j <=90 && !bag.IsNumHealEmpoty() ) 
{ 
cout << "����ʹ���˻ظ���,�����ָ���100�� " << endl; 
Hp +=100; 
bag.NumHeal --; 
if ( Hp > HpMax ) 
{ 
Hp = HpMax; 
} 
} 
else if ( (Mp>=50 && j<=80) || (p.Hp<=75 && Mp>=50 && j<=50) ) 
{ 
cout << "���˵����⹥��(��û���- -��) " << endl; 
Mp -= 40; 
if ( speed <= p.speed && (j >= 20 || j <= 30) ) 
{ 
cout << p.name << "�����е���λ " << endl; 
cout << p.name << "�㿪�˵��˹�����Ч " << endl; 
} 
else 
{ 
cout << p.name << "�ܵ����ҳ�� " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) * 2 + 2 * (LV - 1); 
cout << p.name << "��ʧHp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
else if (Mp < 50 && j <=40 && !bag.IsMWEmpoty() ) 
{ 
cout << "����ʹ��ħ������ħ��ֵ�ָ���80��~ " << endl; 
Mp += 80; 
bag.NumMgWorter --; 
if (Mp > MpMax) 
{ 
Mp = MpMax; 
} 
} 
else 
{ 
cout << "���˵���ͨ���� " << endl; 
if ( j <= 25 && speed <= p.speed ) 
{ 
cout << p.name << " �㿪���� " << endl; 
} 
else 
{ 
cout << p.name <<"�ܵ��˺� " << endl; 
Hphit = p.Hp; 
p.Hp -= (Ap + j%10 + 10 - p.Dp) + (LV - 1); 
cout << "��ʧHp " << Hphit - p.Hp << endl; 
p.IsDead(); 
} 
} 
} 

class Archer:public player//�����~ֻ����ֵ�;���Ҫ�ĸ�~������ûʲô��~ֻ�����˸�AI�������ܺ��� 
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



