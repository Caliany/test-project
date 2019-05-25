/*2.实现一个通讯录；
通讯录可以用来存储1000个人的信息，每个人的信息包括：
提供方法：
1. 添加联系人信息
2. 删除指定联系人信息
3. 查找指定联系人信息
4. 修改指定联系人信息
5. 显示所有联系人信息
6. 清空所有联系人
7. 以名字排序所有联系人
8. 保存联系人到文件
9. 加载联系人 */
//1.把基本信息抽象并描述出来（结构体）
//2.需要管理很多，就需要组织起来（数据结构）
//"数组是最简单的数据结构"
typedef struct PersonInfo{
	char name[1024];
	char phone[1024];
}PersonInfo;

#define MAX_PERSON_INFO_SIZE 1000
typedef struct AddressBook{
	PersonInfo persons[MAX_PERSON_INFO_SIZE];
	//[0,size)
	int size;
}AddressBook;
AddressBook g_address_book;
//初始化操作
void Init(){
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_INFO_SIZE; ++i){
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
	}
}
int Menu(){
	printf("======================\n");
	printf("1.新增联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.更新联系人\n");
	printf("5.显示所有联系人\n");
	printf("6.排序联系人\n");
	printf("7.清空联系人\n");
	printf("0.退出\n");
	printf("======================\n");
	printf("请输入您的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Empty(){
	//这个函数啥都不干
}

void AddPersonInfo(){
	printf("新增联系人\n");
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE){
		printf("新增联系人格式失败！\n");
		return;
	}
	printf("请输入联系人姓名：");
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	//必须获得一个指针，修改的内容是一个预期的内容
	scanf("%s", person_info->name);
	printf("请输入联系人电话：");
	scanf("%s", person_info->phone);
	++g_address_book.size;
	printf("新增联系人成功\n");
}
void DelPersonInfo(){
	printf("删除联系人\n");
	if (g_address_book.size <= 0){
		printf("删除失败!通讯录为空！\n");
		return;
	}
	printf("请输入要删除的序号：");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size){
		printf("删除失败！输入的序号有误哦！\n");
		return;
	}
	g_address_book.persons[id]
		= g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;

	printf("删除联系人成功\n");
}
void FindPersonInfo(){
	printf("查找联系人\n");
	if (g_address_book.size <= 0){
		printf("查找失败，通讯录为空！\n");
	}
	printf("请输入要查找的姓名：\n");
	char name[1024] = { 0 };
	scanf("%s", name);
	for (int i = 0; i < g_address_book.size; ++i){
		PersonInfo* info = &g_address_book.persons[i];
		if (strcmp(info->name, name) == 0){
			printf("[%d] %s\t%s\n", i,
				info->name, info->phone);
		}
		break;
	}
	printf("查找联系人成功\n");
}
void UpdatePersonInfo(){
	printf("更新联系人\n");
	if (g_address_book.size <= 0){
		printf("修改失败，通讯录为空！\n");
	}
	printf("请输入要修改的序号：");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>g_address_book.size){
		printf("修改失败，输入的序号有误哦！\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("请输入新的姓名:(%s)\n", info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0){
		strcpy(info->name, name);
	}
	char phone[1024] = { 0 };
	printf("请输入新的电话：(%s)\n", info->phone);
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0){
		strcpy(info->phone, phone);
	}
	printf("更新联系人成功\n");
}
void PrintAllPersonInfo(){
	printf("打印全部联系人\n");
	for (int i = 0; i < g_address_book.size; ++i){
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n", i, info->name, info->phone);
	}
	printf("共打印了 %d 条数据！\n", g_address_book.size);
	printf("打印全部联系人成功\n");
}

//字典序排序法
void SortPersonInfo(){
	printf("排序联系人\n");
	if (g_address_book.size <= 0){
		printf("修改失败，通讯录为空！\n");
	}
	//好像没啥思路，不会写  呜呜呜呜呜呜。。。。。
	printf("排序联系人成功\n");
}
void ClearAllPersonInfo(){
	printf("清空全部数据\n");
	printf("您真的要清空全部数据吗？Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0){
		g_address_book.size = 0;
		printf("清空全部数据成功！\n");
	}
	else{
		printf("清空操作取消！");
	}
}
typedef void(*Func)();

int main(){
	Func arr[] = {
		Empty,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		UpdatePersonInfo,
		PrintAllPersonInfo,
		SortPersonInfo,
		ClearAllPersonInfo
	};
	while (1){
		int choice = Menu();
		if (choice < 0 || choice >= sizeof(arr) / sizeof(arr[0])){
			printf("您的输入有误，请重新输入！\n");
		}
		if (choice == 0){
			printf("goodbye!\n");
			break;
		}
		arr[choice]();
	}

	system("pause");
	return 0;
}