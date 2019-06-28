#include<iostream>
#include<string.h>
#include <fstream>
using namespace std;
void ShowStu();//显示所有学生 
void ShowMenu();//显示菜单 
void choice();//菜单功能 
void add();//添加学生 
void DeleteStu();//删除学生 
void ModifyStu();//修改学生 
void search();//查询学生 
void countA();//根据平均成绩降序 
void countB();//列出平均成绩 
void countC();//列出不及格学生 


int num,n,s;

//学生类 
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
			cout<<"学号"<<schoolnum<<"   ";
			cout<<"姓名"<<name<<"   ";
			cout<<"性别"<<sex<<"   ";
			cout<<"班级"<<Class<<"   ";
			cout<<"语文成绩"<<chinese<<"   ";
			cout<<"数学成绩"<<math<<"   ";
			cout<<"英语成绩"<<english<<"   ";
			cout<<"数据库成绩"<<database<<"   ";
			cout<<"平均成绩"<<average<<"   "<<endl;
		}
	
		stu(){
			schoolnum=0;
	
		}
		
};
stu ss[3000];


//录入学生信息 
void add(){
	
	cout<<"请输入学号"<<endl; 
	cin>>ss[num].schoolnum;
		cout<<"请输入名字"<<endl; 
	cin>>ss[num].name;
		cout<<"请输入性别"<<endl; 
	cin>>ss[num].sex;
		cout<<"请输入班级"<<endl; 
	cin>>ss[num].Class;
		cout<<"请输入语文成绩"<<endl; 
	cin>>ss[num].chinese;
		cout<<"请输入数学成绩"<<endl; 
	cin>>ss[num].math;
		cout<<"请输入英语成绩"<<endl; 
	cin>>ss[num].english;
		cout<<"请输入数据库成绩"<<endl; 
	cin>>ss[num].database;
	ss[num].average=(ss[num].chinese+ss[num].math+ss[num].english+ss[num].database)/4;
	num++;
}



//查询学生
void search(){
	cout<<"请输入要查找的学号"<<endl;
	cin>>s; 
	int count2=0;
	for(;count2<num;count2++){
		if(ss[n].schoolnum==s){
			cout<<"此学生信息为"; 
			ss[n].Show();
			n=0;
			break;
		}
		n++;
		
	}
	if(count2==num){
		cout<<"未找到"<<endl;
		n=0; 
	}
	
} 



//删除学生 
void DeleteStu(){
	char yn;
	cout<<"请输入您要删除的学生的学号"<<endl;
	cin>>s; 
	int count1=0;
	for(;count1<num;count1++){
					if(ss[n].schoolnum==s){
						cout<<"此学生信息为"; 
						ss[n].Show();
						
													for(;1;){
													
														cout<<"确定删除吗？（Y/N）"<<endl; 
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
																cout<<"输入错误，请输入y/n"<<endl;
															}
													}
					}
					else if(count1==num){
						cout<<"未找到此学生"<<endl; 
						n=0;
					}
					else {
					n++;
					}
				
	}
}

//显示所有学生成绩
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

//排序并显示
void countA(){
											//冒泡排序 
										    for (int i = 0; i<num-1; i++) { 
										        for (int j = 0; j<num-i-1;j++) {  
										            if (ss[j].average<ss[j + 1].average) {
										            
										                char temp[10];
										            	//交换姓名 
										                strcpy(temp, ss[j].name);
										                strcpy(ss[j].name,ss[j+1].name);
										                strcpy(ss[j+1].name,temp);
										                //交换性别 
														strcpy(temp, ss[j].sex);
										                strcpy(ss[j].sex,ss[j+1].sex);
										                strcpy(ss[j+1].sex,temp);
														//交换班级 
														strcpy(temp, ss[j].Class);
										                strcpy(ss[j].Class,ss[j+1].Class);
										                strcpy(ss[j+1].Class,temp);
										                //交换学号 
														ss[j].schoolnum += ss[j + 1].schoolnum;
														ss[j + 1].schoolnum = ss[j].schoolnum - ss[j + 1].schoolnum;
														ss[j].schoolnum -= ss[j + 1].schoolnum;
														//交换语文成绩 
										                ss[j].chinese += ss[j + 1].chinese;
														ss[j + 1].chinese = ss[j].chinese - ss[j + 1].chinese;
														ss[j].chinese -= ss[j + 1].chinese;
														//交换数学成绩 
										                ss[j].math += ss[j + 1].math;
														ss[j + 1].math = ss[j].math - ss[j + 1].math;
														ss[j].math -= ss[j + 1].math;
														//交换英语成绩 
										                ss[j].english += ss[j + 1].english;
														ss[j + 1].english = ss[j].english - ss[j + 1].english;
														ss[j].english -= ss[j + 1].english;
														//交换数据库成绩 
										                ss[j].database += ss[j + 1].database;
														ss[j + 1].database = ss[j].database - ss[j + 1].database;
														ss[j].database -= ss[j + 1].database;
														//交换平均成绩 
														ss[j].average += ss[j + 1].average;
														ss[j + 1].average = ss[j].average - ss[j + 1].average;
														ss[j].average -= ss[j + 1].average;

										            }
										        }
										    }
	ShowStu();
} 

//平均成绩 
void countB(){
				//语文 
				double ChineseAve;
				int timesC=0;
						//相加 
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
				cout<<"所有学生语文平均成绩:"<<ChineseAve<<endl;
				//数学 
				double MathAve;
				int timesM=0;
						//相加 
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
				cout<<"所有学生数学平均成绩:"<<MathAve<<endl;
				//英语 
				double EnglishAve;
				int timesE=0;
						//相加 
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
				cout<<"所有学生英语平均成绩:"<<EnglishAve<<endl;
				
				double DataBaseAve;
				int timesD=0;
						//相加 
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
				cout<<"所有学生数据库平均成绩:"<<DataBaseAve<<endl;
					
}






// 不及格学生统计
void countC(){
	//语文不及格学生
	cout<<"语文不及格的学生有："<<endl; 
	 int timesCN=0;
						//相加 
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
	cout<<"语文不及格共计"<<timesCN<<"人"<<endl; 
	cout<<endl;
 

	cout<<"数学不及格的学生有："<<endl; 
	 int timesMN=0;
						//相加 
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
	cout<<"数学不及格共计"<<timesMN<<"人"<<endl; 
	cout<<endl;
 


	cout<<"英语不及格的学生有："<<endl; 
	 int timesEN=0;
						//相加 
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
	cout<<"英语不及格共计"<<timesEN<<"人"<<endl; 
	cout<<endl;
 


	cout<<"数据库不及格的学生有："<<endl; 
	 int timesDN=0;
						//相加 
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
	cout<<"数据库不及格共计"<<timesDN<<"人"<<endl; 
	cout<<endl;
} 






//修改学生信息
 void ModifyStu(){
	cout<<"请输入您要修改的学生的学号"<<endl;
	cin>>s; 
	int count1=0;
	char YN; 
	for(;count1<num;count1++){
					if(ss[n].schoolnum==s){
						cout<<"此学生信息为"; 
						ss[n].Show();
						cout<<"您确定要修改吗？(Y/N)"<<endl; 
						cin>>YN;
															if(YN=='y'||YN=='Y'){
																cout<<"请输入修改后的学号"<<endl;
																cin>>ss[n].schoolnum; 
																cout<<"请输入修改后的姓名"<<endl; 
																cin>>ss[n].name;
																cout<<"请输入修改后的性别"<<endl; 
																cin>>ss[n].sex;
																cout<<"请输入修改后的班级"<<endl;
																cin>>ss[n].Class;
																cout<<"请输入修改后的语文成绩"<<endl;
																cin>>ss[n].chinese;
																cout<<"请输入修改后数学成绩"<<endl;
																cin>>ss[n].math;
																cout<<"请输入修改后的英语成绩"<<endl;
																cin>>ss[n].english;
																cout<<"请输入修改后的数据库成绩"<<endl;
																cin>>ss[n].database;
															}
					
					}
					else if(count1==num){
						cout<<"未找到此学生"<<endl; 
						n=0;
					}
					else {
					n++;
					}
				
	}
	n=0;
}


//界面 
void ShowMenu(){
  cout<<"********************************************************************************"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          2.删除学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          3.显示所有成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          4.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          5.按学号查找学生成绩  ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          6.降序学生平均成绩    ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          7.输出学生平均成绩    ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          8.列出不及格学生      ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          0.安全退出系统        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
 cout<<"————————————————————————————————————请选择功能"<<endl;
}




//选择功能 
void choice(){
	int x;
	char pb ;
	cin>>x;
	switch(x) {
		case 0:cout<<"退出"<<endl;
		exit(0);
		break;
		case 1:cout<<"增加学生"<<endl;
		add();
									for(;1;){
												cout<<"是否要继续添加？(Y/N)" <<endl; 
														cin>>pb;
															if(pb=='y'||pb=='Y'){
															add();
															} 
															else{
																break;
															}
											}
															
		break;
		case 2:cout<<"删除学生信息"<<endl;
		DeleteStu();
		break;
		case 3:cout<<"显示所有学生"<<endl; 
		ShowStu();
		break;
		case 4:cout<<"修改学生信息"<<endl;
		ModifyStu(); 
		break; 
		case 5:cout<<"按学号查找学生"<<endl; 
		search();
		break;
		case 6:cout<<"降序"<<endl;
		countA(); 
		break;
		case 7:cout<<"平均"<<endl; 
		countB();
		break;
		case 8:cout<<"不及格"<<endl; 
		countC();
		break;
		default:cout<<"无效指令，请重新输入"<<endl; 
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


//改进；修改，默认值,添加的时候有学号重复，int判断； 
//待做；储存。 
