#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#define MAX 1000

//设计联系人结构体
struct Person{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};


//设计通讯录结构体
struct Adressbooks{
    //通讯录中保存的联系人数组
    struct Person personArray[MAX];

    //通讯录中当前记录联系人个数
    int m_Size;
};

//1、添加联系人
void addPerson(struct Adressbooks* abs){
    if(abs->m_Size==MAX){
        cout<<"通讯录已满,无法添加"<<endl;
        return;
    }
    else{
        //添加具体联系人
        //姓名
        string name;
        cout<<"请输入姓名： "<<endl;
        cin>>name;
        abs->personArray[abs->m_Size].m_Name=name;

        //性别
        int sex=0;
        cout<<"请输入性别：　"<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(1){
            cin>>sex;
            if(sex==1||sex==2){
                abs->personArray[abs->m_Size].m_Sex=sex;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }
        
        //年龄
        cout<<"请输入年龄： "<<endl;
        int age=0;
        while(1){
            cin>>age;
            if(age>1 && age<150){
                abs->personArray[abs->m_Size].m_Age=age;
                break;
            }
            cout<<"输入有误，请重新输入"<<endl;
        }

        //联系电话
        cout<<"请输入联系电话"<<endl;
        string phone;
        cin>>phone;
        abs->personArray[abs->m_Size].m_Phone=phone;

        //家庭住址
        cout<<"请输入家庭住址"<<endl;
        string adress;
        cin>>adress;
        abs->personArray[abs->m_Size].m_Addr=adress;

        ++abs->m_Size;

        cout<<"添加成功！"<<endl;

        system("read -p 'Press Enter to continue...' var"); //请按任意键继续
        system("clear");  //清屏
    }
}

//2、显示所有联系人
void showPerson(struct Adressbooks* abs){
    if(abs->m_Size<1){
        cout<<"通讯录中没有联系人"<<endl;
        return;
    }
    else{
        for(int i=0;i<abs->m_Size;++i){
            cout<<"姓名： "<<abs->personArray[i].m_Name<<"\t";
            cout<<"性别： "<<(abs->personArray[i].m_Sex==1?"男":"女")<<"\t";
            cout<<"年龄： "<<abs->personArray[i].m_Age<<"\t";
            cout<<"电话： "<<abs->personArray[i].m_Phone<<"\t";
            cout<<"住址： "<<abs->personArray[i].m_Addr<<endl;
        }
    }
    system("read -p 'Press Enter to continue...' var"); //请按任意键继续
    system("clear");  //清屏
}

//检测联系人是否存在，存在返回具体位置，否则-1
int isExist(struct Adressbooks* abs,string name){
    for(int i=0;i<abs->m_Size;++i){
        if(abs->personArray[i].m_Name==name)
            return i;
    }
    return -1;
}

//3、删除联系人
void deletePerson(struct Adressbooks* abs){
    cout<<"请输入您要删除的联系人： "<<endl;
    string name;
    cin>>name;
    int res=isExist(abs,name);
    if(res!=-1){
        //if(res!=abs->m_Size-1){
            for(int i=res;i<abs->m_Size;++i){
                abs->personArray[i]=abs->personArray[i+1];
            }
            --abs->m_Size;
            cout<<"删除成功！"<<endl;
        //}
    }else{
        cout<<"查无此人"<<endl;
    }
    system("read -p 'Press Enter to continue...' var"); //请按任意键继续
    system("clear");  //清屏
}

//4、查找指定的联系人信息
void findPerson(struct Adressbooks* abs){
    cout<<"请输入您想要查找的联系人姓名： "<<endl;
    string name;
    cin>>name;
    int res=isExist(abs,name);
    if(res!=-1){
        cout<<"姓名： "<<abs->personArray[res].m_Name<<"\t";
        cout<<"性别： "<<(abs->personArray[res].m_Sex==1?"男":"女")<<"\t";
        cout<<"年龄： "<<abs->personArray[res].m_Age<<"\t";
        cout<<"电话： "<<abs->personArray[res].m_Phone<<"\t";
        cout<<"住址： "<<abs->personArray[res].m_Addr<<endl;
    }else{
        cout<<"查无此人"<<endl;
    }
    system("read -p 'Press Enter to continue...' var"); //请按任意键继续
    system("clear");  //清屏
}

//5、修改联系人
void modifyPerson(struct Adressbooks* abs){
    cout<<"请输入您想要修改的联系人姓名： "<<endl;
    string name;
    cin>>name;
    int res=isExist(abs,name);
    if(res!=-1){
        bool flag=true;
        while(flag){
            cout<<"请输入您想要修改的信息： "<<endl;
            cout<<"1--姓名"<<endl;
            cout<<"2--性别"<<endl;
            cout<<"3--年龄"<<endl;
            cout<<"4--电话"<<endl;
            cout<<"5--住址"<<endl;
            int t;
            cin>>t;
            while(1){
                if(t==1){
                    cout<<"请输入姓名： "<<endl;
                    string name;
                    cin>>name;
                    abs->personArray[res].m_Name=name;
                    break;
                }else if(t==2){
                    cout<<"请输入性别： "<<endl;
                    cout<<"1---男"<<endl;
                    cout<<"2---女"<<endl;
                    int sex=0;
                    while(1){
                        cin>>sex;
                        if(sex==1||sex==2){
                            abs->personArray[res].m_Sex=sex; 
                            break; 
                        }else{
                            cout<<"输入错误，请重新输入"<<endl;
                        }
                    }
                    break;
                }else if(t==3){
                    cout<<"请输入年龄： "<<endl;
                    int age=0;
                    while(1){
                        cin>>age;
                        if(age>1&&age<=150){
                            abs->personArray[res].m_Age=age;
                            break;
                        }else{
                            cout<<"输入有误，请重新输入： "<<endl;
                        }
                    }
                    break;
                }else if(t==4){
                    cout<<"请输入住址： "<<endl;
                    string address;
                    cin>>address;
                    abs->personArray[res].m_Addr=address;
                    break;
                }else{
                    cout<<"您的输入有误，请重新输入"<<endl;
                }
            }
            cout<<"是否需要继续修改"<<abs->personArray[res].m_Name<<"的信息？"<<endl;
            cout<<"Y---YES"<<endl;
            cout<<"N---NO"<<endl;
            string yn;
            cin>>yn;
            if(yn=="Y") flag==true;
            else{ 
                flag==false;
                break;
            }
        }
        cout<<"修改成功！"<<endl;
    }else{
        cout<<"查无此人"<<endl;
    }
    system("read -p 'Press Enter to continue...' var"); //请按任意键继续
    system("clear");  //清屏
}

//6、清空联系人
void clearPerson(struct Adressbooks* abs){
    cout<<"您确定要清空联系人吗？"<<endl;
    cout<<"Y---YES"<<endl;
    cout<<"N---NO"<<endl;
    string yn;
    cin>>yn;
    if(yn=="Y"){
        abs->m_Size=0;
        cout<<"通讯录已清空"<<endl;
    }else if(yn=="N"){
        return;
    }
    system("read -p 'Press Enter to continue...' var"); //请按任意键继续
    system("clear");  //清屏
}

//0、退出
void exit(){
    exit(0);
}

//显示菜单
void showMenu(){
    cout<<"************************"<<endl;
    cout<<"***** 1、添加联系人 *****"<<endl;
    cout<<"***** 2、显示联系人 *****"<<endl;
    cout<<"***** 3、删除联系人 *****"<<endl;
    cout<<"***** 4、查找联系人 *****"<<endl;
    cout<<"***** 5、修改联系人 *****"<<endl;
    cout<<"***** 6、清空联系人 *****"<<endl;
    cout<<"***** 0、退出通讯录 *****"<<endl;
    cout<<"************************"<<endl;
}


int main(){
    //创建通讯录结构体变量
    Adressbooks abs;
    abs.m_Size=0;


    int select=0;

    while(1){
        showMenu();
        
        cin>>select;

        switch(select)
        {
            case 1: //1、添加联系人
                addPerson(&abs);
                break;
            case 2: //2、显示联系人
                showPerson(&abs);
                break;
            case 3: //3、删除联系人
                deletePerson(&abs);
                break;
            case 4: //4、查找联系人
            findPerson(&abs);
                break;
            case 5: //5、修改联系人
            modifyPerson(&abs);
                break;
            case 6: //6、清空联系人
                clearPerson(&abs);
                break;
            case 0: //0、退出通讯录
                exit();
                cout<<"欢迎下次使用"<<endl;
                system("read -p 'Press Enter to continue...' var");
                return 0;
                break;
            default:
                break;
        }
    }
    

    


    return 0;
}