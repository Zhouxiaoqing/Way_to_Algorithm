//染色问题
//coloring.cpp

//用一些颜色给无向图中的节点染色，相邻节点不能用同一种颜色
//求出给无向图染色至少需要的不同颜色的数量

//染色实际是点独立集的划分，每种颜色的节点的集合都是一个独立集，其中任意节点间不相邻
//设无向图G至少需要k种不同的颜色，则称无向图G是k色可染的，或k色图
//染色问题也可以扩展成边的染色
//即至少需要k种颜色来对图G的边进行染色，且任意相邻两边的颜色不同
//显然用任何m(m > k)个颜色也可以对图G染色，k也是图G中最少的不相交点独立集数量
//四色定理：拓扑平面上的任何地图都可以用至多四种颜色染色，使得相邻区域的颜色不同
//
//求无向图G的颜色数k及其染色方案是一个NP-Hard问题
//该问题可以转化为判断给定颜色数k'，是否存在方案将无向图G染色
//这是一个NP-Complete问题，也称K-Coloring问题
//枚举颜色数k即可求出无向图G的颜色数k及其染色方案
//
//NP问题已经超出本章的范围，本文只对染色问题的算法稍作介绍
//1)添边粘合法
//对图G中不相邻的所有节点i和j重复以下步骤：
//在节点i和j之间添加一条边，然后将i和j粘合称为一个节点，并删去所有的重复边
//得到一个新图G'，若依然存在不相邻的节点i和j，继续重复上面的操作
//直到图中不存在不相邻的节点，此时的图中节点数量即为原图G的颜色数k
//2)极大独立集法(规范染色法)
//设无向图G=<V,E>有这样的k个极大独立集{V1, V2, ..., Vk}
//其中V1是G的极大独立集，V2是G/V1的极大独立集，V3是G/(V1并V2)的极大独立集
//...Vk是G/(V1并V2并...并Vk-1)的极大独立集，则k是图G的颜色数
//3)顺序染色法
//从某个节点i开始，每次选择一个它的所有邻节点都没有使用过的颜色对它进行染色
//然后继续对它的某个未染色的邻节点j重复以上的染色操作
//若相邻两节点的颜色相同则颜色数需要增大
//
//下面是几种高级搜索算法在染色问题上的应用(见本书第1章第2节高级搜索算法介绍)：
//4)简单局部搜索(Simple Local Search)
//初始时随机的构造一个染色方案(相邻节点可能会有相同颜色)
//通过一个产生邻居的动作来通过当前方案构造出多个邻居方案，所有邻居方案的集合为邻域
//定义产生邻居方案的动作为：将颜色相同的两邻节点都称为冲突点
//将冲突点的颜色改为除过当前的另外k-1个颜色中的一种，邻域大小为冲突点数量*(k-1)
//即产生的邻居方案的数量为冲突点数量*(k-1)
//而评价标准显而易见可以定义为：选择冲突点数最少的邻居方案进行下一轮搜索
//5)禁忌算法
//若一次操作中，某个节点从颜色i变为颜色j，则接下来的t次迭代重复中
//该节点禁止再回到颜色i，被限制的迭代次数t即为禁忌长度
//设置禁忌表来维护图中各节点的禁忌长度，每次迭代后各节点的禁忌长度减1
//禁忌长度的初始值t可以设置为定值，也可以为动态值，通过设置随机函数来实现
//每次新的迭代中，判断当前方案和邻域中的所有邻居方案
//若邻居方案属于禁忌方案，则判断该禁忌方案是否优于历史上的最优方案
//若比历史上最优方案还好，则解禁该方案，否则只在未被禁忌的邻居方案中选择最优方案
//若有多个同程度的最优方案则随机选择其中一个
//6)进化算法，遗传算法
//维护一个较小的群体，其中每个个体(方案)都是经过局部搜索得到的
//对这个群体进行进化算法，即通过一定的遗传算子进行繁殖，得到新一代个体(邻居方案)
//按照一个适应函数对新一代个体进行评价，只选取那些较优秀的个体加入新一代群体
//直到达到终止条件
//
//本文引用了“图染色问题”，作者“JiePro”



