#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define RAND(X) (rand()%(X))
#define NUM_ORDER	(30)
#define NUM_CAR    (10)
#define GENERATIONS	(5000)
#define MAX_SIZE	(50)
#define LOWEST_ALIVE	(1.0/MAX_SIZE)

class Point{
//坐标点
public:
    double x,y;
};

class Order{
//订单，表示坐标点的联系和订单的完成情况
public:
    Point shop,customer;
    bool has_taken, is_finish;
};

class Car{
//骑手，最多途经2*NUM_ORDER个坐标点
public:
    int _order;
    Order orders[NUM_ORDER];
    Point points[2*NUM_ORDER];
};

class Solution{
//订单配送方案，包含每个骑手的路径信息
//相当于种族中的“个体”，具有自己的适应值和存活率
public:
    Car cars[NUM_CAR];
    double adapt,pAlive;
};

Solution solutions[MAX_SIZE];//one generation

float	Pm = 0.1;//变异概率
float	Pc = 0.8;//交配概率
int bestOne;//该代最优解的id

void getFitness(Solution &solution) // 得到适应值（与目标函数有关）
{
    double cost;
    cost=;
    solution.adapt=cost;
    solution.pAlive=1.0/cost;
//	int distance = 0;
//	int temp;
//	int x1, x2, y1, y2;
//	int tdistance;
//	for (int i = 1; i < NUM_CITY; i++)
//	{
//		distance += cityDistance[group.city[i - 1]][group.city[i]];
//	}
//	group.adapt = distance;
//	group.pAlive = 1 / (float)distance;
}

void Swap(int &a, int &b) // 交换ab值
{
    int c;
	c = a;
	a = b;
	b = c;
}

void Init() // 初始化
{
	srand((unsigned int)time(0));

	for (int i = 0; i < MAX_SIZE; i++){ // 初始化种族
		for (int j = 0; j < NUM_CITY; j++){
			g_Group[i].city[j] = j;
		}
	}
	int r;
	for (int i = 0; i < MAX_SIZE; i++) {// 打乱顺序
		for (int j = 0; j < NUM_CITY; j++){
			r = RAND(NUM_CITY);
			Swap(g_Group[i].city[j], g_Group[i].city[r]);
		}
	}
	printf("产生初始种群如下：\n");
	for (int i = 0; i < MAX_SIZE; i++){
		printf("第%d个个体:\n", i + 1);
		for (int j = 0; j < NUM_CITY; j++){
			printf("%3d ", g_Group[i].city[j]);
		}
		printf("\n");
	}
}

void GetAliveP() //个体存活率计算&矫正
{
    double totalAlive = 0;
	for (int i = 0; i < MAX_SIZE; i++){// 计算个体适应值
		getFitness(solutions[i]);
		totalAlive += solutions.pAlive;
	}
	for (int i = 0; i < MAX_SIZE; i++) {// 矫正个体存活率 让总和为1
		solutions[i].pAlive /= totalAlive;
	}
}

void ShowBest()//选择并展示该代最优个体
{
	bestOne = 0;
	for (int i = 1; i < MAX_SIZE; i++){
		if (solutions[i].pAlive > solutions[bestOne].pAlive)
			bestOne = i;
	}
	printf("目前最佳个体为：%d, 其代价为%lf ,其轨迹如下：\n", bestOne+1, solutions[bestOne].adapt);
	for(int i=0;i<NUM_CAR;i++){
        int num_of_points=2*solutions[bestOne].cars[i]._order;
        for(int j=0;j<num_of_points;j++){
            printf("(%lf,%lf) ",solutions[bestOne].cars[i].points[j].x,
                                          solutions[bestOne].cars[i].points[j].y);
        }
	}
	printf("\n");
}

int isOnIt(int num, int Array[NUM_CITY], int ignorePos, int pos1, int pos2){ // num是否在Array[]的pos1到pos2之间 其中跳过ignorePos(该数字的原位置)
	for (int i = pos1; i <= pos2; i++){
		if (Array[i] == num)
			return i;
	}
	return -1;
}

void Swap(int sel1,int sel2,int pos1, int pos2)// 交叉互换
{
    int temp;
	//int maxSize = pos2 - pos1 + 1;
	//printf("开始初步交叉互换\n");
	//printf("%d %d\n", pos1, pos2);
	for (int i = pos1; i <= pos2; i++){
		temp = g_Group[sel1].city[i];
		g_Group[sel1].city[i] = g_Group[sel2].city[i];
		g_Group[sel2].city[i] = temp;
	}
	int pos;
	//printf("开始矫正重复值\n");
	int times = 0;
	for (int i = 0; i < NUM_CITY; i++){// 矫正重复值
		times = 0;
		if (i >= pos1 && i <= pos2){
			i = pos2;
			continue;
		}
		do{
			times++;
			pos = isOnIt(g_Group[sel1].city[i], g_Group[sel1].city, i, pos1, pos2);
			if (pos != -1){
			/*
				for (int j = 0; j < NUM_CITY; j++)
					printf("%4d", g_Group[sel1].city[j]);
				printf("\n");
				for (int j = 0; j < NUM_CITY; j++)
					printf("%4d", g_Group[sel2].city[j]);
				printf("\n");
				printf("%d %d %d %d %d\n",pos1,pos2,pos, g_Group[sel1].city[i], g_Group[sel2].city[pos]);*/
				g_Group[sel1].city[i] = g_Group[sel2].city[pos];
				//printf("pos:%d,pos1:%d,pos2:%d\n", pos, pos1, pos2);
			}
		} while (pos != -1);
		do{
			pos = isOnIt(g_Group[sel2].city[i], g_Group[sel2].city, i, pos1, pos2);
			if (pos != -1)
			{
				g_Group[sel2].city[i] = g_Group[sel1].city[pos];
				//printf("pos:%d,pos1:%d,pos2:%d\n", pos, pos1, pos2);
			}
		} while (pos != -1);
	}
//	printf("交叉互换过程完毕\n");
}

void Mutation(int sel, int pos1,int pos2)//个体突变
{
    int maxSize = pos2 - pos1 + 1;
	for (int i = 0; i < maxSize / 2; i++)
	{
		Swap(g_Group[sel].city[pos1+i], g_Group[sel].city[pos2-i]);
	}
}

void Genetic()// 产生下一代种群
{
	int maxNum = 0, minNum = 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (g_Group[i].pAlive > g_Group[maxNum].pAlive)
			maxNum = i;
		if (g_Group[i].pAlive < g_Group[maxNum].pAlive)
			minNum = i;
	}
	g_Group[minNum] = g_Group[maxNum]; // 使最大直接替换最小
	//printf("开始交叉\n");
	// 交叉配对
	int selNum;
	int maxTimes = 0, nowTimes = 0;
	int canSelected[MAX_SIZE]; // 可以用于交叉的个体
	bool isCanSelected[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++){
		if (i == maxNum) // 不让最优秀的个体参与配对
			continue;
		else if ((RAND(100)) / 100.0 < Pc){// 根据概率判断是否参与配对
			canSelected[maxTimes++] = i;
		}
	}
	for (int i = 0; i < maxTimes; i++){
		selNum = RAND(maxTimes);

		Swap(canSelected[i], canSelected[selNum]);
	}
	int pos1, pos2;
	for (int i = 0; i < maxTimes; i+=2){
		selNum = i + 1;
		if (selNum >= maxTimes)
			break;
		pos1 = RAND(NUM_CITY); // 选定交叉位置
		pos2 = RAND(NUM_CITY - pos1) + pos1;
		if (pos1 == pos2){
			if (pos1 > 0)
				pos1--;
			else
				pos2++;
		}/*
		printf("%d与%d开始交叉互换\n", canSelected[i], canSelected[selNum]);*/
		Swap(canSelected[i], canSelected[selNum], pos1, pos2);
		/*
				printf("第%d个体与第%d个体进行交叉配对，得到新的两个个体如下:\n", canSelected[i] + 1, canSelected[selNum] + 1);
				printf("第%d个体:\n", canSelected[i] + 1);
				for (int j = 0; j < NUM_CITY; j++)
				printf("%4d", g_Group[canSelected[i]].city[j]);
				printf("\n第%d个体:\n", canSelected[selNum] + 1);
				for (int j = 0; j < NUM_CITY; j++)
				printf("%4d", g_Group[canSelected[selNum]].city[j]);
				printf("\nselNum:%d, maxTimes:%d\n",selNum,maxTimes);*/
	}
/*
	printf("开始突变\n");*/
	// 突变
	for (int i = 0; i < MAX_SIZE; i++){
		if (i == maxNum || i == minNum){
			continue;
		}
		if (RAND(100) / 100.0 < Pm){ // 符合突变概率
			pos1 = RAND(NUM_CITY); // 选择位置
			pos2 = RAND(NUM_CITY - pos1) + pos1;
			if (pos1 == pos2){
				if (pos1 > 0)
					pos1--;
				else
					pos2++;
			}
			/*printf("第%d个体突变前：\n", i + 1);
			for (int j = 0; j < NUM_CITY; j++)
				printf("%4d", g_Group[i].city[j]);
			printf("\n");*/
			Mutation(i, pos1, pos2);
		//	printf("第%d个体突变：\n", i + 1);/*
		//	for (int j = 0; j < NUM_CITY; j++)
		//		printf("%4d", g_Group[i].city[j]);
		//	printf("\n");
		}
	}
}

void Train(){
	int nowGenerations = 0;
	float totalAlive = 0;
	do{
		printf("第%d代种群\n", nowGenerations + 1);
		GetAliveP();// 计算存活率
		Genetic();// 根据遗传规律得到下一代
		nowGenerations++;
	} while (nowGenerations < GENERATIONS);
	printf("经过%d次繁衍，得到的优秀个体为:\n", nowGenerations);
	printf("其距离为%d,其轨迹如下：\n", g_Group[bestOne].adapt);
	for (int i = 0; i < NUM_CITY; i++)
		printf("%d ", g_Group[bestOne].city[i]);
	printf("\n");
	printf("其他个体如下：\n");
	for (int i = 0; i < MAX_SIZE; i++){
		printf("其距离为%d,其轨迹如下：\n", g_Group[i].adapt);
		for (int j = 0; j < NUM_CITY; j++){
			printf("%d ", g_Group[i].city[j]);
		}
		printf("\n");
	}
}
int main(){
	Init();
	Train();
	return 0;
}



