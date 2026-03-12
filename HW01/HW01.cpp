#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {

    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main() {


    int status[4] = { 0, 0, 0, 0 };


    int hp_potion = 0;
    int mp_potion = 0;


    printf("HP와 MP를 입력하세요 (둘 다 50 초과여야 함): ");
    scanf("%d %d", &status[0], &status[1]);

    while (status[0] <= 50 || status[1] <= 50) {
        printf("하나라도 50 이하면 안 됩니다! 다시 입력: ");
        scanf("%d %d", &status[0], &status[1]);
    }


    printf("공격력과 방어력을 입력하세요 (둘 다 0 초과여야 함): ");
    scanf("%d %d", &status[2], &status[3]);

    while (status[2] <= 0 || status[3] <= 0) {
        printf("하나라도 0 이하면 안 됩니다! 다시 입력: ");
        scanf("%d %d", &status[2], &status[3]);
    }


    setPotion(5, &hp_potion, &mp_potion);


    int choice = -1;
    while (choice != 0) {
        printf("\n--- 메뉴 선택 ---\n");
        printf("1.MP UP / 2.HP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (mp_potion > 0) {
                status[1] += 20;
                mp_potion--;
                printf("MP가 20 올랐습니다! (남은 MP포션: %d)\n", mp_potion);
            }
            else {
                printf("MP 포션이 부족합니다!\n");
            }
            break;

        case 2:
            if (hp_potion > 0) {
                status[0] += 20;
                hp_potion--;
                printf("HP가 20 올랐습니다! (남은 HP포션: %d)\n", hp_potion);
            }
            else {
                printf("HP 포션이 부족합니다!\n");
            }
            break;

        case 3:
            status[2] *= 2;
            printf("공격력이 2배가 되어 %d이 되었습니다!\n", status[2]);
            break;

        case 4:
            status[3] *= 2;
            printf("방어력이 2배가 되어 %d이 되었습니다!\n", status[3]);
            break;

        case 5:
            printf("\n[현재 능력치] HP:%d, MP:%d, 공:%d, 방:%d\n", status[0], status[1], status[2], status[3]);
            printf("[남은 포션] HP포션:%d, MP포션:%d\n", hp_potion, mp_potion);
            break;

        case 6:
            hp_potion++;
            mp_potion++;
            printf("레벨 업! 포션을 각각 1개씩 추가 지급합니다.\n");
            break;

        case 0:
            printf("프로그램을 종료합니다.\n");
            break;

        default:
            printf("잘못된 번호입니다. 다시 선택하세요.\n");
            break;
        }
    }

    return 0;
}
