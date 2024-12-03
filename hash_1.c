#include <stdio.h>

#define HASH_TABLE_SIZE 20

int hashTable[HASH_TABLE_SIZE];

/// @brief ハッシュ値を求める
/// @param key 元のデータの値
/// @return 求めたハッシュ値
int hash(int key)
{
    return key % HASH_TABLE_SIZE;
}

/// @brief 値をハッシュ表に登録する
/// @param key 登録する値
/// @return データ登録時に発生したハッシュ衝突の回数
int resister(int key)
{
    int clashCount = 0;
    for (int index = hash(key); index < HASH_TABLE_SIZE; index++)
    {
        if (hashTable[index] == 0)
        {
            hashTable[index] = key;
            return clashCount;
        }
        clashCount++;
    }
    printf("値の登録失敗¥n");
    return clashCount;
}

/// @brief 値がハッシュ表に登録されているか調べる
/// @param key 検索する値
/// @return 登録されていれば1、されていなければ0
int search(int key)
{
    for (int index = hash(key); index < HASH_TABLE_SIZE; index++)
    {
        if (hashTable[index] == key)
            return 1;
    }
    return 0;
}

int main()
{
    int key, x, index;
    int maxClashCount = 0;
    for (;;)
    {
        printf("記憶する電話番号(0で終了):");
        scanf("%d", &key);
        if (key == 0)
            break;
        int clashCount = resister(key);
        if (clashCount > maxClashCount)
            maxClashCount = clashCount;
        printf("ハッシュ衝突の回数:%d¥n", clashCount);
    }
    printf("最大のハッシュ衝突の回数:%d¥n", maxClashCount);
    for (;;)
    {
        printf("探したい電話番号(0で終了):");
        scanf("%d", &x);
        if (x == 0)
            break;
        if (search(x))
            printf("見つかった¥n");
        else
            printf("見つからない¥n");
    }
}
