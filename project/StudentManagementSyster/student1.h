
/*name type*/
typedef char Name[20];

/**
 *@brief student information of struct
 *
 */
struct Student
{
    Name name;
    char sex;
    short int age;
    short int score;
};

struct StudentList
{
    struct StudentList *hand;
    Name name;
    char sex;
    short int age;
    short int score;
}
/**
 *@brief class information
 *
 */
struct Class
{
    struct Student stu[100];
    int count;
};

/*function*/

/**
 *@brief Insert student
 *
 *@param cls
 *@return int
 */
int Insert_stu(struct Class *cls);
/**
 *@brief set up list of student
 *
 *@param cls
 *@return int
 */
int Set_stu_list(struct Class *cls);
/**
 *@brief
 *
 *@param cls
 *@return int
 */
int Delete_stu(struct Class *cls);
int Update_stu_score(struct Class *cls);
int Select_stu(struct Class *cls);
int Sort_stu_score(struct Class *cls);
int Sort_stu_score_name(struct Class *cls);
int Sort_stu_score_score(struct Class *cls);

int Printf_stu_score(struct Class *cls);
int Debug_stu(struct Class *cls);