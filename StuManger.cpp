#include<iostream>
#include<string.h>
#include <fstream>
using namespace std;
void ShowStu();//��ʾ����ѧ�� 
void ShowMenu();//��ʾ�˵� 
void choice();//�˵����� 
void add();//���ѧ�� 
void DeleteStu();//ɾ��ѧ�� 
void ModifyStu();//�޸�ѧ�� 
void search();//��ѯѧ�� 
void countA();//����ƽ���ɼ����� 
void countB();//�г�ƽ���ɼ� 
void countC();//�г�������ѧ�� 


int num,n,s;

//ѧ���� 
class stu{
	public:
		int schoolnum;
		char name[10];
		char sex[10];
		char Class[10];
		double chinese;
		double math;
		double english;
		double database;
		double average;
		void Show(){
			cout<<"ѧ��"<<schoolnum<<"   ";
			cout<<"����"<<name<<"   ";
			cout<<"�Ա�"<<sex<<"   ";
			cout<<"�༶"<<Class<<"   ";
			cout<<"���ĳɼ�"<<chinese<<"   ";
			cout<<"��ѧ�ɼ�"<<math<<"   ";
			cout<<"Ӣ��ɼ�"<<english<<"   ";
			cout<<"���ݿ�ɼ�"<<database<<"   ";
			cout<<"ƽ���ɼ�"<<average<<"   "<<endl;
		}
	
		stu(){
			schoolnum=0;
	
		}
		
};
stu ss[3000];


//¼��ѧ����Ϣ 
void add(){
	
	cout<<"������ѧ��"<<endl; 
	cin>>ss[num].schoolnum;
		cout<<"����������"<<endl; 
	cin>>ss[num].name;
		cout<<"�������Ա�"<<endl; 
	cin>>ss[num].sex;
		cout<<"������༶"<<endl; 
	cin>>ss[num].Class;
		cout<<"���������ĳɼ�"<<endl; 
	cin>>ss[num].chinese;
		cout<<"��������ѧ�ɼ�"<<endl; 
	cin>>ss[num].math;
		cout<<"������Ӣ��ɼ�"<<endl; 
	cin>>ss[num].english;
		cout<<"���������ݿ�ɼ�"<<endl; 
	cin>>ss[num].database;
	ss[num].average=(ss[num].chinese+ss[num].math+ss[num].english+ss[num].database)/4;
	num++;
}



//��ѯѧ��
void search(){
	cout<<"������Ҫ���ҵ�ѧ��"<<endl;
	cin>>s; 
	int count2=0;
	for(;count2<num;count2++){
		if(ss[n].schoolnum==s){
			cout<<"��ѧ����ϢΪ"; 
			ss[n].Show();
			n=0;
			break;
		}
		n++;
		
	}
	if(count2==num){
		cout<<"δ�ҵ�"<<endl;
		n=0; 
	}
	
} 



//ɾ��ѧ�� 
void DeleteStu(){
	char yn;
	cout<<"��������Ҫɾ����ѧ����ѧ��"<<endl;
	cin>>s; 
	int count1=0;
	for(;count1<num;count1++){
					if(ss[n].schoolnum==s){
						cout<<"��ѧ����ϢΪ"; 
						ss[n].Show();
						
													for(;1;){
													
														cout<<"ȷ��ɾ���𣿣�Y/N��"<<endl; 
														cin>>yn;
															if(yn=='y'||yn=='Y'){
																ss[n].schoolnum=0;
																n=0;
																break; 
																break;
															}
															else if(yn=='n'||yn=='N'){
																n=0;
																break;
																break;
															}
															else if(yn!='n'||yn!='N'||yn!='y'||yn!='Y'){
																cout<<"�������������y/n"<<endl;
															}
													}
					}
					else if(count1==num){
						cout<<"δ�ҵ���ѧ��"<<endl; 
						n=0;
					}
					else {
					n++;
					}
				
	}
}

//��ʾ����ѧ���ɼ�
void ShowStu(){
	for(int count=1;count<=num;count++){
	
				if(ss[n].schoolnum!=0){	
					ss[n].Show();
					n++;
					}
				else{
					n++;
					}
	}
	n=0;
	
} 

//������ʾ
void countA(){
											//ð������ 
										    for (int i = 0; i<num-1; i++) { 
										        for (int j = 0; j<num-i-1;j++) {  
										            if (ss[j].average<ss[j + 1].average) {
										            
										                char temp[10];
										            	//�������� 
										                strcpy(temp, ss[j].name);
										                strcpy(ss[j].name,ss[j+1].name);
										                strcpy(ss[j+1].name,temp);
										                //�����Ա� 
														strcpy(temp, ss[j].sex);
										                strcpy(ss[j].sex,ss[j+1].sex);
										                strcpy(ss[j+1].sex,temp);
														//�����༶ 
														strcpy(temp, ss[j].Class);
										                strcpy(ss[j].Class,ss[j+1].Class);
										                strcpy(ss[j+1].Class,temp);
										                //����ѧ�� 
														ss[j].schoolnum += ss[j + 1].schoolnum;
														ss[j + 1].schoolnum = ss[j].schoolnum - ss[j + 1].schoolnum;
														ss[j].schoolnum -= ss[j + 1].schoolnum;
														//�������ĳɼ� 
										                ss[j].chinese += ss[j + 1].chinese;
														ss[j + 1].chinese = ss[j].chinese - ss[j + 1].chinese;
														ss[j].chinese -= ss[j + 1].chinese;
														//������ѧ�ɼ� 
										                ss[j].math += ss[j + 1].math;
														ss[j + 1].math = ss[j].math - ss[j + 1].math;
														ss[j].math -= ss[j + 1].math;
														//����Ӣ��ɼ� 
										                ss[j].english += ss[j + 1].english;
														ss[j + 1].english = ss[j].english - ss[j + 1].english;
														ss[j].english -= ss[j + 1].english;
														//�������ݿ�ɼ� 
										                ss[j].database += ss[j + 1].database;
														ss[j + 1].database = ss[j].database - ss[j + 1].database;
														ss[j].database -= ss[j + 1].database;
														//����ƽ���ɼ� 
														ss[j].average += ss[j + 1].average;
														ss[j + 1].average = ss[j].average - ss[j + 1].average;
														ss[j].average -= ss[j + 1].average;

										            }
										        }
										    }
	ShowStu();
} 

//ƽ���ɼ� 
void countB(){
				//���� 
				double ChineseAve;
				int timesC=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
							ChineseAve+=ss[n].chinese;
							timesC++;
							n++;
							}
							else{
							n++;
							}
						}
				ChineseAve=ChineseAve/timesC;
				n=0;
				cout<<"����ѧ������ƽ���ɼ�:"<<ChineseAve<<endl;
				//��ѧ 
				double MathAve;
				int timesM=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
							MathAve+=ss[n].math;
							timesM++;
							n++;
							}
							else{
							n++;
							}
						}
				MathAve=MathAve/timesM;
				n=0;
				cout<<"����ѧ����ѧƽ���ɼ�:"<<MathAve<<endl;
				//Ӣ�� 
				double EnglishAve;
				int timesE=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
							EnglishAve+=ss[n].english;
							timesE++;
							n++;
							}
							else{
							n++;
							}
						}
				EnglishAve=EnglishAve/timesE;
				n=0;
				cout<<"����ѧ��Ӣ��ƽ���ɼ�:"<<EnglishAve<<endl;
				
				double DataBaseAve;
				int timesD=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
							DataBaseAve+=ss[n].database;
							timesD++;
							n++;
							}
							else{
							n++;
							}
						}
				DataBaseAve=DataBaseAve/timesD;
				n=0;
				cout<<"����ѧ�����ݿ�ƽ���ɼ�:"<<DataBaseAve<<endl;
					
}






// ������ѧ��ͳ��
void countC(){
	//���Ĳ�����ѧ��
	cout<<"���Ĳ������ѧ���У�"<<endl; 
	 int timesCN=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
								if(ss[n].chinese<60){
									ss[n].Show();
									timesCN++;
								}
							
							n++;
							}
							else{
							n++;
							}
						}
	n=0;
	cout<<"���Ĳ����񹲼�"<<timesCN<<"��"<<endl; 
	cout<<endl;
 

	cout<<"��ѧ�������ѧ���У�"<<endl; 
	 int timesMN=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
								if(ss[n].math<60){
									ss[n].Show();
									timesMN++;
								}
							
							n++;
							}
							else{
							n++;
							}
						}
	n=0;
	cout<<"��ѧ�����񹲼�"<<timesMN<<"��"<<endl; 
	cout<<endl;
 


	cout<<"Ӣ�ﲻ�����ѧ���У�"<<endl; 
	 int timesEN=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
								if(ss[n].english<60){
									ss[n].Show();
									timesEN++;
								}
							
							n++;
							}
							else{
							n++;
							}
						}
	n=0;
	cout<<"Ӣ�ﲻ���񹲼�"<<timesEN<<"��"<<endl; 
	cout<<endl;
 


	cout<<"���ݿⲻ�����ѧ���У�"<<endl; 
	 int timesDN=0;
						//��� 
						for(int countc=0;countc<num;countc++){
							if(ss[n].schoolnum!=0){
								if(ss[n].database<60){
									ss[n].Show();
									timesDN++;
								}
							
							n++;
							}
							else{
							n++;
							}
						}
	n=0;
	cout<<"���ݿⲻ���񹲼�"<<timesDN<<"��"<<endl; 
	cout<<endl;
} 






//�޸�ѧ����Ϣ
 void ModifyStu(){
	cout<<"��������Ҫ�޸ĵ�ѧ����ѧ��"<<endl;
	cin>>s; 
	int count1=0;
	char YN; 
	for(;count1<num;count1++){
					if(ss[n].schoolnum==s){
						cout<<"��ѧ����ϢΪ"; 
						ss[n].Show();
						cout<<"��ȷ��Ҫ�޸���(Y/N)"<<endl; 
						cin>>YN;
															if(YN=='y'||YN=='Y'){
																cout<<"�������޸ĺ��ѧ��"<<endl;
																cin>>ss[n].schoolnum; 
																cout<<"�������޸ĺ������"<<endl; 
																cin>>ss[n].name;
																cout<<"�������޸ĺ���Ա�"<<endl; 
																cin>>ss[n].sex;
																cout<<"�������޸ĺ�İ༶"<<endl;
																cin>>ss[n].Class;
																cout<<"�������޸ĺ�����ĳɼ�"<<endl;
																cin>>ss[n].chinese;
																cout<<"�������޸ĺ���ѧ�ɼ�"<<endl;
																cin>>ss[n].math;
																cout<<"�������޸ĺ��Ӣ��ɼ�"<<endl;
																cin>>ss[n].english;
																cout<<"�������޸ĺ�����ݿ�ɼ�"<<endl;
																cin>>ss[n].database;
															}
					
					}
					else if(count1==num){
						cout<<"δ�ҵ���ѧ��"<<endl; 
						n=0;
					}
					else {
					n++;
					}
				
	}
	n=0;
}


//���� 
void ShowMenu(){
  cout<<"********************************************************************************"<<endl;
  cout<<"��������������������  ��   ѧ �� �� �� �� �� ϵ  ͳ     ��  ��������������������"<<endl;
  cout<<"��������������������         ��������         �������������������"<<endl;
  cout<<"��������������������  ��          1.����ѧ���ɼ�        ��  �������������������"<<endl;
  cout<<"��������������������  ��          2.ɾ��ѧ���ɼ�        ��  �������������������"<<endl;
  cout<<"��������������������  ��          3.��ʾ���гɼ�        ��  �������������������"<<endl;
  cout<<"��������������������  ��          4.�޸�ѧ����Ϣ        ��  �������������������"<<endl;
  cout<<"��������������������  ��          5.��ѧ�Ų���ѧ���ɼ�  ��  �������������������"<<endl;
  cout<<"��������������������  ��          6.����ѧ��ƽ���ɼ�    ��  �������������������"<<endl;
  cout<<"��������������������  ��          7.���ѧ��ƽ���ɼ�    ��  �������������������"<<endl;
  cout<<"��������������������  ��          8.�г�������ѧ��      ��  �������������������"<<endl;
  cout<<"��������������������  ��          0.��ȫ�˳�ϵͳ        ��  �������������������"<<endl;
 cout<<"��������������������������������������������������������������������������ѡ����"<<endl;
}




//ѡ���� 
void choice(){
	int x;
	char pb ;
	cin>>x;
	switch(x) {
		case 0:cout<<"�˳�"<<endl;
		exit(0);
		break;
		case 1:cout<<"����ѧ��"<<endl;
		add();
									for(;1;){
												cout<<"�Ƿ�Ҫ������ӣ�(Y/N)" <<endl; 
														cin>>pb;
															if(pb=='y'||pb=='Y'){
															add();
															} 
															else{
																break;
															}
											}
															
		break;
		case 2:cout<<"ɾ��ѧ����Ϣ"<<endl;
		DeleteStu();
		break;
		case 3:cout<<"��ʾ����ѧ��"<<endl; 
		ShowStu();
		break;
		case 4:cout<<"�޸�ѧ����Ϣ"<<endl;
		ModifyStu(); 
		break; 
		case 5:cout<<"��ѧ�Ų���ѧ��"<<endl; 
		search();
		break;
		case 6:cout<<"����"<<endl;
		countA(); 
		break;
		case 7:cout<<"ƽ��"<<endl; 
		countB();
		break;
		case 8:cout<<"������"<<endl; 
		countC();
		break;
		default:cout<<"��Чָ�����������"<<endl; 
		break;
	}
	//system("cls");
}

int main(){
	system("color 3F");
	int num=0;
	int n=0;
for(;1;){
	ShowMenu();
	choice();
}
	return 0;
}


//�Ľ����޸ģ�Ĭ��ֵ,��ӵ�ʱ����ѧ���ظ���int�жϣ� 
//���������档 
