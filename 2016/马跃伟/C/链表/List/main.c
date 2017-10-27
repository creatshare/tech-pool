#include "list.h"
int main() {
    struct LNode MessageBoard;
    MessageBoard.Next = NULL;
    MessageBoard.Data = "我真帅";
    List PrtL;
    PrtL = &MessageBoard;
    int a;
    do {
        printf("                      留言板                          \n");
        printf("******************************************************\n");
        printf("                     请选择功能                        \n");
        printf("        1.查看所有留言                                 \n");
        printf("        2.查看一条留言                                 \n");
        printf("        3.写一条留言                                   \n");
        printf("        4.修改一条留言                                 \n");
        printf("        5.删除一条留言                                 \n");
        printf("        0.退出                                         \n");
        printf("******************************************************\n");
        scanf("%d", &a);
        switch (a) {
            case 1:
                show_all(PrtL);
                break;
            case 2:
                show_one(PrtL);
                break;
            case 3:
                wirte_one(PrtL);
                break;
            case 4:
                change_one(PrtL);
                break;
            case 5:
                delete_one(PrtL);
                break;
        }
    } while (a != 0);
    return 0;
}


