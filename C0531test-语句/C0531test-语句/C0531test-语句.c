#include <stdio.h>

int main(){
	int a = 0;
	int b = 2;
	if (a == 5){
		if (b == 2)
			printf("hehe\n");
	}
	else{
		printf("haha\n");
	}
	system("pause");
	return 0;
}

#include <stdio.h>
int main()
{
	int day = 6;
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("weekday\n");
		break;
	case 6:
	case 7:
		printf("weekend\n");
		break;
	}
	printf("%d\n", day);
	system("pause");
	return 0;
}
