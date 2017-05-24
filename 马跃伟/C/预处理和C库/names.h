#define SLEN 32

struct name_st
{
	char first[SLEN];
	char last[SLEN];

};

//定义类型
typedef struct names_st names;
//函数原型
void get_names(names *);
void show_names(const names *);
