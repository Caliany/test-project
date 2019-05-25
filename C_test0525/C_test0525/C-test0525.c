/*2.ʵ��һ��ͨѶ¼��
ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
�ṩ������
1. �����ϵ����Ϣ
2. ɾ��ָ����ϵ����Ϣ
3. ����ָ����ϵ����Ϣ
4. �޸�ָ����ϵ����Ϣ
5. ��ʾ������ϵ����Ϣ
6. ���������ϵ��
7. ����������������ϵ��
8. ������ϵ�˵��ļ�
9. ������ϵ�� */
//1.�ѻ�����Ϣ���������������ṹ�壩
//2.��Ҫ����ܶ࣬����Ҫ��֯���������ݽṹ��
//"��������򵥵����ݽṹ"
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
//��ʼ������
void Init(){
	g_address_book.size = 0;
	for (int i = 0; i < MAX_PERSON_INFO_SIZE; ++i){
		g_address_book.persons[i].name[0] = '\0';
		g_address_book.persons[i].phone[0] = '\0';
	}
}
int Menu(){
	printf("======================\n");
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.��ʾ������ϵ��\n");
	printf("6.������ϵ��\n");
	printf("7.�����ϵ��\n");
	printf("0.�˳�\n");
	printf("======================\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Empty(){
	//�������ɶ������
}

void AddPersonInfo(){
	printf("������ϵ��\n");
	if (g_address_book.size >= MAX_PERSON_INFO_SIZE){
		printf("������ϵ�˸�ʽʧ�ܣ�\n");
		return;
	}
	printf("��������ϵ��������");
	PersonInfo* person_info = &g_address_book.persons[g_address_book.size];
	//������һ��ָ�룬�޸ĵ�������һ��Ԥ�ڵ�����
	scanf("%s", person_info->name);
	printf("��������ϵ�˵绰��");
	scanf("%s", person_info->phone);
	++g_address_book.size;
	printf("������ϵ�˳ɹ�\n");
}
void DelPersonInfo(){
	printf("ɾ����ϵ��\n");
	if (g_address_book.size <= 0){
		printf("ɾ��ʧ��!ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("������Ҫɾ������ţ�");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= g_address_book.size){
		printf("ɾ��ʧ�ܣ�������������Ŷ��\n");
		return;
	}
	g_address_book.persons[id]
		= g_address_book.persons[g_address_book.size - 1];
	--g_address_book.size;

	printf("ɾ����ϵ�˳ɹ�\n");
}
void FindPersonInfo(){
	printf("������ϵ��\n");
	if (g_address_book.size <= 0){
		printf("����ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
	}
	printf("������Ҫ���ҵ�������\n");
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
	printf("������ϵ�˳ɹ�\n");
}
void UpdatePersonInfo(){
	printf("������ϵ��\n");
	if (g_address_book.size <= 0){
		printf("�޸�ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
	}
	printf("������Ҫ�޸ĵ���ţ�");
	int id = 0;
	scanf("%d", &id);
	if (id<0 || id>g_address_book.size){
		printf("�޸�ʧ�ܣ�������������Ŷ��\n");
		return;
	}
	PersonInfo* info = &g_address_book.persons[id];
	printf("�������µ�����:(%s)\n", info->name);
	char name[1024] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0){
		strcpy(info->name, name);
	}
	char phone[1024] = { 0 };
	printf("�������µĵ绰��(%s)\n", info->phone);
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0){
		strcpy(info->phone, phone);
	}
	printf("������ϵ�˳ɹ�\n");
}
void PrintAllPersonInfo(){
	printf("��ӡȫ����ϵ��\n");
	for (int i = 0; i < g_address_book.size; ++i){
		PersonInfo* info = &g_address_book.persons[i];
		printf("[%d] %s\t%s\n", i, info->name, info->phone);
	}
	printf("����ӡ�� %d �����ݣ�\n", g_address_book.size);
	printf("��ӡȫ����ϵ�˳ɹ�\n");
}

//�ֵ�������
void SortPersonInfo(){
	printf("������ϵ��\n");
	if (g_address_book.size <= 0){
		printf("�޸�ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
	}
	//����ûɶ˼·������д  �����������ء���������
	printf("������ϵ�˳ɹ�\n");
}
void ClearAllPersonInfo(){
	printf("���ȫ������\n");
	printf("�����Ҫ���ȫ��������Y/N\n");
	char choice[1024] = { 0 };
	scanf("%s", choice);
	if (strcmp(choice, "Y") == 0){
		g_address_book.size = 0;
		printf("���ȫ�����ݳɹ���\n");
	}
	else{
		printf("��ղ���ȡ����");
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
			printf("���������������������룡\n");
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