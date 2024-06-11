#include<stdio.h>
#include<string.h>
#include<alloca.h>
struct student{
	int stud_id;
	int name_len;
	int struct_size;
	char stud_name[];
};
struct student* createstudent(int id,const char* name)
{
	int name_len=strlen(name);
	struct student* s = alloca(sizeof(struct student)+ name_len + 1);
	s->stud_id=id;
	s->name_len=name_len;
	strcpy(s->stud_name,name);
	s->struct_size=sizeof(struct student)+name_len + 1;
	return s;
}
void printstudent(struct student* s)
{
	printf("Student_id: %d\n stud_Name:%s\nName_Length:%d\nAllocated_struct_size:%d \n\n", s->stud_id, s->stud_name, s->name_len, s->struct_size);
}

int main()
{
	struct student* s1 = createstudent(531,"ABC");
	struct student* s2 = createstudent(532,"MMM");
	printstudent(s1);
	printstudent(s2);

	printf("Size of Student : %ld \n\n",sizeof(struct student));
	printf("Size of Student : %ld \n\n",sizeof(s1));
	return 0;
}

